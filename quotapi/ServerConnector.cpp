#include "ServerConnector.h"


using boost::asio::ip::tcp;

CServerConnector::CServerConnector(boost::asio::io_service& io,const char* servaddr,unsigned int nTcpSndSiz,unsigned int nTcpRcvSiz,unsigned short nHeartbeatTimeout,CBCESQuotApiImp* pApi):
	m_io(io),
	m_nTcpSndSiz(nTcpSndSiz),
	m_nTcpRcvSiz(nTcpRcvSiz),
	m_nHeartbeatTimeout(nHeartbeatTimeout),
    m_reconnecttimer(io,boost::posix_time::seconds(1)),
	m_pApi(pApi)
{
	const char* p=strchr(servaddr,':');
	memset(m_servip,0x00,sizeof(m_servip));
	memcpy(m_servip,servaddr,p-servaddr);
	m_servport=atol(p+1);
	m_bStoped=false;
}

CServerConnector::~CServerConnector()
{
	m_bStoped=true;
	if(m_pConnection)
		m_pConnection->Disconnect("Stoped");
}

int CServerConnector::AsyncConnect()
{
	char ServPort[100];
	sprintf(ServPort,"%d",m_servport);
	tcp::resolver resolver(m_io);
    tcp::resolver::query query(m_servip, ServPort);
    tcp::resolver::iterator iterator = resolver.resolve(query);

	boost::shared_ptr<CServerConnection> pNewConnection(new CServerConnection(m_io,m_nTcpSndSiz,m_nTcpRcvSiz,m_nHeartbeatTimeout,this));
	boost::asio::async_connect(pNewConnection->m_socket,iterator,boost::bind(&CServerConnector::HandleConnected,this,pNewConnection,boost::asio::placeholders::error));

	return 0;
}

void CServerConnector::HandleConnected(boost::shared_ptr<CServerConnection> pServerConnection,const boost::system::error_code& error)
{
	//if(m_bStoped)
	//	return;
	if(error){
		if(error==boost::asio::error::operation_aborted){
			//logsend(lp,LOG_WARN,"CServerConnector","connect canceled.");
			return;
		}
		// Set ReConnect Timer
        m_reconnecttimer.expires_from_now(boost::posix_time::seconds(1));
        m_reconnecttimer.async_wait(boost::bind(&CServerConnector::HandleReConnectTimeout,this,boost::asio::placeholders::error,pServerConnection));
		return;
	}
//	logsend(lp,LOG_DEBUG,"CServerConnector","Connected.");

	m_pConnection=pServerConnection;
	/* Init */
	pServerConnection->HandleConnected(pServerConnection);
}
void CServerConnector::HandleReConnectTimeout(const boost::system::error_code& error,boost::shared_ptr<CServerConnection> pAppConnection)
{
	// This function will be called when timer is canceled or time changed.
	if(error){
		if(error==boost::asio::error::operation_aborted){
			return;
		}
	}
    
    if(m_pConnection)
        return;
    
	// Connect
    char ServPort[100];
    sprintf(ServPort,"%d",m_servport);
    tcp::resolver resolver(m_io);
    tcp::resolver::query query(m_servip, ServPort);
    tcp::resolver::iterator iterator = resolver.resolve(query);
    boost::asio::async_connect(pAppConnection->m_socket,iterator,boost::bind(&CServerConnector::HandleConnected,this,pAppConnection,boost::asio::placeholders::error));
}
void CServerConnector::OnDisconnected(CServerConnection* pServerConnection)
{
	m_pConnection.reset();
	AsyncConnect();
}
