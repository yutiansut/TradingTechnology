#include "ServerConnector.h"
#include "ServerConnection.h"
#include "BMLRecordSet.h"
#include "BCESQuotApiImp.h"

using boost::asio::ip::tcp;

CServerConnection::CServerConnection(boost::asio::io_service& io_service,unsigned int nTcpSndSiz,unsigned int nTcpRcvSiz,unsigned short nTimeout,CServerConnector* pServerConnector):
	CTcpConnection(io_service,nTcpSndSiz,nTcpRcvSiz),
	m_io(io_service),
	m_nTimeout(nTimeout),
	m_recvtimer(io_service,boost::posix_time::seconds(nTimeout)),
	m_sendtimer(io_service,boost::posix_time::seconds(nTimeout/2)),
	m_pServerConnector(pServerConnector)
{
	m_recvlen=0;
	m_recvbuf=(char*)malloc(BCESMacroAPIPackageSize);
	m_sendbuf=(char*)malloc(BCESMacroAPIPackageSize);
	m_pApi=pServerConnector->m_pApi;
}

CServerConnection::~CServerConnection()
{
	free(m_recvbuf);
	free(m_sendbuf);
}

void CServerConnection::HandleConnected(boost::shared_ptr<CServerConnection> pConnection)
{
	m_pConnection=pConnection;
	CTcpConnection::HandleConnected(pConnection);
	m_recvtimer.expires_from_now(boost::posix_time::seconds(m_nTimeout));
	m_recvtimer.async_wait(boost::bind(&CServerConnection::HandleHeartbeatRecvTimeout,this,boost::asio::placeholders::error,pConnection));

	// Heartbeat Send Timer
	m_sendtimer.expires_from_now(boost::posix_time::seconds(m_nTimeout/2));
	m_sendtimer.async_wait(boost::bind(&CServerConnection::HandleHeartbeatSendTimeout,this,boost::asio::placeholders::error,m_pConnection));

	m_pApi->m_pSpi->OnConnected();
}

void CServerConnection::HandleHeartbeatRecvTimeout(const boost::system::error_code& error,boost::shared_ptr<CServerConnection> pConnection)
{
	if(m_bIsDead)
		return;
	// This function will be called when timer is canceled or time changed.
	if(error){
		if(error==boost::asio::error::operation_aborted){
			//logsend(lp,LOG_WARN,"CServerConnection","Timer canceled.");
			return;
		}
	}
	Disconnect("Disconnect because of heartbeat timeout!");
}

void CServerConnection::HandleHeartbeatSendTimeout(const boost::system::error_code& error,boost::shared_ptr<CServerConnection> pConnection)
{
	if(m_bIsDead)
		return;
	// This function will be called when timer is canceled or time changed.
	if(error){
		if(error==boost::asio::error::operation_aborted){
			//logsend(lp,LOG_WARN,"CServerConnection","Timer canceled.");
			return;
		}
	}
	SendHeartbeatMessage();
}

void CServerConnection::Disconnect(const char* e)
{
	CTcpConnection::Disconnect();
	HandleDisconnected(e);
}

void CServerConnection::HandleDisconnected(const char* e)
{
	//logsend(lp,LOG_WARN,"CServerConnection","Disconnected:%s[%s]",e,m_szRemoteIP);
	m_sendtimer.cancel();
	m_recvtimer.cancel();
	m_pConnection.reset();

	if(!m_pServerConnector->m_bStoped){
		m_pApi->m_pSpi->OnDisconnected();
		m_pServerConnector->OnDisconnected(this);
	}
}

int CServerConnection::HandleInput(const char* buf,unsigned int len)
{
	UINT msglen;
	int n;

	// reset timer.
	m_recvtimer.expires_from_now(boost::posix_time::seconds(m_nTimeout));
	m_recvtimer.async_wait(boost::bind(&CServerConnection::HandleHeartbeatRecvTimeout,this,boost::asio::placeholders::error,m_pConnection)); // wait again when time changed.

	// continue last message
	if(m_recvlen){
		if(m_recvlen<sizeof(msglen)){
			n=len>sizeof(msglen)-m_recvlen?sizeof(msglen)-m_recvlen:len;
			memcpy(m_recvbuf+m_recvlen,buf,n);
			m_recvlen+=n;
			len-=n;
			buf+=n;
			if(m_recvlen<sizeof(msglen))
				return 0;
		}
		memcpy(&msglen,m_recvbuf,sizeof(msglen));
		msglen=ntohl(msglen);
		if(msglen>BCESMacroAPIPackageSize-sizeof(msglen)){
			Disconnect("Disconnect because package is too large!");
			return -1;
		}
		n=len>msglen-(m_recvlen-sizeof(msglen))?msglen-(m_recvlen-sizeof(msglen)):len;
		memcpy(m_recvbuf+m_recvlen,buf,n);
		m_recvlen+=n;
		len-=n;
		buf+=n;
		if(m_recvlen-sizeof(msglen)!=msglen)
			return 0;
		if(HandleMessage(m_recvbuf+sizeof(msglen),msglen)<0){
			Disconnect("Disconnect because of an error in business processing!");
			return -1;
		}
		m_recvlen=0;
	}

	// process next message
	while(len>=sizeof(msglen)){
		memcpy(&msglen,buf,sizeof(msglen));
		msglen=ntohl(msglen);
		if(msglen>BCESMacroAPIPackageSize-sizeof(msglen)){
			Disconnect("Disconnect because package is too large!");
			return -1;
		}
		if(msglen>len-sizeof(msglen))
			break;
		if(HandleMessage(buf+sizeof(msglen),msglen)<0){
			Disconnect("Disconnect because of an error in business processing!");
			return -1;
		}
		buf+=sizeof(msglen)+msglen;
		len-=sizeof(msglen)+msglen;
	}

	// save uncompleted message
	if(len){
		memcpy(m_recvbuf,buf,len);
		m_recvlen=len;
	}

	return 0;
}

int CServerConnection::HandleMessage(const char* msgbuf,unsigned int msglen)
{
	CAPIPackage Package;

	Package.Init(msgbuf,msglen);

	return HandlePackage(Package);
}

int CServerConnection::HandlePackage(CAPIPackage& Package)
{
	int r=0;

	//logsend(lp,LOG_INFO,"CServerConnection","HandlePackage():Received a package.[%hd]",Package.GetServiceNo());
	switch(Package.GetServiceNo()){
		case BCESMsgTypeLoginRsp:	/* 登录应答 */
			r=HandleLoginRsp(Package);
			break;
		case BCESMsgTypeLogoutRsp:	/* 登出应答 */
			r=HandleLogoutRsp(Package);
			break;
		case BCESMsgTypeQuotSubscribeRsp:	/* 行情订阅应答 */
			r=HandleQuotSubscribeRsp(Package);
			break;
		case BCESMsgTypeQuotUnSubscribeRsp:	/* 行情退订应答 */
			r=HandleQuotUnSubscribeRsp(Package);
			break;
		case BCESMsgTypeQuotNty:	/* 行情通知 */
			r=HandleQuotNty(Package);
			break;
		case BCESMsgTypeMinDataQueryRsp:	/* 分线查询应答 */
			r=HandleMinDataQueryRsp(Package);
			break;
		case BCESMsgTypeDayDataQueryRsp:	/* 日线查询应答 */
			r=HandleDayDataQueryRsp(Package);
			break;
		case BCESMsgTypeMin5DataQueryRsp:	/* 5分线查询应答 */
			r=HandleMin5DataQueryRsp(Package);
			break;
		case BCESMsgTypeMin15DataQueryRsp:	/* 15分线查询应答 */
			r=HandleMin15DataQueryRsp(Package);
			break;
		case BCESMsgTypeTradeDetailDataQueryRsp:	/* 成交明细查询应答 */
			r=HandleTradeDetailDataQueryRsp(Package);
			break;
		case 0:	// Heartbeat
			break;
		default:
			break;
	}

	return r;
}

int CServerConnection::SendHeartbeatMessage()
{
	CAPIPackage Package;
	Package.Init(0,0,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	SendPackage(Package);

	return 0;
}


int CServerConnection::SendPackage(CAPIPackage& Package)
{
	SendMessage(Package.GetBuffer(),Package.GetLength());

	// reset sendtimer.
	m_sendtimer.expires_from_now(boost::posix_time::seconds(m_nTimeout/2));
	m_sendtimer.async_wait(boost::bind(&CServerConnection::HandleHeartbeatSendTimeout,this,boost::asio::placeholders::error,m_pConnection)); // wait again when time changed.

	return 0;
}

int CServerConnection::SendMessage(const char* msgbuf,unsigned int msglen)
{
	UINT length;

	length=htonl(msglen);
	memcpy(m_sendbuf,&length,sizeof(length));
	memcpy(m_sendbuf+sizeof(length),msgbuf,msglen);
	Send(m_sendbuf,msglen+sizeof(length));

	return 0;
}

/* 请求 */

/*登录请求*/
int CServerConnection::LoginReq(stBCESLoginReq& stLoginReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsLoginReq LoginReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeLoginReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// LoginReq
	memcpy(LoginReq.GetAddress(),&stLoginReq,sizeof(stBCESLoginReq));
	ReqPackage.PutFields(&LoginReq,BCESFieldNoLoginReq);

	SendPackage(ReqPackage);

	return 0;
}

/*登出请求*/
int CServerConnection::LogoutReq(stBCESLogoutReq& stLogoutReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsLogoutReq LogoutReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeLogoutReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// LogoutReq
	memcpy(LogoutReq.GetAddress(),&stLogoutReq,sizeof(stBCESLogoutReq));
	ReqPackage.PutFields(&LogoutReq,BCESFieldNoLogoutReq);

	SendPackage(ReqPackage);

	return 0;
}



/*行情订阅请求*/
int CServerConnection::QuotSubscribeReq(stBCESQuotSubscribeReq& stQuotSubscribeReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsQuotSubscribeReq QuotSubscribeReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeQuotSubscribeReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// QuotSubscribeReq
	memcpy(QuotSubscribeReq.GetAddress(),&stQuotSubscribeReq,sizeof(stBCESQuotSubscribeReq));
	ReqPackage.PutFields(&QuotSubscribeReq,BCESFieldNoQuotSubscribeReq);

	SendPackage(ReqPackage);

	return 0;
}

/*行情退订请求*/
int CServerConnection::QuotUnSubscribeReq(stBCESQuotUnSubscribeReq& stQuotUnSubscribeReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsQuotUnSubscribeReq QuotUnSubscribeReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeQuotUnSubscribeReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// QuotUnSubscribeReq
	memcpy(QuotUnSubscribeReq.GetAddress(),&stQuotUnSubscribeReq,sizeof(stBCESQuotUnSubscribeReq));
	ReqPackage.PutFields(&QuotUnSubscribeReq,BCESFieldNoQuotUnSubscribeReq);

	SendPackage(ReqPackage);

	return 0;
}

/*分线查询请求*/
int CServerConnection::MinDataQueryReq(stBCESMinDataQueryReq& stMinDataQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsMinDataQueryReq MinDataQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeMinDataQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// MinDataQueryReq
	memcpy(MinDataQueryReq.GetAddress(),&stMinDataQueryReq,sizeof(stBCESMinDataQueryReq));
	ReqPackage.PutFields(&MinDataQueryReq,BCESFieldNoMinDataQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*日线查询请求*/
int CServerConnection::DayDataQueryReq(stBCESDayDataQueryReq& stDayDataQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsDayDataQueryReq DayDataQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeDayDataQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// DayDataQueryReq
	memcpy(DayDataQueryReq.GetAddress(),&stDayDataQueryReq,sizeof(stBCESDayDataQueryReq));
	ReqPackage.PutFields(&DayDataQueryReq,BCESFieldNoDayDataQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*5分线查询请求*/
int CServerConnection::Min5DataQueryReq(stBCESMinDataQueryReq& stMinDataQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsMinDataQueryReq MinDataQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeMin5DataQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// MinDataQueryReq
	memcpy(MinDataQueryReq.GetAddress(),&stMinDataQueryReq,sizeof(stBCESMinDataQueryReq));
	ReqPackage.PutFields(&MinDataQueryReq,BCESFieldNoMinDataQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*15分线查询请求*/
int CServerConnection::Min15DataQueryReq(stBCESMinDataQueryReq& stMinDataQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsMinDataQueryReq MinDataQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeMin15DataQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// MinDataQueryReq
	memcpy(MinDataQueryReq.GetAddress(),&stMinDataQueryReq,sizeof(stBCESMinDataQueryReq));
	ReqPackage.PutFields(&MinDataQueryReq,BCESFieldNoMinDataQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*成交明细查询请求*/
int CServerConnection::TradeDetailDataQueryReq(stBCESTradeDetailDataQueryReq& stTradeDetailDataQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsTradeDetailDataQueryReq TradeDetailDataQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeTradeDetailDataQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// TradeDetailDataQueryReq
	memcpy(TradeDetailDataQueryReq.GetAddress(),&stTradeDetailDataQueryReq,sizeof(stBCESTradeDetailDataQueryReq));
	ReqPackage.PutFields(&TradeDetailDataQueryReq,BCESFieldNoTradeDetailDataQueryReq);

	SendPackage(ReqPackage);

	return 0;
}


/* 应答 */

/*登录应答*/
int CServerConnection::HandleLoginRsp(CAPIPackage& Package)
{
	//LoginRsp
	CBCESFieldsLoginRsp LoginRsp;
	stBCESLoginRsp stLoginRsp;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo;

	// LoginRsp
	Package.GetFields(&LoginRsp,BCESFieldNoLoginRsp);
	memcpy(&stLoginRsp,LoginRsp.GetAddress(),sizeof(stBCESLoginRsp));
	// RspInfo
	Package.GetFields(&RspInfo,BCESFieldNoRspInfo);
	memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));

	if(!RspInfo.RspNo){
		strcpy(m_pApi->m_TradeDate,LoginRsp.TradeDate);
	}

	m_pApi->m_pSpi->OnLoginRsp(&stLoginRsp,&stRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*登出应答*/
int CServerConnection::HandleLogoutRsp(CAPIPackage& Package)
{
	//LogoutRsp
	CBCESFieldsLogoutRsp LogoutRsp;
	stBCESLogoutRsp stLogoutRsp;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo;

	// LogoutRsp
	Package.GetFields(&LogoutRsp,BCESFieldNoLogoutRsp);
	memcpy(&stLogoutRsp,LogoutRsp.GetAddress(),sizeof(stBCESLogoutRsp));
	// RspInfo
	Package.GetFields(&RspInfo,BCESFieldNoRspInfo);
	memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));

	m_pApi->m_pSpi->OnLogoutRsp(&stLogoutRsp,&stRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}


/*行情订阅应答*/
int CServerConnection::HandleQuotSubscribeRsp(CAPIPackage& Package)
{
	//QuotSubscribeRsp
	CBCESFieldsQuotSubscribeRsp QuotSubscribeRsp;
	stBCESQuotSubscribeRsp stQuotSubscribeRsp,*pstQuotSubscribeRsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// QuotSubscribeRsp
	if(Package.GetFields(&QuotSubscribeRsp,BCESFieldNoQuotSubscribeRsp)>=0){
		memcpy(&stQuotSubscribeRsp,QuotSubscribeRsp.GetAddress(),sizeof(stBCESQuotSubscribeRsp));
		pstQuotSubscribeRsp=&stQuotSubscribeRsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnQuotSubscribeRsp(pstQuotSubscribeRsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*行情退订应答*/
int CServerConnection::HandleQuotUnSubscribeRsp(CAPIPackage& Package)
{
	//QuotUnSubscribeRsp
	CBCESFieldsQuotUnSubscribeRsp QuotUnSubscribeRsp;
	stBCESQuotUnSubscribeRsp stQuotUnSubscribeRsp,*pstQuotUnSubscribeRsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// QuotUnSubscribeRsp
	if(Package.GetFields(&QuotUnSubscribeRsp,BCESFieldNoQuotUnSubscribeRsp)>=0){
		memcpy(&stQuotUnSubscribeRsp,QuotUnSubscribeRsp.GetAddress(),sizeof(stBCESQuotUnSubscribeRsp));
		pstQuotUnSubscribeRsp=&stQuotUnSubscribeRsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnQuotUnSubscribeRsp(pstQuotUnSubscribeRsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*分线查询应答*/
int CServerConnection::HandleMinDataQueryRsp(CAPIPackage& Package)
{
	//MinData
	CBCESFieldsMinData MinData;
	stBCESMinData stMinData,*pstMinData=NULL;
	CBMLRecordSet MinDataList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// MinData
	Package.GetRecordSet(BCESFieldNoMinDataList,&MinDataList);
	if(MinDataList.Count()>0){
		while(MinDataList.Fetch(&MinData)){
			memcpy(&stMinData,MinData.GetAddress(),sizeof(stBCESMinData));
			pstMinData=&stMinData;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnMinDataQueryRsp(pstMinData,pstRspInfo,Package.GetRequestID(),MinDataList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnMinDataQueryRsp(pstMinData,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*日线查询应答*/
int CServerConnection::HandleDayDataQueryRsp(CAPIPackage& Package)
{
	//DayData
	CBCESFieldsDayData DayData;
	stBCESDayData stDayData,*pstDayData=NULL;
	CBMLRecordSet DayDataList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// DayData
	Package.GetRecordSet(BCESFieldNoDayDataList,&DayDataList);
	if(DayDataList.Count()>0){
		while(DayDataList.Fetch(&DayData)){
			memcpy(&stDayData,DayData.GetAddress(),sizeof(stBCESDayData));
			pstDayData=&stDayData;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnDayDataQueryRsp(pstDayData,pstRspInfo,Package.GetRequestID(),DayDataList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnDayDataQueryRsp(pstDayData,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*5分线查询应答*/
int CServerConnection::HandleMin5DataQueryRsp(CAPIPackage& Package)
{
	//MinData
	CBCESFieldsMinData MinData;
	stBCESMinData stMinData,*pstMinData=NULL;
	CBMLRecordSet MinDataList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// MinData
	Package.GetRecordSet(BCESFieldNoMinDataList,&MinDataList);
	if(MinDataList.Count()>0){
		while(MinDataList.Fetch(&MinData)){
			memcpy(&stMinData,MinData.GetAddress(),sizeof(stBCESMinData));
			pstMinData=&stMinData;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnMin5DataQueryRsp(pstMinData,pstRspInfo,Package.GetRequestID(),MinDataList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnMin5DataQueryRsp(pstMinData,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*15分线查询应答*/
int CServerConnection::HandleMin15DataQueryRsp(CAPIPackage& Package)
{
	//MinData
	CBCESFieldsMinData MinData;
	stBCESMinData stMinData,*pstMinData=NULL;
	CBMLRecordSet MinDataList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// MinData
	Package.GetRecordSet(BCESFieldNoMinDataList,&MinDataList);
	if(MinDataList.Count()>0){
		while(MinDataList.Fetch(&MinData)){
			memcpy(&stMinData,MinData.GetAddress(),sizeof(stBCESMinData));
			pstMinData=&stMinData;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnMin15DataQueryRsp(pstMinData,pstRspInfo,Package.GetRequestID(),MinDataList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnMin15DataQueryRsp(pstMinData,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*成交明细查询应答*/
int CServerConnection::HandleTradeDetailDataQueryRsp(CAPIPackage& Package)
{
	//TradeDetailData
	CBCESFieldsTradeDetailData TradeDetailData;
	stBCESTradeDetailData stTradeDetailData,*pstTradeDetailData=NULL;
	CBMLRecordSet TradeDetailDataList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// TradeDetailData
	Package.GetRecordSet(BCESFieldNoTradeDetailDataList,&TradeDetailDataList);
	if(TradeDetailDataList.Count()>0){
		while(TradeDetailDataList.Fetch(&TradeDetailData)){
			memcpy(&stTradeDetailData,TradeDetailData.GetAddress(),sizeof(stBCESTradeDetailData));
			pstTradeDetailData=&stTradeDetailData;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnTradeDetailDataQueryRsp(pstTradeDetailData,pstRspInfo,Package.GetRequestID(),TradeDetailDataList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnTradeDetailDataQueryRsp(pstTradeDetailData,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}


/* 通知 */


/*行情通知*/
int CServerConnection::HandleQuotNty(CAPIPackage& Package)
{
	//Quot
	CBCESFieldsQuot Quot;
	stBCESQuot stQuot;

	// Quot
	Package.GetFields(&Quot,BCESFieldNoQuot);
	memcpy(&stQuot,Quot.GetAddress(),sizeof(stBCESQuot));

	m_pApi->m_pSpi->OnQuotNty(&stQuot);

	return 0;
}
