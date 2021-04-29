#ifndef __BCESTRADEAPI_H__
#define __BCESTRADEAPI_H__

#include "APIFieldDefine.h"

#ifdef TRADEAPI_EXPORTS
#define TRADEAPI_LIB __declspec(dllexport)
#else
#ifdef WIN32
#define TRADEAPI_LIB __declspec(dllimport)
#else
#define TRADEAPI_LIB 
#endif
#endif

class CBCESTradeSpi	//回调接口
{
 public:
	//连接建立通知
	/* 说明：
		1. 此连接为系统连接，即便没有任何用户登录，该连接依然会维持在线状态
	*/
	virtual void OnConnected(){};

	//连接断开通知，用户无需处理，API会自动重连
	/* 说明：
		1. 连接断开后，所有在此连接上登录的用户均处于离线状态，重新连接后均需要重新发送登录请求
	*/
	virtual void OnDisconnected(){};

	/*登录应答*/
	virtual void OnLoginRsp(stBCESLoginRsp *pLoginRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*登出应答*/
	virtual void OnLogoutRsp(stBCESLogoutRsp *pLogoutRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*修改密码应答*/
	virtual void OnChangePasswordRsp(stBCESChangePasswordRsp *pChangePasswordRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*订单录入应答*/
	virtual void OnOrderInsertRsp(stBCESInputOrder *pInputOrder,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*订单通知*/
	virtual void OnOrderNty(stBCESOrder *pOrder){};

	/*撤单应答*/
	virtual void OnOrderCancelRsp(stBCESOrderCancelRsp *pOrderCancelRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*市场状态通知*/
	virtual void OnMarketStatusNty(stBCESMarketStatusNty *pMarketStatusNty){};

	/*成交通知*/
	virtual void OnTradeNty(stBCESTrade *pTrade){};

	/*行情查询应答*/
	virtual void OnQuotQueryRsp(stBCESQuot *pQuot,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*订单查询应答*/
	virtual void OnOrderQueryRsp(stBCESOrder *pOrder,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*成交查询应答*/
	virtual void OnTradeQueryRsp(stBCESTrade *pTrade,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*持仓查询应答*/
	virtual void OnPosiQueryRsp(stBCESPosi *pPosi,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*资金查询应答*/
	virtual void OnFundQueryRsp(stBCESFund *pFund,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*合约查询应答*/
	virtual void OnInstrumentQueryRsp(stBCESInstrument *pInstrument,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*持仓明细查询应答*/
	virtual void OnPosiDetailQueryRsp(stBCESPosiDetail *pPosiDetail,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*止赢止损设置应答*/
	virtual void OnProfitLossStopSetRsp(stBCESProfitLossStopSetRsp *pProfitLossStopSetRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*持仓明细通知*/
	virtual void OnPosiDetailNty(stBCESPosiDetail *pPosiDetail){};

	/*资金通知*/
	virtual void OnFundNty(stBCESFund *pFund){};

	/*持仓通知*/
	virtual void OnPosiNty(stBCESPosi *pPosi){};

	/*订单修改应答*/
	virtual void OnOrderModifyRsp(stBCESInputOrder *pInputOrder,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*公告查询应答*/
	virtual void OnBulletinQueryRsp(stBCESBulletin *pBulletin,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*通知查询应答*/
	virtual void OnNoticeQueryRsp(stBCESNotice *pNotice,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*公告通知*/
	virtual void OnBulletinNty(stBCESBulletin *pBulletin){};

	/*信息通知*/
	virtual void OnNoticeNty(stBCESNotice *pNotice){};

	/*电子出入金请求应答*/
	virtual void OnElectronicFundIORsp(stBCESElectronicFundIORsp *pElectronicFundIORsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*电子出入金通知*/
	virtual void OnElectronicFundIONty(stBCESElectronicFundIONty *pElectronicFundIONty){};

	/*出入金明细查询应答*/
	virtual void OnFundIODetailQueryRsp(stBCESFundIODetail *pFundIODetail,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*报表查询应答*/
	virtual void OnReportQueryRsp(stBCESReport *pReport,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*历史订单查询应答*/
	virtual void OnHisOrderQueryRsp(stBCESOrder *pOrder,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*历史成交查询应答*/
	virtual void OnHisTradeQueryRsp(stBCESTrade *pTrade,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*历史公告查询应答*/
	virtual void OnHisBulletinQueryRsp(stBCESBulletin *pBulletin,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*通知查询应答*/
	virtual void OnHisNoticeQueryRsp(stBCESNotice *pNotice,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*签约应答*/
	virtual void OnAccountBindRsp(stBCESAccountBindRsp *pAccountBindRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*签约信息查询应答*/
	virtual void OnAccountBindQueryRsp(stBCESAccountBind *pAccountBind,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*资金查询应答*/
	virtual void OnHisFundQueryRsp(stBCESFund *pFund,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*持仓明细查询应答*/
	virtual void OnHisPosiDetailQueryRsp(stBCESPosiDetail *pPosiDetail,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*签约通知*/
	virtual void OnAccountBindNty(stBCESAccountBind *pAccountBind){};
};

class TRADEAPI_LIB CBCESTradeApi
{
public:
	static CBCESTradeApi *CreateBCESTradeApi();	//创建API实现实例
	virtual void Release()=0;	//释放API实现实例
	virtual void RegisterSpi(CBCESTradeSpi* pSpi)=0;	//注册回调接口
	virtual int Run()=0;// 启动实例
	virtual int Stop()=0;// 停止实例
	virtual int SetServerAddress(const char* szServerAddress)=0;	// 注册前置地址，格式：127.0.0.1:20002，可以多次调用以注册多个前置地址
	virtual const char* GetErrorMessage(int ErrorNo)=0;	// 获取错误编号对应的描述信息

public:
	/*登录请求*/
	virtual int LoginReq(stBCESLoginReq *pLoginReq,UINT nRequestID)=0;

	/*登出请求*/
	virtual int LogoutReq(stBCESLogoutReq *pLogoutReq,UINT nRequestID)=0;

	/* 订阅推送信息 */
	/* 说明：
		1. 登录成功后可以调用此函数订阅私有流（订单回报、成交回报等个人信息）、公有流信息（市场状态、公告等公共信息）
		2. nPrivateResumeMethod为私有流订阅方式，有三种订阅方式：从起始点订阅，从断点订阅，从最新点订阅，如果不需要订阅私有流，则置0即可。
		3. nPublicResumeMethod为公共流订阅方式，有三种订阅方式：从起始点订阅，从断点订阅，从最新点订阅，如果不需要订阅公共流，则置0即可。
		4. 如果是断线重连后的再次订阅，则可以指定nMethod为BCESMacroFlowResumeMethodResume。
		5. 订阅方式：
			从起始点订阅：BCESMacroFlowResumeMethodRestart
			从断点订阅：BCESMacroFlowResumeMethodResume
			从最新点订阅：BCESMacroFlowResumeMethodQuick
	*/
	virtual int FlowSubscribeReq(UINT nPrivateResumeMethod,UINT nPublicResumeMethod)=0;

	/*修改密码请求*/
	virtual int ChangePasswordReq(stBCESChangePasswordReq *pChangePasswordReq,UINT nRequestID)=0;

	/*订单录入请求*/
	virtual int OrderInsertReq(stBCESInputOrder *pInputOrder,UINT nRequestID)=0;

	/*撤单请求*/
	virtual int OrderCancelReq(stBCESOrderCancelReq *pOrderCancelReq,UINT nRequestID)=0;

	/*行情查询请求*/
	virtual int QuotQueryReq(stBCESQuotQueryReq *pQuotQueryReq,UINT nRequestID)=0;

	/*订单查询请求*/
	virtual int OrderQueryReq(stBCESOrderQueryReq *pOrderQueryReq,UINT nRequestID)=0;

	/*成交查询请求*/
	virtual int TradeQueryReq(stBCESTradeQueryReq *pTradeQueryReq,UINT nRequestID)=0;

	/*持仓查询请求*/
	virtual int PosiQueryReq(stBCESPosiQueryReq *pPosiQueryReq,UINT nRequestID)=0;

	/*资金查询请求*/
	virtual int FundQueryReq(stBCESFundQueryReq *pFundQueryReq,UINT nRequestID)=0;

	/*合约查询请求*/
	virtual int InstrumentQueryReq(stBCESInstrumentQueryReq *pInstrumentQueryReq,UINT nRequestID)=0;

	/*持仓明细查询请求*/
	virtual int PosiDetailQueryReq(stBCESPosiDetailQueryReq *pPosiDetailQueryReq,UINT nRequestID)=0;

	/*止赢止损设置请求*/
	virtual int ProfitLossStopSetReq(stBCESProfitLossStopSetReq *pProfitLossStopSetReq,UINT nRequestID)=0;

	/*订单修改请求*/
	virtual int OrderModifyReq(stBCESInputOrder *pInputOrder,UINT nRequestID)=0;

	/*公告查询请求*/
	virtual int BulletinQueryReq(stBCESBulletinQueryReq *pBulletinQueryReq,UINT nRequestID)=0;

	/*通知查询请求*/
	virtual int NoticeQueryReq(stBCESNoticeQueryReq *pNoticeQueryReq,UINT nRequestID)=0;

	/*电子出入金请求*/
	virtual int ElectronicFundIOReq(stBCESElectronicFundIOReq *pElectronicFundIOReq,UINT nRequestID)=0;

	/*出入金明细查询请求*/
	virtual int FundIODetailQueryReq(stBCESFundIODetailQueryReq *pFundIODetailQueryReq,UINT nRequestID)=0;

	/*报表查询请求*/
	virtual int ReportQueryReq(stBCESReportQueryReq *pReportQueryReq,UINT nRequestID)=0;

	/*历史订单查询请求*/
	virtual int HisOrderQueryReq(stBCESHisOrderQueryReq *pHisOrderQueryReq,UINT nRequestID)=0;

	/*历史成交查询请求*/
	virtual int HisTradeQueryReq(stBCESHisTradeQueryReq *pHisTradeQueryReq,UINT nRequestID)=0;

	/*历史公告查询请求*/
	virtual int HisBulletinQueryReq(stBCESHisBulletinQueryReq *pHisBulletinQueryReq,UINT nRequestID)=0;

	/*历史通知查询请求*/
	virtual int HisNoticeQueryReq(stBCESHisNoticeQueryReq *pHisNoticeQueryReq,UINT nRequestID)=0;

	/*签约请求*/
	virtual int AccountBindReq(stBCESAccountBindReq *pAccountBindReq,UINT nRequestID)=0;

	/*签约信息查询请求*/
	virtual int AccountBindQueryReq(stBCESAccountBindQueryReq *pAccountBindQueryReq,UINT nRequestID)=0;

	/*资金查询请求*/
	virtual int HisFundQueryReq(stBCESHisFundQueryReq *pHisFundQueryReq,UINT nRequestID)=0;

	/*持仓明细查询请求*/
	virtual int HisPosiDetailQueryReq(stBCESHisPosiDetailQueryReq *pHisPosiDetailQueryReq,UINT nRequestID)=0;

protected:
	virtual ~CBCESTradeApi();	//析构函数
};

#endif /* __BCESTRADEAPI_H__ */
