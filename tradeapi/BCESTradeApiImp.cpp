#include "BCESTradeApiImp.h"
#include <string>
#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <stdarg.h>
#include <boost/asio.hpp>
#include "ServerConnector.h"
#include <fcntl.h>
#include <boost/thread/thread.hpp>

//LOGFP* lp=NULL;

#define TCP_SND_SIZ		1024*1024*10		// Tcp Send Buffer Size 10MB
#define TCP_RCV_SIZ		1024*1024*1			// Tcp Recv Buffer Size 1MB
#define APP_TIMEOUT		120					// Seconds

unsigned int nTcpSndSiz=TCP_SND_SIZ;
unsigned int nTcpRcvSiz=TCP_RCV_SIZ;

using namespace std;

// 错误定义
typedef struct {
	int ErrorNo;
	char ErrorMessage[256];
} stAPIErrorInfo;

stAPIErrorInfo APIErrorInfoArray[]={
#define BCESAPIErrorMessageSucceeded			0
	{BCESAPIErrorMessageSucceeded,"操作成功！"},
#define BCESAPIErrorMessageFailed			-1
	{BCESAPIErrorMessageFailed,"操作失败！"}
};
const char APIErrorMessageUnKnownErrorCode[]="未知错误编码";

CBCESTradeApiImp::CBCESTradeApiImp()
{
	m_pConnector=NULL;
}

CBCESTradeApiImp::~CBCESTradeApiImp()
{
	if(m_pConnector)
		Stop();
}

void CBCESTradeApiImp::RegisterSpi(CBCESTradeSpi* pSpi)
{
	m_pSpi=pSpi;
}

void CBCESTradeApiImp::Release()
{
	delete this;
}

int CBCESTradeApiImp::SetServerAddress(const char* szServerAddress)
{
	strcpy(m_servaddr,szServerAddress);
	return 0;
}

int CBCESTradeApiImp::Run()
{
	m_pConnector=new CServerConnector(m_io,m_servaddr,nTcpSndSiz,nTcpRcvSiz,APP_TIMEOUT,this);
	m_pConnector->AsyncConnect();
	boost::thread t(boost::bind(&boost::asio::io_service::run, &m_io));

	return 0;
}
int CBCESTradeApiImp::Stop()
{
	if(!m_pConnector)
		return 0;
	m_io.stop();
	delete m_pConnector;
	m_pConnector=NULL;

	return 0;
}

const char* CBCESTradeApiImp::GetErrorMessage(int ErrorNo)
{
	const char* p=NULL;
	int i,count;

	count=sizeof(APIErrorInfoArray)/sizeof(stAPIErrorInfo);
	for(i=0;i<count;i++){
		if(ErrorNo==APIErrorInfoArray[i].ErrorNo){
			p=APIErrorInfoArray[i].ErrorMessage;
			break;
		}
	}

	if(!p)
		return APIErrorMessageUnKnownErrorCode;

	return p;
}

/*登录请求*/
int CBCESTradeApiImp::LoginReq(stBCESLoginReq *pLoginReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::LoginReq,m_pConnector->m_pConnection,*pLoginReq,nRequestID));

	return 0;
}


/*登出请求*/
int CBCESTradeApiImp::LogoutReq(stBCESLogoutReq *pLogoutReq,UINT nRequestID)
{
	m_io.post(boost::bind(&CServerConnection::LogoutReq,m_pConnector->m_pConnection,*pLogoutReq,nRequestID));

	return 0;
}

int CBCESTradeApiImp::FlowSubscribeReq(UINT nPrivateResumeMethod,UINT nPublicResumeMethod)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::FlowSubscribeReq,m_pConnector->m_pConnection,nPrivateResumeMethod,nPublicResumeMethod));

	return 0;
}


/*修改密码请求*/
int CBCESTradeApiImp::ChangePasswordReq(stBCESChangePasswordReq *pChangePasswordReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::ChangePasswordReq,m_pConnector->m_pConnection,*pChangePasswordReq,nRequestID));

	return 0;
}

/*订单录入请求*/
int CBCESTradeApiImp::OrderInsertReq(stBCESInputOrder *pInputOrder,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::OrderInsertReq,m_pConnector->m_pConnection,*pInputOrder,nRequestID));

	return 0;
}

/*撤单请求*/
int CBCESTradeApiImp::OrderCancelReq(stBCESOrderCancelReq *pOrderCancelReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::OrderCancelReq,m_pConnector->m_pConnection,*pOrderCancelReq,nRequestID));

	return 0;
}

/*行情查询请求*/
int CBCESTradeApiImp::QuotQueryReq(stBCESQuotQueryReq *pQuotQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::QuotQueryReq,m_pConnector->m_pConnection,*pQuotQueryReq,nRequestID));

	return 0;
}

/*订单查询请求*/
int CBCESTradeApiImp::OrderQueryReq(stBCESOrderQueryReq *pOrderQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::OrderQueryReq,m_pConnector->m_pConnection,*pOrderQueryReq,nRequestID));

	return 0;
}

/*成交查询请求*/
int CBCESTradeApiImp::TradeQueryReq(stBCESTradeQueryReq *pTradeQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::TradeQueryReq,m_pConnector->m_pConnection,*pTradeQueryReq,nRequestID));

	return 0;
}

/*持仓查询请求*/
int CBCESTradeApiImp::PosiQueryReq(stBCESPosiQueryReq *pPosiQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::PosiQueryReq,m_pConnector->m_pConnection,*pPosiQueryReq,nRequestID));

	return 0;
}

/*资金查询请求*/
int CBCESTradeApiImp::FundQueryReq(stBCESFundQueryReq *pFundQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::FundQueryReq,m_pConnector->m_pConnection,*pFundQueryReq,nRequestID));

	return 0;
}

/*合约查询请求*/
int CBCESTradeApiImp::InstrumentQueryReq(stBCESInstrumentQueryReq *pInstrumentQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::InstrumentQueryReq,m_pConnector->m_pConnection,*pInstrumentQueryReq,nRequestID));

	return 0;
}

/*持仓明细查询请求*/
int CBCESTradeApiImp::PosiDetailQueryReq(stBCESPosiDetailQueryReq *pPosiDetailQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::PosiDetailQueryReq,m_pConnector->m_pConnection,*pPosiDetailQueryReq,nRequestID));

	return 0;
}

/*止赢止损设置请求*/
int CBCESTradeApiImp::ProfitLossStopSetReq(stBCESProfitLossStopSetReq *pProfitLossStopSetReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::ProfitLossStopSetReq,m_pConnector->m_pConnection,*pProfitLossStopSetReq,nRequestID));

	return 0;
}

/*订单修改请求*/
int CBCESTradeApiImp::OrderModifyReq(stBCESInputOrder *pInputOrder,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::OrderModifyReq,m_pConnector->m_pConnection,*pInputOrder,nRequestID));

	return 0;
}

/*公告查询请求*/
int CBCESTradeApiImp::BulletinQueryReq(stBCESBulletinQueryReq *pBulletinQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::BulletinQueryReq,m_pConnector->m_pConnection,*pBulletinQueryReq,nRequestID));

	return 0;
}

/*通知查询请求*/
int CBCESTradeApiImp::NoticeQueryReq(stBCESNoticeQueryReq *pNoticeQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::NoticeQueryReq,m_pConnector->m_pConnection,*pNoticeQueryReq,nRequestID));

	return 0;
}

/*电子出入金请求*/
int CBCESTradeApiImp::ElectronicFundIOReq(stBCESElectronicFundIOReq *pElectronicFundIOReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::ElectronicFundIOReq,m_pConnector->m_pConnection,*pElectronicFundIOReq,nRequestID));

	return 0;
}

/*出入金明细查询请求*/
int CBCESTradeApiImp::FundIODetailQueryReq(stBCESFundIODetailQueryReq *pFundIODetailQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::FundIODetailQueryReq,m_pConnector->m_pConnection,*pFundIODetailQueryReq,nRequestID));

	return 0;
}

/*报表查询请求*/
int CBCESTradeApiImp::ReportQueryReq(stBCESReportQueryReq *pReportQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::ReportQueryReq,m_pConnector->m_pConnection,*pReportQueryReq,nRequestID));

	return 0;
}

/*历史订单查询请求*/
int CBCESTradeApiImp::HisOrderQueryReq(stBCESHisOrderQueryReq *pHisOrderQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::HisOrderQueryReq,m_pConnector->m_pConnection,*pHisOrderQueryReq,nRequestID));

	return 0;
}

/*历史成交查询请求*/
int CBCESTradeApiImp::HisTradeQueryReq(stBCESHisTradeQueryReq *pHisTradeQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::HisTradeQueryReq,m_pConnector->m_pConnection,*pHisTradeQueryReq,nRequestID));

	return 0;
}

/*历史公告查询请求*/
int CBCESTradeApiImp::HisBulletinQueryReq(stBCESHisBulletinQueryReq *pHisBulletinQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::HisBulletinQueryReq,m_pConnector->m_pConnection,*pHisBulletinQueryReq,nRequestID));

	return 0;
}

/*历史通知查询请求*/
int CBCESTradeApiImp::HisNoticeQueryReq(stBCESHisNoticeQueryReq *pHisNoticeQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::HisNoticeQueryReq,m_pConnector->m_pConnection,*pHisNoticeQueryReq,nRequestID));

	return 0;
}

/*签约请求*/
int CBCESTradeApiImp::AccountBindReq(stBCESAccountBindReq *pAccountBindReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::AccountBindReq,m_pConnector->m_pConnection,*pAccountBindReq,nRequestID));

	return 0;
}

/*签约信息查询请求*/
int CBCESTradeApiImp::AccountBindQueryReq(stBCESAccountBindQueryReq *pAccountBindQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::AccountBindQueryReq,m_pConnector->m_pConnection,*pAccountBindQueryReq,nRequestID));

	return 0;
}

/*资金查询请求*/
int CBCESTradeApiImp::HisFundQueryReq(stBCESHisFundQueryReq *pHisFundQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::HisFundQueryReq,m_pConnector->m_pConnection,*pHisFundQueryReq,nRequestID));

	return 0;
}

/*持仓明细查询请求*/
int CBCESTradeApiImp::HisPosiDetailQueryReq(stBCESHisPosiDetailQueryReq *pHisPosiDetailQueryReq,UINT nRequestID)
{
	if(!m_pConnector || !m_pConnector->m_pConnection)
		return -1;

	m_io.post(boost::bind(&CServerConnection::HisPosiDetailQueryReq,m_pConnector->m_pConnection,*pHisPosiDetailQueryReq,nRequestID));

	return 0;
}
