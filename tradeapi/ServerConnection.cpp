#include "ServerConnector.h"
#include "ServerConnection.h"
#include "BMLRecordSet.h"
#include "BCESTradeApiImp.h"

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
		case BCESMsgTypePrivatePkgNty:
			HandlePrivateNty(Package);
			break;
		case BCESMsgTypePublicPkgNty:
			HandlePublicNty(Package);
			break;
		case BCESMsgTypeLoginRsp:	/* 登录应答 */
			r=HandleLoginRsp(Package);
			break;
		case BCESMsgTypeLogoutRsp:	/* 登出应答 */
			r=HandleLogoutRsp(Package);
			break;
		case BCESMsgTypeFlowSubscribeRsp:
			r=HandleFlowSubscribeRsp(Package);
			break;
		case BCESMsgTypeChangePasswordRsp:	/* 修改密码应答 */
			r=HandleChangePasswordRsp(Package);
			break;
		case BCESMsgTypeOrderInsertRsp:	/* 订单录入应答 */
			r=HandleOrderInsertRsp(Package);
			break;
		case BCESMsgTypeOrderCancelRsp:	/* 撤单应答 */
			r=HandleOrderCancelRsp(Package);
			break;
		case BCESMsgTypeQuotQueryRsp:	/* 行情查询应答 */
			r=HandleQuotQueryRsp(Package);
			break;
		case BCESMsgTypeOrderQueryRsp:	/* 订单查询应答 */
			r=HandleOrderQueryRsp(Package);
			break;
		case BCESMsgTypeTradeQueryRsp:	/* 成交查询应答 */
			r=HandleTradeQueryRsp(Package);
			break;
		case BCESMsgTypePosiQueryRsp:	/* 持仓查询应答 */
			r=HandlePosiQueryRsp(Package);
			break;
		case BCESMsgTypeFundQueryRsp:	/* 资金查询应答 */
			r=HandleFundQueryRsp(Package);
			break;
		case BCESMsgTypeInstrumentQueryRsp:	/* 合约查询应答 */
			r=HandleInstrumentQueryRsp(Package);
			break;
		case BCESMsgTypePosiDetailQueryRsp:	/* 持仓明细查询应答 */
			r=HandlePosiDetailQueryRsp(Package);
			break;
		case BCESMsgTypeProfitLossStopSetRsp:	/* 止赢止损设置应答 */
			r=HandleProfitLossStopSetRsp(Package);
			break;
		case BCESMsgTypeOrderModifyRsp:	/* 订单修改应答 */
			r=HandleOrderModifyRsp(Package);
			break;
		case BCESMsgTypeBulletinQueryRsp:	/* 公告查询应答 */
			r=HandleBulletinQueryRsp(Package);
			break;
		case BCESMsgTypeNoticeQueryRsp:	/* 通知查询应答 */
			r=HandleNoticeQueryRsp(Package);
			break;
		case BCESMsgTypeElectronicFundIORsp:	/* 电子出入金请求应答 */
			r=HandleElectronicFundIORsp(Package);
			break;
		case BCESMsgTypeFundIODetailQueryRsp:	/* 出入金明细查询应答 */
			r=HandleFundIODetailQueryRsp(Package);
			break;
		case BCESMsgTypeReportQueryRsp:	/* 报表查询应答 */
			r=HandleReportQueryRsp(Package);
			break;
		case BCESMsgTypeHisOrderQueryRsp:	/* 历史订单查询应答 */
			r=HandleHisOrderQueryRsp(Package);
			break;
		case BCESMsgTypeHisTradeQueryRsp:	/* 历史成交查询应答 */
			r=HandleHisTradeQueryRsp(Package);
			break;
		case BCESMsgTypeHisBulletinQueryRsp:	/* 历史公告查询应答 */
			r=HandleHisBulletinQueryRsp(Package);
			break;
		case BCESMsgTypeHisNoticeQueryRsp:	/* 通知查询应答 */
			r=HandleHisNoticeQueryRsp(Package);
			break;
		case BCESMsgTypeAccountBindRsp:	/* 签约应答 */
			r=HandleAccountBindRsp(Package);
			break;
		case BCESMsgTypeAccountBindQueryRsp:	/* 签约信息查询应答 */
			r=HandleAccountBindQueryRsp(Package);
			break;
		case BCESMsgTypeHisFundQueryRsp:	/* 资金查询应答 */
			r=HandleHisFundQueryRsp(Package);
			break;
		case BCESMsgTypeHisPosiDetailQueryRsp:	/* 持仓明细查询应答 */
			r=HandleHisPosiDetailQueryRsp(Package);
			break;
		case BCESMsgTypeAccountBindNty:	/* 签约通知 */
			r=HandleAccountBindNty(Package);
			break;
		case 0:	// Heartbeat
			break;
		default:
			break;
	}

	return r;
}

int CServerConnection::HandlePrivateNty(CAPIPackage& Package)
{
	int r=0;

	if(Package.GetEndFlag()<=m_pApi->m_nPrivatePkgNo)
		return 0;
	switch(Package.GetRequestID()){
	case BCESMsgTypeOrderNty:	/* 订单通知 */
		r=HandleOrderNty(Package);
		break;
	case BCESMsgTypeTradeNty:	/* 成交通知 */
		r=HandleTradeNty(Package);
		break;
	case BCESMsgTypePosiDetailNty:	/* 持仓明细通知 */
		r=HandlePosiDetailNty(Package);
		break;
	case BCESMsgTypeFundNty:	/* 资金通知 */
		r=HandleFundNty(Package);
		break;
	case BCESMsgTypePosiNty:	/* 持仓通知 */
		r=HandlePosiNty(Package);
		break;
	case BCESMsgTypeNoticeNty:	/* 信息通知 */
		r=HandleNoticeNty(Package);
		break;
	case BCESMsgTypeElectronicFundIONty:	/* 电子出入金通知 */
		r=HandleElectronicFundIONty(Package);
		break;
	default:
		break;
	}
	m_pApi->m_nPrivatePkgNo=Package.GetEndFlag();

	return 0;
}

int CServerConnection::HandlePublicNty(CAPIPackage& Package)
{
	int r=0;

	if(Package.GetEndFlag()<=m_pApi->m_nPublicPkgNo)
		return 0;
	switch(Package.GetRequestID()){
	case BCESMsgTypeMarketStatusNty:	/* 市场状态通知 */
		r=HandleMarketStatusNty(Package);
		break;
	case BCESMsgTypeBulletinNty:	/* 公告通知 */
		r=HandleBulletinNty(Package);
		break;
	case BCESMsgTypeNoticeNty:	/* 信息通知 */
		r=HandleNoticeNty(Package);
		break;
	default:
		break;
	}
	m_pApi->m_nPublicPkgNo=Package.GetEndFlag();

	return 0;
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


/* 订阅推送信息 */
int CServerConnection::FlowSubscribeReq(UINT nPrivateResumeMethod,UINT nPublicResumeMethod)
{
	CAPIPackage ReqPackage;
	CBCESFieldsFlowSubscribeReq FlowSubscribeReq;
	CBMLRecordSet FlowSubscribeReqList;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeFlowSubscribeReq,0,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));
	// FlowSubscribeReqList
	ReqPackage.PutRecordSet(BCESFieldNoFlowSubscribeReqList,&FlowSubscribeReqList);

	// Subscribe Private Flow
	if(nPrivateResumeMethod){
		FlowSubscribeReq.FlowID=BCESConstFlowIDPrivate;
		if(nPrivateResumeMethod == BCESMacroFlowResumeMethodRestart){
			FlowSubscribeReq.PkgNo=0;
		}else if(nPrivateResumeMethod == BCESMacroFlowResumeMethodResume){
			FlowSubscribeReq.PkgNo=m_pApi->m_nPrivatePkgNo;
		}else{
			FlowSubscribeReq.PkgNo=(UINT)-1;
		}
		m_pApi->m_nPrivatePkgNo=FlowSubscribeReq.PkgNo;
		FlowSubscribeReqList.Insert(&FlowSubscribeReq);
	}
	
	// Subscribe Public Flow
	if(nPublicResumeMethod){
		FlowSubscribeReq.FlowID=BCESConstFlowIDPublic;
		if(nPublicResumeMethod == BCESMacroFlowResumeMethodRestart){
			FlowSubscribeReq.PkgNo=0;
		}else if(nPublicResumeMethod == BCESMacroFlowResumeMethodResume){
			FlowSubscribeReq.PkgNo=m_pApi->m_nPublicPkgNo;
		}else{
			FlowSubscribeReq.PkgNo=(UINT)-1;
		}
		m_pApi->m_nPublicPkgNo=FlowSubscribeReq.PkgNo;
		FlowSubscribeReqList.Insert(&FlowSubscribeReq);
	}

	SendPackage(ReqPackage);

	return 0;
}


/*修改密码请求*/
int CServerConnection::ChangePasswordReq(stBCESChangePasswordReq& stChangePasswordReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsChangePasswordReq ChangePasswordReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeChangePasswordReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// ChangePasswordReq
	memcpy(ChangePasswordReq.GetAddress(),&stChangePasswordReq,sizeof(stBCESChangePasswordReq));
	ReqPackage.PutFields(&ChangePasswordReq,BCESFieldNoChangePasswordReq);

	SendPackage(ReqPackage);

	return 0;
}

/*订单录入请求*/
int CServerConnection::OrderInsertReq(stBCESInputOrder& stInputOrder,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsInputOrder InputOrder;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeOrderInsertReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// InputOrder
	memcpy(InputOrder.GetAddress(),&stInputOrder,sizeof(stBCESInputOrder));
	ReqPackage.PutFields(&InputOrder,BCESFieldNoInputOrder);

	SendPackage(ReqPackage);

	return 0;
}

/*撤单请求*/
int CServerConnection::OrderCancelReq(stBCESOrderCancelReq& stOrderCancelReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsOrderCancelReq OrderCancelReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeOrderCancelReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// OrderCancelReq
	memcpy(OrderCancelReq.GetAddress(),&stOrderCancelReq,sizeof(stBCESOrderCancelReq));
	ReqPackage.PutFields(&OrderCancelReq,BCESFieldNoOrderCancelReq);

	SendPackage(ReqPackage);

	return 0;
}

/*行情查询请求*/
int CServerConnection::QuotQueryReq(stBCESQuotQueryReq& stQuotQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsQuotQueryReq QuotQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeQuotQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// QuotQueryReq
	memcpy(QuotQueryReq.GetAddress(),&stQuotQueryReq,sizeof(stBCESQuotQueryReq));
	ReqPackage.PutFields(&QuotQueryReq,BCESFieldNoQuotQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*订单查询请求*/
int CServerConnection::OrderQueryReq(stBCESOrderQueryReq& stOrderQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsOrderQueryReq OrderQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeOrderQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// OrderQueryReq
	memcpy(OrderQueryReq.GetAddress(),&stOrderQueryReq,sizeof(stBCESOrderQueryReq));
	ReqPackage.PutFields(&OrderQueryReq,BCESFieldNoOrderQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*成交查询请求*/
int CServerConnection::TradeQueryReq(stBCESTradeQueryReq& stTradeQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsTradeQueryReq TradeQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeTradeQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// TradeQueryReq
	memcpy(TradeQueryReq.GetAddress(),&stTradeQueryReq,sizeof(stBCESTradeQueryReq));
	ReqPackage.PutFields(&TradeQueryReq,BCESFieldNoTradeQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*持仓查询请求*/
int CServerConnection::PosiQueryReq(stBCESPosiQueryReq& stPosiQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsPosiQueryReq PosiQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypePosiQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// PosiQueryReq
	memcpy(PosiQueryReq.GetAddress(),&stPosiQueryReq,sizeof(stBCESPosiQueryReq));
	ReqPackage.PutFields(&PosiQueryReq,BCESFieldNoPosiQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*资金查询请求*/
int CServerConnection::FundQueryReq(stBCESFundQueryReq& stFundQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsFundQueryReq FundQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeFundQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// FundQueryReq
	memcpy(FundQueryReq.GetAddress(),&stFundQueryReq,sizeof(stBCESFundQueryReq));
	ReqPackage.PutFields(&FundQueryReq,BCESFieldNoFundQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*合约查询请求*/
int CServerConnection::InstrumentQueryReq(stBCESInstrumentQueryReq& stInstrumentQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsInstrumentQueryReq InstrumentQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeInstrumentQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// InstrumentQueryReq
	memcpy(InstrumentQueryReq.GetAddress(),&stInstrumentQueryReq,sizeof(stBCESInstrumentQueryReq));
	ReqPackage.PutFields(&InstrumentQueryReq,BCESFieldNoInstrumentQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*持仓明细查询请求*/
int CServerConnection::PosiDetailQueryReq(stBCESPosiDetailQueryReq& stPosiDetailQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsPosiDetailQueryReq PosiDetailQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypePosiDetailQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// PosiDetailQueryReq
	memcpy(PosiDetailQueryReq.GetAddress(),&stPosiDetailQueryReq,sizeof(stBCESPosiDetailQueryReq));
	ReqPackage.PutFields(&PosiDetailQueryReq,BCESFieldNoPosiDetailQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*止赢止损设置请求*/
int CServerConnection::ProfitLossStopSetReq(stBCESProfitLossStopSetReq& stProfitLossStopSetReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsProfitLossStopSetReq ProfitLossStopSetReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeProfitLossStopSetReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// ProfitLossStopSetReq
	memcpy(ProfitLossStopSetReq.GetAddress(),&stProfitLossStopSetReq,sizeof(stBCESProfitLossStopSetReq));
	ReqPackage.PutFields(&ProfitLossStopSetReq,BCESFieldNoProfitLossStopSetReq);

	SendPackage(ReqPackage);

	return 0;
}

/*订单修改请求*/
int CServerConnection::OrderModifyReq(stBCESInputOrder& stInputOrder,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsInputOrder InputOrder;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeOrderModifyReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// InputOrder
	memcpy(InputOrder.GetAddress(),&stInputOrder,sizeof(stBCESInputOrder));
	ReqPackage.PutFields(&InputOrder,BCESFieldNoInputOrder);

	SendPackage(ReqPackage);

	return 0;
}

/*公告查询请求*/
int CServerConnection::BulletinQueryReq(stBCESBulletinQueryReq& stBulletinQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsBulletinQueryReq BulletinQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeBulletinQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// BulletinQueryReq
	memcpy(BulletinQueryReq.GetAddress(),&stBulletinQueryReq,sizeof(stBCESBulletinQueryReq));
	ReqPackage.PutFields(&BulletinQueryReq,BCESFieldNoBulletinQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*通知查询请求*/
int CServerConnection::NoticeQueryReq(stBCESNoticeQueryReq& stNoticeQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsNoticeQueryReq NoticeQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeNoticeQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// NoticeQueryReq
	memcpy(NoticeQueryReq.GetAddress(),&stNoticeQueryReq,sizeof(stBCESNoticeQueryReq));
	ReqPackage.PutFields(&NoticeQueryReq,BCESFieldNoNoticeQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*电子出入金请求*/
int CServerConnection::ElectronicFundIOReq(stBCESElectronicFundIOReq& stElectronicFundIOReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsElectronicFundIOReq ElectronicFundIOReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeElectronicFundIOReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// ElectronicFundIOReq
	memcpy(ElectronicFundIOReq.GetAddress(),&stElectronicFundIOReq,sizeof(stBCESElectronicFundIOReq));
	ReqPackage.PutFields(&ElectronicFundIOReq,BCESFieldNoElectronicFundIOReq);

	SendPackage(ReqPackage);

	return 0;
}

/*出入金明细查询请求*/
int CServerConnection::FundIODetailQueryReq(stBCESFundIODetailQueryReq& stFundIODetailQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsFundIODetailQueryReq FundIODetailQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeFundIODetailQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// FundIODetailQueryReq
	memcpy(FundIODetailQueryReq.GetAddress(),&stFundIODetailQueryReq,sizeof(stBCESFundIODetailQueryReq));
	ReqPackage.PutFields(&FundIODetailQueryReq,BCESFieldNoFundIODetailQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*报表查询请求*/
int CServerConnection::ReportQueryReq(stBCESReportQueryReq& stReportQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsReportQueryReq ReportQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeReportQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// ReportQueryReq
	memcpy(ReportQueryReq.GetAddress(),&stReportQueryReq,sizeof(stBCESReportQueryReq));
	ReqPackage.PutFields(&ReportQueryReq,BCESFieldNoReportQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*历史订单查询请求*/
int CServerConnection::HisOrderQueryReq(stBCESHisOrderQueryReq& stHisOrderQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsHisOrderQueryReq HisOrderQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeHisOrderQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// HisOrderQueryReq
	memcpy(HisOrderQueryReq.GetAddress(),&stHisOrderQueryReq,sizeof(stBCESHisOrderQueryReq));
	ReqPackage.PutFields(&HisOrderQueryReq,BCESFieldNoHisOrderQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*历史成交查询请求*/
int CServerConnection::HisTradeQueryReq(stBCESHisTradeQueryReq& stHisTradeQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsHisTradeQueryReq HisTradeQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeHisTradeQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// HisTradeQueryReq
	memcpy(HisTradeQueryReq.GetAddress(),&stHisTradeQueryReq,sizeof(stBCESHisTradeQueryReq));
	ReqPackage.PutFields(&HisTradeQueryReq,BCESFieldNoHisTradeQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*历史公告查询请求*/
int CServerConnection::HisBulletinQueryReq(stBCESHisBulletinQueryReq& stHisBulletinQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsHisBulletinQueryReq HisBulletinQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeHisBulletinQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// HisBulletinQueryReq
	memcpy(HisBulletinQueryReq.GetAddress(),&stHisBulletinQueryReq,sizeof(stBCESHisBulletinQueryReq));
	ReqPackage.PutFields(&HisBulletinQueryReq,BCESFieldNoHisBulletinQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*历史通知查询请求*/
int CServerConnection::HisNoticeQueryReq(stBCESHisNoticeQueryReq& stHisNoticeQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsHisNoticeQueryReq HisNoticeQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeHisNoticeQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// HisNoticeQueryReq
	memcpy(HisNoticeQueryReq.GetAddress(),&stHisNoticeQueryReq,sizeof(stBCESHisNoticeQueryReq));
	ReqPackage.PutFields(&HisNoticeQueryReq,BCESFieldNoHisNoticeQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*签约请求*/
int CServerConnection::AccountBindReq(stBCESAccountBindReq& stAccountBindReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsAccountBindReq AccountBindReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeAccountBindReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// AccountBindReq
	memcpy(AccountBindReq.GetAddress(),&stAccountBindReq,sizeof(stBCESAccountBindReq));
	ReqPackage.PutFields(&AccountBindReq,BCESFieldNoAccountBindReq);

	SendPackage(ReqPackage);

	return 0;
}

/*签约信息查询请求*/
int CServerConnection::AccountBindQueryReq(stBCESAccountBindQueryReq& stAccountBindQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsAccountBindQueryReq AccountBindQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeAccountBindQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// AccountBindQueryReq
	memcpy(AccountBindQueryReq.GetAddress(),&stAccountBindQueryReq,sizeof(stBCESAccountBindQueryReq));
	ReqPackage.PutFields(&AccountBindQueryReq,BCESFieldNoAccountBindQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*资金查询请求*/
int CServerConnection::HisFundQueryReq(stBCESHisFundQueryReq& stHisFundQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsHisFundQueryReq HisFundQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeHisFundQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// HisFundQueryReq
	memcpy(HisFundQueryReq.GetAddress(),&stHisFundQueryReq,sizeof(stBCESHisFundQueryReq));
	ReqPackage.PutFields(&HisFundQueryReq,BCESFieldNoHisFundQueryReq);

	SendPackage(ReqPackage);

	return 0;
}

/*持仓明细查询请求*/
int CServerConnection::HisPosiDetailQueryReq(stBCESHisPosiDetailQueryReq& stHisPosiDetailQueryReq,UINT nRequestID)
{
	CAPIPackage ReqPackage;
	CBCESFieldsHisPosiDetailQueryReq HisPosiDetailQueryReq;

	if(m_bIsDead)
		return -1;

	ReqPackage.Init(BCESMsgTypeHisPosiDetailQueryReq,nRequestID,0,m_sendbuf+sizeof(UINT),BCESMacroAPIPackageSize-sizeof(UINT));

	// HisPosiDetailQueryReq
	memcpy(HisPosiDetailQueryReq.GetAddress(),&stHisPosiDetailQueryReq,sizeof(stBCESHisPosiDetailQueryReq));
	ReqPackage.PutFields(&HisPosiDetailQueryReq,BCESFieldNoHisPosiDetailQueryReq);

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
		if(strcmp(m_pApi->m_TradeDate,LoginRsp.TradeDate)!=0){
			// Reset FlowNo
			m_pApi->m_nPrivatePkgNo=0;
			m_pApi->m_nPublicPkgNo=0;
		}
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

/*流订阅应答*/
int CServerConnection::HandleFlowSubscribeRsp(CAPIPackage& Package)
{
	//ChangePasswordRsp
	CBCESFieldsFlowSubscribeRsp FlowSubscribeRsp;
	CBMLRecordSet FlowSubscribeRspList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;

	// RspInfo
	Package.GetFields(&RspInfo,BCESFieldNoRspInfo);

	if(RspInfo.RspNo)
		return 0;

	// FlowSubscribeRspList
	Package.GetRecordSet(BCESFieldNoFlowSubscribeRspList,&FlowSubscribeRspList);
	if(FlowSubscribeRspList.Count()>0){
		// FlowSubscribeRsp
		while(FlowSubscribeRspList.Fetch(&FlowSubscribeRsp)){
			if(FlowSubscribeRsp.FlowID==BCESConstFlowIDPrivate){
				m_pApi->m_nPrivatePkgNo=FlowSubscribeRsp.PkgNo;
			}else{
				m_pApi->m_nPublicPkgNo=FlowSubscribeRsp.PkgNo;
			}
		}
	}

	return 0;
}

/*修改密码应答*/
int CServerConnection::HandleChangePasswordRsp(CAPIPackage& Package)
{
	//ChangePasswordRsp
	CBCESFieldsChangePasswordRsp ChangePasswordRsp;
	stBCESChangePasswordRsp stChangePasswordRsp,*pstChangePasswordRsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// ChangePasswordRsp
	if(Package.GetFields(&ChangePasswordRsp,BCESFieldNoChangePasswordRsp)>=0){
		memcpy(&stChangePasswordRsp,ChangePasswordRsp.GetAddress(),sizeof(stBCESChangePasswordRsp));
		pstChangePasswordRsp=&stChangePasswordRsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnChangePasswordRsp(pstChangePasswordRsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*订单录入应答*/
int CServerConnection::HandleOrderInsertRsp(CAPIPackage& Package)
{
	//InputOrder
	CBCESFieldsInputOrder InputOrder;
	stBCESInputOrder stInputOrder,*pstInputOrder=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// InputOrder
	if(Package.GetFields(&InputOrder,BCESFieldNoInputOrder)>=0){
		memcpy(&stInputOrder,InputOrder.GetAddress(),sizeof(stBCESInputOrder));
		pstInputOrder=&stInputOrder;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnOrderInsertRsp(pstInputOrder,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*撤单应答*/
int CServerConnection::HandleOrderCancelRsp(CAPIPackage& Package)
{
	//OrderCancelRsp
	CBCESFieldsOrderCancelRsp OrderCancelRsp;
	stBCESOrderCancelRsp stOrderCancelRsp,*pstOrderCancelRsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// OrderCancelRsp
	if(Package.GetFields(&OrderCancelRsp,BCESFieldNoOrderCancelRsp)>=0){
		memcpy(&stOrderCancelRsp,OrderCancelRsp.GetAddress(),sizeof(stBCESOrderCancelRsp));
		pstOrderCancelRsp=&stOrderCancelRsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnOrderCancelRsp(pstOrderCancelRsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*行情查询应答*/
int CServerConnection::HandleQuotQueryRsp(CAPIPackage& Package)
{
	//Quot
	CBCESFieldsQuot Quot;
	stBCESQuot stQuot,*pstQuot=NULL;
	CBMLRecordSet QuotList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Quot
	Package.GetRecordSet(BCESFieldNoQuotList,&QuotList);
	if(QuotList.Count()>0){
		while(QuotList.Fetch(&Quot)){
			memcpy(&stQuot,Quot.GetAddress(),sizeof(stBCESQuot));
			pstQuot=&stQuot;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnQuotQueryRsp(pstQuot,pstRspInfo,Package.GetRequestID(),QuotList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnQuotQueryRsp(pstQuot,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*订单查询应答*/
int CServerConnection::HandleOrderQueryRsp(CAPIPackage& Package)
{
	//Order
	CBCESFieldsOrder Order;
	stBCESOrder stOrder,*pstOrder=NULL;
	CBMLRecordSet OrderList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Order
	Package.GetRecordSet(BCESFieldNoOrderList,&OrderList);
	if(OrderList.Count()>0){
		while(OrderList.Fetch(&Order)){
			memcpy(&stOrder,Order.GetAddress(),sizeof(stBCESOrder));
			pstOrder=&stOrder;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnOrderQueryRsp(pstOrder,pstRspInfo,Package.GetRequestID(),OrderList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnOrderQueryRsp(pstOrder,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*成交查询应答*/
int CServerConnection::HandleTradeQueryRsp(CAPIPackage& Package)
{
	//Trade
	CBCESFieldsTrade Trade;
	stBCESTrade stTrade,*pstTrade=NULL;
	CBMLRecordSet TradeList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Trade
	Package.GetRecordSet(BCESFieldNoTradeList,&TradeList);
	if(TradeList.Count()>0){
		while(TradeList.Fetch(&Trade)){
			memcpy(&stTrade,Trade.GetAddress(),sizeof(stBCESTrade));
			pstTrade=&stTrade;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnTradeQueryRsp(pstTrade,pstRspInfo,Package.GetRequestID(),TradeList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnTradeQueryRsp(pstTrade,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*持仓查询应答*/
int CServerConnection::HandlePosiQueryRsp(CAPIPackage& Package)
{
	//Posi
	CBCESFieldsPosi Posi;
	stBCESPosi stPosi,*pstPosi=NULL;
	CBMLRecordSet PosiList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Posi
	Package.GetRecordSet(BCESFieldNoPosiList,&PosiList);
	if(PosiList.Count()>0){
		while(PosiList.Fetch(&Posi)){
			memcpy(&stPosi,Posi.GetAddress(),sizeof(stBCESPosi));
			pstPosi=&stPosi;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnPosiQueryRsp(pstPosi,pstRspInfo,Package.GetRequestID(),PosiList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnPosiQueryRsp(pstPosi,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*资金查询应答*/
int CServerConnection::HandleFundQueryRsp(CAPIPackage& Package)
{
	//Fund
	CBCESFieldsFund Fund;
	stBCESFund stFund,*pstFund=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Fund
	if(Package.GetFields(&Fund,BCESFieldNoFund)>=0){
		memcpy(&stFund,Fund.GetAddress(),sizeof(stBCESFund));
		pstFund=&stFund;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnFundQueryRsp(pstFund,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*合约查询应答*/
int CServerConnection::HandleInstrumentQueryRsp(CAPIPackage& Package)
{
	//Instrument
	CBCESFieldsInstrument Instrument;
	stBCESInstrument stInstrument,*pstInstrument=NULL;
	CBMLRecordSet InstrumentList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Instrument
	Package.GetRecordSet(BCESFieldNoInstrumentList,&InstrumentList);
	if(InstrumentList.Count()>0){
		while(InstrumentList.Fetch(&Instrument)){
			memcpy(&stInstrument,Instrument.GetAddress(),sizeof(stBCESInstrument));
			pstInstrument=&stInstrument;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnInstrumentQueryRsp(pstInstrument,pstRspInfo,Package.GetRequestID(),InstrumentList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnInstrumentQueryRsp(pstInstrument,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*持仓明细查询应答*/
int CServerConnection::HandlePosiDetailQueryRsp(CAPIPackage& Package)
{
	//PosiDetail
	CBCESFieldsPosiDetail PosiDetail;
	stBCESPosiDetail stPosiDetail,*pstPosiDetail=NULL;
	CBMLRecordSet PosiDetailList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// PosiDetail
	Package.GetRecordSet(BCESFieldNoPosiDetailList,&PosiDetailList);
	if(PosiDetailList.Count()>0){
		while(PosiDetailList.Fetch(&PosiDetail)){
			memcpy(&stPosiDetail,PosiDetail.GetAddress(),sizeof(stBCESPosiDetail));
			pstPosiDetail=&stPosiDetail;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnPosiDetailQueryRsp(pstPosiDetail,pstRspInfo,Package.GetRequestID(),PosiDetailList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnPosiDetailQueryRsp(pstPosiDetail,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*止赢止损设置应答*/
int CServerConnection::HandleProfitLossStopSetRsp(CAPIPackage& Package)
{
	//ProfitLossStopSetRsp
	CBCESFieldsProfitLossStopSetRsp ProfitLossStopSetRsp;
	stBCESProfitLossStopSetRsp stProfitLossStopSetRsp,*pstProfitLossStopSetRsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// ProfitLossStopSetRsp
	if(Package.GetFields(&ProfitLossStopSetRsp,BCESFieldNoProfitLossStopSetRsp)>=0){
		memcpy(&stProfitLossStopSetRsp,ProfitLossStopSetRsp.GetAddress(),sizeof(stBCESProfitLossStopSetRsp));
		pstProfitLossStopSetRsp=&stProfitLossStopSetRsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnProfitLossStopSetRsp(pstProfitLossStopSetRsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*订单修改应答*/
int CServerConnection::HandleOrderModifyRsp(CAPIPackage& Package)
{
	//InputOrder
	CBCESFieldsInputOrder InputOrder;
	stBCESInputOrder stInputOrder,*pstInputOrder=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// InputOrder
	if(Package.GetFields(&InputOrder,BCESFieldNoInputOrder)>=0){
		memcpy(&stInputOrder,InputOrder.GetAddress(),sizeof(stBCESInputOrder));
		pstInputOrder=&stInputOrder;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnOrderModifyRsp(pstInputOrder,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*公告查询应答*/
int CServerConnection::HandleBulletinQueryRsp(CAPIPackage& Package)
{
	//Bulletin
	CBCESFieldsBulletin Bulletin;
	stBCESBulletin stBulletin,*pstBulletin=NULL;
	CBMLRecordSet BulletinList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Bulletin
	Package.GetRecordSet(BCESFieldNoBulletinList,&BulletinList);
	if(BulletinList.Count()>0){
		while(BulletinList.Fetch(&Bulletin)){
			memcpy(&stBulletin,Bulletin.GetAddress(),sizeof(stBCESBulletin));
			pstBulletin=&stBulletin;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnBulletinQueryRsp(pstBulletin,pstRspInfo,Package.GetRequestID(),BulletinList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnBulletinQueryRsp(pstBulletin,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*通知查询应答*/
int CServerConnection::HandleNoticeQueryRsp(CAPIPackage& Package)
{
	//Notice
	CBCESFieldsNotice Notice;
	stBCESNotice stNotice,*pstNotice=NULL;
	CBMLRecordSet NoticeList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Notice
	Package.GetRecordSet(BCESFieldNoNoticeList,&NoticeList);
	if(NoticeList.Count()>0){
		while(NoticeList.Fetch(&Notice)){
			memcpy(&stNotice,Notice.GetAddress(),sizeof(stBCESNotice));
			pstNotice=&stNotice;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnNoticeQueryRsp(pstNotice,pstRspInfo,Package.GetRequestID(),NoticeList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnNoticeQueryRsp(pstNotice,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*电子出入金请求应答*/
int CServerConnection::HandleElectronicFundIORsp(CAPIPackage& Package)
{
	//ElectronicFundIORsp
	CBCESFieldsElectronicFundIORsp ElectronicFundIORsp;
	stBCESElectronicFundIORsp stElectronicFundIORsp,*pstElectronicFundIORsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// ElectronicFundIORsp
	if(Package.GetFields(&ElectronicFundIORsp,BCESFieldNoElectronicFundIORsp)>=0){
		memcpy(&stElectronicFundIORsp,ElectronicFundIORsp.GetAddress(),sizeof(stBCESElectronicFundIORsp));
		pstElectronicFundIORsp=&stElectronicFundIORsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnElectronicFundIORsp(pstElectronicFundIORsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*出入金明细查询应答*/
int CServerConnection::HandleFundIODetailQueryRsp(CAPIPackage& Package)
{
	//FundIODetail
	CBCESFieldsFundIODetail FundIODetail;
	stBCESFundIODetail stFundIODetail,*pstFundIODetail=NULL;
	CBMLRecordSet FundIODetailList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// FundIODetail
	Package.GetRecordSet(BCESFieldNoFundIODetailList,&FundIODetailList);
	if(FundIODetailList.Count()>0){
		while(FundIODetailList.Fetch(&FundIODetail)){
			memcpy(&stFundIODetail,FundIODetail.GetAddress(),sizeof(stBCESFundIODetail));
			pstFundIODetail=&stFundIODetail;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnFundIODetailQueryRsp(pstFundIODetail,pstRspInfo,Package.GetRequestID(),FundIODetailList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnFundIODetailQueryRsp(pstFundIODetail,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*报表查询应答*/
int CServerConnection::HandleReportQueryRsp(CAPIPackage& Package)
{
	//Report
	CBCESFieldsReport Report;
	stBCESReport stReport,*pstReport=NULL;
	CBMLRecordSet ReportList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Report
	Package.GetRecordSet(BCESFieldNoReportList,&ReportList);
	if(ReportList.Count()>0){
		while(ReportList.Fetch(&Report)){
			memcpy(&stReport,Report.GetAddress(),sizeof(stBCESReport));
			pstReport=&stReport;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnReportQueryRsp(pstReport,pstRspInfo,Package.GetRequestID(),ReportList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnReportQueryRsp(pstReport,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*历史订单查询应答*/
int CServerConnection::HandleHisOrderQueryRsp(CAPIPackage& Package)
{
	//Order
	CBCESFieldsOrder Order;
	stBCESOrder stOrder,*pstOrder=NULL;
	CBMLRecordSet OrderList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Order
	Package.GetRecordSet(BCESFieldNoOrderList,&OrderList);
	if(OrderList.Count()>0){
		while(OrderList.Fetch(&Order)){
			memcpy(&stOrder,Order.GetAddress(),sizeof(stBCESOrder));
			pstOrder=&stOrder;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnHisOrderQueryRsp(pstOrder,pstRspInfo,Package.GetRequestID(),OrderList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnHisOrderQueryRsp(pstOrder,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*历史成交查询应答*/
int CServerConnection::HandleHisTradeQueryRsp(CAPIPackage& Package)
{
	//Trade
	CBCESFieldsTrade Trade;
	stBCESTrade stTrade,*pstTrade=NULL;
	CBMLRecordSet TradeList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Trade
	Package.GetRecordSet(BCESFieldNoTradeList,&TradeList);
	if(TradeList.Count()>0){
		while(TradeList.Fetch(&Trade)){
			memcpy(&stTrade,Trade.GetAddress(),sizeof(stBCESTrade));
			pstTrade=&stTrade;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnHisTradeQueryRsp(pstTrade,pstRspInfo,Package.GetRequestID(),TradeList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnHisTradeQueryRsp(pstTrade,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*历史公告查询应答*/
int CServerConnection::HandleHisBulletinQueryRsp(CAPIPackage& Package)
{
	//Bulletin
	CBCESFieldsBulletin Bulletin;
	stBCESBulletin stBulletin,*pstBulletin=NULL;
	CBMLRecordSet BulletinList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Bulletin
	Package.GetRecordSet(BCESFieldNoBulletinList,&BulletinList);
	if(BulletinList.Count()>0){
		while(BulletinList.Fetch(&Bulletin)){
			memcpy(&stBulletin,Bulletin.GetAddress(),sizeof(stBCESBulletin));
			pstBulletin=&stBulletin;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnHisBulletinQueryRsp(pstBulletin,pstRspInfo,Package.GetRequestID(),BulletinList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnHisBulletinQueryRsp(pstBulletin,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*通知查询应答*/
int CServerConnection::HandleHisNoticeQueryRsp(CAPIPackage& Package)
{
	//Notice
	CBCESFieldsNotice Notice;
	stBCESNotice stNotice,*pstNotice=NULL;
	CBMLRecordSet NoticeList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Notice
	Package.GetRecordSet(BCESFieldNoNoticeList,&NoticeList);
	if(NoticeList.Count()>0){
		while(NoticeList.Fetch(&Notice)){
			memcpy(&stNotice,Notice.GetAddress(),sizeof(stBCESNotice));
			pstNotice=&stNotice;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnHisNoticeQueryRsp(pstNotice,pstRspInfo,Package.GetRequestID(),NoticeList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnHisNoticeQueryRsp(pstNotice,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*签约应答*/
int CServerConnection::HandleAccountBindRsp(CAPIPackage& Package)
{
	//AccountBindRsp
	CBCESFieldsAccountBindRsp AccountBindRsp;
	stBCESAccountBindRsp stAccountBindRsp,*pstAccountBindRsp=NULL;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// AccountBindRsp
	if(Package.GetFields(&AccountBindRsp,BCESFieldNoAccountBindRsp)>=0){
		memcpy(&stAccountBindRsp,AccountBindRsp.GetAddress(),sizeof(stBCESAccountBindRsp));
		pstAccountBindRsp=&stAccountBindRsp;
	}

	if(m_pApi->m_pSpi)
		m_pApi->m_pSpi->OnAccountBindRsp(pstAccountBindRsp,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());

	return 0;
}

/*签约信息查询应答*/
int CServerConnection::HandleAccountBindQueryRsp(CAPIPackage& Package)
{
	//AccountBind
	CBCESFieldsAccountBind AccountBind;
	stBCESAccountBind stAccountBind,*pstAccountBind=NULL;
	CBMLRecordSet AccountBindList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// AccountBind
	Package.GetRecordSet(BCESFieldNoAccountBindList,&AccountBindList);
	if(AccountBindList.Count()>0){
		while(AccountBindList.Fetch(&AccountBind)){
			memcpy(&stAccountBind,AccountBind.GetAddress(),sizeof(stBCESAccountBind));
			pstAccountBind=&stAccountBind;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnAccountBindQueryRsp(pstAccountBind,pstRspInfo,Package.GetRequestID(),AccountBindList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnAccountBindQueryRsp(pstAccountBind,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*资金查询应答*/
int CServerConnection::HandleHisFundQueryRsp(CAPIPackage& Package)
{
	//Fund
	CBCESFieldsFund Fund;
	stBCESFund stFund,*pstFund=NULL;
	CBMLRecordSet FundList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// Fund
	Package.GetRecordSet(BCESFieldNoFundList,&FundList);
	if(FundList.Count()>0){
		while(FundList.Fetch(&Fund)){
			memcpy(&stFund,Fund.GetAddress(),sizeof(stBCESFund));
			pstFund=&stFund;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnHisFundQueryRsp(pstFund,pstRspInfo,Package.GetRequestID(),FundList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnHisFundQueryRsp(pstFund,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}

/*持仓明细查询应答*/
int CServerConnection::HandleHisPosiDetailQueryRsp(CAPIPackage& Package)
{
	//PosiDetail
	CBCESFieldsPosiDetail PosiDetail;
	stBCESPosiDetail stPosiDetail,*pstPosiDetail=NULL;
	CBMLRecordSet PosiDetailList;
	//RspInfo
	CBCESFieldsRspInfo RspInfo;
	stBCESRspInfo stRspInfo,*pstRspInfo=NULL;

	// RspInfo
	if(Package.GetFields(&RspInfo,BCESFieldNoRspInfo)>=0){
		memcpy(&stRspInfo,RspInfo.GetAddress(),sizeof(stBCESRspInfo));
		pstRspInfo=&stRspInfo;
	}

	// PosiDetail
	Package.GetRecordSet(BCESFieldNoPosiDetailList,&PosiDetailList);
	if(PosiDetailList.Count()>0){
		while(PosiDetailList.Fetch(&PosiDetail)){
			memcpy(&stPosiDetail,PosiDetail.GetAddress(),sizeof(stBCESPosiDetail));
			pstPosiDetail=&stPosiDetail;
			if(m_pApi->m_pSpi)
				m_pApi->m_pSpi->OnHisPosiDetailQueryRsp(pstPosiDetail,pstRspInfo,Package.GetRequestID(),PosiDetailList.HasNext()?1:Package.GetEndFlag());
		}
	}else{
		if(m_pApi->m_pSpi)
			m_pApi->m_pSpi->OnHisPosiDetailQueryRsp(pstPosiDetail,pstRspInfo,Package.GetRequestID(),Package.GetEndFlag());
	}

	return 0;
}


/* 通知 */


/*订单通知*/
int CServerConnection::HandleOrderNty(CAPIPackage& Package)
{
	//Order
	CBCESFieldsOrder Order;
	stBCESOrder stOrder;

	// Order
	Package.GetFields(&Order,BCESFieldNoOrder);
	memcpy(&stOrder,Order.GetAddress(),sizeof(stBCESOrder));

	m_pApi->m_pSpi->OnOrderNty(&stOrder);

	return 0;
}

/*市场状态通知*/
int CServerConnection::HandleMarketStatusNty(CAPIPackage& Package)
{
	//MarketStatusNty
	CBCESFieldsMarketStatusNty MarketStatusNty;
	stBCESMarketStatusNty stMarketStatusNty;

	// MarketStatusNty
	Package.GetFields(&MarketStatusNty,BCESFieldNoMarketStatusNty);
	memcpy(&stMarketStatusNty,MarketStatusNty.GetAddress(),sizeof(stBCESMarketStatusNty));

	m_pApi->m_pSpi->OnMarketStatusNty(&stMarketStatusNty);

	return 0;
}

/*成交通知*/
int CServerConnection::HandleTradeNty(CAPIPackage& Package)
{
	//Trade
	CBCESFieldsTrade Trade;
	stBCESTrade stTrade;

	// Trade
	Package.GetFields(&Trade,BCESFieldNoTrade);
	memcpy(&stTrade,Trade.GetAddress(),sizeof(stBCESTrade));

	m_pApi->m_pSpi->OnTradeNty(&stTrade);

	return 0;
}

/*持仓明细通知*/
int CServerConnection::HandlePosiDetailNty(CAPIPackage& Package)
{
	//PosiDetail
	CBCESFieldsPosiDetail PosiDetail;
	stBCESPosiDetail stPosiDetail;

	// PosiDetail
	Package.GetFields(&PosiDetail,BCESFieldNoPosiDetail);
	memcpy(&stPosiDetail,PosiDetail.GetAddress(),sizeof(stBCESPosiDetail));

	m_pApi->m_pSpi->OnPosiDetailNty(&stPosiDetail);

	return 0;
}

/*资金通知*/
int CServerConnection::HandleFundNty(CAPIPackage& Package)
{
	//Fund
	CBCESFieldsFund Fund;
	stBCESFund stFund;

	// Fund
	Package.GetFields(&Fund,BCESFieldNoFund);
	memcpy(&stFund,Fund.GetAddress(),sizeof(stBCESFund));

	m_pApi->m_pSpi->OnFundNty(&stFund);

	return 0;
}

/*持仓通知*/
int CServerConnection::HandlePosiNty(CAPIPackage& Package)
{
	//Posi
	CBCESFieldsPosi Posi;
	stBCESPosi stPosi;

	// Posi
	Package.GetFields(&Posi,BCESFieldNoPosi);
	memcpy(&stPosi,Posi.GetAddress(),sizeof(stBCESPosi));

	m_pApi->m_pSpi->OnPosiNty(&stPosi);

	return 0;
}

/*公告通知*/
int CServerConnection::HandleBulletinNty(CAPIPackage& Package)
{
	//Bulletin
	CBCESFieldsBulletin Bulletin;
	stBCESBulletin stBulletin;

	// Bulletin
	Package.GetFields(&Bulletin,BCESFieldNoBulletin);
	memcpy(&stBulletin,Bulletin.GetAddress(),sizeof(stBCESBulletin));

	m_pApi->m_pSpi->OnBulletinNty(&stBulletin);

	return 0;
}

/*信息通知*/
int CServerConnection::HandleNoticeNty(CAPIPackage& Package)
{
	//Notice
	CBCESFieldsNotice Notice;
	stBCESNotice stNotice;

	// Notice
	Package.GetFields(&Notice,BCESFieldNoNotice);
	memcpy(&stNotice,Notice.GetAddress(),sizeof(stBCESNotice));

	m_pApi->m_pSpi->OnNoticeNty(&stNotice);

	return 0;
}

/*电子出入金通知*/
int CServerConnection::HandleElectronicFundIONty(CAPIPackage& Package)
{
	//ElectronicFundIONty
	CBCESFieldsElectronicFundIONty ElectronicFundIONty;
	stBCESElectronicFundIONty stElectronicFundIONty;

	// ElectronicFundIONty
	Package.GetFields(&ElectronicFundIONty,BCESFieldNoElectronicFundIONty);
	memcpy(&stElectronicFundIONty,ElectronicFundIONty.GetAddress(),sizeof(stBCESElectronicFundIONty));

	m_pApi->m_pSpi->OnElectronicFundIONty(&stElectronicFundIONty);

	return 0;
}

/*签约通知*/
int CServerConnection::HandleAccountBindNty(CAPIPackage& Package)
{
	//AccountBind
	CBCESFieldsAccountBind AccountBind;
	stBCESAccountBind stAccountBind;

	// AccountBind
	Package.GetFields(&AccountBind,BCESFieldNoAccountBind);
	memcpy(&stAccountBind,AccountBind.GetAddress(),sizeof(stBCESAccountBind));

	m_pApi->m_pSpi->OnAccountBindNty(&stAccountBind);

	return 0;
}
