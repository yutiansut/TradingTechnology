#ifndef __BCESQUOTAPI_H__
#define __BCESQUOTAPI_H__

#include "APIFieldDefine.h"

#ifdef QUOTAPI_EXPORTS
#define QUOTAPI_LIB __declspec(dllexport)
#else
#ifdef WIN32
#define QUOTAPI_LIB __declspec(dllimport)
#else
#define QUOTAPI_LIB 
#endif
#endif

class CBCESQuotSpi	//回调接口
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

	/*行情订阅应答*/
	virtual void OnQuotSubscribeRsp(stBCESQuotSubscribeRsp *pQuotSubscribeRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*行情退订应答*/
	virtual void OnQuotUnSubscribeRsp(stBCESQuotUnSubscribeRsp *pQuotUnSubscribeRsp,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*行情通知*/
	virtual void OnQuotNty(stBCESQuot *pQuot){};

	/*分线查询应答*/
	virtual void OnMinDataQueryRsp(stBCESMinData *pMinData,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*日线查询应答*/
	virtual void OnDayDataQueryRsp(stBCESDayData *pDayData,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*5分线查询应答*/
	virtual void OnMin5DataQueryRsp(stBCESMinData *pMinData,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*15分线查询应答*/
	virtual void OnMin15DataQueryRsp(stBCESMinData *pMinData,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};

	/*成交明细查询应答*/
	virtual void OnTradeDetailDataQueryRsp(stBCESTradeDetailData *pTradeDetailData,stBCESRspInfo *pRspInfo,UINT nRequestID,UINT EndFlag){};
};

class QUOTAPI_LIB CBCESQuotApi
{
public:
	static CBCESQuotApi *CreateBCESQuotApi();	//创建API实现实例
	virtual void Release()=0;	//释放API实现实例
	virtual void RegisterSpi(CBCESQuotSpi* pSpi)=0;	//注册回调接口
	virtual int Run()=0;// 启动实例
	virtual int Stop()=0;// 停止实例
	virtual int SetServerAddress(const char* szServerAddress)=0;	// 注册前置地址，格式：127.0.0.1:20004，可以多次调用以注册多个前置地址
	virtual const char* GetErrorMessage(int ErrorNo)=0;	// 获取错误编号对应的描述信息

public:
	/*登录请求*/
	virtual int LoginReq(stBCESLoginReq *pLoginReq,UINT nRequestID)=0;

	/*登出请求*/
	virtual int LogoutReq(stBCESLogoutReq *pLogoutReq,UINT nRequestID)=0;

	/*行情订阅请求*/
	virtual int QuotSubscribeReq(stBCESQuotSubscribeReq *pQuotSubscribeReq,UINT nRequestID)=0;

	/*行情退订请求*/
	virtual int QuotUnSubscribeReq(stBCESQuotUnSubscribeReq *pQuotUnSubscribeReq,UINT nRequestID)=0;

	/*分线查询请求*/
	virtual int MinDataQueryReq(stBCESMinDataQueryReq *pMinDataQueryReq,UINT nRequestID)=0;

	/*日线查询请求*/
	virtual int DayDataQueryReq(stBCESDayDataQueryReq *pDayDataQueryReq,UINT nRequestID)=0;

	/*5分线查询请求*/
	virtual int Min5DataQueryReq(stBCESMinDataQueryReq *pMinDataQueryReq,UINT nRequestID)=0;

	/*15分线查询请求*/
	virtual int Min15DataQueryReq(stBCESMinDataQueryReq *pMinDataQueryReq,UINT nRequestID)=0;

	/*成交明细查询请求*/
	virtual int TradeDetailDataQueryReq(stBCESTradeDetailDataQueryReq *pTradeDetailDataQueryReq,UINT nRequestID)=0;

protected:
	virtual ~CBCESQuotApi();	//析构函数
};

#endif /* __BCESQUOTAPI_H__ */
