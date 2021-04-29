#ifndef __BCESTRADEAPIIMP_H__
#define __BCESTRADEAPIIMP_H__

#include "os.h"
#include <string>
#include <vector>
#include <map>
#include "BCESPackage.h"
#include "ServerConnector.h"
#include "BCESTradeApi.h"
//#include "applog.h"

//extern LOGFP* lp;

#pragma warning(disable : 4996)
#pragma warning(disable : 4267)

class CServerConnector;
class CServerConnection;
class CBCESTradeApiImp:public CBCESTradeApi
{
public:
	CBCESTradeApiImp();	//创建API实现实例
	~CBCESTradeApiImp();	//析构函数

public:
	void Release();	//释放API实现实例
	void RegisterSpi(CBCESTradeSpi* pSpi);
	int SetServerAddress(const char* szServerAddress);
	int Run();
	int Stop();
	const char* GetErrorMessage(int ErrorNo);

	/*登录请求*/
	int LoginReq(stBCESLoginReq *pLoginReq,UINT nRequestID);

	/*登出请求*/
	int LogoutReq(stBCESLogoutReq *pLogoutReq,UINT nRequestID);

	/* 订阅推送信息 */
	int FlowSubscribeReq(UINT nPrivateResumeMethod,UINT nPublicResumeMethod);

	/*修改密码请求*/
	int ChangePasswordReq(stBCESChangePasswordReq *pChangePasswordReq,UINT nRequestID);

	/*订单录入请求*/
	int OrderInsertReq(stBCESInputOrder *pInputOrder,UINT nRequestID);

	/*撤单请求*/
	int OrderCancelReq(stBCESOrderCancelReq *pOrderCancelReq,UINT nRequestID);

	/*行情查询请求*/
	int QuotQueryReq(stBCESQuotQueryReq *pQuotQueryReq,UINT nRequestID);

	/*订单查询请求*/
	int OrderQueryReq(stBCESOrderQueryReq *pOrderQueryReq,UINT nRequestID);

	/*成交查询请求*/
	int TradeQueryReq(stBCESTradeQueryReq *pTradeQueryReq,UINT nRequestID);

	/*持仓查询请求*/
	int PosiQueryReq(stBCESPosiQueryReq *pPosiQueryReq,UINT nRequestID);

	/*资金查询请求*/
	int FundQueryReq(stBCESFundQueryReq *pFundQueryReq,UINT nRequestID);

	/*合约查询请求*/
	int InstrumentQueryReq(stBCESInstrumentQueryReq *pInstrumentQueryReq,UINT nRequestID);

	/*持仓明细查询请求*/
	int PosiDetailQueryReq(stBCESPosiDetailQueryReq *pPosiDetailQueryReq,UINT nRequestID);

	/*止赢止损设置请求*/
	int ProfitLossStopSetReq(stBCESProfitLossStopSetReq *pProfitLossStopSetReq,UINT nRequestID);

	/*订单修改请求*/
	int OrderModifyReq(stBCESInputOrder *pInputOrder,UINT nRequestID);

	/*公告查询请求*/
	int BulletinQueryReq(stBCESBulletinQueryReq *pBulletinQueryReq,UINT nRequestID);

	/*通知查询请求*/
	int NoticeQueryReq(stBCESNoticeQueryReq *pNoticeQueryReq,UINT nRequestID);

	/*电子出入金请求*/
	int ElectronicFundIOReq(stBCESElectronicFundIOReq *pElectronicFundIOReq,UINT nRequestID);

	/*出入金明细查询请求*/
	int FundIODetailQueryReq(stBCESFundIODetailQueryReq *pFundIODetailQueryReq,UINT nRequestID);

	/*报表查询请求*/
	int ReportQueryReq(stBCESReportQueryReq *pReportQueryReq,UINT nRequestID);

	/*历史订单查询请求*/
	int HisOrderQueryReq(stBCESHisOrderQueryReq *pHisOrderQueryReq,UINT nRequestID);

	/*历史成交查询请求*/
	int HisTradeQueryReq(stBCESHisTradeQueryReq *pHisTradeQueryReq,UINT nRequestID);

	/*历史公告查询请求*/
	int HisBulletinQueryReq(stBCESHisBulletinQueryReq *pHisBulletinQueryReq,UINT nRequestID);

	/*历史通知查询请求*/
	int HisNoticeQueryReq(stBCESHisNoticeQueryReq *pHisNoticeQueryReq,UINT nRequestID);

	/*签约请求*/
	int AccountBindReq(stBCESAccountBindReq *pAccountBindReq,UINT nRequestID);

	/*签约信息查询请求*/
	int AccountBindQueryReq(stBCESAccountBindQueryReq *pAccountBindQueryReq,UINT nRequestID);

	/*资金查询请求*/
	int HisFundQueryReq(stBCESHisFundQueryReq *pHisFundQueryReq,UINT nRequestID);

	/*持仓明细查询请求*/
	int HisPosiDetailQueryReq(stBCESHisPosiDetailQueryReq *pHisPosiDetailQueryReq,UINT nRequestID);
public:
	boost::asio::io_service m_io;
	CServerConnector* m_pConnector;
	char m_servaddr[100];
	CBCESTradeSpi* m_pSpi;
	BCESFieldTypeDate m_TradeDate;
	UINT m_nPrivatePkgNo;
	UINT m_nPublicPkgNo;
};


#endif /* __BCESTRADEAPIIMP_H__ */
