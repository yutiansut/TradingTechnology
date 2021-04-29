#ifndef __SERVER_CONNECTION__
#define __SERVER_CONNECTION__

#include "os.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "TcpConnection.h"
#include "ServerConnector.h"
#include "BCESPackage.h"
#include "APIPackage.h"
#include "APIFieldDefine.h"
#include "BCESTradeApiImp.h"
#include <vector>

using boost::asio::ip::tcp;

class CBCESTradeApiImp;
class CServerConnector;
class CServerConnection:public CTcpConnection
{
public:
	CServerConnection(boost::asio::io_service& io_service,unsigned int nTcpSndSiz,unsigned int nTcpRcvSiz,unsigned short nTimeout,CServerConnector* pServerConnector);
	~CServerConnection();


	char* m_recvbuf;
	unsigned int m_recvlen;
	char* m_sendbuf;

	// inherite from CTcpConnection
	void HandleDisconnected(const char* e);
	int HandleInput(const char* buf,unsigned int len);
	void HandleConnected(boost::shared_ptr<CServerConnection> pConnection);

	// Handle Server Messages
	void HandleHeartbeatRecvTimeout(const boost::system::error_code& error,boost::shared_ptr<CServerConnection> pConnection); // Heartbeat Check
	void HandleHeartbeatSendTimeout(const boost::system::error_code& error,boost::shared_ptr<CServerConnection> pConnection); // Heartbeat Check
	int HandleMessage(const char* msgbuf,unsigned int msglen);
	int SendMessage(const char* msgbuf,unsigned int msglen);
	void Disconnect(const char* e);
	int SendHeartbeatMessage();

	// Handle Package
	int HandlePackage(CAPIPackage& Package);
	int SendPackage(CAPIPackage& Package);

	/* 请求 */

	/*登录请求*/
	int LoginReq(stBCESLoginReq& stLoginReq,UINT nRequestID);

	/*登出请求*/
	int LogoutReq(stBCESLogoutReq& stLogoutReq,UINT nRequestID);

	/* 订阅推送信息 */
	int FlowSubscribeReq(UINT nPrivateResumeMethod,UINT nPublicResumeMethod);

	/*修改密码请求*/
	int ChangePasswordReq(stBCESChangePasswordReq& stChangePasswordReq,UINT nRequestID);

	/*订单录入请求*/
	int OrderInsertReq(stBCESInputOrder& stInputOrder,UINT nRequestID);

	/*撤单请求*/
	int OrderCancelReq(stBCESOrderCancelReq& stOrderCancelReq,UINT nRequestID);

	/*行情查询请求*/
	int QuotQueryReq(stBCESQuotQueryReq& stQuotQueryReq,UINT nRequestID);

	/*订单查询请求*/
	int OrderQueryReq(stBCESOrderQueryReq& stOrderQueryReq,UINT nRequestID);

	/*成交查询请求*/
	int TradeQueryReq(stBCESTradeQueryReq& stTradeQueryReq,UINT nRequestID);

	/*持仓查询请求*/
	int PosiQueryReq(stBCESPosiQueryReq& stPosiQueryReq,UINT nRequestID);

	/*资金查询请求*/
	int FundQueryReq(stBCESFundQueryReq& stFundQueryReq,UINT nRequestID);

	/*合约查询请求*/
	int InstrumentQueryReq(stBCESInstrumentQueryReq& stInstrumentQueryReq,UINT nRequestID);

	/*持仓明细查询请求*/
	int PosiDetailQueryReq(stBCESPosiDetailQueryReq& stPosiDetailQueryReq,UINT nRequestID);

	/*止赢止损设置请求*/
	int ProfitLossStopSetReq(stBCESProfitLossStopSetReq& stProfitLossStopSetReq,UINT nRequestID);

	/*订单修改请求*/
	int OrderModifyReq(stBCESInputOrder& stInputOrder,UINT nRequestID);

	/*公告查询请求*/
	int BulletinQueryReq(stBCESBulletinQueryReq& stBulletinQueryReq,UINT nRequestID);

	/*通知查询请求*/
	int NoticeQueryReq(stBCESNoticeQueryReq& stNoticeQueryReq,UINT nRequestID);

	/*电子出入金请求*/
	int ElectronicFundIOReq(stBCESElectronicFundIOReq& stElectronicFundIOReq,UINT nRequestID);

	/*出入金明细查询请求*/
	int FundIODetailQueryReq(stBCESFundIODetailQueryReq& stFundIODetailQueryReq,UINT nRequestID);

	/*报表查询请求*/
	int ReportQueryReq(stBCESReportQueryReq& stReportQueryReq,UINT nRequestID);

	/*历史订单查询请求*/
	int HisOrderQueryReq(stBCESHisOrderQueryReq& stHisOrderQueryReq,UINT nRequestID);

	/*历史成交查询请求*/
	int HisTradeQueryReq(stBCESHisTradeQueryReq& stHisTradeQueryReq,UINT nRequestID);

	/*历史公告查询请求*/
	int HisBulletinQueryReq(stBCESHisBulletinQueryReq& stHisBulletinQueryReq,UINT nRequestID);

	/*历史通知查询请求*/
	int HisNoticeQueryReq(stBCESHisNoticeQueryReq& stHisNoticeQueryReq,UINT nRequestID);

	/*签约请求*/
	int AccountBindReq(stBCESAccountBindReq& stAccountBindReq,UINT nRequestID);

	/*签约信息查询请求*/
	int AccountBindQueryReq(stBCESAccountBindQueryReq& stAccountBindQueryReq,UINT nRequestID);

	/*资金查询请求*/
	int HisFundQueryReq(stBCESHisFundQueryReq& stHisFundQueryReq,UINT nRequestID);

	/*持仓明细查询请求*/
	int HisPosiDetailQueryReq(stBCESHisPosiDetailQueryReq& stHisPosiDetailQueryReq,UINT nRequestID);

	/* 应答 */

	/*登录应答*/
	int HandleLoginRsp(CAPIPackage& Package);

	/*登出应答*/
	int HandleLogoutRsp(CAPIPackage& Package);

	/*流订阅应答*/
	int HandleFlowSubscribeRsp(CAPIPackage& Package);

	/*修改密码应答*/
	int HandleChangePasswordRsp(CAPIPackage& Package);

	/*订单录入应答*/
	int HandleOrderInsertRsp(CAPIPackage& Package);

	/*撤单应答*/
	int HandleOrderCancelRsp(CAPIPackage& Package);

	/*行情查询应答*/
	int HandleQuotQueryRsp(CAPIPackage& Package);

	/*订单查询应答*/
	int HandleOrderQueryRsp(CAPIPackage& Package);

	/*成交查询应答*/
	int HandleTradeQueryRsp(CAPIPackage& Package);

	/*持仓查询应答*/
	int HandlePosiQueryRsp(CAPIPackage& Package);

	/*资金查询应答*/
	int HandleFundQueryRsp(CAPIPackage& Package);

	/*合约查询应答*/
	int HandleInstrumentQueryRsp(CAPIPackage& Package);

	/*持仓明细查询应答*/
	int HandlePosiDetailQueryRsp(CAPIPackage& Package);

	/*止赢止损设置应答*/
	int HandleProfitLossStopSetRsp(CAPIPackage& Package);

	/*订单修改应答*/
	int HandleOrderModifyRsp(CAPIPackage& Package);

	/*公告查询应答*/
	int HandleBulletinQueryRsp(CAPIPackage& Package);

	/*通知查询应答*/
	int HandleNoticeQueryRsp(CAPIPackage& Package);

	/*电子出入金请求应答*/
	int HandleElectronicFundIORsp(CAPIPackage& Package);

	/*出入金明细查询应答*/
	int HandleFundIODetailQueryRsp(CAPIPackage& Package);

	/*报表查询应答*/
	int HandleReportQueryRsp(CAPIPackage& Package);

	/*历史订单查询应答*/
	int HandleHisOrderQueryRsp(CAPIPackage& Package);

	/*历史成交查询应答*/
	int HandleHisTradeQueryRsp(CAPIPackage& Package);

	/*历史公告查询应答*/
	int HandleHisBulletinQueryRsp(CAPIPackage& Package);

	/*通知查询应答*/
	int HandleHisNoticeQueryRsp(CAPIPackage& Package);

	/*签约应答*/
	int HandleAccountBindRsp(CAPIPackage& Package);

	/*签约信息查询应答*/
	int HandleAccountBindQueryRsp(CAPIPackage& Package);

	/*资金查询应答*/
	int HandleHisFundQueryRsp(CAPIPackage& Package);

	/*持仓明细查询应答*/
	int HandleHisPosiDetailQueryRsp(CAPIPackage& Package);

	/* 通知 */
	int HandlePrivateNty(CAPIPackage& Package);
	int HandlePublicNty(CAPIPackage& Package);

	/*订单通知*/
	int HandleOrderNty(CAPIPackage& Package);

	/*市场状态通知*/
	int HandleMarketStatusNty(CAPIPackage& Package);

	/*成交通知*/
	int HandleTradeNty(CAPIPackage& Package);

	/*持仓明细通知*/
	int HandlePosiDetailNty(CAPIPackage& Package);

	/*资金通知*/
	int HandleFundNty(CAPIPackage& Package);

	/*持仓通知*/
	int HandlePosiNty(CAPIPackage& Package);

	/*公告通知*/
	int HandleBulletinNty(CAPIPackage& Package);

	/*信息通知*/
	int HandleNoticeNty(CAPIPackage& Package);

	/*电子出入金通知*/
	int HandleElectronicFundIONty(CAPIPackage& Package);

	/*签约通知*/
	int HandleAccountBindNty(CAPIPackage& Package);

	boost::asio::io_service& m_io;
	boost::asio::deadline_timer m_recvtimer;
	boost::asio::deadline_timer m_sendtimer;
	unsigned int m_sessionid;
	unsigned int m_nTcpSndSiz;
	unsigned int m_nTcpRcvSiz;
	CServerConnector* m_pServerConnector;
	unsigned short m_nTimeout;

	CBCESTradeApiImp* m_pApi;
	boost::shared_ptr<CServerConnection> m_pConnection;
};

#endif /* __SERVER_CONNECTION__ */
