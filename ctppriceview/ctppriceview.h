#ifndef __PRICE_VIEW_H__
#define __PRICE_VIEW_H__

#include "curses.h"
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <string.h>
#include "ThostFtdcMdApi.h"

typedef struct {
	char exchange_id[20];
	char exchange_name[100];
	char product_id[30];
	char product_name[100];
	double price;
	int quantity;
	int trade_volume;
	double high;
	double low;
	double settle;
	double prev_close;
	int openint;
	int prev_openint;
	double average_price;
	double buy_price;
	int buy_quantity;
	double sell_price;
	int sell_quantity;
	double open_price;
	double prev_settle;
	double min_movement;
	double high_limit;
	double low_limit;
	int precision;
	bool subscribed;
	char expired_date[20];
	int product_type;
	char product[20];
	double margin_ratio;
	int multiple;
	char tradingday[11];
} quotation_t;
extern std::vector<quotation_t> vquotes;
extern std::map<std::string, size_t> mquotes; // 索引，合约号==>vquotes下标
extern char** instruments; // 要订阅的合约列表
extern size_t instrument_count;

// Basic
void init_screen();
int on_key_pressed(int ch);
void time_thread();
void work_thread();
void HandleTickTimeout();

// Main Board
void refresh_screen();
void display_title();
void display_status();
void display_quotation(const char *product_id);
int on_key_pressed_mainboard(int ch);
int input_parse(int *num,int *cmd);
int move_forward_1_line();
int move_backward_1_line();
int scroll_forward_1_line();
int scroll_backward_1_line();
int scroll_left_1_column();
int scroll_right_1_column();
int goto_file_top();
int goto_file_bottom();
int goto_page_top();
int goto_page_bottom();
int goto_page_middle();
int move_forward_1_page();
int move_backward_1_page();
int move_forward_half_page();
int move_backward_half_page();
void focus_quotation(int index);

// Corner Window
void corner_refresh_screen();
void corner_display_matches();
void corner_display_focus();
void corner_redraw();
int on_key_pressed_corner(int ch);
void corner_destroy();
void corner_reset();
void corner_display_input();
void corner_choose_item();
void corner_move_left_1_pos();
void corner_move_right_1_pos();
void corner_delete_char_before_current_pos();
void corner_delete_char_at_current_pos();
int input_parse_corner(int *num,int *cmd);
void corner_move_forward_1_line();
void corner_move_backward_1_line();
void corner_research();


#define CONNECTION_STATUS_DISCONNECTED	0
#define CONNECTION_STATUS_CONNECTED		1
#define CONNECTION_STATUS_LOGINOK		2
#define CONNECTION_STATUS_LOGINFAILED	3

extern int ConnectionStatus;
void post_task(std::function<void()> task);


// CTP
class CCTPMdSpiImp :public CThostFtdcMdSpi
{
public:
	CCTPMdSpiImp(CThostFtdcMdApi* pMdApi) :m_pMdApi(pMdApi) {}

	//已连接
	void OnFrontConnected() { post_task(std::bind(&CCTPMdSpiImp::HandleFrontConnected, this)); }

	//未连接
	void OnFrontDisconnected(int nReason) { post_task(std::bind(&CCTPMdSpiImp::HandleFrontDisconnected, this, nReason)); }

	//登录应答
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) { post_task(std::bind(&CCTPMdSpiImp::HandleRspUserLogin, this, *pRspUserLogin, *pRspInfo, nRequestID, bIsLast)); }

	//行情服务的深度行情通知
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) { post_task(std::bind(&CCTPMdSpiImp::HandleRtnDepthMarketData, this, *pDepthMarketData)); }

	void HandleFrontConnected()
	{
		ConnectionStatus = CONNECTION_STATUS_CONNECTED;
		CThostFtdcReqUserLoginField Req;

		memset(&Req, 0x00, sizeof(Req));
		m_pMdApi->ReqUserLogin(&Req, 0);
	}

	void HandleFrontDisconnected(int nReason)
	{
		ConnectionStatus = CONNECTION_STATUS_DISCONNECTED;
		refresh_screen();
	}

	void HandleRspUserLogin(CThostFtdcRspUserLoginField& RspUserLogin, CThostFtdcRspInfoField& RspInfo, int nRequestID, bool bIsLast)
	{
		ConnectionStatus = CONNECTION_STATUS_LOGINOK;
		display_status();

		if (instrument_count == 0)
		{
			char* contracts[1];
			contracts[0] = "*";
			m_pMdApi->SubscribeMarketData(contracts, 1);
		}
		else
		{
			m_pMdApi->SubscribeMarketData(instruments, instrument_count);
		}
	}

	void HandleRtnDepthMarketData(CThostFtdcDepthMarketDataField& DepthMarketData)
	{
		std::map<std::string, size_t>::iterator iter;
		if ((iter = mquotes.find(DepthMarketData.InstrumentID)) == mquotes.end()) {
			// new
			quotation_t quot;
			memset(&quot, 0x00, sizeof(quot));
			strcpy(quot.product_id, DepthMarketData.InstrumentID);
			strcpy(quot.exchange_id, DepthMarketData.ExchangeID);
			quot.precision = 2;
			vquotes.push_back(quot);
			mquotes[DepthMarketData.InstrumentID] = vquotes.size() - 1;
			iter = mquotes.find(DepthMarketData.InstrumentID);
		}
		quotation_t& q = vquotes[iter->second];

		q.price = DepthMarketData.LastPrice;
		if (q.quantity != DepthMarketData.Volume)
			q.trade_volume = DepthMarketData.Volume - q.quantity;
		q.quantity = DepthMarketData.Volume;
		q.buy_price = DepthMarketData.BidPrice1;
		q.buy_quantity = DepthMarketData.BidVolume1;
		q.sell_price = DepthMarketData.AskPrice1;
		q.sell_quantity = DepthMarketData.AskVolume1;
		q.open_price = DepthMarketData.OpenPrice;
		q.high = DepthMarketData.HighestPrice;
		q.low = DepthMarketData.LowestPrice;
		q.high_limit = DepthMarketData.UpperLimitPrice;
		q.low_limit = DepthMarketData.LowerLimitPrice;
		q.settle = DepthMarketData.SettlementPrice;
		q.openint = DepthMarketData.OpenInterest;
		q.prev_openint = DepthMarketData.PreOpenInterest;
		q.prev_close = DepthMarketData.PreClosePrice;
		q.prev_settle = DepthMarketData.PreSettlementPrice;
		q.average_price = DepthMarketData.Volume ? DepthMarketData.Turnover / DepthMarketData.Volume : 0.0;
		strcpy(q.tradingday, DepthMarketData.TradingDay);

		display_quotation(DepthMarketData.InstrumentID);
	}

	CThostFtdcMdApi* m_pMdApi;
};

#endif /*__PRICE_VIEW_H__*/
