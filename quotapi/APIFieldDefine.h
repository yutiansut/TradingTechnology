#ifndef __API_FIELD_DEFINE_H__
#define __API_FIELD_DEFINE_H__

#include "BCESFieldTypeDefine.h"

/* API报文头 */
struct stBCESApiHead
{
	BCESFieldTypeServiceNo ServiceNo;	/* 指令编号 */
	BCESFieldTypeRequestID RequestID;	/* 请求编号 */
	BCESFieldTypeEndFlag EndFlag;	/* 结束标记 */
};

/* 应答信息域 */
struct stBCESRspInfo
{
	BCESFieldTypeRspNo RspNo;	/* 应答编码 */
	BCESFieldTypeRspDesc RspDesc;	/* 应答描述 */
};

/* 流订阅请求 */
struct stBCESFlowSubscribeReq
{
	BCESFieldTypeFlowID FlowID;	/* 流编号 */
	BCESFieldTypePkgNo PkgNo;	/* 报文序号 */
};

/* 流订阅应答 */
struct stBCESFlowSubscribeRsp
{
	BCESFieldTypeFlowID FlowID;	/* 流编号 */
	BCESFieldTypePkgNo PkgNo;	/* 报文序号 */
};

/* 报文头 */
struct stBCESHead
{
	BCESFieldTypeRequestID RequestID;	/* 请求编号 */
	BCESFieldTypeEndFlag EndFlag;	/* 结束标记 */
};

/* 行情订阅请求 */
struct stBCESQuotSubscribeReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 行情订阅应答 */
struct stBCESQuotSubscribeRsp
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 行情退订请求 */
struct stBCESQuotUnSubscribeReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 行情退订应答 */
struct stBCESQuotUnSubscribeRsp
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 数据操作概要 */
struct stBCESDBOperateSummary
{
	BCESFieldTypeTableName TableName;	/* 表名 */
	BCESFieldTypeTableOperation TableOperation;	/* 表操作 */
};

/* 登录请求 */
struct stBCESLoginReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypePassword InvestorPassword;	/* 投资者密码 */
	BCESFieldTypeIP IP;	/* IP地址 */
	BCESFieldTypeFlag ProductType;	/* 产品编号 */
	BCESFieldTypeVersionNo ProductVersion;	/* 产品版本号 */
};

/* 登录应答 */
struct stBCESLoginRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeName SysName;	/* 系统名称 */
	BCESFieldTypeFlag SysMode;	/* 系统模式 */
	BCESFieldTypeFlag PayServerType;	/* 支付服务类型 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeFlag InvestorAdviserFlag;	/* 投资者顾问标志 */
	BCESFieldTypeSessionID SessionID;	/* 会话编号 */
};

/* 登出请求 */
struct stBCESLogoutReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 登出应答 */
struct stBCESLogoutRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 修改密码请求 */
struct stBCESChangePasswordReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypePassword InvestorOldPassword;	/* 投资者旧密码 */
	BCESFieldTypePassword InvestorNewPassword;	/* 投资者新密码 */
};

/* 修改密码应答 */
struct stBCESChangePasswordRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 报单账户 */
struct stBCESAccount
{
	BCESFieldTypeAccountID AccountID;	/* 报单账号 */
};

/* 交易所 */
struct stBCESExchange
{
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 订单录入 */
struct stBCESInputOrder
{
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeFlag OCFlag;	/* 开平标志 */
	BCESFieldTypeFlag PriceType;	/* 价格类型 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
	BCESFieldTypePoints FilledPoints;	/* 成交滑点 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypeFlag ConditionType;	/* 条件类型 */
	BCESFieldTypeFlag ConditionMethod;	/* 条件方法 */
	BCESFieldTypePrice ConditionPrice;	/* 条件价格 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeSessionID SessionID;	/* 会话编号 */
	BCESFieldTypeOrderRef OrderRef;	/* 报单引用 */
	BCESFieldTypeDate ClosedTradeDate;	/* 平仓交易日期 */
	BCESFieldTypeOrderID ClosedOrderID;	/* 平仓订单号 */
	BCESFieldTypeMatchID ClosedMatchID;	/* 平仓成交号 */
	BCESFieldTypeAccountID AccountID;	/* 交易账号 */
};

/* 订单 */
struct stBCESOrder
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
	BCESFieldTypeDate OrderDate;	/* 报单日期 */
	BCESFieldTypeTime OrderTime;	/* 报单时间 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeFlag OCFlag;	/* 开平标志 */
	BCESFieldTypeFlag PriceType;	/* 价格类型 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypeQty QtyLeft;	/* 剩余数量 */
	BCESFieldTypePrice AvgPrice;	/* 成交均价 */
	BCESFieldTypeDate ModifyDate;	/* 修改日期 */
	BCESFieldTypeTime ModifyTime;	/* 修改时间 */
	BCESFieldTypeFlag OrderStatus;	/* 订单状态 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
	BCESFieldTypePoints FilledPoints;	/* 成交滑点 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypeAmount Margin;	/* 占用保证金 */
	BCESFieldTypeAmount FrozenMargin;	/* 冻结保证金 */
	BCESFieldTypeFlag ConditionType;	/* 条件类型 */
	BCESFieldTypeFlag ConditionMethod;	/* 条件方法 */
	BCESFieldTypePrice ConditionPrice;	/* 条件价格 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeSessionID SessionID;	/* 会话编号 */
	BCESFieldTypeOrderRef OrderRef;	/* 报单引用 */
	BCESFieldTypeDate ClosedTradeDate;	/* 平仓交易日期 */
	BCESFieldTypeOrderID ClosedOrderID;	/* 平仓订单号 */
	BCESFieldTypeMatchID ClosedMatchID;	/* 平仓成交号 */
	BCESFieldTypeOrderStatusDesc OrderStatusDesc;	/* 订单状态描述 */
	BCESFieldTypeAccountID AccountID;	/* 交易账号 */
	BCESFieldTypeCTPFrontID CTPFrontID;	/* CTP前置编号 */
	BCESFieldTypeCTPSessionID CTPSessionID;	/* CTP会话编号 */
	BCESFieldTypeCTPOrderRef CTPOrderRef;	/* CTP报单引用 */
	BCESFieldTypeOrderSysID OrderSysID;	/* 交易所报单编号 */
};

/* 撤单请求 */
struct stBCESOrderCancelReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeSessionID SessionID;	/* 会话编号 */
	BCESFieldTypeOrderRef OrderRef;	/* 报单引用 */
	BCESFieldTypeAccountID AccountID;	/* 交易账号 */
	BCESFieldTypeOrderSysID OrderSysID;	/* 交易所报单编号 */
};

/* 撤单应答 */
struct stBCESOrderCancelRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeSessionID SessionID;	/* 会话编号 */
	BCESFieldTypeOrderRef OrderRef;	/* 报单引用 */
	BCESFieldTypeAccountID AccountID;	/* 交易账号 */
	BCESFieldTypeOrderSysID OrderSysID;	/* 交易所报单编号 */
};

/* 成交单 */
struct stBCESTrade
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeMatchID MatchID;	/* 成交号 */
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeFlag OCFlag;	/* 开平标志 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypeDate MatchDate;	/* 成交日期 */
	BCESFieldTypeTime MatchTime;	/* 成交时间 */
	BCESFieldTypeRate FeeRate;	/* 手续费 */
	BCESFieldTypeAmount Margin;	/* 占用保证金 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeDate ClosedTradeDate;	/* 平仓交易日期 */
	BCESFieldTypeOrderID ClosedOrderID;	/* 平仓订单号 */
	BCESFieldTypeMatchID ClosedMatchID;	/* 平仓成交号 */
	BCESFieldTypeAccountID AccountID;	/* 交易账号 */
	BCESFieldTypeOrderSysID OrderSysID;	/* 交易所报单编号 */
};

/* 行情 */
struct stBCESQuot
{
	BCESFieldTypeMatchID MatchID;	/* 成交号 */
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约 */
	BCESFieldTypePrice Price;	/* 现价 */
	BCESFieldTypeQty Qty;	/* 现手 */
	BCESFieldTypePrice BidPrice;	/* 叫买价 */
	BCESFieldTypeQty BidQty;	/* 叫买量 */
	BCESFieldTypePrice AskPrice;	/* 叫卖价 */
	BCESFieldTypeQty AskQty;	/* 叫卖量 */
	BCESFieldTypePrice OpenPrice;	/* 开盘价 */
	BCESFieldTypePrice HighestPrice;	/* 最高价 */
	BCESFieldTypePrice LowestPrice;	/* 最低价 */
	BCESFieldTypePrice HighLimit;	/* 涨停板价 */
	BCESFieldTypePrice LowLimit;	/* 跌停板价 */
	BCESFieldTypeQtyTotal OI;	/* 持仓量 */
	BCESFieldTypePrice SettlePrice;	/* 结算价 */
	BCESFieldTypePrice PreClose;	/* 昨收盘价 */
	BCESFieldTypePrice PreSettle;	/* 昨结算价 */
	BCESFieldTypeQtyTotal PreOI;	/* 昨持仓量 */
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
	BCESFieldTypeAmount Amount;	/* 成交额 */
	BCESFieldTypeDate ModifyDate;	/* 更新日期 */
	BCESFieldTypeTime ModifyTime;	/* 更新时间 */
	BCESFieldTypePrice BidPrice2;	/* 叫买价2 */
	BCESFieldTypeQty BidQty2;	/* 叫买量2 */
	BCESFieldTypePrice AskPrice2;	/* 叫卖价2 */
	BCESFieldTypeQty AskQty2;	/* 叫卖量2 */
	BCESFieldTypePrice BidPrice3;	/* 叫买价3 */
	BCESFieldTypeQty BidQty3;	/* 叫买量3 */
	BCESFieldTypePrice AskPrice3;	/* 叫卖价3 */
	BCESFieldTypeQty AskQty3;	/* 叫卖量3 */
	BCESFieldTypePrice BidPrice4;	/* 叫买价4 */
	BCESFieldTypeQty BidQty4;	/* 叫买量4 */
	BCESFieldTypePrice AskPrice4;	/* 叫卖价4 */
	BCESFieldTypeQty AskQty4;	/* 叫卖量4 */
	BCESFieldTypePrice BidPrice5;	/* 叫买价5 */
	BCESFieldTypeQty BidQty5;	/* 叫买量5 */
	BCESFieldTypePrice AskPrice5;	/* 叫卖价5 */
	BCESFieldTypeQty AskQty5;	/* 叫卖量5 */
	BCESFieldTypePrice BidPrice6;	/* 叫买价6 */
	BCESFieldTypeQty BidQty6;	/* 叫买量6 */
	BCESFieldTypePrice AskPrice6;	/* 叫卖价6 */
	BCESFieldTypeQty AskQty6;	/* 叫卖量6 */
	BCESFieldTypePrice BidPrice7;	/* 叫买价7 */
	BCESFieldTypeQty BidQty7;	/* 叫买量7 */
	BCESFieldTypePrice AskPrice7;	/* 叫卖价7 */
	BCESFieldTypeQty AskQty7;	/* 叫卖量7 */
	BCESFieldTypePrice BidPrice8;	/* 叫买价8 */
	BCESFieldTypeQty BidQty8;	/* 叫买量8 */
	BCESFieldTypePrice AskPrice8;	/* 叫卖价8 */
	BCESFieldTypeQty AskQty8;	/* 叫卖量8 */
	BCESFieldTypePrice BidPrice9;	/* 叫买价9 */
	BCESFieldTypeQty BidQty9;	/* 叫买量9 */
	BCESFieldTypePrice AskPrice9;	/* 叫卖价9 */
	BCESFieldTypeQty AskQty9;	/* 叫卖量9 */
	BCESFieldTypePrice BidPrice10;	/* 叫买价10 */
	BCESFieldTypeQty BidQty10;	/* 叫买量10 */
	BCESFieldTypePrice AskPrice10;	/* 叫卖价10 */
	BCESFieldTypeQty AskQty10;	/* 叫卖量10 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 行情 */
struct stBCESInternationalQuot
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约 */
	BCESFieldTypePrice Price;	/* 现价 */
	BCESFieldTypeQty Qty;	/* 现手 */
	BCESFieldTypePrice BidPrice;	/* 叫买价 */
	BCESFieldTypeQty BidQty;	/* 叫买量 */
	BCESFieldTypePrice AskPrice;	/* 叫卖价 */
	BCESFieldTypeQty AskQty;	/* 叫卖量 */
	BCESFieldTypePrice OpenPrice;	/* 开盘价 */
	BCESFieldTypePrice HighestPrice;	/* 最高价 */
	BCESFieldTypePrice LowestPrice;	/* 最低价 */
	BCESFieldTypePrice HighLimit;	/* 涨停板价 */
	BCESFieldTypePrice LowLimit;	/* 跌停板价 */
	BCESFieldTypeQtyTotal OI;	/* 持仓量 */
	BCESFieldTypePrice SettlePrice;	/* 结算价 */
	BCESFieldTypePrice PreClose;	/* 昨收盘价 */
	BCESFieldTypePrice PreSettle;	/* 昨结算价 */
	BCESFieldTypeQtyTotal PreOI;	/* 昨持仓量 */
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
	BCESFieldTypeAmount Amount;	/* 成交额 */
	BCESFieldTypeDate ModifyDate;	/* 更新日期 */
	BCESFieldTypeTime ModifyTime;	/* 更新时间 */
	BCESFieldTypePrice BidPrice2;	/* 叫买价2 */
	BCESFieldTypeQty BidQty2;	/* 叫买量2 */
	BCESFieldTypePrice AskPrice2;	/* 叫卖价2 */
	BCESFieldTypeQty AskQty2;	/* 叫卖量2 */
	BCESFieldTypePrice BidPrice3;	/* 叫买价3 */
	BCESFieldTypeQty BidQty3;	/* 叫买量3 */
	BCESFieldTypePrice AskPrice3;	/* 叫卖价3 */
	BCESFieldTypeQty AskQty3;	/* 叫卖量3 */
	BCESFieldTypePrice BidPrice4;	/* 叫买价4 */
	BCESFieldTypeQty BidQty4;	/* 叫买量4 */
	BCESFieldTypePrice AskPrice4;	/* 叫卖价4 */
	BCESFieldTypeQty AskQty4;	/* 叫卖量4 */
	BCESFieldTypePrice BidPrice5;	/* 叫买价5 */
	BCESFieldTypeQty BidQty5;	/* 叫买量5 */
	BCESFieldTypePrice AskPrice5;	/* 叫卖价5 */
	BCESFieldTypeQty AskQty5;	/* 叫卖量5 */
	BCESFieldTypePrice BidPrice6;	/* 叫买价6 */
	BCESFieldTypeQty BidQty6;	/* 叫买量6 */
	BCESFieldTypePrice AskPrice6;	/* 叫卖价6 */
	BCESFieldTypeQty AskQty6;	/* 叫卖量6 */
	BCESFieldTypePrice BidPrice7;	/* 叫买价7 */
	BCESFieldTypeQty BidQty7;	/* 叫买量7 */
	BCESFieldTypePrice AskPrice7;	/* 叫卖价7 */
	BCESFieldTypeQty AskQty7;	/* 叫卖量7 */
	BCESFieldTypePrice BidPrice8;	/* 叫买价8 */
	BCESFieldTypeQty BidQty8;	/* 叫买量8 */
	BCESFieldTypePrice AskPrice8;	/* 叫卖价8 */
	BCESFieldTypeQty AskQty8;	/* 叫卖量8 */
	BCESFieldTypePrice BidPrice9;	/* 叫买价9 */
	BCESFieldTypeQty BidQty9;	/* 叫买量9 */
	BCESFieldTypePrice AskPrice9;	/* 叫卖价9 */
	BCESFieldTypeQty AskQty9;	/* 叫卖量9 */
	BCESFieldTypePrice BidPrice10;	/* 叫买价10 */
	BCESFieldTypeQty BidQty10;	/* 叫买量10 */
	BCESFieldTypePrice AskPrice10;	/* 叫卖价10 */
	BCESFieldTypeQty AskQty10;	/* 叫卖量10 */
	BCESFieldTypeGoodsName GoodsName;	/* 品种大类 */
};

/* 行情查询请求 */
struct stBCESQuotQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 订单查询请求 */
struct stBCESOrderQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 成交查询请求 */
struct stBCESTradeQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 持仓查询 */
struct stBCESPosiQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 持仓明细查询 */
struct stBCESPosiDetailQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 历史持仓明细查询 */
struct stBCESHisPosiDetailQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 持仓 */
struct stBCESPosi
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeQty BuyQty;	/* 买持仓量 */
	BCESFieldTypePrice BuyPrice;	/* 买持仓均价 */
	BCESFieldTypeQty SellQty;	/* 卖持仓量 */
	BCESFieldTypePrice SellPrice;	/* 卖持仓均价 */
	BCESFieldTypeQty BuyQtyFrozen;	/* 买冻结持仓量 */
	BCESFieldTypeQty SellQtyFrozen;	/* 卖冻结持仓量 */
	BCESFieldTypeQty PreBuyQty;	/* 昨买持仓量 */
	BCESFieldTypeQty PreSellQty;	/* 昨卖持仓量 */
	BCESFieldTypeQty TodayBuyQty;	/* 今买持仓量 */
	BCESFieldTypeQty TodaySellQty;	/* 今卖持仓量 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeQty TodayBuyQtyFrozen;	/* 今买冻结持仓量 */
	BCESFieldTypeQty TodaySellQtyFrozen;	/* 今卖冻结持仓量 */
	BCESFieldTypeAmount ClosedPL;	/* 平仓盈亏 */
	BCESFieldTypeAmount FloatingPL;	/* 浮动盈亏 */
	BCESFieldTypeAmount Margin;	/* 占用保证金 */
	BCESFieldTypeAmount Fee;	/* 手续费 */
	BCESFieldTypeAmount FrozenMargin;	/* 冻结保证金 */
	BCESFieldTypeAmount FeeFrozen;	/* 冻结手续费 */
};

/* 持仓明细 */
struct stBCESPosiDetail
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypeMatchID MatchID;	/* 成交号 */
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypeQty QtyLeft;	/* 剩余数量 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeName AgentName;	/* 代理商名称 */
	BCESFieldTypeAmount FloatingPL;	/* 浮动盈亏 */
	BCESFieldTypeAmount ClosedPL;	/* 平仓盈亏 */
	BCESFieldTypeAmount Fee;	/* 手续费 */
	BCESFieldTypeAmount Margin;	/* 保证金 */
	BCESFieldTypeDate CreateDate;	/* 建仓日期 */
	BCESFieldTypeTime CreateTime;	/* 建仓时间 */
	BCESFieldTypeDate CloseDate;	/* 平仓日期 */
	BCESFieldTypeTime CloseTime;	/* 平仓时间 */
	BCESFieldTypePrice ClosePrice;	/* 平仓价格 */
	BCESFieldTypePrice OverNightFee;	/* 隔夜费 */
	BCESFieldTypeQty QtyFrozen;	/* 冻结持仓量 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypePrice CreatePrice;	/* 建仓价 */
	BCESFieldTypeAmount HistoryClosedPL;	/* 历史平仓盈亏 */
	BCESFieldTypeDate CreateTradeDate;	/* 建仓交易日期 */
	BCESFieldTypeQty PreQtyLeft;	/* 上日剩余数量 */
};

/* 资金查询请求 */
struct stBCESFundQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 历史资金查询请求 */
struct stBCESHisFundQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 资金 */
struct stBCESFund
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAmount LastBalance;	/* 上日权益 */
	BCESFieldTypeAmount FloatBalance;	/* 浮动权益 */
	BCESFieldTypeAmount FreeBalance;	/* 可用资金 */
	BCESFieldTypeAmount Margin;	/* 占用保证金 */
	BCESFieldTypeAmount FrozenMargin;	/* 冻结保证金 */
	BCESFieldTypeAmount Fee;	/* 手续费 */
	BCESFieldTypeAmount FeeFrozen;	/* 冻结手续费 */
	BCESFieldTypeAmount ClosedPL;	/* 平仓盈亏 */
	BCESFieldTypeAmount FloatingPL;	/* 浮动盈亏 */
	BCESFieldTypeAmount ProfitLoss;	/* 盈亏 */
	BCESFieldTypeAmount TotalPL;	/* 累计盈亏 */
	BCESFieldTypeAmount FrozenBalance;	/* 冻结资金 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeName AgentName;	/* 代理商名称 */
	BCESFieldTypeAmount InAmount;	/* 入金金额 */
	BCESFieldTypeAmount OutAmount;	/* 出金金额 */
	BCESFieldTypePrice OverNightFee;	/* 隔夜费 */
};

/* 市场状态通知 */
struct stBCESMarketStatusNty
{
	BCESFieldTypeFlag MarketStatus;	/* 市场状态 */
	BCESFieldTypeMarketStatusDesc MarketStatusDesc;	/* 市场状态描述 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 合约查询请求 */
struct stBCESInstrumentQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 合约 */
struct stBCESInstrument
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeInstrumentName InstrumentName;	/* 合约名称 */
	BCESFieldTypeFlag FeeType;	/* 手续费类型 */
	BCESFieldTypeRate FeeRate;	/* 手续费率 */
	BCESFieldTypePrice MarginRate;	/* 保证金 */
	BCESFieldTypeRate DailyPriceLimit;	/* 每日涨跌限制 */
	BCESFieldTypeFlag PriceUnit;	/* 报价单位 */
	BCESFieldTypeQty TradeUnit;	/* 交易单位 */
	BCESFieldTypePrice MinMovement;	/* 最小变动价位 */
	BCESFieldTypePrice PriceScale;	/* 报价精度 */
	BCESFieldTypeRate PriceCoefficient;	/* 价格系数 */
	BCESFieldTypeFlag InstrumentStatus;	/* 合约状态 */
	BCESFieldTypePoints LimitedFilledPoints;	/* 最小成交滑点 */
	BCESFieldTypePoints LimitedOrderPoints;	/* 最小报价点差 */
	BCESFieldTypePoints LimitedStopPoints;	/* 最小止赢止损点差 */
	BCESFieldTypeAddress Address;	/* 产地 */
	BCESFieldTypeAddress WareHouse;	/* 仓库 */
	BCESFieldTypeFlag Currency;	/* 币种 */
	BCESFieldTypeFlag MarginRateType;	/* 保证金率类型 */
	BCESFieldTypePrice OverNightFee;	/* 隔夜费 */
	BCESFieldTypeFlag OverNightFeeType;	/* 隔夜费类型 */
	BCESFieldTypeRate PriceMultiply;	/* 报价乘数 */
	BCESFieldTypeFlag FeeFlag;	/* 收费类型 */
	BCESFieldTypeQty EachQtyLimt;	/* 每笔持仓限量 */
	BCESFieldTypeQty TotalQtyLimt;	/* 总持仓限量 */
	BCESFieldTypeGoodsName GoodsName;	/* 品种大类 */
	BCESFieldTypePlateName PlateName;	/* 板块 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeFlag InstrumentType;	/* 商品类型 */
};

/* 分线查询请求 */
struct stBCESMinDataQueryReq
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 分线 */
struct stBCESMinData
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTime;	/* 日期时间 */
	BCESFieldTypePrice OpenPrice;	/* 开盘价 */
	BCESFieldTypePrice HighestPrice;	/* 最高价 */
	BCESFieldTypePrice LowestPrice;	/* 最低价 */
	BCESFieldTypePrice ClosePrice;	/* 收盘价 */
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
	BCESFieldTypeQtyTotal OI;	/* 空盘量 */
	BCESFieldTypeAmount Amount;	/* 成交额 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 日线查询请求 */
struct stBCESDayDataQueryReq
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 日线 */
struct stBCESDayData
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate Date;	/* 日期 */
	BCESFieldTypePrice OpenPrice;	/* 开盘价 */
	BCESFieldTypePrice HighestPrice;	/* 最高价 */
	BCESFieldTypePrice LowestPrice;	/* 最低价 */
	BCESFieldTypePrice ClosePrice;	/* 收盘价 */
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
	BCESFieldTypeQtyTotal OI;	/* 空盘量 */
	BCESFieldTypeAmount Amount;	/* 成交额 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 成交明细查询请求 */
struct stBCESTradeDetailDataQueryReq
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 成交明细 */
struct stBCESTradeDetailData
{
	BCESFieldTypeMatchID MatchID;	/* 成交号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate Date;	/* 日期 */
	BCESFieldTypeTime Time;	/* 时间 */
	BCESFieldTypeQty Qty;	/* 成交量 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 止赢止损设置请求 */
struct stBCESProfitLossStopSetReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
};

/* 止赢止损设置应答 */
struct stBCESProfitLossStopSetRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
};

/* 公告 */
struct stBCESBulletin
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeBulletinID BulletinID;	/* 公告编号 */
	BCESFieldTypeTitle Title;	/* 公告标题 */
	BCESFieldTypeContent Content;	/* 公告内容 */
	BCESFieldTypeDate PublishDate;	/* 发布日期 */
	BCESFieldTypeTime PublishTime;	/* 发布时间 */
	BCESFieldTypeDate CreateDate;	/* 创建日期 */
	BCESFieldTypeTime CreateTime;	/* 创建时间 */
	BCESFieldTypeFlag PublishMethod;	/* 发布方式 */
	BCESFieldTypeUserID PublishUserID;	/* 发布人 */
};

/* 公告查询请求 */
struct stBCESBulletinQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 通知查询请求 */
struct stBCESNoticeQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 通知 */
struct stBCESNotice
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeNoticeID NoticeID;	/* 通知编号 */
	BCESFieldTypeTitle Title;	/* 通知标题 */
	BCESFieldTypeContent Content;	/* 通知内容 */
	BCESFieldTypeDate PublishDate;	/* 发布日期 */
	BCESFieldTypeTime PublishTime;	/* 发布时间 */
	BCESFieldTypeDate CreateDate;	/* 创建日期 */
	BCESFieldTypeTime CreateTime;	/* 创建时间 */
	BCESFieldTypeFlag PublishMethod;	/* 发布方式 */
	BCESFieldTypeUserID PublishUserID;	/* 发布人 */
};

/* 电子出入金请求 */
struct stBCESElectronicFundIOReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag FundIODirection;	/* 出入金方向 */
	BCESFieldTypeAmount Amount;	/* 金额 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
};

/* 电子出入金响应 */
struct stBCESElectronicFundIORsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFundIOSeqno FundIOSeqno;	/* 出入金流水号 */
	BCESFieldTypeFlag FundIODirection;	/* 出入金方向 */
	BCESFieldTypeAmount Amount;	/* 金额 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
	BCESFieldTypeDate CreateDate;	/* 发起日期 */
	BCESFieldTypeTime CreateTime;	/* 发起时间 */
	BCESFieldTypeFlag FundIOStatus;	/* 出入金状态 */
	BCESFieldTypeFundIOStatusDesc FundIOStatusDesc;	/* 出入金状态描述 */
	BCESFieldTypeDate CompleteDate;	/* 完成日期 */
	BCESFieldTypeTime CompleteTime;	/* 完成时间 */
	BCESFieldTypeURL PayURL;	/* 支付链接 */
};

/* 电子出入金通知 */
struct stBCESElectronicFundIONty
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFundIOSeqno FundIOSeqno;	/* 出入金流水号 */
	BCESFieldTypeFlag FundIODirection;	/* 出入金方向 */
	BCESFieldTypeAmount Amount;	/* 金额 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
	BCESFieldTypeFlag FundIOStatus;	/* 出入金状态 */
	BCESFieldTypeFundIOStatusDesc FundIOStatusDesc;	/* 出入金状态描述 */
	BCESFieldTypeDate CreateDate;	/* 发起日期 */
	BCESFieldTypeTime CreateTime;	/* 发起时间 */
	BCESFieldTypeDate CompleteDate;	/* 完成日期 */
	BCESFieldTypeTime CompleteTime;	/* 完成时间 */
	BCESFieldTypeURL PayURL;	/* 支付链接 */
};

/* 出入金明细 */
struct stBCESFundIODetail
{
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeFundIOSeqno FundIOSeqno;	/* 出入金流水号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag FundIODirection;	/* 出入金方向 */
	BCESFieldTypeAmount Amount;	/* 金额 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
	BCESFieldTypeFlag FundIOStatus;	/* 出入金状态 */
	BCESFieldTypeDate CreateDate;	/* 发起日期 */
	BCESFieldTypeTime CreateTime;	/* 发起时间 */
	BCESFieldTypeDate CompleteDate;	/* 完成日期 */
	BCESFieldTypeTime CompleteTime;	/* 完成时间 */
	BCESFieldTypeFlag FundIOMethod;	/* 出入金方式 */
	BCESFieldTypeFundIOStatusDesc FundIOStatusDesc;	/* 出入金状态描述 */
	BCESFieldTypeAddress ReceiveBranchName;	/* 支行名称 */
	BCESFieldTypePaySeqno PaySeqno;	/* 支付流水号 */
};

/* 出入金明细查询请求 */
struct stBCESFundIODetailQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 起始日期 */
};

/* 报表查询请求 */
struct stBCESReportQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 报表 */
struct stBCESReport
{
	BCESFieldTypeReportData ReportData;	/* 报表内容 */
};

/* 历史订单查询请求 */
struct stBCESHisOrderQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 历史成交查询请求 */
struct stBCESHisTradeQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 历史公告查询请求 */
struct stBCESHisBulletinQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 起始日期 */
};

/* 历史通知查询请求 */
struct stBCESHisNoticeQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 起始日期 */
};

/* 投资者排名 */
struct stBCESInvestorRanking
{
	BCESFieldTypeInstrumentName InstrumentName;	/* 合约名 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};

/* 查询投资者排名请求 */
struct stBCESInvestorRankingQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 交易设置 */
struct stBCESTradeSettings
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};

/* 交易设置增加请求 */
struct stBCESTradeSettingsAddReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};

/* 交易设置增加应答 */
struct stBCESTradeSettingsAddRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置修改请求 */
struct stBCESTradeSettingsModifyReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};

/* 交易设置修改应答 */
struct stBCESTradeSettingsModifyRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置删除请求 */
struct stBCESTradeSettingsDeleteReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置删除应答 */
struct stBCESTradeSettingsDeleteRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置查询请求 */
struct stBCESTradeSettingsQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 签约信息 */
struct stBCESAccountBind
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
	BCESFieldTypeAddress ReceiveBranchName;	/* 支行名称 */
	BCESFieldTypeName ReceiveProvice;	/* 开户省份 */
	BCESFieldTypeName ReceiveCity;	/* 开户市 */
	BCESFieldTypeFlag AccountBindStatus;	/* 签约状态 */
	BCESFieldTypeFundIOStatusDesc AccountBindStatusDesc;	/* 签约状态描述 */
	BCESFieldTypeFlag CredentialType;	/* 证件类型 */
	BCESFieldTypeCredentialNo CredentialNo;	/* 证件号 */
};

/* 签约请求 */
struct stBCESAccountBindReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
	BCESFieldTypeAddress ReceiveBranchName;	/* 支行名称 */
	BCESFieldTypeName ReceiveProvice;	/* 开户省份 */
	BCESFieldTypeName ReceiveCity;	/* 开户市 */
	BCESFieldTypeFlag CredentialType;	/* 证件类型 */
	BCESFieldTypeCredentialNo CredentialNo;	/* 证件号 */
};

/* 签约信息查询请求 */
struct stBCESAccountBindQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 签约应答 */
struct stBCESAccountBindRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeURL AccountBindURL;	/* 网址 */
	BCESFieldTypeFlag AccountBindStatus;	/* 签约状态 */
};

/* 测试设置修改请求 */
struct stBCESTestSettingsModifyReq
{
	BCESFieldTypeUserID UserID;	/* 用户号 */
	BCESFieldTypePoints ErrNetTradeSec;	/* 网络故障成交延迟 */
	BCESFieldTypePoints ErrNetRemindSec;	/* 网络故障提醒延迟 */
	BCESFieldTypeRspDesc ErrNetRemindTxt;	/* 网络故障提醒信息 */
	BCESFieldTypePoints ErrSeverTradePort;	/* 服务器故障成交点差 */
	BCESFieldTypePoints ErrSeverRemindPort;	/* 服务器故障提醒点差 */
	BCESFieldTypeRspDesc ErrSeverRemindTxt;	/* 服务器故障提醒信息 */
};

/* 测试设置修改应答 */
struct stBCESTestSettingsModifyRsp
{
	BCESFieldTypeUserID UserID;	/* 用户号 */
};

/* 挂单量排名查询请求 */
struct stBCESTopInvestorQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 挂单量排名 */
struct stBCESTopInvestor
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeQty Qty;	/* 挂单量 */
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};

/* 投资者挂单查询请求 */
struct stBCESInvestorQuotQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeInvestorID RankingInvestorID;	/* 排名投资者号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 投资者挂单 */
struct stBCESInvestorQuot
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeQty Qty;	/* 挂单量 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};

/* 交易时间 */
struct stBCESTradeTime
{
	BCESFieldTypeTime TimeBegin;	/* 开始时间 */
	BCESFieldTypeTime TimeEnd;	/* 结束时间 */
	BCESFieldTypeFlag MarketStatus;	/* 市场状态 */
};

/* 交收交割申请 */
struct stBCESDeliveryApply
{
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDeliveryID DeliveryAddress;	/* 交收交割地址 */
	BCESFieldTypeName LiaisonName;	/* 联系人名称 */
	BCESFieldTypePhoneNo LiaisonNumber;	/* 联系电话 */
	BCESFieldTypeFlag CredentialType;	/* 证件类型 */
	BCESFieldTypeCredentialNo CredentialNo;	/* 证件号 */
	BCESFieldTypeAddress LiaisonAddress;	/* 联系地址 */
	BCESFieldTypePostCode PostCode;	/* 邮编 */
	BCESFieldTypeName CompanyName;	/* 企业名称 */
	BCESFieldTypeAddress CompanyAddress;	/* 公司地址 */
	BCESFieldTypePhoneNo CompanyNumber;	/* 公司电话 */
	BCESFieldTypeBankNameAccountID BankNameAccountID;	/* 银行名称及账号 */
	BCESFieldTypeTaxNo TaxNo;	/* 税务登记号 */
	BCESFieldTypeFlag InvoiceFlag;	/* 发票标识 */
	BCESFieldTypeFlag InvoiceType;	/* 发票类型 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypeFlag DeliveryStatus;	/* 交收交割状态 */
	BCESFieldTypeDate ApplyDate;	/* 申请日期 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 交收交割申请查看请求 */
struct stBCESDeliveryApplyQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
	BCESFieldTypeFlag DeliveryStatus;	/* 交收交割状态 */
};

/* 交收交割申请增加请求 */
struct stBCESDeliveryApplyAddReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDeliveryID DeliveryAddress;	/* 交收交割地址 */
	BCESFieldTypeName LiaisonName;	/* 联系人名称 */
	BCESFieldTypePhoneNo LiaisonNumber;	/* 联系电话 */
	BCESFieldTypeFlag CredentialType;	/* 证件类型 */
	BCESFieldTypeCredentialNo CredentialNo;	/* 证件号 */
	BCESFieldTypeAddress LiaisonAddress;	/* 联系地址 */
	BCESFieldTypePostCode PostCode;	/* 邮编 */
	BCESFieldTypeName CompanyName;	/* 企业名称 */
	BCESFieldTypeAddress CompanyAddress;	/* 公司地址 */
	BCESFieldTypePhoneNo CompanyNumber;	/* 公司电话 */
	BCESFieldTypeBankNameAccountID BankNameAccountID;	/* 银行名称及账号 */
	BCESFieldTypeTaxNo TaxNo;	/* 税务登记号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeFlag DeliveryStatus;	/* 交收交割状态 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypeDate ApplyDate;	/* 申请日期 */
	BCESFieldTypeFlag InvoiceFlag;	/* 发票标识 */
	BCESFieldTypeFlag InvoiceType;	/* 发票类型 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 交收交割申请增加应答 */
struct stBCESDeliveryApplyAddRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
};

/* 交收交割申请修改请求 */
struct stBCESDeliveryApplyModifyReq
{
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDeliveryID DeliveryAddress;	/* 交收交割地址 */
	BCESFieldTypeName LiaisonName;	/* 联系人名称 */
	BCESFieldTypePhoneNo LiaisonNumber;	/* 联系电话 */
	BCESFieldTypeFlag CredentialType;	/* 证件类型 */
	BCESFieldTypeCredentialNo CredentialNo;	/* 证件号 */
	BCESFieldTypeAddress LiaisonAddress;	/* 联系地址 */
	BCESFieldTypePostCode PostCode;	/* 邮编 */
	BCESFieldTypeName CompanyName;	/* 企业名称 */
	BCESFieldTypeAddress CompanyAddress;	/* 公司地址 */
	BCESFieldTypePhoneNo CompanyNumber;	/* 公司电话 */
	BCESFieldTypeBankNameAccountID BankNameAccountID;	/* 银行名称及账号 */
	BCESFieldTypeTaxNo TaxNo;	/* 税务登记号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeFlag DeliveryStatus;	/* 交收交割状态 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeQty Qty;	/* 数量 */
	BCESFieldTypeDate ApplyDate;	/* 申请日期 */
	BCESFieldTypeFlag InvoiceFlag;	/* 发票标识 */
	BCESFieldTypeFlag InvoiceType;	/* 发票类型 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 交收交割申请修改应答 */
struct stBCESDeliveryApplyModifyRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 交收交割申请删除请求 */
struct stBCESDeliveryApplyDeleteReq
{
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
};

/* 交收交割申请删除应答 */
struct stBCESDeliveryApplyDeleteRsp
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 行情顾问提问/回答请求 */
struct stBCESQuotAdviserQuesAnswReq
{
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeFlag QuesAnswFlag;	/* 提问回答标志 */
	BCESFieldTypeQuesAnswContent QuesAnswContent;	/* 提问/回答内容 */
	BCESFieldTypeDate QuesAnswDate;	/* 提问/回答日期 */
	BCESFieldTypeTime QuesAnswTime;	/* 提问/回答时间 */
};

/* 行情顾问提问/回答应答 */
struct stBCESQuotAdviserQuesAnswRsp
{
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
};

/* 行情顾问提问查询请求 */
struct stBCESQuotAdviserQuesQueryReq
{
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeFlag InvestorAdviserFlag;	/* 投资者顾问标志 */
};

/* 行情顾问提问查询应答 */
struct stBCESQuotAdviserQuesQuery
{
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeQuesAnswContent QuestionContent;	/* 提问内容 */
	BCESFieldTypeDate QuestionDate;	/* 提问日期 */
	BCESFieldTypeTime QuestionTime;	/* 提问时间 */
	BCESFieldTypeQuesAnswContent AnswerContent;	/* 回答内容 */
	BCESFieldTypeDate AnswerDate;	/* 回答日期 */
	BCESFieldTypeTime AnswerTime;	/* 回答时间 */
};

/* 行情顾问提问历史查询请求 */
struct stBCESQuotAdviserQuesHisQueryReq
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 行情顾问提问历史查询应答 */
struct stBCESQuotAdviserQuesHis
{
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeQuesAnswContent QuestionContent;	/* 提问内容 */
	BCESFieldTypeDate QuestionDate;	/* 提问日期 */
	BCESFieldTypeTime QuestionTime;	/* 提问时间 */
	BCESFieldTypeQuesAnswContent AnswerContent;	/* 回答内容 */
	BCESFieldTypeDate AnswerDate;	/* 回答日期 */
	BCESFieldTypeTime AnswerTime;	/* 回答时间 */
};

/* 投资者 */
struct stBCESInvestor
{
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypePassword InvestorPassword;	/* 收款户名 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeFlag InvestorFlag;	/* 投资者标志 */
	BCESFieldTypeAccountID AccountID;	/* 报单账号 */
};

/* K线查询请求 */
struct stBCESKLineQueryReq
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeFlag KLineType;	/* K线类型 */
	BCESFieldTypeRequestID BarFrom;	/* 起始Bar */
	BCESFieldTypeRequestID BarCount;	/* Bar数量 */
};

/* K线 */
struct stBCESKLineData
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTime;	/* 日期时间 */
	BCESFieldTypePrice OpenPrice;	/* 开盘价 */
	BCESFieldTypePrice HighestPrice;	/* 最高价 */
	BCESFieldTypePrice LowestPrice;	/* 最低价 */
	BCESFieldTypePrice ClosePrice;	/* 收盘价 */
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
	BCESFieldTypeQtyTotal OI;	/* 空盘量 */
	BCESFieldTypeAmount Amount;	/* 成交额 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeFlag KLineType;	/* K线类型 */
};

/* Tick线查询请求 */
struct stBCESTickLineQueryReq
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* Tick线 */
struct stBCESTickLineData
{
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTime;	/* 日期时间 */
	BCESFieldTypePrice Price;	/* 收盘价 */
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
	BCESFieldTypeQtyTotal OI;	/* 空盘量 */
	BCESFieldTypeAmount Amount;	/* 成交额 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypePrice BidPrice;	/* 叫买价 */
	BCESFieldTypeQty BidQty;	/* 叫买量 */
	BCESFieldTypePrice AskPrice;	/* 叫卖价 */
	BCESFieldTypeQty AskQty;	/* 叫卖量 */
	BCESFieldTypePrice HighLimit;	/* 涨停板价 */
	BCESFieldTypePrice LowLimit;	/* 跌停板价 */
};


#endif /* __API_FIELD_DEFINE_H__ */
