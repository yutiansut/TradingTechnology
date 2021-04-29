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
#include "BCESQuotApiImp.h"
#include <vector>

using boost::asio::ip::tcp;

class CBCESQuotApiImp;
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


	/*行情订阅请求*/
	int QuotSubscribeReq(stBCESQuotSubscribeReq& stQuotSubscribeReq,UINT nRequestID);

	/*行情退订请求*/
	int QuotUnSubscribeReq(stBCESQuotUnSubscribeReq& stQuotUnSubscribeReq,UINT nRequestID);

	/*分线查询请求*/
	int MinDataQueryReq(stBCESMinDataQueryReq& stMinDataQueryReq,UINT nRequestID);

	/*日线查询请求*/
	int DayDataQueryReq(stBCESDayDataQueryReq& stDayDataQueryReq,UINT nRequestID);

	/*5分线查询请求*/
	int Min5DataQueryReq(stBCESMinDataQueryReq& stMinDataQueryReq,UINT nRequestID);

	/*15分线查询请求*/
	int Min15DataQueryReq(stBCESMinDataQueryReq& stMinDataQueryReq,UINT nRequestID);

	/*成交明细查询请求*/
	int TradeDetailDataQueryReq(stBCESTradeDetailDataQueryReq& stTradeDetailDataQueryReq,UINT nRequestID);

	/* 应答 */

	/*登录应答*/
	int HandleLoginRsp(CAPIPackage& Package);

	/*登出应答*/
	int HandleLogoutRsp(CAPIPackage& Package);


	/*行情订阅应答*/
	int HandleQuotSubscribeRsp(CAPIPackage& Package);

	/*行情退订应答*/
	int HandleQuotUnSubscribeRsp(CAPIPackage& Package);

	/*分线查询应答*/
	int HandleMinDataQueryRsp(CAPIPackage& Package);

	/*日线查询应答*/
	int HandleDayDataQueryRsp(CAPIPackage& Package);

	/*5分线查询应答*/
	int HandleMin5DataQueryRsp(CAPIPackage& Package);

	/*15分线查询应答*/
	int HandleMin15DataQueryRsp(CAPIPackage& Package);

	/*成交明细查询应答*/
	int HandleTradeDetailDataQueryRsp(CAPIPackage& Package);

	/* 通知 */

	/*行情通知*/
	int HandleQuotNty(CAPIPackage& Package);

	boost::asio::io_service& m_io;
	boost::asio::deadline_timer m_recvtimer;
	boost::asio::deadline_timer m_sendtimer;
	unsigned int m_nTcpSndSiz;
	unsigned int m_nTcpRcvSiz;
	CServerConnector* m_pServerConnector;
	unsigned short m_nTimeout;

	CBCESQuotApiImp* m_pApi;
	boost::shared_ptr<CServerConnection> m_pConnection;
};

#endif /* __SERVER_CONNECTION__ */
