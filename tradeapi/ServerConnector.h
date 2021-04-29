#ifndef __SERVER_LISTENER__
#define __SERVER_LISTENER__

#include "os.h"
#include <string>
#include <map>
#include "ServerConnection.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "BCESTradeApiImp.h"

using boost::asio::ip::tcp;

class CBCESTradeApiImp;
class CServerConnection;
class CServerConnector
{
public:
	CServerConnector(boost::asio::io_service& io_service,const char* servaddr,unsigned int nTcpSndSiz,unsigned int nTcpRcvSiz,unsigned short nHeartbeatTimeout,CBCESTradeApiImp* pApi);
	~CServerConnector();

	int AsyncConnect();
	void HandleConnected(boost::shared_ptr<CServerConnection> pServerConnection,const boost::system::error_code& error);
	void OnDisconnected(CServerConnection* pServerConnection);
	void HandleReConnectTimeout(const boost::system::error_code& error,boost::shared_ptr<CServerConnection> pAppConnection); // Reconnect

	boost::asio::io_service& m_io;
	unsigned int m_nTcpSndSiz;	// Tcp Send Buffer Size
	unsigned int m_nTcpRcvSiz;	// Tcp Recv Buffer Size
	unsigned short m_nHeartbeatTimeout;	// Heartbeat Timeout
	char m_servip[128];
	unsigned short m_servport;
	CBCESTradeApiImp* m_pApi;
	boost::shared_ptr<CServerConnection> m_pConnection;
	bool m_bStoped;
	boost::asio::deadline_timer m_reconnecttimer;	// Heartbeat Send Timer
};

#endif /* __SERVER_LISTENER__ */
