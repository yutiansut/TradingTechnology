#ifndef __BCESTRADEAPIIMP_H__
#define __BCESTRADEAPIIMP_H__

#include "os.h"
#include <string>
#include <vector>
#include <map>
#include "BCESPackage.h"
#include "ServerConnector.h"
#include "BCESQuotApi.h"
//#include "applog.h"

//extern LOGFP* lp;

#pragma warning(disable : 4996)
#pragma warning(disable : 4267)

class CServerConnector;
class CServerConnection;
class CBCESQuotApiImp:public CBCESQuotApi
{
public:
	CBCESQuotApiImp();	//创建API实现实例
	~CBCESQuotApiImp();	//析构函数

public:
	void Release();	//释放API实现实例
	void RegisterSpi(CBCESQuotSpi* pSpi);
	int SetServerAddress(const char* szServerAddress);
	int Run();
	int Stop();
	const char* GetErrorMessage(int ErrorNo);

	/*登录请求*/
	int LoginReq(stBCESLoginReq *pLoginReq,UINT nRequestID);

	/*登出请求*/
	int LogoutReq(stBCESLogoutReq *pLogoutReq,UINT nRequestID);


	/*行情订阅请求*/
	int QuotSubscribeReq(stBCESQuotSubscribeReq *pQuotSubscribeReq,UINT nRequestID);

	/*行情退订请求*/
	int QuotUnSubscribeReq(stBCESQuotUnSubscribeReq *pQuotUnSubscribeReq,UINT nRequestID);

	/*分线查询请求*/
	int MinDataQueryReq(stBCESMinDataQueryReq *pMinDataQueryReq,UINT nRequestID);

	/*日线查询请求*/
	int DayDataQueryReq(stBCESDayDataQueryReq *pDayDataQueryReq,UINT nRequestID);

	/*5分线查询请求*/
	int Min5DataQueryReq(stBCESMinDataQueryReq *pMinDataQueryReq,UINT nRequestID);

	/*15分线查询请求*/
	int Min15DataQueryReq(stBCESMinDataQueryReq *pMinDataQueryReq,UINT nRequestID);

	/*成交明细查询请求*/
	int TradeDetailDataQueryReq(stBCESTradeDetailDataQueryReq *pTradeDetailDataQueryReq,UINT nRequestID);
public:
	boost::asio::io_service m_io;
	CServerConnector* m_pConnector;
	char m_servaddr[100];
	CBCESQuotSpi* m_pSpi;
	BCESFieldTypeDate m_TradeDate;
};


#endif /* __BCESTRADEAPIIMP_H__ */
