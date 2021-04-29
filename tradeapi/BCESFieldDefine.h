#ifndef __BCES_FIELD_DEFINE_H__
#define __BCES_FIELD_DEFINE_H__

#include "os.h"
#include "BCESFieldTypeDefine.h"
#include "BML.h"
#include "BMLField.h"
#include "BMLFields.h"

/* Field Rule List */
extern BML_FIELD_RULE bces_rulearray[];
extern int bces_rulecount;

/* MsgType */
#define BCESMsgTypePrivatePkgNty                  1	/* 私有报文通知 */
#define BCESMsgTypePublicPkgNty                   2	/* 公共报文通知 */
#define BCESMsgTypeFlowSubscribeReq               3	/* 流订阅请求 */
#define BCESMsgTypeFlowSubscribeRsp               4	/* 流订阅应答 */
#define BCESMsgTypeQuotSubscribeReq               7	/* 行情订阅请求 */
#define BCESMsgTypeQuotSubscribeRsp               8	/* 行情订阅应答 */
#define BCESMsgTypeQuotUnSubscribeReq             9	/* 行情退订请求 */
#define BCESMsgTypeQuotUnSubscribeRsp             10	/* 行情退订应答 */
#define BCESMsgTypeDBSyncNty                      11	/* 数据同步通知 */
#define BCESMsgTypeLoginReq                       116	/* 登录请求 */
#define BCESMsgTypeLoginRsp                       117	/* 登录应答 */
#define BCESMsgTypeLogoutReq                      118	/* 登出请求 */
#define BCESMsgTypeLogoutRsp                      119	/* 登出应答 */
#define BCESMsgTypeChangePasswordReq              120	/* 修改密码请求 */
#define BCESMsgTypeChangePasswordRsp              121	/* 修改密码应答 */
#define BCESMsgTypeOrderInsertReq                 122	/* 订单录入请求 */
#define BCESMsgTypeOrderInsertRsp                 123	/* 订单录入应答 */
#define BCESMsgTypeOrderNty                       124	/* 订单通知 */
#define BCESMsgTypeQuotNty                        125	/* 行情通知 */
#define BCESMsgTypeOrderCancelReq                 127	/* 撤单请求 */
#define BCESMsgTypeOrderCancelRsp                 128	/* 撤单应答 */
#define BCESMsgTypeMarketStatusNty                129	/* 市场状态通知 */
#define BCESMsgTypeTradeNty                       130	/* 成交通知 */
#define BCESMsgTypeQuotQueryReq                   131	/* 行情查询请求 */
#define BCESMsgTypeQuotQueryRsp                   132	/* 行情查询应答 */
#define BCESMsgTypeOrderQueryReq                  137	/* 订单查询请求 */
#define BCESMsgTypeOrderQueryRsp                  138	/* 订单查询应答 */
#define BCESMsgTypeTradeQueryReq                  139	/* 成交查询请求 */
#define BCESMsgTypeTradeQueryRsp                  140	/* 成交查询应答 */
#define BCESMsgTypePosiQueryReq                   141	/* 持仓查询请求 */
#define BCESMsgTypePosiQueryRsp                   142	/* 持仓查询应答 */
#define BCESMsgTypeFundQueryReq                   143	/* 资金查询请求 */
#define BCESMsgTypeFundQueryRsp                   144	/* 资金查询应答 */
#define BCESMsgTypeInstrumentQueryReq             145	/* 合约查询请求 */
#define BCESMsgTypeInstrumentQueryRsp             146	/* 合约查询应答 */
#define BCESMsgTypePosiDetailQueryReq             147	/* 持仓明细查询请求 */
#define BCESMsgTypePosiDetailQueryRsp             148	/* 持仓明细查询应答 */
#define BCESMsgTypeInternationalQuotNty           149	/* 国际行情通知 */
#define BCESMsgTypeMinDataQueryReq                150	/* 分线查询请求 */
#define BCESMsgTypeMinDataQueryRsp                151	/* 分线查询应答 */
#define BCESMsgTypeDayDataQueryReq                152	/* 日线查询请求 */
#define BCESMsgTypeDayDataQueryRsp                153	/* 日线查询应答 */
#define BCESMsgTypeProfitLossStopSetReq           154	/* 止赢止损设置请求 */
#define BCESMsgTypeProfitLossStopSetRsp           155	/* 止赢止损设置应答 */
#define BCESMsgTypePosiDetailNty                  156	/* 持仓明细通知 */
#define BCESMsgTypeFundNty                        157	/* 资金通知 */
#define BCESMsgTypePosiNty                        158	/* 持仓通知 */
#define BCESMsgTypeOrderModifyReq                 159	/* 订单修改请求 */
#define BCESMsgTypeOrderModifyRsp                 160	/* 订单修改应答 */
#define BCESMsgTypeBulletinQueryReq               161	/* 公告查询请求 */
#define BCESMsgTypeBulletinQueryRsp               162	/* 公告查询应答 */
#define BCESMsgTypeNoticeQueryReq                 163	/* 通知查询请求 */
#define BCESMsgTypeNoticeQueryRsp                 164	/* 通知查询应答 */
#define BCESMsgTypeBulletinNty                    165	/* 公告通知 */
#define BCESMsgTypeNoticeNty                      166	/* 信息通知 */
#define BCESMsgTypeElectronicFundIOReq            167	/* 电子出入金请求 */
#define BCESMsgTypeElectronicFundIORsp            168	/* 电子出入金请求应答 */
#define BCESMsgTypeElectronicFundIONty            169	/* 电子出入金通知 */
#define BCESMsgTypeFundIODetailQueryReq           170	/* 出入金明细查询请求 */
#define BCESMsgTypeFundIODetailQueryRsp           171	/* 出入金明细查询应答 */
#define BCESMsgTypeReportQueryReq                 172	/* 报表查询请求 */
#define BCESMsgTypeReportQueryRsp                 173	/* 报表查询应答 */
#define BCESMsgTypeHisOrderQueryReq               174	/* 历史订单查询请求 */
#define BCESMsgTypeHisOrderQueryRsp               175	/* 历史订单查询应答 */
#define BCESMsgTypeHisTradeQueryReq               176	/* 历史成交查询请求 */
#define BCESMsgTypeHisTradeQueryRsp               177	/* 历史成交查询应答 */
#define BCESMsgTypeHisBulletinQueryReq            178	/* 历史公告查询请求 */
#define BCESMsgTypeHisBulletinQueryRsp            179	/* 历史公告查询应答 */
#define BCESMsgTypeHisNoticeQueryReq              180	/* 历史通知查询请求 */
#define BCESMsgTypeHisNoticeQueryRsp              181	/* 通知查询应答 */
#define BCESMsgTypeMin5DataQueryReq               192	/* 5分线查询请求 */
#define BCESMsgTypeMin5DataQueryRsp               193	/* 5分线查询应答 */
#define BCESMsgTypeMin15DataQueryReq              194	/* 15分线查询请求 */
#define BCESMsgTypeMin15DataQueryRsp              195	/* 15分线查询应答 */
#define BCESMsgTypeAccountBindReq                 196	/* 签约请求 */
#define BCESMsgTypeAccountBindRsp                 197	/* 签约应答 */
#define BCESMsgTypeAccountBindQueryReq            198	/* 签约信息查询请求 */
#define BCESMsgTypeAccountBindQueryRsp            199	/* 签约信息查询应答 */
#define BCESMsgTypeHisFundQueryReq                200	/* 资金查询请求 */
#define BCESMsgTypeHisFundQueryRsp                201	/* 资金查询应答 */
#define BCESMsgTypeHisPosiDetailQueryReq          202	/* 持仓明细查询请求 */
#define BCESMsgTypeHisPosiDetailQueryRsp          203	/* 持仓明细查询应答 */
#define BCESMsgTypeAccountBindNty                 210	/* 签约通知 */
#define BCESMsgTypeTradeDetailDataQueryReq        211	/* 成交明细查询请求 */
#define BCESMsgTypeTradeDetailDataQueryRsp        212	/* 成交明细查询应答 */
#define BCESMsgTypeExtOrderInsertReq              213	/* 报盘订单录入请求 */
#define BCESMsgTypeExtOrderInsertRsp              214	/* 报盘订单录入应答 */
#define BCESMsgTypeExtOrderNty                    215	/* 报盘订单通知 */
#define BCESMsgTypeExtQuotNty                     216	/* 报盘行情通知 */
#define BCESMsgTypeExtOrderCancelReq              218	/* 报盘撤单请求 */
#define BCESMsgTypeExtOrderCancelRsp              219	/* 报盘撤单应答 */
#define BCESMsgTypeExtMarketStatusNty             220	/* 报盘市场状态通知 */
#define BCESMsgTypeExtTradeNty                    221	/* 报盘成交通知 */
#define BCESMsgTypeKLineQueryReq                  243	/* K线查询请求 */
#define BCESMsgTypeKLineQueryRsp                  244	/* K线查询应答 */
#define BCESMsgTypeTickLineQueryReq               245	/* Tick线查询请求 */
#define BCESMsgTypeTickLineQueryRsp               246	/* Tick线查询应答 */
#define BCESMsgTypeMatchLoginNty                  300	/* 报盘登录通知 */

/* FieldNo */
#define BCESFieldNoHead                           1000	/* 报文头 */
#define BCESFieldNoBody                           1001	/* 报文体 */
#define BCESFieldNoFlowID                         1002	/* 流编号 */
#define BCESFieldNoRequestID                      1003	/* 请求编号 */
#define BCESFieldNoEndFlag                        1004	/* 结束标记 */
#define BCESFieldNoPkgNo                          1005	/* 报文编号 */
#define BCESFieldNoServiceNo                      1008	/* 指令编码 */
#define BCESFieldNoApiHead                        1009	/* API报文头 */
#define BCESFieldNoApiBody                        1010	/* API报文体 */
#define BCESFieldNoFlowSubscribeReq               1013	/* 流订阅请求 */
#define BCESFieldNoFlowSubscribeReqList           1014	/* 流订阅请求列表 */
#define BCESFieldNoFlowSubscribeRsp               1015	/* 流订阅应答 */
#define BCESFieldNoFlowSubscribeRspList           1016	/* 流订阅应答列表 */
#define BCESFieldNoQuotSubscribeReq               1017	/* 行情订阅请求 */
#define BCESFieldNoQuotSubscribeRsp               1018	/* 行情订阅应答 */
#define BCESFieldNoQuotUnSubscribeReq             1019	/* 行情退订请求 */
#define BCESFieldNoQuotUnSubscribeRsp             1020	/* 行情退订应答 */
#define BCESFieldNoDBOperateSummary               1021	/* 数据操作概要 */
#define BCESFieldNoDBOperateList                  1022	/* 数据操作列表 */
#define BCESFieldNoTableName                      1023	/* 表名 */
#define BCESFieldNoTableOperation                 1024	/* 表操作 */
#define BCESFieldNoRspInfo                        1025	/* 应答信息域 */
#define BCESFieldNoRspNo                          1026	/* 应答编码 */
#define BCESFieldNoRspDesc                        1027	/* 应答描述 */
#define BCESFieldNoLoginReq                       1032	/* 登录请求 */
#define BCESFieldNoLoginRsp                       1033	/* 登录应答 */
#define BCESFieldNoInvestorID                     1034	/* 投资者号 */
#define BCESFieldNoInvestorPassword               1035	/* 投资者密码 */
#define BCESFieldNoLogoutReq                      1037	/* 登出请求 */
#define BCESFieldNoLogoutRsp                      1038	/* 登出应答 */
#define BCESFieldNoChangePasswordReq              1039	/* 修改密码请求 */
#define BCESFieldNoChangePasswordRsp              1040	/* 修改密码应答 */
#define BCESFieldNoInvestorOldPassword            1041	/* 投资者旧密码 */
#define BCESFieldNoInvestorNewPassword            1042	/* 投资者新密码 */
#define BCESFieldNoInputOrder                     1043	/* 订单录入 */
#define BCESFieldNoBSFlag                         1045	/* 买卖标志 */
#define BCESFieldNoInstrumentID                   1046	/* 合约号 */
#define BCESFieldNoPrice                          1047	/* 价格 */
#define BCESFieldNoQty                            1048	/* 数量 */
#define BCESFieldNoOCFlag                         1049	/* 开平标志 */
#define BCESFieldNoOrderDate                      1055	/* 报单日期 */
#define BCESFieldNoOrderID                        1056	/* 订单号 */
#define BCESFieldNoPriceType                      1059	/* 价格类型 */
#define BCESFieldNoOrderTime                      1060	/* 报单时间 */
#define BCESFieldNoQtyLeft                        1061	/* 剩余数量 */
#define BCESFieldNoModifyDate                     1062	/* 修改日期 */
#define BCESFieldNoModifyTime                     1063	/* 修改时间 */
#define BCESFieldNoOrderStatus                    1064	/* 订单状态 */
#define BCESFieldNoOrderCancelReq                 1065	/* 撤单请求 */
#define BCESFieldNoOrderCancelRsp                 1066	/* 撤单应答 */
#define BCESFieldNoInstrumentType                 1068	/* 合约类型 */
#define BCESFieldNoMatchDate                      1070	/* 成交日期 */
#define BCESFieldNoMatchTime                      1071	/* 成交时间 */
#define BCESFieldNoMatchID                        1072	/* 成交号 */
#define BCESFieldNoPosiID                         1073	/* 持仓号 */
#define BCESFieldNoTradeDate                      1081	/* 交易日期 */
#define BCESFieldNoBidPrice                       1083	/* 叫买价 */
#define BCESFieldNoAskPrice                       1084	/* 叫卖价 */
#define BCESFieldNoPreSettle                      1085	/* 昨结算价 */
#define BCESFieldNoPreOI                          1086	/* 昨持仓量 */
#define BCESFieldNoQtyTotal                       1087	/* 成交量 */
#define BCESFieldNoOI                             1088	/* 持仓量 */
#define BCESFieldNoAmount                         1089	/* 成交金额 */
#define BCESFieldNoAvgPrice                       1090	/* 均价 */
#define BCESFieldNoSettlePrice                    1091	/* 结算价 */
#define BCESFieldNoPreClose                       1092	/* 昨收盘价 */
#define BCESFieldNoOpenPrice                      1093	/* 开盘价 */
#define BCESFieldNoHighestPrice                   1094	/* 最高价 */
#define BCESFieldNoLowestPrice                    1095	/* 最低价 */
#define BCESFieldNoClosePrice                     1096	/* 收盘价 */
#define BCESFieldNoAmountTotal                    1097	/* 成交额 */
#define BCESFieldNoBidQty                         1099	/* 叫买量 */
#define BCESFieldNoAskQty                         1100	/* 叫卖量 */
#define BCESFieldNoQuotList                       1139	/* 行情列表 */
#define BCESFieldNoQuotQueryReq                   1140	/* 行情查询请求 */
#define BCESFieldNoQuot                           1141	/* 行情 */
#define BCESFieldNoInternationalQuot              1142	/* 国际行情 */
#define BCESFieldNoOrderQueryReq                  1147	/* 订单查询请求 */
#define BCESFieldNoOrder                          1148	/* 订单 */
#define BCESFieldNoTradeQueryReq                  1149	/* 成交查询请求 */
#define BCESFieldNoTrade                          1150	/* 成交单 */
#define BCESFieldNoPosiQueryReq                   1151	/* 持仓查询请求 */
#define BCESFieldNoPosi                           1152	/* 持仓 */
#define BCESFieldNoOrderList                      1154	/* 订单列表 */
#define BCESFieldNoTradeList                      1155	/* 成交单列表 */
#define BCESFieldNoPosiList                       1156	/* 持仓列表 */
#define BCESFieldNoMarketStatus                   1158	/* 市场状态 */
#define BCESFieldNoMarketStatusNty                1159	/* 市场状态通知 */
#define BCESFieldNoHisFundQueryReq                1160	/* 资金查询请求 */
#define BCESFieldNoHisPosiDetailQueryReq          1261	/* 持仓明细查询请求 */
#define BCESFieldNoFreeBalance                    1163	/* 可用资金 */
#define BCESFieldNoFundQueryReq                   1164	/* 资金查询请求 */
#define BCESFieldNoFund                           1165	/* 资金 */
#define BCESFieldNoFrozenBalance                  1169	/* 冻结资金 */
#define BCESFieldNoLastBalance                    1170	/* 上日资金 */
#define BCESFieldNoFloatBalance                   1171	/* 当日出入金 */
#define BCESFieldNoMargin                         1172	/* 当日保证金 */
#define BCESFieldNoFrozenMargin                   1173	/* 当日追加保证金 */
#define BCESFieldNoFee                            1174	/* 手续费 */
#define BCESFieldNoFeeFrozen                      1175	/* 冻结手续费 */
#define BCESFieldNoClosedPL                       1176	/* 当日平仓盈亏 */
#define BCESFieldNoFloatingPL                     1177	/* 当日总盈亏 */
#define BCESFieldNoProfitLoss                     1178	/* 当日交易手续费 */
#define BCESFieldNoTotalPL                        1179	/* 当日风险手续费 */
#define BCESFieldNoInstrumentList                 1185	/* 合约列表 */
#define BCESFieldNoInstrumentQueryReq             1186	/* 合约查询请求 */
#define BCESFieldNoInstrument                     1187	/* 合约 */
#define BCESFieldNoMarketStatusDesc               1189	/* 市场状态描述 */
#define BCESFieldNoVarietyID                      1201	/* 品种代码 */
#define BCESFieldNoInstrumentStatus               1202	/* 合约状态 */
#define BCESFieldNoTradeUnit                      1204	/* 交易单位 */
#define BCESFieldNoPriceUnit                      1205	/* 报价单位 */
#define BCESFieldNoDailyPriceLimit                1207	/* 涨跌停限制 */
#define BCESFieldNoFeeType                        1208	/* 手续费类型 */
#define BCESFieldNoFeeRate                        1209	/* 手续费率 */
#define BCESFieldNoPriceScale                     1211	/* 报价精度 */
#define BCESFieldNoMarginRate                     1213	/* 保证金率 */
#define BCESFieldNoHighLimit                      1214	/* 涨停板价 */
#define BCESFieldNoLowLimit                       1215	/* 跌停板价 */
#define BCESFieldNoBuyQtyFrozen                   1216	/* 买冻结持仓量 */
#define BCESFieldNoSellQtyFrozen                  1217	/* 卖冻结持仓量 */
#define BCESFieldNoPosiDetailQueryReq             1267	/* 持仓明细查询请求 */
#define BCESFieldNoPosiDetail                     1268	/* 持仓明细 */
#define BCESFieldNoPosiDetailList                 1269	/* 持仓明细列表 */
#define BCESFieldNoInstrumentName                 1270	/* 合约名称 */
#define BCESFieldNoMinMovement                    1271	/* 价格变动限制 */
#define BCESFieldNoPriceCoefficient               1272	/* 价格变动限制 */
#define BCESFieldNoBuyQty                         1273	/* 买持仓量 */
#define BCESFieldNoBuyPrice                       1274	/* 买持仓均价 */
#define BCESFieldNoSellQty                        1275	/* 卖持仓量 */
#define BCESFieldNoSellPrice                      1276	/* 卖持仓均价 */
#define BCESFieldNoMinDataQueryReq                1277	/* 分线查询请求 */
#define BCESFieldNoMinData                        1278	/* 分线 */
#define BCESFieldNoDayDataQueryReq                1279	/* 日线查询请求 */
#define BCESFieldNoDayData                        1280	/* 日线 */
#define BCESFieldNoMinDataList                    1281	/* 分线列表 */
#define BCESFieldNoDayDataList                    1282	/* 日线列表 */
#define BCESFieldNoDateTimeFrom                   1283	/* 起始日期时间 */
#define BCESFieldNoDateTimeTo                     1284	/* 结束日期时间 */
#define BCESFieldNoDateFrom                       1285	/* 起始日期 */
#define BCESFieldNoDateTo                         1286	/* 结束日期 */
#define BCESFieldNoDate                           1287	/* 日期 */
#define BCESFieldNoTime                           1288	/* 时间 */
#define BCESFieldNoTimeFrom                       1289	/* 起始时间 */
#define BCESFieldNoTimeTo                         1290	/* 结束时间 */
#define BCESFieldNoDateTime                       1291	/* 日期时间 */
#define BCESFieldNoLimitedFilledPoints            1292	/* 最小成交滑点 */
#define BCESFieldNoLimitedOrderPoints             1293	/* 最小报价点差 */
#define BCESFieldNoLimitedStopPoints              1294	/* 最小止赢止损点差 */
#define BCESFieldNoProfitStopPrice                1295	/* 止赢价 */
#define BCESFieldNoLossStopPrice                  1296	/* 止损价 */
#define BCESFieldNoProfitLossStopSetReq           1297	/* 止赢止损设置请求 */
#define BCESFieldNoProfitLossStopSetRsp           1298	/* 止赢止损设置应答 */
#define BCESFieldNoFilledPoints                   1299	/* 成交滑点 */
#define BCESFieldNoCreateDate                     1365	/* 发起日期 */
#define BCESFieldNoCreateTime                     1366	/* 发起时间 */
#define BCESFieldNoPublishDate                    1374	/* 发布日期 */
#define BCESFieldNoPublishTime                    1375	/* 发布时间 */
#define BCESFieldNoBulletinQueryReq               1378	/* 查询公告请求 */
#define BCESFieldNoBulletinList                   1383	/* 公告列表 */
#define BCESFieldNoBulletin                       1384	/* 公告 */
#define BCESFieldNoPublishUserID                  1385	/* 发布人 */
#define BCESFieldNoBulletinID                     1386	/* 公告编号 */
#define BCESFieldNoTitle                          1387	/* 标题 */
#define BCESFieldNoContent                        1388	/* 内容 */
#define BCESFieldNoNoticeID                       1389	/* 通知编号 */
#define BCESFieldNoPublishMethod                  1390	/* 发布方式 */
#define BCESFieldNoNoticeList                     1398	/* 通知列表 */
#define BCESFieldNoNotice                         1399	/* 通知 */
#define BCESFieldNoNoticeQueryReq                 1393	/* 查询通知请求 */
#define BCESFieldNoFundIODirection                1394	/* 出入金方向 */
#define BCESFieldNoFundIOStatus                   1395	/* 出入金状态 */
#define BCESFieldNoCompleteDate                   1396	/* 完成日期 */
#define BCESFieldNoCompleteTime                   1397	/* 完成时间 */
#define BCESFieldNoFundIOSeqno                    1398	/* 出入金流水号 */
#define BCESFieldNoFundIOStatusDesc               1399	/* 出入金状态描述 */
#define BCESFieldNoElectronicFundIOReq            1411	/* 电子出入金请求 */
#define BCESFieldNoElectronicFundIORsp            1412	/* 电子出入金响应 */
#define BCESFieldNoPayURL                         1413	/* 网址 */
#define BCESFieldNoPayDirection                   1414	/* 支付方向 */
#define BCESFieldNoElectronicFundIONty            1415	/* 电子出入金通知 */
#define BCESFieldNoFundIOMethod                   1416	/* 出入金方式 */
#define BCESFieldNoFundIODetail                   1417	/* 出入金明细 */
#define BCESFieldNoFundIODetailList               1418	/* 出入金明细列表 */
#define BCESFieldNoFundIODetailQueryReq           1419	/* 出入金明细查询请求 */
#define BCESFieldNoReceiveBankID                  1420	/* 收款行号 */
#define BCESFieldNoReceiveAccountID               1421	/* 收款帐号 */
#define BCESFieldNoReceiveAccountName             1422	/* 收款户名 */
#define BCESFieldNoReport                         1423	/* 报表 */
#define BCESFieldNoReportList                     1424	/* 报表列表 */
#define BCESFieldNoReportQueryReq                 1425	/* 报表查询请求 */
#define BCESFieldNoReportData                     1426	/* 报表内容 */
#define BCESFieldNoHisOrderQueryReq               1427	/* 历史订单查询请求 */
#define BCESFieldNoHisTradeQueryReq               1428	/* 历史成交查询请求 */
#define BCESFieldNoHisBulletinQueryReq            1429	/* 查询历史公告请求 */
#define BCESFieldNoHisNoticeQueryReq              1430	/* 查询历史通知请求 */
#define BCESFieldNoInvestorRanking                1459	/* 投资者排名 */
#define BCESFieldNoInvestorRankingList            1460	/* 投资者排名列表 */
#define BCESFieldNoInvestorRankingQueryReq        1467	/* 投资者排名查询请求 */
#define BCESFieldNoInvestorRankingQueryRsp        1468	/* 投资者排名查询应答 */
#define BCESFieldNoRankingNum                     1469	/* 排名 */
#define BCESFieldNoInvestorName                   1470	/* 投资者名称 */
#define BCESFieldNoTradeSettings                  1471	/* 交易设置 */
#define BCESFieldNoTradeSettingsList              1472	/* 交易设置列表 */
#define BCESFieldNoTradeSettingsAddReq            1473	/* 交易设置增加请求 */
#define BCESFieldNoTradeSettingsAddRsp            1474	/* 交易设置增加应答 */
#define BCESFieldNoTradeSettingsModifyReq         1475	/* 交易设置修改请求 */
#define BCESFieldNoTradeSettingsModifyRsp         1476	/* 交易设置修改应答 */
#define BCESFieldNoTradeSettingsDeleteReq         1477	/* 交易设置删除请求 */
#define BCESFieldNoTradeSettingsDeleteRsp         1478	/* 交易设置删除应答 */
#define BCESFieldNoTradeSettingsQueryReq          1479	/* 交易设置查询请求 */
#define BCESFieldNoTradeAction                    1480	/* 交易行为 */
#define BCESFieldNoAddress                        1481	/* 产地 */
#define BCESFieldNoWareHouse                      1482	/* 仓库 */
#define BCESFieldNoCurrency                       1483	/* 币种 */
#define BCESFieldNoAccountBind                    1484	/* 签约信息 */
#define BCESFieldNoAccountBindList                1485	/* 签约信息列表 */
#define BCESFieldNoAccountBindQueryReq            1486	/* 签约信息查询请求 */
#define BCESFieldNoAccountBindReq                 1488	/* 签约请求 */
#define BCESFieldNoAccountBindRsp                 1489	/* 签约应答 */
#define BCESFieldNoCloseDate                      1511	/* 平仓日期 */
#define BCESFieldNoCloseTime                      1512	/* 平仓时间 */
#define BCESFieldNoOverNightFee                   1513	/* 隔夜费 */
#define BCESFieldNoAgentName                      1514	/* 代理商名称 */
#define BCESFieldNoInAmount                       1515	/* 入金金额 */
#define BCESFieldNoOutAmount                      1516	/* 出金金额 */
#define BCESFieldNoFundList                       1517	/* 资金列表 */
#define BCESFieldNoSysName                        1518	/* 系统名称 */
#define BCESFieldNoErrNetTradeSec                 1521	/* 网络故障成交延迟 */
#define BCESFieldNoErrNetRemindSec                1522	/* 网络故障提醒延迟 */
#define BCESFieldNoErrNetRemindTxt                1523	/* 网络故障提醒信息 */
#define BCESFieldNoErrSeverTradePort              1524	/* 服务器故障成交点差 */
#define BCESFieldNoErrSeverRemindPort             1525	/* 服务器故障提醒点差 */
#define BCESFieldNoErrSeverRemindTxt              1526	/* 服务器故障提醒信息 */
#define BCESFieldNoTestSettingsModifyReq          1528	/* 测试设置修改请求 */
#define BCESFieldNoTestSettingsModifyRsp          1529	/* 测试设置修改应答 */
#define BCESFieldNoMarginRateType                 1615	/* 保证金率类型 */
#define BCESFieldNoOverNightFeeType               1616	/* 隔夜费类型 */
#define BCESFieldNoFeeFlag                        1616	/* 收费类型 */
#define BCESFieldNoPriceMultiply                  1617	/* 报价乘数 */
#define BCESFieldNoEachQtyLimt                    1619	/* 每笔持仓限量 */
#define BCESFieldNoTotalQtyLimt                   1620	/* 总持仓限量 */
#define BCESFieldNoUserID                         1621	/* 操作员号 */
#define BCESFieldNoBidPrice2                      1622	/* 叫买价2 */
#define BCESFieldNoAskPrice2                      1623	/* 叫卖价2 */
#define BCESFieldNoBidQty2                        1624	/* 叫买量2 */
#define BCESFieldNoAskQty2                        1625	/* 叫卖量2 */
#define BCESFieldNoBidPrice3                      1626	/* 叫买价3 */
#define BCESFieldNoAskPrice3                      1627	/* 叫卖价3 */
#define BCESFieldNoBidQty3                        1628	/* 叫买量3 */
#define BCESFieldNoAskQty3                        1629	/* 叫卖量3 */
#define BCESFieldNoBidPrice4                      1630	/* 叫买价4 */
#define BCESFieldNoAskPrice4                      1631	/* 叫卖价4 */
#define BCESFieldNoBidQty4                        1632	/* 叫买量4 */
#define BCESFieldNoAskQty4                        1633	/* 叫卖量4 */
#define BCESFieldNoBidPrice5                      1634	/* 叫买价5 */
#define BCESFieldNoAskPrice5                      1635	/* 叫卖价5 */
#define BCESFieldNoBidQty5                        1636	/* 叫买量5 */
#define BCESFieldNoAskQty5                        1637	/* 叫卖量5 */
#define BCESFieldNoSysMode                        1638	/* 系统模式 */
#define BCESFieldNoQtyFrozen                      1639	/* 冻结持仓量 */
#define BCESFieldNoBidPrice6                      1640	/* 叫买价6 */
#define BCESFieldNoAskPrice6                      1641	/* 叫卖价6 */
#define BCESFieldNoBidQty6                        1642	/* 叫买量6 */
#define BCESFieldNoAskQty6                        1643	/* 叫卖量6 */
#define BCESFieldNoBidPrice7                      1644	/* 叫买价7 */
#define BCESFieldNoAskPrice7                      1645	/* 叫卖价7 */
#define BCESFieldNoBidQty7                        1646	/* 叫买量7 */
#define BCESFieldNoAskQty7                        1647	/* 叫卖量7 */
#define BCESFieldNoBidPrice8                      1648	/* 叫买价8 */
#define BCESFieldNoAskPrice8                      1649	/* 叫卖价8 */
#define BCESFieldNoBidQty8                        1650	/* 叫买量8 */
#define BCESFieldNoAskQty8                        1651	/* 叫卖量8 */
#define BCESFieldNoBidPrice9                      1652	/* 叫买价9 */
#define BCESFieldNoAskPrice9                      1653	/* 叫卖价9 */
#define BCESFieldNoBidQty9                        1654	/* 叫买量9 */
#define BCESFieldNoAskQty9                        1655	/* 叫卖量9 */
#define BCESFieldNoBidPrice10                     1656	/* 叫买价10 */
#define BCESFieldNoAskPrice10                     1657	/* 叫卖价10 */
#define BCESFieldNoBidQty10                       1658	/* 叫买量10 */
#define BCESFieldNoAskQty10                       1659	/* 叫卖量10 */
#define BCESFieldNoIP                             1660	/* IP地址 */
#define BCESFieldNoTopInvestorQueryReq            1661	/* 挂单量排名查询请求 */
#define BCESFieldNoTopInvestor                    1662	/* 挂单量排名 */
#define BCESFieldNoTopInvestorList                1663	/* 挂单量排名列表 */
#define BCESFieldNoInvestorQuotQueryReq           1664	/* 投资者挂单查询请求 */
#define BCESFieldNoInvestorQuot                   1665	/* 挂单量排名 */
#define BCESFieldNoInvestorQuotList               1666	/* 挂单量排名列表 */
#define BCESFieldNoRankingInvestorID              1667	/* 排名投资者号 */
#define BCESFieldNoConditionType                  1668	/* 条件类型 */
#define BCESFieldNoConditionMethod                1669	/* 条件方法 */
#define BCESFieldNoConditionPrice                 1670	/* 条件价格 */
#define BCESFieldNoGoodsName                      1671	/* 品种大类 */
#define BCESFieldNoTradeTime                      1672	/* 交易时间 */
#define BCESFieldNoTimeBegin                      1673	/* 开始时间 */
#define BCESFieldNoTimeEnd                        1674	/* 结束时间 */
#define BCESFieldNoReceiveBranchName              1675	/* 支行名称 */
#define BCESFieldNoReceiveProvice                 1676	/* 开户省份 */
#define BCESFieldNoReceiveCity                    1677	/* 开户市 */
#define BCESFieldNoAccountBindStatus              1678	/* 签约状态 */
#define BCESFieldNoAccountBindURL                 1679	/* 网址 */
#define BCESFieldNoAccountBindStatusDesc          1680	/* 签约状态描述 */
#define BCESFieldNoProductType                    1681	/* 产品编号 */
#define BCESFieldNoProductVersion                 1682	/* 产品版本号 */
#define BCESFieldNoDeliveryDemand                 1578	/* 交收交割需求 */
#define BCESFieldNoCompanyName                    1579	/* 企业名称 */
#define BCESFieldNoLiaisonName                    1560	/* 联系人名称 */
#define BCESFieldNoLiaisonNumber                  1561	/* 联系电话 */
#define BCESFieldNoLiaisonAddress                 1562	/* 联系地址 */
#define BCESFieldNoGuaranteedQty                  1563	/* 保守数量 */
#define BCESFieldNoGeneralQty                     1564	/* 一般数量 */
#define BCESFieldNoRiskQty                        1565	/* 风险数量 */
#define BCESFieldNoBankName                       1566	/* 银行名称 */
#define BCESFieldNoInvoiceTitle                   1567	/* 发票抬头 */
#define BCESFieldNoDeliveryDemandID               1568	/* 交收交割编号 */
#define BCESFieldNoDeliveryStatus                 1569	/* 交收交割状态 */
#define BCESFieldNoDeliveryDemandQueryReq         1570	/* 交收交割需求请求 */
#define BCESFieldNoDeliveryDemandQueryRsp         1571	/* 交收交割需求应答 */
#define BCESFieldNoInvoiceFlag                    1572	/* 发票标识 */
#define BCESFieldNoInvoiceType                    1573	/* 发票类型 */
#define BCESFieldNoCredentialType                 1304	/* 证件类型 */
#define BCESFieldNoCredentialNo                   1305	/* 证件号 */
#define BCESFieldNoEmail                          1306	/* 电子邮箱 */
#define BCESFieldNoPostCode                       1310	/* 邮编 */
#define BCESFieldNoBankAccountID                  1405	/* 银行帐号 */
#define BCESFieldNoBankNameAccountID              1406	/* 银行户名及账号 */
#define BCESFieldNoDeliveryApplyID                1574	/* 交收交割申请编号 */
#define BCESFieldNoDeliveryAddress                1575	/* 交收交割地址 */
#define BCESFieldNoApplyDate                      1576	/* 申请日期 */
#define BCESFieldNoVerifedDate                    1577	/* 确认日期 */
#define BCESFieldNoCompletedDate                  1578	/* 成交日期 */
#define BCESFieldNoCompanyAddress                 1579	/* 公司地址 */
#define BCESFieldNoTaxNo                          1580	/* 税务登记号 */
#define BCESFieldNoInvoice                        1581	/* 发票 */
#define BCESFieldNoDeliveryApplyAddReq            1595	/* 交收交割申请增加请求 */
#define BCESFieldNoDeliveryApplyAddRsp            1596	/* 交收交割申请增加应答 */
#define BCESFieldNoDeliveryApplyModifyReq         1597	/* 交收交割申请修改请求 */
#define BCESFieldNoDeliveryApplyModifyRsp         1598	/* 交收交割申请修改应答 */
#define BCESFieldNoDeliveryApply                  1599	/* 交收交割申请 */
#define BCESFieldNoDeliveryApplyQueryReq          1600	/* 交收交割申请查询请求 */
#define BCESFieldNoDeliveryApplyQueryRsp          1601	/* 交收交割申请查询应答 */
#define BCESFieldNoDeliveryApplyList              1602	/* 交收交割申请列表 */
#define BCESFieldNoDeliveryApplyDeleteReq         1603	/* 交收交割申请删除请求 */
#define BCESFieldNoDeliveryApplyDeleteRsp         1604	/* 交收交割申请删除应答 */
#define BCESFieldNoPayServerType                  1605	/* 支付服务类型 */
#define BCESFieldNoTradeDetailDataQueryReq        1606	/* 成交明细查询请求 */
#define BCESFieldNoCompanyNumber                  1607	/* 公司电话 */
#define BCESFieldNoTradeDetailDataList            1608	/* 成交明细列表 */
#define BCESFieldNoAdviserID                      1609	/* 顾问号 */
#define BCESFieldNoQuestionContent                1610	/* 提问内容 */
#define BCESFieldNoQuestionDate                   1611	/* 提问日期 */
#define BCESFieldNoQuestionTime                   1612	/* 提问时间 */
#define BCESFieldNoAnswerContent                  1613	/* 回答内容 */
#define BCESFieldNoAnswerDate                     1614	/* 回答日期 */
#define BCESFieldNoAnswerTime                     1615	/* 回答时间 */
#define BCESFieldNoQuestionID                     1616	/* 提问编号 */
#define BCESFieldNoQuesAnswFlag                   1617	/* 提问/回答标志 */
#define BCESFieldNoQuesAnswContent                1618	/* 提问/回答内容 */
#define BCESFieldNoQuesAnswDate                   1619	/* 提问/回答日期 */
#define BCESFieldNoQuesAnswTime                   1620	/* 提问/回答时间 */
#define BCESFieldNoInvestorAdviserFlag            1621	/* 投资者顾问标志 */
#define BCESFieldNoQuotAdviserQuesAnswReq         1622	/* 行情顾问提问/回答请求 */
#define BCESFieldNoQuotAdviserQuesAnswRsp         1623	/* 行情顾问提问/回答应答 */
#define BCESFieldNoQuotAdviserQuesHisQueryReq     1624	/* 行情顾问提问历史查询请求 */
#define BCESFieldNoQuotAdviserQuesHisQueryRsp     1625	/* 行情顾问提问历史查询应答 */
#define BCESFieldNoQuotAdviserQuesHisList         1626	/* 行情顾问提问历史查询列表 */
#define BCESFieldNoQuotAdviserQuesQueryReq        1627	/* 行情顾问提问查询请求 */
#define BCESFieldNoQuotAdviserQuesQueryRsp        1628	/* 行情顾问提问查询应答 */
#define BCESFieldNoQuotAdviserQuesQuerylist       1629	/* 行情顾问提问查询列表 */
#define BCESFieldNoPlateName                      1630	/* 板块 */
#define BCESFieldNoPreBuyQty                      1631	/* 昨买持仓量 */
#define BCESFieldNoPreSellQty                     1632	/* 昨卖持仓量 */
#define BCESFieldNoTodayBuyQty                    1633	/* 今买持仓量 */
#define BCESFieldNoTodaySellQty                   1634	/* 今卖持仓量 */
#define BCESFieldNoTodayBuyQtyFrozen              1635	/* 今买冻结持仓量 */
#define BCESFieldNoTodaySellQtyFrozen             1636	/* 今卖冻结持仓量 */
#define BCESFieldNoExchangeID                     1637	/* 交易所号 */
#define BCESFieldNoSessionID                      1638	/* 会话编号 */
#define BCESFieldNoOrderRef                       1639	/* 报单引用 */
#define BCESFieldNoCreatePrice                    1640	/* 建仓价 */
#define BCESFieldNoHistoryClosedPL                1641	/* 历史平仓盈亏 */
#define BCESFieldNoInvestorRole                   1642	/* 投资者角色 */
#define BCESFieldNoInvestorFlag                   1643	/* 投资者标志 */
#define BCESFieldNoPaySeqno                       1644	/* 支付流水号 */
#define BCESFieldNoPreQtyLeft                     1645	/* 上日剩余数量 */
#define BCESFieldNoCreateTradeDate                1646	/* 建仓交易日期 */
#define BCESFieldNoClosedTradeDate                1647	/* 平仓交易日期 */
#define BCESFieldNoClosedOrderID                  1648	/* 平仓订单号 */
#define BCESFieldNoClosedMatchID                  1649	/* 平仓成交号 */
#define BCESFieldNoAccountID                      1686	/* 报单账号 */
#define BCESFieldNoOrderStatusDesc                1707	/* 状态说明 */
#define BCESFieldNoOrderSysID                     1701	/* 交易所报单编号 */
#define BCESFieldNoCTPSessionID                   1697	/* 会话编号 */
#define BCESFieldNoCTPFrontID                     1698	/* 前置编号 */
#define BCESFieldNoCTPOrderRef                    1699	/* 报单引用 */
#define BCESFieldNoCloseFeeRate                   1703	/* 平仓手续费率 */
#define BCESFieldNoCloseTodayFeeRate              1704	/* 平今仓手续费率 */
#define BCESFieldNoStampRate                      1705	/* 印花税费率 */
#define BCESFieldNoKLineType                      1716	/* K线类型 */
#define BCESFieldNoKLineQueryReq                  1717	/* K线查询请求 */
#define BCESFieldNoKLineList                      1718	/* K线列表 */
#define BCESFieldNoTickLineQueryReq               1719	/* Tick线查询请求 */
#define BCESFieldNoTickLineList                   1720	/* Tick线列表 */
#define BCESFieldNoBarFrom                        1721	/* 起始Bar */
#define BCESFieldNoBarCount                       1722	/* Bar数量 */
#define BCESFieldNoAccountList                    1800	/* 报单账户列表 */
#define BCESFieldNoAccount                        1801	/* 报单账户 */
#define BCESFieldNoExchangeList                   1802	/* 交易所列表 */
#define BCESFieldNoExchange                       1803	/* 交易所 */
#define BCESFieldNoPreClosedPL                    1804	/* 上日平仓盈亏 */
#define BCESFieldNoPreClosePrice                  1805	/* 上日平仓价 */

/* FieldIndex */
#define BCESFieldIndexHead                           0	/* 报文头 */
#define BCESFieldIndexBody                           1	/* 报文体 */
#define BCESFieldIndexFlowID                         2	/* 流编号 */
#define BCESFieldIndexRequestID                      3	/* 请求编号 */
#define BCESFieldIndexEndFlag                        4	/* 结束标记 */
#define BCESFieldIndexPkgNo                          5	/* 报文编号 */
#define BCESFieldIndexServiceNo                      6	/* 指令编码 */
#define BCESFieldIndexApiHead                        7	/* API报文头 */
#define BCESFieldIndexApiBody                        8	/* API报文体 */
#define BCESFieldIndexFlowSubscribeReq               9	/* 流订阅请求 */
#define BCESFieldIndexFlowSubscribeReqList           10	/* 流订阅请求列表 */
#define BCESFieldIndexFlowSubscribeRsp               11	/* 流订阅应答 */
#define BCESFieldIndexFlowSubscribeRspList           12	/* 流订阅应答列表 */
#define BCESFieldIndexQuotSubscribeReq               13	/* 行情订阅请求 */
#define BCESFieldIndexQuotSubscribeRsp               14	/* 行情订阅应答 */
#define BCESFieldIndexQuotUnSubscribeReq             15	/* 行情退订请求 */
#define BCESFieldIndexQuotUnSubscribeRsp             16	/* 行情退订应答 */
#define BCESFieldIndexDBOperateSummary               17	/* 数据操作概要 */
#define BCESFieldIndexDBOperateList                  18	/* 数据操作列表 */
#define BCESFieldIndexTableName                      19	/* 表名 */
#define BCESFieldIndexTableOperation                 20	/* 表操作 */
#define BCESFieldIndexRspInfo                        21	/* 应答信息域 */
#define BCESFieldIndexRspNo                          22	/* 应答编码 */
#define BCESFieldIndexRspDesc                        23	/* 应答描述 */
#define BCESFieldIndexLoginReq                       24	/* 登录请求 */
#define BCESFieldIndexLoginRsp                       25	/* 登录应答 */
#define BCESFieldIndexInvestorID                     26	/* 投资者号 */
#define BCESFieldIndexInvestorPassword               27	/* 投资者密码 */
#define BCESFieldIndexLogoutReq                      28	/* 登出请求 */
#define BCESFieldIndexLogoutRsp                      29	/* 登出应答 */
#define BCESFieldIndexChangePasswordReq              30	/* 修改密码请求 */
#define BCESFieldIndexChangePasswordRsp              31	/* 修改密码应答 */
#define BCESFieldIndexInvestorOldPassword            32	/* 投资者旧密码 */
#define BCESFieldIndexInvestorNewPassword            33	/* 投资者新密码 */
#define BCESFieldIndexInputOrder                     34	/* 订单录入 */
#define BCESFieldIndexBSFlag                         35	/* 买卖标志 */
#define BCESFieldIndexInstrumentID                   36	/* 合约号 */
#define BCESFieldIndexPrice                          37	/* 价格 */
#define BCESFieldIndexQty                            38	/* 数量 */
#define BCESFieldIndexOCFlag                         39	/* 开平标志 */
#define BCESFieldIndexOrderDate                      40	/* 报单日期 */
#define BCESFieldIndexOrderID                        41	/* 订单号 */
#define BCESFieldIndexPriceType                      42	/* 价格类型 */
#define BCESFieldIndexOrderTime                      43	/* 报单时间 */
#define BCESFieldIndexQtyLeft                        44	/* 剩余数量 */
#define BCESFieldIndexModifyDate                     45	/* 修改日期 */
#define BCESFieldIndexModifyTime                     46	/* 修改时间 */
#define BCESFieldIndexOrderStatus                    47	/* 订单状态 */
#define BCESFieldIndexOrderCancelReq                 48	/* 撤单请求 */
#define BCESFieldIndexOrderCancelRsp                 49	/* 撤单应答 */
#define BCESFieldIndexInstrumentType                 50	/* 合约类型 */
#define BCESFieldIndexMatchDate                      51	/* 成交日期 */
#define BCESFieldIndexMatchTime                      52	/* 成交时间 */
#define BCESFieldIndexMatchID                        53	/* 成交号 */
#define BCESFieldIndexPosiID                         54	/* 持仓号 */
#define BCESFieldIndexTradeDate                      55	/* 交易日期 */
#define BCESFieldIndexBidPrice                       56	/* 叫买价 */
#define BCESFieldIndexAskPrice                       57	/* 叫卖价 */
#define BCESFieldIndexPreSettle                      58	/* 昨结算价 */
#define BCESFieldIndexPreOI                          59	/* 昨持仓量 */
#define BCESFieldIndexQtyTotal                       60	/* 成交量 */
#define BCESFieldIndexOI                             61	/* 持仓量 */
#define BCESFieldIndexAmount                         62	/* 成交金额 */
#define BCESFieldIndexAvgPrice                       63	/* 均价 */
#define BCESFieldIndexSettlePrice                    64	/* 结算价 */
#define BCESFieldIndexPreClose                       65	/* 昨收盘价 */
#define BCESFieldIndexOpenPrice                      66	/* 开盘价 */
#define BCESFieldIndexHighestPrice                   67	/* 最高价 */
#define BCESFieldIndexLowestPrice                    68	/* 最低价 */
#define BCESFieldIndexClosePrice                     69	/* 收盘价 */
#define BCESFieldIndexAmountTotal                    70	/* 成交额 */
#define BCESFieldIndexBidQty                         71	/* 叫买量 */
#define BCESFieldIndexAskQty                         72	/* 叫卖量 */
#define BCESFieldIndexQuotList                       73	/* 行情列表 */
#define BCESFieldIndexQuotQueryReq                   74	/* 行情查询请求 */
#define BCESFieldIndexQuot                           75	/* 行情 */
#define BCESFieldIndexInternationalQuot              76	/* 国际行情 */
#define BCESFieldIndexOrderQueryReq                  77	/* 订单查询请求 */
#define BCESFieldIndexOrder                          78	/* 订单 */
#define BCESFieldIndexTradeQueryReq                  79	/* 成交查询请求 */
#define BCESFieldIndexTrade                          80	/* 成交单 */
#define BCESFieldIndexPosiQueryReq                   81	/* 持仓查询请求 */
#define BCESFieldIndexPosi                           82	/* 持仓 */
#define BCESFieldIndexOrderList                      83	/* 订单列表 */
#define BCESFieldIndexTradeList                      84	/* 成交单列表 */
#define BCESFieldIndexPosiList                       85	/* 持仓列表 */
#define BCESFieldIndexMarketStatus                   86	/* 市场状态 */
#define BCESFieldIndexMarketStatusNty                87	/* 市场状态通知 */
#define BCESFieldIndexHisFundQueryReq                88	/* 资金查询请求 */
#define BCESFieldIndexHisPosiDetailQueryReq          89	/* 持仓明细查询请求 */
#define BCESFieldIndexFreeBalance                    90	/* 可用资金 */
#define BCESFieldIndexFundQueryReq                   91	/* 资金查询请求 */
#define BCESFieldIndexFund                           92	/* 资金 */
#define BCESFieldIndexFrozenBalance                  93	/* 冻结资金 */
#define BCESFieldIndexLastBalance                    94	/* 上日资金 */
#define BCESFieldIndexFloatBalance                   95	/* 当日出入金 */
#define BCESFieldIndexMargin                         96	/* 当日保证金 */
#define BCESFieldIndexFrozenMargin                   97	/* 当日追加保证金 */
#define BCESFieldIndexFee                            98	/* 手续费 */
#define BCESFieldIndexFeeFrozen                      99	/* 冻结手续费 */
#define BCESFieldIndexClosedPL                       100	/* 当日平仓盈亏 */
#define BCESFieldIndexFloatingPL                     101	/* 当日总盈亏 */
#define BCESFieldIndexProfitLoss                     102	/* 当日交易手续费 */
#define BCESFieldIndexTotalPL                        103	/* 当日风险手续费 */
#define BCESFieldIndexInstrumentList                 104	/* 合约列表 */
#define BCESFieldIndexInstrumentQueryReq             105	/* 合约查询请求 */
#define BCESFieldIndexInstrument                     106	/* 合约 */
#define BCESFieldIndexMarketStatusDesc               107	/* 市场状态描述 */
#define BCESFieldIndexVarietyID                      108	/* 品种代码 */
#define BCESFieldIndexInstrumentStatus               109	/* 合约状态 */
#define BCESFieldIndexTradeUnit                      110	/* 交易单位 */
#define BCESFieldIndexPriceUnit                      111	/* 报价单位 */
#define BCESFieldIndexDailyPriceLimit                112	/* 涨跌停限制 */
#define BCESFieldIndexFeeType                        113	/* 手续费类型 */
#define BCESFieldIndexFeeRate                        114	/* 手续费率 */
#define BCESFieldIndexPriceScale                     115	/* 报价精度 */
#define BCESFieldIndexMarginRate                     116	/* 保证金率 */
#define BCESFieldIndexHighLimit                      117	/* 涨停板价 */
#define BCESFieldIndexLowLimit                       118	/* 跌停板价 */
#define BCESFieldIndexBuyQtyFrozen                   119	/* 买冻结持仓量 */
#define BCESFieldIndexSellQtyFrozen                  120	/* 卖冻结持仓量 */
#define BCESFieldIndexPosiDetailQueryReq             121	/* 持仓明细查询请求 */
#define BCESFieldIndexPosiDetail                     122	/* 持仓明细 */
#define BCESFieldIndexPosiDetailList                 123	/* 持仓明细列表 */
#define BCESFieldIndexInstrumentName                 124	/* 合约名称 */
#define BCESFieldIndexMinMovement                    125	/* 价格变动限制 */
#define BCESFieldIndexPriceCoefficient               126	/* 价格变动限制 */
#define BCESFieldIndexBuyQty                         127	/* 买持仓量 */
#define BCESFieldIndexBuyPrice                       128	/* 买持仓均价 */
#define BCESFieldIndexSellQty                        129	/* 卖持仓量 */
#define BCESFieldIndexSellPrice                      130	/* 卖持仓均价 */
#define BCESFieldIndexMinDataQueryReq                131	/* 分线查询请求 */
#define BCESFieldIndexMinData                        132	/* 分线 */
#define BCESFieldIndexDayDataQueryReq                133	/* 日线查询请求 */
#define BCESFieldIndexDayData                        134	/* 日线 */
#define BCESFieldIndexMinDataList                    135	/* 分线列表 */
#define BCESFieldIndexDayDataList                    136	/* 日线列表 */
#define BCESFieldIndexDateTimeFrom                   137	/* 起始日期时间 */
#define BCESFieldIndexDateTimeTo                     138	/* 结束日期时间 */
#define BCESFieldIndexDateFrom                       139	/* 起始日期 */
#define BCESFieldIndexDateTo                         140	/* 结束日期 */
#define BCESFieldIndexDate                           141	/* 日期 */
#define BCESFieldIndexTime                           142	/* 时间 */
#define BCESFieldIndexTimeFrom                       143	/* 起始时间 */
#define BCESFieldIndexTimeTo                         144	/* 结束时间 */
#define BCESFieldIndexDateTime                       145	/* 日期时间 */
#define BCESFieldIndexLimitedFilledPoints            146	/* 最小成交滑点 */
#define BCESFieldIndexLimitedOrderPoints             147	/* 最小报价点差 */
#define BCESFieldIndexLimitedStopPoints              148	/* 最小止赢止损点差 */
#define BCESFieldIndexProfitStopPrice                149	/* 止赢价 */
#define BCESFieldIndexLossStopPrice                  150	/* 止损价 */
#define BCESFieldIndexProfitLossStopSetReq           151	/* 止赢止损设置请求 */
#define BCESFieldIndexProfitLossStopSetRsp           152	/* 止赢止损设置应答 */
#define BCESFieldIndexFilledPoints                   153	/* 成交滑点 */
#define BCESFieldIndexCreateDate                     154	/* 发起日期 */
#define BCESFieldIndexCreateTime                     155	/* 发起时间 */
#define BCESFieldIndexPublishDate                    156	/* 发布日期 */
#define BCESFieldIndexPublishTime                    157	/* 发布时间 */
#define BCESFieldIndexBulletinQueryReq               158	/* 查询公告请求 */
#define BCESFieldIndexBulletinList                   159	/* 公告列表 */
#define BCESFieldIndexBulletin                       160	/* 公告 */
#define BCESFieldIndexPublishUserID                  161	/* 发布人 */
#define BCESFieldIndexBulletinID                     162	/* 公告编号 */
#define BCESFieldIndexTitle                          163	/* 标题 */
#define BCESFieldIndexContent                        164	/* 内容 */
#define BCESFieldIndexNoticeID                       165	/* 通知编号 */
#define BCESFieldIndexPublishMethod                  166	/* 发布方式 */
#define BCESFieldIndexNoticeList                     167	/* 通知列表 */
#define BCESFieldIndexNotice                         168	/* 通知 */
#define BCESFieldIndexNoticeQueryReq                 169	/* 查询通知请求 */
#define BCESFieldIndexFundIODirection                170	/* 出入金方向 */
#define BCESFieldIndexFundIOStatus                   171	/* 出入金状态 */
#define BCESFieldIndexCompleteDate                   172	/* 完成日期 */
#define BCESFieldIndexCompleteTime                   173	/* 完成时间 */
#define BCESFieldIndexFundIOSeqno                    174	/* 出入金流水号 */
#define BCESFieldIndexFundIOStatusDesc               175	/* 出入金状态描述 */
#define BCESFieldIndexElectronicFundIOReq            176	/* 电子出入金请求 */
#define BCESFieldIndexElectronicFundIORsp            177	/* 电子出入金响应 */
#define BCESFieldIndexPayURL                         178	/* 网址 */
#define BCESFieldIndexPayDirection                   179	/* 支付方向 */
#define BCESFieldIndexElectronicFundIONty            180	/* 电子出入金通知 */
#define BCESFieldIndexFundIOMethod                   181	/* 出入金方式 */
#define BCESFieldIndexFundIODetail                   182	/* 出入金明细 */
#define BCESFieldIndexFundIODetailList               183	/* 出入金明细列表 */
#define BCESFieldIndexFundIODetailQueryReq           184	/* 出入金明细查询请求 */
#define BCESFieldIndexReceiveBankID                  185	/* 收款行号 */
#define BCESFieldIndexReceiveAccountID               186	/* 收款帐号 */
#define BCESFieldIndexReceiveAccountName             187	/* 收款户名 */
#define BCESFieldIndexReport                         188	/* 报表 */
#define BCESFieldIndexReportList                     189	/* 报表列表 */
#define BCESFieldIndexReportQueryReq                 190	/* 报表查询请求 */
#define BCESFieldIndexReportData                     191	/* 报表内容 */
#define BCESFieldIndexHisOrderQueryReq               192	/* 历史订单查询请求 */
#define BCESFieldIndexHisTradeQueryReq               193	/* 历史成交查询请求 */
#define BCESFieldIndexHisBulletinQueryReq            194	/* 查询历史公告请求 */
#define BCESFieldIndexHisNoticeQueryReq              195	/* 查询历史通知请求 */
#define BCESFieldIndexInvestorRanking                196	/* 投资者排名 */
#define BCESFieldIndexInvestorRankingList            197	/* 投资者排名列表 */
#define BCESFieldIndexInvestorRankingQueryReq        198	/* 投资者排名查询请求 */
#define BCESFieldIndexInvestorRankingQueryRsp        199	/* 投资者排名查询应答 */
#define BCESFieldIndexRankingNum                     200	/* 排名 */
#define BCESFieldIndexInvestorName                   201	/* 投资者名称 */
#define BCESFieldIndexTradeSettings                  202	/* 交易设置 */
#define BCESFieldIndexTradeSettingsList              203	/* 交易设置列表 */
#define BCESFieldIndexTradeSettingsAddReq            204	/* 交易设置增加请求 */
#define BCESFieldIndexTradeSettingsAddRsp            205	/* 交易设置增加应答 */
#define BCESFieldIndexTradeSettingsModifyReq         206	/* 交易设置修改请求 */
#define BCESFieldIndexTradeSettingsModifyRsp         207	/* 交易设置修改应答 */
#define BCESFieldIndexTradeSettingsDeleteReq         208	/* 交易设置删除请求 */
#define BCESFieldIndexTradeSettingsDeleteRsp         209	/* 交易设置删除应答 */
#define BCESFieldIndexTradeSettingsQueryReq          210	/* 交易设置查询请求 */
#define BCESFieldIndexTradeAction                    211	/* 交易行为 */
#define BCESFieldIndexAddress                        212	/* 产地 */
#define BCESFieldIndexWareHouse                      213	/* 仓库 */
#define BCESFieldIndexCurrency                       214	/* 币种 */
#define BCESFieldIndexAccountBind                    215	/* 签约信息 */
#define BCESFieldIndexAccountBindList                216	/* 签约信息列表 */
#define BCESFieldIndexAccountBindQueryReq            217	/* 签约信息查询请求 */
#define BCESFieldIndexAccountBindReq                 218	/* 签约请求 */
#define BCESFieldIndexAccountBindRsp                 219	/* 签约应答 */
#define BCESFieldIndexCloseDate                      220	/* 平仓日期 */
#define BCESFieldIndexCloseTime                      221	/* 平仓时间 */
#define BCESFieldIndexOverNightFee                   222	/* 隔夜费 */
#define BCESFieldIndexAgentName                      223	/* 代理商名称 */
#define BCESFieldIndexInAmount                       224	/* 入金金额 */
#define BCESFieldIndexOutAmount                      225	/* 出金金额 */
#define BCESFieldIndexFundList                       226	/* 资金列表 */
#define BCESFieldIndexSysName                        227	/* 系统名称 */
#define BCESFieldIndexErrNetTradeSec                 228	/* 网络故障成交延迟 */
#define BCESFieldIndexErrNetRemindSec                229	/* 网络故障提醒延迟 */
#define BCESFieldIndexErrNetRemindTxt                230	/* 网络故障提醒信息 */
#define BCESFieldIndexErrSeverTradePort              231	/* 服务器故障成交点差 */
#define BCESFieldIndexErrSeverRemindPort             232	/* 服务器故障提醒点差 */
#define BCESFieldIndexErrSeverRemindTxt              233	/* 服务器故障提醒信息 */
#define BCESFieldIndexTestSettingsModifyReq          234	/* 测试设置修改请求 */
#define BCESFieldIndexTestSettingsModifyRsp          235	/* 测试设置修改应答 */
#define BCESFieldIndexMarginRateType                 236	/* 保证金率类型 */
#define BCESFieldIndexOverNightFeeType               237	/* 隔夜费类型 */
#define BCESFieldIndexFeeFlag                        238	/* 收费类型 */
#define BCESFieldIndexPriceMultiply                  239	/* 报价乘数 */
#define BCESFieldIndexEachQtyLimt                    240	/* 每笔持仓限量 */
#define BCESFieldIndexTotalQtyLimt                   241	/* 总持仓限量 */
#define BCESFieldIndexUserID                         242	/* 操作员号 */
#define BCESFieldIndexBidPrice2                      243	/* 叫买价2 */
#define BCESFieldIndexAskPrice2                      244	/* 叫卖价2 */
#define BCESFieldIndexBidQty2                        245	/* 叫买量2 */
#define BCESFieldIndexAskQty2                        246	/* 叫卖量2 */
#define BCESFieldIndexBidPrice3                      247	/* 叫买价3 */
#define BCESFieldIndexAskPrice3                      248	/* 叫卖价3 */
#define BCESFieldIndexBidQty3                        249	/* 叫买量3 */
#define BCESFieldIndexAskQty3                        250	/* 叫卖量3 */
#define BCESFieldIndexBidPrice4                      251	/* 叫买价4 */
#define BCESFieldIndexAskPrice4                      252	/* 叫卖价4 */
#define BCESFieldIndexBidQty4                        253	/* 叫买量4 */
#define BCESFieldIndexAskQty4                        254	/* 叫卖量4 */
#define BCESFieldIndexBidPrice5                      255	/* 叫买价5 */
#define BCESFieldIndexAskPrice5                      256	/* 叫卖价5 */
#define BCESFieldIndexBidQty5                        257	/* 叫买量5 */
#define BCESFieldIndexAskQty5                        258	/* 叫卖量5 */
#define BCESFieldIndexSysMode                        259	/* 系统模式 */
#define BCESFieldIndexQtyFrozen                      260	/* 冻结持仓量 */
#define BCESFieldIndexBidPrice6                      261	/* 叫买价6 */
#define BCESFieldIndexAskPrice6                      262	/* 叫卖价6 */
#define BCESFieldIndexBidQty6                        263	/* 叫买量6 */
#define BCESFieldIndexAskQty6                        264	/* 叫卖量6 */
#define BCESFieldIndexBidPrice7                      265	/* 叫买价7 */
#define BCESFieldIndexAskPrice7                      266	/* 叫卖价7 */
#define BCESFieldIndexBidQty7                        267	/* 叫买量7 */
#define BCESFieldIndexAskQty7                        268	/* 叫卖量7 */
#define BCESFieldIndexBidPrice8                      269	/* 叫买价8 */
#define BCESFieldIndexAskPrice8                      270	/* 叫卖价8 */
#define BCESFieldIndexBidQty8                        271	/* 叫买量8 */
#define BCESFieldIndexAskQty8                        272	/* 叫卖量8 */
#define BCESFieldIndexBidPrice9                      273	/* 叫买价9 */
#define BCESFieldIndexAskPrice9                      274	/* 叫卖价9 */
#define BCESFieldIndexBidQty9                        275	/* 叫买量9 */
#define BCESFieldIndexAskQty9                        276	/* 叫卖量9 */
#define BCESFieldIndexBidPrice10                     277	/* 叫买价10 */
#define BCESFieldIndexAskPrice10                     278	/* 叫卖价10 */
#define BCESFieldIndexBidQty10                       279	/* 叫买量10 */
#define BCESFieldIndexAskQty10                       280	/* 叫卖量10 */
#define BCESFieldIndexIP                             281	/* IP地址 */
#define BCESFieldIndexTopInvestorQueryReq            282	/* 挂单量排名查询请求 */
#define BCESFieldIndexTopInvestor                    283	/* 挂单量排名 */
#define BCESFieldIndexTopInvestorList                284	/* 挂单量排名列表 */
#define BCESFieldIndexInvestorQuotQueryReq           285	/* 投资者挂单查询请求 */
#define BCESFieldIndexInvestorQuot                   286	/* 挂单量排名 */
#define BCESFieldIndexInvestorQuotList               287	/* 挂单量排名列表 */
#define BCESFieldIndexRankingInvestorID              288	/* 排名投资者号 */
#define BCESFieldIndexConditionType                  289	/* 条件类型 */
#define BCESFieldIndexConditionMethod                290	/* 条件方法 */
#define BCESFieldIndexConditionPrice                 291	/* 条件价格 */
#define BCESFieldIndexGoodsName                      292	/* 品种大类 */
#define BCESFieldIndexTradeTime                      293	/* 交易时间 */
#define BCESFieldIndexTimeBegin                      294	/* 开始时间 */
#define BCESFieldIndexTimeEnd                        295	/* 结束时间 */
#define BCESFieldIndexReceiveBranchName              296	/* 支行名称 */
#define BCESFieldIndexReceiveProvice                 297	/* 开户省份 */
#define BCESFieldIndexReceiveCity                    298	/* 开户市 */
#define BCESFieldIndexAccountBindStatus              299	/* 签约状态 */
#define BCESFieldIndexAccountBindURL                 300	/* 网址 */
#define BCESFieldIndexAccountBindStatusDesc          301	/* 签约状态描述 */
#define BCESFieldIndexProductType                    302	/* 产品编号 */
#define BCESFieldIndexProductVersion                 303	/* 产品版本号 */
#define BCESFieldIndexDeliveryDemand                 304	/* 交收交割需求 */
#define BCESFieldIndexCompanyName                    305	/* 企业名称 */
#define BCESFieldIndexLiaisonName                    306	/* 联系人名称 */
#define BCESFieldIndexLiaisonNumber                  307	/* 联系电话 */
#define BCESFieldIndexLiaisonAddress                 308	/* 联系地址 */
#define BCESFieldIndexGuaranteedQty                  309	/* 保守数量 */
#define BCESFieldIndexGeneralQty                     310	/* 一般数量 */
#define BCESFieldIndexRiskQty                        311	/* 风险数量 */
#define BCESFieldIndexBankName                       312	/* 银行名称 */
#define BCESFieldIndexInvoiceTitle                   313	/* 发票抬头 */
#define BCESFieldIndexDeliveryDemandID               314	/* 交收交割编号 */
#define BCESFieldIndexDeliveryStatus                 315	/* 交收交割状态 */
#define BCESFieldIndexDeliveryDemandQueryReq         316	/* 交收交割需求请求 */
#define BCESFieldIndexDeliveryDemandQueryRsp         317	/* 交收交割需求应答 */
#define BCESFieldIndexInvoiceFlag                    318	/* 发票标识 */
#define BCESFieldIndexInvoiceType                    319	/* 发票类型 */
#define BCESFieldIndexCredentialType                 320	/* 证件类型 */
#define BCESFieldIndexCredentialNo                   321	/* 证件号 */
#define BCESFieldIndexEmail                          322	/* 电子邮箱 */
#define BCESFieldIndexPostCode                       323	/* 邮编 */
#define BCESFieldIndexBankAccountID                  324	/* 银行帐号 */
#define BCESFieldIndexBankNameAccountID              325	/* 银行户名及账号 */
#define BCESFieldIndexDeliveryApplyID                326	/* 交收交割申请编号 */
#define BCESFieldIndexDeliveryAddress                327	/* 交收交割地址 */
#define BCESFieldIndexApplyDate                      328	/* 申请日期 */
#define BCESFieldIndexVerifedDate                    329	/* 确认日期 */
#define BCESFieldIndexCompletedDate                  330	/* 成交日期 */
#define BCESFieldIndexCompanyAddress                 331	/* 公司地址 */
#define BCESFieldIndexTaxNo                          332	/* 税务登记号 */
#define BCESFieldIndexInvoice                        333	/* 发票 */
#define BCESFieldIndexDeliveryApplyAddReq            334	/* 交收交割申请增加请求 */
#define BCESFieldIndexDeliveryApplyAddRsp            335	/* 交收交割申请增加应答 */
#define BCESFieldIndexDeliveryApplyModifyReq         336	/* 交收交割申请修改请求 */
#define BCESFieldIndexDeliveryApplyModifyRsp         337	/* 交收交割申请修改应答 */
#define BCESFieldIndexDeliveryApply                  338	/* 交收交割申请 */
#define BCESFieldIndexDeliveryApplyQueryReq          339	/* 交收交割申请查询请求 */
#define BCESFieldIndexDeliveryApplyQueryRsp          340	/* 交收交割申请查询应答 */
#define BCESFieldIndexDeliveryApplyList              341	/* 交收交割申请列表 */
#define BCESFieldIndexDeliveryApplyDeleteReq         342	/* 交收交割申请删除请求 */
#define BCESFieldIndexDeliveryApplyDeleteRsp         343	/* 交收交割申请删除应答 */
#define BCESFieldIndexPayServerType                  344	/* 支付服务类型 */
#define BCESFieldIndexTradeDetailDataQueryReq        345	/* 成交明细查询请求 */
#define BCESFieldIndexCompanyNumber                  346	/* 公司电话 */
#define BCESFieldIndexTradeDetailDataList            347	/* 成交明细列表 */
#define BCESFieldIndexAdviserID                      348	/* 顾问号 */
#define BCESFieldIndexQuestionContent                349	/* 提问内容 */
#define BCESFieldIndexQuestionDate                   350	/* 提问日期 */
#define BCESFieldIndexQuestionTime                   351	/* 提问时间 */
#define BCESFieldIndexAnswerContent                  352	/* 回答内容 */
#define BCESFieldIndexAnswerDate                     353	/* 回答日期 */
#define BCESFieldIndexAnswerTime                     354	/* 回答时间 */
#define BCESFieldIndexQuestionID                     355	/* 提问编号 */
#define BCESFieldIndexQuesAnswFlag                   356	/* 提问/回答标志 */
#define BCESFieldIndexQuesAnswContent                357	/* 提问/回答内容 */
#define BCESFieldIndexQuesAnswDate                   358	/* 提问/回答日期 */
#define BCESFieldIndexQuesAnswTime                   359	/* 提问/回答时间 */
#define BCESFieldIndexInvestorAdviserFlag            360	/* 投资者顾问标志 */
#define BCESFieldIndexQuotAdviserQuesAnswReq         361	/* 行情顾问提问/回答请求 */
#define BCESFieldIndexQuotAdviserQuesAnswRsp         362	/* 行情顾问提问/回答应答 */
#define BCESFieldIndexQuotAdviserQuesHisQueryReq     363	/* 行情顾问提问历史查询请求 */
#define BCESFieldIndexQuotAdviserQuesHisQueryRsp     364	/* 行情顾问提问历史查询应答 */
#define BCESFieldIndexQuotAdviserQuesHisList         365	/* 行情顾问提问历史查询列表 */
#define BCESFieldIndexQuotAdviserQuesQueryReq        366	/* 行情顾问提问查询请求 */
#define BCESFieldIndexQuotAdviserQuesQueryRsp        367	/* 行情顾问提问查询应答 */
#define BCESFieldIndexQuotAdviserQuesQuerylist       368	/* 行情顾问提问查询列表 */
#define BCESFieldIndexPlateName                      369	/* 板块 */
#define BCESFieldIndexPreBuyQty                      370	/* 昨买持仓量 */
#define BCESFieldIndexPreSellQty                     371	/* 昨卖持仓量 */
#define BCESFieldIndexTodayBuyQty                    372	/* 今买持仓量 */
#define BCESFieldIndexTodaySellQty                   373	/* 今卖持仓量 */
#define BCESFieldIndexTodayBuyQtyFrozen              374	/* 今买冻结持仓量 */
#define BCESFieldIndexTodaySellQtyFrozen             375	/* 今卖冻结持仓量 */
#define BCESFieldIndexExchangeID                     376	/* 交易所号 */
#define BCESFieldIndexSessionID                      377	/* 会话编号 */
#define BCESFieldIndexOrderRef                       378	/* 报单引用 */
#define BCESFieldIndexCreatePrice                    379	/* 建仓价 */
#define BCESFieldIndexHistoryClosedPL                380	/* 历史平仓盈亏 */
#define BCESFieldIndexInvestorRole                   381	/* 投资者角色 */
#define BCESFieldIndexInvestorFlag                   382	/* 投资者标志 */
#define BCESFieldIndexPaySeqno                       383	/* 支付流水号 */
#define BCESFieldIndexPreQtyLeft                     384	/* 上日剩余数量 */
#define BCESFieldIndexCreateTradeDate                385	/* 建仓交易日期 */
#define BCESFieldIndexClosedTradeDate                386	/* 平仓交易日期 */
#define BCESFieldIndexClosedOrderID                  387	/* 平仓订单号 */
#define BCESFieldIndexClosedMatchID                  388	/* 平仓成交号 */
#define BCESFieldIndexAccountID                      389	/* 报单账号 */
#define BCESFieldIndexOrderStatusDesc                390	/* 状态说明 */
#define BCESFieldIndexOrderSysID                     391	/* 交易所报单编号 */
#define BCESFieldIndexCTPSessionID                   392	/* 会话编号 */
#define BCESFieldIndexCTPFrontID                     393	/* 前置编号 */
#define BCESFieldIndexCTPOrderRef                    394	/* 报单引用 */
#define BCESFieldIndexCloseFeeRate                   395	/* 平仓手续费率 */
#define BCESFieldIndexCloseTodayFeeRate              396	/* 平今仓手续费率 */
#define BCESFieldIndexStampRate                      397	/* 印花税费率 */
#define BCESFieldIndexKLineType                      398	/* K线类型 */
#define BCESFieldIndexKLineQueryReq                  399	/* K线查询请求 */
#define BCESFieldIndexKLineList                      400	/* K线列表 */
#define BCESFieldIndexTickLineQueryReq               401	/* Tick线查询请求 */
#define BCESFieldIndexTickLineList                   402	/* Tick线列表 */
#define BCESFieldIndexBarFrom                        403	/* 起始Bar */
#define BCESFieldIndexBarCount                       404	/* Bar数量 */
#define BCESFieldIndexAccountList                    405	/* 报单账户列表 */
#define BCESFieldIndexAccount                        406	/* 报单账户 */
#define BCESFieldIndexExchangeList                   407	/* 交易所列表 */
#define BCESFieldIndexExchange                       408	/* 交易所 */
#define BCESFieldIndexPreClosedPL                    409	/* 上日平仓盈亏 */
#define BCESFieldIndexPreClosePrice                  410	/* 上日平仓价 */

/* Field Define */

/* 报文头 */
class CBCESFieldHead:public CBMLField
{
public:
	CBCESFieldHead(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHead;
		
	}
	
};
/* 报文体 */
class CBCESFieldBody:public CBMLField
{
public:
	CBCESFieldBody(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBody;
		
	}
	
};
/* 流编号 */
class CBCESFieldFlowID:public CBMLField
{
public:
	CBCESFieldFlowID(){
		m_dat=(void*)&FlowID;
		m_siz=sizeof(FlowID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFlowID;
		memset(&FlowID,0x00,sizeof(FlowID));	/* 流编号 */
	}
	BCESFieldTypeFlowID FlowID;	/* 流编号 */
};
/* 请求编号 */
class CBCESFieldRequestID:public CBMLField
{
public:
	CBCESFieldRequestID(){
		m_dat=(void*)&RequestID;
		m_siz=sizeof(RequestID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRequestID;
		memset(&RequestID,0x00,sizeof(RequestID));	/* 请求编号 */
	}
	BCESFieldTypeRequestID RequestID;	/* 请求编号 */
};
/* 结束标记 */
class CBCESFieldEndFlag:public CBMLField
{
public:
	CBCESFieldEndFlag(){
		m_dat=(void*)&EndFlag;
		m_siz=sizeof(EndFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexEndFlag;
		memset(&EndFlag,0x00,sizeof(EndFlag));	/* 结束标记 */
	}
	BCESFieldTypeEndFlag EndFlag;	/* 结束标记 */
};
/* 报文编号 */
class CBCESFieldPkgNo:public CBMLField
{
public:
	CBCESFieldPkgNo(){
		m_dat=(void*)&PkgNo;
		m_siz=sizeof(PkgNo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPkgNo;
		memset(&PkgNo,0x00,sizeof(PkgNo));	/* 报文编号 */
	}
	BCESFieldTypePkgNo PkgNo;	/* 报文编号 */
};
/* 指令编码 */
class CBCESFieldServiceNo:public CBMLField
{
public:
	CBCESFieldServiceNo(){
		m_dat=(void*)&ServiceNo;
		m_siz=sizeof(ServiceNo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexServiceNo;
		memset(&ServiceNo,0x00,sizeof(ServiceNo));	/* 指令编码 */
	}
	BCESFieldTypeServiceNo ServiceNo;	/* 指令编码 */
};
/* API报文头 */
class CBCESFieldApiHead:public CBMLField
{
public:
	CBCESFieldApiHead(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexApiHead;
		
	}
	
};
/* API报文体 */
class CBCESFieldApiBody:public CBMLField
{
public:
	CBCESFieldApiBody(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexApiBody;
		
	}
	
};
/* 流订阅请求 */
class CBCESFieldFlowSubscribeReq:public CBMLField
{
public:
	CBCESFieldFlowSubscribeReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFlowSubscribeReq;
		
	}
	
};
/* 流订阅请求列表 */
class CBCESFieldFlowSubscribeReqList:public CBMLField
{
public:
	CBCESFieldFlowSubscribeReqList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFlowSubscribeReqList;
		
	}
	
};
/* 流订阅应答 */
class CBCESFieldFlowSubscribeRsp:public CBMLField
{
public:
	CBCESFieldFlowSubscribeRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFlowSubscribeRsp;
		
	}
	
};
/* 流订阅应答列表 */
class CBCESFieldFlowSubscribeRspList:public CBMLField
{
public:
	CBCESFieldFlowSubscribeRspList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFlowSubscribeRspList;
		
	}
	
};
/* 行情订阅请求 */
class CBCESFieldQuotSubscribeReq:public CBMLField
{
public:
	CBCESFieldQuotSubscribeReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotSubscribeReq;
		
	}
	
};
/* 行情订阅应答 */
class CBCESFieldQuotSubscribeRsp:public CBMLField
{
public:
	CBCESFieldQuotSubscribeRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotSubscribeRsp;
		
	}
	
};
/* 行情退订请求 */
class CBCESFieldQuotUnSubscribeReq:public CBMLField
{
public:
	CBCESFieldQuotUnSubscribeReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotUnSubscribeReq;
		
	}
	
};
/* 行情退订应答 */
class CBCESFieldQuotUnSubscribeRsp:public CBMLField
{
public:
	CBCESFieldQuotUnSubscribeRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotUnSubscribeRsp;
		
	}
	
};
/* 数据操作概要 */
class CBCESFieldDBOperateSummary:public CBMLField
{
public:
	CBCESFieldDBOperateSummary(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDBOperateSummary;
		
	}
	
};
/* 数据操作列表 */
class CBCESFieldDBOperateList:public CBMLField
{
public:
	CBCESFieldDBOperateList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDBOperateList;
		
	}
	
};
/* 表名 */
class CBCESFieldTableName:public CBMLField
{
public:
	CBCESFieldTableName(){
		m_dat=(void*)TableName;
		m_siz=sizeof(TableName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTableName;
		memset(TableName,0x00,sizeof(TableName));	/* 表名 */
	}
	BCESFieldTypeTableName TableName;	/* 表名 */
};
/* 表操作 */
class CBCESFieldTableOperation:public CBMLField
{
public:
	CBCESFieldTableOperation(){
		m_dat=(void*)&TableOperation;
		m_siz=sizeof(TableOperation);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTableOperation;
		memset(&TableOperation,0x00,sizeof(TableOperation));	/* 表操作 */
	}
	BCESFieldTypeTableOperation TableOperation;	/* 表操作 */
};
/* 应答信息域 */
class CBCESFieldRspInfo:public CBMLField
{
public:
	CBCESFieldRspInfo(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRspInfo;
		
	}
	
};
/* 应答编码 */
class CBCESFieldRspNo:public CBMLField
{
public:
	CBCESFieldRspNo(){
		m_dat=(void*)&RspNo;
		m_siz=sizeof(RspNo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRspNo;
		memset(&RspNo,0x00,sizeof(RspNo));	/* 应答编码 */
	}
	BCESFieldTypeRspNo RspNo;	/* 应答编码 */
};
/* 应答描述 */
class CBCESFieldRspDesc:public CBMLField
{
public:
	CBCESFieldRspDesc(){
		m_dat=(void*)RspDesc;
		m_siz=sizeof(RspDesc);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRspDesc;
		memset(RspDesc,0x00,sizeof(RspDesc));	/* 应答描述 */
	}
	BCESFieldTypeRspDesc RspDesc;	/* 应答描述 */
};
/* 登录请求 */
class CBCESFieldLoginReq:public CBMLField
{
public:
	CBCESFieldLoginReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLoginReq;
		
	}
	
};
/* 登录应答 */
class CBCESFieldLoginRsp:public CBMLField
{
public:
	CBCESFieldLoginRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLoginRsp;
		
	}
	
};
/* 投资者号 */
class CBCESFieldInvestorID:public CBMLField
{
public:
	CBCESFieldInvestorID(){
		m_dat=(void*)InvestorID;
		m_siz=sizeof(InvestorID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorID;
		memset(InvestorID,0x00,sizeof(InvestorID));	/* 投资者号 */
	}
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};
/* 投资者密码 */
class CBCESFieldInvestorPassword:public CBMLField
{
public:
	CBCESFieldInvestorPassword(){
		m_dat=(void*)InvestorPassword;
		m_siz=sizeof(InvestorPassword);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorPassword;
		memset(InvestorPassword,0x00,sizeof(InvestorPassword));	/* 投资者密码 */
	}
	BCESFieldTypePassword InvestorPassword;	/* 投资者密码 */
};
/* 登出请求 */
class CBCESFieldLogoutReq:public CBMLField
{
public:
	CBCESFieldLogoutReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLogoutReq;
		
	}
	
};
/* 登出应答 */
class CBCESFieldLogoutRsp:public CBMLField
{
public:
	CBCESFieldLogoutRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLogoutRsp;
		
	}
	
};
/* 修改密码请求 */
class CBCESFieldChangePasswordReq:public CBMLField
{
public:
	CBCESFieldChangePasswordReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexChangePasswordReq;
		
	}
	
};
/* 修改密码应答 */
class CBCESFieldChangePasswordRsp:public CBMLField
{
public:
	CBCESFieldChangePasswordRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexChangePasswordRsp;
		
	}
	
};
/* 投资者旧密码 */
class CBCESFieldInvestorOldPassword:public CBMLField
{
public:
	CBCESFieldInvestorOldPassword(){
		m_dat=(void*)InvestorOldPassword;
		m_siz=sizeof(InvestorOldPassword);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorOldPassword;
		memset(InvestorOldPassword,0x00,sizeof(InvestorOldPassword));	/* 投资者旧密码 */
	}
	BCESFieldTypePassword InvestorOldPassword;	/* 投资者旧密码 */
};
/* 投资者新密码 */
class CBCESFieldInvestorNewPassword:public CBMLField
{
public:
	CBCESFieldInvestorNewPassword(){
		m_dat=(void*)InvestorNewPassword;
		m_siz=sizeof(InvestorNewPassword);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorNewPassword;
		memset(InvestorNewPassword,0x00,sizeof(InvestorNewPassword));	/* 投资者新密码 */
	}
	BCESFieldTypePassword InvestorNewPassword;	/* 投资者新密码 */
};
/* 订单录入 */
class CBCESFieldInputOrder:public CBMLField
{
public:
	CBCESFieldInputOrder(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInputOrder;
		
	}
	
};
/* 买卖标志 */
class CBCESFieldBSFlag:public CBMLField
{
public:
	CBCESFieldBSFlag(){
		m_dat=(void*)&BSFlag;
		m_siz=sizeof(BSFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBSFlag;
		memset(&BSFlag,0x00,sizeof(BSFlag));	/* 买卖标志 */
	}
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};
/* 合约号 */
class CBCESFieldInstrumentID:public CBMLField
{
public:
	CBCESFieldInstrumentID(){
		m_dat=(void*)InstrumentID;
		m_siz=sizeof(InstrumentID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrumentID;
		memset(InstrumentID,0x00,sizeof(InstrumentID));	/* 合约号 */
	}
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};
/* 价格 */
class CBCESFieldPrice:public CBMLField
{
public:
	CBCESFieldPrice(){
		m_dat=(void*)&Price;
		m_siz=sizeof(Price);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPrice;
		memset(&Price,0x00,sizeof(Price));	/* 价格 */
	}
	BCESFieldTypePrice Price;	/* 价格 */
};
/* 数量 */
class CBCESFieldQty:public CBMLField
{
public:
	CBCESFieldQty(){
		m_dat=(void*)&Qty;
		m_siz=sizeof(Qty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQty;
		memset(&Qty,0x00,sizeof(Qty));	/* 数量 */
	}
	BCESFieldTypeQty Qty;	/* 数量 */
};
/* 开平标志 */
class CBCESFieldOCFlag:public CBMLField
{
public:
	CBCESFieldOCFlag(){
		m_dat=(void*)&OCFlag;
		m_siz=sizeof(OCFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOCFlag;
		memset(&OCFlag,0x00,sizeof(OCFlag));	/* 开平标志 */
	}
	BCESFieldTypeFlag OCFlag;	/* 开平标志 */
};
/* 报单日期 */
class CBCESFieldOrderDate:public CBMLField
{
public:
	CBCESFieldOrderDate(){
		m_dat=(void*)OrderDate;
		m_siz=sizeof(OrderDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderDate;
		memset(OrderDate,0x00,sizeof(OrderDate));	/* 报单日期 */
	}
	BCESFieldTypeDate OrderDate;	/* 报单日期 */
};
/* 订单号 */
class CBCESFieldOrderID:public CBMLField
{
public:
	CBCESFieldOrderID(){
		m_dat=(void*)OrderID;
		m_siz=sizeof(OrderID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderID;
		memset(OrderID,0x00,sizeof(OrderID));	/* 订单号 */
	}
	BCESFieldTypeOrderID OrderID;	/* 订单号 */
};
/* 价格类型 */
class CBCESFieldPriceType:public CBMLField
{
public:
	CBCESFieldPriceType(){
		m_dat=(void*)&PriceType;
		m_siz=sizeof(PriceType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPriceType;
		memset(&PriceType,0x00,sizeof(PriceType));	/* 价格类型 */
	}
	BCESFieldTypeFlag PriceType;	/* 价格类型 */
};
/* 报单时间 */
class CBCESFieldOrderTime:public CBMLField
{
public:
	CBCESFieldOrderTime(){
		m_dat=(void*)OrderTime;
		m_siz=sizeof(OrderTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderTime;
		memset(OrderTime,0x00,sizeof(OrderTime));	/* 报单时间 */
	}
	BCESFieldTypeTime OrderTime;	/* 报单时间 */
};
/* 剩余数量 */
class CBCESFieldQtyLeft:public CBMLField
{
public:
	CBCESFieldQtyLeft(){
		m_dat=(void*)&QtyLeft;
		m_siz=sizeof(QtyLeft);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQtyLeft;
		memset(&QtyLeft,0x00,sizeof(QtyLeft));	/* 剩余数量 */
	}
	BCESFieldTypeQty QtyLeft;	/* 剩余数量 */
};
/* 修改日期 */
class CBCESFieldModifyDate:public CBMLField
{
public:
	CBCESFieldModifyDate(){
		m_dat=(void*)ModifyDate;
		m_siz=sizeof(ModifyDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexModifyDate;
		memset(ModifyDate,0x00,sizeof(ModifyDate));	/* 修改日期 */
	}
	BCESFieldTypeDate ModifyDate;	/* 修改日期 */
};
/* 修改时间 */
class CBCESFieldModifyTime:public CBMLField
{
public:
	CBCESFieldModifyTime(){
		m_dat=(void*)ModifyTime;
		m_siz=sizeof(ModifyTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexModifyTime;
		memset(ModifyTime,0x00,sizeof(ModifyTime));	/* 修改时间 */
	}
	BCESFieldTypeTime ModifyTime;	/* 修改时间 */
};
/* 订单状态 */
class CBCESFieldOrderStatus:public CBMLField
{
public:
	CBCESFieldOrderStatus(){
		m_dat=(void*)&OrderStatus;
		m_siz=sizeof(OrderStatus);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderStatus;
		memset(&OrderStatus,0x00,sizeof(OrderStatus));	/* 订单状态 */
	}
	BCESFieldTypeFlag OrderStatus;	/* 订单状态 */
};
/* 撤单请求 */
class CBCESFieldOrderCancelReq:public CBMLField
{
public:
	CBCESFieldOrderCancelReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderCancelReq;
		
	}
	
};
/* 撤单应答 */
class CBCESFieldOrderCancelRsp:public CBMLField
{
public:
	CBCESFieldOrderCancelRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderCancelRsp;
		
	}
	
};
/* 合约类型 */
class CBCESFieldInstrumentType:public CBMLField
{
public:
	CBCESFieldInstrumentType(){
		m_dat=(void*)&InstrumentType;
		m_siz=sizeof(InstrumentType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrumentType;
		memset(&InstrumentType,0x00,sizeof(InstrumentType));	/* 合约类型 */
	}
	BCESFieldTypeFlag InstrumentType;	/* 合约类型 */
};
/* 成交日期 */
class CBCESFieldMatchDate:public CBMLField
{
public:
	CBCESFieldMatchDate(){
		m_dat=(void*)MatchDate;
		m_siz=sizeof(MatchDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMatchDate;
		memset(MatchDate,0x00,sizeof(MatchDate));	/* 成交日期 */
	}
	BCESFieldTypeDate MatchDate;	/* 成交日期 */
};
/* 成交时间 */
class CBCESFieldMatchTime:public CBMLField
{
public:
	CBCESFieldMatchTime(){
		m_dat=(void*)MatchTime;
		m_siz=sizeof(MatchTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMatchTime;
		memset(MatchTime,0x00,sizeof(MatchTime));	/* 成交时间 */
	}
	BCESFieldTypeTime MatchTime;	/* 成交时间 */
};
/* 成交号 */
class CBCESFieldMatchID:public CBMLField
{
public:
	CBCESFieldMatchID(){
		m_dat=(void*)MatchID;
		m_siz=sizeof(MatchID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMatchID;
		memset(MatchID,0x00,sizeof(MatchID));	/* 成交号 */
	}
	BCESFieldTypeMatchID MatchID;	/* 成交号 */
};
/* 持仓号 */
class CBCESFieldPosiID:public CBMLField
{
public:
	CBCESFieldPosiID(){
		m_dat=(void*)PosiID;
		m_siz=sizeof(PosiID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosiID;
		memset(PosiID,0x00,sizeof(PosiID));	/* 持仓号 */
	}
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
};
/* 交易日期 */
class CBCESFieldTradeDate:public CBMLField
{
public:
	CBCESFieldTradeDate(){
		m_dat=(void*)TradeDate;
		m_siz=sizeof(TradeDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeDate;
		memset(TradeDate,0x00,sizeof(TradeDate));	/* 交易日期 */
	}
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
};
/* 叫买价 */
class CBCESFieldBidPrice:public CBMLField
{
public:
	CBCESFieldBidPrice(){
		m_dat=(void*)&BidPrice;
		m_siz=sizeof(BidPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice;
		memset(&BidPrice,0x00,sizeof(BidPrice));	/* 叫买价 */
	}
	BCESFieldTypePrice BidPrice;	/* 叫买价 */
};
/* 叫卖价 */
class CBCESFieldAskPrice:public CBMLField
{
public:
	CBCESFieldAskPrice(){
		m_dat=(void*)&AskPrice;
		m_siz=sizeof(AskPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice;
		memset(&AskPrice,0x00,sizeof(AskPrice));	/* 叫卖价 */
	}
	BCESFieldTypePrice AskPrice;	/* 叫卖价 */
};
/* 昨结算价 */
class CBCESFieldPreSettle:public CBMLField
{
public:
	CBCESFieldPreSettle(){
		m_dat=(void*)&PreSettle;
		m_siz=sizeof(PreSettle);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreSettle;
		memset(&PreSettle,0x00,sizeof(PreSettle));	/* 昨结算价 */
	}
	BCESFieldTypePrice PreSettle;	/* 昨结算价 */
};
/* 昨持仓量 */
class CBCESFieldPreOI:public CBMLField
{
public:
	CBCESFieldPreOI(){
		m_dat=(void*)&PreOI;
		m_siz=sizeof(PreOI);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreOI;
		memset(&PreOI,0x00,sizeof(PreOI));	/* 昨持仓量 */
	}
	BCESFieldTypeQtyTotal PreOI;	/* 昨持仓量 */
};
/* 成交量 */
class CBCESFieldQtyTotal:public CBMLField
{
public:
	CBCESFieldQtyTotal(){
		m_dat=(void*)&QtyTotal;
		m_siz=sizeof(QtyTotal);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQtyTotal;
		memset(&QtyTotal,0x00,sizeof(QtyTotal));	/* 成交量 */
	}
	BCESFieldTypeQtyTotal QtyTotal;	/* 成交量 */
};
/* 持仓量 */
class CBCESFieldOI:public CBMLField
{
public:
	CBCESFieldOI(){
		m_dat=(void*)&OI;
		m_siz=sizeof(OI);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOI;
		memset(&OI,0x00,sizeof(OI));	/* 持仓量 */
	}
	BCESFieldTypeQtyTotal OI;	/* 持仓量 */
};
/* 成交金额 */
class CBCESFieldAmount:public CBMLField
{
public:
	CBCESFieldAmount(){
		m_dat=(void*)&Amount;
		m_siz=sizeof(Amount);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAmount;
		memset(&Amount,0x00,sizeof(Amount));	/* 成交金额 */
	}
	BCESFieldTypeAmount Amount;	/* 成交金额 */
};
/* 均价 */
class CBCESFieldAvgPrice:public CBMLField
{
public:
	CBCESFieldAvgPrice(){
		m_dat=(void*)&AvgPrice;
		m_siz=sizeof(AvgPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAvgPrice;
		memset(&AvgPrice,0x00,sizeof(AvgPrice));	/* 均价 */
	}
	BCESFieldTypePrice AvgPrice;	/* 均价 */
};
/* 结算价 */
class CBCESFieldSettlePrice:public CBMLField
{
public:
	CBCESFieldSettlePrice(){
		m_dat=(void*)&SettlePrice;
		m_siz=sizeof(SettlePrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSettlePrice;
		memset(&SettlePrice,0x00,sizeof(SettlePrice));	/* 结算价 */
	}
	BCESFieldTypePrice SettlePrice;	/* 结算价 */
};
/* 昨收盘价 */
class CBCESFieldPreClose:public CBMLField
{
public:
	CBCESFieldPreClose(){
		m_dat=(void*)&PreClose;
		m_siz=sizeof(PreClose);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreClose;
		memset(&PreClose,0x00,sizeof(PreClose));	/* 昨收盘价 */
	}
	BCESFieldTypePrice PreClose;	/* 昨收盘价 */
};
/* 开盘价 */
class CBCESFieldOpenPrice:public CBMLField
{
public:
	CBCESFieldOpenPrice(){
		m_dat=(void*)&OpenPrice;
		m_siz=sizeof(OpenPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOpenPrice;
		memset(&OpenPrice,0x00,sizeof(OpenPrice));	/* 开盘价 */
	}
	BCESFieldTypePrice OpenPrice;	/* 开盘价 */
};
/* 最高价 */
class CBCESFieldHighestPrice:public CBMLField
{
public:
	CBCESFieldHighestPrice(){
		m_dat=(void*)&HighestPrice;
		m_siz=sizeof(HighestPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHighestPrice;
		memset(&HighestPrice,0x00,sizeof(HighestPrice));	/* 最高价 */
	}
	BCESFieldTypePrice HighestPrice;	/* 最高价 */
};
/* 最低价 */
class CBCESFieldLowestPrice:public CBMLField
{
public:
	CBCESFieldLowestPrice(){
		m_dat=(void*)&LowestPrice;
		m_siz=sizeof(LowestPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLowestPrice;
		memset(&LowestPrice,0x00,sizeof(LowestPrice));	/* 最低价 */
	}
	BCESFieldTypePrice LowestPrice;	/* 最低价 */
};
/* 收盘价 */
class CBCESFieldClosePrice:public CBMLField
{
public:
	CBCESFieldClosePrice(){
		m_dat=(void*)&ClosePrice;
		m_siz=sizeof(ClosePrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexClosePrice;
		memset(&ClosePrice,0x00,sizeof(ClosePrice));	/* 收盘价 */
	}
	BCESFieldTypePrice ClosePrice;	/* 收盘价 */
};
/* 成交额 */
class CBCESFieldAmountTotal:public CBMLField
{
public:
	CBCESFieldAmountTotal(){
		m_dat=(void*)&AmountTotal;
		m_siz=sizeof(AmountTotal);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAmountTotal;
		memset(&AmountTotal,0x00,sizeof(AmountTotal));	/* 成交额 */
	}
	BCESFieldTypeAmount AmountTotal;	/* 成交额 */
};
/* 叫买量 */
class CBCESFieldBidQty:public CBMLField
{
public:
	CBCESFieldBidQty(){
		m_dat=(void*)&BidQty;
		m_siz=sizeof(BidQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty;
		memset(&BidQty,0x00,sizeof(BidQty));	/* 叫买量 */
	}
	BCESFieldTypeQty BidQty;	/* 叫买量 */
};
/* 叫卖量 */
class CBCESFieldAskQty:public CBMLField
{
public:
	CBCESFieldAskQty(){
		m_dat=(void*)&AskQty;
		m_siz=sizeof(AskQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty;
		memset(&AskQty,0x00,sizeof(AskQty));	/* 叫卖量 */
	}
	BCESFieldTypeQty AskQty;	/* 叫卖量 */
};
/* 行情列表 */
class CBCESFieldQuotList:public CBMLField
{
public:
	CBCESFieldQuotList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotList;
		
	}
	
};
/* 行情查询请求 */
class CBCESFieldQuotQueryReq:public CBMLField
{
public:
	CBCESFieldQuotQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotQueryReq;
		
	}
	
};
/* 行情 */
class CBCESFieldQuot:public CBMLField
{
public:
	CBCESFieldQuot(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuot;
		
	}
	
};
/* 国际行情 */
class CBCESFieldInternationalQuot:public CBMLField
{
public:
	CBCESFieldInternationalQuot(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInternationalQuot;
		
	}
	
};
/* 订单查询请求 */
class CBCESFieldOrderQueryReq:public CBMLField
{
public:
	CBCESFieldOrderQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderQueryReq;
		
	}
	
};
/* 订单 */
class CBCESFieldOrder:public CBMLField
{
public:
	CBCESFieldOrder(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrder;
		
	}
	
};
/* 成交查询请求 */
class CBCESFieldTradeQueryReq:public CBMLField
{
public:
	CBCESFieldTradeQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeQueryReq;
		
	}
	
};
/* 成交单 */
class CBCESFieldTrade:public CBMLField
{
public:
	CBCESFieldTrade(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTrade;
		
	}
	
};
/* 持仓查询请求 */
class CBCESFieldPosiQueryReq:public CBMLField
{
public:
	CBCESFieldPosiQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosiQueryReq;
		
	}
	
};
/* 持仓 */
class CBCESFieldPosi:public CBMLField
{
public:
	CBCESFieldPosi(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosi;
		
	}
	
};
/* 订单列表 */
class CBCESFieldOrderList:public CBMLField
{
public:
	CBCESFieldOrderList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderList;
		
	}
	
};
/* 成交单列表 */
class CBCESFieldTradeList:public CBMLField
{
public:
	CBCESFieldTradeList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeList;
		
	}
	
};
/* 持仓列表 */
class CBCESFieldPosiList:public CBMLField
{
public:
	CBCESFieldPosiList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosiList;
		
	}
	
};
/* 市场状态 */
class CBCESFieldMarketStatus:public CBMLField
{
public:
	CBCESFieldMarketStatus(){
		m_dat=(void*)&MarketStatus;
		m_siz=sizeof(MarketStatus);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMarketStatus;
		memset(&MarketStatus,0x00,sizeof(MarketStatus));	/* 市场状态 */
	}
	BCESFieldTypeFlag MarketStatus;	/* 市场状态 */
};
/* 市场状态通知 */
class CBCESFieldMarketStatusNty:public CBMLField
{
public:
	CBCESFieldMarketStatusNty(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMarketStatusNty;
		
	}
	
};
/* 资金查询请求 */
class CBCESFieldHisFundQueryReq:public CBMLField
{
public:
	CBCESFieldHisFundQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHisFundQueryReq;
		
	}
	
};
/* 持仓明细查询请求 */
class CBCESFieldHisPosiDetailQueryReq:public CBMLField
{
public:
	CBCESFieldHisPosiDetailQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHisPosiDetailQueryReq;
		
	}
	
};
/* 可用资金 */
class CBCESFieldFreeBalance:public CBMLField
{
public:
	CBCESFieldFreeBalance(){
		m_dat=(void*)&FreeBalance;
		m_siz=sizeof(FreeBalance);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFreeBalance;
		memset(&FreeBalance,0x00,sizeof(FreeBalance));	/* 可用资金 */
	}
	BCESFieldTypeAmount FreeBalance;	/* 可用资金 */
};
/* 资金查询请求 */
class CBCESFieldFundQueryReq:public CBMLField
{
public:
	CBCESFieldFundQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundQueryReq;
		
	}
	
};
/* 资金 */
class CBCESFieldFund:public CBMLField
{
public:
	CBCESFieldFund(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFund;
		
	}
	
};
/* 冻结资金 */
class CBCESFieldFrozenBalance:public CBMLField
{
public:
	CBCESFieldFrozenBalance(){
		m_dat=(void*)&FrozenBalance;
		m_siz=sizeof(FrozenBalance);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFrozenBalance;
		memset(&FrozenBalance,0x00,sizeof(FrozenBalance));	/* 冻结资金 */
	}
	BCESFieldTypeAmount FrozenBalance;	/* 冻结资金 */
};
/* 上日资金 */
class CBCESFieldLastBalance:public CBMLField
{
public:
	CBCESFieldLastBalance(){
		m_dat=(void*)&LastBalance;
		m_siz=sizeof(LastBalance);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLastBalance;
		memset(&LastBalance,0x00,sizeof(LastBalance));	/* 上日资金 */
	}
	BCESFieldTypeAmount LastBalance;	/* 上日资金 */
};
/* 当日出入金 */
class CBCESFieldFloatBalance:public CBMLField
{
public:
	CBCESFieldFloatBalance(){
		m_dat=(void*)&FloatBalance;
		m_siz=sizeof(FloatBalance);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFloatBalance;
		memset(&FloatBalance,0x00,sizeof(FloatBalance));	/* 当日出入金 */
	}
	BCESFieldTypeAmount FloatBalance;	/* 当日出入金 */
};
/* 当日保证金 */
class CBCESFieldMargin:public CBMLField
{
public:
	CBCESFieldMargin(){
		m_dat=(void*)&Margin;
		m_siz=sizeof(Margin);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMargin;
		memset(&Margin,0x00,sizeof(Margin));	/* 当日保证金 */
	}
	BCESFieldTypeAmount Margin;	/* 当日保证金 */
};
/* 当日追加保证金 */
class CBCESFieldFrozenMargin:public CBMLField
{
public:
	CBCESFieldFrozenMargin(){
		m_dat=(void*)&FrozenMargin;
		m_siz=sizeof(FrozenMargin);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFrozenMargin;
		memset(&FrozenMargin,0x00,sizeof(FrozenMargin));	/* 当日追加保证金 */
	}
	BCESFieldTypeAmount FrozenMargin;	/* 当日追加保证金 */
};
/* 手续费 */
class CBCESFieldFee:public CBMLField
{
public:
	CBCESFieldFee(){
		m_dat=(void*)&Fee;
		m_siz=sizeof(Fee);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFee;
		memset(&Fee,0x00,sizeof(Fee));	/* 手续费 */
	}
	BCESFieldTypeAmount Fee;	/* 手续费 */
};
/* 冻结手续费 */
class CBCESFieldFeeFrozen:public CBMLField
{
public:
	CBCESFieldFeeFrozen(){
		m_dat=(void*)&FeeFrozen;
		m_siz=sizeof(FeeFrozen);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFeeFrozen;
		memset(&FeeFrozen,0x00,sizeof(FeeFrozen));	/* 冻结手续费 */
	}
	BCESFieldTypeAmount FeeFrozen;	/* 冻结手续费 */
};
/* 当日平仓盈亏 */
class CBCESFieldClosedPL:public CBMLField
{
public:
	CBCESFieldClosedPL(){
		m_dat=(void*)&ClosedPL;
		m_siz=sizeof(ClosedPL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexClosedPL;
		memset(&ClosedPL,0x00,sizeof(ClosedPL));	/* 当日平仓盈亏 */
	}
	BCESFieldTypeAmount ClosedPL;	/* 当日平仓盈亏 */
};
/* 当日总盈亏 */
class CBCESFieldFloatingPL:public CBMLField
{
public:
	CBCESFieldFloatingPL(){
		m_dat=(void*)&FloatingPL;
		m_siz=sizeof(FloatingPL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFloatingPL;
		memset(&FloatingPL,0x00,sizeof(FloatingPL));	/* 当日总盈亏 */
	}
	BCESFieldTypeAmount FloatingPL;	/* 当日总盈亏 */
};
/* 当日交易手续费 */
class CBCESFieldProfitLoss:public CBMLField
{
public:
	CBCESFieldProfitLoss(){
		m_dat=(void*)&ProfitLoss;
		m_siz=sizeof(ProfitLoss);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexProfitLoss;
		memset(&ProfitLoss,0x00,sizeof(ProfitLoss));	/* 当日交易手续费 */
	}
	BCESFieldTypeAmount ProfitLoss;	/* 当日交易手续费 */
};
/* 当日风险手续费 */
class CBCESFieldTotalPL:public CBMLField
{
public:
	CBCESFieldTotalPL(){
		m_dat=(void*)&TotalPL;
		m_siz=sizeof(TotalPL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTotalPL;
		memset(&TotalPL,0x00,sizeof(TotalPL));	/* 当日风险手续费 */
	}
	BCESFieldTypeAmount TotalPL;	/* 当日风险手续费 */
};
/* 合约列表 */
class CBCESFieldInstrumentList:public CBMLField
{
public:
	CBCESFieldInstrumentList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrumentList;
		
	}
	
};
/* 合约查询请求 */
class CBCESFieldInstrumentQueryReq:public CBMLField
{
public:
	CBCESFieldInstrumentQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrumentQueryReq;
		
	}
	
};
/* 合约 */
class CBCESFieldInstrument:public CBMLField
{
public:
	CBCESFieldInstrument(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrument;
		
	}
	
};
/* 市场状态描述 */
class CBCESFieldMarketStatusDesc:public CBMLField
{
public:
	CBCESFieldMarketStatusDesc(){
		m_dat=(void*)MarketStatusDesc;
		m_siz=sizeof(MarketStatusDesc);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMarketStatusDesc;
		memset(MarketStatusDesc,0x00,sizeof(MarketStatusDesc));	/* 市场状态描述 */
	}
	BCESFieldTypeMarketStatusDesc MarketStatusDesc;	/* 市场状态描述 */
};
/* 品种代码 */
class CBCESFieldVarietyID:public CBMLField
{
public:
	CBCESFieldVarietyID(){
		m_dat=(void*)VarietyID;
		m_siz=sizeof(VarietyID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexVarietyID;
		memset(VarietyID,0x00,sizeof(VarietyID));	/* 品种代码 */
	}
	BCESFieldTypeVarietyID VarietyID;	/* 品种代码 */
};
/* 合约状态 */
class CBCESFieldInstrumentStatus:public CBMLField
{
public:
	CBCESFieldInstrumentStatus(){
		m_dat=(void*)&InstrumentStatus;
		m_siz=sizeof(InstrumentStatus);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrumentStatus;
		memset(&InstrumentStatus,0x00,sizeof(InstrumentStatus));	/* 合约状态 */
	}
	BCESFieldTypeFlag InstrumentStatus;	/* 合约状态 */
};
/* 交易单位 */
class CBCESFieldTradeUnit:public CBMLField
{
public:
	CBCESFieldTradeUnit(){
		m_dat=(void*)&TradeUnit;
		m_siz=sizeof(TradeUnit);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeUnit;
		memset(&TradeUnit,0x00,sizeof(TradeUnit));	/* 交易单位 */
	}
	BCESFieldTypeQty TradeUnit;	/* 交易单位 */
};
/* 报价单位 */
class CBCESFieldPriceUnit:public CBMLField
{
public:
	CBCESFieldPriceUnit(){
		m_dat=(void*)&PriceUnit;
		m_siz=sizeof(PriceUnit);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPriceUnit;
		memset(&PriceUnit,0x00,sizeof(PriceUnit));	/* 报价单位 */
	}
	BCESFieldTypeFlag PriceUnit;	/* 报价单位 */
};
/* 涨跌停限制 */
class CBCESFieldDailyPriceLimit:public CBMLField
{
public:
	CBCESFieldDailyPriceLimit(){
		m_dat=(void*)&DailyPriceLimit;
		m_siz=sizeof(DailyPriceLimit);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDailyPriceLimit;
		memset(&DailyPriceLimit,0x00,sizeof(DailyPriceLimit));	/* 涨跌停限制 */
	}
	BCESFieldTypeRate DailyPriceLimit;	/* 涨跌停限制 */
};
/* 手续费类型 */
class CBCESFieldFeeType:public CBMLField
{
public:
	CBCESFieldFeeType(){
		m_dat=(void*)&FeeType;
		m_siz=sizeof(FeeType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFeeType;
		memset(&FeeType,0x00,sizeof(FeeType));	/* 手续费类型 */
	}
	BCESFieldTypeFlag FeeType;	/* 手续费类型 */
};
/* 手续费率 */
class CBCESFieldFeeRate:public CBMLField
{
public:
	CBCESFieldFeeRate(){
		m_dat=(void*)&FeeRate;
		m_siz=sizeof(FeeRate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFeeRate;
		memset(&FeeRate,0x00,sizeof(FeeRate));	/* 手续费率 */
	}
	BCESFieldTypeRate FeeRate;	/* 手续费率 */
};
/* 报价精度 */
class CBCESFieldPriceScale:public CBMLField
{
public:
	CBCESFieldPriceScale(){
		m_dat=(void*)&PriceScale;
		m_siz=sizeof(PriceScale);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPriceScale;
		memset(&PriceScale,0x00,sizeof(PriceScale));	/* 报价精度 */
	}
	BCESFieldTypePrice PriceScale;	/* 报价精度 */
};
/* 保证金率 */
class CBCESFieldMarginRate:public CBMLField
{
public:
	CBCESFieldMarginRate(){
		m_dat=(void*)&MarginRate;
		m_siz=sizeof(MarginRate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMarginRate;
		memset(&MarginRate,0x00,sizeof(MarginRate));	/* 保证金率 */
	}
	BCESFieldTypePrice MarginRate;	/* 保证金率 */
};
/* 涨停板价 */
class CBCESFieldHighLimit:public CBMLField
{
public:
	CBCESFieldHighLimit(){
		m_dat=(void*)&HighLimit;
		m_siz=sizeof(HighLimit);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHighLimit;
		memset(&HighLimit,0x00,sizeof(HighLimit));	/* 涨停板价 */
	}
	BCESFieldTypePrice HighLimit;	/* 涨停板价 */
};
/* 跌停板价 */
class CBCESFieldLowLimit:public CBMLField
{
public:
	CBCESFieldLowLimit(){
		m_dat=(void*)&LowLimit;
		m_siz=sizeof(LowLimit);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLowLimit;
		memset(&LowLimit,0x00,sizeof(LowLimit));	/* 跌停板价 */
	}
	BCESFieldTypePrice LowLimit;	/* 跌停板价 */
};
/* 买冻结持仓量 */
class CBCESFieldBuyQtyFrozen:public CBMLField
{
public:
	CBCESFieldBuyQtyFrozen(){
		m_dat=(void*)&BuyQtyFrozen;
		m_siz=sizeof(BuyQtyFrozen);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBuyQtyFrozen;
		memset(&BuyQtyFrozen,0x00,sizeof(BuyQtyFrozen));	/* 买冻结持仓量 */
	}
	BCESFieldTypeQty BuyQtyFrozen;	/* 买冻结持仓量 */
};
/* 卖冻结持仓量 */
class CBCESFieldSellQtyFrozen:public CBMLField
{
public:
	CBCESFieldSellQtyFrozen(){
		m_dat=(void*)&SellQtyFrozen;
		m_siz=sizeof(SellQtyFrozen);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSellQtyFrozen;
		memset(&SellQtyFrozen,0x00,sizeof(SellQtyFrozen));	/* 卖冻结持仓量 */
	}
	BCESFieldTypeQty SellQtyFrozen;	/* 卖冻结持仓量 */
};
/* 持仓明细查询请求 */
class CBCESFieldPosiDetailQueryReq:public CBMLField
{
public:
	CBCESFieldPosiDetailQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosiDetailQueryReq;
		
	}
	
};
/* 持仓明细 */
class CBCESFieldPosiDetail:public CBMLField
{
public:
	CBCESFieldPosiDetail(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosiDetail;
		
	}
	
};
/* 持仓明细列表 */
class CBCESFieldPosiDetailList:public CBMLField
{
public:
	CBCESFieldPosiDetailList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPosiDetailList;
		
	}
	
};
/* 合约名称 */
class CBCESFieldInstrumentName:public CBMLField
{
public:
	CBCESFieldInstrumentName(){
		m_dat=(void*)InstrumentName;
		m_siz=sizeof(InstrumentName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInstrumentName;
		memset(InstrumentName,0x00,sizeof(InstrumentName));	/* 合约名称 */
	}
	BCESFieldTypeInstrumentName InstrumentName;	/* 合约名称 */
};
/* 价格变动限制 */
class CBCESFieldMinMovement:public CBMLField
{
public:
	CBCESFieldMinMovement(){
		m_dat=(void*)&MinMovement;
		m_siz=sizeof(MinMovement);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMinMovement;
		memset(&MinMovement,0x00,sizeof(MinMovement));	/* 价格变动限制 */
	}
	BCESFieldTypePrice MinMovement;	/* 价格变动限制 */
};
/* 价格变动限制 */
class CBCESFieldPriceCoefficient:public CBMLField
{
public:
	CBCESFieldPriceCoefficient(){
		m_dat=(void*)&PriceCoefficient;
		m_siz=sizeof(PriceCoefficient);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPriceCoefficient;
		memset(&PriceCoefficient,0x00,sizeof(PriceCoefficient));	/* 价格变动限制 */
	}
	BCESFieldTypeRate PriceCoefficient;	/* 价格变动限制 */
};
/* 买持仓量 */
class CBCESFieldBuyQty:public CBMLField
{
public:
	CBCESFieldBuyQty(){
		m_dat=(void*)&BuyQty;
		m_siz=sizeof(BuyQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBuyQty;
		memset(&BuyQty,0x00,sizeof(BuyQty));	/* 买持仓量 */
	}
	BCESFieldTypeQty BuyQty;	/* 买持仓量 */
};
/* 买持仓均价 */
class CBCESFieldBuyPrice:public CBMLField
{
public:
	CBCESFieldBuyPrice(){
		m_dat=(void*)&BuyPrice;
		m_siz=sizeof(BuyPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBuyPrice;
		memset(&BuyPrice,0x00,sizeof(BuyPrice));	/* 买持仓均价 */
	}
	BCESFieldTypePrice BuyPrice;	/* 买持仓均价 */
};
/* 卖持仓量 */
class CBCESFieldSellQty:public CBMLField
{
public:
	CBCESFieldSellQty(){
		m_dat=(void*)&SellQty;
		m_siz=sizeof(SellQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSellQty;
		memset(&SellQty,0x00,sizeof(SellQty));	/* 卖持仓量 */
	}
	BCESFieldTypeQty SellQty;	/* 卖持仓量 */
};
/* 卖持仓均价 */
class CBCESFieldSellPrice:public CBMLField
{
public:
	CBCESFieldSellPrice(){
		m_dat=(void*)&SellPrice;
		m_siz=sizeof(SellPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSellPrice;
		memset(&SellPrice,0x00,sizeof(SellPrice));	/* 卖持仓均价 */
	}
	BCESFieldTypePrice SellPrice;	/* 卖持仓均价 */
};
/* 分线查询请求 */
class CBCESFieldMinDataQueryReq:public CBMLField
{
public:
	CBCESFieldMinDataQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMinDataQueryReq;
		
	}
	
};
/* 分线 */
class CBCESFieldMinData:public CBMLField
{
public:
	CBCESFieldMinData(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMinData;
		
	}
	
};
/* 日线查询请求 */
class CBCESFieldDayDataQueryReq:public CBMLField
{
public:
	CBCESFieldDayDataQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDayDataQueryReq;
		
	}
	
};
/* 日线 */
class CBCESFieldDayData:public CBMLField
{
public:
	CBCESFieldDayData(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDayData;
		
	}
	
};
/* 分线列表 */
class CBCESFieldMinDataList:public CBMLField
{
public:
	CBCESFieldMinDataList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMinDataList;
		
	}
	
};
/* 日线列表 */
class CBCESFieldDayDataList:public CBMLField
{
public:
	CBCESFieldDayDataList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDayDataList;
		
	}
	
};
/* 起始日期时间 */
class CBCESFieldDateTimeFrom:public CBMLField
{
public:
	CBCESFieldDateTimeFrom(){
		m_dat=(void*)DateTimeFrom;
		m_siz=sizeof(DateTimeFrom);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDateTimeFrom;
		memset(DateTimeFrom,0x00,sizeof(DateTimeFrom));	/* 起始日期时间 */
	}
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
};
/* 结束日期时间 */
class CBCESFieldDateTimeTo:public CBMLField
{
public:
	CBCESFieldDateTimeTo(){
		m_dat=(void*)DateTimeTo;
		m_siz=sizeof(DateTimeTo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDateTimeTo;
		memset(DateTimeTo,0x00,sizeof(DateTimeTo));	/* 结束日期时间 */
	}
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
};
/* 起始日期 */
class CBCESFieldDateFrom:public CBMLField
{
public:
	CBCESFieldDateFrom(){
		m_dat=(void*)DateFrom;
		m_siz=sizeof(DateFrom);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDateFrom;
		memset(DateFrom,0x00,sizeof(DateFrom));	/* 起始日期 */
	}
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
};
/* 结束日期 */
class CBCESFieldDateTo:public CBMLField
{
public:
	CBCESFieldDateTo(){
		m_dat=(void*)DateTo;
		m_siz=sizeof(DateTo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDateTo;
		memset(DateTo,0x00,sizeof(DateTo));	/* 结束日期 */
	}
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};
/* 日期 */
class CBCESFieldDate:public CBMLField
{
public:
	CBCESFieldDate(){
		m_dat=(void*)Date;
		m_siz=sizeof(Date);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDate;
		memset(Date,0x00,sizeof(Date));	/* 日期 */
	}
	BCESFieldTypeDate Date;	/* 日期 */
};
/* 时间 */
class CBCESFieldTime:public CBMLField
{
public:
	CBCESFieldTime(){
		m_dat=(void*)Time;
		m_siz=sizeof(Time);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTime;
		memset(Time,0x00,sizeof(Time));	/* 时间 */
	}
	BCESFieldTypeTime Time;	/* 时间 */
};
/* 起始时间 */
class CBCESFieldTimeFrom:public CBMLField
{
public:
	CBCESFieldTimeFrom(){
		m_dat=(void*)TimeFrom;
		m_siz=sizeof(TimeFrom);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTimeFrom;
		memset(TimeFrom,0x00,sizeof(TimeFrom));	/* 起始时间 */
	}
	BCESFieldTypeDate TimeFrom;	/* 起始时间 */
};
/* 结束时间 */
class CBCESFieldTimeTo:public CBMLField
{
public:
	CBCESFieldTimeTo(){
		m_dat=(void*)TimeTo;
		m_siz=sizeof(TimeTo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTimeTo;
		memset(TimeTo,0x00,sizeof(TimeTo));	/* 结束时间 */
	}
	BCESFieldTypeTime TimeTo;	/* 结束时间 */
};
/* 日期时间 */
class CBCESFieldDateTime:public CBMLField
{
public:
	CBCESFieldDateTime(){
		m_dat=(void*)DateTime;
		m_siz=sizeof(DateTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDateTime;
		memset(DateTime,0x00,sizeof(DateTime));	/* 日期时间 */
	}
	BCESFieldTypeDateTime DateTime;	/* 日期时间 */
};
/* 最小成交滑点 */
class CBCESFieldLimitedFilledPoints:public CBMLField
{
public:
	CBCESFieldLimitedFilledPoints(){
		m_dat=(void*)&LimitedFilledPoints;
		m_siz=sizeof(LimitedFilledPoints);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLimitedFilledPoints;
		memset(&LimitedFilledPoints,0x00,sizeof(LimitedFilledPoints));	/* 最小成交滑点 */
	}
	BCESFieldTypePoints LimitedFilledPoints;	/* 最小成交滑点 */
};
/* 最小报价点差 */
class CBCESFieldLimitedOrderPoints:public CBMLField
{
public:
	CBCESFieldLimitedOrderPoints(){
		m_dat=(void*)&LimitedOrderPoints;
		m_siz=sizeof(LimitedOrderPoints);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLimitedOrderPoints;
		memset(&LimitedOrderPoints,0x00,sizeof(LimitedOrderPoints));	/* 最小报价点差 */
	}
	BCESFieldTypePoints LimitedOrderPoints;	/* 最小报价点差 */
};
/* 最小止赢止损点差 */
class CBCESFieldLimitedStopPoints:public CBMLField
{
public:
	CBCESFieldLimitedStopPoints(){
		m_dat=(void*)&LimitedStopPoints;
		m_siz=sizeof(LimitedStopPoints);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLimitedStopPoints;
		memset(&LimitedStopPoints,0x00,sizeof(LimitedStopPoints));	/* 最小止赢止损点差 */
	}
	BCESFieldTypePoints LimitedStopPoints;	/* 最小止赢止损点差 */
};
/* 止赢价 */
class CBCESFieldProfitStopPrice:public CBMLField
{
public:
	CBCESFieldProfitStopPrice(){
		m_dat=(void*)&ProfitStopPrice;
		m_siz=sizeof(ProfitStopPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexProfitStopPrice;
		memset(&ProfitStopPrice,0x00,sizeof(ProfitStopPrice));	/* 止赢价 */
	}
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
};
/* 止损价 */
class CBCESFieldLossStopPrice:public CBMLField
{
public:
	CBCESFieldLossStopPrice(){
		m_dat=(void*)&LossStopPrice;
		m_siz=sizeof(LossStopPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLossStopPrice;
		memset(&LossStopPrice,0x00,sizeof(LossStopPrice));	/* 止损价 */
	}
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
};
/* 止赢止损设置请求 */
class CBCESFieldProfitLossStopSetReq:public CBMLField
{
public:
	CBCESFieldProfitLossStopSetReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexProfitLossStopSetReq;
		
	}
	
};
/* 止赢止损设置应答 */
class CBCESFieldProfitLossStopSetRsp:public CBMLField
{
public:
	CBCESFieldProfitLossStopSetRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexProfitLossStopSetRsp;
		
	}
	
};
/* 成交滑点 */
class CBCESFieldFilledPoints:public CBMLField
{
public:
	CBCESFieldFilledPoints(){
		m_dat=(void*)&FilledPoints;
		m_siz=sizeof(FilledPoints);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFilledPoints;
		memset(&FilledPoints,0x00,sizeof(FilledPoints));	/* 成交滑点 */
	}
	BCESFieldTypePoints FilledPoints;	/* 成交滑点 */
};
/* 发起日期 */
class CBCESFieldCreateDate:public CBMLField
{
public:
	CBCESFieldCreateDate(){
		m_dat=(void*)CreateDate;
		m_siz=sizeof(CreateDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCreateDate;
		memset(CreateDate,0x00,sizeof(CreateDate));	/* 发起日期 */
	}
	BCESFieldTypeDate CreateDate;	/* 发起日期 */
};
/* 发起时间 */
class CBCESFieldCreateTime:public CBMLField
{
public:
	CBCESFieldCreateTime(){
		m_dat=(void*)CreateTime;
		m_siz=sizeof(CreateTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCreateTime;
		memset(CreateTime,0x00,sizeof(CreateTime));	/* 发起时间 */
	}
	BCESFieldTypeTime CreateTime;	/* 发起时间 */
};
/* 发布日期 */
class CBCESFieldPublishDate:public CBMLField
{
public:
	CBCESFieldPublishDate(){
		m_dat=(void*)PublishDate;
		m_siz=sizeof(PublishDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPublishDate;
		memset(PublishDate,0x00,sizeof(PublishDate));	/* 发布日期 */
	}
	BCESFieldTypeDate PublishDate;	/* 发布日期 */
};
/* 发布时间 */
class CBCESFieldPublishTime:public CBMLField
{
public:
	CBCESFieldPublishTime(){
		m_dat=(void*)PublishTime;
		m_siz=sizeof(PublishTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPublishTime;
		memset(PublishTime,0x00,sizeof(PublishTime));	/* 发布时间 */
	}
	BCESFieldTypeTime PublishTime;	/* 发布时间 */
};
/* 查询公告请求 */
class CBCESFieldBulletinQueryReq:public CBMLField
{
public:
	CBCESFieldBulletinQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBulletinQueryReq;
		
	}
	
};
/* 公告列表 */
class CBCESFieldBulletinList:public CBMLField
{
public:
	CBCESFieldBulletinList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBulletinList;
		
	}
	
};
/* 公告 */
class CBCESFieldBulletin:public CBMLField
{
public:
	CBCESFieldBulletin(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBulletin;
		
	}
	
};
/* 发布人 */
class CBCESFieldPublishUserID:public CBMLField
{
public:
	CBCESFieldPublishUserID(){
		m_dat=(void*)PublishUserID;
		m_siz=sizeof(PublishUserID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPublishUserID;
		memset(PublishUserID,0x00,sizeof(PublishUserID));	/* 发布人 */
	}
	BCESFieldTypeUserID PublishUserID;	/* 发布人 */
};
/* 公告编号 */
class CBCESFieldBulletinID:public CBMLField
{
public:
	CBCESFieldBulletinID(){
		m_dat=(void*)BulletinID;
		m_siz=sizeof(BulletinID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBulletinID;
		memset(BulletinID,0x00,sizeof(BulletinID));	/* 公告编号 */
	}
	BCESFieldTypeBulletinID BulletinID;	/* 公告编号 */
};
/* 标题 */
class CBCESFieldTitle:public CBMLField
{
public:
	CBCESFieldTitle(){
		m_dat=(void*)Title;
		m_siz=sizeof(Title);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTitle;
		memset(Title,0x00,sizeof(Title));	/* 标题 */
	}
	BCESFieldTypeTitle Title;	/* 标题 */
};
/* 内容 */
class CBCESFieldContent:public CBMLField
{
public:
	CBCESFieldContent(){
		m_dat=(void*)Content;
		m_siz=sizeof(Content);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexContent;
		memset(Content,0x00,sizeof(Content));	/* 内容 */
	}
	BCESFieldTypeContent Content;	/* 内容 */
};
/* 通知编号 */
class CBCESFieldNoticeID:public CBMLField
{
public:
	CBCESFieldNoticeID(){
		m_dat=(void*)NoticeID;
		m_siz=sizeof(NoticeID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexNoticeID;
		memset(NoticeID,0x00,sizeof(NoticeID));	/* 通知编号 */
	}
	BCESFieldTypeNoticeID NoticeID;	/* 通知编号 */
};
/* 发布方式 */
class CBCESFieldPublishMethod:public CBMLField
{
public:
	CBCESFieldPublishMethod(){
		m_dat=(void*)&PublishMethod;
		m_siz=sizeof(PublishMethod);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPublishMethod;
		memset(&PublishMethod,0x00,sizeof(PublishMethod));	/* 发布方式 */
	}
	BCESFieldTypeFlag PublishMethod;	/* 发布方式 */
};
/* 通知列表 */
class CBCESFieldNoticeList:public CBMLField
{
public:
	CBCESFieldNoticeList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexNoticeList;
		
	}
	
};
/* 通知 */
class CBCESFieldNotice:public CBMLField
{
public:
	CBCESFieldNotice(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexNotice;
		
	}
	
};
/* 查询通知请求 */
class CBCESFieldNoticeQueryReq:public CBMLField
{
public:
	CBCESFieldNoticeQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexNoticeQueryReq;
		
	}
	
};
/* 出入金方向 */
class CBCESFieldFundIODirection:public CBMLField
{
public:
	CBCESFieldFundIODirection(){
		m_dat=(void*)&FundIODirection;
		m_siz=sizeof(FundIODirection);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIODirection;
		memset(&FundIODirection,0x00,sizeof(FundIODirection));	/* 出入金方向 */
	}
	BCESFieldTypeFlag FundIODirection;	/* 出入金方向 */
};
/* 出入金状态 */
class CBCESFieldFundIOStatus:public CBMLField
{
public:
	CBCESFieldFundIOStatus(){
		m_dat=(void*)&FundIOStatus;
		m_siz=sizeof(FundIOStatus);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIOStatus;
		memset(&FundIOStatus,0x00,sizeof(FundIOStatus));	/* 出入金状态 */
	}
	BCESFieldTypeFlag FundIOStatus;	/* 出入金状态 */
};
/* 完成日期 */
class CBCESFieldCompleteDate:public CBMLField
{
public:
	CBCESFieldCompleteDate(){
		m_dat=(void*)CompleteDate;
		m_siz=sizeof(CompleteDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCompleteDate;
		memset(CompleteDate,0x00,sizeof(CompleteDate));	/* 完成日期 */
	}
	BCESFieldTypeDate CompleteDate;	/* 完成日期 */
};
/* 完成时间 */
class CBCESFieldCompleteTime:public CBMLField
{
public:
	CBCESFieldCompleteTime(){
		m_dat=(void*)CompleteTime;
		m_siz=sizeof(CompleteTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCompleteTime;
		memset(CompleteTime,0x00,sizeof(CompleteTime));	/* 完成时间 */
	}
	BCESFieldTypeTime CompleteTime;	/* 完成时间 */
};
/* 出入金流水号 */
class CBCESFieldFundIOSeqno:public CBMLField
{
public:
	CBCESFieldFundIOSeqno(){
		m_dat=(void*)FundIOSeqno;
		m_siz=sizeof(FundIOSeqno);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIOSeqno;
		memset(FundIOSeqno,0x00,sizeof(FundIOSeqno));	/* 出入金流水号 */
	}
	BCESFieldTypeFundIOSeqno FundIOSeqno;	/* 出入金流水号 */
};
/* 出入金状态描述 */
class CBCESFieldFundIOStatusDesc:public CBMLField
{
public:
	CBCESFieldFundIOStatusDesc(){
		m_dat=(void*)FundIOStatusDesc;
		m_siz=sizeof(FundIOStatusDesc);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIOStatusDesc;
		memset(FundIOStatusDesc,0x00,sizeof(FundIOStatusDesc));	/* 出入金状态描述 */
	}
	BCESFieldTypeFundIOStatusDesc FundIOStatusDesc;	/* 出入金状态描述 */
};
/* 电子出入金请求 */
class CBCESFieldElectronicFundIOReq:public CBMLField
{
public:
	CBCESFieldElectronicFundIOReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexElectronicFundIOReq;
		
	}
	
};
/* 电子出入金响应 */
class CBCESFieldElectronicFundIORsp:public CBMLField
{
public:
	CBCESFieldElectronicFundIORsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexElectronicFundIORsp;
		
	}
	
};
/* 网址 */
class CBCESFieldPayURL:public CBMLField
{
public:
	CBCESFieldPayURL(){
		m_dat=(void*)PayURL;
		m_siz=sizeof(PayURL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPayURL;
		memset(PayURL,0x00,sizeof(PayURL));	/* 网址 */
	}
	BCESFieldTypeURL PayURL;	/* 网址 */
};
/* 支付方向 */
class CBCESFieldPayDirection:public CBMLField
{
public:
	CBCESFieldPayDirection(){
		m_dat=(void*)&PayDirection;
		m_siz=sizeof(PayDirection);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPayDirection;
		memset(&PayDirection,0x00,sizeof(PayDirection));	/* 支付方向 */
	}
	BCESFieldTypeFlag PayDirection;	/* 支付方向 */
};
/* 电子出入金通知 */
class CBCESFieldElectronicFundIONty:public CBMLField
{
public:
	CBCESFieldElectronicFundIONty(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexElectronicFundIONty;
		
	}
	
};
/* 出入金方式 */
class CBCESFieldFundIOMethod:public CBMLField
{
public:
	CBCESFieldFundIOMethod(){
		m_dat=(void*)&FundIOMethod;
		m_siz=sizeof(FundIOMethod);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIOMethod;
		memset(&FundIOMethod,0x00,sizeof(FundIOMethod));	/* 出入金方式 */
	}
	BCESFieldTypeFlag FundIOMethod;	/* 出入金方式 */
};
/* 出入金明细 */
class CBCESFieldFundIODetail:public CBMLField
{
public:
	CBCESFieldFundIODetail(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIODetail;
		
	}
	
};
/* 出入金明细列表 */
class CBCESFieldFundIODetailList:public CBMLField
{
public:
	CBCESFieldFundIODetailList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIODetailList;
		
	}
	
};
/* 出入金明细查询请求 */
class CBCESFieldFundIODetailQueryReq:public CBMLField
{
public:
	CBCESFieldFundIODetailQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundIODetailQueryReq;
		
	}
	
};
/* 收款行号 */
class CBCESFieldReceiveBankID:public CBMLField
{
public:
	CBCESFieldReceiveBankID(){
		m_dat=(void*)ReceiveBankID;
		m_siz=sizeof(ReceiveBankID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReceiveBankID;
		memset(ReceiveBankID,0x00,sizeof(ReceiveBankID));	/* 收款行号 */
	}
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
};
/* 收款帐号 */
class CBCESFieldReceiveAccountID:public CBMLField
{
public:
	CBCESFieldReceiveAccountID(){
		m_dat=(void*)ReceiveAccountID;
		m_siz=sizeof(ReceiveAccountID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReceiveAccountID;
		memset(ReceiveAccountID,0x00,sizeof(ReceiveAccountID));	/* 收款帐号 */
	}
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
};
/* 收款户名 */
class CBCESFieldReceiveAccountName:public CBMLField
{
public:
	CBCESFieldReceiveAccountName(){
		m_dat=(void*)ReceiveAccountName;
		m_siz=sizeof(ReceiveAccountName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReceiveAccountName;
		memset(ReceiveAccountName,0x00,sizeof(ReceiveAccountName));	/* 收款户名 */
	}
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
};
/* 报表 */
class CBCESFieldReport:public CBMLField
{
public:
	CBCESFieldReport(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReport;
		
	}
	
};
/* 报表列表 */
class CBCESFieldReportList:public CBMLField
{
public:
	CBCESFieldReportList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReportList;
		
	}
	
};
/* 报表查询请求 */
class CBCESFieldReportQueryReq:public CBMLField
{
public:
	CBCESFieldReportQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReportQueryReq;
		
	}
	
};
/* 报表内容 */
class CBCESFieldReportData:public CBMLField
{
public:
	CBCESFieldReportData(){
		m_dat=(void*)ReportData;
		m_siz=sizeof(ReportData);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReportData;
		memset(ReportData,0x00,sizeof(ReportData));	/* 报表内容 */
	}
	BCESFieldTypeReportData ReportData;	/* 报表内容 */
};
/* 历史订单查询请求 */
class CBCESFieldHisOrderQueryReq:public CBMLField
{
public:
	CBCESFieldHisOrderQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHisOrderQueryReq;
		
	}
	
};
/* 历史成交查询请求 */
class CBCESFieldHisTradeQueryReq:public CBMLField
{
public:
	CBCESFieldHisTradeQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHisTradeQueryReq;
		
	}
	
};
/* 查询历史公告请求 */
class CBCESFieldHisBulletinQueryReq:public CBMLField
{
public:
	CBCESFieldHisBulletinQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHisBulletinQueryReq;
		
	}
	
};
/* 查询历史通知请求 */
class CBCESFieldHisNoticeQueryReq:public CBMLField
{
public:
	CBCESFieldHisNoticeQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHisNoticeQueryReq;
		
	}
	
};
/* 投资者排名 */
class CBCESFieldInvestorRanking:public CBMLField
{
public:
	CBCESFieldInvestorRanking(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorRanking;
		
	}
	
};
/* 投资者排名列表 */
class CBCESFieldInvestorRankingList:public CBMLField
{
public:
	CBCESFieldInvestorRankingList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorRankingList;
		
	}
	
};
/* 投资者排名查询请求 */
class CBCESFieldInvestorRankingQueryReq:public CBMLField
{
public:
	CBCESFieldInvestorRankingQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorRankingQueryReq;
		
	}
	
};
/* 投资者排名查询应答 */
class CBCESFieldInvestorRankingQueryRsp:public CBMLField
{
public:
	CBCESFieldInvestorRankingQueryRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorRankingQueryRsp;
		
	}
	
};
/* 排名 */
class CBCESFieldRankingNum:public CBMLField
{
public:
	CBCESFieldRankingNum(){
		m_dat=(void*)&RankingNum;
		m_siz=sizeof(RankingNum);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRankingNum;
		memset(&RankingNum,0x00,sizeof(RankingNum));	/* 排名 */
	}
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};
/* 投资者名称 */
class CBCESFieldInvestorName:public CBMLField
{
public:
	CBCESFieldInvestorName(){
		m_dat=(void*)InvestorName;
		m_siz=sizeof(InvestorName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorName;
		memset(InvestorName,0x00,sizeof(InvestorName));	/* 投资者名称 */
	}
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
};
/* 交易设置 */
class CBCESFieldTradeSettings:public CBMLField
{
public:
	CBCESFieldTradeSettings(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettings;
		
	}
	
};
/* 交易设置列表 */
class CBCESFieldTradeSettingsList:public CBMLField
{
public:
	CBCESFieldTradeSettingsList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsList;
		
	}
	
};
/* 交易设置增加请求 */
class CBCESFieldTradeSettingsAddReq:public CBMLField
{
public:
	CBCESFieldTradeSettingsAddReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsAddReq;
		
	}
	
};
/* 交易设置增加应答 */
class CBCESFieldTradeSettingsAddRsp:public CBMLField
{
public:
	CBCESFieldTradeSettingsAddRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsAddRsp;
		
	}
	
};
/* 交易设置修改请求 */
class CBCESFieldTradeSettingsModifyReq:public CBMLField
{
public:
	CBCESFieldTradeSettingsModifyReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsModifyReq;
		
	}
	
};
/* 交易设置修改应答 */
class CBCESFieldTradeSettingsModifyRsp:public CBMLField
{
public:
	CBCESFieldTradeSettingsModifyRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsModifyRsp;
		
	}
	
};
/* 交易设置删除请求 */
class CBCESFieldTradeSettingsDeleteReq:public CBMLField
{
public:
	CBCESFieldTradeSettingsDeleteReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsDeleteReq;
		
	}
	
};
/* 交易设置删除应答 */
class CBCESFieldTradeSettingsDeleteRsp:public CBMLField
{
public:
	CBCESFieldTradeSettingsDeleteRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsDeleteRsp;
		
	}
	
};
/* 交易设置查询请求 */
class CBCESFieldTradeSettingsQueryReq:public CBMLField
{
public:
	CBCESFieldTradeSettingsQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeSettingsQueryReq;
		
	}
	
};
/* 交易行为 */
class CBCESFieldTradeAction:public CBMLField
{
public:
	CBCESFieldTradeAction(){
		m_dat=(void*)&TradeAction;
		m_siz=sizeof(TradeAction);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeAction;
		memset(&TradeAction,0x00,sizeof(TradeAction));	/* 交易行为 */
	}
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};
/* 产地 */
class CBCESFieldAddress:public CBMLField
{
public:
	CBCESFieldAddress(){
		m_dat=(void*)Address;
		m_siz=sizeof(Address);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAddress;
		memset(Address,0x00,sizeof(Address));	/* 产地 */
	}
	BCESFieldTypeAddress Address;	/* 产地 */
};
/* 仓库 */
class CBCESFieldWareHouse:public CBMLField
{
public:
	CBCESFieldWareHouse(){
		m_dat=(void*)WareHouse;
		m_siz=sizeof(WareHouse);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexWareHouse;
		memset(WareHouse,0x00,sizeof(WareHouse));	/* 仓库 */
	}
	BCESFieldTypeAddress WareHouse;	/* 仓库 */
};
/* 币种 */
class CBCESFieldCurrency:public CBMLField
{
public:
	CBCESFieldCurrency(){
		m_dat=(void*)&Currency;
		m_siz=sizeof(Currency);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCurrency;
		memset(&Currency,0x00,sizeof(Currency));	/* 币种 */
	}
	BCESFieldTypeFlag Currency;	/* 币种 */
};
/* 签约信息 */
class CBCESFieldAccountBind:public CBMLField
{
public:
	CBCESFieldAccountBind(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBind;
		
	}
	
};
/* 签约信息列表 */
class CBCESFieldAccountBindList:public CBMLField
{
public:
	CBCESFieldAccountBindList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindList;
		
	}
	
};
/* 签约信息查询请求 */
class CBCESFieldAccountBindQueryReq:public CBMLField
{
public:
	CBCESFieldAccountBindQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindQueryReq;
		
	}
	
};
/* 签约请求 */
class CBCESFieldAccountBindReq:public CBMLField
{
public:
	CBCESFieldAccountBindReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindReq;
		
	}
	
};
/* 签约应答 */
class CBCESFieldAccountBindRsp:public CBMLField
{
public:
	CBCESFieldAccountBindRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindRsp;
		
	}
	
};
/* 平仓日期 */
class CBCESFieldCloseDate:public CBMLField
{
public:
	CBCESFieldCloseDate(){
		m_dat=(void*)CloseDate;
		m_siz=sizeof(CloseDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCloseDate;
		memset(CloseDate,0x00,sizeof(CloseDate));	/* 平仓日期 */
	}
	BCESFieldTypeDate CloseDate;	/* 平仓日期 */
};
/* 平仓时间 */
class CBCESFieldCloseTime:public CBMLField
{
public:
	CBCESFieldCloseTime(){
		m_dat=(void*)CloseTime;
		m_siz=sizeof(CloseTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCloseTime;
		memset(CloseTime,0x00,sizeof(CloseTime));	/* 平仓时间 */
	}
	BCESFieldTypeTime CloseTime;	/* 平仓时间 */
};
/* 隔夜费 */
class CBCESFieldOverNightFee:public CBMLField
{
public:
	CBCESFieldOverNightFee(){
		m_dat=(void*)&OverNightFee;
		m_siz=sizeof(OverNightFee);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOverNightFee;
		memset(&OverNightFee,0x00,sizeof(OverNightFee));	/* 隔夜费 */
	}
	BCESFieldTypePrice OverNightFee;	/* 隔夜费 */
};
/* 代理商名称 */
class CBCESFieldAgentName:public CBMLField
{
public:
	CBCESFieldAgentName(){
		m_dat=(void*)AgentName;
		m_siz=sizeof(AgentName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAgentName;
		memset(AgentName,0x00,sizeof(AgentName));	/* 代理商名称 */
	}
	BCESFieldTypeName AgentName;	/* 代理商名称 */
};
/* 入金金额 */
class CBCESFieldInAmount:public CBMLField
{
public:
	CBCESFieldInAmount(){
		m_dat=(void*)&InAmount;
		m_siz=sizeof(InAmount);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInAmount;
		memset(&InAmount,0x00,sizeof(InAmount));	/* 入金金额 */
	}
	BCESFieldTypeAmount InAmount;	/* 入金金额 */
};
/* 出金金额 */
class CBCESFieldOutAmount:public CBMLField
{
public:
	CBCESFieldOutAmount(){
		m_dat=(void*)&OutAmount;
		m_siz=sizeof(OutAmount);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOutAmount;
		memset(&OutAmount,0x00,sizeof(OutAmount));	/* 出金金额 */
	}
	BCESFieldTypeAmount OutAmount;	/* 出金金额 */
};
/* 资金列表 */
class CBCESFieldFundList:public CBMLField
{
public:
	CBCESFieldFundList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFundList;
		
	}
	
};
/* 系统名称 */
class CBCESFieldSysName:public CBMLField
{
public:
	CBCESFieldSysName(){
		m_dat=(void*)SysName;
		m_siz=sizeof(SysName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSysName;
		memset(SysName,0x00,sizeof(SysName));	/* 系统名称 */
	}
	BCESFieldTypeName SysName;	/* 系统名称 */
};
/* 网络故障成交延迟 */
class CBCESFieldErrNetTradeSec:public CBMLField
{
public:
	CBCESFieldErrNetTradeSec(){
		m_dat=(void*)&ErrNetTradeSec;
		m_siz=sizeof(ErrNetTradeSec);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexErrNetTradeSec;
		memset(&ErrNetTradeSec,0x00,sizeof(ErrNetTradeSec));	/* 网络故障成交延迟 */
	}
	BCESFieldTypePoints ErrNetTradeSec;	/* 网络故障成交延迟 */
};
/* 网络故障提醒延迟 */
class CBCESFieldErrNetRemindSec:public CBMLField
{
public:
	CBCESFieldErrNetRemindSec(){
		m_dat=(void*)&ErrNetRemindSec;
		m_siz=sizeof(ErrNetRemindSec);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexErrNetRemindSec;
		memset(&ErrNetRemindSec,0x00,sizeof(ErrNetRemindSec));	/* 网络故障提醒延迟 */
	}
	BCESFieldTypePoints ErrNetRemindSec;	/* 网络故障提醒延迟 */
};
/* 网络故障提醒信息 */
class CBCESFieldErrNetRemindTxt:public CBMLField
{
public:
	CBCESFieldErrNetRemindTxt(){
		m_dat=(void*)ErrNetRemindTxt;
		m_siz=sizeof(ErrNetRemindTxt);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexErrNetRemindTxt;
		memset(ErrNetRemindTxt,0x00,sizeof(ErrNetRemindTxt));	/* 网络故障提醒信息 */
	}
	BCESFieldTypeRspDesc ErrNetRemindTxt;	/* 网络故障提醒信息 */
};
/* 服务器故障成交点差 */
class CBCESFieldErrSeverTradePort:public CBMLField
{
public:
	CBCESFieldErrSeverTradePort(){
		m_dat=(void*)&ErrSeverTradePort;
		m_siz=sizeof(ErrSeverTradePort);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexErrSeverTradePort;
		memset(&ErrSeverTradePort,0x00,sizeof(ErrSeverTradePort));	/* 服务器故障成交点差 */
	}
	BCESFieldTypePoints ErrSeverTradePort;	/* 服务器故障成交点差 */
};
/* 服务器故障提醒点差 */
class CBCESFieldErrSeverRemindPort:public CBMLField
{
public:
	CBCESFieldErrSeverRemindPort(){
		m_dat=(void*)&ErrSeverRemindPort;
		m_siz=sizeof(ErrSeverRemindPort);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexErrSeverRemindPort;
		memset(&ErrSeverRemindPort,0x00,sizeof(ErrSeverRemindPort));	/* 服务器故障提醒点差 */
	}
	BCESFieldTypePoints ErrSeverRemindPort;	/* 服务器故障提醒点差 */
};
/* 服务器故障提醒信息 */
class CBCESFieldErrSeverRemindTxt:public CBMLField
{
public:
	CBCESFieldErrSeverRemindTxt(){
		m_dat=(void*)ErrSeverRemindTxt;
		m_siz=sizeof(ErrSeverRemindTxt);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexErrSeverRemindTxt;
		memset(ErrSeverRemindTxt,0x00,sizeof(ErrSeverRemindTxt));	/* 服务器故障提醒信息 */
	}
	BCESFieldTypeRspDesc ErrSeverRemindTxt;	/* 服务器故障提醒信息 */
};
/* 测试设置修改请求 */
class CBCESFieldTestSettingsModifyReq:public CBMLField
{
public:
	CBCESFieldTestSettingsModifyReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTestSettingsModifyReq;
		
	}
	
};
/* 测试设置修改应答 */
class CBCESFieldTestSettingsModifyRsp:public CBMLField
{
public:
	CBCESFieldTestSettingsModifyRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTestSettingsModifyRsp;
		
	}
	
};
/* 保证金率类型 */
class CBCESFieldMarginRateType:public CBMLField
{
public:
	CBCESFieldMarginRateType(){
		m_dat=(void*)&MarginRateType;
		m_siz=sizeof(MarginRateType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexMarginRateType;
		memset(&MarginRateType,0x00,sizeof(MarginRateType));	/* 保证金率类型 */
	}
	BCESFieldTypeFlag MarginRateType;	/* 保证金率类型 */
};
/* 隔夜费类型 */
class CBCESFieldOverNightFeeType:public CBMLField
{
public:
	CBCESFieldOverNightFeeType(){
		m_dat=(void*)&OverNightFeeType;
		m_siz=sizeof(OverNightFeeType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOverNightFeeType;
		memset(&OverNightFeeType,0x00,sizeof(OverNightFeeType));	/* 隔夜费类型 */
	}
	BCESFieldTypeFlag OverNightFeeType;	/* 隔夜费类型 */
};
/* 收费类型 */
class CBCESFieldFeeFlag:public CBMLField
{
public:
	CBCESFieldFeeFlag(){
		m_dat=(void*)&FeeFlag;
		m_siz=sizeof(FeeFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexFeeFlag;
		memset(&FeeFlag,0x00,sizeof(FeeFlag));	/* 收费类型 */
	}
	BCESFieldTypeFlag FeeFlag;	/* 收费类型 */
};
/* 报价乘数 */
class CBCESFieldPriceMultiply:public CBMLField
{
public:
	CBCESFieldPriceMultiply(){
		m_dat=(void*)&PriceMultiply;
		m_siz=sizeof(PriceMultiply);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPriceMultiply;
		memset(&PriceMultiply,0x00,sizeof(PriceMultiply));	/* 报价乘数 */
	}
	BCESFieldTypeRate PriceMultiply;	/* 报价乘数 */
};
/* 每笔持仓限量 */
class CBCESFieldEachQtyLimt:public CBMLField
{
public:
	CBCESFieldEachQtyLimt(){
		m_dat=(void*)&EachQtyLimt;
		m_siz=sizeof(EachQtyLimt);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexEachQtyLimt;
		memset(&EachQtyLimt,0x00,sizeof(EachQtyLimt));	/* 每笔持仓限量 */
	}
	BCESFieldTypeQty EachQtyLimt;	/* 每笔持仓限量 */
};
/* 总持仓限量 */
class CBCESFieldTotalQtyLimt:public CBMLField
{
public:
	CBCESFieldTotalQtyLimt(){
		m_dat=(void*)&TotalQtyLimt;
		m_siz=sizeof(TotalQtyLimt);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTotalQtyLimt;
		memset(&TotalQtyLimt,0x00,sizeof(TotalQtyLimt));	/* 总持仓限量 */
	}
	BCESFieldTypeQty TotalQtyLimt;	/* 总持仓限量 */
};
/* 操作员号 */
class CBCESFieldUserID:public CBMLField
{
public:
	CBCESFieldUserID(){
		m_dat=(void*)UserID;
		m_siz=sizeof(UserID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexUserID;
		memset(UserID,0x00,sizeof(UserID));	/* 操作员号 */
	}
	BCESFieldTypeUserID UserID;	/* 操作员号 */
};
/* 叫买价2 */
class CBCESFieldBidPrice2:public CBMLField
{
public:
	CBCESFieldBidPrice2(){
		m_dat=(void*)&BidPrice2;
		m_siz=sizeof(BidPrice2);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice2;
		memset(&BidPrice2,0x00,sizeof(BidPrice2));	/* 叫买价2 */
	}
	BCESFieldTypePrice BidPrice2;	/* 叫买价2 */
};
/* 叫卖价2 */
class CBCESFieldAskPrice2:public CBMLField
{
public:
	CBCESFieldAskPrice2(){
		m_dat=(void*)&AskPrice2;
		m_siz=sizeof(AskPrice2);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice2;
		memset(&AskPrice2,0x00,sizeof(AskPrice2));	/* 叫卖价2 */
	}
	BCESFieldTypePrice AskPrice2;	/* 叫卖价2 */
};
/* 叫买量2 */
class CBCESFieldBidQty2:public CBMLField
{
public:
	CBCESFieldBidQty2(){
		m_dat=(void*)&BidQty2;
		m_siz=sizeof(BidQty2);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty2;
		memset(&BidQty2,0x00,sizeof(BidQty2));	/* 叫买量2 */
	}
	BCESFieldTypeQty BidQty2;	/* 叫买量2 */
};
/* 叫卖量2 */
class CBCESFieldAskQty2:public CBMLField
{
public:
	CBCESFieldAskQty2(){
		m_dat=(void*)&AskQty2;
		m_siz=sizeof(AskQty2);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty2;
		memset(&AskQty2,0x00,sizeof(AskQty2));	/* 叫卖量2 */
	}
	BCESFieldTypeQty AskQty2;	/* 叫卖量2 */
};
/* 叫买价3 */
class CBCESFieldBidPrice3:public CBMLField
{
public:
	CBCESFieldBidPrice3(){
		m_dat=(void*)&BidPrice3;
		m_siz=sizeof(BidPrice3);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice3;
		memset(&BidPrice3,0x00,sizeof(BidPrice3));	/* 叫买价3 */
	}
	BCESFieldTypePrice BidPrice3;	/* 叫买价3 */
};
/* 叫卖价3 */
class CBCESFieldAskPrice3:public CBMLField
{
public:
	CBCESFieldAskPrice3(){
		m_dat=(void*)&AskPrice3;
		m_siz=sizeof(AskPrice3);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice3;
		memset(&AskPrice3,0x00,sizeof(AskPrice3));	/* 叫卖价3 */
	}
	BCESFieldTypePrice AskPrice3;	/* 叫卖价3 */
};
/* 叫买量3 */
class CBCESFieldBidQty3:public CBMLField
{
public:
	CBCESFieldBidQty3(){
		m_dat=(void*)&BidQty3;
		m_siz=sizeof(BidQty3);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty3;
		memset(&BidQty3,0x00,sizeof(BidQty3));	/* 叫买量3 */
	}
	BCESFieldTypeQty BidQty3;	/* 叫买量3 */
};
/* 叫卖量3 */
class CBCESFieldAskQty3:public CBMLField
{
public:
	CBCESFieldAskQty3(){
		m_dat=(void*)&AskQty3;
		m_siz=sizeof(AskQty3);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty3;
		memset(&AskQty3,0x00,sizeof(AskQty3));	/* 叫卖量3 */
	}
	BCESFieldTypeQty AskQty3;	/* 叫卖量3 */
};
/* 叫买价4 */
class CBCESFieldBidPrice4:public CBMLField
{
public:
	CBCESFieldBidPrice4(){
		m_dat=(void*)&BidPrice4;
		m_siz=sizeof(BidPrice4);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice4;
		memset(&BidPrice4,0x00,sizeof(BidPrice4));	/* 叫买价4 */
	}
	BCESFieldTypePrice BidPrice4;	/* 叫买价4 */
};
/* 叫卖价4 */
class CBCESFieldAskPrice4:public CBMLField
{
public:
	CBCESFieldAskPrice4(){
		m_dat=(void*)&AskPrice4;
		m_siz=sizeof(AskPrice4);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice4;
		memset(&AskPrice4,0x00,sizeof(AskPrice4));	/* 叫卖价4 */
	}
	BCESFieldTypePrice AskPrice4;	/* 叫卖价4 */
};
/* 叫买量4 */
class CBCESFieldBidQty4:public CBMLField
{
public:
	CBCESFieldBidQty4(){
		m_dat=(void*)&BidQty4;
		m_siz=sizeof(BidQty4);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty4;
		memset(&BidQty4,0x00,sizeof(BidQty4));	/* 叫买量4 */
	}
	BCESFieldTypeQty BidQty4;	/* 叫买量4 */
};
/* 叫卖量4 */
class CBCESFieldAskQty4:public CBMLField
{
public:
	CBCESFieldAskQty4(){
		m_dat=(void*)&AskQty4;
		m_siz=sizeof(AskQty4);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty4;
		memset(&AskQty4,0x00,sizeof(AskQty4));	/* 叫卖量4 */
	}
	BCESFieldTypeQty AskQty4;	/* 叫卖量4 */
};
/* 叫买价5 */
class CBCESFieldBidPrice5:public CBMLField
{
public:
	CBCESFieldBidPrice5(){
		m_dat=(void*)&BidPrice5;
		m_siz=sizeof(BidPrice5);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice5;
		memset(&BidPrice5,0x00,sizeof(BidPrice5));	/* 叫买价5 */
	}
	BCESFieldTypePrice BidPrice5;	/* 叫买价5 */
};
/* 叫卖价5 */
class CBCESFieldAskPrice5:public CBMLField
{
public:
	CBCESFieldAskPrice5(){
		m_dat=(void*)&AskPrice5;
		m_siz=sizeof(AskPrice5);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice5;
		memset(&AskPrice5,0x00,sizeof(AskPrice5));	/* 叫卖价5 */
	}
	BCESFieldTypePrice AskPrice5;	/* 叫卖价5 */
};
/* 叫买量5 */
class CBCESFieldBidQty5:public CBMLField
{
public:
	CBCESFieldBidQty5(){
		m_dat=(void*)&BidQty5;
		m_siz=sizeof(BidQty5);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty5;
		memset(&BidQty5,0x00,sizeof(BidQty5));	/* 叫买量5 */
	}
	BCESFieldTypeQty BidQty5;	/* 叫买量5 */
};
/* 叫卖量5 */
class CBCESFieldAskQty5:public CBMLField
{
public:
	CBCESFieldAskQty5(){
		m_dat=(void*)&AskQty5;
		m_siz=sizeof(AskQty5);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty5;
		memset(&AskQty5,0x00,sizeof(AskQty5));	/* 叫卖量5 */
	}
	BCESFieldTypeQty AskQty5;	/* 叫卖量5 */
};
/* 系统模式 */
class CBCESFieldSysMode:public CBMLField
{
public:
	CBCESFieldSysMode(){
		m_dat=(void*)&SysMode;
		m_siz=sizeof(SysMode);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSysMode;
		memset(&SysMode,0x00,sizeof(SysMode));	/* 系统模式 */
	}
	BCESFieldTypeFlag SysMode;	/* 系统模式 */
};
/* 冻结持仓量 */
class CBCESFieldQtyFrozen:public CBMLField
{
public:
	CBCESFieldQtyFrozen(){
		m_dat=(void*)&QtyFrozen;
		m_siz=sizeof(QtyFrozen);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQtyFrozen;
		memset(&QtyFrozen,0x00,sizeof(QtyFrozen));	/* 冻结持仓量 */
	}
	BCESFieldTypeQty QtyFrozen;	/* 冻结持仓量 */
};
/* 叫买价6 */
class CBCESFieldBidPrice6:public CBMLField
{
public:
	CBCESFieldBidPrice6(){
		m_dat=(void*)&BidPrice6;
		m_siz=sizeof(BidPrice6);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice6;
		memset(&BidPrice6,0x00,sizeof(BidPrice6));	/* 叫买价6 */
	}
	BCESFieldTypePrice BidPrice6;	/* 叫买价6 */
};
/* 叫卖价6 */
class CBCESFieldAskPrice6:public CBMLField
{
public:
	CBCESFieldAskPrice6(){
		m_dat=(void*)&AskPrice6;
		m_siz=sizeof(AskPrice6);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice6;
		memset(&AskPrice6,0x00,sizeof(AskPrice6));	/* 叫卖价6 */
	}
	BCESFieldTypePrice AskPrice6;	/* 叫卖价6 */
};
/* 叫买量6 */
class CBCESFieldBidQty6:public CBMLField
{
public:
	CBCESFieldBidQty6(){
		m_dat=(void*)&BidQty6;
		m_siz=sizeof(BidQty6);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty6;
		memset(&BidQty6,0x00,sizeof(BidQty6));	/* 叫买量6 */
	}
	BCESFieldTypeQty BidQty6;	/* 叫买量6 */
};
/* 叫卖量6 */
class CBCESFieldAskQty6:public CBMLField
{
public:
	CBCESFieldAskQty6(){
		m_dat=(void*)&AskQty6;
		m_siz=sizeof(AskQty6);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty6;
		memset(&AskQty6,0x00,sizeof(AskQty6));	/* 叫卖量6 */
	}
	BCESFieldTypeQty AskQty6;	/* 叫卖量6 */
};
/* 叫买价7 */
class CBCESFieldBidPrice7:public CBMLField
{
public:
	CBCESFieldBidPrice7(){
		m_dat=(void*)&BidPrice7;
		m_siz=sizeof(BidPrice7);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice7;
		memset(&BidPrice7,0x00,sizeof(BidPrice7));	/* 叫买价7 */
	}
	BCESFieldTypePrice BidPrice7;	/* 叫买价7 */
};
/* 叫卖价7 */
class CBCESFieldAskPrice7:public CBMLField
{
public:
	CBCESFieldAskPrice7(){
		m_dat=(void*)&AskPrice7;
		m_siz=sizeof(AskPrice7);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice7;
		memset(&AskPrice7,0x00,sizeof(AskPrice7));	/* 叫卖价7 */
	}
	BCESFieldTypePrice AskPrice7;	/* 叫卖价7 */
};
/* 叫买量7 */
class CBCESFieldBidQty7:public CBMLField
{
public:
	CBCESFieldBidQty7(){
		m_dat=(void*)&BidQty7;
		m_siz=sizeof(BidQty7);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty7;
		memset(&BidQty7,0x00,sizeof(BidQty7));	/* 叫买量7 */
	}
	BCESFieldTypeQty BidQty7;	/* 叫买量7 */
};
/* 叫卖量7 */
class CBCESFieldAskQty7:public CBMLField
{
public:
	CBCESFieldAskQty7(){
		m_dat=(void*)&AskQty7;
		m_siz=sizeof(AskQty7);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty7;
		memset(&AskQty7,0x00,sizeof(AskQty7));	/* 叫卖量7 */
	}
	BCESFieldTypeQty AskQty7;	/* 叫卖量7 */
};
/* 叫买价8 */
class CBCESFieldBidPrice8:public CBMLField
{
public:
	CBCESFieldBidPrice8(){
		m_dat=(void*)&BidPrice8;
		m_siz=sizeof(BidPrice8);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice8;
		memset(&BidPrice8,0x00,sizeof(BidPrice8));	/* 叫买价8 */
	}
	BCESFieldTypePrice BidPrice8;	/* 叫买价8 */
};
/* 叫卖价8 */
class CBCESFieldAskPrice8:public CBMLField
{
public:
	CBCESFieldAskPrice8(){
		m_dat=(void*)&AskPrice8;
		m_siz=sizeof(AskPrice8);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice8;
		memset(&AskPrice8,0x00,sizeof(AskPrice8));	/* 叫卖价8 */
	}
	BCESFieldTypePrice AskPrice8;	/* 叫卖价8 */
};
/* 叫买量8 */
class CBCESFieldBidQty8:public CBMLField
{
public:
	CBCESFieldBidQty8(){
		m_dat=(void*)&BidQty8;
		m_siz=sizeof(BidQty8);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty8;
		memset(&BidQty8,0x00,sizeof(BidQty8));	/* 叫买量8 */
	}
	BCESFieldTypeQty BidQty8;	/* 叫买量8 */
};
/* 叫卖量8 */
class CBCESFieldAskQty8:public CBMLField
{
public:
	CBCESFieldAskQty8(){
		m_dat=(void*)&AskQty8;
		m_siz=sizeof(AskQty8);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty8;
		memset(&AskQty8,0x00,sizeof(AskQty8));	/* 叫卖量8 */
	}
	BCESFieldTypeQty AskQty8;	/* 叫卖量8 */
};
/* 叫买价9 */
class CBCESFieldBidPrice9:public CBMLField
{
public:
	CBCESFieldBidPrice9(){
		m_dat=(void*)&BidPrice9;
		m_siz=sizeof(BidPrice9);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice9;
		memset(&BidPrice9,0x00,sizeof(BidPrice9));	/* 叫买价9 */
	}
	BCESFieldTypePrice BidPrice9;	/* 叫买价9 */
};
/* 叫卖价9 */
class CBCESFieldAskPrice9:public CBMLField
{
public:
	CBCESFieldAskPrice9(){
		m_dat=(void*)&AskPrice9;
		m_siz=sizeof(AskPrice9);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice9;
		memset(&AskPrice9,0x00,sizeof(AskPrice9));	/* 叫卖价9 */
	}
	BCESFieldTypePrice AskPrice9;	/* 叫卖价9 */
};
/* 叫买量9 */
class CBCESFieldBidQty9:public CBMLField
{
public:
	CBCESFieldBidQty9(){
		m_dat=(void*)&BidQty9;
		m_siz=sizeof(BidQty9);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty9;
		memset(&BidQty9,0x00,sizeof(BidQty9));	/* 叫买量9 */
	}
	BCESFieldTypeQty BidQty9;	/* 叫买量9 */
};
/* 叫卖量9 */
class CBCESFieldAskQty9:public CBMLField
{
public:
	CBCESFieldAskQty9(){
		m_dat=(void*)&AskQty9;
		m_siz=sizeof(AskQty9);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty9;
		memset(&AskQty9,0x00,sizeof(AskQty9));	/* 叫卖量9 */
	}
	BCESFieldTypeQty AskQty9;	/* 叫卖量9 */
};
/* 叫买价10 */
class CBCESFieldBidPrice10:public CBMLField
{
public:
	CBCESFieldBidPrice10(){
		m_dat=(void*)&BidPrice10;
		m_siz=sizeof(BidPrice10);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidPrice10;
		memset(&BidPrice10,0x00,sizeof(BidPrice10));	/* 叫买价10 */
	}
	BCESFieldTypePrice BidPrice10;	/* 叫买价10 */
};
/* 叫卖价10 */
class CBCESFieldAskPrice10:public CBMLField
{
public:
	CBCESFieldAskPrice10(){
		m_dat=(void*)&AskPrice10;
		m_siz=sizeof(AskPrice10);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskPrice10;
		memset(&AskPrice10,0x00,sizeof(AskPrice10));	/* 叫卖价10 */
	}
	BCESFieldTypePrice AskPrice10;	/* 叫卖价10 */
};
/* 叫买量10 */
class CBCESFieldBidQty10:public CBMLField
{
public:
	CBCESFieldBidQty10(){
		m_dat=(void*)&BidQty10;
		m_siz=sizeof(BidQty10);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBidQty10;
		memset(&BidQty10,0x00,sizeof(BidQty10));	/* 叫买量10 */
	}
	BCESFieldTypeQty BidQty10;	/* 叫买量10 */
};
/* 叫卖量10 */
class CBCESFieldAskQty10:public CBMLField
{
public:
	CBCESFieldAskQty10(){
		m_dat=(void*)&AskQty10;
		m_siz=sizeof(AskQty10);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAskQty10;
		memset(&AskQty10,0x00,sizeof(AskQty10));	/* 叫卖量10 */
	}
	BCESFieldTypeQty AskQty10;	/* 叫卖量10 */
};
/* IP地址 */
class CBCESFieldIP:public CBMLField
{
public:
	CBCESFieldIP(){
		m_dat=(void*)IP;
		m_siz=sizeof(IP);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexIP;
		memset(IP,0x00,sizeof(IP));	/* IP地址 */
	}
	BCESFieldTypeIP IP;	/* IP地址 */
};
/* 挂单量排名查询请求 */
class CBCESFieldTopInvestorQueryReq:public CBMLField
{
public:
	CBCESFieldTopInvestorQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTopInvestorQueryReq;
		
	}
	
};
/* 挂单量排名 */
class CBCESFieldTopInvestor:public CBMLField
{
public:
	CBCESFieldTopInvestor(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTopInvestor;
		
	}
	
};
/* 挂单量排名列表 */
class CBCESFieldTopInvestorList:public CBMLField
{
public:
	CBCESFieldTopInvestorList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTopInvestorList;
		
	}
	
};
/* 投资者挂单查询请求 */
class CBCESFieldInvestorQuotQueryReq:public CBMLField
{
public:
	CBCESFieldInvestorQuotQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorQuotQueryReq;
		
	}
	
};
/* 挂单量排名 */
class CBCESFieldInvestorQuot:public CBMLField
{
public:
	CBCESFieldInvestorQuot(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorQuot;
		
	}
	
};
/* 挂单量排名列表 */
class CBCESFieldInvestorQuotList:public CBMLField
{
public:
	CBCESFieldInvestorQuotList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorQuotList;
		
	}
	
};
/* 排名投资者号 */
class CBCESFieldRankingInvestorID:public CBMLField
{
public:
	CBCESFieldRankingInvestorID(){
		m_dat=(void*)RankingInvestorID;
		m_siz=sizeof(RankingInvestorID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRankingInvestorID;
		memset(RankingInvestorID,0x00,sizeof(RankingInvestorID));	/* 排名投资者号 */
	}
	BCESFieldTypeInvestorID RankingInvestorID;	/* 排名投资者号 */
};
/* 条件类型 */
class CBCESFieldConditionType:public CBMLField
{
public:
	CBCESFieldConditionType(){
		m_dat=(void*)&ConditionType;
		m_siz=sizeof(ConditionType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexConditionType;
		memset(&ConditionType,0x00,sizeof(ConditionType));	/* 条件类型 */
	}
	BCESFieldTypeFlag ConditionType;	/* 条件类型 */
};
/* 条件方法 */
class CBCESFieldConditionMethod:public CBMLField
{
public:
	CBCESFieldConditionMethod(){
		m_dat=(void*)&ConditionMethod;
		m_siz=sizeof(ConditionMethod);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexConditionMethod;
		memset(&ConditionMethod,0x00,sizeof(ConditionMethod));	/* 条件方法 */
	}
	BCESFieldTypeFlag ConditionMethod;	/* 条件方法 */
};
/* 条件价格 */
class CBCESFieldConditionPrice:public CBMLField
{
public:
	CBCESFieldConditionPrice(){
		m_dat=(void*)&ConditionPrice;
		m_siz=sizeof(ConditionPrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexConditionPrice;
		memset(&ConditionPrice,0x00,sizeof(ConditionPrice));	/* 条件价格 */
	}
	BCESFieldTypePrice ConditionPrice;	/* 条件价格 */
};
/* 品种大类 */
class CBCESFieldGoodsName:public CBMLField
{
public:
	CBCESFieldGoodsName(){
		m_dat=(void*)GoodsName;
		m_siz=sizeof(GoodsName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexGoodsName;
		memset(GoodsName,0x00,sizeof(GoodsName));	/* 品种大类 */
	}
	BCESFieldTypeGoodsName GoodsName;	/* 品种大类 */
};
/* 交易时间 */
class CBCESFieldTradeTime:public CBMLField
{
public:
	CBCESFieldTradeTime(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeTime;
		
	}
	
};
/* 开始时间 */
class CBCESFieldTimeBegin:public CBMLField
{
public:
	CBCESFieldTimeBegin(){
		m_dat=(void*)TimeBegin;
		m_siz=sizeof(TimeBegin);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTimeBegin;
		memset(TimeBegin,0x00,sizeof(TimeBegin));	/* 开始时间 */
	}
	BCESFieldTypeTime TimeBegin;	/* 开始时间 */
};
/* 结束时间 */
class CBCESFieldTimeEnd:public CBMLField
{
public:
	CBCESFieldTimeEnd(){
		m_dat=(void*)TimeEnd;
		m_siz=sizeof(TimeEnd);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTimeEnd;
		memset(TimeEnd,0x00,sizeof(TimeEnd));	/* 结束时间 */
	}
	BCESFieldTypeTime TimeEnd;	/* 结束时间 */
};
/* 支行名称 */
class CBCESFieldReceiveBranchName:public CBMLField
{
public:
	CBCESFieldReceiveBranchName(){
		m_dat=(void*)ReceiveBranchName;
		m_siz=sizeof(ReceiveBranchName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReceiveBranchName;
		memset(ReceiveBranchName,0x00,sizeof(ReceiveBranchName));	/* 支行名称 */
	}
	BCESFieldTypeAddress ReceiveBranchName;	/* 支行名称 */
};
/* 开户省份 */
class CBCESFieldReceiveProvice:public CBMLField
{
public:
	CBCESFieldReceiveProvice(){
		m_dat=(void*)ReceiveProvice;
		m_siz=sizeof(ReceiveProvice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReceiveProvice;
		memset(ReceiveProvice,0x00,sizeof(ReceiveProvice));	/* 开户省份 */
	}
	BCESFieldTypeName ReceiveProvice;	/* 开户省份 */
};
/* 开户市 */
class CBCESFieldReceiveCity:public CBMLField
{
public:
	CBCESFieldReceiveCity(){
		m_dat=(void*)ReceiveCity;
		m_siz=sizeof(ReceiveCity);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexReceiveCity;
		memset(ReceiveCity,0x00,sizeof(ReceiveCity));	/* 开户市 */
	}
	BCESFieldTypeName ReceiveCity;	/* 开户市 */
};
/* 签约状态 */
class CBCESFieldAccountBindStatus:public CBMLField
{
public:
	CBCESFieldAccountBindStatus(){
		m_dat=(void*)&AccountBindStatus;
		m_siz=sizeof(AccountBindStatus);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindStatus;
		memset(&AccountBindStatus,0x00,sizeof(AccountBindStatus));	/* 签约状态 */
	}
	BCESFieldTypeFlag AccountBindStatus;	/* 签约状态 */
};
/* 网址 */
class CBCESFieldAccountBindURL:public CBMLField
{
public:
	CBCESFieldAccountBindURL(){
		m_dat=(void*)AccountBindURL;
		m_siz=sizeof(AccountBindURL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindURL;
		memset(AccountBindURL,0x00,sizeof(AccountBindURL));	/* 网址 */
	}
	BCESFieldTypeURL AccountBindURL;	/* 网址 */
};
/* 签约状态描述 */
class CBCESFieldAccountBindStatusDesc:public CBMLField
{
public:
	CBCESFieldAccountBindStatusDesc(){
		m_dat=(void*)AccountBindStatusDesc;
		m_siz=sizeof(AccountBindStatusDesc);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountBindStatusDesc;
		memset(AccountBindStatusDesc,0x00,sizeof(AccountBindStatusDesc));	/* 签约状态描述 */
	}
	BCESFieldTypeFundIOStatusDesc AccountBindStatusDesc;	/* 签约状态描述 */
};
/* 产品编号 */
class CBCESFieldProductType:public CBMLField
{
public:
	CBCESFieldProductType(){
		m_dat=(void*)&ProductType;
		m_siz=sizeof(ProductType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexProductType;
		memset(&ProductType,0x00,sizeof(ProductType));	/* 产品编号 */
	}
	BCESFieldTypeFlag ProductType;	/* 产品编号 */
};
/* 产品版本号 */
class CBCESFieldProductVersion:public CBMLField
{
public:
	CBCESFieldProductVersion(){
		m_dat=(void*)&ProductVersion;
		m_siz=sizeof(ProductVersion);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexProductVersion;
		memset(&ProductVersion,0x00,sizeof(ProductVersion));	/* 产品版本号 */
	}
	BCESFieldTypeVersionNo ProductVersion;	/* 产品版本号 */
};
/* 交收交割需求 */
class CBCESFieldDeliveryDemand:public CBMLField
{
public:
	CBCESFieldDeliveryDemand(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryDemand;
		
	}
	
};
/* 企业名称 */
class CBCESFieldCompanyName:public CBMLField
{
public:
	CBCESFieldCompanyName(){
		m_dat=(void*)CompanyName;
		m_siz=sizeof(CompanyName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCompanyName;
		memset(CompanyName,0x00,sizeof(CompanyName));	/* 企业名称 */
	}
	BCESFieldTypeName CompanyName;	/* 企业名称 */
};
/* 联系人名称 */
class CBCESFieldLiaisonName:public CBMLField
{
public:
	CBCESFieldLiaisonName(){
		m_dat=(void*)LiaisonName;
		m_siz=sizeof(LiaisonName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLiaisonName;
		memset(LiaisonName,0x00,sizeof(LiaisonName));	/* 联系人名称 */
	}
	BCESFieldTypeName LiaisonName;	/* 联系人名称 */
};
/* 联系电话 */
class CBCESFieldLiaisonNumber:public CBMLField
{
public:
	CBCESFieldLiaisonNumber(){
		m_dat=(void*)LiaisonNumber;
		m_siz=sizeof(LiaisonNumber);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLiaisonNumber;
		memset(LiaisonNumber,0x00,sizeof(LiaisonNumber));	/* 联系电话 */
	}
	BCESFieldTypePhoneNo LiaisonNumber;	/* 联系电话 */
};
/* 联系地址 */
class CBCESFieldLiaisonAddress:public CBMLField
{
public:
	CBCESFieldLiaisonAddress(){
		m_dat=(void*)LiaisonAddress;
		m_siz=sizeof(LiaisonAddress);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexLiaisonAddress;
		memset(LiaisonAddress,0x00,sizeof(LiaisonAddress));	/* 联系地址 */
	}
	BCESFieldTypeAddress LiaisonAddress;	/* 联系地址 */
};
/* 保守数量 */
class CBCESFieldGuaranteedQty:public CBMLField
{
public:
	CBCESFieldGuaranteedQty(){
		m_dat=(void*)&GuaranteedQty;
		m_siz=sizeof(GuaranteedQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexGuaranteedQty;
		memset(&GuaranteedQty,0x00,sizeof(GuaranteedQty));	/* 保守数量 */
	}
	BCESFieldTypeQty GuaranteedQty;	/* 保守数量 */
};
/* 一般数量 */
class CBCESFieldGeneralQty:public CBMLField
{
public:
	CBCESFieldGeneralQty(){
		m_dat=(void*)&GeneralQty;
		m_siz=sizeof(GeneralQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexGeneralQty;
		memset(&GeneralQty,0x00,sizeof(GeneralQty));	/* 一般数量 */
	}
	BCESFieldTypeQty GeneralQty;	/* 一般数量 */
};
/* 风险数量 */
class CBCESFieldRiskQty:public CBMLField
{
public:
	CBCESFieldRiskQty(){
		m_dat=(void*)&RiskQty;
		m_siz=sizeof(RiskQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexRiskQty;
		memset(&RiskQty,0x00,sizeof(RiskQty));	/* 风险数量 */
	}
	BCESFieldTypeQty RiskQty;	/* 风险数量 */
};
/* 银行名称 */
class CBCESFieldBankName:public CBMLField
{
public:
	CBCESFieldBankName(){
		m_dat=(void*)BankName;
		m_siz=sizeof(BankName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBankName;
		memset(BankName,0x00,sizeof(BankName));	/* 银行名称 */
	}
	BCESFieldTypeName BankName;	/* 银行名称 */
};
/* 发票抬头 */
class CBCESFieldInvoiceTitle:public CBMLField
{
public:
	CBCESFieldInvoiceTitle(){
		m_dat=(void*)InvoiceTitle;
		m_siz=sizeof(InvoiceTitle);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvoiceTitle;
		memset(InvoiceTitle,0x00,sizeof(InvoiceTitle));	/* 发票抬头 */
	}
	BCESFieldTypeTitle InvoiceTitle;	/* 发票抬头 */
};
/* 交收交割编号 */
class CBCESFieldDeliveryDemandID:public CBMLField
{
public:
	CBCESFieldDeliveryDemandID(){
		m_dat=(void*)DeliveryDemandID;
		m_siz=sizeof(DeliveryDemandID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryDemandID;
		memset(DeliveryDemandID,0x00,sizeof(DeliveryDemandID));	/* 交收交割编号 */
	}
	BCESFieldTypeDeliveryID DeliveryDemandID;	/* 交收交割编号 */
};
/* 交收交割状态 */
class CBCESFieldDeliveryStatus:public CBMLField
{
public:
	CBCESFieldDeliveryStatus(){
		m_dat=(void*)&DeliveryStatus;
		m_siz=sizeof(DeliveryStatus);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryStatus;
		memset(&DeliveryStatus,0x00,sizeof(DeliveryStatus));	/* 交收交割状态 */
	}
	BCESFieldTypeFlag DeliveryStatus;	/* 交收交割状态 */
};
/* 交收交割需求请求 */
class CBCESFieldDeliveryDemandQueryReq:public CBMLField
{
public:
	CBCESFieldDeliveryDemandQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryDemandQueryReq;
		
	}
	
};
/* 交收交割需求应答 */
class CBCESFieldDeliveryDemandQueryRsp:public CBMLField
{
public:
	CBCESFieldDeliveryDemandQueryRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryDemandQueryRsp;
		
	}
	
};
/* 发票标识 */
class CBCESFieldInvoiceFlag:public CBMLField
{
public:
	CBCESFieldInvoiceFlag(){
		m_dat=(void*)&InvoiceFlag;
		m_siz=sizeof(InvoiceFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvoiceFlag;
		memset(&InvoiceFlag,0x00,sizeof(InvoiceFlag));	/* 发票标识 */
	}
	BCESFieldTypeFlag InvoiceFlag;	/* 发票标识 */
};
/* 发票类型 */
class CBCESFieldInvoiceType:public CBMLField
{
public:
	CBCESFieldInvoiceType(){
		m_dat=(void*)&InvoiceType;
		m_siz=sizeof(InvoiceType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvoiceType;
		memset(&InvoiceType,0x00,sizeof(InvoiceType));	/* 发票类型 */
	}
	BCESFieldTypeFlag InvoiceType;	/* 发票类型 */
};
/* 证件类型 */
class CBCESFieldCredentialType:public CBMLField
{
public:
	CBCESFieldCredentialType(){
		m_dat=(void*)&CredentialType;
		m_siz=sizeof(CredentialType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCredentialType;
		memset(&CredentialType,0x00,sizeof(CredentialType));	/* 证件类型 */
	}
	BCESFieldTypeFlag CredentialType;	/* 证件类型 */
};
/* 证件号 */
class CBCESFieldCredentialNo:public CBMLField
{
public:
	CBCESFieldCredentialNo(){
		m_dat=(void*)CredentialNo;
		m_siz=sizeof(CredentialNo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCredentialNo;
		memset(CredentialNo,0x00,sizeof(CredentialNo));	/* 证件号 */
	}
	BCESFieldTypeCredentialNo CredentialNo;	/* 证件号 */
};
/* 电子邮箱 */
class CBCESFieldEmail:public CBMLField
{
public:
	CBCESFieldEmail(){
		m_dat=(void*)Email;
		m_siz=sizeof(Email);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexEmail;
		memset(Email,0x00,sizeof(Email));	/* 电子邮箱 */
	}
	BCESFieldTypeEmail Email;	/* 电子邮箱 */
};
/* 邮编 */
class CBCESFieldPostCode:public CBMLField
{
public:
	CBCESFieldPostCode(){
		m_dat=(void*)PostCode;
		m_siz=sizeof(PostCode);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPostCode;
		memset(PostCode,0x00,sizeof(PostCode));	/* 邮编 */
	}
	BCESFieldTypePostCode PostCode;	/* 邮编 */
};
/* 银行帐号 */
class CBCESFieldBankAccountID:public CBMLField
{
public:
	CBCESFieldBankAccountID(){
		m_dat=(void*)BankAccountID;
		m_siz=sizeof(BankAccountID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBankAccountID;
		memset(BankAccountID,0x00,sizeof(BankAccountID));	/* 银行帐号 */
	}
	BCESFieldTypeBankAccountID BankAccountID;	/* 银行帐号 */
};
/* 银行户名及账号 */
class CBCESFieldBankNameAccountID:public CBMLField
{
public:
	CBCESFieldBankNameAccountID(){
		m_dat=(void*)BankNameAccountID;
		m_siz=sizeof(BankNameAccountID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBankNameAccountID;
		memset(BankNameAccountID,0x00,sizeof(BankNameAccountID));	/* 银行户名及账号 */
	}
	BCESFieldTypeBankNameAccountID BankNameAccountID;	/* 银行户名及账号 */
};
/* 交收交割申请编号 */
class CBCESFieldDeliveryApplyID:public CBMLField
{
public:
	CBCESFieldDeliveryApplyID(){
		m_dat=(void*)DeliveryApplyID;
		m_siz=sizeof(DeliveryApplyID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyID;
		memset(DeliveryApplyID,0x00,sizeof(DeliveryApplyID));	/* 交收交割申请编号 */
	}
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
};
/* 交收交割地址 */
class CBCESFieldDeliveryAddress:public CBMLField
{
public:
	CBCESFieldDeliveryAddress(){
		m_dat=(void*)DeliveryAddress;
		m_siz=sizeof(DeliveryAddress);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryAddress;
		memset(DeliveryAddress,0x00,sizeof(DeliveryAddress));	/* 交收交割地址 */
	}
	BCESFieldTypeDeliveryID DeliveryAddress;	/* 交收交割地址 */
};
/* 申请日期 */
class CBCESFieldApplyDate:public CBMLField
{
public:
	CBCESFieldApplyDate(){
		m_dat=(void*)ApplyDate;
		m_siz=sizeof(ApplyDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexApplyDate;
		memset(ApplyDate,0x00,sizeof(ApplyDate));	/* 申请日期 */
	}
	BCESFieldTypeDate ApplyDate;	/* 申请日期 */
};
/* 确认日期 */
class CBCESFieldVerifedDate:public CBMLField
{
public:
	CBCESFieldVerifedDate(){
		m_dat=(void*)VerifedDate;
		m_siz=sizeof(VerifedDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexVerifedDate;
		memset(VerifedDate,0x00,sizeof(VerifedDate));	/* 确认日期 */
	}
	BCESFieldTypeDate VerifedDate;	/* 确认日期 */
};
/* 成交日期 */
class CBCESFieldCompletedDate:public CBMLField
{
public:
	CBCESFieldCompletedDate(){
		m_dat=(void*)CompletedDate;
		m_siz=sizeof(CompletedDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCompletedDate;
		memset(CompletedDate,0x00,sizeof(CompletedDate));	/* 成交日期 */
	}
	BCESFieldTypeDate CompletedDate;	/* 成交日期 */
};
/* 公司地址 */
class CBCESFieldCompanyAddress:public CBMLField
{
public:
	CBCESFieldCompanyAddress(){
		m_dat=(void*)CompanyAddress;
		m_siz=sizeof(CompanyAddress);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCompanyAddress;
		memset(CompanyAddress,0x00,sizeof(CompanyAddress));	/* 公司地址 */
	}
	BCESFieldTypeAddress CompanyAddress;	/* 公司地址 */
};
/* 税务登记号 */
class CBCESFieldTaxNo:public CBMLField
{
public:
	CBCESFieldTaxNo(){
		m_dat=(void*)TaxNo;
		m_siz=sizeof(TaxNo);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTaxNo;
		memset(TaxNo,0x00,sizeof(TaxNo));	/* 税务登记号 */
	}
	BCESFieldTypeTaxNo TaxNo;	/* 税务登记号 */
};
/* 发票 */
class CBCESFieldInvoice:public CBMLField
{
public:
	CBCESFieldInvoice(){
		m_dat=(void*)Invoice;
		m_siz=sizeof(Invoice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvoice;
		memset(Invoice,0x00,sizeof(Invoice));	/* 发票 */
	}
	BCESFieldTypeContent Invoice;	/* 发票 */
};
/* 交收交割申请增加请求 */
class CBCESFieldDeliveryApplyAddReq:public CBMLField
{
public:
	CBCESFieldDeliveryApplyAddReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyAddReq;
		
	}
	
};
/* 交收交割申请增加应答 */
class CBCESFieldDeliveryApplyAddRsp:public CBMLField
{
public:
	CBCESFieldDeliveryApplyAddRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyAddRsp;
		
	}
	
};
/* 交收交割申请修改请求 */
class CBCESFieldDeliveryApplyModifyReq:public CBMLField
{
public:
	CBCESFieldDeliveryApplyModifyReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyModifyReq;
		
	}
	
};
/* 交收交割申请修改应答 */
class CBCESFieldDeliveryApplyModifyRsp:public CBMLField
{
public:
	CBCESFieldDeliveryApplyModifyRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyModifyRsp;
		
	}
	
};
/* 交收交割申请 */
class CBCESFieldDeliveryApply:public CBMLField
{
public:
	CBCESFieldDeliveryApply(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApply;
		
	}
	
};
/* 交收交割申请查询请求 */
class CBCESFieldDeliveryApplyQueryReq:public CBMLField
{
public:
	CBCESFieldDeliveryApplyQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyQueryReq;
		
	}
	
};
/* 交收交割申请查询应答 */
class CBCESFieldDeliveryApplyQueryRsp:public CBMLField
{
public:
	CBCESFieldDeliveryApplyQueryRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyQueryRsp;
		
	}
	
};
/* 交收交割申请列表 */
class CBCESFieldDeliveryApplyList:public CBMLField
{
public:
	CBCESFieldDeliveryApplyList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyList;
		
	}
	
};
/* 交收交割申请删除请求 */
class CBCESFieldDeliveryApplyDeleteReq:public CBMLField
{
public:
	CBCESFieldDeliveryApplyDeleteReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyDeleteReq;
		
	}
	
};
/* 交收交割申请删除应答 */
class CBCESFieldDeliveryApplyDeleteRsp:public CBMLField
{
public:
	CBCESFieldDeliveryApplyDeleteRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexDeliveryApplyDeleteRsp;
		
	}
	
};
/* 支付服务类型 */
class CBCESFieldPayServerType:public CBMLField
{
public:
	CBCESFieldPayServerType(){
		m_dat=(void*)&PayServerType;
		m_siz=sizeof(PayServerType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPayServerType;
		memset(&PayServerType,0x00,sizeof(PayServerType));	/* 支付服务类型 */
	}
	BCESFieldTypeFlag PayServerType;	/* 支付服务类型 */
};
/* 成交明细查询请求 */
class CBCESFieldTradeDetailDataQueryReq:public CBMLField
{
public:
	CBCESFieldTradeDetailDataQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeDetailDataQueryReq;
		
	}
	
};
/* 公司电话 */
class CBCESFieldCompanyNumber:public CBMLField
{
public:
	CBCESFieldCompanyNumber(){
		m_dat=(void*)CompanyNumber;
		m_siz=sizeof(CompanyNumber);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCompanyNumber;
		memset(CompanyNumber,0x00,sizeof(CompanyNumber));	/* 公司电话 */
	}
	BCESFieldTypePhoneNo CompanyNumber;	/* 公司电话 */
};
/* 成交明细列表 */
class CBCESFieldTradeDetailDataList:public CBMLField
{
public:
	CBCESFieldTradeDetailDataList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTradeDetailDataList;
		
	}
	
};
/* 顾问号 */
class CBCESFieldAdviserID:public CBMLField
{
public:
	CBCESFieldAdviserID(){
		m_dat=(void*)AdviserID;
		m_siz=sizeof(AdviserID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAdviserID;
		memset(AdviserID,0x00,sizeof(AdviserID));	/* 顾问号 */
	}
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
};
/* 提问内容 */
class CBCESFieldQuestionContent:public CBMLField
{
public:
	CBCESFieldQuestionContent(){
		m_dat=(void*)QuestionContent;
		m_siz=sizeof(QuestionContent);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuestionContent;
		memset(QuestionContent,0x00,sizeof(QuestionContent));	/* 提问内容 */
	}
	BCESFieldTypeQuesAnswContent QuestionContent;	/* 提问内容 */
};
/* 提问日期 */
class CBCESFieldQuestionDate:public CBMLField
{
public:
	CBCESFieldQuestionDate(){
		m_dat=(void*)QuestionDate;
		m_siz=sizeof(QuestionDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuestionDate;
		memset(QuestionDate,0x00,sizeof(QuestionDate));	/* 提问日期 */
	}
	BCESFieldTypeDate QuestionDate;	/* 提问日期 */
};
/* 提问时间 */
class CBCESFieldQuestionTime:public CBMLField
{
public:
	CBCESFieldQuestionTime(){
		m_dat=(void*)QuestionTime;
		m_siz=sizeof(QuestionTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuestionTime;
		memset(QuestionTime,0x00,sizeof(QuestionTime));	/* 提问时间 */
	}
	BCESFieldTypeTime QuestionTime;	/* 提问时间 */
};
/* 回答内容 */
class CBCESFieldAnswerContent:public CBMLField
{
public:
	CBCESFieldAnswerContent(){
		m_dat=(void*)AnswerContent;
		m_siz=sizeof(AnswerContent);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAnswerContent;
		memset(AnswerContent,0x00,sizeof(AnswerContent));	/* 回答内容 */
	}
	BCESFieldTypeQuesAnswContent AnswerContent;	/* 回答内容 */
};
/* 回答日期 */
class CBCESFieldAnswerDate:public CBMLField
{
public:
	CBCESFieldAnswerDate(){
		m_dat=(void*)AnswerDate;
		m_siz=sizeof(AnswerDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAnswerDate;
		memset(AnswerDate,0x00,sizeof(AnswerDate));	/* 回答日期 */
	}
	BCESFieldTypeDate AnswerDate;	/* 回答日期 */
};
/* 回答时间 */
class CBCESFieldAnswerTime:public CBMLField
{
public:
	CBCESFieldAnswerTime(){
		m_dat=(void*)AnswerTime;
		m_siz=sizeof(AnswerTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAnswerTime;
		memset(AnswerTime,0x00,sizeof(AnswerTime));	/* 回答时间 */
	}
	BCESFieldTypeTime AnswerTime;	/* 回答时间 */
};
/* 提问编号 */
class CBCESFieldQuestionID:public CBMLField
{
public:
	CBCESFieldQuestionID(){
		m_dat=(void*)QuestionID;
		m_siz=sizeof(QuestionID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuestionID;
		memset(QuestionID,0x00,sizeof(QuestionID));	/* 提问编号 */
	}
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
};
/* 提问/回答标志 */
class CBCESFieldQuesAnswFlag:public CBMLField
{
public:
	CBCESFieldQuesAnswFlag(){
		m_dat=(void*)&QuesAnswFlag;
		m_siz=sizeof(QuesAnswFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuesAnswFlag;
		memset(&QuesAnswFlag,0x00,sizeof(QuesAnswFlag));	/* 提问/回答标志 */
	}
	BCESFieldTypeFlag QuesAnswFlag;	/* 提问/回答标志 */
};
/* 提问/回答内容 */
class CBCESFieldQuesAnswContent:public CBMLField
{
public:
	CBCESFieldQuesAnswContent(){
		m_dat=(void*)QuesAnswContent;
		m_siz=sizeof(QuesAnswContent);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuesAnswContent;
		memset(QuesAnswContent,0x00,sizeof(QuesAnswContent));	/* 提问/回答内容 */
	}
	BCESFieldTypeQuesAnswContent QuesAnswContent;	/* 提问/回答内容 */
};
/* 提问/回答日期 */
class CBCESFieldQuesAnswDate:public CBMLField
{
public:
	CBCESFieldQuesAnswDate(){
		m_dat=(void*)QuesAnswDate;
		m_siz=sizeof(QuesAnswDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuesAnswDate;
		memset(QuesAnswDate,0x00,sizeof(QuesAnswDate));	/* 提问/回答日期 */
	}
	BCESFieldTypeDate QuesAnswDate;	/* 提问/回答日期 */
};
/* 提问/回答时间 */
class CBCESFieldQuesAnswTime:public CBMLField
{
public:
	CBCESFieldQuesAnswTime(){
		m_dat=(void*)QuesAnswTime;
		m_siz=sizeof(QuesAnswTime);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuesAnswTime;
		memset(QuesAnswTime,0x00,sizeof(QuesAnswTime));	/* 提问/回答时间 */
	}
	BCESFieldTypeTime QuesAnswTime;	/* 提问/回答时间 */
};
/* 投资者顾问标志 */
class CBCESFieldInvestorAdviserFlag:public CBMLField
{
public:
	CBCESFieldInvestorAdviserFlag(){
		m_dat=(void*)&InvestorAdviserFlag;
		m_siz=sizeof(InvestorAdviserFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorAdviserFlag;
		memset(&InvestorAdviserFlag,0x00,sizeof(InvestorAdviserFlag));	/* 投资者顾问标志 */
	}
	BCESFieldTypeFlag InvestorAdviserFlag;	/* 投资者顾问标志 */
};
/* 行情顾问提问/回答请求 */
class CBCESFieldQuotAdviserQuesAnswReq:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesAnswReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesAnswReq;
		
	}
	
};
/* 行情顾问提问/回答应答 */
class CBCESFieldQuotAdviserQuesAnswRsp:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesAnswRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesAnswRsp;
		
	}
	
};
/* 行情顾问提问历史查询请求 */
class CBCESFieldQuotAdviserQuesHisQueryReq:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesHisQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesHisQueryReq;
		
	}
	
};
/* 行情顾问提问历史查询应答 */
class CBCESFieldQuotAdviserQuesHisQueryRsp:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesHisQueryRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesHisQueryRsp;
		
	}
	
};
/* 行情顾问提问历史查询列表 */
class CBCESFieldQuotAdviserQuesHisList:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesHisList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesHisList;
		
	}
	
};
/* 行情顾问提问查询请求 */
class CBCESFieldQuotAdviserQuesQueryReq:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesQueryReq;
		
	}
	
};
/* 行情顾问提问查询应答 */
class CBCESFieldQuotAdviserQuesQueryRsp:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesQueryRsp(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesQueryRsp;
		
	}
	
};
/* 行情顾问提问查询列表 */
class CBCESFieldQuotAdviserQuesQuerylist:public CBMLField
{
public:
	CBCESFieldQuotAdviserQuesQuerylist(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexQuotAdviserQuesQuerylist;
		
	}
	
};
/* 板块 */
class CBCESFieldPlateName:public CBMLField
{
public:
	CBCESFieldPlateName(){
		m_dat=(void*)PlateName;
		m_siz=sizeof(PlateName);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPlateName;
		memset(PlateName,0x00,sizeof(PlateName));	/* 板块 */
	}
	BCESFieldTypePlateName PlateName;	/* 板块 */
};
/* 昨买持仓量 */
class CBCESFieldPreBuyQty:public CBMLField
{
public:
	CBCESFieldPreBuyQty(){
		m_dat=(void*)&PreBuyQty;
		m_siz=sizeof(PreBuyQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreBuyQty;
		memset(&PreBuyQty,0x00,sizeof(PreBuyQty));	/* 昨买持仓量 */
	}
	BCESFieldTypeQty PreBuyQty;	/* 昨买持仓量 */
};
/* 昨卖持仓量 */
class CBCESFieldPreSellQty:public CBMLField
{
public:
	CBCESFieldPreSellQty(){
		m_dat=(void*)&PreSellQty;
		m_siz=sizeof(PreSellQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreSellQty;
		memset(&PreSellQty,0x00,sizeof(PreSellQty));	/* 昨卖持仓量 */
	}
	BCESFieldTypeQty PreSellQty;	/* 昨卖持仓量 */
};
/* 今买持仓量 */
class CBCESFieldTodayBuyQty:public CBMLField
{
public:
	CBCESFieldTodayBuyQty(){
		m_dat=(void*)&TodayBuyQty;
		m_siz=sizeof(TodayBuyQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTodayBuyQty;
		memset(&TodayBuyQty,0x00,sizeof(TodayBuyQty));	/* 今买持仓量 */
	}
	BCESFieldTypeQty TodayBuyQty;	/* 今买持仓量 */
};
/* 今卖持仓量 */
class CBCESFieldTodaySellQty:public CBMLField
{
public:
	CBCESFieldTodaySellQty(){
		m_dat=(void*)&TodaySellQty;
		m_siz=sizeof(TodaySellQty);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTodaySellQty;
		memset(&TodaySellQty,0x00,sizeof(TodaySellQty));	/* 今卖持仓量 */
	}
	BCESFieldTypeQty TodaySellQty;	/* 今卖持仓量 */
};
/* 今买冻结持仓量 */
class CBCESFieldTodayBuyQtyFrozen:public CBMLField
{
public:
	CBCESFieldTodayBuyQtyFrozen(){
		m_dat=(void*)&TodayBuyQtyFrozen;
		m_siz=sizeof(TodayBuyQtyFrozen);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTodayBuyQtyFrozen;
		memset(&TodayBuyQtyFrozen,0x00,sizeof(TodayBuyQtyFrozen));	/* 今买冻结持仓量 */
	}
	BCESFieldTypeQty TodayBuyQtyFrozen;	/* 今买冻结持仓量 */
};
/* 今卖冻结持仓量 */
class CBCESFieldTodaySellQtyFrozen:public CBMLField
{
public:
	CBCESFieldTodaySellQtyFrozen(){
		m_dat=(void*)&TodaySellQtyFrozen;
		m_siz=sizeof(TodaySellQtyFrozen);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTodaySellQtyFrozen;
		memset(&TodaySellQtyFrozen,0x00,sizeof(TodaySellQtyFrozen));	/* 今卖冻结持仓量 */
	}
	BCESFieldTypeQty TodaySellQtyFrozen;	/* 今卖冻结持仓量 */
};
/* 交易所号 */
class CBCESFieldExchangeID:public CBMLField
{
public:
	CBCESFieldExchangeID(){
		m_dat=(void*)ExchangeID;
		m_siz=sizeof(ExchangeID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexExchangeID;
		memset(ExchangeID,0x00,sizeof(ExchangeID));	/* 交易所号 */
	}
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};
/* 会话编号 */
class CBCESFieldSessionID:public CBMLField
{
public:
	CBCESFieldSessionID(){
		m_dat=(void*)&SessionID;
		m_siz=sizeof(SessionID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexSessionID;
		memset(&SessionID,0x00,sizeof(SessionID));	/* 会话编号 */
	}
	BCESFieldTypeSessionID SessionID;	/* 会话编号 */
};
/* 报单引用 */
class CBCESFieldOrderRef:public CBMLField
{
public:
	CBCESFieldOrderRef(){
		m_dat=(void*)OrderRef;
		m_siz=sizeof(OrderRef);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderRef;
		memset(OrderRef,0x00,sizeof(OrderRef));	/* 报单引用 */
	}
	BCESFieldTypeOrderRef OrderRef;	/* 报单引用 */
};
/* 建仓价 */
class CBCESFieldCreatePrice:public CBMLField
{
public:
	CBCESFieldCreatePrice(){
		m_dat=(void*)&CreatePrice;
		m_siz=sizeof(CreatePrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCreatePrice;
		memset(&CreatePrice,0x00,sizeof(CreatePrice));	/* 建仓价 */
	}
	BCESFieldTypePrice CreatePrice;	/* 建仓价 */
};
/* 历史平仓盈亏 */
class CBCESFieldHistoryClosedPL:public CBMLField
{
public:
	CBCESFieldHistoryClosedPL(){
		m_dat=(void*)&HistoryClosedPL;
		m_siz=sizeof(HistoryClosedPL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexHistoryClosedPL;
		memset(&HistoryClosedPL,0x00,sizeof(HistoryClosedPL));	/* 历史平仓盈亏 */
	}
	BCESFieldTypeAmount HistoryClosedPL;	/* 历史平仓盈亏 */
};
/* 投资者角色 */
class CBCESFieldInvestorRole:public CBMLField
{
public:
	CBCESFieldInvestorRole(){
		m_dat=(void*)&InvestorRole;
		m_siz=sizeof(InvestorRole);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorRole;
		memset(&InvestorRole,0x00,sizeof(InvestorRole));	/* 投资者角色 */
	}
	BCESFieldTypeFlag InvestorRole;	/* 投资者角色 */
};
/* 投资者标志 */
class CBCESFieldInvestorFlag:public CBMLField
{
public:
	CBCESFieldInvestorFlag(){
		m_dat=(void*)&InvestorFlag;
		m_siz=sizeof(InvestorFlag);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexInvestorFlag;
		memset(&InvestorFlag,0x00,sizeof(InvestorFlag));	/* 投资者标志 */
	}
	BCESFieldTypeFlag InvestorFlag;	/* 投资者标志 */
};
/* 支付流水号 */
class CBCESFieldPaySeqno:public CBMLField
{
public:
	CBCESFieldPaySeqno(){
		m_dat=(void*)PaySeqno;
		m_siz=sizeof(PaySeqno);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPaySeqno;
		memset(PaySeqno,0x00,sizeof(PaySeqno));	/* 支付流水号 */
	}
	BCESFieldTypePaySeqno PaySeqno;	/* 支付流水号 */
};
/* 上日剩余数量 */
class CBCESFieldPreQtyLeft:public CBMLField
{
public:
	CBCESFieldPreQtyLeft(){
		m_dat=(void*)&PreQtyLeft;
		m_siz=sizeof(PreQtyLeft);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreQtyLeft;
		memset(&PreQtyLeft,0x00,sizeof(PreQtyLeft));	/* 上日剩余数量 */
	}
	BCESFieldTypeQty PreQtyLeft;	/* 上日剩余数量 */
};
/* 建仓交易日期 */
class CBCESFieldCreateTradeDate:public CBMLField
{
public:
	CBCESFieldCreateTradeDate(){
		m_dat=(void*)CreateTradeDate;
		m_siz=sizeof(CreateTradeDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCreateTradeDate;
		memset(CreateTradeDate,0x00,sizeof(CreateTradeDate));	/* 建仓交易日期 */
	}
	BCESFieldTypeDate CreateTradeDate;	/* 建仓交易日期 */
};
/* 平仓交易日期 */
class CBCESFieldClosedTradeDate:public CBMLField
{
public:
	CBCESFieldClosedTradeDate(){
		m_dat=(void*)ClosedTradeDate;
		m_siz=sizeof(ClosedTradeDate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexClosedTradeDate;
		memset(ClosedTradeDate,0x00,sizeof(ClosedTradeDate));	/* 平仓交易日期 */
	}
	BCESFieldTypeDate ClosedTradeDate;	/* 平仓交易日期 */
};
/* 平仓订单号 */
class CBCESFieldClosedOrderID:public CBMLField
{
public:
	CBCESFieldClosedOrderID(){
		m_dat=(void*)ClosedOrderID;
		m_siz=sizeof(ClosedOrderID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexClosedOrderID;
		memset(ClosedOrderID,0x00,sizeof(ClosedOrderID));	/* 平仓订单号 */
	}
	BCESFieldTypeOrderID ClosedOrderID;	/* 平仓订单号 */
};
/* 平仓成交号 */
class CBCESFieldClosedMatchID:public CBMLField
{
public:
	CBCESFieldClosedMatchID(){
		m_dat=(void*)ClosedMatchID;
		m_siz=sizeof(ClosedMatchID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexClosedMatchID;
		memset(ClosedMatchID,0x00,sizeof(ClosedMatchID));	/* 平仓成交号 */
	}
	BCESFieldTypeMatchID ClosedMatchID;	/* 平仓成交号 */
};
/* 报单账号 */
class CBCESFieldAccountID:public CBMLField
{
public:
	CBCESFieldAccountID(){
		m_dat=(void*)AccountID;
		m_siz=sizeof(AccountID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountID;
		memset(AccountID,0x00,sizeof(AccountID));	/* 报单账号 */
	}
	BCESFieldTypeAccountID AccountID;	/* 报单账号 */
};
/* 状态说明 */
class CBCESFieldOrderStatusDesc:public CBMLField
{
public:
	CBCESFieldOrderStatusDesc(){
		m_dat=(void*)OrderStatusDesc;
		m_siz=sizeof(OrderStatusDesc);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderStatusDesc;
		memset(OrderStatusDesc,0x00,sizeof(OrderStatusDesc));	/* 状态说明 */
	}
	BCESFieldTypeOrderStatusDesc OrderStatusDesc;	/* 状态说明 */
};
/* 交易所报单编号 */
class CBCESFieldOrderSysID:public CBMLField
{
public:
	CBCESFieldOrderSysID(){
		m_dat=(void*)OrderSysID;
		m_siz=sizeof(OrderSysID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexOrderSysID;
		memset(OrderSysID,0x00,sizeof(OrderSysID));	/* 交易所报单编号 */
	}
	BCESFieldTypeOrderSysID OrderSysID;	/* 交易所报单编号 */
};
/* 会话编号 */
class CBCESFieldCTPSessionID:public CBMLField
{
public:
	CBCESFieldCTPSessionID(){
		m_dat=(void*)&CTPSessionID;
		m_siz=sizeof(CTPSessionID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCTPSessionID;
		memset(&CTPSessionID,0x00,sizeof(CTPSessionID));	/* 会话编号 */
	}
	BCESFieldTypeCTPSessionID CTPSessionID;	/* 会话编号 */
};
/* 前置编号 */
class CBCESFieldCTPFrontID:public CBMLField
{
public:
	CBCESFieldCTPFrontID(){
		m_dat=(void*)&CTPFrontID;
		m_siz=sizeof(CTPFrontID);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCTPFrontID;
		memset(&CTPFrontID,0x00,sizeof(CTPFrontID));	/* 前置编号 */
	}
	BCESFieldTypeCTPFrontID CTPFrontID;	/* 前置编号 */
};
/* 报单引用 */
class CBCESFieldCTPOrderRef:public CBMLField
{
public:
	CBCESFieldCTPOrderRef(){
		m_dat=(void*)CTPOrderRef;
		m_siz=sizeof(CTPOrderRef);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCTPOrderRef;
		memset(CTPOrderRef,0x00,sizeof(CTPOrderRef));	/* 报单引用 */
	}
	BCESFieldTypeCTPOrderRef CTPOrderRef;	/* 报单引用 */
};
/* 平仓手续费率 */
class CBCESFieldCloseFeeRate:public CBMLField
{
public:
	CBCESFieldCloseFeeRate(){
		m_dat=(void*)&CloseFeeRate;
		m_siz=sizeof(CloseFeeRate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCloseFeeRate;
		memset(&CloseFeeRate,0x00,sizeof(CloseFeeRate));	/* 平仓手续费率 */
	}
	BCESFieldTypeRate CloseFeeRate;	/* 平仓手续费率 */
};
/* 平今仓手续费率 */
class CBCESFieldCloseTodayFeeRate:public CBMLField
{
public:
	CBCESFieldCloseTodayFeeRate(){
		m_dat=(void*)&CloseTodayFeeRate;
		m_siz=sizeof(CloseTodayFeeRate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexCloseTodayFeeRate;
		memset(&CloseTodayFeeRate,0x00,sizeof(CloseTodayFeeRate));	/* 平今仓手续费率 */
	}
	BCESFieldTypeRate CloseTodayFeeRate;	/* 平今仓手续费率 */
};
/* 印花税费率 */
class CBCESFieldStampRate:public CBMLField
{
public:
	CBCESFieldStampRate(){
		m_dat=(void*)&StampRate;
		m_siz=sizeof(StampRate);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexStampRate;
		memset(&StampRate,0x00,sizeof(StampRate));	/* 印花税费率 */
	}
	BCESFieldTypeRate StampRate;	/* 印花税费率 */
};
/* K线类型 */
class CBCESFieldKLineType:public CBMLField
{
public:
	CBCESFieldKLineType(){
		m_dat=(void*)&KLineType;
		m_siz=sizeof(KLineType);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexKLineType;
		memset(&KLineType,0x00,sizeof(KLineType));	/* K线类型 */
	}
	BCESFieldTypeFlag KLineType;	/* K线类型 */
};
/* K线查询请求 */
class CBCESFieldKLineQueryReq:public CBMLField
{
public:
	CBCESFieldKLineQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexKLineQueryReq;
		
	}
	
};
/* K线列表 */
class CBCESFieldKLineList:public CBMLField
{
public:
	CBCESFieldKLineList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexKLineList;
		
	}
	
};
/* Tick线查询请求 */
class CBCESFieldTickLineQueryReq:public CBMLField
{
public:
	CBCESFieldTickLineQueryReq(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTickLineQueryReq;
		
	}
	
};
/* Tick线列表 */
class CBCESFieldTickLineList:public CBMLField
{
public:
	CBCESFieldTickLineList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexTickLineList;
		
	}
	
};
/* 起始Bar */
class CBCESFieldBarFrom:public CBMLField
{
public:
	CBCESFieldBarFrom(){
		m_dat=(void*)&BarFrom;
		m_siz=sizeof(BarFrom);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBarFrom;
		memset(&BarFrom,0x00,sizeof(BarFrom));	/* 起始Bar */
	}
	BCESFieldTypeRequestID BarFrom;	/* 起始Bar */
};
/* Bar数量 */
class CBCESFieldBarCount:public CBMLField
{
public:
	CBCESFieldBarCount(){
		m_dat=(void*)&BarCount;
		m_siz=sizeof(BarCount);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexBarCount;
		memset(&BarCount,0x00,sizeof(BarCount));	/* Bar数量 */
	}
	BCESFieldTypeRequestID BarCount;	/* Bar数量 */
};
/* 报单账户列表 */
class CBCESFieldAccountList:public CBMLField
{
public:
	CBCESFieldAccountList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccountList;
		
	}
	
};
/* 报单账户 */
class CBCESFieldAccount:public CBMLField
{
public:
	CBCESFieldAccount(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexAccount;
		
	}
	
};
/* 交易所列表 */
class CBCESFieldExchangeList:public CBMLField
{
public:
	CBCESFieldExchangeList(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexExchangeList;
		
	}
	
};
/* 交易所 */
class CBCESFieldExchange:public CBMLField
{
public:
	CBCESFieldExchange(){
		m_dat=NULL;
		m_siz=0;
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexExchange;
		
	}
	
};
/* 上日平仓盈亏 */
class CBCESFieldPreClosedPL:public CBMLField
{
public:
	CBCESFieldPreClosedPL(){
		m_dat=(void*)&PreClosedPL;
		m_siz=sizeof(PreClosedPL);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreClosedPL;
		memset(&PreClosedPL,0x00,sizeof(PreClosedPL));	/* 上日平仓盈亏 */
	}
	BCESFieldTypeAmount PreClosedPL;	/* 上日平仓盈亏 */
};
/* 上日平仓价 */
class CBCESFieldPreClosePrice:public CBMLField
{
public:
	CBCESFieldPreClosePrice(){
		m_dat=(void*)&PreClosePrice;
		m_siz=sizeof(PreClosePrice);
		m_len=NULL;
		m_opflags=0;
		m_rule=bces_rulearray+BCESFieldIndexPreClosePrice;
		memset(&PreClosePrice,0x00,sizeof(PreClosePrice));	/* 上日平仓价 */
	}
	BCESFieldTypePrice PreClosePrice;	/* 上日平仓价 */
};

/* Fields Define */
/* API报文头 */
class CBCESFieldsApiHead:public CBMLFields
{
public:
	CBCESFieldsApiHead()
	{
		m_fieldarray=m_fieldarray_ApiHead;
		m_fieldsize=sizeof(m_fieldarray_ApiHead)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsApiHead)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&ServiceNo,sizeof(ServiceNo),NULL,0,bces_rulearray+BCESFieldIndexServiceNo);	/* 指令编号 */
		AddField((void*)&RequestID,sizeof(RequestID),NULL,0,bces_rulearray+BCESFieldIndexRequestID);	/* 请求编号 */
		AddField((void*)&EndFlag,sizeof(EndFlag),NULL,0,bces_rulearray+BCESFieldIndexEndFlag);	/* 结束标记 */
	}
	CBCESFieldsApiHead(const CBCESFieldsApiHead& ApiHead){
		m_fieldarray=m_fieldarray_ApiHead;
		m_fieldsize=sizeof(m_fieldarray_ApiHead)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ApiHead+sizeof(CBMLFields),sizeof(CBCESFieldsApiHead)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&ServiceNo,sizeof(ServiceNo),NULL,0,bces_rulearray+BCESFieldIndexServiceNo);	/* 指令编号 */
		AddField((void*)&RequestID,sizeof(RequestID),NULL,0,bces_rulearray+BCESFieldIndexRequestID);	/* 请求编号 */
		AddField((void*)&EndFlag,sizeof(EndFlag),NULL,0,bces_rulearray+BCESFieldIndexEndFlag);	/* 结束标记 */
	}
	CBCESFieldsApiHead& operator=(const CBCESFieldsApiHead& ApiHead){
		m_fieldarray=m_fieldarray_ApiHead;
		m_fieldsize=sizeof(m_fieldarray_ApiHead)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ApiHead+sizeof(CBMLFields),sizeof(CBCESFieldsApiHead)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&ServiceNo,sizeof(ServiceNo),NULL,0,bces_rulearray+BCESFieldIndexServiceNo);	/* 指令编号 */
		AddField((void*)&RequestID,sizeof(RequestID),NULL,0,bces_rulearray+BCESFieldIndexRequestID);	/* 请求编号 */
		AddField((void*)&EndFlag,sizeof(EndFlag),NULL,0,bces_rulearray+BCESFieldIndexEndFlag);	/* 结束标记 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ApiHead),0x00,sizeof(CBCESFieldsApiHead)-sizeof(CBMLFields)-sizeof(m_fieldarray_ApiHead));
	}

	BML_FIELD_INFO m_fieldarray_ApiHead[3];

	// Field
	BCESFieldTypeServiceNo ServiceNo;	/* 指令编号 */
	BCESFieldTypeRequestID RequestID;	/* 请求编号 */
	BCESFieldTypeEndFlag EndFlag;	/* 结束标记 */
};

/* 应答信息域 */
class CBCESFieldsRspInfo:public CBMLFields
{
public:
	CBCESFieldsRspInfo()
	{
		m_fieldarray=m_fieldarray_RspInfo;
		m_fieldsize=sizeof(m_fieldarray_RspInfo)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsRspInfo)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&RspNo,sizeof(RspNo),NULL,0,bces_rulearray+BCESFieldIndexRspNo);	/* 应答编码 */
		AddField((void*)RspDesc,sizeof(RspDesc),NULL,0,bces_rulearray+BCESFieldIndexRspDesc);	/* 应答描述 */
	}
	CBCESFieldsRspInfo(const CBCESFieldsRspInfo& RspInfo){
		m_fieldarray=m_fieldarray_RspInfo;
		m_fieldsize=sizeof(m_fieldarray_RspInfo)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&RspInfo+sizeof(CBMLFields),sizeof(CBCESFieldsRspInfo)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&RspNo,sizeof(RspNo),NULL,0,bces_rulearray+BCESFieldIndexRspNo);	/* 应答编码 */
		AddField((void*)RspDesc,sizeof(RspDesc),NULL,0,bces_rulearray+BCESFieldIndexRspDesc);	/* 应答描述 */
	}
	CBCESFieldsRspInfo& operator=(const CBCESFieldsRspInfo& RspInfo){
		m_fieldarray=m_fieldarray_RspInfo;
		m_fieldsize=sizeof(m_fieldarray_RspInfo)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&RspInfo+sizeof(CBMLFields),sizeof(CBCESFieldsRspInfo)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&RspNo,sizeof(RspNo),NULL,0,bces_rulearray+BCESFieldIndexRspNo);	/* 应答编码 */
		AddField((void*)RspDesc,sizeof(RspDesc),NULL,0,bces_rulearray+BCESFieldIndexRspDesc);	/* 应答描述 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_RspInfo),0x00,sizeof(CBCESFieldsRspInfo)-sizeof(CBMLFields)-sizeof(m_fieldarray_RspInfo));
	}

	BML_FIELD_INFO m_fieldarray_RspInfo[2];

	// Field
	BCESFieldTypeRspNo RspNo;	/* 应答编码 */
	BCESFieldTypeRspDesc RspDesc;	/* 应答描述 */
};

/* 流订阅请求 */
class CBCESFieldsFlowSubscribeReq:public CBMLFields
{
public:
	CBCESFieldsFlowSubscribeReq()
	{
		m_fieldarray=m_fieldarray_FlowSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_FlowSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsFlowSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&FlowID,sizeof(FlowID),NULL,0,bces_rulearray+BCESFieldIndexFlowID);	/* 流编号 */
		AddField((void*)&PkgNo,sizeof(PkgNo),NULL,0,bces_rulearray+BCESFieldIndexPkgNo);	/* 报文序号 */
	}
	CBCESFieldsFlowSubscribeReq(const CBCESFieldsFlowSubscribeReq& FlowSubscribeReq){
		m_fieldarray=m_fieldarray_FlowSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_FlowSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FlowSubscribeReq+sizeof(CBMLFields),sizeof(CBCESFieldsFlowSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&FlowID,sizeof(FlowID),NULL,0,bces_rulearray+BCESFieldIndexFlowID);	/* 流编号 */
		AddField((void*)&PkgNo,sizeof(PkgNo),NULL,0,bces_rulearray+BCESFieldIndexPkgNo);	/* 报文序号 */
	}
	CBCESFieldsFlowSubscribeReq& operator=(const CBCESFieldsFlowSubscribeReq& FlowSubscribeReq){
		m_fieldarray=m_fieldarray_FlowSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_FlowSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FlowSubscribeReq+sizeof(CBMLFields),sizeof(CBCESFieldsFlowSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&FlowID,sizeof(FlowID),NULL,0,bces_rulearray+BCESFieldIndexFlowID);	/* 流编号 */
		AddField((void*)&PkgNo,sizeof(PkgNo),NULL,0,bces_rulearray+BCESFieldIndexPkgNo);	/* 报文序号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_FlowSubscribeReq),0x00,sizeof(CBCESFieldsFlowSubscribeReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_FlowSubscribeReq));
	}

	BML_FIELD_INFO m_fieldarray_FlowSubscribeReq[2];

	// Field
	BCESFieldTypeFlowID FlowID;	/* 流编号 */
	BCESFieldTypePkgNo PkgNo;	/* 报文序号 */
};

/* 流订阅应答 */
class CBCESFieldsFlowSubscribeRsp:public CBMLFields
{
public:
	CBCESFieldsFlowSubscribeRsp()
	{
		m_fieldarray=m_fieldarray_FlowSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_FlowSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsFlowSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&FlowID,sizeof(FlowID),NULL,0,bces_rulearray+BCESFieldIndexFlowID);	/* 流编号 */
		AddField((void*)&PkgNo,sizeof(PkgNo),NULL,0,bces_rulearray+BCESFieldIndexPkgNo);	/* 报文序号 */
	}
	CBCESFieldsFlowSubscribeRsp(const CBCESFieldsFlowSubscribeRsp& FlowSubscribeRsp){
		m_fieldarray=m_fieldarray_FlowSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_FlowSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FlowSubscribeRsp+sizeof(CBMLFields),sizeof(CBCESFieldsFlowSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&FlowID,sizeof(FlowID),NULL,0,bces_rulearray+BCESFieldIndexFlowID);	/* 流编号 */
		AddField((void*)&PkgNo,sizeof(PkgNo),NULL,0,bces_rulearray+BCESFieldIndexPkgNo);	/* 报文序号 */
	}
	CBCESFieldsFlowSubscribeRsp& operator=(const CBCESFieldsFlowSubscribeRsp& FlowSubscribeRsp){
		m_fieldarray=m_fieldarray_FlowSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_FlowSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FlowSubscribeRsp+sizeof(CBMLFields),sizeof(CBCESFieldsFlowSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&FlowID,sizeof(FlowID),NULL,0,bces_rulearray+BCESFieldIndexFlowID);	/* 流编号 */
		AddField((void*)&PkgNo,sizeof(PkgNo),NULL,0,bces_rulearray+BCESFieldIndexPkgNo);	/* 报文序号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_FlowSubscribeRsp),0x00,sizeof(CBCESFieldsFlowSubscribeRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_FlowSubscribeRsp));
	}

	BML_FIELD_INFO m_fieldarray_FlowSubscribeRsp[2];

	// Field
	BCESFieldTypeFlowID FlowID;	/* 流编号 */
	BCESFieldTypePkgNo PkgNo;	/* 报文序号 */
};

/* 报文头 */
class CBCESFieldsHead:public CBMLFields
{
public:
	CBCESFieldsHead()
	{
		m_fieldarray=m_fieldarray_Head;
		m_fieldsize=sizeof(m_fieldarray_Head)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHead)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&RequestID,sizeof(RequestID),NULL,0,bces_rulearray+BCESFieldIndexRequestID);	/* 请求编号 */
		AddField((void*)&EndFlag,sizeof(EndFlag),NULL,0,bces_rulearray+BCESFieldIndexEndFlag);	/* 结束标记 */
	}
	CBCESFieldsHead(const CBCESFieldsHead& Head){
		m_fieldarray=m_fieldarray_Head;
		m_fieldsize=sizeof(m_fieldarray_Head)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Head+sizeof(CBMLFields),sizeof(CBCESFieldsHead)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&RequestID,sizeof(RequestID),NULL,0,bces_rulearray+BCESFieldIndexRequestID);	/* 请求编号 */
		AddField((void*)&EndFlag,sizeof(EndFlag),NULL,0,bces_rulearray+BCESFieldIndexEndFlag);	/* 结束标记 */
	}
	CBCESFieldsHead& operator=(const CBCESFieldsHead& Head){
		m_fieldarray=m_fieldarray_Head;
		m_fieldsize=sizeof(m_fieldarray_Head)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Head+sizeof(CBMLFields),sizeof(CBCESFieldsHead)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&RequestID,sizeof(RequestID),NULL,0,bces_rulearray+BCESFieldIndexRequestID);	/* 请求编号 */
		AddField((void*)&EndFlag,sizeof(EndFlag),NULL,0,bces_rulearray+BCESFieldIndexEndFlag);	/* 结束标记 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Head),0x00,sizeof(CBCESFieldsHead)-sizeof(CBMLFields)-sizeof(m_fieldarray_Head));
	}

	BML_FIELD_INFO m_fieldarray_Head[2];

	// Field
	BCESFieldTypeRequestID RequestID;	/* 请求编号 */
	BCESFieldTypeEndFlag EndFlag;	/* 结束标记 */
};

/* 行情订阅请求 */
class CBCESFieldsQuotSubscribeReq:public CBMLFields
{
public:
	CBCESFieldsQuotSubscribeReq()
	{
		m_fieldarray=m_fieldarray_QuotSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_QuotSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotSubscribeReq(const CBCESFieldsQuotSubscribeReq& QuotSubscribeReq){
		m_fieldarray=m_fieldarray_QuotSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_QuotSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotSubscribeReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotSubscribeReq& operator=(const CBCESFieldsQuotSubscribeReq& QuotSubscribeReq){
		m_fieldarray=m_fieldarray_QuotSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_QuotSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotSubscribeReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotSubscribeReq),0x00,sizeof(CBCESFieldsQuotSubscribeReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotSubscribeReq));
	}

	BML_FIELD_INFO m_fieldarray_QuotSubscribeReq[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 行情订阅应答 */
class CBCESFieldsQuotSubscribeRsp:public CBMLFields
{
public:
	CBCESFieldsQuotSubscribeRsp()
	{
		m_fieldarray=m_fieldarray_QuotSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotSubscribeRsp(const CBCESFieldsQuotSubscribeRsp& QuotSubscribeRsp){
		m_fieldarray=m_fieldarray_QuotSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotSubscribeRsp+sizeof(CBMLFields),sizeof(CBCESFieldsQuotSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotSubscribeRsp& operator=(const CBCESFieldsQuotSubscribeRsp& QuotSubscribeRsp){
		m_fieldarray=m_fieldarray_QuotSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotSubscribeRsp+sizeof(CBMLFields),sizeof(CBCESFieldsQuotSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotSubscribeRsp),0x00,sizeof(CBCESFieldsQuotSubscribeRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotSubscribeRsp));
	}

	BML_FIELD_INFO m_fieldarray_QuotSubscribeRsp[1];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 行情退订请求 */
class CBCESFieldsQuotUnSubscribeReq:public CBMLFields
{
public:
	CBCESFieldsQuotUnSubscribeReq()
	{
		m_fieldarray=m_fieldarray_QuotUnSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_QuotUnSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotUnSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotUnSubscribeReq(const CBCESFieldsQuotUnSubscribeReq& QuotUnSubscribeReq){
		m_fieldarray=m_fieldarray_QuotUnSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_QuotUnSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotUnSubscribeReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotUnSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotUnSubscribeReq& operator=(const CBCESFieldsQuotUnSubscribeReq& QuotUnSubscribeReq){
		m_fieldarray=m_fieldarray_QuotUnSubscribeReq;
		m_fieldsize=sizeof(m_fieldarray_QuotUnSubscribeReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotUnSubscribeReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotUnSubscribeReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotUnSubscribeReq),0x00,sizeof(CBCESFieldsQuotUnSubscribeReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotUnSubscribeReq));
	}

	BML_FIELD_INFO m_fieldarray_QuotUnSubscribeReq[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 行情退订应答 */
class CBCESFieldsQuotUnSubscribeRsp:public CBMLFields
{
public:
	CBCESFieldsQuotUnSubscribeRsp()
	{
		m_fieldarray=m_fieldarray_QuotUnSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotUnSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotUnSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotUnSubscribeRsp(const CBCESFieldsQuotUnSubscribeRsp& QuotUnSubscribeRsp){
		m_fieldarray=m_fieldarray_QuotUnSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotUnSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotUnSubscribeRsp+sizeof(CBMLFields),sizeof(CBCESFieldsQuotUnSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsQuotUnSubscribeRsp& operator=(const CBCESFieldsQuotUnSubscribeRsp& QuotUnSubscribeRsp){
		m_fieldarray=m_fieldarray_QuotUnSubscribeRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotUnSubscribeRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotUnSubscribeRsp+sizeof(CBMLFields),sizeof(CBCESFieldsQuotUnSubscribeRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotUnSubscribeRsp),0x00,sizeof(CBCESFieldsQuotUnSubscribeRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotUnSubscribeRsp));
	}

	BML_FIELD_INFO m_fieldarray_QuotUnSubscribeRsp[1];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 数据操作概要 */
class CBCESFieldsDBOperateSummary:public CBMLFields
{
public:
	CBCESFieldsDBOperateSummary()
	{
		m_fieldarray=m_fieldarray_DBOperateSummary;
		m_fieldsize=sizeof(m_fieldarray_DBOperateSummary)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDBOperateSummary)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TableName,sizeof(TableName),NULL,0,bces_rulearray+BCESFieldIndexTableName);	/* 表名 */
		AddField((void*)&TableOperation,sizeof(TableOperation),NULL,0,bces_rulearray+BCESFieldIndexTableOperation);	/* 表操作 */
	}
	CBCESFieldsDBOperateSummary(const CBCESFieldsDBOperateSummary& DBOperateSummary){
		m_fieldarray=m_fieldarray_DBOperateSummary;
		m_fieldsize=sizeof(m_fieldarray_DBOperateSummary)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DBOperateSummary+sizeof(CBMLFields),sizeof(CBCESFieldsDBOperateSummary)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TableName,sizeof(TableName),NULL,0,bces_rulearray+BCESFieldIndexTableName);	/* 表名 */
		AddField((void*)&TableOperation,sizeof(TableOperation),NULL,0,bces_rulearray+BCESFieldIndexTableOperation);	/* 表操作 */
	}
	CBCESFieldsDBOperateSummary& operator=(const CBCESFieldsDBOperateSummary& DBOperateSummary){
		m_fieldarray=m_fieldarray_DBOperateSummary;
		m_fieldsize=sizeof(m_fieldarray_DBOperateSummary)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DBOperateSummary+sizeof(CBMLFields),sizeof(CBCESFieldsDBOperateSummary)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TableName,sizeof(TableName),NULL,0,bces_rulearray+BCESFieldIndexTableName);	/* 表名 */
		AddField((void*)&TableOperation,sizeof(TableOperation),NULL,0,bces_rulearray+BCESFieldIndexTableOperation);	/* 表操作 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DBOperateSummary),0x00,sizeof(CBCESFieldsDBOperateSummary)-sizeof(CBMLFields)-sizeof(m_fieldarray_DBOperateSummary));
	}

	BML_FIELD_INFO m_fieldarray_DBOperateSummary[2];

	// Field
	BCESFieldTypeTableName TableName;	/* 表名 */
	BCESFieldTypeTableOperation TableOperation;	/* 表操作 */
};

/* 登录请求 */
class CBCESFieldsLoginReq:public CBMLFields
{
public:
	CBCESFieldsLoginReq()
	{
		m_fieldarray=m_fieldarray_LoginReq;
		m_fieldsize=sizeof(m_fieldarray_LoginReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsLoginReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorPassword,sizeof(InvestorPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorPassword);	/* 投资者密码 */
		AddField((void*)IP,sizeof(IP),NULL,0,bces_rulearray+BCESFieldIndexIP);	/* IP地址 */
		AddField((void*)&ProductType,sizeof(ProductType),NULL,0,bces_rulearray+BCESFieldIndexProductType);	/* 产品编号 */
		AddField((void*)&ProductVersion,sizeof(ProductVersion),NULL,0,bces_rulearray+BCESFieldIndexProductVersion);	/* 产品版本号 */
	}
	CBCESFieldsLoginReq(const CBCESFieldsLoginReq& LoginReq){
		m_fieldarray=m_fieldarray_LoginReq;
		m_fieldsize=sizeof(m_fieldarray_LoginReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LoginReq+sizeof(CBMLFields),sizeof(CBCESFieldsLoginReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorPassword,sizeof(InvestorPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorPassword);	/* 投资者密码 */
		AddField((void*)IP,sizeof(IP),NULL,0,bces_rulearray+BCESFieldIndexIP);	/* IP地址 */
		AddField((void*)&ProductType,sizeof(ProductType),NULL,0,bces_rulearray+BCESFieldIndexProductType);	/* 产品编号 */
		AddField((void*)&ProductVersion,sizeof(ProductVersion),NULL,0,bces_rulearray+BCESFieldIndexProductVersion);	/* 产品版本号 */
	}
	CBCESFieldsLoginReq& operator=(const CBCESFieldsLoginReq& LoginReq){
		m_fieldarray=m_fieldarray_LoginReq;
		m_fieldsize=sizeof(m_fieldarray_LoginReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LoginReq+sizeof(CBMLFields),sizeof(CBCESFieldsLoginReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorPassword,sizeof(InvestorPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorPassword);	/* 投资者密码 */
		AddField((void*)IP,sizeof(IP),NULL,0,bces_rulearray+BCESFieldIndexIP);	/* IP地址 */
		AddField((void*)&ProductType,sizeof(ProductType),NULL,0,bces_rulearray+BCESFieldIndexProductType);	/* 产品编号 */
		AddField((void*)&ProductVersion,sizeof(ProductVersion),NULL,0,bces_rulearray+BCESFieldIndexProductVersion);	/* 产品版本号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_LoginReq),0x00,sizeof(CBCESFieldsLoginReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_LoginReq));
	}

	BML_FIELD_INFO m_fieldarray_LoginReq[5];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypePassword InvestorPassword;	/* 投资者密码 */
	BCESFieldTypeIP IP;	/* IP地址 */
	BCESFieldTypeFlag ProductType;	/* 产品编号 */
	BCESFieldTypeVersionNo ProductVersion;	/* 产品版本号 */
};

/* 登录应答 */
class CBCESFieldsLoginRsp:public CBMLFields
{
public:
	CBCESFieldsLoginRsp()
	{
		m_fieldarray=m_fieldarray_LoginRsp;
		m_fieldsize=sizeof(m_fieldarray_LoginRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsLoginRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)SysName,sizeof(SysName),NULL,0,bces_rulearray+BCESFieldIndexSysName);	/* 系统名称 */
		AddField((void*)&SysMode,sizeof(SysMode),NULL,0,bces_rulearray+BCESFieldIndexSysMode);	/* 系统模式 */
		AddField((void*)&PayServerType,sizeof(PayServerType),NULL,0,bces_rulearray+BCESFieldIndexPayServerType);	/* 支付服务类型 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&InvestorAdviserFlag,sizeof(InvestorAdviserFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorAdviserFlag);	/* 投资者顾问标志 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
	}
	CBCESFieldsLoginRsp(const CBCESFieldsLoginRsp& LoginRsp){
		m_fieldarray=m_fieldarray_LoginRsp;
		m_fieldsize=sizeof(m_fieldarray_LoginRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LoginRsp+sizeof(CBMLFields),sizeof(CBCESFieldsLoginRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)SysName,sizeof(SysName),NULL,0,bces_rulearray+BCESFieldIndexSysName);	/* 系统名称 */
		AddField((void*)&SysMode,sizeof(SysMode),NULL,0,bces_rulearray+BCESFieldIndexSysMode);	/* 系统模式 */
		AddField((void*)&PayServerType,sizeof(PayServerType),NULL,0,bces_rulearray+BCESFieldIndexPayServerType);	/* 支付服务类型 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&InvestorAdviserFlag,sizeof(InvestorAdviserFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorAdviserFlag);	/* 投资者顾问标志 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
	}
	CBCESFieldsLoginRsp& operator=(const CBCESFieldsLoginRsp& LoginRsp){
		m_fieldarray=m_fieldarray_LoginRsp;
		m_fieldsize=sizeof(m_fieldarray_LoginRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LoginRsp+sizeof(CBMLFields),sizeof(CBCESFieldsLoginRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)SysName,sizeof(SysName),NULL,0,bces_rulearray+BCESFieldIndexSysName);	/* 系统名称 */
		AddField((void*)&SysMode,sizeof(SysMode),NULL,0,bces_rulearray+BCESFieldIndexSysMode);	/* 系统模式 */
		AddField((void*)&PayServerType,sizeof(PayServerType),NULL,0,bces_rulearray+BCESFieldIndexPayServerType);	/* 支付服务类型 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&InvestorAdviserFlag,sizeof(InvestorAdviserFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorAdviserFlag);	/* 投资者顾问标志 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_LoginRsp),0x00,sizeof(CBCESFieldsLoginRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_LoginRsp));
	}

	BML_FIELD_INFO m_fieldarray_LoginRsp[9];

	// Field
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
class CBCESFieldsLogoutReq:public CBMLFields
{
public:
	CBCESFieldsLogoutReq()
	{
		m_fieldarray=m_fieldarray_LogoutReq;
		m_fieldsize=sizeof(m_fieldarray_LogoutReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsLogoutReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsLogoutReq(const CBCESFieldsLogoutReq& LogoutReq){
		m_fieldarray=m_fieldarray_LogoutReq;
		m_fieldsize=sizeof(m_fieldarray_LogoutReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LogoutReq+sizeof(CBMLFields),sizeof(CBCESFieldsLogoutReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsLogoutReq& operator=(const CBCESFieldsLogoutReq& LogoutReq){
		m_fieldarray=m_fieldarray_LogoutReq;
		m_fieldsize=sizeof(m_fieldarray_LogoutReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LogoutReq+sizeof(CBMLFields),sizeof(CBCESFieldsLogoutReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_LogoutReq),0x00,sizeof(CBCESFieldsLogoutReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_LogoutReq));
	}

	BML_FIELD_INFO m_fieldarray_LogoutReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 登出应答 */
class CBCESFieldsLogoutRsp:public CBMLFields
{
public:
	CBCESFieldsLogoutRsp()
	{
		m_fieldarray=m_fieldarray_LogoutRsp;
		m_fieldsize=sizeof(m_fieldarray_LogoutRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsLogoutRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsLogoutRsp(const CBCESFieldsLogoutRsp& LogoutRsp){
		m_fieldarray=m_fieldarray_LogoutRsp;
		m_fieldsize=sizeof(m_fieldarray_LogoutRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LogoutRsp+sizeof(CBMLFields),sizeof(CBCESFieldsLogoutRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsLogoutRsp& operator=(const CBCESFieldsLogoutRsp& LogoutRsp){
		m_fieldarray=m_fieldarray_LogoutRsp;
		m_fieldsize=sizeof(m_fieldarray_LogoutRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&LogoutRsp+sizeof(CBMLFields),sizeof(CBCESFieldsLogoutRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_LogoutRsp),0x00,sizeof(CBCESFieldsLogoutRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_LogoutRsp));
	}

	BML_FIELD_INFO m_fieldarray_LogoutRsp[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 修改密码请求 */
class CBCESFieldsChangePasswordReq:public CBMLFields
{
public:
	CBCESFieldsChangePasswordReq()
	{
		m_fieldarray=m_fieldarray_ChangePasswordReq;
		m_fieldsize=sizeof(m_fieldarray_ChangePasswordReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsChangePasswordReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorOldPassword,sizeof(InvestorOldPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorOldPassword);	/* 投资者旧密码 */
		AddField((void*)InvestorNewPassword,sizeof(InvestorNewPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorNewPassword);	/* 投资者新密码 */
	}
	CBCESFieldsChangePasswordReq(const CBCESFieldsChangePasswordReq& ChangePasswordReq){
		m_fieldarray=m_fieldarray_ChangePasswordReq;
		m_fieldsize=sizeof(m_fieldarray_ChangePasswordReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ChangePasswordReq+sizeof(CBMLFields),sizeof(CBCESFieldsChangePasswordReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorOldPassword,sizeof(InvestorOldPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorOldPassword);	/* 投资者旧密码 */
		AddField((void*)InvestorNewPassword,sizeof(InvestorNewPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorNewPassword);	/* 投资者新密码 */
	}
	CBCESFieldsChangePasswordReq& operator=(const CBCESFieldsChangePasswordReq& ChangePasswordReq){
		m_fieldarray=m_fieldarray_ChangePasswordReq;
		m_fieldsize=sizeof(m_fieldarray_ChangePasswordReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ChangePasswordReq+sizeof(CBMLFields),sizeof(CBCESFieldsChangePasswordReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorOldPassword,sizeof(InvestorOldPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorOldPassword);	/* 投资者旧密码 */
		AddField((void*)InvestorNewPassword,sizeof(InvestorNewPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorNewPassword);	/* 投资者新密码 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ChangePasswordReq),0x00,sizeof(CBCESFieldsChangePasswordReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_ChangePasswordReq));
	}

	BML_FIELD_INFO m_fieldarray_ChangePasswordReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypePassword InvestorOldPassword;	/* 投资者旧密码 */
	BCESFieldTypePassword InvestorNewPassword;	/* 投资者新密码 */
};

/* 修改密码应答 */
class CBCESFieldsChangePasswordRsp:public CBMLFields
{
public:
	CBCESFieldsChangePasswordRsp()
	{
		m_fieldarray=m_fieldarray_ChangePasswordRsp;
		m_fieldsize=sizeof(m_fieldarray_ChangePasswordRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsChangePasswordRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsChangePasswordRsp(const CBCESFieldsChangePasswordRsp& ChangePasswordRsp){
		m_fieldarray=m_fieldarray_ChangePasswordRsp;
		m_fieldsize=sizeof(m_fieldarray_ChangePasswordRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ChangePasswordRsp+sizeof(CBMLFields),sizeof(CBCESFieldsChangePasswordRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsChangePasswordRsp& operator=(const CBCESFieldsChangePasswordRsp& ChangePasswordRsp){
		m_fieldarray=m_fieldarray_ChangePasswordRsp;
		m_fieldsize=sizeof(m_fieldarray_ChangePasswordRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ChangePasswordRsp+sizeof(CBMLFields),sizeof(CBCESFieldsChangePasswordRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ChangePasswordRsp),0x00,sizeof(CBCESFieldsChangePasswordRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_ChangePasswordRsp));
	}

	BML_FIELD_INFO m_fieldarray_ChangePasswordRsp[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 报单账户 */
class CBCESFieldsAccount:public CBMLFields
{
public:
	CBCESFieldsAccount()
	{
		m_fieldarray=m_fieldarray_Account;
		m_fieldsize=sizeof(m_fieldarray_Account)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsAccount)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 报单账号 */
	}
	CBCESFieldsAccount(const CBCESFieldsAccount& Account){
		m_fieldarray=m_fieldarray_Account;
		m_fieldsize=sizeof(m_fieldarray_Account)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Account+sizeof(CBMLFields),sizeof(CBCESFieldsAccount)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 报单账号 */
	}
	CBCESFieldsAccount& operator=(const CBCESFieldsAccount& Account){
		m_fieldarray=m_fieldarray_Account;
		m_fieldsize=sizeof(m_fieldarray_Account)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Account+sizeof(CBMLFields),sizeof(CBCESFieldsAccount)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 报单账号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Account),0x00,sizeof(CBCESFieldsAccount)-sizeof(CBMLFields)-sizeof(m_fieldarray_Account));
	}

	BML_FIELD_INFO m_fieldarray_Account[1];

	// Field
	BCESFieldTypeAccountID AccountID;	/* 报单账号 */
};

/* 交易所 */
class CBCESFieldsExchange:public CBMLFields
{
public:
	CBCESFieldsExchange()
	{
		m_fieldarray=m_fieldarray_Exchange;
		m_fieldsize=sizeof(m_fieldarray_Exchange)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsExchange)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsExchange(const CBCESFieldsExchange& Exchange){
		m_fieldarray=m_fieldarray_Exchange;
		m_fieldsize=sizeof(m_fieldarray_Exchange)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Exchange+sizeof(CBMLFields),sizeof(CBCESFieldsExchange)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsExchange& operator=(const CBCESFieldsExchange& Exchange){
		m_fieldarray=m_fieldarray_Exchange;
		m_fieldsize=sizeof(m_fieldarray_Exchange)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Exchange+sizeof(CBMLFields),sizeof(CBCESFieldsExchange)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Exchange),0x00,sizeof(CBCESFieldsExchange)-sizeof(CBMLFields)-sizeof(m_fieldarray_Exchange));
	}

	BML_FIELD_INFO m_fieldarray_Exchange[1];

	// Field
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 订单录入 */
class CBCESFieldsInputOrder:public CBMLFields
{
public:
	CBCESFieldsInputOrder()
	{
		m_fieldarray=m_fieldarray_InputOrder;
		m_fieldsize=sizeof(m_fieldarray_InputOrder)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInputOrder)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&PriceType,sizeof(PriceType),NULL,0,bces_rulearray+BCESFieldIndexPriceType);	/* 价格类型 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)&FilledPoints,sizeof(FilledPoints),NULL,0,bces_rulearray+BCESFieldIndexFilledPoints);	/* 成交滑点 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ConditionType,sizeof(ConditionType),NULL,0,bces_rulearray+BCESFieldIndexConditionType);	/* 条件类型 */
		AddField((void*)&ConditionMethod,sizeof(ConditionMethod),NULL,0,bces_rulearray+BCESFieldIndexConditionMethod);	/* 条件方法 */
		AddField((void*)&ConditionPrice,sizeof(ConditionPrice),NULL,0,bces_rulearray+BCESFieldIndexConditionPrice);	/* 条件价格 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
	}
	CBCESFieldsInputOrder(const CBCESFieldsInputOrder& InputOrder){
		m_fieldarray=m_fieldarray_InputOrder;
		m_fieldsize=sizeof(m_fieldarray_InputOrder)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InputOrder+sizeof(CBMLFields),sizeof(CBCESFieldsInputOrder)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&PriceType,sizeof(PriceType),NULL,0,bces_rulearray+BCESFieldIndexPriceType);	/* 价格类型 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)&FilledPoints,sizeof(FilledPoints),NULL,0,bces_rulearray+BCESFieldIndexFilledPoints);	/* 成交滑点 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ConditionType,sizeof(ConditionType),NULL,0,bces_rulearray+BCESFieldIndexConditionType);	/* 条件类型 */
		AddField((void*)&ConditionMethod,sizeof(ConditionMethod),NULL,0,bces_rulearray+BCESFieldIndexConditionMethod);	/* 条件方法 */
		AddField((void*)&ConditionPrice,sizeof(ConditionPrice),NULL,0,bces_rulearray+BCESFieldIndexConditionPrice);	/* 条件价格 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
	}
	CBCESFieldsInputOrder& operator=(const CBCESFieldsInputOrder& InputOrder){
		m_fieldarray=m_fieldarray_InputOrder;
		m_fieldsize=sizeof(m_fieldarray_InputOrder)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InputOrder+sizeof(CBMLFields),sizeof(CBCESFieldsInputOrder)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&PriceType,sizeof(PriceType),NULL,0,bces_rulearray+BCESFieldIndexPriceType);	/* 价格类型 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)&FilledPoints,sizeof(FilledPoints),NULL,0,bces_rulearray+BCESFieldIndexFilledPoints);	/* 成交滑点 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ConditionType,sizeof(ConditionType),NULL,0,bces_rulearray+BCESFieldIndexConditionType);	/* 条件类型 */
		AddField((void*)&ConditionMethod,sizeof(ConditionMethod),NULL,0,bces_rulearray+BCESFieldIndexConditionMethod);	/* 条件方法 */
		AddField((void*)&ConditionPrice,sizeof(ConditionPrice),NULL,0,bces_rulearray+BCESFieldIndexConditionPrice);	/* 条件价格 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InputOrder),0x00,sizeof(CBCESFieldsInputOrder)-sizeof(CBMLFields)-sizeof(m_fieldarray_InputOrder));
	}

	BML_FIELD_INFO m_fieldarray_InputOrder[22];

	// Field
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
class CBCESFieldsOrder:public CBMLFields
{
public:
	CBCESFieldsOrder()
	{
		m_fieldarray=m_fieldarray_Order;
		m_fieldsize=sizeof(m_fieldarray_Order)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsOrder)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)OrderDate,sizeof(OrderDate),NULL,0,bces_rulearray+BCESFieldIndexOrderDate);	/* 报单日期 */
		AddField((void*)OrderTime,sizeof(OrderTime),NULL,0,bces_rulearray+BCESFieldIndexOrderTime);	/* 报单时间 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&PriceType,sizeof(PriceType),NULL,0,bces_rulearray+BCESFieldIndexPriceType);	/* 价格类型 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&QtyLeft,sizeof(QtyLeft),NULL,0,bces_rulearray+BCESFieldIndexQtyLeft);	/* 剩余数量 */
		AddField((void*)&AvgPrice,sizeof(AvgPrice),NULL,0,bces_rulearray+BCESFieldIndexAvgPrice);	/* 成交均价 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 修改日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 修改时间 */
		AddField((void*)&OrderStatus,sizeof(OrderStatus),NULL,0,bces_rulearray+BCESFieldIndexOrderStatus);	/* 订单状态 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)&FilledPoints,sizeof(FilledPoints),NULL,0,bces_rulearray+BCESFieldIndexFilledPoints);	/* 成交滑点 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&ConditionType,sizeof(ConditionType),NULL,0,bces_rulearray+BCESFieldIndexConditionType);	/* 条件类型 */
		AddField((void*)&ConditionMethod,sizeof(ConditionMethod),NULL,0,bces_rulearray+BCESFieldIndexConditionMethod);	/* 条件方法 */
		AddField((void*)&ConditionPrice,sizeof(ConditionPrice),NULL,0,bces_rulearray+BCESFieldIndexConditionPrice);	/* 条件价格 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)OrderStatusDesc,sizeof(OrderStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexOrderStatusDesc);	/* 订单状态描述 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)&CTPFrontID,sizeof(CTPFrontID),NULL,0,bces_rulearray+BCESFieldIndexCTPFrontID);	/* CTP前置编号 */
		AddField((void*)&CTPSessionID,sizeof(CTPSessionID),NULL,0,bces_rulearray+BCESFieldIndexCTPSessionID);	/* CTP会话编号 */
		AddField((void*)CTPOrderRef,sizeof(CTPOrderRef),NULL,0,bces_rulearray+BCESFieldIndexCTPOrderRef);	/* CTP报单引用 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsOrder(const CBCESFieldsOrder& Order){
		m_fieldarray=m_fieldarray_Order;
		m_fieldsize=sizeof(m_fieldarray_Order)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Order+sizeof(CBMLFields),sizeof(CBCESFieldsOrder)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)OrderDate,sizeof(OrderDate),NULL,0,bces_rulearray+BCESFieldIndexOrderDate);	/* 报单日期 */
		AddField((void*)OrderTime,sizeof(OrderTime),NULL,0,bces_rulearray+BCESFieldIndexOrderTime);	/* 报单时间 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&PriceType,sizeof(PriceType),NULL,0,bces_rulearray+BCESFieldIndexPriceType);	/* 价格类型 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&QtyLeft,sizeof(QtyLeft),NULL,0,bces_rulearray+BCESFieldIndexQtyLeft);	/* 剩余数量 */
		AddField((void*)&AvgPrice,sizeof(AvgPrice),NULL,0,bces_rulearray+BCESFieldIndexAvgPrice);	/* 成交均价 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 修改日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 修改时间 */
		AddField((void*)&OrderStatus,sizeof(OrderStatus),NULL,0,bces_rulearray+BCESFieldIndexOrderStatus);	/* 订单状态 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)&FilledPoints,sizeof(FilledPoints),NULL,0,bces_rulearray+BCESFieldIndexFilledPoints);	/* 成交滑点 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&ConditionType,sizeof(ConditionType),NULL,0,bces_rulearray+BCESFieldIndexConditionType);	/* 条件类型 */
		AddField((void*)&ConditionMethod,sizeof(ConditionMethod),NULL,0,bces_rulearray+BCESFieldIndexConditionMethod);	/* 条件方法 */
		AddField((void*)&ConditionPrice,sizeof(ConditionPrice),NULL,0,bces_rulearray+BCESFieldIndexConditionPrice);	/* 条件价格 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)OrderStatusDesc,sizeof(OrderStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexOrderStatusDesc);	/* 订单状态描述 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)&CTPFrontID,sizeof(CTPFrontID),NULL,0,bces_rulearray+BCESFieldIndexCTPFrontID);	/* CTP前置编号 */
		AddField((void*)&CTPSessionID,sizeof(CTPSessionID),NULL,0,bces_rulearray+BCESFieldIndexCTPSessionID);	/* CTP会话编号 */
		AddField((void*)CTPOrderRef,sizeof(CTPOrderRef),NULL,0,bces_rulearray+BCESFieldIndexCTPOrderRef);	/* CTP报单引用 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsOrder& operator=(const CBCESFieldsOrder& Order){
		m_fieldarray=m_fieldarray_Order;
		m_fieldsize=sizeof(m_fieldarray_Order)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Order+sizeof(CBMLFields),sizeof(CBCESFieldsOrder)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)OrderDate,sizeof(OrderDate),NULL,0,bces_rulearray+BCESFieldIndexOrderDate);	/* 报单日期 */
		AddField((void*)OrderTime,sizeof(OrderTime),NULL,0,bces_rulearray+BCESFieldIndexOrderTime);	/* 报单时间 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&PriceType,sizeof(PriceType),NULL,0,bces_rulearray+BCESFieldIndexPriceType);	/* 价格类型 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&QtyLeft,sizeof(QtyLeft),NULL,0,bces_rulearray+BCESFieldIndexQtyLeft);	/* 剩余数量 */
		AddField((void*)&AvgPrice,sizeof(AvgPrice),NULL,0,bces_rulearray+BCESFieldIndexAvgPrice);	/* 成交均价 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 修改日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 修改时间 */
		AddField((void*)&OrderStatus,sizeof(OrderStatus),NULL,0,bces_rulearray+BCESFieldIndexOrderStatus);	/* 订单状态 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)&FilledPoints,sizeof(FilledPoints),NULL,0,bces_rulearray+BCESFieldIndexFilledPoints);	/* 成交滑点 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&ConditionType,sizeof(ConditionType),NULL,0,bces_rulearray+BCESFieldIndexConditionType);	/* 条件类型 */
		AddField((void*)&ConditionMethod,sizeof(ConditionMethod),NULL,0,bces_rulearray+BCESFieldIndexConditionMethod);	/* 条件方法 */
		AddField((void*)&ConditionPrice,sizeof(ConditionPrice),NULL,0,bces_rulearray+BCESFieldIndexConditionPrice);	/* 条件价格 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)OrderStatusDesc,sizeof(OrderStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexOrderStatusDesc);	/* 订单状态描述 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)&CTPFrontID,sizeof(CTPFrontID),NULL,0,bces_rulearray+BCESFieldIndexCTPFrontID);	/* CTP前置编号 */
		AddField((void*)&CTPSessionID,sizeof(CTPSessionID),NULL,0,bces_rulearray+BCESFieldIndexCTPSessionID);	/* CTP会话编号 */
		AddField((void*)CTPOrderRef,sizeof(CTPOrderRef),NULL,0,bces_rulearray+BCESFieldIndexCTPOrderRef);	/* CTP报单引用 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Order),0x00,sizeof(CBCESFieldsOrder)-sizeof(CBMLFields)-sizeof(m_fieldarray_Order));
	}

	BML_FIELD_INFO m_fieldarray_Order[37];

	// Field
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
class CBCESFieldsOrderCancelReq:public CBMLFields
{
public:
	CBCESFieldsOrderCancelReq()
	{
		m_fieldarray=m_fieldarray_OrderCancelReq;
		m_fieldsize=sizeof(m_fieldarray_OrderCancelReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsOrderCancelReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsOrderCancelReq(const CBCESFieldsOrderCancelReq& OrderCancelReq){
		m_fieldarray=m_fieldarray_OrderCancelReq;
		m_fieldsize=sizeof(m_fieldarray_OrderCancelReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&OrderCancelReq+sizeof(CBMLFields),sizeof(CBCESFieldsOrderCancelReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsOrderCancelReq& operator=(const CBCESFieldsOrderCancelReq& OrderCancelReq){
		m_fieldarray=m_fieldarray_OrderCancelReq;
		m_fieldsize=sizeof(m_fieldarray_OrderCancelReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&OrderCancelReq+sizeof(CBMLFields),sizeof(CBCESFieldsOrderCancelReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_OrderCancelReq),0x00,sizeof(CBCESFieldsOrderCancelReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_OrderCancelReq));
	}

	BML_FIELD_INFO m_fieldarray_OrderCancelReq[8];

	// Field
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
class CBCESFieldsOrderCancelRsp:public CBMLFields
{
public:
	CBCESFieldsOrderCancelRsp()
	{
		m_fieldarray=m_fieldarray_OrderCancelRsp;
		m_fieldsize=sizeof(m_fieldarray_OrderCancelRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsOrderCancelRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsOrderCancelRsp(const CBCESFieldsOrderCancelRsp& OrderCancelRsp){
		m_fieldarray=m_fieldarray_OrderCancelRsp;
		m_fieldsize=sizeof(m_fieldarray_OrderCancelRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&OrderCancelRsp+sizeof(CBMLFields),sizeof(CBCESFieldsOrderCancelRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsOrderCancelRsp& operator=(const CBCESFieldsOrderCancelRsp& OrderCancelRsp){
		m_fieldarray=m_fieldarray_OrderCancelRsp;
		m_fieldsize=sizeof(m_fieldarray_OrderCancelRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&OrderCancelRsp+sizeof(CBMLFields),sizeof(CBCESFieldsOrderCancelRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&SessionID,sizeof(SessionID),NULL,0,bces_rulearray+BCESFieldIndexSessionID);	/* 会话编号 */
		AddField((void*)OrderRef,sizeof(OrderRef),NULL,0,bces_rulearray+BCESFieldIndexOrderRef);	/* 报单引用 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_OrderCancelRsp),0x00,sizeof(CBCESFieldsOrderCancelRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_OrderCancelRsp));
	}

	BML_FIELD_INFO m_fieldarray_OrderCancelRsp[8];

	// Field
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
class CBCESFieldsTrade:public CBMLFields
{
public:
	CBCESFieldsTrade()
	{
		m_fieldarray=m_fieldarray_Trade;
		m_fieldsize=sizeof(m_fieldarray_Trade)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTrade)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)MatchDate,sizeof(MatchDate),NULL,0,bces_rulearray+BCESFieldIndexMatchDate);	/* 成交日期 */
		AddField((void*)MatchTime,sizeof(MatchTime),NULL,0,bces_rulearray+BCESFieldIndexMatchTime);	/* 成交时间 */
		AddField((void*)&FeeRate,sizeof(FeeRate),NULL,0,bces_rulearray+BCESFieldIndexFeeRate);	/* 手续费 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsTrade(const CBCESFieldsTrade& Trade){
		m_fieldarray=m_fieldarray_Trade;
		m_fieldsize=sizeof(m_fieldarray_Trade)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Trade+sizeof(CBMLFields),sizeof(CBCESFieldsTrade)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)MatchDate,sizeof(MatchDate),NULL,0,bces_rulearray+BCESFieldIndexMatchDate);	/* 成交日期 */
		AddField((void*)MatchTime,sizeof(MatchTime),NULL,0,bces_rulearray+BCESFieldIndexMatchTime);	/* 成交时间 */
		AddField((void*)&FeeRate,sizeof(FeeRate),NULL,0,bces_rulearray+BCESFieldIndexFeeRate);	/* 手续费 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
	}
	CBCESFieldsTrade& operator=(const CBCESFieldsTrade& Trade){
		m_fieldarray=m_fieldarray_Trade;
		m_fieldsize=sizeof(m_fieldarray_Trade)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Trade+sizeof(CBMLFields),sizeof(CBCESFieldsTrade)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&OCFlag,sizeof(OCFlag),NULL,0,bces_rulearray+BCESFieldIndexOCFlag);	/* 开平标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)MatchDate,sizeof(MatchDate),NULL,0,bces_rulearray+BCESFieldIndexMatchDate);	/* 成交日期 */
		AddField((void*)MatchTime,sizeof(MatchTime),NULL,0,bces_rulearray+BCESFieldIndexMatchTime);	/* 成交时间 */
		AddField((void*)&FeeRate,sizeof(FeeRate),NULL,0,bces_rulearray+BCESFieldIndexFeeRate);	/* 手续费 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)ClosedTradeDate,sizeof(ClosedTradeDate),NULL,0,bces_rulearray+BCESFieldIndexClosedTradeDate);	/* 平仓交易日期 */
		AddField((void*)ClosedOrderID,sizeof(ClosedOrderID),NULL,0,bces_rulearray+BCESFieldIndexClosedOrderID);	/* 平仓订单号 */
		AddField((void*)ClosedMatchID,sizeof(ClosedMatchID),NULL,0,bces_rulearray+BCESFieldIndexClosedMatchID);	/* 平仓成交号 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 交易账号 */
		AddField((void*)OrderSysID,sizeof(OrderSysID),NULL,0,bces_rulearray+BCESFieldIndexOrderSysID);	/* 交易所报单编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Trade),0x00,sizeof(CBCESFieldsTrade)-sizeof(CBMLFields)-sizeof(m_fieldarray_Trade));
	}

	BML_FIELD_INFO m_fieldarray_Trade[19];

	// Field
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
class CBCESFieldsQuot:public CBMLFields
{
public:
	CBCESFieldsQuot()
	{
		m_fieldarray=m_fieldarray_Quot;
		m_fieldsize=sizeof(m_fieldarray_Quot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 现价 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 现手 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 持仓量 */
		AddField((void*)&SettlePrice,sizeof(SettlePrice),NULL,0,bces_rulearray+BCESFieldIndexSettlePrice);	/* 结算价 */
		AddField((void*)&PreClose,sizeof(PreClose),NULL,0,bces_rulearray+BCESFieldIndexPreClose);	/* 昨收盘价 */
		AddField((void*)&PreSettle,sizeof(PreSettle),NULL,0,bces_rulearray+BCESFieldIndexPreSettle);	/* 昨结算价 */
		AddField((void*)&PreOI,sizeof(PreOI),NULL,0,bces_rulearray+BCESFieldIndexPreOI);	/* 昨持仓量 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 更新日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 更新时间 */
		AddField((void*)&BidPrice2,sizeof(BidPrice2),NULL,0,bces_rulearray+BCESFieldIndexBidPrice2);	/* 叫买价2 */
		AddField((void*)&BidQty2,sizeof(BidQty2),NULL,0,bces_rulearray+BCESFieldIndexBidQty2);	/* 叫买量2 */
		AddField((void*)&AskPrice2,sizeof(AskPrice2),NULL,0,bces_rulearray+BCESFieldIndexAskPrice2);	/* 叫卖价2 */
		AddField((void*)&AskQty2,sizeof(AskQty2),NULL,0,bces_rulearray+BCESFieldIndexAskQty2);	/* 叫卖量2 */
		AddField((void*)&BidPrice3,sizeof(BidPrice3),NULL,0,bces_rulearray+BCESFieldIndexBidPrice3);	/* 叫买价3 */
		AddField((void*)&BidQty3,sizeof(BidQty3),NULL,0,bces_rulearray+BCESFieldIndexBidQty3);	/* 叫买量3 */
		AddField((void*)&AskPrice3,sizeof(AskPrice3),NULL,0,bces_rulearray+BCESFieldIndexAskPrice3);	/* 叫卖价3 */
		AddField((void*)&AskQty3,sizeof(AskQty3),NULL,0,bces_rulearray+BCESFieldIndexAskQty3);	/* 叫卖量3 */
		AddField((void*)&BidPrice4,sizeof(BidPrice4),NULL,0,bces_rulearray+BCESFieldIndexBidPrice4);	/* 叫买价4 */
		AddField((void*)&BidQty4,sizeof(BidQty4),NULL,0,bces_rulearray+BCESFieldIndexBidQty4);	/* 叫买量4 */
		AddField((void*)&AskPrice4,sizeof(AskPrice4),NULL,0,bces_rulearray+BCESFieldIndexAskPrice4);	/* 叫卖价4 */
		AddField((void*)&AskQty4,sizeof(AskQty4),NULL,0,bces_rulearray+BCESFieldIndexAskQty4);	/* 叫卖量4 */
		AddField((void*)&BidPrice5,sizeof(BidPrice5),NULL,0,bces_rulearray+BCESFieldIndexBidPrice5);	/* 叫买价5 */
		AddField((void*)&BidQty5,sizeof(BidQty5),NULL,0,bces_rulearray+BCESFieldIndexBidQty5);	/* 叫买量5 */
		AddField((void*)&AskPrice5,sizeof(AskPrice5),NULL,0,bces_rulearray+BCESFieldIndexAskPrice5);	/* 叫卖价5 */
		AddField((void*)&AskQty5,sizeof(AskQty5),NULL,0,bces_rulearray+BCESFieldIndexAskQty5);	/* 叫卖量5 */
		AddField((void*)&BidPrice6,sizeof(BidPrice6),NULL,0,bces_rulearray+BCESFieldIndexBidPrice6);	/* 叫买价6 */
		AddField((void*)&BidQty6,sizeof(BidQty6),NULL,0,bces_rulearray+BCESFieldIndexBidQty6);	/* 叫买量6 */
		AddField((void*)&AskPrice6,sizeof(AskPrice6),NULL,0,bces_rulearray+BCESFieldIndexAskPrice6);	/* 叫卖价6 */
		AddField((void*)&AskQty6,sizeof(AskQty6),NULL,0,bces_rulearray+BCESFieldIndexAskQty6);	/* 叫卖量6 */
		AddField((void*)&BidPrice7,sizeof(BidPrice7),NULL,0,bces_rulearray+BCESFieldIndexBidPrice7);	/* 叫买价7 */
		AddField((void*)&BidQty7,sizeof(BidQty7),NULL,0,bces_rulearray+BCESFieldIndexBidQty7);	/* 叫买量7 */
		AddField((void*)&AskPrice7,sizeof(AskPrice7),NULL,0,bces_rulearray+BCESFieldIndexAskPrice7);	/* 叫卖价7 */
		AddField((void*)&AskQty7,sizeof(AskQty7),NULL,0,bces_rulearray+BCESFieldIndexAskQty7);	/* 叫卖量7 */
		AddField((void*)&BidPrice8,sizeof(BidPrice8),NULL,0,bces_rulearray+BCESFieldIndexBidPrice8);	/* 叫买价8 */
		AddField((void*)&BidQty8,sizeof(BidQty8),NULL,0,bces_rulearray+BCESFieldIndexBidQty8);	/* 叫买量8 */
		AddField((void*)&AskPrice8,sizeof(AskPrice8),NULL,0,bces_rulearray+BCESFieldIndexAskPrice8);	/* 叫卖价8 */
		AddField((void*)&AskQty8,sizeof(AskQty8),NULL,0,bces_rulearray+BCESFieldIndexAskQty8);	/* 叫卖量8 */
		AddField((void*)&BidPrice9,sizeof(BidPrice9),NULL,0,bces_rulearray+BCESFieldIndexBidPrice9);	/* 叫买价9 */
		AddField((void*)&BidQty9,sizeof(BidQty9),NULL,0,bces_rulearray+BCESFieldIndexBidQty9);	/* 叫买量9 */
		AddField((void*)&AskPrice9,sizeof(AskPrice9),NULL,0,bces_rulearray+BCESFieldIndexAskPrice9);	/* 叫卖价9 */
		AddField((void*)&AskQty9,sizeof(AskQty9),NULL,0,bces_rulearray+BCESFieldIndexAskQty9);	/* 叫卖量9 */
		AddField((void*)&BidPrice10,sizeof(BidPrice10),NULL,0,bces_rulearray+BCESFieldIndexBidPrice10);	/* 叫买价10 */
		AddField((void*)&BidQty10,sizeof(BidQty10),NULL,0,bces_rulearray+BCESFieldIndexBidQty10);	/* 叫买量10 */
		AddField((void*)&AskPrice10,sizeof(AskPrice10),NULL,0,bces_rulearray+BCESFieldIndexAskPrice10);	/* 叫卖价10 */
		AddField((void*)&AskQty10,sizeof(AskQty10),NULL,0,bces_rulearray+BCESFieldIndexAskQty10);	/* 叫卖量10 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsQuot(const CBCESFieldsQuot& Quot){
		m_fieldarray=m_fieldarray_Quot;
		m_fieldsize=sizeof(m_fieldarray_Quot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Quot+sizeof(CBMLFields),sizeof(CBCESFieldsQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 现价 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 现手 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 持仓量 */
		AddField((void*)&SettlePrice,sizeof(SettlePrice),NULL,0,bces_rulearray+BCESFieldIndexSettlePrice);	/* 结算价 */
		AddField((void*)&PreClose,sizeof(PreClose),NULL,0,bces_rulearray+BCESFieldIndexPreClose);	/* 昨收盘价 */
		AddField((void*)&PreSettle,sizeof(PreSettle),NULL,0,bces_rulearray+BCESFieldIndexPreSettle);	/* 昨结算价 */
		AddField((void*)&PreOI,sizeof(PreOI),NULL,0,bces_rulearray+BCESFieldIndexPreOI);	/* 昨持仓量 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 更新日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 更新时间 */
		AddField((void*)&BidPrice2,sizeof(BidPrice2),NULL,0,bces_rulearray+BCESFieldIndexBidPrice2);	/* 叫买价2 */
		AddField((void*)&BidQty2,sizeof(BidQty2),NULL,0,bces_rulearray+BCESFieldIndexBidQty2);	/* 叫买量2 */
		AddField((void*)&AskPrice2,sizeof(AskPrice2),NULL,0,bces_rulearray+BCESFieldIndexAskPrice2);	/* 叫卖价2 */
		AddField((void*)&AskQty2,sizeof(AskQty2),NULL,0,bces_rulearray+BCESFieldIndexAskQty2);	/* 叫卖量2 */
		AddField((void*)&BidPrice3,sizeof(BidPrice3),NULL,0,bces_rulearray+BCESFieldIndexBidPrice3);	/* 叫买价3 */
		AddField((void*)&BidQty3,sizeof(BidQty3),NULL,0,bces_rulearray+BCESFieldIndexBidQty3);	/* 叫买量3 */
		AddField((void*)&AskPrice3,sizeof(AskPrice3),NULL,0,bces_rulearray+BCESFieldIndexAskPrice3);	/* 叫卖价3 */
		AddField((void*)&AskQty3,sizeof(AskQty3),NULL,0,bces_rulearray+BCESFieldIndexAskQty3);	/* 叫卖量3 */
		AddField((void*)&BidPrice4,sizeof(BidPrice4),NULL,0,bces_rulearray+BCESFieldIndexBidPrice4);	/* 叫买价4 */
		AddField((void*)&BidQty4,sizeof(BidQty4),NULL,0,bces_rulearray+BCESFieldIndexBidQty4);	/* 叫买量4 */
		AddField((void*)&AskPrice4,sizeof(AskPrice4),NULL,0,bces_rulearray+BCESFieldIndexAskPrice4);	/* 叫卖价4 */
		AddField((void*)&AskQty4,sizeof(AskQty4),NULL,0,bces_rulearray+BCESFieldIndexAskQty4);	/* 叫卖量4 */
		AddField((void*)&BidPrice5,sizeof(BidPrice5),NULL,0,bces_rulearray+BCESFieldIndexBidPrice5);	/* 叫买价5 */
		AddField((void*)&BidQty5,sizeof(BidQty5),NULL,0,bces_rulearray+BCESFieldIndexBidQty5);	/* 叫买量5 */
		AddField((void*)&AskPrice5,sizeof(AskPrice5),NULL,0,bces_rulearray+BCESFieldIndexAskPrice5);	/* 叫卖价5 */
		AddField((void*)&AskQty5,sizeof(AskQty5),NULL,0,bces_rulearray+BCESFieldIndexAskQty5);	/* 叫卖量5 */
		AddField((void*)&BidPrice6,sizeof(BidPrice6),NULL,0,bces_rulearray+BCESFieldIndexBidPrice6);	/* 叫买价6 */
		AddField((void*)&BidQty6,sizeof(BidQty6),NULL,0,bces_rulearray+BCESFieldIndexBidQty6);	/* 叫买量6 */
		AddField((void*)&AskPrice6,sizeof(AskPrice6),NULL,0,bces_rulearray+BCESFieldIndexAskPrice6);	/* 叫卖价6 */
		AddField((void*)&AskQty6,sizeof(AskQty6),NULL,0,bces_rulearray+BCESFieldIndexAskQty6);	/* 叫卖量6 */
		AddField((void*)&BidPrice7,sizeof(BidPrice7),NULL,0,bces_rulearray+BCESFieldIndexBidPrice7);	/* 叫买价7 */
		AddField((void*)&BidQty7,sizeof(BidQty7),NULL,0,bces_rulearray+BCESFieldIndexBidQty7);	/* 叫买量7 */
		AddField((void*)&AskPrice7,sizeof(AskPrice7),NULL,0,bces_rulearray+BCESFieldIndexAskPrice7);	/* 叫卖价7 */
		AddField((void*)&AskQty7,sizeof(AskQty7),NULL,0,bces_rulearray+BCESFieldIndexAskQty7);	/* 叫卖量7 */
		AddField((void*)&BidPrice8,sizeof(BidPrice8),NULL,0,bces_rulearray+BCESFieldIndexBidPrice8);	/* 叫买价8 */
		AddField((void*)&BidQty8,sizeof(BidQty8),NULL,0,bces_rulearray+BCESFieldIndexBidQty8);	/* 叫买量8 */
		AddField((void*)&AskPrice8,sizeof(AskPrice8),NULL,0,bces_rulearray+BCESFieldIndexAskPrice8);	/* 叫卖价8 */
		AddField((void*)&AskQty8,sizeof(AskQty8),NULL,0,bces_rulearray+BCESFieldIndexAskQty8);	/* 叫卖量8 */
		AddField((void*)&BidPrice9,sizeof(BidPrice9),NULL,0,bces_rulearray+BCESFieldIndexBidPrice9);	/* 叫买价9 */
		AddField((void*)&BidQty9,sizeof(BidQty9),NULL,0,bces_rulearray+BCESFieldIndexBidQty9);	/* 叫买量9 */
		AddField((void*)&AskPrice9,sizeof(AskPrice9),NULL,0,bces_rulearray+BCESFieldIndexAskPrice9);	/* 叫卖价9 */
		AddField((void*)&AskQty9,sizeof(AskQty9),NULL,0,bces_rulearray+BCESFieldIndexAskQty9);	/* 叫卖量9 */
		AddField((void*)&BidPrice10,sizeof(BidPrice10),NULL,0,bces_rulearray+BCESFieldIndexBidPrice10);	/* 叫买价10 */
		AddField((void*)&BidQty10,sizeof(BidQty10),NULL,0,bces_rulearray+BCESFieldIndexBidQty10);	/* 叫买量10 */
		AddField((void*)&AskPrice10,sizeof(AskPrice10),NULL,0,bces_rulearray+BCESFieldIndexAskPrice10);	/* 叫卖价10 */
		AddField((void*)&AskQty10,sizeof(AskQty10),NULL,0,bces_rulearray+BCESFieldIndexAskQty10);	/* 叫卖量10 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsQuot& operator=(const CBCESFieldsQuot& Quot){
		m_fieldarray=m_fieldarray_Quot;
		m_fieldsize=sizeof(m_fieldarray_Quot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Quot+sizeof(CBMLFields),sizeof(CBCESFieldsQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 现价 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 现手 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 持仓量 */
		AddField((void*)&SettlePrice,sizeof(SettlePrice),NULL,0,bces_rulearray+BCESFieldIndexSettlePrice);	/* 结算价 */
		AddField((void*)&PreClose,sizeof(PreClose),NULL,0,bces_rulearray+BCESFieldIndexPreClose);	/* 昨收盘价 */
		AddField((void*)&PreSettle,sizeof(PreSettle),NULL,0,bces_rulearray+BCESFieldIndexPreSettle);	/* 昨结算价 */
		AddField((void*)&PreOI,sizeof(PreOI),NULL,0,bces_rulearray+BCESFieldIndexPreOI);	/* 昨持仓量 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 更新日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 更新时间 */
		AddField((void*)&BidPrice2,sizeof(BidPrice2),NULL,0,bces_rulearray+BCESFieldIndexBidPrice2);	/* 叫买价2 */
		AddField((void*)&BidQty2,sizeof(BidQty2),NULL,0,bces_rulearray+BCESFieldIndexBidQty2);	/* 叫买量2 */
		AddField((void*)&AskPrice2,sizeof(AskPrice2),NULL,0,bces_rulearray+BCESFieldIndexAskPrice2);	/* 叫卖价2 */
		AddField((void*)&AskQty2,sizeof(AskQty2),NULL,0,bces_rulearray+BCESFieldIndexAskQty2);	/* 叫卖量2 */
		AddField((void*)&BidPrice3,sizeof(BidPrice3),NULL,0,bces_rulearray+BCESFieldIndexBidPrice3);	/* 叫买价3 */
		AddField((void*)&BidQty3,sizeof(BidQty3),NULL,0,bces_rulearray+BCESFieldIndexBidQty3);	/* 叫买量3 */
		AddField((void*)&AskPrice3,sizeof(AskPrice3),NULL,0,bces_rulearray+BCESFieldIndexAskPrice3);	/* 叫卖价3 */
		AddField((void*)&AskQty3,sizeof(AskQty3),NULL,0,bces_rulearray+BCESFieldIndexAskQty3);	/* 叫卖量3 */
		AddField((void*)&BidPrice4,sizeof(BidPrice4),NULL,0,bces_rulearray+BCESFieldIndexBidPrice4);	/* 叫买价4 */
		AddField((void*)&BidQty4,sizeof(BidQty4),NULL,0,bces_rulearray+BCESFieldIndexBidQty4);	/* 叫买量4 */
		AddField((void*)&AskPrice4,sizeof(AskPrice4),NULL,0,bces_rulearray+BCESFieldIndexAskPrice4);	/* 叫卖价4 */
		AddField((void*)&AskQty4,sizeof(AskQty4),NULL,0,bces_rulearray+BCESFieldIndexAskQty4);	/* 叫卖量4 */
		AddField((void*)&BidPrice5,sizeof(BidPrice5),NULL,0,bces_rulearray+BCESFieldIndexBidPrice5);	/* 叫买价5 */
		AddField((void*)&BidQty5,sizeof(BidQty5),NULL,0,bces_rulearray+BCESFieldIndexBidQty5);	/* 叫买量5 */
		AddField((void*)&AskPrice5,sizeof(AskPrice5),NULL,0,bces_rulearray+BCESFieldIndexAskPrice5);	/* 叫卖价5 */
		AddField((void*)&AskQty5,sizeof(AskQty5),NULL,0,bces_rulearray+BCESFieldIndexAskQty5);	/* 叫卖量5 */
		AddField((void*)&BidPrice6,sizeof(BidPrice6),NULL,0,bces_rulearray+BCESFieldIndexBidPrice6);	/* 叫买价6 */
		AddField((void*)&BidQty6,sizeof(BidQty6),NULL,0,bces_rulearray+BCESFieldIndexBidQty6);	/* 叫买量6 */
		AddField((void*)&AskPrice6,sizeof(AskPrice6),NULL,0,bces_rulearray+BCESFieldIndexAskPrice6);	/* 叫卖价6 */
		AddField((void*)&AskQty6,sizeof(AskQty6),NULL,0,bces_rulearray+BCESFieldIndexAskQty6);	/* 叫卖量6 */
		AddField((void*)&BidPrice7,sizeof(BidPrice7),NULL,0,bces_rulearray+BCESFieldIndexBidPrice7);	/* 叫买价7 */
		AddField((void*)&BidQty7,sizeof(BidQty7),NULL,0,bces_rulearray+BCESFieldIndexBidQty7);	/* 叫买量7 */
		AddField((void*)&AskPrice7,sizeof(AskPrice7),NULL,0,bces_rulearray+BCESFieldIndexAskPrice7);	/* 叫卖价7 */
		AddField((void*)&AskQty7,sizeof(AskQty7),NULL,0,bces_rulearray+BCESFieldIndexAskQty7);	/* 叫卖量7 */
		AddField((void*)&BidPrice8,sizeof(BidPrice8),NULL,0,bces_rulearray+BCESFieldIndexBidPrice8);	/* 叫买价8 */
		AddField((void*)&BidQty8,sizeof(BidQty8),NULL,0,bces_rulearray+BCESFieldIndexBidQty8);	/* 叫买量8 */
		AddField((void*)&AskPrice8,sizeof(AskPrice8),NULL,0,bces_rulearray+BCESFieldIndexAskPrice8);	/* 叫卖价8 */
		AddField((void*)&AskQty8,sizeof(AskQty8),NULL,0,bces_rulearray+BCESFieldIndexAskQty8);	/* 叫卖量8 */
		AddField((void*)&BidPrice9,sizeof(BidPrice9),NULL,0,bces_rulearray+BCESFieldIndexBidPrice9);	/* 叫买价9 */
		AddField((void*)&BidQty9,sizeof(BidQty9),NULL,0,bces_rulearray+BCESFieldIndexBidQty9);	/* 叫买量9 */
		AddField((void*)&AskPrice9,sizeof(AskPrice9),NULL,0,bces_rulearray+BCESFieldIndexAskPrice9);	/* 叫卖价9 */
		AddField((void*)&AskQty9,sizeof(AskQty9),NULL,0,bces_rulearray+BCESFieldIndexAskQty9);	/* 叫卖量9 */
		AddField((void*)&BidPrice10,sizeof(BidPrice10),NULL,0,bces_rulearray+BCESFieldIndexBidPrice10);	/* 叫买价10 */
		AddField((void*)&BidQty10,sizeof(BidQty10),NULL,0,bces_rulearray+BCESFieldIndexBidQty10);	/* 叫买量10 */
		AddField((void*)&AskPrice10,sizeof(AskPrice10),NULL,0,bces_rulearray+BCESFieldIndexAskPrice10);	/* 叫卖价10 */
		AddField((void*)&AskQty10,sizeof(AskQty10),NULL,0,bces_rulearray+BCESFieldIndexAskQty10);	/* 叫卖量10 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Quot),0x00,sizeof(CBCESFieldsQuot)-sizeof(CBMLFields)-sizeof(m_fieldarray_Quot));
	}

	BML_FIELD_INFO m_fieldarray_Quot[61];

	// Field
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
class CBCESFieldsInternationalQuot:public CBMLFields
{
public:
	CBCESFieldsInternationalQuot()
	{
		m_fieldarray=m_fieldarray_InternationalQuot;
		m_fieldsize=sizeof(m_fieldarray_InternationalQuot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInternationalQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 现价 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 现手 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 持仓量 */
		AddField((void*)&SettlePrice,sizeof(SettlePrice),NULL,0,bces_rulearray+BCESFieldIndexSettlePrice);	/* 结算价 */
		AddField((void*)&PreClose,sizeof(PreClose),NULL,0,bces_rulearray+BCESFieldIndexPreClose);	/* 昨收盘价 */
		AddField((void*)&PreSettle,sizeof(PreSettle),NULL,0,bces_rulearray+BCESFieldIndexPreSettle);	/* 昨结算价 */
		AddField((void*)&PreOI,sizeof(PreOI),NULL,0,bces_rulearray+BCESFieldIndexPreOI);	/* 昨持仓量 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 更新日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 更新时间 */
		AddField((void*)&BidPrice2,sizeof(BidPrice2),NULL,0,bces_rulearray+BCESFieldIndexBidPrice2);	/* 叫买价2 */
		AddField((void*)&BidQty2,sizeof(BidQty2),NULL,0,bces_rulearray+BCESFieldIndexBidQty2);	/* 叫买量2 */
		AddField((void*)&AskPrice2,sizeof(AskPrice2),NULL,0,bces_rulearray+BCESFieldIndexAskPrice2);	/* 叫卖价2 */
		AddField((void*)&AskQty2,sizeof(AskQty2),NULL,0,bces_rulearray+BCESFieldIndexAskQty2);	/* 叫卖量2 */
		AddField((void*)&BidPrice3,sizeof(BidPrice3),NULL,0,bces_rulearray+BCESFieldIndexBidPrice3);	/* 叫买价3 */
		AddField((void*)&BidQty3,sizeof(BidQty3),NULL,0,bces_rulearray+BCESFieldIndexBidQty3);	/* 叫买量3 */
		AddField((void*)&AskPrice3,sizeof(AskPrice3),NULL,0,bces_rulearray+BCESFieldIndexAskPrice3);	/* 叫卖价3 */
		AddField((void*)&AskQty3,sizeof(AskQty3),NULL,0,bces_rulearray+BCESFieldIndexAskQty3);	/* 叫卖量3 */
		AddField((void*)&BidPrice4,sizeof(BidPrice4),NULL,0,bces_rulearray+BCESFieldIndexBidPrice4);	/* 叫买价4 */
		AddField((void*)&BidQty4,sizeof(BidQty4),NULL,0,bces_rulearray+BCESFieldIndexBidQty4);	/* 叫买量4 */
		AddField((void*)&AskPrice4,sizeof(AskPrice4),NULL,0,bces_rulearray+BCESFieldIndexAskPrice4);	/* 叫卖价4 */
		AddField((void*)&AskQty4,sizeof(AskQty4),NULL,0,bces_rulearray+BCESFieldIndexAskQty4);	/* 叫卖量4 */
		AddField((void*)&BidPrice5,sizeof(BidPrice5),NULL,0,bces_rulearray+BCESFieldIndexBidPrice5);	/* 叫买价5 */
		AddField((void*)&BidQty5,sizeof(BidQty5),NULL,0,bces_rulearray+BCESFieldIndexBidQty5);	/* 叫买量5 */
		AddField((void*)&AskPrice5,sizeof(AskPrice5),NULL,0,bces_rulearray+BCESFieldIndexAskPrice5);	/* 叫卖价5 */
		AddField((void*)&AskQty5,sizeof(AskQty5),NULL,0,bces_rulearray+BCESFieldIndexAskQty5);	/* 叫卖量5 */
		AddField((void*)&BidPrice6,sizeof(BidPrice6),NULL,0,bces_rulearray+BCESFieldIndexBidPrice6);	/* 叫买价6 */
		AddField((void*)&BidQty6,sizeof(BidQty6),NULL,0,bces_rulearray+BCESFieldIndexBidQty6);	/* 叫买量6 */
		AddField((void*)&AskPrice6,sizeof(AskPrice6),NULL,0,bces_rulearray+BCESFieldIndexAskPrice6);	/* 叫卖价6 */
		AddField((void*)&AskQty6,sizeof(AskQty6),NULL,0,bces_rulearray+BCESFieldIndexAskQty6);	/* 叫卖量6 */
		AddField((void*)&BidPrice7,sizeof(BidPrice7),NULL,0,bces_rulearray+BCESFieldIndexBidPrice7);	/* 叫买价7 */
		AddField((void*)&BidQty7,sizeof(BidQty7),NULL,0,bces_rulearray+BCESFieldIndexBidQty7);	/* 叫买量7 */
		AddField((void*)&AskPrice7,sizeof(AskPrice7),NULL,0,bces_rulearray+BCESFieldIndexAskPrice7);	/* 叫卖价7 */
		AddField((void*)&AskQty7,sizeof(AskQty7),NULL,0,bces_rulearray+BCESFieldIndexAskQty7);	/* 叫卖量7 */
		AddField((void*)&BidPrice8,sizeof(BidPrice8),NULL,0,bces_rulearray+BCESFieldIndexBidPrice8);	/* 叫买价8 */
		AddField((void*)&BidQty8,sizeof(BidQty8),NULL,0,bces_rulearray+BCESFieldIndexBidQty8);	/* 叫买量8 */
		AddField((void*)&AskPrice8,sizeof(AskPrice8),NULL,0,bces_rulearray+BCESFieldIndexAskPrice8);	/* 叫卖价8 */
		AddField((void*)&AskQty8,sizeof(AskQty8),NULL,0,bces_rulearray+BCESFieldIndexAskQty8);	/* 叫卖量8 */
		AddField((void*)&BidPrice9,sizeof(BidPrice9),NULL,0,bces_rulearray+BCESFieldIndexBidPrice9);	/* 叫买价9 */
		AddField((void*)&BidQty9,sizeof(BidQty9),NULL,0,bces_rulearray+BCESFieldIndexBidQty9);	/* 叫买量9 */
		AddField((void*)&AskPrice9,sizeof(AskPrice9),NULL,0,bces_rulearray+BCESFieldIndexAskPrice9);	/* 叫卖价9 */
		AddField((void*)&AskQty9,sizeof(AskQty9),NULL,0,bces_rulearray+BCESFieldIndexAskQty9);	/* 叫卖量9 */
		AddField((void*)&BidPrice10,sizeof(BidPrice10),NULL,0,bces_rulearray+BCESFieldIndexBidPrice10);	/* 叫买价10 */
		AddField((void*)&BidQty10,sizeof(BidQty10),NULL,0,bces_rulearray+BCESFieldIndexBidQty10);	/* 叫买量10 */
		AddField((void*)&AskPrice10,sizeof(AskPrice10),NULL,0,bces_rulearray+BCESFieldIndexAskPrice10);	/* 叫卖价10 */
		AddField((void*)&AskQty10,sizeof(AskQty10),NULL,0,bces_rulearray+BCESFieldIndexAskQty10);	/* 叫卖量10 */
		AddField((void*)GoodsName,sizeof(GoodsName),NULL,0,bces_rulearray+BCESFieldIndexGoodsName);	/* 品种大类 */
	}
	CBCESFieldsInternationalQuot(const CBCESFieldsInternationalQuot& InternationalQuot){
		m_fieldarray=m_fieldarray_InternationalQuot;
		m_fieldsize=sizeof(m_fieldarray_InternationalQuot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InternationalQuot+sizeof(CBMLFields),sizeof(CBCESFieldsInternationalQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 现价 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 现手 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 持仓量 */
		AddField((void*)&SettlePrice,sizeof(SettlePrice),NULL,0,bces_rulearray+BCESFieldIndexSettlePrice);	/* 结算价 */
		AddField((void*)&PreClose,sizeof(PreClose),NULL,0,bces_rulearray+BCESFieldIndexPreClose);	/* 昨收盘价 */
		AddField((void*)&PreSettle,sizeof(PreSettle),NULL,0,bces_rulearray+BCESFieldIndexPreSettle);	/* 昨结算价 */
		AddField((void*)&PreOI,sizeof(PreOI),NULL,0,bces_rulearray+BCESFieldIndexPreOI);	/* 昨持仓量 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 更新日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 更新时间 */
		AddField((void*)&BidPrice2,sizeof(BidPrice2),NULL,0,bces_rulearray+BCESFieldIndexBidPrice2);	/* 叫买价2 */
		AddField((void*)&BidQty2,sizeof(BidQty2),NULL,0,bces_rulearray+BCESFieldIndexBidQty2);	/* 叫买量2 */
		AddField((void*)&AskPrice2,sizeof(AskPrice2),NULL,0,bces_rulearray+BCESFieldIndexAskPrice2);	/* 叫卖价2 */
		AddField((void*)&AskQty2,sizeof(AskQty2),NULL,0,bces_rulearray+BCESFieldIndexAskQty2);	/* 叫卖量2 */
		AddField((void*)&BidPrice3,sizeof(BidPrice3),NULL,0,bces_rulearray+BCESFieldIndexBidPrice3);	/* 叫买价3 */
		AddField((void*)&BidQty3,sizeof(BidQty3),NULL,0,bces_rulearray+BCESFieldIndexBidQty3);	/* 叫买量3 */
		AddField((void*)&AskPrice3,sizeof(AskPrice3),NULL,0,bces_rulearray+BCESFieldIndexAskPrice3);	/* 叫卖价3 */
		AddField((void*)&AskQty3,sizeof(AskQty3),NULL,0,bces_rulearray+BCESFieldIndexAskQty3);	/* 叫卖量3 */
		AddField((void*)&BidPrice4,sizeof(BidPrice4),NULL,0,bces_rulearray+BCESFieldIndexBidPrice4);	/* 叫买价4 */
		AddField((void*)&BidQty4,sizeof(BidQty4),NULL,0,bces_rulearray+BCESFieldIndexBidQty4);	/* 叫买量4 */
		AddField((void*)&AskPrice4,sizeof(AskPrice4),NULL,0,bces_rulearray+BCESFieldIndexAskPrice4);	/* 叫卖价4 */
		AddField((void*)&AskQty4,sizeof(AskQty4),NULL,0,bces_rulearray+BCESFieldIndexAskQty4);	/* 叫卖量4 */
		AddField((void*)&BidPrice5,sizeof(BidPrice5),NULL,0,bces_rulearray+BCESFieldIndexBidPrice5);	/* 叫买价5 */
		AddField((void*)&BidQty5,sizeof(BidQty5),NULL,0,bces_rulearray+BCESFieldIndexBidQty5);	/* 叫买量5 */
		AddField((void*)&AskPrice5,sizeof(AskPrice5),NULL,0,bces_rulearray+BCESFieldIndexAskPrice5);	/* 叫卖价5 */
		AddField((void*)&AskQty5,sizeof(AskQty5),NULL,0,bces_rulearray+BCESFieldIndexAskQty5);	/* 叫卖量5 */
		AddField((void*)&BidPrice6,sizeof(BidPrice6),NULL,0,bces_rulearray+BCESFieldIndexBidPrice6);	/* 叫买价6 */
		AddField((void*)&BidQty6,sizeof(BidQty6),NULL,0,bces_rulearray+BCESFieldIndexBidQty6);	/* 叫买量6 */
		AddField((void*)&AskPrice6,sizeof(AskPrice6),NULL,0,bces_rulearray+BCESFieldIndexAskPrice6);	/* 叫卖价6 */
		AddField((void*)&AskQty6,sizeof(AskQty6),NULL,0,bces_rulearray+BCESFieldIndexAskQty6);	/* 叫卖量6 */
		AddField((void*)&BidPrice7,sizeof(BidPrice7),NULL,0,bces_rulearray+BCESFieldIndexBidPrice7);	/* 叫买价7 */
		AddField((void*)&BidQty7,sizeof(BidQty7),NULL,0,bces_rulearray+BCESFieldIndexBidQty7);	/* 叫买量7 */
		AddField((void*)&AskPrice7,sizeof(AskPrice7),NULL,0,bces_rulearray+BCESFieldIndexAskPrice7);	/* 叫卖价7 */
		AddField((void*)&AskQty7,sizeof(AskQty7),NULL,0,bces_rulearray+BCESFieldIndexAskQty7);	/* 叫卖量7 */
		AddField((void*)&BidPrice8,sizeof(BidPrice8),NULL,0,bces_rulearray+BCESFieldIndexBidPrice8);	/* 叫买价8 */
		AddField((void*)&BidQty8,sizeof(BidQty8),NULL,0,bces_rulearray+BCESFieldIndexBidQty8);	/* 叫买量8 */
		AddField((void*)&AskPrice8,sizeof(AskPrice8),NULL,0,bces_rulearray+BCESFieldIndexAskPrice8);	/* 叫卖价8 */
		AddField((void*)&AskQty8,sizeof(AskQty8),NULL,0,bces_rulearray+BCESFieldIndexAskQty8);	/* 叫卖量8 */
		AddField((void*)&BidPrice9,sizeof(BidPrice9),NULL,0,bces_rulearray+BCESFieldIndexBidPrice9);	/* 叫买价9 */
		AddField((void*)&BidQty9,sizeof(BidQty9),NULL,0,bces_rulearray+BCESFieldIndexBidQty9);	/* 叫买量9 */
		AddField((void*)&AskPrice9,sizeof(AskPrice9),NULL,0,bces_rulearray+BCESFieldIndexAskPrice9);	/* 叫卖价9 */
		AddField((void*)&AskQty9,sizeof(AskQty9),NULL,0,bces_rulearray+BCESFieldIndexAskQty9);	/* 叫卖量9 */
		AddField((void*)&BidPrice10,sizeof(BidPrice10),NULL,0,bces_rulearray+BCESFieldIndexBidPrice10);	/* 叫买价10 */
		AddField((void*)&BidQty10,sizeof(BidQty10),NULL,0,bces_rulearray+BCESFieldIndexBidQty10);	/* 叫买量10 */
		AddField((void*)&AskPrice10,sizeof(AskPrice10),NULL,0,bces_rulearray+BCESFieldIndexAskPrice10);	/* 叫卖价10 */
		AddField((void*)&AskQty10,sizeof(AskQty10),NULL,0,bces_rulearray+BCESFieldIndexAskQty10);	/* 叫卖量10 */
		AddField((void*)GoodsName,sizeof(GoodsName),NULL,0,bces_rulearray+BCESFieldIndexGoodsName);	/* 品种大类 */
	}
	CBCESFieldsInternationalQuot& operator=(const CBCESFieldsInternationalQuot& InternationalQuot){
		m_fieldarray=m_fieldarray_InternationalQuot;
		m_fieldsize=sizeof(m_fieldarray_InternationalQuot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InternationalQuot+sizeof(CBMLFields),sizeof(CBCESFieldsInternationalQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 现价 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 现手 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 持仓量 */
		AddField((void*)&SettlePrice,sizeof(SettlePrice),NULL,0,bces_rulearray+BCESFieldIndexSettlePrice);	/* 结算价 */
		AddField((void*)&PreClose,sizeof(PreClose),NULL,0,bces_rulearray+BCESFieldIndexPreClose);	/* 昨收盘价 */
		AddField((void*)&PreSettle,sizeof(PreSettle),NULL,0,bces_rulearray+BCESFieldIndexPreSettle);	/* 昨结算价 */
		AddField((void*)&PreOI,sizeof(PreOI),NULL,0,bces_rulearray+BCESFieldIndexPreOI);	/* 昨持仓量 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ModifyDate,sizeof(ModifyDate),NULL,0,bces_rulearray+BCESFieldIndexModifyDate);	/* 更新日期 */
		AddField((void*)ModifyTime,sizeof(ModifyTime),NULL,0,bces_rulearray+BCESFieldIndexModifyTime);	/* 更新时间 */
		AddField((void*)&BidPrice2,sizeof(BidPrice2),NULL,0,bces_rulearray+BCESFieldIndexBidPrice2);	/* 叫买价2 */
		AddField((void*)&BidQty2,sizeof(BidQty2),NULL,0,bces_rulearray+BCESFieldIndexBidQty2);	/* 叫买量2 */
		AddField((void*)&AskPrice2,sizeof(AskPrice2),NULL,0,bces_rulearray+BCESFieldIndexAskPrice2);	/* 叫卖价2 */
		AddField((void*)&AskQty2,sizeof(AskQty2),NULL,0,bces_rulearray+BCESFieldIndexAskQty2);	/* 叫卖量2 */
		AddField((void*)&BidPrice3,sizeof(BidPrice3),NULL,0,bces_rulearray+BCESFieldIndexBidPrice3);	/* 叫买价3 */
		AddField((void*)&BidQty3,sizeof(BidQty3),NULL,0,bces_rulearray+BCESFieldIndexBidQty3);	/* 叫买量3 */
		AddField((void*)&AskPrice3,sizeof(AskPrice3),NULL,0,bces_rulearray+BCESFieldIndexAskPrice3);	/* 叫卖价3 */
		AddField((void*)&AskQty3,sizeof(AskQty3),NULL,0,bces_rulearray+BCESFieldIndexAskQty3);	/* 叫卖量3 */
		AddField((void*)&BidPrice4,sizeof(BidPrice4),NULL,0,bces_rulearray+BCESFieldIndexBidPrice4);	/* 叫买价4 */
		AddField((void*)&BidQty4,sizeof(BidQty4),NULL,0,bces_rulearray+BCESFieldIndexBidQty4);	/* 叫买量4 */
		AddField((void*)&AskPrice4,sizeof(AskPrice4),NULL,0,bces_rulearray+BCESFieldIndexAskPrice4);	/* 叫卖价4 */
		AddField((void*)&AskQty4,sizeof(AskQty4),NULL,0,bces_rulearray+BCESFieldIndexAskQty4);	/* 叫卖量4 */
		AddField((void*)&BidPrice5,sizeof(BidPrice5),NULL,0,bces_rulearray+BCESFieldIndexBidPrice5);	/* 叫买价5 */
		AddField((void*)&BidQty5,sizeof(BidQty5),NULL,0,bces_rulearray+BCESFieldIndexBidQty5);	/* 叫买量5 */
		AddField((void*)&AskPrice5,sizeof(AskPrice5),NULL,0,bces_rulearray+BCESFieldIndexAskPrice5);	/* 叫卖价5 */
		AddField((void*)&AskQty5,sizeof(AskQty5),NULL,0,bces_rulearray+BCESFieldIndexAskQty5);	/* 叫卖量5 */
		AddField((void*)&BidPrice6,sizeof(BidPrice6),NULL,0,bces_rulearray+BCESFieldIndexBidPrice6);	/* 叫买价6 */
		AddField((void*)&BidQty6,sizeof(BidQty6),NULL,0,bces_rulearray+BCESFieldIndexBidQty6);	/* 叫买量6 */
		AddField((void*)&AskPrice6,sizeof(AskPrice6),NULL,0,bces_rulearray+BCESFieldIndexAskPrice6);	/* 叫卖价6 */
		AddField((void*)&AskQty6,sizeof(AskQty6),NULL,0,bces_rulearray+BCESFieldIndexAskQty6);	/* 叫卖量6 */
		AddField((void*)&BidPrice7,sizeof(BidPrice7),NULL,0,bces_rulearray+BCESFieldIndexBidPrice7);	/* 叫买价7 */
		AddField((void*)&BidQty7,sizeof(BidQty7),NULL,0,bces_rulearray+BCESFieldIndexBidQty7);	/* 叫买量7 */
		AddField((void*)&AskPrice7,sizeof(AskPrice7),NULL,0,bces_rulearray+BCESFieldIndexAskPrice7);	/* 叫卖价7 */
		AddField((void*)&AskQty7,sizeof(AskQty7),NULL,0,bces_rulearray+BCESFieldIndexAskQty7);	/* 叫卖量7 */
		AddField((void*)&BidPrice8,sizeof(BidPrice8),NULL,0,bces_rulearray+BCESFieldIndexBidPrice8);	/* 叫买价8 */
		AddField((void*)&BidQty8,sizeof(BidQty8),NULL,0,bces_rulearray+BCESFieldIndexBidQty8);	/* 叫买量8 */
		AddField((void*)&AskPrice8,sizeof(AskPrice8),NULL,0,bces_rulearray+BCESFieldIndexAskPrice8);	/* 叫卖价8 */
		AddField((void*)&AskQty8,sizeof(AskQty8),NULL,0,bces_rulearray+BCESFieldIndexAskQty8);	/* 叫卖量8 */
		AddField((void*)&BidPrice9,sizeof(BidPrice9),NULL,0,bces_rulearray+BCESFieldIndexBidPrice9);	/* 叫买价9 */
		AddField((void*)&BidQty9,sizeof(BidQty9),NULL,0,bces_rulearray+BCESFieldIndexBidQty9);	/* 叫买量9 */
		AddField((void*)&AskPrice9,sizeof(AskPrice9),NULL,0,bces_rulearray+BCESFieldIndexAskPrice9);	/* 叫卖价9 */
		AddField((void*)&AskQty9,sizeof(AskQty9),NULL,0,bces_rulearray+BCESFieldIndexAskQty9);	/* 叫卖量9 */
		AddField((void*)&BidPrice10,sizeof(BidPrice10),NULL,0,bces_rulearray+BCESFieldIndexBidPrice10);	/* 叫买价10 */
		AddField((void*)&BidQty10,sizeof(BidQty10),NULL,0,bces_rulearray+BCESFieldIndexBidQty10);	/* 叫买量10 */
		AddField((void*)&AskPrice10,sizeof(AskPrice10),NULL,0,bces_rulearray+BCESFieldIndexAskPrice10);	/* 叫卖价10 */
		AddField((void*)&AskQty10,sizeof(AskQty10),NULL,0,bces_rulearray+BCESFieldIndexAskQty10);	/* 叫卖量10 */
		AddField((void*)GoodsName,sizeof(GoodsName),NULL,0,bces_rulearray+BCESFieldIndexGoodsName);	/* 品种大类 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InternationalQuot),0x00,sizeof(CBCESFieldsInternationalQuot)-sizeof(CBMLFields)-sizeof(m_fieldarray_InternationalQuot));
	}

	BML_FIELD_INFO m_fieldarray_InternationalQuot[58];

	// Field
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
class CBCESFieldsQuotQueryReq:public CBMLFields
{
public:
	CBCESFieldsQuotQueryReq()
	{
		m_fieldarray=m_fieldarray_QuotQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsQuotQueryReq(const CBCESFieldsQuotQueryReq& QuotQueryReq){
		m_fieldarray=m_fieldarray_QuotQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsQuotQueryReq& operator=(const CBCESFieldsQuotQueryReq& QuotQueryReq){
		m_fieldarray=m_fieldarray_QuotQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotQueryReq),0x00,sizeof(CBCESFieldsQuotQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_QuotQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 订单查询请求 */
class CBCESFieldsOrderQueryReq:public CBMLFields
{
public:
	CBCESFieldsOrderQueryReq()
	{
		m_fieldarray=m_fieldarray_OrderQueryReq;
		m_fieldsize=sizeof(m_fieldarray_OrderQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsOrderQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsOrderQueryReq(const CBCESFieldsOrderQueryReq& OrderQueryReq){
		m_fieldarray=m_fieldarray_OrderQueryReq;
		m_fieldsize=sizeof(m_fieldarray_OrderQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&OrderQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsOrderQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsOrderQueryReq& operator=(const CBCESFieldsOrderQueryReq& OrderQueryReq){
		m_fieldarray=m_fieldarray_OrderQueryReq;
		m_fieldsize=sizeof(m_fieldarray_OrderQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&OrderQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsOrderQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_OrderQueryReq),0x00,sizeof(CBCESFieldsOrderQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_OrderQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_OrderQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 成交查询请求 */
class CBCESFieldsTradeQueryReq:public CBMLFields
{
public:
	CBCESFieldsTradeQueryReq()
	{
		m_fieldarray=m_fieldarray_TradeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsTradeQueryReq(const CBCESFieldsTradeQueryReq& TradeQueryReq){
		m_fieldarray=m_fieldarray_TradeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsTradeQueryReq& operator=(const CBCESFieldsTradeQueryReq& TradeQueryReq){
		m_fieldarray=m_fieldarray_TradeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeQueryReq),0x00,sizeof(CBCESFieldsTradeQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_TradeQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 持仓查询 */
class CBCESFieldsPosiQueryReq:public CBMLFields
{
public:
	CBCESFieldsPosiQueryReq()
	{
		m_fieldarray=m_fieldarray_PosiQueryReq;
		m_fieldsize=sizeof(m_fieldarray_PosiQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsPosiQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsPosiQueryReq(const CBCESFieldsPosiQueryReq& PosiQueryReq){
		m_fieldarray=m_fieldarray_PosiQueryReq;
		m_fieldsize=sizeof(m_fieldarray_PosiQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&PosiQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsPosiQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsPosiQueryReq& operator=(const CBCESFieldsPosiQueryReq& PosiQueryReq){
		m_fieldarray=m_fieldarray_PosiQueryReq;
		m_fieldsize=sizeof(m_fieldarray_PosiQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&PosiQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsPosiQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_PosiQueryReq),0x00,sizeof(CBCESFieldsPosiQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_PosiQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_PosiQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 持仓明细查询 */
class CBCESFieldsPosiDetailQueryReq:public CBMLFields
{
public:
	CBCESFieldsPosiDetailQueryReq()
	{
		m_fieldarray=m_fieldarray_PosiDetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_PosiDetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsPosiDetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsPosiDetailQueryReq(const CBCESFieldsPosiDetailQueryReq& PosiDetailQueryReq){
		m_fieldarray=m_fieldarray_PosiDetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_PosiDetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&PosiDetailQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsPosiDetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsPosiDetailQueryReq& operator=(const CBCESFieldsPosiDetailQueryReq& PosiDetailQueryReq){
		m_fieldarray=m_fieldarray_PosiDetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_PosiDetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&PosiDetailQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsPosiDetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_PosiDetailQueryReq),0x00,sizeof(CBCESFieldsPosiDetailQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_PosiDetailQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_PosiDetailQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 历史持仓明细查询 */
class CBCESFieldsHisPosiDetailQueryReq:public CBMLFields
{
public:
	CBCESFieldsHisPosiDetailQueryReq()
	{
		m_fieldarray=m_fieldarray_HisPosiDetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisPosiDetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHisPosiDetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsHisPosiDetailQueryReq(const CBCESFieldsHisPosiDetailQueryReq& HisPosiDetailQueryReq){
		m_fieldarray=m_fieldarray_HisPosiDetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisPosiDetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisPosiDetailQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisPosiDetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsHisPosiDetailQueryReq& operator=(const CBCESFieldsHisPosiDetailQueryReq& HisPosiDetailQueryReq){
		m_fieldarray=m_fieldarray_HisPosiDetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisPosiDetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisPosiDetailQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisPosiDetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_HisPosiDetailQueryReq),0x00,sizeof(CBCESFieldsHisPosiDetailQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_HisPosiDetailQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_HisPosiDetailQueryReq[5];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 持仓 */
class CBCESFieldsPosi:public CBMLFields
{
public:
	CBCESFieldsPosi()
	{
		m_fieldarray=m_fieldarray_Posi;
		m_fieldsize=sizeof(m_fieldarray_Posi)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsPosi)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BuyQty,sizeof(BuyQty),NULL,0,bces_rulearray+BCESFieldIndexBuyQty);	/* 买持仓量 */
		AddField((void*)&BuyPrice,sizeof(BuyPrice),NULL,0,bces_rulearray+BCESFieldIndexBuyPrice);	/* 买持仓均价 */
		AddField((void*)&SellQty,sizeof(SellQty),NULL,0,bces_rulearray+BCESFieldIndexSellQty);	/* 卖持仓量 */
		AddField((void*)&SellPrice,sizeof(SellPrice),NULL,0,bces_rulearray+BCESFieldIndexSellPrice);	/* 卖持仓均价 */
		AddField((void*)&BuyQtyFrozen,sizeof(BuyQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexBuyQtyFrozen);	/* 买冻结持仓量 */
		AddField((void*)&SellQtyFrozen,sizeof(SellQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexSellQtyFrozen);	/* 卖冻结持仓量 */
		AddField((void*)&PreBuyQty,sizeof(PreBuyQty),NULL,0,bces_rulearray+BCESFieldIndexPreBuyQty);	/* 昨买持仓量 */
		AddField((void*)&PreSellQty,sizeof(PreSellQty),NULL,0,bces_rulearray+BCESFieldIndexPreSellQty);	/* 昨卖持仓量 */
		AddField((void*)&TodayBuyQty,sizeof(TodayBuyQty),NULL,0,bces_rulearray+BCESFieldIndexTodayBuyQty);	/* 今买持仓量 */
		AddField((void*)&TodaySellQty,sizeof(TodaySellQty),NULL,0,bces_rulearray+BCESFieldIndexTodaySellQty);	/* 今卖持仓量 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&TodayBuyQtyFrozen,sizeof(TodayBuyQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexTodayBuyQtyFrozen);	/* 今买冻结持仓量 */
		AddField((void*)&TodaySellQtyFrozen,sizeof(TodaySellQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexTodaySellQtyFrozen);	/* 今卖冻结持仓量 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&FeeFrozen,sizeof(FeeFrozen),NULL,0,bces_rulearray+BCESFieldIndexFeeFrozen);	/* 冻结手续费 */
	}
	CBCESFieldsPosi(const CBCESFieldsPosi& Posi){
		m_fieldarray=m_fieldarray_Posi;
		m_fieldsize=sizeof(m_fieldarray_Posi)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Posi+sizeof(CBMLFields),sizeof(CBCESFieldsPosi)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BuyQty,sizeof(BuyQty),NULL,0,bces_rulearray+BCESFieldIndexBuyQty);	/* 买持仓量 */
		AddField((void*)&BuyPrice,sizeof(BuyPrice),NULL,0,bces_rulearray+BCESFieldIndexBuyPrice);	/* 买持仓均价 */
		AddField((void*)&SellQty,sizeof(SellQty),NULL,0,bces_rulearray+BCESFieldIndexSellQty);	/* 卖持仓量 */
		AddField((void*)&SellPrice,sizeof(SellPrice),NULL,0,bces_rulearray+BCESFieldIndexSellPrice);	/* 卖持仓均价 */
		AddField((void*)&BuyQtyFrozen,sizeof(BuyQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexBuyQtyFrozen);	/* 买冻结持仓量 */
		AddField((void*)&SellQtyFrozen,sizeof(SellQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexSellQtyFrozen);	/* 卖冻结持仓量 */
		AddField((void*)&PreBuyQty,sizeof(PreBuyQty),NULL,0,bces_rulearray+BCESFieldIndexPreBuyQty);	/* 昨买持仓量 */
		AddField((void*)&PreSellQty,sizeof(PreSellQty),NULL,0,bces_rulearray+BCESFieldIndexPreSellQty);	/* 昨卖持仓量 */
		AddField((void*)&TodayBuyQty,sizeof(TodayBuyQty),NULL,0,bces_rulearray+BCESFieldIndexTodayBuyQty);	/* 今买持仓量 */
		AddField((void*)&TodaySellQty,sizeof(TodaySellQty),NULL,0,bces_rulearray+BCESFieldIndexTodaySellQty);	/* 今卖持仓量 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&TodayBuyQtyFrozen,sizeof(TodayBuyQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexTodayBuyQtyFrozen);	/* 今买冻结持仓量 */
		AddField((void*)&TodaySellQtyFrozen,sizeof(TodaySellQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexTodaySellQtyFrozen);	/* 今卖冻结持仓量 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&FeeFrozen,sizeof(FeeFrozen),NULL,0,bces_rulearray+BCESFieldIndexFeeFrozen);	/* 冻结手续费 */
	}
	CBCESFieldsPosi& operator=(const CBCESFieldsPosi& Posi){
		m_fieldarray=m_fieldarray_Posi;
		m_fieldsize=sizeof(m_fieldarray_Posi)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Posi+sizeof(CBMLFields),sizeof(CBCESFieldsPosi)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BuyQty,sizeof(BuyQty),NULL,0,bces_rulearray+BCESFieldIndexBuyQty);	/* 买持仓量 */
		AddField((void*)&BuyPrice,sizeof(BuyPrice),NULL,0,bces_rulearray+BCESFieldIndexBuyPrice);	/* 买持仓均价 */
		AddField((void*)&SellQty,sizeof(SellQty),NULL,0,bces_rulearray+BCESFieldIndexSellQty);	/* 卖持仓量 */
		AddField((void*)&SellPrice,sizeof(SellPrice),NULL,0,bces_rulearray+BCESFieldIndexSellPrice);	/* 卖持仓均价 */
		AddField((void*)&BuyQtyFrozen,sizeof(BuyQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexBuyQtyFrozen);	/* 买冻结持仓量 */
		AddField((void*)&SellQtyFrozen,sizeof(SellQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexSellQtyFrozen);	/* 卖冻结持仓量 */
		AddField((void*)&PreBuyQty,sizeof(PreBuyQty),NULL,0,bces_rulearray+BCESFieldIndexPreBuyQty);	/* 昨买持仓量 */
		AddField((void*)&PreSellQty,sizeof(PreSellQty),NULL,0,bces_rulearray+BCESFieldIndexPreSellQty);	/* 昨卖持仓量 */
		AddField((void*)&TodayBuyQty,sizeof(TodayBuyQty),NULL,0,bces_rulearray+BCESFieldIndexTodayBuyQty);	/* 今买持仓量 */
		AddField((void*)&TodaySellQty,sizeof(TodaySellQty),NULL,0,bces_rulearray+BCESFieldIndexTodaySellQty);	/* 今卖持仓量 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&TodayBuyQtyFrozen,sizeof(TodayBuyQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexTodayBuyQtyFrozen);	/* 今买冻结持仓量 */
		AddField((void*)&TodaySellQtyFrozen,sizeof(TodaySellQtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexTodaySellQtyFrozen);	/* 今卖冻结持仓量 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&FeeFrozen,sizeof(FeeFrozen),NULL,0,bces_rulearray+BCESFieldIndexFeeFrozen);	/* 冻结手续费 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Posi),0x00,sizeof(CBCESFieldsPosi)-sizeof(CBMLFields)-sizeof(m_fieldarray_Posi));
	}

	BML_FIELD_INFO m_fieldarray_Posi[22];

	// Field
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
class CBCESFieldsPosiDetail:public CBMLFields
{
public:
	CBCESFieldsPosiDetail()
	{
		m_fieldarray=m_fieldarray_PosiDetail;
		m_fieldsize=sizeof(m_fieldarray_PosiDetail)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsPosiDetail)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&QtyLeft,sizeof(QtyLeft),NULL,0,bces_rulearray+BCESFieldIndexQtyLeft);	/* 剩余数量 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)AgentName,sizeof(AgentName),NULL,0,bces_rulearray+BCESFieldIndexAgentName);	/* 代理商名称 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 保证金 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 建仓日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 建仓时间 */
		AddField((void*)CloseDate,sizeof(CloseDate),NULL,0,bces_rulearray+BCESFieldIndexCloseDate);	/* 平仓日期 */
		AddField((void*)CloseTime,sizeof(CloseTime),NULL,0,bces_rulearray+BCESFieldIndexCloseTime);	/* 平仓时间 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 平仓价格 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		AddField((void*)&QtyFrozen,sizeof(QtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexQtyFrozen);	/* 冻结持仓量 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&CreatePrice,sizeof(CreatePrice),NULL,0,bces_rulearray+BCESFieldIndexCreatePrice);	/* 建仓价 */
		AddField((void*)&HistoryClosedPL,sizeof(HistoryClosedPL),NULL,0,bces_rulearray+BCESFieldIndexHistoryClosedPL);	/* 历史平仓盈亏 */
		AddField((void*)CreateTradeDate,sizeof(CreateTradeDate),NULL,0,bces_rulearray+BCESFieldIndexCreateTradeDate);	/* 建仓交易日期 */
		AddField((void*)&PreQtyLeft,sizeof(PreQtyLeft),NULL,0,bces_rulearray+BCESFieldIndexPreQtyLeft);	/* 上日剩余数量 */
		AddField((void*)&PreClosedPL,sizeof(PreClosedPL),NULL,0,bces_rulearray+BCESFieldIndexPreClosedPL);	/* 上日平仓盈亏 */
		AddField((void*)&PreClosePrice,sizeof(PreClosePrice),NULL,0,bces_rulearray+BCESFieldIndexPreClosePrice);	/* 上日平仓价格 */
	}
	CBCESFieldsPosiDetail(const CBCESFieldsPosiDetail& PosiDetail){
		m_fieldarray=m_fieldarray_PosiDetail;
		m_fieldsize=sizeof(m_fieldarray_PosiDetail)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&PosiDetail+sizeof(CBMLFields),sizeof(CBCESFieldsPosiDetail)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&QtyLeft,sizeof(QtyLeft),NULL,0,bces_rulearray+BCESFieldIndexQtyLeft);	/* 剩余数量 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)AgentName,sizeof(AgentName),NULL,0,bces_rulearray+BCESFieldIndexAgentName);	/* 代理商名称 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 保证金 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 建仓日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 建仓时间 */
		AddField((void*)CloseDate,sizeof(CloseDate),NULL,0,bces_rulearray+BCESFieldIndexCloseDate);	/* 平仓日期 */
		AddField((void*)CloseTime,sizeof(CloseTime),NULL,0,bces_rulearray+BCESFieldIndexCloseTime);	/* 平仓时间 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 平仓价格 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		AddField((void*)&QtyFrozen,sizeof(QtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexQtyFrozen);	/* 冻结持仓量 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&CreatePrice,sizeof(CreatePrice),NULL,0,bces_rulearray+BCESFieldIndexCreatePrice);	/* 建仓价 */
		AddField((void*)&HistoryClosedPL,sizeof(HistoryClosedPL),NULL,0,bces_rulearray+BCESFieldIndexHistoryClosedPL);	/* 历史平仓盈亏 */
		AddField((void*)CreateTradeDate,sizeof(CreateTradeDate),NULL,0,bces_rulearray+BCESFieldIndexCreateTradeDate);	/* 建仓交易日期 */
		AddField((void*)&PreQtyLeft,sizeof(PreQtyLeft),NULL,0,bces_rulearray+BCESFieldIndexPreQtyLeft);	/* 上日剩余数量 */
		AddField((void*)&PreClosedPL,sizeof(PreClosedPL),NULL,0,bces_rulearray+BCESFieldIndexPreClosedPL);	/* 上日平仓盈亏 */
		AddField((void*)&PreClosePrice,sizeof(PreClosePrice),NULL,0,bces_rulearray+BCESFieldIndexPreClosePrice);	/* 上日平仓价格 */
	}
	CBCESFieldsPosiDetail& operator=(const CBCESFieldsPosiDetail& PosiDetail){
		m_fieldarray=m_fieldarray_PosiDetail;
		m_fieldsize=sizeof(m_fieldarray_PosiDetail)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&PosiDetail+sizeof(CBMLFields),sizeof(CBCESFieldsPosiDetail)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)OrderID,sizeof(OrderID),NULL,0,bces_rulearray+BCESFieldIndexOrderID);	/* 订单号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&QtyLeft,sizeof(QtyLeft),NULL,0,bces_rulearray+BCESFieldIndexQtyLeft);	/* 剩余数量 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)AgentName,sizeof(AgentName),NULL,0,bces_rulearray+BCESFieldIndexAgentName);	/* 代理商名称 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 保证金 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 建仓日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 建仓时间 */
		AddField((void*)CloseDate,sizeof(CloseDate),NULL,0,bces_rulearray+BCESFieldIndexCloseDate);	/* 平仓日期 */
		AddField((void*)CloseTime,sizeof(CloseTime),NULL,0,bces_rulearray+BCESFieldIndexCloseTime);	/* 平仓时间 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 平仓价格 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		AddField((void*)&QtyFrozen,sizeof(QtyFrozen),NULL,0,bces_rulearray+BCESFieldIndexQtyFrozen);	/* 冻结持仓量 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&CreatePrice,sizeof(CreatePrice),NULL,0,bces_rulearray+BCESFieldIndexCreatePrice);	/* 建仓价 */
		AddField((void*)&HistoryClosedPL,sizeof(HistoryClosedPL),NULL,0,bces_rulearray+BCESFieldIndexHistoryClosedPL);	/* 历史平仓盈亏 */
		AddField((void*)CreateTradeDate,sizeof(CreateTradeDate),NULL,0,bces_rulearray+BCESFieldIndexCreateTradeDate);	/* 建仓交易日期 */
		AddField((void*)&PreQtyLeft,sizeof(PreQtyLeft),NULL,0,bces_rulearray+BCESFieldIndexPreQtyLeft);	/* 上日剩余数量 */
		AddField((void*)&PreClosedPL,sizeof(PreClosedPL),NULL,0,bces_rulearray+BCESFieldIndexPreClosedPL);	/* 上日平仓盈亏 */
		AddField((void*)&PreClosePrice,sizeof(PreClosePrice),NULL,0,bces_rulearray+BCESFieldIndexPreClosePrice);	/* 上日平仓价格 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_PosiDetail),0x00,sizeof(CBCESFieldsPosiDetail)-sizeof(CBMLFields)-sizeof(m_fieldarray_PosiDetail));
	}

	BML_FIELD_INFO m_fieldarray_PosiDetail[32];

	// Field
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
	BCESFieldTypeAmount PreClosedPL;	/* 上日平仓盈亏 */
	BCESFieldTypePrice PreClosePrice;	/* 上日平仓价格 */
};

/* 资金查询请求 */
class CBCESFieldsFundQueryReq:public CBMLFields
{
public:
	CBCESFieldsFundQueryReq()
	{
		m_fieldarray=m_fieldarray_FundQueryReq;
		m_fieldsize=sizeof(m_fieldarray_FundQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsFundQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsFundQueryReq(const CBCESFieldsFundQueryReq& FundQueryReq){
		m_fieldarray=m_fieldarray_FundQueryReq;
		m_fieldsize=sizeof(m_fieldarray_FundQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FundQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsFundQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsFundQueryReq& operator=(const CBCESFieldsFundQueryReq& FundQueryReq){
		m_fieldarray=m_fieldarray_FundQueryReq;
		m_fieldsize=sizeof(m_fieldarray_FundQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FundQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsFundQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_FundQueryReq),0x00,sizeof(CBCESFieldsFundQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_FundQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_FundQueryReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 历史资金查询请求 */
class CBCESFieldsHisFundQueryReq:public CBMLFields
{
public:
	CBCESFieldsHisFundQueryReq()
	{
		m_fieldarray=m_fieldarray_HisFundQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisFundQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHisFundQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsHisFundQueryReq(const CBCESFieldsHisFundQueryReq& HisFundQueryReq){
		m_fieldarray=m_fieldarray_HisFundQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisFundQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisFundQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisFundQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsHisFundQueryReq& operator=(const CBCESFieldsHisFundQueryReq& HisFundQueryReq){
		m_fieldarray=m_fieldarray_HisFundQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisFundQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisFundQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisFundQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_HisFundQueryReq),0x00,sizeof(CBCESFieldsHisFundQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_HisFundQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_HisFundQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 资金 */
class CBCESFieldsFund:public CBMLFields
{
public:
	CBCESFieldsFund()
	{
		m_fieldarray=m_fieldarray_Fund;
		m_fieldsize=sizeof(m_fieldarray_Fund)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsFund)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&LastBalance,sizeof(LastBalance),NULL,0,bces_rulearray+BCESFieldIndexLastBalance);	/* 上日权益 */
		AddField((void*)&FloatBalance,sizeof(FloatBalance),NULL,0,bces_rulearray+BCESFieldIndexFloatBalance);	/* 浮动权益 */
		AddField((void*)&FreeBalance,sizeof(FreeBalance),NULL,0,bces_rulearray+BCESFieldIndexFreeBalance);	/* 可用资金 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&FeeFrozen,sizeof(FeeFrozen),NULL,0,bces_rulearray+BCESFieldIndexFeeFrozen);	/* 冻结手续费 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&ProfitLoss,sizeof(ProfitLoss),NULL,0,bces_rulearray+BCESFieldIndexProfitLoss);	/* 盈亏 */
		AddField((void*)&TotalPL,sizeof(TotalPL),NULL,0,bces_rulearray+BCESFieldIndexTotalPL);	/* 累计盈亏 */
		AddField((void*)&FrozenBalance,sizeof(FrozenBalance),NULL,0,bces_rulearray+BCESFieldIndexFrozenBalance);	/* 冻结资金 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)AgentName,sizeof(AgentName),NULL,0,bces_rulearray+BCESFieldIndexAgentName);	/* 代理商名称 */
		AddField((void*)&InAmount,sizeof(InAmount),NULL,0,bces_rulearray+BCESFieldIndexInAmount);	/* 入金金额 */
		AddField((void*)&OutAmount,sizeof(OutAmount),NULL,0,bces_rulearray+BCESFieldIndexOutAmount);	/* 出金金额 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
	}
	CBCESFieldsFund(const CBCESFieldsFund& Fund){
		m_fieldarray=m_fieldarray_Fund;
		m_fieldsize=sizeof(m_fieldarray_Fund)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Fund+sizeof(CBMLFields),sizeof(CBCESFieldsFund)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&LastBalance,sizeof(LastBalance),NULL,0,bces_rulearray+BCESFieldIndexLastBalance);	/* 上日权益 */
		AddField((void*)&FloatBalance,sizeof(FloatBalance),NULL,0,bces_rulearray+BCESFieldIndexFloatBalance);	/* 浮动权益 */
		AddField((void*)&FreeBalance,sizeof(FreeBalance),NULL,0,bces_rulearray+BCESFieldIndexFreeBalance);	/* 可用资金 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&FeeFrozen,sizeof(FeeFrozen),NULL,0,bces_rulearray+BCESFieldIndexFeeFrozen);	/* 冻结手续费 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&ProfitLoss,sizeof(ProfitLoss),NULL,0,bces_rulearray+BCESFieldIndexProfitLoss);	/* 盈亏 */
		AddField((void*)&TotalPL,sizeof(TotalPL),NULL,0,bces_rulearray+BCESFieldIndexTotalPL);	/* 累计盈亏 */
		AddField((void*)&FrozenBalance,sizeof(FrozenBalance),NULL,0,bces_rulearray+BCESFieldIndexFrozenBalance);	/* 冻结资金 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)AgentName,sizeof(AgentName),NULL,0,bces_rulearray+BCESFieldIndexAgentName);	/* 代理商名称 */
		AddField((void*)&InAmount,sizeof(InAmount),NULL,0,bces_rulearray+BCESFieldIndexInAmount);	/* 入金金额 */
		AddField((void*)&OutAmount,sizeof(OutAmount),NULL,0,bces_rulearray+BCESFieldIndexOutAmount);	/* 出金金额 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
	}
	CBCESFieldsFund& operator=(const CBCESFieldsFund& Fund){
		m_fieldarray=m_fieldarray_Fund;
		m_fieldsize=sizeof(m_fieldarray_Fund)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Fund+sizeof(CBMLFields),sizeof(CBCESFieldsFund)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&LastBalance,sizeof(LastBalance),NULL,0,bces_rulearray+BCESFieldIndexLastBalance);	/* 上日权益 */
		AddField((void*)&FloatBalance,sizeof(FloatBalance),NULL,0,bces_rulearray+BCESFieldIndexFloatBalance);	/* 浮动权益 */
		AddField((void*)&FreeBalance,sizeof(FreeBalance),NULL,0,bces_rulearray+BCESFieldIndexFreeBalance);	/* 可用资金 */
		AddField((void*)&Margin,sizeof(Margin),NULL,0,bces_rulearray+BCESFieldIndexMargin);	/* 占用保证金 */
		AddField((void*)&FrozenMargin,sizeof(FrozenMargin),NULL,0,bces_rulearray+BCESFieldIndexFrozenMargin);	/* 冻结保证金 */
		AddField((void*)&Fee,sizeof(Fee),NULL,0,bces_rulearray+BCESFieldIndexFee);	/* 手续费 */
		AddField((void*)&FeeFrozen,sizeof(FeeFrozen),NULL,0,bces_rulearray+BCESFieldIndexFeeFrozen);	/* 冻结手续费 */
		AddField((void*)&ClosedPL,sizeof(ClosedPL),NULL,0,bces_rulearray+BCESFieldIndexClosedPL);	/* 平仓盈亏 */
		AddField((void*)&FloatingPL,sizeof(FloatingPL),NULL,0,bces_rulearray+BCESFieldIndexFloatingPL);	/* 浮动盈亏 */
		AddField((void*)&ProfitLoss,sizeof(ProfitLoss),NULL,0,bces_rulearray+BCESFieldIndexProfitLoss);	/* 盈亏 */
		AddField((void*)&TotalPL,sizeof(TotalPL),NULL,0,bces_rulearray+BCESFieldIndexTotalPL);	/* 累计盈亏 */
		AddField((void*)&FrozenBalance,sizeof(FrozenBalance),NULL,0,bces_rulearray+BCESFieldIndexFrozenBalance);	/* 冻结资金 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)AgentName,sizeof(AgentName),NULL,0,bces_rulearray+BCESFieldIndexAgentName);	/* 代理商名称 */
		AddField((void*)&InAmount,sizeof(InAmount),NULL,0,bces_rulearray+BCESFieldIndexInAmount);	/* 入金金额 */
		AddField((void*)&OutAmount,sizeof(OutAmount),NULL,0,bces_rulearray+BCESFieldIndexOutAmount);	/* 出金金额 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Fund),0x00,sizeof(CBCESFieldsFund)-sizeof(CBMLFields)-sizeof(m_fieldarray_Fund));
	}

	BML_FIELD_INFO m_fieldarray_Fund[19];

	// Field
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
class CBCESFieldsMarketStatusNty:public CBMLFields
{
public:
	CBCESFieldsMarketStatusNty()
	{
		m_fieldarray=m_fieldarray_MarketStatusNty;
		m_fieldsize=sizeof(m_fieldarray_MarketStatusNty)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsMarketStatusNty)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&MarketStatus,sizeof(MarketStatus),NULL,0,bces_rulearray+BCESFieldIndexMarketStatus);	/* 市场状态 */
		AddField((void*)MarketStatusDesc,sizeof(MarketStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexMarketStatusDesc);	/* 市场状态描述 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsMarketStatusNty(const CBCESFieldsMarketStatusNty& MarketStatusNty){
		m_fieldarray=m_fieldarray_MarketStatusNty;
		m_fieldsize=sizeof(m_fieldarray_MarketStatusNty)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&MarketStatusNty+sizeof(CBMLFields),sizeof(CBCESFieldsMarketStatusNty)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&MarketStatus,sizeof(MarketStatus),NULL,0,bces_rulearray+BCESFieldIndexMarketStatus);	/* 市场状态 */
		AddField((void*)MarketStatusDesc,sizeof(MarketStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexMarketStatusDesc);	/* 市场状态描述 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsMarketStatusNty& operator=(const CBCESFieldsMarketStatusNty& MarketStatusNty){
		m_fieldarray=m_fieldarray_MarketStatusNty;
		m_fieldsize=sizeof(m_fieldarray_MarketStatusNty)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&MarketStatusNty+sizeof(CBMLFields),sizeof(CBCESFieldsMarketStatusNty)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)&MarketStatus,sizeof(MarketStatus),NULL,0,bces_rulearray+BCESFieldIndexMarketStatus);	/* 市场状态 */
		AddField((void*)MarketStatusDesc,sizeof(MarketStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexMarketStatusDesc);	/* 市场状态描述 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_MarketStatusNty),0x00,sizeof(CBCESFieldsMarketStatusNty)-sizeof(CBMLFields)-sizeof(m_fieldarray_MarketStatusNty));
	}

	BML_FIELD_INFO m_fieldarray_MarketStatusNty[3];

	// Field
	BCESFieldTypeFlag MarketStatus;	/* 市场状态 */
	BCESFieldTypeMarketStatusDesc MarketStatusDesc;	/* 市场状态描述 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 合约查询请求 */
class CBCESFieldsInstrumentQueryReq:public CBMLFields
{
public:
	CBCESFieldsInstrumentQueryReq()
	{
		m_fieldarray=m_fieldarray_InstrumentQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InstrumentQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInstrumentQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsInstrumentQueryReq(const CBCESFieldsInstrumentQueryReq& InstrumentQueryReq){
		m_fieldarray=m_fieldarray_InstrumentQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InstrumentQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InstrumentQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsInstrumentQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsInstrumentQueryReq& operator=(const CBCESFieldsInstrumentQueryReq& InstrumentQueryReq){
		m_fieldarray=m_fieldarray_InstrumentQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InstrumentQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InstrumentQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsInstrumentQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InstrumentQueryReq),0x00,sizeof(CBCESFieldsInstrumentQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_InstrumentQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_InstrumentQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 合约 */
class CBCESFieldsInstrument:public CBMLFields
{
public:
	CBCESFieldsInstrument()
	{
		m_fieldarray=m_fieldarray_Instrument;
		m_fieldsize=sizeof(m_fieldarray_Instrument)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInstrument)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)InstrumentName,sizeof(InstrumentName),NULL,0,bces_rulearray+BCESFieldIndexInstrumentName);	/* 合约名称 */
		AddField((void*)&FeeType,sizeof(FeeType),NULL,0,bces_rulearray+BCESFieldIndexFeeType);	/* 手续费类型 */
		AddField((void*)&FeeRate,sizeof(FeeRate),NULL,0,bces_rulearray+BCESFieldIndexFeeRate);	/* 手续费率 */
		AddField((void*)&MarginRate,sizeof(MarginRate),NULL,0,bces_rulearray+BCESFieldIndexMarginRate);	/* 保证金 */
		AddField((void*)&DailyPriceLimit,sizeof(DailyPriceLimit),NULL,0,bces_rulearray+BCESFieldIndexDailyPriceLimit);	/* 每日涨跌限制 */
		AddField((void*)&PriceUnit,sizeof(PriceUnit),NULL,0,bces_rulearray+BCESFieldIndexPriceUnit);	/* 报价单位 */
		AddField((void*)&TradeUnit,sizeof(TradeUnit),NULL,0,bces_rulearray+BCESFieldIndexTradeUnit);	/* 交易单位 */
		AddField((void*)&MinMovement,sizeof(MinMovement),NULL,0,bces_rulearray+BCESFieldIndexMinMovement);	/* 最小变动价位 */
		AddField((void*)&PriceScale,sizeof(PriceScale),NULL,0,bces_rulearray+BCESFieldIndexPriceScale);	/* 报价精度 */
		AddField((void*)&PriceCoefficient,sizeof(PriceCoefficient),NULL,0,bces_rulearray+BCESFieldIndexPriceCoefficient);	/* 价格系数 */
		AddField((void*)&InstrumentStatus,sizeof(InstrumentStatus),NULL,0,bces_rulearray+BCESFieldIndexInstrumentStatus);	/* 合约状态 */
		AddField((void*)&Currency,sizeof(Currency),NULL,0,bces_rulearray+BCESFieldIndexCurrency);	/* 币种 */
		AddField((void*)&MarginRateType,sizeof(MarginRateType),NULL,0,bces_rulearray+BCESFieldIndexMarginRateType);	/* 保证金率类型 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		AddField((void*)&OverNightFeeType,sizeof(OverNightFeeType),NULL,0,bces_rulearray+BCESFieldIndexOverNightFeeType);	/* 隔夜费类型 */
		AddField((void*)&PriceMultiply,sizeof(PriceMultiply),NULL,0,bces_rulearray+BCESFieldIndexPriceMultiply);	/* 报价乘数 */
		AddField((void*)&FeeFlag,sizeof(FeeFlag),NULL,0,bces_rulearray+BCESFieldIndexFeeFlag);	/* 收费类型 */
		AddField((void*)&EachQtyLimt,sizeof(EachQtyLimt),NULL,0,bces_rulearray+BCESFieldIndexEachQtyLimt);	/* 每笔持仓限量 */
		AddField((void*)&TotalQtyLimt,sizeof(TotalQtyLimt),NULL,0,bces_rulearray+BCESFieldIndexTotalQtyLimt);	/* 总持仓限量 */
		AddField((void*)GoodsName,sizeof(GoodsName),NULL,0,bces_rulearray+BCESFieldIndexGoodsName);	/* 品种大类 */
		AddField((void*)PlateName,sizeof(PlateName),NULL,0,bces_rulearray+BCESFieldIndexPlateName);	/* 板块 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&InstrumentType,sizeof(InstrumentType),NULL,0,bces_rulearray+BCESFieldIndexInstrumentType);	/* 商品类型 */
	}
	CBCESFieldsInstrument(const CBCESFieldsInstrument& Instrument){
		m_fieldarray=m_fieldarray_Instrument;
		m_fieldsize=sizeof(m_fieldarray_Instrument)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Instrument+sizeof(CBMLFields),sizeof(CBCESFieldsInstrument)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)InstrumentName,sizeof(InstrumentName),NULL,0,bces_rulearray+BCESFieldIndexInstrumentName);	/* 合约名称 */
		AddField((void*)&FeeType,sizeof(FeeType),NULL,0,bces_rulearray+BCESFieldIndexFeeType);	/* 手续费类型 */
		AddField((void*)&FeeRate,sizeof(FeeRate),NULL,0,bces_rulearray+BCESFieldIndexFeeRate);	/* 手续费率 */
		AddField((void*)&MarginRate,sizeof(MarginRate),NULL,0,bces_rulearray+BCESFieldIndexMarginRate);	/* 保证金 */
		AddField((void*)&DailyPriceLimit,sizeof(DailyPriceLimit),NULL,0,bces_rulearray+BCESFieldIndexDailyPriceLimit);	/* 每日涨跌限制 */
		AddField((void*)&PriceUnit,sizeof(PriceUnit),NULL,0,bces_rulearray+BCESFieldIndexPriceUnit);	/* 报价单位 */
		AddField((void*)&TradeUnit,sizeof(TradeUnit),NULL,0,bces_rulearray+BCESFieldIndexTradeUnit);	/* 交易单位 */
		AddField((void*)&MinMovement,sizeof(MinMovement),NULL,0,bces_rulearray+BCESFieldIndexMinMovement);	/* 最小变动价位 */
		AddField((void*)&PriceScale,sizeof(PriceScale),NULL,0,bces_rulearray+BCESFieldIndexPriceScale);	/* 报价精度 */
		AddField((void*)&PriceCoefficient,sizeof(PriceCoefficient),NULL,0,bces_rulearray+BCESFieldIndexPriceCoefficient);	/* 价格系数 */
		AddField((void*)&InstrumentStatus,sizeof(InstrumentStatus),NULL,0,bces_rulearray+BCESFieldIndexInstrumentStatus);	/* 合约状态 */
		AddField((void*)&Currency,sizeof(Currency),NULL,0,bces_rulearray+BCESFieldIndexCurrency);	/* 币种 */
		AddField((void*)&MarginRateType,sizeof(MarginRateType),NULL,0,bces_rulearray+BCESFieldIndexMarginRateType);	/* 保证金率类型 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		AddField((void*)&OverNightFeeType,sizeof(OverNightFeeType),NULL,0,bces_rulearray+BCESFieldIndexOverNightFeeType);	/* 隔夜费类型 */
		AddField((void*)&PriceMultiply,sizeof(PriceMultiply),NULL,0,bces_rulearray+BCESFieldIndexPriceMultiply);	/* 报价乘数 */
		AddField((void*)&FeeFlag,sizeof(FeeFlag),NULL,0,bces_rulearray+BCESFieldIndexFeeFlag);	/* 收费类型 */
		AddField((void*)&EachQtyLimt,sizeof(EachQtyLimt),NULL,0,bces_rulearray+BCESFieldIndexEachQtyLimt);	/* 每笔持仓限量 */
		AddField((void*)&TotalQtyLimt,sizeof(TotalQtyLimt),NULL,0,bces_rulearray+BCESFieldIndexTotalQtyLimt);	/* 总持仓限量 */
		AddField((void*)GoodsName,sizeof(GoodsName),NULL,0,bces_rulearray+BCESFieldIndexGoodsName);	/* 品种大类 */
		AddField((void*)PlateName,sizeof(PlateName),NULL,0,bces_rulearray+BCESFieldIndexPlateName);	/* 板块 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&InstrumentType,sizeof(InstrumentType),NULL,0,bces_rulearray+BCESFieldIndexInstrumentType);	/* 商品类型 */
	}
	CBCESFieldsInstrument& operator=(const CBCESFieldsInstrument& Instrument){
		m_fieldarray=m_fieldarray_Instrument;
		m_fieldsize=sizeof(m_fieldarray_Instrument)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Instrument+sizeof(CBMLFields),sizeof(CBCESFieldsInstrument)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)InstrumentName,sizeof(InstrumentName),NULL,0,bces_rulearray+BCESFieldIndexInstrumentName);	/* 合约名称 */
		AddField((void*)&FeeType,sizeof(FeeType),NULL,0,bces_rulearray+BCESFieldIndexFeeType);	/* 手续费类型 */
		AddField((void*)&FeeRate,sizeof(FeeRate),NULL,0,bces_rulearray+BCESFieldIndexFeeRate);	/* 手续费率 */
		AddField((void*)&MarginRate,sizeof(MarginRate),NULL,0,bces_rulearray+BCESFieldIndexMarginRate);	/* 保证金 */
		AddField((void*)&DailyPriceLimit,sizeof(DailyPriceLimit),NULL,0,bces_rulearray+BCESFieldIndexDailyPriceLimit);	/* 每日涨跌限制 */
		AddField((void*)&PriceUnit,sizeof(PriceUnit),NULL,0,bces_rulearray+BCESFieldIndexPriceUnit);	/* 报价单位 */
		AddField((void*)&TradeUnit,sizeof(TradeUnit),NULL,0,bces_rulearray+BCESFieldIndexTradeUnit);	/* 交易单位 */
		AddField((void*)&MinMovement,sizeof(MinMovement),NULL,0,bces_rulearray+BCESFieldIndexMinMovement);	/* 最小变动价位 */
		AddField((void*)&PriceScale,sizeof(PriceScale),NULL,0,bces_rulearray+BCESFieldIndexPriceScale);	/* 报价精度 */
		AddField((void*)&PriceCoefficient,sizeof(PriceCoefficient),NULL,0,bces_rulearray+BCESFieldIndexPriceCoefficient);	/* 价格系数 */
		AddField((void*)&InstrumentStatus,sizeof(InstrumentStatus),NULL,0,bces_rulearray+BCESFieldIndexInstrumentStatus);	/* 合约状态 */
		AddField((void*)&Currency,sizeof(Currency),NULL,0,bces_rulearray+BCESFieldIndexCurrency);	/* 币种 */
		AddField((void*)&MarginRateType,sizeof(MarginRateType),NULL,0,bces_rulearray+BCESFieldIndexMarginRateType);	/* 保证金率类型 */
		AddField((void*)&OverNightFee,sizeof(OverNightFee),NULL,0,bces_rulearray+BCESFieldIndexOverNightFee);	/* 隔夜费 */
		AddField((void*)&OverNightFeeType,sizeof(OverNightFeeType),NULL,0,bces_rulearray+BCESFieldIndexOverNightFeeType);	/* 隔夜费类型 */
		AddField((void*)&PriceMultiply,sizeof(PriceMultiply),NULL,0,bces_rulearray+BCESFieldIndexPriceMultiply);	/* 报价乘数 */
		AddField((void*)&FeeFlag,sizeof(FeeFlag),NULL,0,bces_rulearray+BCESFieldIndexFeeFlag);	/* 收费类型 */
		AddField((void*)&EachQtyLimt,sizeof(EachQtyLimt),NULL,0,bces_rulearray+BCESFieldIndexEachQtyLimt);	/* 每笔持仓限量 */
		AddField((void*)&TotalQtyLimt,sizeof(TotalQtyLimt),NULL,0,bces_rulearray+BCESFieldIndexTotalQtyLimt);	/* 总持仓限量 */
		AddField((void*)GoodsName,sizeof(GoodsName),NULL,0,bces_rulearray+BCESFieldIndexGoodsName);	/* 品种大类 */
		AddField((void*)PlateName,sizeof(PlateName),NULL,0,bces_rulearray+BCESFieldIndexPlateName);	/* 板块 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&InstrumentType,sizeof(InstrumentType),NULL,0,bces_rulearray+BCESFieldIndexInstrumentType);	/* 商品类型 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Instrument),0x00,sizeof(CBCESFieldsInstrument)-sizeof(CBMLFields)-sizeof(m_fieldarray_Instrument));
	}

	BML_FIELD_INFO m_fieldarray_Instrument[24];

	// Field
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
class CBCESFieldsMinDataQueryReq:public CBMLFields
{
public:
	CBCESFieldsMinDataQueryReq()
	{
		m_fieldarray=m_fieldarray_MinDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_MinDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsMinDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsMinDataQueryReq(const CBCESFieldsMinDataQueryReq& MinDataQueryReq){
		m_fieldarray=m_fieldarray_MinDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_MinDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&MinDataQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsMinDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsMinDataQueryReq& operator=(const CBCESFieldsMinDataQueryReq& MinDataQueryReq){
		m_fieldarray=m_fieldarray_MinDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_MinDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&MinDataQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsMinDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_MinDataQueryReq),0x00,sizeof(CBCESFieldsMinDataQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_MinDataQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_MinDataQueryReq[4];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 分线 */
class CBCESFieldsMinData:public CBMLFields
{
public:
	CBCESFieldsMinData()
	{
		m_fieldarray=m_fieldarray_MinData;
		m_fieldsize=sizeof(m_fieldarray_MinData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsMinData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsMinData(const CBCESFieldsMinData& MinData){
		m_fieldarray=m_fieldarray_MinData;
		m_fieldsize=sizeof(m_fieldarray_MinData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&MinData+sizeof(CBMLFields),sizeof(CBCESFieldsMinData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsMinData& operator=(const CBCESFieldsMinData& MinData){
		m_fieldarray=m_fieldarray_MinData;
		m_fieldsize=sizeof(m_fieldarray_MinData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&MinData+sizeof(CBMLFields),sizeof(CBCESFieldsMinData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_MinData),0x00,sizeof(CBCESFieldsMinData)-sizeof(CBMLFields)-sizeof(m_fieldarray_MinData));
	}

	BML_FIELD_INFO m_fieldarray_MinData[10];

	// Field
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
class CBCESFieldsDayDataQueryReq:public CBMLFields
{
public:
	CBCESFieldsDayDataQueryReq()
	{
		m_fieldarray=m_fieldarray_DayDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_DayDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDayDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsDayDataQueryReq(const CBCESFieldsDayDataQueryReq& DayDataQueryReq){
		m_fieldarray=m_fieldarray_DayDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_DayDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DayDataQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsDayDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsDayDataQueryReq& operator=(const CBCESFieldsDayDataQueryReq& DayDataQueryReq){
		m_fieldarray=m_fieldarray_DayDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_DayDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DayDataQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsDayDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DayDataQueryReq),0x00,sizeof(CBCESFieldsDayDataQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_DayDataQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_DayDataQueryReq[4];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 日线 */
class CBCESFieldsDayData:public CBMLFields
{
public:
	CBCESFieldsDayData()
	{
		m_fieldarray=m_fieldarray_DayData;
		m_fieldsize=sizeof(m_fieldarray_DayData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDayData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)Date,sizeof(Date),NULL,0,bces_rulearray+BCESFieldIndexDate);	/* 日期 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsDayData(const CBCESFieldsDayData& DayData){
		m_fieldarray=m_fieldarray_DayData;
		m_fieldsize=sizeof(m_fieldarray_DayData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DayData+sizeof(CBMLFields),sizeof(CBCESFieldsDayData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)Date,sizeof(Date),NULL,0,bces_rulearray+BCESFieldIndexDate);	/* 日期 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsDayData& operator=(const CBCESFieldsDayData& DayData){
		m_fieldarray=m_fieldarray_DayData;
		m_fieldsize=sizeof(m_fieldarray_DayData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DayData+sizeof(CBMLFields),sizeof(CBCESFieldsDayData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)Date,sizeof(Date),NULL,0,bces_rulearray+BCESFieldIndexDate);	/* 日期 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DayData),0x00,sizeof(CBCESFieldsDayData)-sizeof(CBMLFields)-sizeof(m_fieldarray_DayData));
	}

	BML_FIELD_INFO m_fieldarray_DayData[10];

	// Field
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
class CBCESFieldsTradeDetailDataQueryReq:public CBMLFields
{
public:
	CBCESFieldsTradeDetailDataQueryReq()
	{
		m_fieldarray=m_fieldarray_TradeDetailDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeDetailDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeDetailDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsTradeDetailDataQueryReq(const CBCESFieldsTradeDetailDataQueryReq& TradeDetailDataQueryReq){
		m_fieldarray=m_fieldarray_TradeDetailDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeDetailDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeDetailDataQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeDetailDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsTradeDetailDataQueryReq& operator=(const CBCESFieldsTradeDetailDataQueryReq& TradeDetailDataQueryReq){
		m_fieldarray=m_fieldarray_TradeDetailDataQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeDetailDataQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeDetailDataQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeDetailDataQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeDetailDataQueryReq),0x00,sizeof(CBCESFieldsTradeDetailDataQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeDetailDataQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_TradeDetailDataQueryReq[3];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate TradeDate;	/* 交易日期 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* 成交明细 */
class CBCESFieldsTradeDetailData:public CBMLFields
{
public:
	CBCESFieldsTradeDetailData()
	{
		m_fieldarray=m_fieldarray_TradeDetailData;
		m_fieldsize=sizeof(m_fieldarray_TradeDetailData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeDetailData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)Date,sizeof(Date),NULL,0,bces_rulearray+BCESFieldIndexDate);	/* 日期 */
		AddField((void*)Time,sizeof(Time),NULL,0,bces_rulearray+BCESFieldIndexTime);	/* 时间 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 成交量 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsTradeDetailData(const CBCESFieldsTradeDetailData& TradeDetailData){
		m_fieldarray=m_fieldarray_TradeDetailData;
		m_fieldsize=sizeof(m_fieldarray_TradeDetailData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeDetailData+sizeof(CBMLFields),sizeof(CBCESFieldsTradeDetailData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)Date,sizeof(Date),NULL,0,bces_rulearray+BCESFieldIndexDate);	/* 日期 */
		AddField((void*)Time,sizeof(Time),NULL,0,bces_rulearray+BCESFieldIndexTime);	/* 时间 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 成交量 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsTradeDetailData& operator=(const CBCESFieldsTradeDetailData& TradeDetailData){
		m_fieldarray=m_fieldarray_TradeDetailData;
		m_fieldsize=sizeof(m_fieldarray_TradeDetailData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeDetailData+sizeof(CBMLFields),sizeof(CBCESFieldsTradeDetailData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)MatchID,sizeof(MatchID),NULL,0,bces_rulearray+BCESFieldIndexMatchID);	/* 成交号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)Date,sizeof(Date),NULL,0,bces_rulearray+BCESFieldIndexDate);	/* 日期 */
		AddField((void*)Time,sizeof(Time),NULL,0,bces_rulearray+BCESFieldIndexTime);	/* 时间 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 成交量 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeDetailData),0x00,sizeof(CBCESFieldsTradeDetailData)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeDetailData));
	}

	BML_FIELD_INFO m_fieldarray_TradeDetailData[7];

	// Field
	BCESFieldTypeMatchID MatchID;	/* 成交号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate Date;	/* 日期 */
	BCESFieldTypeTime Time;	/* 时间 */
	BCESFieldTypeQty Qty;	/* 成交量 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 止赢止损设置请求 */
class CBCESFieldsProfitLossStopSetReq:public CBMLFields
{
public:
	CBCESFieldsProfitLossStopSetReq()
	{
		m_fieldarray=m_fieldarray_ProfitLossStopSetReq;
		m_fieldsize=sizeof(m_fieldarray_ProfitLossStopSetReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsProfitLossStopSetReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
	}
	CBCESFieldsProfitLossStopSetReq(const CBCESFieldsProfitLossStopSetReq& ProfitLossStopSetReq){
		m_fieldarray=m_fieldarray_ProfitLossStopSetReq;
		m_fieldsize=sizeof(m_fieldarray_ProfitLossStopSetReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ProfitLossStopSetReq+sizeof(CBMLFields),sizeof(CBCESFieldsProfitLossStopSetReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
	}
	CBCESFieldsProfitLossStopSetReq& operator=(const CBCESFieldsProfitLossStopSetReq& ProfitLossStopSetReq){
		m_fieldarray=m_fieldarray_ProfitLossStopSetReq;
		m_fieldsize=sizeof(m_fieldarray_ProfitLossStopSetReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ProfitLossStopSetReq+sizeof(CBMLFields),sizeof(CBCESFieldsProfitLossStopSetReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ProfitLossStopSetReq),0x00,sizeof(CBCESFieldsProfitLossStopSetReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_ProfitLossStopSetReq));
	}

	BML_FIELD_INFO m_fieldarray_ProfitLossStopSetReq[5];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
};

/* 止赢止损设置应答 */
class CBCESFieldsProfitLossStopSetRsp:public CBMLFields
{
public:
	CBCESFieldsProfitLossStopSetRsp()
	{
		m_fieldarray=m_fieldarray_ProfitLossStopSetRsp;
		m_fieldsize=sizeof(m_fieldarray_ProfitLossStopSetRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsProfitLossStopSetRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
	}
	CBCESFieldsProfitLossStopSetRsp(const CBCESFieldsProfitLossStopSetRsp& ProfitLossStopSetRsp){
		m_fieldarray=m_fieldarray_ProfitLossStopSetRsp;
		m_fieldsize=sizeof(m_fieldarray_ProfitLossStopSetRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ProfitLossStopSetRsp+sizeof(CBMLFields),sizeof(CBCESFieldsProfitLossStopSetRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
	}
	CBCESFieldsProfitLossStopSetRsp& operator=(const CBCESFieldsProfitLossStopSetRsp& ProfitLossStopSetRsp){
		m_fieldarray=m_fieldarray_ProfitLossStopSetRsp;
		m_fieldsize=sizeof(m_fieldarray_ProfitLossStopSetRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ProfitLossStopSetRsp+sizeof(CBMLFields),sizeof(CBCESFieldsProfitLossStopSetRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)PosiID,sizeof(PosiID),NULL,0,bces_rulearray+BCESFieldIndexPosiID);	/* 持仓号 */
		AddField((void*)&ProfitStopPrice,sizeof(ProfitStopPrice),NULL,0,bces_rulearray+BCESFieldIndexProfitStopPrice);	/* 止赢价 */
		AddField((void*)&LossStopPrice,sizeof(LossStopPrice),NULL,0,bces_rulearray+BCESFieldIndexLossStopPrice);	/* 止损价 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ProfitLossStopSetRsp),0x00,sizeof(CBCESFieldsProfitLossStopSetRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_ProfitLossStopSetRsp));
	}

	BML_FIELD_INFO m_fieldarray_ProfitLossStopSetRsp[5];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypePosiID PosiID;	/* 持仓号 */
	BCESFieldTypePrice ProfitStopPrice;	/* 止赢价 */
	BCESFieldTypePrice LossStopPrice;	/* 止损价 */
};

/* 公告 */
class CBCESFieldsBulletin:public CBMLFields
{
public:
	CBCESFieldsBulletin()
	{
		m_fieldarray=m_fieldarray_Bulletin;
		m_fieldsize=sizeof(m_fieldarray_Bulletin)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsBulletin)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)BulletinID,sizeof(BulletinID),NULL,0,bces_rulearray+BCESFieldIndexBulletinID);	/* 公告编号 */
		AddField((void*)Title,sizeof(Title),NULL,0,bces_rulearray+BCESFieldIndexTitle);	/* 公告标题 */
		AddField((void*)Content,sizeof(Content),NULL,0,bces_rulearray+BCESFieldIndexContent);	/* 公告内容 */
		AddField((void*)PublishDate,sizeof(PublishDate),NULL,0,bces_rulearray+BCESFieldIndexPublishDate);	/* 发布日期 */
		AddField((void*)PublishTime,sizeof(PublishTime),NULL,0,bces_rulearray+BCESFieldIndexPublishTime);	/* 发布时间 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 创建日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 创建时间 */
		AddField((void*)&PublishMethod,sizeof(PublishMethod),NULL,0,bces_rulearray+BCESFieldIndexPublishMethod);	/* 发布方式 */
		AddField((void*)PublishUserID,sizeof(PublishUserID),NULL,0,bces_rulearray+BCESFieldIndexPublishUserID);	/* 发布人 */
	}
	CBCESFieldsBulletin(const CBCESFieldsBulletin& Bulletin){
		m_fieldarray=m_fieldarray_Bulletin;
		m_fieldsize=sizeof(m_fieldarray_Bulletin)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Bulletin+sizeof(CBMLFields),sizeof(CBCESFieldsBulletin)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)BulletinID,sizeof(BulletinID),NULL,0,bces_rulearray+BCESFieldIndexBulletinID);	/* 公告编号 */
		AddField((void*)Title,sizeof(Title),NULL,0,bces_rulearray+BCESFieldIndexTitle);	/* 公告标题 */
		AddField((void*)Content,sizeof(Content),NULL,0,bces_rulearray+BCESFieldIndexContent);	/* 公告内容 */
		AddField((void*)PublishDate,sizeof(PublishDate),NULL,0,bces_rulearray+BCESFieldIndexPublishDate);	/* 发布日期 */
		AddField((void*)PublishTime,sizeof(PublishTime),NULL,0,bces_rulearray+BCESFieldIndexPublishTime);	/* 发布时间 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 创建日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 创建时间 */
		AddField((void*)&PublishMethod,sizeof(PublishMethod),NULL,0,bces_rulearray+BCESFieldIndexPublishMethod);	/* 发布方式 */
		AddField((void*)PublishUserID,sizeof(PublishUserID),NULL,0,bces_rulearray+BCESFieldIndexPublishUserID);	/* 发布人 */
	}
	CBCESFieldsBulletin& operator=(const CBCESFieldsBulletin& Bulletin){
		m_fieldarray=m_fieldarray_Bulletin;
		m_fieldsize=sizeof(m_fieldarray_Bulletin)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Bulletin+sizeof(CBMLFields),sizeof(CBCESFieldsBulletin)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)BulletinID,sizeof(BulletinID),NULL,0,bces_rulearray+BCESFieldIndexBulletinID);	/* 公告编号 */
		AddField((void*)Title,sizeof(Title),NULL,0,bces_rulearray+BCESFieldIndexTitle);	/* 公告标题 */
		AddField((void*)Content,sizeof(Content),NULL,0,bces_rulearray+BCESFieldIndexContent);	/* 公告内容 */
		AddField((void*)PublishDate,sizeof(PublishDate),NULL,0,bces_rulearray+BCESFieldIndexPublishDate);	/* 发布日期 */
		AddField((void*)PublishTime,sizeof(PublishTime),NULL,0,bces_rulearray+BCESFieldIndexPublishTime);	/* 发布时间 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 创建日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 创建时间 */
		AddField((void*)&PublishMethod,sizeof(PublishMethod),NULL,0,bces_rulearray+BCESFieldIndexPublishMethod);	/* 发布方式 */
		AddField((void*)PublishUserID,sizeof(PublishUserID),NULL,0,bces_rulearray+BCESFieldIndexPublishUserID);	/* 发布人 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Bulletin),0x00,sizeof(CBCESFieldsBulletin)-sizeof(CBMLFields)-sizeof(m_fieldarray_Bulletin));
	}

	BML_FIELD_INFO m_fieldarray_Bulletin[10];

	// Field
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
class CBCESFieldsBulletinQueryReq:public CBMLFields
{
public:
	CBCESFieldsBulletinQueryReq()
	{
		m_fieldarray=m_fieldarray_BulletinQueryReq;
		m_fieldsize=sizeof(m_fieldarray_BulletinQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsBulletinQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsBulletinQueryReq(const CBCESFieldsBulletinQueryReq& BulletinQueryReq){
		m_fieldarray=m_fieldarray_BulletinQueryReq;
		m_fieldsize=sizeof(m_fieldarray_BulletinQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&BulletinQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsBulletinQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsBulletinQueryReq& operator=(const CBCESFieldsBulletinQueryReq& BulletinQueryReq){
		m_fieldarray=m_fieldarray_BulletinQueryReq;
		m_fieldsize=sizeof(m_fieldarray_BulletinQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&BulletinQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsBulletinQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_BulletinQueryReq),0x00,sizeof(CBCESFieldsBulletinQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_BulletinQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_BulletinQueryReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 通知查询请求 */
class CBCESFieldsNoticeQueryReq:public CBMLFields
{
public:
	CBCESFieldsNoticeQueryReq()
	{
		m_fieldarray=m_fieldarray_NoticeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_NoticeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsNoticeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsNoticeQueryReq(const CBCESFieldsNoticeQueryReq& NoticeQueryReq){
		m_fieldarray=m_fieldarray_NoticeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_NoticeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&NoticeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsNoticeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsNoticeQueryReq& operator=(const CBCESFieldsNoticeQueryReq& NoticeQueryReq){
		m_fieldarray=m_fieldarray_NoticeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_NoticeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&NoticeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsNoticeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_NoticeQueryReq),0x00,sizeof(CBCESFieldsNoticeQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_NoticeQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_NoticeQueryReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 通知 */
class CBCESFieldsNotice:public CBMLFields
{
public:
	CBCESFieldsNotice()
	{
		m_fieldarray=m_fieldarray_Notice;
		m_fieldsize=sizeof(m_fieldarray_Notice)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsNotice)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)NoticeID,sizeof(NoticeID),NULL,0,bces_rulearray+BCESFieldIndexNoticeID);	/* 通知编号 */
		AddField((void*)Title,sizeof(Title),NULL,0,bces_rulearray+BCESFieldIndexTitle);	/* 通知标题 */
		AddField((void*)Content,sizeof(Content),NULL,0,bces_rulearray+BCESFieldIndexContent);	/* 通知内容 */
		AddField((void*)PublishDate,sizeof(PublishDate),NULL,0,bces_rulearray+BCESFieldIndexPublishDate);	/* 发布日期 */
		AddField((void*)PublishTime,sizeof(PublishTime),NULL,0,bces_rulearray+BCESFieldIndexPublishTime);	/* 发布时间 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 创建日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 创建时间 */
		AddField((void*)&PublishMethod,sizeof(PublishMethod),NULL,0,bces_rulearray+BCESFieldIndexPublishMethod);	/* 发布方式 */
		AddField((void*)PublishUserID,sizeof(PublishUserID),NULL,0,bces_rulearray+BCESFieldIndexPublishUserID);	/* 发布人 */
	}
	CBCESFieldsNotice(const CBCESFieldsNotice& Notice){
		m_fieldarray=m_fieldarray_Notice;
		m_fieldsize=sizeof(m_fieldarray_Notice)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Notice+sizeof(CBMLFields),sizeof(CBCESFieldsNotice)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)NoticeID,sizeof(NoticeID),NULL,0,bces_rulearray+BCESFieldIndexNoticeID);	/* 通知编号 */
		AddField((void*)Title,sizeof(Title),NULL,0,bces_rulearray+BCESFieldIndexTitle);	/* 通知标题 */
		AddField((void*)Content,sizeof(Content),NULL,0,bces_rulearray+BCESFieldIndexContent);	/* 通知内容 */
		AddField((void*)PublishDate,sizeof(PublishDate),NULL,0,bces_rulearray+BCESFieldIndexPublishDate);	/* 发布日期 */
		AddField((void*)PublishTime,sizeof(PublishTime),NULL,0,bces_rulearray+BCESFieldIndexPublishTime);	/* 发布时间 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 创建日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 创建时间 */
		AddField((void*)&PublishMethod,sizeof(PublishMethod),NULL,0,bces_rulearray+BCESFieldIndexPublishMethod);	/* 发布方式 */
		AddField((void*)PublishUserID,sizeof(PublishUserID),NULL,0,bces_rulearray+BCESFieldIndexPublishUserID);	/* 发布人 */
	}
	CBCESFieldsNotice& operator=(const CBCESFieldsNotice& Notice){
		m_fieldarray=m_fieldarray_Notice;
		m_fieldsize=sizeof(m_fieldarray_Notice)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Notice+sizeof(CBMLFields),sizeof(CBCESFieldsNotice)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)NoticeID,sizeof(NoticeID),NULL,0,bces_rulearray+BCESFieldIndexNoticeID);	/* 通知编号 */
		AddField((void*)Title,sizeof(Title),NULL,0,bces_rulearray+BCESFieldIndexTitle);	/* 通知标题 */
		AddField((void*)Content,sizeof(Content),NULL,0,bces_rulearray+BCESFieldIndexContent);	/* 通知内容 */
		AddField((void*)PublishDate,sizeof(PublishDate),NULL,0,bces_rulearray+BCESFieldIndexPublishDate);	/* 发布日期 */
		AddField((void*)PublishTime,sizeof(PublishTime),NULL,0,bces_rulearray+BCESFieldIndexPublishTime);	/* 发布时间 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 创建日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 创建时间 */
		AddField((void*)&PublishMethod,sizeof(PublishMethod),NULL,0,bces_rulearray+BCESFieldIndexPublishMethod);	/* 发布方式 */
		AddField((void*)PublishUserID,sizeof(PublishUserID),NULL,0,bces_rulearray+BCESFieldIndexPublishUserID);	/* 发布人 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Notice),0x00,sizeof(CBCESFieldsNotice)-sizeof(CBMLFields)-sizeof(m_fieldarray_Notice));
	}

	BML_FIELD_INFO m_fieldarray_Notice[10];

	// Field
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
class CBCESFieldsElectronicFundIOReq:public CBMLFields
{
public:
	CBCESFieldsElectronicFundIOReq()
	{
		m_fieldarray=m_fieldarray_ElectronicFundIOReq;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIOReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsElectronicFundIOReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
	}
	CBCESFieldsElectronicFundIOReq(const CBCESFieldsElectronicFundIOReq& ElectronicFundIOReq){
		m_fieldarray=m_fieldarray_ElectronicFundIOReq;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIOReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ElectronicFundIOReq+sizeof(CBMLFields),sizeof(CBCESFieldsElectronicFundIOReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
	}
	CBCESFieldsElectronicFundIOReq& operator=(const CBCESFieldsElectronicFundIOReq& ElectronicFundIOReq){
		m_fieldarray=m_fieldarray_ElectronicFundIOReq;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIOReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ElectronicFundIOReq+sizeof(CBMLFields),sizeof(CBCESFieldsElectronicFundIOReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ElectronicFundIOReq),0x00,sizeof(CBCESFieldsElectronicFundIOReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_ElectronicFundIOReq));
	}

	BML_FIELD_INFO m_fieldarray_ElectronicFundIOReq[6];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag FundIODirection;	/* 出入金方向 */
	BCESFieldTypeAmount Amount;	/* 金额 */
	BCESFieldTypeBankAccountID ReceiveAccountID;	/* 收款帐号 */
	BCESFieldTypeBankAccountName ReceiveAccountName;	/* 收款户名 */
	BCESFieldTypeBankID ReceiveBankID;	/* 收款行号 */
};

/* 电子出入金响应 */
class CBCESFieldsElectronicFundIORsp:public CBMLFields
{
public:
	CBCESFieldsElectronicFundIORsp()
	{
		m_fieldarray=m_fieldarray_ElectronicFundIORsp;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIORsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsElectronicFundIORsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)PayURL,sizeof(PayURL),NULL,0,bces_rulearray+BCESFieldIndexPayURL);	/* 支付链接 */
	}
	CBCESFieldsElectronicFundIORsp(const CBCESFieldsElectronicFundIORsp& ElectronicFundIORsp){
		m_fieldarray=m_fieldarray_ElectronicFundIORsp;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIORsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ElectronicFundIORsp+sizeof(CBMLFields),sizeof(CBCESFieldsElectronicFundIORsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)PayURL,sizeof(PayURL),NULL,0,bces_rulearray+BCESFieldIndexPayURL);	/* 支付链接 */
	}
	CBCESFieldsElectronicFundIORsp& operator=(const CBCESFieldsElectronicFundIORsp& ElectronicFundIORsp){
		m_fieldarray=m_fieldarray_ElectronicFundIORsp;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIORsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ElectronicFundIORsp+sizeof(CBMLFields),sizeof(CBCESFieldsElectronicFundIORsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)PayURL,sizeof(PayURL),NULL,0,bces_rulearray+BCESFieldIndexPayURL);	/* 支付链接 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ElectronicFundIORsp),0x00,sizeof(CBCESFieldsElectronicFundIORsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_ElectronicFundIORsp));
	}

	BML_FIELD_INFO m_fieldarray_ElectronicFundIORsp[14];

	// Field
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
class CBCESFieldsElectronicFundIONty:public CBMLFields
{
public:
	CBCESFieldsElectronicFundIONty()
	{
		m_fieldarray=m_fieldarray_ElectronicFundIONty;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIONty)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsElectronicFundIONty)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)PayURL,sizeof(PayURL),NULL,0,bces_rulearray+BCESFieldIndexPayURL);	/* 支付链接 */
	}
	CBCESFieldsElectronicFundIONty(const CBCESFieldsElectronicFundIONty& ElectronicFundIONty){
		m_fieldarray=m_fieldarray_ElectronicFundIONty;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIONty)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ElectronicFundIONty+sizeof(CBMLFields),sizeof(CBCESFieldsElectronicFundIONty)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)PayURL,sizeof(PayURL),NULL,0,bces_rulearray+BCESFieldIndexPayURL);	/* 支付链接 */
	}
	CBCESFieldsElectronicFundIONty& operator=(const CBCESFieldsElectronicFundIONty& ElectronicFundIONty){
		m_fieldarray=m_fieldarray_ElectronicFundIONty;
		m_fieldsize=sizeof(m_fieldarray_ElectronicFundIONty)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ElectronicFundIONty+sizeof(CBMLFields),sizeof(CBCESFieldsElectronicFundIONty)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)PayURL,sizeof(PayURL),NULL,0,bces_rulearray+BCESFieldIndexPayURL);	/* 支付链接 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ElectronicFundIONty),0x00,sizeof(CBCESFieldsElectronicFundIONty)-sizeof(CBMLFields)-sizeof(m_fieldarray_ElectronicFundIONty));
	}

	BML_FIELD_INFO m_fieldarray_ElectronicFundIONty[15];

	// Field
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
class CBCESFieldsFundIODetail:public CBMLFields
{
public:
	CBCESFieldsFundIODetail()
	{
		m_fieldarray=m_fieldarray_FundIODetail;
		m_fieldsize=sizeof(m_fieldarray_FundIODetail)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsFundIODetail)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)&FundIOMethod,sizeof(FundIOMethod),NULL,0,bces_rulearray+BCESFieldIndexFundIOMethod);	/* 出入金方式 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)PaySeqno,sizeof(PaySeqno),NULL,0,bces_rulearray+BCESFieldIndexPaySeqno);	/* 支付流水号 */
	}
	CBCESFieldsFundIODetail(const CBCESFieldsFundIODetail& FundIODetail){
		m_fieldarray=m_fieldarray_FundIODetail;
		m_fieldsize=sizeof(m_fieldarray_FundIODetail)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FundIODetail+sizeof(CBMLFields),sizeof(CBCESFieldsFundIODetail)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)&FundIOMethod,sizeof(FundIOMethod),NULL,0,bces_rulearray+BCESFieldIndexFundIOMethod);	/* 出入金方式 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)PaySeqno,sizeof(PaySeqno),NULL,0,bces_rulearray+BCESFieldIndexPaySeqno);	/* 支付流水号 */
	}
	CBCESFieldsFundIODetail& operator=(const CBCESFieldsFundIODetail& FundIODetail){
		m_fieldarray=m_fieldarray_FundIODetail;
		m_fieldsize=sizeof(m_fieldarray_FundIODetail)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FundIODetail+sizeof(CBMLFields),sizeof(CBCESFieldsFundIODetail)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TradeDate,sizeof(TradeDate),NULL,0,bces_rulearray+BCESFieldIndexTradeDate);	/* 交易日期 */
		AddField((void*)FundIOSeqno,sizeof(FundIOSeqno),NULL,0,bces_rulearray+BCESFieldIndexFundIOSeqno);	/* 出入金流水号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&FundIODirection,sizeof(FundIODirection),NULL,0,bces_rulearray+BCESFieldIndexFundIODirection);	/* 出入金方向 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 金额 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)&FundIOStatus,sizeof(FundIOStatus),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatus);	/* 出入金状态 */
		AddField((void*)CreateDate,sizeof(CreateDate),NULL,0,bces_rulearray+BCESFieldIndexCreateDate);	/* 发起日期 */
		AddField((void*)CreateTime,sizeof(CreateTime),NULL,0,bces_rulearray+BCESFieldIndexCreateTime);	/* 发起时间 */
		AddField((void*)CompleteDate,sizeof(CompleteDate),NULL,0,bces_rulearray+BCESFieldIndexCompleteDate);	/* 完成日期 */
		AddField((void*)CompleteTime,sizeof(CompleteTime),NULL,0,bces_rulearray+BCESFieldIndexCompleteTime);	/* 完成时间 */
		AddField((void*)&FundIOMethod,sizeof(FundIOMethod),NULL,0,bces_rulearray+BCESFieldIndexFundIOMethod);	/* 出入金方式 */
		AddField((void*)FundIOStatusDesc,sizeof(FundIOStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexFundIOStatusDesc);	/* 出入金状态描述 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)PaySeqno,sizeof(PaySeqno),NULL,0,bces_rulearray+BCESFieldIndexPaySeqno);	/* 支付流水号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_FundIODetail),0x00,sizeof(CBCESFieldsFundIODetail)-sizeof(CBMLFields)-sizeof(m_fieldarray_FundIODetail));
	}

	BML_FIELD_INFO m_fieldarray_FundIODetail[17];

	// Field
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
class CBCESFieldsFundIODetailQueryReq:public CBMLFields
{
public:
	CBCESFieldsFundIODetailQueryReq()
	{
		m_fieldarray=m_fieldarray_FundIODetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_FundIODetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsFundIODetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
	}
	CBCESFieldsFundIODetailQueryReq(const CBCESFieldsFundIODetailQueryReq& FundIODetailQueryReq){
		m_fieldarray=m_fieldarray_FundIODetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_FundIODetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FundIODetailQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsFundIODetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
	}
	CBCESFieldsFundIODetailQueryReq& operator=(const CBCESFieldsFundIODetailQueryReq& FundIODetailQueryReq){
		m_fieldarray=m_fieldarray_FundIODetailQueryReq;
		m_fieldsize=sizeof(m_fieldarray_FundIODetailQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&FundIODetailQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsFundIODetailQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_FundIODetailQueryReq),0x00,sizeof(CBCESFieldsFundIODetailQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_FundIODetailQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_FundIODetailQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 起始日期 */
};

/* 报表查询请求 */
class CBCESFieldsReportQueryReq:public CBMLFields
{
public:
	CBCESFieldsReportQueryReq()
	{
		m_fieldarray=m_fieldarray_ReportQueryReq;
		m_fieldsize=sizeof(m_fieldarray_ReportQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsReportQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsReportQueryReq(const CBCESFieldsReportQueryReq& ReportQueryReq){
		m_fieldarray=m_fieldarray_ReportQueryReq;
		m_fieldsize=sizeof(m_fieldarray_ReportQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ReportQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsReportQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsReportQueryReq& operator=(const CBCESFieldsReportQueryReq& ReportQueryReq){
		m_fieldarray=m_fieldarray_ReportQueryReq;
		m_fieldsize=sizeof(m_fieldarray_ReportQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&ReportQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsReportQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_ReportQueryReq),0x00,sizeof(CBCESFieldsReportQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_ReportQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_ReportQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 报表 */
class CBCESFieldsReport:public CBMLFields
{
public:
	CBCESFieldsReport()
	{
		m_fieldarray=m_fieldarray_Report;
		m_fieldsize=sizeof(m_fieldarray_Report)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsReport)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)ReportData,sizeof(ReportData),NULL,0,bces_rulearray+BCESFieldIndexReportData);	/* 报表内容 */
	}
	CBCESFieldsReport(const CBCESFieldsReport& Report){
		m_fieldarray=m_fieldarray_Report;
		m_fieldsize=sizeof(m_fieldarray_Report)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Report+sizeof(CBMLFields),sizeof(CBCESFieldsReport)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)ReportData,sizeof(ReportData),NULL,0,bces_rulearray+BCESFieldIndexReportData);	/* 报表内容 */
	}
	CBCESFieldsReport& operator=(const CBCESFieldsReport& Report){
		m_fieldarray=m_fieldarray_Report;
		m_fieldsize=sizeof(m_fieldarray_Report)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Report+sizeof(CBMLFields),sizeof(CBCESFieldsReport)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)ReportData,sizeof(ReportData),NULL,0,bces_rulearray+BCESFieldIndexReportData);	/* 报表内容 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Report),0x00,sizeof(CBCESFieldsReport)-sizeof(CBMLFields)-sizeof(m_fieldarray_Report));
	}

	BML_FIELD_INFO m_fieldarray_Report[1];

	// Field
	BCESFieldTypeReportData ReportData;	/* 报表内容 */
};

/* 历史订单查询请求 */
class CBCESFieldsHisOrderQueryReq:public CBMLFields
{
public:
	CBCESFieldsHisOrderQueryReq()
	{
		m_fieldarray=m_fieldarray_HisOrderQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisOrderQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHisOrderQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsHisOrderQueryReq(const CBCESFieldsHisOrderQueryReq& HisOrderQueryReq){
		m_fieldarray=m_fieldarray_HisOrderQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisOrderQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisOrderQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisOrderQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsHisOrderQueryReq& operator=(const CBCESFieldsHisOrderQueryReq& HisOrderQueryReq){
		m_fieldarray=m_fieldarray_HisOrderQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisOrderQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisOrderQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisOrderQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_HisOrderQueryReq),0x00,sizeof(CBCESFieldsHisOrderQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_HisOrderQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_HisOrderQueryReq[4];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 历史成交查询请求 */
class CBCESFieldsHisTradeQueryReq:public CBMLFields
{
public:
	CBCESFieldsHisTradeQueryReq()
	{
		m_fieldarray=m_fieldarray_HisTradeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisTradeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHisTradeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsHisTradeQueryReq(const CBCESFieldsHisTradeQueryReq& HisTradeQueryReq){
		m_fieldarray=m_fieldarray_HisTradeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisTradeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisTradeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisTradeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsHisTradeQueryReq& operator=(const CBCESFieldsHisTradeQueryReq& HisTradeQueryReq){
		m_fieldarray=m_fieldarray_HisTradeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisTradeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisTradeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisTradeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_HisTradeQueryReq),0x00,sizeof(CBCESFieldsHisTradeQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_HisTradeQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_HisTradeQueryReq[4];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 历史公告查询请求 */
class CBCESFieldsHisBulletinQueryReq:public CBMLFields
{
public:
	CBCESFieldsHisBulletinQueryReq()
	{
		m_fieldarray=m_fieldarray_HisBulletinQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisBulletinQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHisBulletinQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
	}
	CBCESFieldsHisBulletinQueryReq(const CBCESFieldsHisBulletinQueryReq& HisBulletinQueryReq){
		m_fieldarray=m_fieldarray_HisBulletinQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisBulletinQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisBulletinQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisBulletinQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
	}
	CBCESFieldsHisBulletinQueryReq& operator=(const CBCESFieldsHisBulletinQueryReq& HisBulletinQueryReq){
		m_fieldarray=m_fieldarray_HisBulletinQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisBulletinQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisBulletinQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisBulletinQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_HisBulletinQueryReq),0x00,sizeof(CBCESFieldsHisBulletinQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_HisBulletinQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_HisBulletinQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 起始日期 */
};

/* 历史通知查询请求 */
class CBCESFieldsHisNoticeQueryReq:public CBMLFields
{
public:
	CBCESFieldsHisNoticeQueryReq()
	{
		m_fieldarray=m_fieldarray_HisNoticeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisNoticeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsHisNoticeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
	}
	CBCESFieldsHisNoticeQueryReq(const CBCESFieldsHisNoticeQueryReq& HisNoticeQueryReq){
		m_fieldarray=m_fieldarray_HisNoticeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisNoticeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisNoticeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisNoticeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
	}
	CBCESFieldsHisNoticeQueryReq& operator=(const CBCESFieldsHisNoticeQueryReq& HisNoticeQueryReq){
		m_fieldarray=m_fieldarray_HisNoticeQueryReq;
		m_fieldsize=sizeof(m_fieldarray_HisNoticeQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&HisNoticeQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsHisNoticeQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 起始日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_HisNoticeQueryReq),0x00,sizeof(CBCESFieldsHisNoticeQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_HisNoticeQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_HisNoticeQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 起始日期 */
};

/* 投资者排名 */
class CBCESFieldsInvestorRanking:public CBMLFields
{
public:
	CBCESFieldsInvestorRanking()
	{
		m_fieldarray=m_fieldarray_InvestorRanking;
		m_fieldsize=sizeof(m_fieldarray_InvestorRanking)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInvestorRanking)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentName,sizeof(InstrumentName),NULL,0,bces_rulearray+BCESFieldIndexInstrumentName);	/* 合约名 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
	}
	CBCESFieldsInvestorRanking(const CBCESFieldsInvestorRanking& InvestorRanking){
		m_fieldarray=m_fieldarray_InvestorRanking;
		m_fieldsize=sizeof(m_fieldarray_InvestorRanking)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorRanking+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorRanking)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentName,sizeof(InstrumentName),NULL,0,bces_rulearray+BCESFieldIndexInstrumentName);	/* 合约名 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
	}
	CBCESFieldsInvestorRanking& operator=(const CBCESFieldsInvestorRanking& InvestorRanking){
		m_fieldarray=m_fieldarray_InvestorRanking;
		m_fieldsize=sizeof(m_fieldarray_InvestorRanking)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorRanking+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorRanking)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentName,sizeof(InstrumentName),NULL,0,bces_rulearray+BCESFieldIndexInstrumentName);	/* 合约名 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InvestorRanking),0x00,sizeof(CBCESFieldsInvestorRanking)-sizeof(CBMLFields)-sizeof(m_fieldarray_InvestorRanking));
	}

	BML_FIELD_INFO m_fieldarray_InvestorRanking[4];

	// Field
	BCESFieldTypeInstrumentName InstrumentName;	/* 合约名 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};

/* 查询投资者排名请求 */
class CBCESFieldsInvestorRankingQueryReq:public CBMLFields
{
public:
	CBCESFieldsInvestorRankingQueryReq()
	{
		m_fieldarray=m_fieldarray_InvestorRankingQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InvestorRankingQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInvestorRankingQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsInvestorRankingQueryReq(const CBCESFieldsInvestorRankingQueryReq& InvestorRankingQueryReq){
		m_fieldarray=m_fieldarray_InvestorRankingQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InvestorRankingQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorRankingQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorRankingQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsInvestorRankingQueryReq& operator=(const CBCESFieldsInvestorRankingQueryReq& InvestorRankingQueryReq){
		m_fieldarray=m_fieldarray_InvestorRankingQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InvestorRankingQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorRankingQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorRankingQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InvestorRankingQueryReq),0x00,sizeof(CBCESFieldsInvestorRankingQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_InvestorRankingQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_InvestorRankingQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 交易设置 */
class CBCESFieldsTradeSettings:public CBMLFields
{
public:
	CBCESFieldsTradeSettings()
	{
		m_fieldarray=m_fieldarray_TradeSettings;
		m_fieldsize=sizeof(m_fieldarray_TradeSettings)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettings)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
	}
	CBCESFieldsTradeSettings(const CBCESFieldsTradeSettings& TradeSettings){
		m_fieldarray=m_fieldarray_TradeSettings;
		m_fieldsize=sizeof(m_fieldarray_TradeSettings)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettings+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettings)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
	}
	CBCESFieldsTradeSettings& operator=(const CBCESFieldsTradeSettings& TradeSettings){
		m_fieldarray=m_fieldarray_TradeSettings;
		m_fieldsize=sizeof(m_fieldarray_TradeSettings)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettings+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettings)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettings),0x00,sizeof(CBCESFieldsTradeSettings)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettings));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettings[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};

/* 交易设置增加请求 */
class CBCESFieldsTradeSettingsAddReq:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsAddReq()
	{
		m_fieldarray=m_fieldarray_TradeSettingsAddReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsAddReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsAddReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
	}
	CBCESFieldsTradeSettingsAddReq(const CBCESFieldsTradeSettingsAddReq& TradeSettingsAddReq){
		m_fieldarray=m_fieldarray_TradeSettingsAddReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsAddReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsAddReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsAddReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
	}
	CBCESFieldsTradeSettingsAddReq& operator=(const CBCESFieldsTradeSettingsAddReq& TradeSettingsAddReq){
		m_fieldarray=m_fieldarray_TradeSettingsAddReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsAddReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsAddReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsAddReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsAddReq),0x00,sizeof(CBCESFieldsTradeSettingsAddReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsAddReq));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsAddReq[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};

/* 交易设置增加应答 */
class CBCESFieldsTradeSettingsAddRsp:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsAddRsp()
	{
		m_fieldarray=m_fieldarray_TradeSettingsAddRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsAddRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsAddRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsAddRsp(const CBCESFieldsTradeSettingsAddRsp& TradeSettingsAddRsp){
		m_fieldarray=m_fieldarray_TradeSettingsAddRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsAddRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsAddRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsAddRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsAddRsp& operator=(const CBCESFieldsTradeSettingsAddRsp& TradeSettingsAddRsp){
		m_fieldarray=m_fieldarray_TradeSettingsAddRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsAddRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsAddRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsAddRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsAddRsp),0x00,sizeof(CBCESFieldsTradeSettingsAddRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsAddRsp));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsAddRsp[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置修改请求 */
class CBCESFieldsTradeSettingsModifyReq:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsModifyReq()
	{
		m_fieldarray=m_fieldarray_TradeSettingsModifyReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
	}
	CBCESFieldsTradeSettingsModifyReq(const CBCESFieldsTradeSettingsModifyReq& TradeSettingsModifyReq){
		m_fieldarray=m_fieldarray_TradeSettingsModifyReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsModifyReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
	}
	CBCESFieldsTradeSettingsModifyReq& operator=(const CBCESFieldsTradeSettingsModifyReq& TradeSettingsModifyReq){
		m_fieldarray=m_fieldarray_TradeSettingsModifyReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsModifyReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&TradeAction,sizeof(TradeAction),NULL,0,bces_rulearray+BCESFieldIndexTradeAction);	/* 交易行为 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsModifyReq),0x00,sizeof(CBCESFieldsTradeSettingsModifyReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsModifyReq));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsModifyReq[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag TradeAction;	/* 交易行为 */
};

/* 交易设置修改应答 */
class CBCESFieldsTradeSettingsModifyRsp:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsModifyRsp()
	{
		m_fieldarray=m_fieldarray_TradeSettingsModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsModifyRsp(const CBCESFieldsTradeSettingsModifyRsp& TradeSettingsModifyRsp){
		m_fieldarray=m_fieldarray_TradeSettingsModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsModifyRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsModifyRsp& operator=(const CBCESFieldsTradeSettingsModifyRsp& TradeSettingsModifyRsp){
		m_fieldarray=m_fieldarray_TradeSettingsModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsModifyRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsModifyRsp),0x00,sizeof(CBCESFieldsTradeSettingsModifyRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsModifyRsp));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsModifyRsp[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置删除请求 */
class CBCESFieldsTradeSettingsDeleteReq:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsDeleteReq()
	{
		m_fieldarray=m_fieldarray_TradeSettingsDeleteReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsDeleteReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsDeleteReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsDeleteReq(const CBCESFieldsTradeSettingsDeleteReq& TradeSettingsDeleteReq){
		m_fieldarray=m_fieldarray_TradeSettingsDeleteReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsDeleteReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsDeleteReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsDeleteReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsDeleteReq& operator=(const CBCESFieldsTradeSettingsDeleteReq& TradeSettingsDeleteReq){
		m_fieldarray=m_fieldarray_TradeSettingsDeleteReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsDeleteReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsDeleteReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsDeleteReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsDeleteReq),0x00,sizeof(CBCESFieldsTradeSettingsDeleteReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsDeleteReq));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsDeleteReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置删除应答 */
class CBCESFieldsTradeSettingsDeleteRsp:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsDeleteRsp()
	{
		m_fieldarray=m_fieldarray_TradeSettingsDeleteRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsDeleteRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsDeleteRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsDeleteRsp(const CBCESFieldsTradeSettingsDeleteRsp& TradeSettingsDeleteRsp){
		m_fieldarray=m_fieldarray_TradeSettingsDeleteRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsDeleteRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsDeleteRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsDeleteRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsDeleteRsp& operator=(const CBCESFieldsTradeSettingsDeleteRsp& TradeSettingsDeleteRsp){
		m_fieldarray=m_fieldarray_TradeSettingsDeleteRsp;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsDeleteRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsDeleteRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsDeleteRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsDeleteRsp),0x00,sizeof(CBCESFieldsTradeSettingsDeleteRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsDeleteRsp));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsDeleteRsp[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 交易设置查询请求 */
class CBCESFieldsTradeSettingsQueryReq:public CBMLFields
{
public:
	CBCESFieldsTradeSettingsQueryReq()
	{
		m_fieldarray=m_fieldarray_TradeSettingsQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeSettingsQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsQueryReq(const CBCESFieldsTradeSettingsQueryReq& TradeSettingsQueryReq){
		m_fieldarray=m_fieldarray_TradeSettingsQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsTradeSettingsQueryReq& operator=(const CBCESFieldsTradeSettingsQueryReq& TradeSettingsQueryReq){
		m_fieldarray=m_fieldarray_TradeSettingsQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TradeSettingsQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeSettingsQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTradeSettingsQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeSettingsQueryReq),0x00,sizeof(CBCESFieldsTradeSettingsQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeSettingsQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_TradeSettingsQueryReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 签约信息 */
class CBCESFieldsAccountBind:public CBMLFields
{
public:
	CBCESFieldsAccountBind()
	{
		m_fieldarray=m_fieldarray_AccountBind;
		m_fieldsize=sizeof(m_fieldarray_AccountBind)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsAccountBind)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)ReceiveProvice,sizeof(ReceiveProvice),NULL,0,bces_rulearray+BCESFieldIndexReceiveProvice);	/* 开户省份 */
		AddField((void*)ReceiveCity,sizeof(ReceiveCity),NULL,0,bces_rulearray+BCESFieldIndexReceiveCity);	/* 开户市 */
		AddField((void*)&AccountBindStatus,sizeof(AccountBindStatus),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatus);	/* 签约状态 */
		AddField((void*)AccountBindStatusDesc,sizeof(AccountBindStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatusDesc);	/* 签约状态描述 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
	}
	CBCESFieldsAccountBind(const CBCESFieldsAccountBind& AccountBind){
		m_fieldarray=m_fieldarray_AccountBind;
		m_fieldsize=sizeof(m_fieldarray_AccountBind)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBind+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBind)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)ReceiveProvice,sizeof(ReceiveProvice),NULL,0,bces_rulearray+BCESFieldIndexReceiveProvice);	/* 开户省份 */
		AddField((void*)ReceiveCity,sizeof(ReceiveCity),NULL,0,bces_rulearray+BCESFieldIndexReceiveCity);	/* 开户市 */
		AddField((void*)&AccountBindStatus,sizeof(AccountBindStatus),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatus);	/* 签约状态 */
		AddField((void*)AccountBindStatusDesc,sizeof(AccountBindStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatusDesc);	/* 签约状态描述 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
	}
	CBCESFieldsAccountBind& operator=(const CBCESFieldsAccountBind& AccountBind){
		m_fieldarray=m_fieldarray_AccountBind;
		m_fieldsize=sizeof(m_fieldarray_AccountBind)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBind+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBind)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)ReceiveProvice,sizeof(ReceiveProvice),NULL,0,bces_rulearray+BCESFieldIndexReceiveProvice);	/* 开户省份 */
		AddField((void*)ReceiveCity,sizeof(ReceiveCity),NULL,0,bces_rulearray+BCESFieldIndexReceiveCity);	/* 开户市 */
		AddField((void*)&AccountBindStatus,sizeof(AccountBindStatus),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatus);	/* 签约状态 */
		AddField((void*)AccountBindStatusDesc,sizeof(AccountBindStatusDesc),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatusDesc);	/* 签约状态描述 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_AccountBind),0x00,sizeof(CBCESFieldsAccountBind)-sizeof(CBMLFields)-sizeof(m_fieldarray_AccountBind));
	}

	BML_FIELD_INFO m_fieldarray_AccountBind[11];

	// Field
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
class CBCESFieldsAccountBindReq:public CBMLFields
{
public:
	CBCESFieldsAccountBindReq()
	{
		m_fieldarray=m_fieldarray_AccountBindReq;
		m_fieldsize=sizeof(m_fieldarray_AccountBindReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsAccountBindReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)ReceiveProvice,sizeof(ReceiveProvice),NULL,0,bces_rulearray+BCESFieldIndexReceiveProvice);	/* 开户省份 */
		AddField((void*)ReceiveCity,sizeof(ReceiveCity),NULL,0,bces_rulearray+BCESFieldIndexReceiveCity);	/* 开户市 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
	}
	CBCESFieldsAccountBindReq(const CBCESFieldsAccountBindReq& AccountBindReq){
		m_fieldarray=m_fieldarray_AccountBindReq;
		m_fieldsize=sizeof(m_fieldarray_AccountBindReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBindReq+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBindReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)ReceiveProvice,sizeof(ReceiveProvice),NULL,0,bces_rulearray+BCESFieldIndexReceiveProvice);	/* 开户省份 */
		AddField((void*)ReceiveCity,sizeof(ReceiveCity),NULL,0,bces_rulearray+BCESFieldIndexReceiveCity);	/* 开户市 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
	}
	CBCESFieldsAccountBindReq& operator=(const CBCESFieldsAccountBindReq& AccountBindReq){
		m_fieldarray=m_fieldarray_AccountBindReq;
		m_fieldsize=sizeof(m_fieldarray_AccountBindReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBindReq+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBindReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)ReceiveAccountID,sizeof(ReceiveAccountID),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountID);	/* 收款帐号 */
		AddField((void*)ReceiveAccountName,sizeof(ReceiveAccountName),NULL,0,bces_rulearray+BCESFieldIndexReceiveAccountName);	/* 收款户名 */
		AddField((void*)ReceiveBankID,sizeof(ReceiveBankID),NULL,0,bces_rulearray+BCESFieldIndexReceiveBankID);	/* 收款行号 */
		AddField((void*)ReceiveBranchName,sizeof(ReceiveBranchName),NULL,0,bces_rulearray+BCESFieldIndexReceiveBranchName);	/* 支行名称 */
		AddField((void*)ReceiveProvice,sizeof(ReceiveProvice),NULL,0,bces_rulearray+BCESFieldIndexReceiveProvice);	/* 开户省份 */
		AddField((void*)ReceiveCity,sizeof(ReceiveCity),NULL,0,bces_rulearray+BCESFieldIndexReceiveCity);	/* 开户市 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_AccountBindReq),0x00,sizeof(CBCESFieldsAccountBindReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_AccountBindReq));
	}

	BML_FIELD_INFO m_fieldarray_AccountBindReq[9];

	// Field
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
class CBCESFieldsAccountBindQueryReq:public CBMLFields
{
public:
	CBCESFieldsAccountBindQueryReq()
	{
		m_fieldarray=m_fieldarray_AccountBindQueryReq;
		m_fieldsize=sizeof(m_fieldarray_AccountBindQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsAccountBindQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsAccountBindQueryReq(const CBCESFieldsAccountBindQueryReq& AccountBindQueryReq){
		m_fieldarray=m_fieldarray_AccountBindQueryReq;
		m_fieldsize=sizeof(m_fieldarray_AccountBindQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBindQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBindQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
	}
	CBCESFieldsAccountBindQueryReq& operator=(const CBCESFieldsAccountBindQueryReq& AccountBindQueryReq){
		m_fieldarray=m_fieldarray_AccountBindQueryReq;
		m_fieldsize=sizeof(m_fieldarray_AccountBindQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBindQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBindQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_AccountBindQueryReq),0x00,sizeof(CBCESFieldsAccountBindQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_AccountBindQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_AccountBindQueryReq[1];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
};

/* 签约应答 */
class CBCESFieldsAccountBindRsp:public CBMLFields
{
public:
	CBCESFieldsAccountBindRsp()
	{
		m_fieldarray=m_fieldarray_AccountBindRsp;
		m_fieldsize=sizeof(m_fieldarray_AccountBindRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsAccountBindRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AccountBindURL,sizeof(AccountBindURL),NULL,0,bces_rulearray+BCESFieldIndexAccountBindURL);	/* 网址 */
		AddField((void*)&AccountBindStatus,sizeof(AccountBindStatus),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatus);	/* 签约状态 */
	}
	CBCESFieldsAccountBindRsp(const CBCESFieldsAccountBindRsp& AccountBindRsp){
		m_fieldarray=m_fieldarray_AccountBindRsp;
		m_fieldsize=sizeof(m_fieldarray_AccountBindRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBindRsp+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBindRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AccountBindURL,sizeof(AccountBindURL),NULL,0,bces_rulearray+BCESFieldIndexAccountBindURL);	/* 网址 */
		AddField((void*)&AccountBindStatus,sizeof(AccountBindStatus),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatus);	/* 签约状态 */
	}
	CBCESFieldsAccountBindRsp& operator=(const CBCESFieldsAccountBindRsp& AccountBindRsp){
		m_fieldarray=m_fieldarray_AccountBindRsp;
		m_fieldsize=sizeof(m_fieldarray_AccountBindRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&AccountBindRsp+sizeof(CBMLFields),sizeof(CBCESFieldsAccountBindRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AccountBindURL,sizeof(AccountBindURL),NULL,0,bces_rulearray+BCESFieldIndexAccountBindURL);	/* 网址 */
		AddField((void*)&AccountBindStatus,sizeof(AccountBindStatus),NULL,0,bces_rulearray+BCESFieldIndexAccountBindStatus);	/* 签约状态 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_AccountBindRsp),0x00,sizeof(CBCESFieldsAccountBindRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_AccountBindRsp));
	}

	BML_FIELD_INFO m_fieldarray_AccountBindRsp[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeURL AccountBindURL;	/* 网址 */
	BCESFieldTypeFlag AccountBindStatus;	/* 签约状态 */
};

/* 测试设置修改请求 */
class CBCESFieldsTestSettingsModifyReq:public CBMLFields
{
public:
	CBCESFieldsTestSettingsModifyReq()
	{
		m_fieldarray=m_fieldarray_TestSettingsModifyReq;
		m_fieldsize=sizeof(m_fieldarray_TestSettingsModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTestSettingsModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)UserID,sizeof(UserID),NULL,0,bces_rulearray+BCESFieldIndexUserID);	/* 用户号 */
		AddField((void*)&ErrNetTradeSec,sizeof(ErrNetTradeSec),NULL,0,bces_rulearray+BCESFieldIndexErrNetTradeSec);	/* 网络故障成交延迟 */
		AddField((void*)&ErrNetRemindSec,sizeof(ErrNetRemindSec),NULL,0,bces_rulearray+BCESFieldIndexErrNetRemindSec);	/* 网络故障提醒延迟 */
		AddField((void*)ErrNetRemindTxt,sizeof(ErrNetRemindTxt),NULL,0,bces_rulearray+BCESFieldIndexErrNetRemindTxt);	/* 网络故障提醒信息 */
		AddField((void*)&ErrSeverTradePort,sizeof(ErrSeverTradePort),NULL,0,bces_rulearray+BCESFieldIndexErrSeverTradePort);	/* 服务器故障成交点差 */
		AddField((void*)&ErrSeverRemindPort,sizeof(ErrSeverRemindPort),NULL,0,bces_rulearray+BCESFieldIndexErrSeverRemindPort);	/* 服务器故障提醒点差 */
		AddField((void*)ErrSeverRemindTxt,sizeof(ErrSeverRemindTxt),NULL,0,bces_rulearray+BCESFieldIndexErrSeverRemindTxt);	/* 服务器故障提醒信息 */
	}
	CBCESFieldsTestSettingsModifyReq(const CBCESFieldsTestSettingsModifyReq& TestSettingsModifyReq){
		m_fieldarray=m_fieldarray_TestSettingsModifyReq;
		m_fieldsize=sizeof(m_fieldarray_TestSettingsModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TestSettingsModifyReq+sizeof(CBMLFields),sizeof(CBCESFieldsTestSettingsModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)UserID,sizeof(UserID),NULL,0,bces_rulearray+BCESFieldIndexUserID);	/* 用户号 */
		AddField((void*)&ErrNetTradeSec,sizeof(ErrNetTradeSec),NULL,0,bces_rulearray+BCESFieldIndexErrNetTradeSec);	/* 网络故障成交延迟 */
		AddField((void*)&ErrNetRemindSec,sizeof(ErrNetRemindSec),NULL,0,bces_rulearray+BCESFieldIndexErrNetRemindSec);	/* 网络故障提醒延迟 */
		AddField((void*)ErrNetRemindTxt,sizeof(ErrNetRemindTxt),NULL,0,bces_rulearray+BCESFieldIndexErrNetRemindTxt);	/* 网络故障提醒信息 */
		AddField((void*)&ErrSeverTradePort,sizeof(ErrSeverTradePort),NULL,0,bces_rulearray+BCESFieldIndexErrSeverTradePort);	/* 服务器故障成交点差 */
		AddField((void*)&ErrSeverRemindPort,sizeof(ErrSeverRemindPort),NULL,0,bces_rulearray+BCESFieldIndexErrSeverRemindPort);	/* 服务器故障提醒点差 */
		AddField((void*)ErrSeverRemindTxt,sizeof(ErrSeverRemindTxt),NULL,0,bces_rulearray+BCESFieldIndexErrSeverRemindTxt);	/* 服务器故障提醒信息 */
	}
	CBCESFieldsTestSettingsModifyReq& operator=(const CBCESFieldsTestSettingsModifyReq& TestSettingsModifyReq){
		m_fieldarray=m_fieldarray_TestSettingsModifyReq;
		m_fieldsize=sizeof(m_fieldarray_TestSettingsModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TestSettingsModifyReq+sizeof(CBMLFields),sizeof(CBCESFieldsTestSettingsModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)UserID,sizeof(UserID),NULL,0,bces_rulearray+BCESFieldIndexUserID);	/* 用户号 */
		AddField((void*)&ErrNetTradeSec,sizeof(ErrNetTradeSec),NULL,0,bces_rulearray+BCESFieldIndexErrNetTradeSec);	/* 网络故障成交延迟 */
		AddField((void*)&ErrNetRemindSec,sizeof(ErrNetRemindSec),NULL,0,bces_rulearray+BCESFieldIndexErrNetRemindSec);	/* 网络故障提醒延迟 */
		AddField((void*)ErrNetRemindTxt,sizeof(ErrNetRemindTxt),NULL,0,bces_rulearray+BCESFieldIndexErrNetRemindTxt);	/* 网络故障提醒信息 */
		AddField((void*)&ErrSeverTradePort,sizeof(ErrSeverTradePort),NULL,0,bces_rulearray+BCESFieldIndexErrSeverTradePort);	/* 服务器故障成交点差 */
		AddField((void*)&ErrSeverRemindPort,sizeof(ErrSeverRemindPort),NULL,0,bces_rulearray+BCESFieldIndexErrSeverRemindPort);	/* 服务器故障提醒点差 */
		AddField((void*)ErrSeverRemindTxt,sizeof(ErrSeverRemindTxt),NULL,0,bces_rulearray+BCESFieldIndexErrSeverRemindTxt);	/* 服务器故障提醒信息 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TestSettingsModifyReq),0x00,sizeof(CBCESFieldsTestSettingsModifyReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TestSettingsModifyReq));
	}

	BML_FIELD_INFO m_fieldarray_TestSettingsModifyReq[7];

	// Field
	BCESFieldTypeUserID UserID;	/* 用户号 */
	BCESFieldTypePoints ErrNetTradeSec;	/* 网络故障成交延迟 */
	BCESFieldTypePoints ErrNetRemindSec;	/* 网络故障提醒延迟 */
	BCESFieldTypeRspDesc ErrNetRemindTxt;	/* 网络故障提醒信息 */
	BCESFieldTypePoints ErrSeverTradePort;	/* 服务器故障成交点差 */
	BCESFieldTypePoints ErrSeverRemindPort;	/* 服务器故障提醒点差 */
	BCESFieldTypeRspDesc ErrSeverRemindTxt;	/* 服务器故障提醒信息 */
};

/* 测试设置修改应答 */
class CBCESFieldsTestSettingsModifyRsp:public CBMLFields
{
public:
	CBCESFieldsTestSettingsModifyRsp()
	{
		m_fieldarray=m_fieldarray_TestSettingsModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_TestSettingsModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTestSettingsModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)UserID,sizeof(UserID),NULL,0,bces_rulearray+BCESFieldIndexUserID);	/* 用户号 */
	}
	CBCESFieldsTestSettingsModifyRsp(const CBCESFieldsTestSettingsModifyRsp& TestSettingsModifyRsp){
		m_fieldarray=m_fieldarray_TestSettingsModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_TestSettingsModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TestSettingsModifyRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTestSettingsModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)UserID,sizeof(UserID),NULL,0,bces_rulearray+BCESFieldIndexUserID);	/* 用户号 */
	}
	CBCESFieldsTestSettingsModifyRsp& operator=(const CBCESFieldsTestSettingsModifyRsp& TestSettingsModifyRsp){
		m_fieldarray=m_fieldarray_TestSettingsModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_TestSettingsModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TestSettingsModifyRsp+sizeof(CBMLFields),sizeof(CBCESFieldsTestSettingsModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)UserID,sizeof(UserID),NULL,0,bces_rulearray+BCESFieldIndexUserID);	/* 用户号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TestSettingsModifyRsp),0x00,sizeof(CBCESFieldsTestSettingsModifyRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_TestSettingsModifyRsp));
	}

	BML_FIELD_INFO m_fieldarray_TestSettingsModifyRsp[1];

	// Field
	BCESFieldTypeUserID UserID;	/* 用户号 */
};

/* 挂单量排名查询请求 */
class CBCESFieldsTopInvestorQueryReq:public CBMLFields
{
public:
	CBCESFieldsTopInvestorQueryReq()
	{
		m_fieldarray=m_fieldarray_TopInvestorQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TopInvestorQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTopInvestorQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsTopInvestorQueryReq(const CBCESFieldsTopInvestorQueryReq& TopInvestorQueryReq){
		m_fieldarray=m_fieldarray_TopInvestorQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TopInvestorQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TopInvestorQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTopInvestorQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
	}
	CBCESFieldsTopInvestorQueryReq& operator=(const CBCESFieldsTopInvestorQueryReq& TopInvestorQueryReq){
		m_fieldarray=m_fieldarray_TopInvestorQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TopInvestorQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TopInvestorQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTopInvestorQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TopInvestorQueryReq),0x00,sizeof(CBCESFieldsTopInvestorQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TopInvestorQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_TopInvestorQueryReq[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
};

/* 挂单量排名 */
class CBCESFieldsTopInvestor:public CBMLFields
{
public:
	CBCESFieldsTopInvestor()
	{
		m_fieldarray=m_fieldarray_TopInvestor;
		m_fieldsize=sizeof(m_fieldarray_TopInvestor)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTopInvestor)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 挂单量 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
	}
	CBCESFieldsTopInvestor(const CBCESFieldsTopInvestor& TopInvestor){
		m_fieldarray=m_fieldarray_TopInvestor;
		m_fieldsize=sizeof(m_fieldarray_TopInvestor)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TopInvestor+sizeof(CBMLFields),sizeof(CBCESFieldsTopInvestor)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 挂单量 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
	}
	CBCESFieldsTopInvestor& operator=(const CBCESFieldsTopInvestor& TopInvestor){
		m_fieldarray=m_fieldarray_TopInvestor;
		m_fieldsize=sizeof(m_fieldarray_TopInvestor)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TopInvestor+sizeof(CBMLFields),sizeof(CBCESFieldsTopInvestor)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 挂单量 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TopInvestor),0x00,sizeof(CBCESFieldsTopInvestor)-sizeof(CBMLFields)-sizeof(m_fieldarray_TopInvestor));
	}

	BML_FIELD_INFO m_fieldarray_TopInvestor[5];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeQty Qty;	/* 挂单量 */
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};

/* 投资者挂单查询请求 */
class CBCESFieldsInvestorQuotQueryReq:public CBMLFields
{
public:
	CBCESFieldsInvestorQuotQueryReq()
	{
		m_fieldarray=m_fieldarray_InvestorQuotQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InvestorQuotQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInvestorQuotQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)RankingInvestorID,sizeof(RankingInvestorID),NULL,0,bces_rulearray+BCESFieldIndexRankingInvestorID);	/* 排名投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsInvestorQuotQueryReq(const CBCESFieldsInvestorQuotQueryReq& InvestorQuotQueryReq){
		m_fieldarray=m_fieldarray_InvestorQuotQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InvestorQuotQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorQuotQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorQuotQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)RankingInvestorID,sizeof(RankingInvestorID),NULL,0,bces_rulearray+BCESFieldIndexRankingInvestorID);	/* 排名投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsInvestorQuotQueryReq& operator=(const CBCESFieldsInvestorQuotQueryReq& InvestorQuotQueryReq){
		m_fieldarray=m_fieldarray_InvestorQuotQueryReq;
		m_fieldsize=sizeof(m_fieldarray_InvestorQuotQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorQuotQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorQuotQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)RankingInvestorID,sizeof(RankingInvestorID),NULL,0,bces_rulearray+BCESFieldIndexRankingInvestorID);	/* 排名投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InvestorQuotQueryReq),0x00,sizeof(CBCESFieldsInvestorQuotQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_InvestorQuotQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_InvestorQuotQueryReq[4];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeInvestorID RankingInvestorID;	/* 排名投资者号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 投资者挂单 */
class CBCESFieldsInvestorQuot:public CBMLFields
{
public:
	CBCESFieldsInvestorQuot()
	{
		m_fieldarray=m_fieldarray_InvestorQuot;
		m_fieldsize=sizeof(m_fieldarray_InvestorQuot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInvestorQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 挂单量 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
	}
	CBCESFieldsInvestorQuot(const CBCESFieldsInvestorQuot& InvestorQuot){
		m_fieldarray=m_fieldarray_InvestorQuot;
		m_fieldsize=sizeof(m_fieldarray_InvestorQuot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorQuot+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 挂单量 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
	}
	CBCESFieldsInvestorQuot& operator=(const CBCESFieldsInvestorQuot& InvestorQuot){
		m_fieldarray=m_fieldarray_InvestorQuot;
		m_fieldsize=sizeof(m_fieldarray_InvestorQuot)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&InvestorQuot+sizeof(CBMLFields),sizeof(CBCESFieldsInvestorQuot)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 挂单量 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&RankingNum,sizeof(RankingNum),NULL,0,bces_rulearray+BCESFieldIndexRankingNum);	/* 排名 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_InvestorQuot),0x00,sizeof(CBCESFieldsInvestorQuot)-sizeof(CBMLFields)-sizeof(m_fieldarray_InvestorQuot));
	}

	BML_FIELD_INFO m_fieldarray_InvestorQuot[6];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeQty Qty;	/* 挂单量 */
	BCESFieldTypePrice Price;	/* 价格 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeRankingNum RankingNum;	/* 排名 */
};

/* 交易时间 */
class CBCESFieldsTradeTime:public CBMLFields
{
public:
	CBCESFieldsTradeTime()
	{
		m_fieldarray=m_fieldarray_TradeTime;
		m_fieldsize=sizeof(m_fieldarray_TradeTime)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTradeTime)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TimeBegin,sizeof(TimeBegin),NULL,0,bces_rulearray+BCESFieldIndexTimeBegin);	/* 开始时间 */
		AddField((void*)TimeEnd,sizeof(TimeEnd),NULL,0,bces_rulearray+BCESFieldIndexTimeEnd);	/* 结束时间 */
		AddField((void*)&MarketStatus,sizeof(MarketStatus),NULL,0,bces_rulearray+BCESFieldIndexMarketStatus);	/* 市场状态 */
	}
	CBCESFieldsTradeTime(const CBCESFieldsTradeTime& TradeTime){
		m_fieldarray=m_fieldarray_TradeTime;
		m_fieldsize=sizeof(m_fieldarray_TradeTime)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeTime+sizeof(CBMLFields),sizeof(CBCESFieldsTradeTime)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TimeBegin,sizeof(TimeBegin),NULL,0,bces_rulearray+BCESFieldIndexTimeBegin);	/* 开始时间 */
		AddField((void*)TimeEnd,sizeof(TimeEnd),NULL,0,bces_rulearray+BCESFieldIndexTimeEnd);	/* 结束时间 */
		AddField((void*)&MarketStatus,sizeof(MarketStatus),NULL,0,bces_rulearray+BCESFieldIndexMarketStatus);	/* 市场状态 */
	}
	CBCESFieldsTradeTime& operator=(const CBCESFieldsTradeTime& TradeTime){
		m_fieldarray=m_fieldarray_TradeTime;
		m_fieldsize=sizeof(m_fieldarray_TradeTime)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TradeTime+sizeof(CBMLFields),sizeof(CBCESFieldsTradeTime)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)TimeBegin,sizeof(TimeBegin),NULL,0,bces_rulearray+BCESFieldIndexTimeBegin);	/* 开始时间 */
		AddField((void*)TimeEnd,sizeof(TimeEnd),NULL,0,bces_rulearray+BCESFieldIndexTimeEnd);	/* 结束时间 */
		AddField((void*)&MarketStatus,sizeof(MarketStatus),NULL,0,bces_rulearray+BCESFieldIndexMarketStatus);	/* 市场状态 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TradeTime),0x00,sizeof(CBCESFieldsTradeTime)-sizeof(CBMLFields)-sizeof(m_fieldarray_TradeTime));
	}

	BML_FIELD_INFO m_fieldarray_TradeTime[3];

	// Field
	BCESFieldTypeTime TimeBegin;	/* 开始时间 */
	BCESFieldTypeTime TimeEnd;	/* 结束时间 */
	BCESFieldTypeFlag MarketStatus;	/* 市场状态 */
};

/* 交收交割申请 */
class CBCESFieldsDeliveryApply:public CBMLFields
{
public:
	CBCESFieldsDeliveryApply()
	{
		m_fieldarray=m_fieldarray_DeliveryApply;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApply)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApply)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsDeliveryApply(const CBCESFieldsDeliveryApply& DeliveryApply){
		m_fieldarray=m_fieldarray_DeliveryApply;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApply)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApply+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApply)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsDeliveryApply& operator=(const CBCESFieldsDeliveryApply& DeliveryApply){
		m_fieldarray=m_fieldarray_DeliveryApply;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApply)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApply+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApply)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApply),0x00,sizeof(CBCESFieldsDeliveryApply)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApply));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApply[24];

	// Field
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
class CBCESFieldsDeliveryApplyQueryReq:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyQueryReq()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyQueryReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
	}
	CBCESFieldsDeliveryApplyQueryReq(const CBCESFieldsDeliveryApplyQueryReq& DeliveryApplyQueryReq){
		m_fieldarray=m_fieldarray_DeliveryApplyQueryReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
	}
	CBCESFieldsDeliveryApplyQueryReq& operator=(const CBCESFieldsDeliveryApplyQueryReq& DeliveryApplyQueryReq){
		m_fieldarray=m_fieldarray_DeliveryApplyQueryReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyQueryReq),0x00,sizeof(CBCESFieldsDeliveryApplyQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyQueryReq[6];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
	BCESFieldTypeFlag DeliveryStatus;	/* 交收交割状态 */
};

/* 交收交割申请增加请求 */
class CBCESFieldsDeliveryApplyAddReq:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyAddReq()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyAddReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyAddReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyAddReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsDeliveryApplyAddReq(const CBCESFieldsDeliveryApplyAddReq& DeliveryApplyAddReq){
		m_fieldarray=m_fieldarray_DeliveryApplyAddReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyAddReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyAddReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyAddReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsDeliveryApplyAddReq& operator=(const CBCESFieldsDeliveryApplyAddReq& DeliveryApplyAddReq){
		m_fieldarray=m_fieldarray_DeliveryApplyAddReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyAddReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyAddReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyAddReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyAddReq),0x00,sizeof(CBCESFieldsDeliveryApplyAddReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyAddReq));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyAddReq[23];

	// Field
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
class CBCESFieldsDeliveryApplyAddRsp:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyAddRsp()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyAddRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyAddRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyAddRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
	}
	CBCESFieldsDeliveryApplyAddRsp(const CBCESFieldsDeliveryApplyAddRsp& DeliveryApplyAddRsp){
		m_fieldarray=m_fieldarray_DeliveryApplyAddRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyAddRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyAddRsp+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyAddRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
	}
	CBCESFieldsDeliveryApplyAddRsp& operator=(const CBCESFieldsDeliveryApplyAddRsp& DeliveryApplyAddRsp){
		m_fieldarray=m_fieldarray_DeliveryApplyAddRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyAddRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyAddRsp+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyAddRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyAddRsp),0x00,sizeof(CBCESFieldsDeliveryApplyAddRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyAddRsp));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyAddRsp[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
};

/* 交收交割申请修改请求 */
class CBCESFieldsDeliveryApplyModifyReq:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyModifyReq()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyModifyReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsDeliveryApplyModifyReq(const CBCESFieldsDeliveryApplyModifyReq& DeliveryApplyModifyReq){
		m_fieldarray=m_fieldarray_DeliveryApplyModifyReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyModifyReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsDeliveryApplyModifyReq& operator=(const CBCESFieldsDeliveryApplyModifyReq& DeliveryApplyModifyReq){
		m_fieldarray=m_fieldarray_DeliveryApplyModifyReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyModifyReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyModifyReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyModifyReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DeliveryAddress,sizeof(DeliveryAddress),NULL,0,bces_rulearray+BCESFieldIndexDeliveryAddress);	/* 交收交割地址 */
		AddField((void*)LiaisonName,sizeof(LiaisonName),NULL,0,bces_rulearray+BCESFieldIndexLiaisonName);	/* 联系人名称 */
		AddField((void*)LiaisonNumber,sizeof(LiaisonNumber),NULL,0,bces_rulearray+BCESFieldIndexLiaisonNumber);	/* 联系电话 */
		AddField((void*)&CredentialType,sizeof(CredentialType),NULL,0,bces_rulearray+BCESFieldIndexCredentialType);	/* 证件类型 */
		AddField((void*)CredentialNo,sizeof(CredentialNo),NULL,0,bces_rulearray+BCESFieldIndexCredentialNo);	/* 证件号 */
		AddField((void*)LiaisonAddress,sizeof(LiaisonAddress),NULL,0,bces_rulearray+BCESFieldIndexLiaisonAddress);	/* 联系地址 */
		AddField((void*)PostCode,sizeof(PostCode),NULL,0,bces_rulearray+BCESFieldIndexPostCode);	/* 邮编 */
		AddField((void*)CompanyName,sizeof(CompanyName),NULL,0,bces_rulearray+BCESFieldIndexCompanyName);	/* 企业名称 */
		AddField((void*)CompanyAddress,sizeof(CompanyAddress),NULL,0,bces_rulearray+BCESFieldIndexCompanyAddress);	/* 公司地址 */
		AddField((void*)CompanyNumber,sizeof(CompanyNumber),NULL,0,bces_rulearray+BCESFieldIndexCompanyNumber);	/* 公司电话 */
		AddField((void*)BankNameAccountID,sizeof(BankNameAccountID),NULL,0,bces_rulearray+BCESFieldIndexBankNameAccountID);	/* 银行名称及账号 */
		AddField((void*)TaxNo,sizeof(TaxNo),NULL,0,bces_rulearray+BCESFieldIndexTaxNo);	/* 税务登记号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		AddField((void*)&DeliveryStatus,sizeof(DeliveryStatus),NULL,0,bces_rulearray+BCESFieldIndexDeliveryStatus);	/* 交收交割状态 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 价格 */
		AddField((void*)&Qty,sizeof(Qty),NULL,0,bces_rulearray+BCESFieldIndexQty);	/* 数量 */
		AddField((void*)ApplyDate,sizeof(ApplyDate),NULL,0,bces_rulearray+BCESFieldIndexApplyDate);	/* 申请日期 */
		AddField((void*)&InvoiceFlag,sizeof(InvoiceFlag),NULL,0,bces_rulearray+BCESFieldIndexInvoiceFlag);	/* 发票标识 */
		AddField((void*)&InvoiceType,sizeof(InvoiceType),NULL,0,bces_rulearray+BCESFieldIndexInvoiceType);	/* 发票类型 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyModifyReq),0x00,sizeof(CBCESFieldsDeliveryApplyModifyReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyModifyReq));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyModifyReq[24];

	// Field
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
class CBCESFieldsDeliveryApplyModifyRsp:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyModifyRsp()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsDeliveryApplyModifyRsp(const CBCESFieldsDeliveryApplyModifyRsp& DeliveryApplyModifyRsp){
		m_fieldarray=m_fieldarray_DeliveryApplyModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyModifyRsp+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsDeliveryApplyModifyRsp& operator=(const CBCESFieldsDeliveryApplyModifyRsp& DeliveryApplyModifyRsp){
		m_fieldarray=m_fieldarray_DeliveryApplyModifyRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyModifyRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyModifyRsp+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyModifyRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyModifyRsp),0x00,sizeof(CBCESFieldsDeliveryApplyModifyRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyModifyRsp));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyModifyRsp[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 交收交割申请删除请求 */
class CBCESFieldsDeliveryApplyDeleteReq:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyDeleteReq()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyDeleteReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyDeleteReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyDeleteReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
	}
	CBCESFieldsDeliveryApplyDeleteReq(const CBCESFieldsDeliveryApplyDeleteReq& DeliveryApplyDeleteReq){
		m_fieldarray=m_fieldarray_DeliveryApplyDeleteReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyDeleteReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyDeleteReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyDeleteReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
	}
	CBCESFieldsDeliveryApplyDeleteReq& operator=(const CBCESFieldsDeliveryApplyDeleteReq& DeliveryApplyDeleteReq){
		m_fieldarray=m_fieldarray_DeliveryApplyDeleteReq;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyDeleteReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyDeleteReq+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyDeleteReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)DeliveryApplyID,sizeof(DeliveryApplyID),NULL,0,bces_rulearray+BCESFieldIndexDeliveryApplyID);	/* 交收交割申请编号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyDeleteReq),0x00,sizeof(CBCESFieldsDeliveryApplyDeleteReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyDeleteReq));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyDeleteReq[1];

	// Field
	BCESFieldTypeDeliveryID DeliveryApplyID;	/* 交收交割申请编号 */
};

/* 交收交割申请删除应答 */
class CBCESFieldsDeliveryApplyDeleteRsp:public CBMLFields
{
public:
	CBCESFieldsDeliveryApplyDeleteRsp()
	{
		m_fieldarray=m_fieldarray_DeliveryApplyDeleteRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyDeleteRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsDeliveryApplyDeleteRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsDeliveryApplyDeleteRsp(const CBCESFieldsDeliveryApplyDeleteRsp& DeliveryApplyDeleteRsp){
		m_fieldarray=m_fieldarray_DeliveryApplyDeleteRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyDeleteRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyDeleteRsp+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyDeleteRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
	}
	CBCESFieldsDeliveryApplyDeleteRsp& operator=(const CBCESFieldsDeliveryApplyDeleteRsp& DeliveryApplyDeleteRsp){
		m_fieldarray=m_fieldarray_DeliveryApplyDeleteRsp;
		m_fieldsize=sizeof(m_fieldarray_DeliveryApplyDeleteRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&DeliveryApplyDeleteRsp+sizeof(CBMLFields),sizeof(CBCESFieldsDeliveryApplyDeleteRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)&BSFlag,sizeof(BSFlag),NULL,0,bces_rulearray+BCESFieldIndexBSFlag);	/* 买卖标志 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_DeliveryApplyDeleteRsp),0x00,sizeof(CBCESFieldsDeliveryApplyDeleteRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_DeliveryApplyDeleteRsp));
	}

	BML_FIELD_INFO m_fieldarray_DeliveryApplyDeleteRsp[2];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeFlag BSFlag;	/* 买卖标志 */
};

/* 行情顾问提问/回答请求 */
class CBCESFieldsQuotAdviserQuesAnswReq:public CBMLFields
{
public:
	CBCESFieldsQuotAdviserQuesAnswReq()
	{
		m_fieldarray=m_fieldarray_QuotAdviserQuesAnswReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesAnswReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotAdviserQuesAnswReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&QuesAnswFlag,sizeof(QuesAnswFlag),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswFlag);	/* 提问回答标志 */
		AddField((void*)QuesAnswContent,sizeof(QuesAnswContent),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswContent);	/* 提问/回答内容 */
		AddField((void*)QuesAnswDate,sizeof(QuesAnswDate),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswDate);	/* 提问/回答日期 */
		AddField((void*)QuesAnswTime,sizeof(QuesAnswTime),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswTime);	/* 提问/回答时间 */
	}
	CBCESFieldsQuotAdviserQuesAnswReq(const CBCESFieldsQuotAdviserQuesAnswReq& QuotAdviserQuesAnswReq){
		m_fieldarray=m_fieldarray_QuotAdviserQuesAnswReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesAnswReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesAnswReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesAnswReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&QuesAnswFlag,sizeof(QuesAnswFlag),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswFlag);	/* 提问回答标志 */
		AddField((void*)QuesAnswContent,sizeof(QuesAnswContent),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswContent);	/* 提问/回答内容 */
		AddField((void*)QuesAnswDate,sizeof(QuesAnswDate),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswDate);	/* 提问/回答日期 */
		AddField((void*)QuesAnswTime,sizeof(QuesAnswTime),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswTime);	/* 提问/回答时间 */
	}
	CBCESFieldsQuotAdviserQuesAnswReq& operator=(const CBCESFieldsQuotAdviserQuesAnswReq& QuotAdviserQuesAnswReq){
		m_fieldarray=m_fieldarray_QuotAdviserQuesAnswReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesAnswReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesAnswReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesAnswReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&QuesAnswFlag,sizeof(QuesAnswFlag),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswFlag);	/* 提问回答标志 */
		AddField((void*)QuesAnswContent,sizeof(QuesAnswContent),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswContent);	/* 提问/回答内容 */
		AddField((void*)QuesAnswDate,sizeof(QuesAnswDate),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswDate);	/* 提问/回答日期 */
		AddField((void*)QuesAnswTime,sizeof(QuesAnswTime),NULL,0,bces_rulearray+BCESFieldIndexQuesAnswTime);	/* 提问/回答时间 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotAdviserQuesAnswReq),0x00,sizeof(CBCESFieldsQuotAdviserQuesAnswReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotAdviserQuesAnswReq));
	}

	BML_FIELD_INFO m_fieldarray_QuotAdviserQuesAnswReq[7];

	// Field
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeFlag QuesAnswFlag;	/* 提问回答标志 */
	BCESFieldTypeQuesAnswContent QuesAnswContent;	/* 提问/回答内容 */
	BCESFieldTypeDate QuesAnswDate;	/* 提问/回答日期 */
	BCESFieldTypeTime QuesAnswTime;	/* 提问/回答时间 */
};

/* 行情顾问提问/回答应答 */
class CBCESFieldsQuotAdviserQuesAnswRsp:public CBMLFields
{
public:
	CBCESFieldsQuotAdviserQuesAnswRsp()
	{
		m_fieldarray=m_fieldarray_QuotAdviserQuesAnswRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesAnswRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotAdviserQuesAnswRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
	}
	CBCESFieldsQuotAdviserQuesAnswRsp(const CBCESFieldsQuotAdviserQuesAnswRsp& QuotAdviserQuesAnswRsp){
		m_fieldarray=m_fieldarray_QuotAdviserQuesAnswRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesAnswRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesAnswRsp+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesAnswRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
	}
	CBCESFieldsQuotAdviserQuesAnswRsp& operator=(const CBCESFieldsQuotAdviserQuesAnswRsp& QuotAdviserQuesAnswRsp){
		m_fieldarray=m_fieldarray_QuotAdviserQuesAnswRsp;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesAnswRsp)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesAnswRsp+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesAnswRsp)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotAdviserQuesAnswRsp),0x00,sizeof(CBCESFieldsQuotAdviserQuesAnswRsp)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotAdviserQuesAnswRsp));
	}

	BML_FIELD_INFO m_fieldarray_QuotAdviserQuesAnswRsp[3];

	// Field
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
};

/* 行情顾问提问查询请求 */
class CBCESFieldsQuotAdviserQuesQueryReq:public CBMLFields
{
public:
	CBCESFieldsQuotAdviserQuesQueryReq()
	{
		m_fieldarray=m_fieldarray_QuotAdviserQuesQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotAdviserQuesQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&InvestorAdviserFlag,sizeof(InvestorAdviserFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorAdviserFlag);	/* 投资者顾问标志 */
	}
	CBCESFieldsQuotAdviserQuesQueryReq(const CBCESFieldsQuotAdviserQuesQueryReq& QuotAdviserQuesQueryReq){
		m_fieldarray=m_fieldarray_QuotAdviserQuesQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&InvestorAdviserFlag,sizeof(InvestorAdviserFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorAdviserFlag);	/* 投资者顾问标志 */
	}
	CBCESFieldsQuotAdviserQuesQueryReq& operator=(const CBCESFieldsQuotAdviserQuesQueryReq& QuotAdviserQuesQueryReq){
		m_fieldarray=m_fieldarray_QuotAdviserQuesQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)&InvestorAdviserFlag,sizeof(InvestorAdviserFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorAdviserFlag);	/* 投资者顾问标志 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotAdviserQuesQueryReq),0x00,sizeof(CBCESFieldsQuotAdviserQuesQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotAdviserQuesQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_QuotAdviserQuesQueryReq[4];

	// Field
	BCESFieldTypeQuestionID QuestionID;	/* 提问编号 */
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeAdviserID AdviserID;	/* 顾问号 */
	BCESFieldTypeFlag InvestorAdviserFlag;	/* 投资者顾问标志 */
};

/* 行情顾问提问查询应答 */
class CBCESFieldsQuotAdviserQuesQuery:public CBMLFields
{
public:
	CBCESFieldsQuotAdviserQuesQuery()
	{
		m_fieldarray=m_fieldarray_QuotAdviserQuesQuery;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesQuery)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotAdviserQuesQuery)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)QuestionContent,sizeof(QuestionContent),NULL,0,bces_rulearray+BCESFieldIndexQuestionContent);	/* 提问内容 */
		AddField((void*)QuestionDate,sizeof(QuestionDate),NULL,0,bces_rulearray+BCESFieldIndexQuestionDate);	/* 提问日期 */
		AddField((void*)QuestionTime,sizeof(QuestionTime),NULL,0,bces_rulearray+BCESFieldIndexQuestionTime);	/* 提问时间 */
		AddField((void*)AnswerContent,sizeof(AnswerContent),NULL,0,bces_rulearray+BCESFieldIndexAnswerContent);	/* 回答内容 */
		AddField((void*)AnswerDate,sizeof(AnswerDate),NULL,0,bces_rulearray+BCESFieldIndexAnswerDate);	/* 回答日期 */
		AddField((void*)AnswerTime,sizeof(AnswerTime),NULL,0,bces_rulearray+BCESFieldIndexAnswerTime);	/* 回答时间 */
	}
	CBCESFieldsQuotAdviserQuesQuery(const CBCESFieldsQuotAdviserQuesQuery& QuotAdviserQuesQuery){
		m_fieldarray=m_fieldarray_QuotAdviserQuesQuery;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesQuery)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesQuery+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesQuery)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)QuestionContent,sizeof(QuestionContent),NULL,0,bces_rulearray+BCESFieldIndexQuestionContent);	/* 提问内容 */
		AddField((void*)QuestionDate,sizeof(QuestionDate),NULL,0,bces_rulearray+BCESFieldIndexQuestionDate);	/* 提问日期 */
		AddField((void*)QuestionTime,sizeof(QuestionTime),NULL,0,bces_rulearray+BCESFieldIndexQuestionTime);	/* 提问时间 */
		AddField((void*)AnswerContent,sizeof(AnswerContent),NULL,0,bces_rulearray+BCESFieldIndexAnswerContent);	/* 回答内容 */
		AddField((void*)AnswerDate,sizeof(AnswerDate),NULL,0,bces_rulearray+BCESFieldIndexAnswerDate);	/* 回答日期 */
		AddField((void*)AnswerTime,sizeof(AnswerTime),NULL,0,bces_rulearray+BCESFieldIndexAnswerTime);	/* 回答时间 */
	}
	CBCESFieldsQuotAdviserQuesQuery& operator=(const CBCESFieldsQuotAdviserQuesQuery& QuotAdviserQuesQuery){
		m_fieldarray=m_fieldarray_QuotAdviserQuesQuery;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesQuery)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesQuery+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesQuery)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)QuestionContent,sizeof(QuestionContent),NULL,0,bces_rulearray+BCESFieldIndexQuestionContent);	/* 提问内容 */
		AddField((void*)QuestionDate,sizeof(QuestionDate),NULL,0,bces_rulearray+BCESFieldIndexQuestionDate);	/* 提问日期 */
		AddField((void*)QuestionTime,sizeof(QuestionTime),NULL,0,bces_rulearray+BCESFieldIndexQuestionTime);	/* 提问时间 */
		AddField((void*)AnswerContent,sizeof(AnswerContent),NULL,0,bces_rulearray+BCESFieldIndexAnswerContent);	/* 回答内容 */
		AddField((void*)AnswerDate,sizeof(AnswerDate),NULL,0,bces_rulearray+BCESFieldIndexAnswerDate);	/* 回答日期 */
		AddField((void*)AnswerTime,sizeof(AnswerTime),NULL,0,bces_rulearray+BCESFieldIndexAnswerTime);	/* 回答时间 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotAdviserQuesQuery),0x00,sizeof(CBCESFieldsQuotAdviserQuesQuery)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotAdviserQuesQuery));
	}

	BML_FIELD_INFO m_fieldarray_QuotAdviserQuesQuery[9];

	// Field
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
class CBCESFieldsQuotAdviserQuesHisQueryReq:public CBMLFields
{
public:
	CBCESFieldsQuotAdviserQuesHisQueryReq()
	{
		m_fieldarray=m_fieldarray_QuotAdviserQuesHisQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesHisQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotAdviserQuesHisQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsQuotAdviserQuesHisQueryReq(const CBCESFieldsQuotAdviserQuesHisQueryReq& QuotAdviserQuesHisQueryReq){
		m_fieldarray=m_fieldarray_QuotAdviserQuesHisQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesHisQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesHisQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesHisQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
	}
	CBCESFieldsQuotAdviserQuesHisQueryReq& operator=(const CBCESFieldsQuotAdviserQuesHisQueryReq& QuotAdviserQuesHisQueryReq){
		m_fieldarray=m_fieldarray_QuotAdviserQuesHisQueryReq;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesHisQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesHisQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesHisQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)DateFrom,sizeof(DateFrom),NULL,0,bces_rulearray+BCESFieldIndexDateFrom);	/* 起始日期 */
		AddField((void*)DateTo,sizeof(DateTo),NULL,0,bces_rulearray+BCESFieldIndexDateTo);	/* 结束日期 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotAdviserQuesHisQueryReq),0x00,sizeof(CBCESFieldsQuotAdviserQuesHisQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotAdviserQuesHisQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_QuotAdviserQuesHisQueryReq[3];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypeDate DateFrom;	/* 起始日期 */
	BCESFieldTypeDate DateTo;	/* 结束日期 */
};

/* 行情顾问提问历史查询应答 */
class CBCESFieldsQuotAdviserQuesHis:public CBMLFields
{
public:
	CBCESFieldsQuotAdviserQuesHis()
	{
		m_fieldarray=m_fieldarray_QuotAdviserQuesHis;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesHis)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsQuotAdviserQuesHis)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)QuestionContent,sizeof(QuestionContent),NULL,0,bces_rulearray+BCESFieldIndexQuestionContent);	/* 提问内容 */
		AddField((void*)QuestionDate,sizeof(QuestionDate),NULL,0,bces_rulearray+BCESFieldIndexQuestionDate);	/* 提问日期 */
		AddField((void*)QuestionTime,sizeof(QuestionTime),NULL,0,bces_rulearray+BCESFieldIndexQuestionTime);	/* 提问时间 */
		AddField((void*)AnswerContent,sizeof(AnswerContent),NULL,0,bces_rulearray+BCESFieldIndexAnswerContent);	/* 回答内容 */
		AddField((void*)AnswerDate,sizeof(AnswerDate),NULL,0,bces_rulearray+BCESFieldIndexAnswerDate);	/* 回答日期 */
		AddField((void*)AnswerTime,sizeof(AnswerTime),NULL,0,bces_rulearray+BCESFieldIndexAnswerTime);	/* 回答时间 */
	}
	CBCESFieldsQuotAdviserQuesHis(const CBCESFieldsQuotAdviserQuesHis& QuotAdviserQuesHis){
		m_fieldarray=m_fieldarray_QuotAdviserQuesHis;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesHis)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesHis+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesHis)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)QuestionContent,sizeof(QuestionContent),NULL,0,bces_rulearray+BCESFieldIndexQuestionContent);	/* 提问内容 */
		AddField((void*)QuestionDate,sizeof(QuestionDate),NULL,0,bces_rulearray+BCESFieldIndexQuestionDate);	/* 提问日期 */
		AddField((void*)QuestionTime,sizeof(QuestionTime),NULL,0,bces_rulearray+BCESFieldIndexQuestionTime);	/* 提问时间 */
		AddField((void*)AnswerContent,sizeof(AnswerContent),NULL,0,bces_rulearray+BCESFieldIndexAnswerContent);	/* 回答内容 */
		AddField((void*)AnswerDate,sizeof(AnswerDate),NULL,0,bces_rulearray+BCESFieldIndexAnswerDate);	/* 回答日期 */
		AddField((void*)AnswerTime,sizeof(AnswerTime),NULL,0,bces_rulearray+BCESFieldIndexAnswerTime);	/* 回答时间 */
	}
	CBCESFieldsQuotAdviserQuesHis& operator=(const CBCESFieldsQuotAdviserQuesHis& QuotAdviserQuesHis){
		m_fieldarray=m_fieldarray_QuotAdviserQuesHis;
		m_fieldsize=sizeof(m_fieldarray_QuotAdviserQuesHis)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&QuotAdviserQuesHis+sizeof(CBMLFields),sizeof(CBCESFieldsQuotAdviserQuesHis)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)QuestionID,sizeof(QuestionID),NULL,0,bces_rulearray+BCESFieldIndexQuestionID);	/* 提问编号 */
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)AdviserID,sizeof(AdviserID),NULL,0,bces_rulearray+BCESFieldIndexAdviserID);	/* 顾问号 */
		AddField((void*)QuestionContent,sizeof(QuestionContent),NULL,0,bces_rulearray+BCESFieldIndexQuestionContent);	/* 提问内容 */
		AddField((void*)QuestionDate,sizeof(QuestionDate),NULL,0,bces_rulearray+BCESFieldIndexQuestionDate);	/* 提问日期 */
		AddField((void*)QuestionTime,sizeof(QuestionTime),NULL,0,bces_rulearray+BCESFieldIndexQuestionTime);	/* 提问时间 */
		AddField((void*)AnswerContent,sizeof(AnswerContent),NULL,0,bces_rulearray+BCESFieldIndexAnswerContent);	/* 回答内容 */
		AddField((void*)AnswerDate,sizeof(AnswerDate),NULL,0,bces_rulearray+BCESFieldIndexAnswerDate);	/* 回答日期 */
		AddField((void*)AnswerTime,sizeof(AnswerTime),NULL,0,bces_rulearray+BCESFieldIndexAnswerTime);	/* 回答时间 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_QuotAdviserQuesHis),0x00,sizeof(CBCESFieldsQuotAdviserQuesHis)-sizeof(CBMLFields)-sizeof(m_fieldarray_QuotAdviserQuesHis));
	}

	BML_FIELD_INFO m_fieldarray_QuotAdviserQuesHis[9];

	// Field
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
class CBCESFieldsInvestor:public CBMLFields
{
public:
	CBCESFieldsInvestor()
	{
		m_fieldarray=m_fieldarray_Investor;
		m_fieldsize=sizeof(m_fieldarray_Investor)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsInvestor)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorPassword,sizeof(InvestorPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorPassword);	/* 收款户名 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)&InvestorFlag,sizeof(InvestorFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorFlag);	/* 投资者标志 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 报单账号 */
	}
	CBCESFieldsInvestor(const CBCESFieldsInvestor& Investor){
		m_fieldarray=m_fieldarray_Investor;
		m_fieldsize=sizeof(m_fieldarray_Investor)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Investor+sizeof(CBMLFields),sizeof(CBCESFieldsInvestor)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorPassword,sizeof(InvestorPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorPassword);	/* 收款户名 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)&InvestorFlag,sizeof(InvestorFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorFlag);	/* 投资者标志 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 报单账号 */
	}
	CBCESFieldsInvestor& operator=(const CBCESFieldsInvestor& Investor){
		m_fieldarray=m_fieldarray_Investor;
		m_fieldsize=sizeof(m_fieldarray_Investor)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&Investor+sizeof(CBMLFields),sizeof(CBCESFieldsInvestor)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InvestorID,sizeof(InvestorID),NULL,0,bces_rulearray+BCESFieldIndexInvestorID);	/* 投资者号 */
		AddField((void*)InvestorPassword,sizeof(InvestorPassword),NULL,0,bces_rulearray+BCESFieldIndexInvestorPassword);	/* 收款户名 */
		AddField((void*)InvestorName,sizeof(InvestorName),NULL,0,bces_rulearray+BCESFieldIndexInvestorName);	/* 投资者名称 */
		AddField((void*)&InvestorFlag,sizeof(InvestorFlag),NULL,0,bces_rulearray+BCESFieldIndexInvestorFlag);	/* 投资者标志 */
		AddField((void*)AccountID,sizeof(AccountID),NULL,0,bces_rulearray+BCESFieldIndexAccountID);	/* 报单账号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_Investor),0x00,sizeof(CBCESFieldsInvestor)-sizeof(CBMLFields)-sizeof(m_fieldarray_Investor));
	}

	BML_FIELD_INFO m_fieldarray_Investor[5];

	// Field
	BCESFieldTypeInvestorID InvestorID;	/* 投资者号 */
	BCESFieldTypePassword InvestorPassword;	/* 收款户名 */
	BCESFieldTypeName InvestorName;	/* 投资者名称 */
	BCESFieldTypeFlag InvestorFlag;	/* 投资者标志 */
	BCESFieldTypeAccountID AccountID;	/* 报单账号 */
};

/* K线查询请求 */
class CBCESFieldsKLineQueryReq:public CBMLFields
{
public:
	CBCESFieldsKLineQueryReq()
	{
		m_fieldarray=m_fieldarray_KLineQueryReq;
		m_fieldsize=sizeof(m_fieldarray_KLineQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsKLineQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&KLineType,sizeof(KLineType),NULL,0,bces_rulearray+BCESFieldIndexKLineType);	/* K线类型 */
		AddField((void*)&BarFrom,sizeof(BarFrom),NULL,0,bces_rulearray+BCESFieldIndexBarFrom);	/* 起始Bar */
		AddField((void*)&BarCount,sizeof(BarCount),NULL,0,bces_rulearray+BCESFieldIndexBarCount);	/* Bar数量 */
	}
	CBCESFieldsKLineQueryReq(const CBCESFieldsKLineQueryReq& KLineQueryReq){
		m_fieldarray=m_fieldarray_KLineQueryReq;
		m_fieldsize=sizeof(m_fieldarray_KLineQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&KLineQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsKLineQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&KLineType,sizeof(KLineType),NULL,0,bces_rulearray+BCESFieldIndexKLineType);	/* K线类型 */
		AddField((void*)&BarFrom,sizeof(BarFrom),NULL,0,bces_rulearray+BCESFieldIndexBarFrom);	/* 起始Bar */
		AddField((void*)&BarCount,sizeof(BarCount),NULL,0,bces_rulearray+BCESFieldIndexBarCount);	/* Bar数量 */
	}
	CBCESFieldsKLineQueryReq& operator=(const CBCESFieldsKLineQueryReq& KLineQueryReq){
		m_fieldarray=m_fieldarray_KLineQueryReq;
		m_fieldsize=sizeof(m_fieldarray_KLineQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&KLineQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsKLineQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&KLineType,sizeof(KLineType),NULL,0,bces_rulearray+BCESFieldIndexKLineType);	/* K线类型 */
		AddField((void*)&BarFrom,sizeof(BarFrom),NULL,0,bces_rulearray+BCESFieldIndexBarFrom);	/* 起始Bar */
		AddField((void*)&BarCount,sizeof(BarCount),NULL,0,bces_rulearray+BCESFieldIndexBarCount);	/* Bar数量 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_KLineQueryReq),0x00,sizeof(CBCESFieldsKLineQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_KLineQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_KLineQueryReq[7];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
	BCESFieldTypeFlag KLineType;	/* K线类型 */
	BCESFieldTypeRequestID BarFrom;	/* 起始Bar */
	BCESFieldTypeRequestID BarCount;	/* Bar数量 */
};

/* K线 */
class CBCESFieldsKLineData:public CBMLFields
{
public:
	CBCESFieldsKLineData()
	{
		m_fieldarray=m_fieldarray_KLineData;
		m_fieldsize=sizeof(m_fieldarray_KLineData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsKLineData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&KLineType,sizeof(KLineType),NULL,0,bces_rulearray+BCESFieldIndexKLineType);	/* K线类型 */
	}
	CBCESFieldsKLineData(const CBCESFieldsKLineData& KLineData){
		m_fieldarray=m_fieldarray_KLineData;
		m_fieldsize=sizeof(m_fieldarray_KLineData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&KLineData+sizeof(CBMLFields),sizeof(CBCESFieldsKLineData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&KLineType,sizeof(KLineType),NULL,0,bces_rulearray+BCESFieldIndexKLineType);	/* K线类型 */
	}
	CBCESFieldsKLineData& operator=(const CBCESFieldsKLineData& KLineData){
		m_fieldarray=m_fieldarray_KLineData;
		m_fieldsize=sizeof(m_fieldarray_KLineData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&KLineData+sizeof(CBMLFields),sizeof(CBCESFieldsKLineData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&OpenPrice,sizeof(OpenPrice),NULL,0,bces_rulearray+BCESFieldIndexOpenPrice);	/* 开盘价 */
		AddField((void*)&HighestPrice,sizeof(HighestPrice),NULL,0,bces_rulearray+BCESFieldIndexHighestPrice);	/* 最高价 */
		AddField((void*)&LowestPrice,sizeof(LowestPrice),NULL,0,bces_rulearray+BCESFieldIndexLowestPrice);	/* 最低价 */
		AddField((void*)&ClosePrice,sizeof(ClosePrice),NULL,0,bces_rulearray+BCESFieldIndexClosePrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&KLineType,sizeof(KLineType),NULL,0,bces_rulearray+BCESFieldIndexKLineType);	/* K线类型 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_KLineData),0x00,sizeof(CBCESFieldsKLineData)-sizeof(CBMLFields)-sizeof(m_fieldarray_KLineData));
	}

	BML_FIELD_INFO m_fieldarray_KLineData[11];

	// Field
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
class CBCESFieldsTickLineQueryReq:public CBMLFields
{
public:
	CBCESFieldsTickLineQueryReq()
	{
		m_fieldarray=m_fieldarray_TickLineQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TickLineQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTickLineQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsTickLineQueryReq(const CBCESFieldsTickLineQueryReq& TickLineQueryReq){
		m_fieldarray=m_fieldarray_TickLineQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TickLineQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TickLineQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTickLineQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
	}
	CBCESFieldsTickLineQueryReq& operator=(const CBCESFieldsTickLineQueryReq& TickLineQueryReq){
		m_fieldarray=m_fieldarray_TickLineQueryReq;
		m_fieldsize=sizeof(m_fieldarray_TickLineQueryReq)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TickLineQueryReq+sizeof(CBMLFields),sizeof(CBCESFieldsTickLineQueryReq)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTimeFrom,sizeof(DateTimeFrom),NULL,0,bces_rulearray+BCESFieldIndexDateTimeFrom);	/* 起始日期时间 */
		AddField((void*)DateTimeTo,sizeof(DateTimeTo),NULL,0,bces_rulearray+BCESFieldIndexDateTimeTo);	/* 结束日期时间 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TickLineQueryReq),0x00,sizeof(CBCESFieldsTickLineQueryReq)-sizeof(CBMLFields)-sizeof(m_fieldarray_TickLineQueryReq));
	}

	BML_FIELD_INFO m_fieldarray_TickLineQueryReq[4];

	// Field
	BCESFieldTypeInstrumentID InstrumentID;	/* 合约号 */
	BCESFieldTypeDateTime DateTimeFrom;	/* 起始日期时间 */
	BCESFieldTypeDateTime DateTimeTo;	/* 结束日期时间 */
	BCESFieldTypeExchangeID ExchangeID;	/* 交易所号 */
};

/* Tick线 */
class CBCESFieldsTickLineData:public CBMLFields
{
public:
	CBCESFieldsTickLineData()
	{
		m_fieldarray=m_fieldarray_TickLineData;
		m_fieldsize=sizeof(m_fieldarray_TickLineData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memset((char*)this+sizeof(CBMLFields),0x00,sizeof(CBCESFieldsTickLineData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
	}
	CBCESFieldsTickLineData(const CBCESFieldsTickLineData& TickLineData){
		m_fieldarray=m_fieldarray_TickLineData;
		m_fieldsize=sizeof(m_fieldarray_TickLineData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TickLineData+sizeof(CBMLFields),sizeof(CBCESFieldsTickLineData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
	}
	CBCESFieldsTickLineData& operator=(const CBCESFieldsTickLineData& TickLineData){
		m_fieldarray=m_fieldarray_TickLineData;
		m_fieldsize=sizeof(m_fieldarray_TickLineData)/sizeof(BML_FIELD_INFO);
		m_fieldcount=0;
		memcpy((char*)this+sizeof(CBMLFields),(char*)&TickLineData+sizeof(CBMLFields),sizeof(CBCESFieldsTickLineData)-sizeof(CBMLFields));

		// Field Info
		AddField((void*)InstrumentID,sizeof(InstrumentID),NULL,0,bces_rulearray+BCESFieldIndexInstrumentID);	/* 合约号 */
		AddField((void*)DateTime,sizeof(DateTime),NULL,0,bces_rulearray+BCESFieldIndexDateTime);	/* 日期时间 */
		AddField((void*)&Price,sizeof(Price),NULL,0,bces_rulearray+BCESFieldIndexPrice);	/* 收盘价 */
		AddField((void*)&QtyTotal,sizeof(QtyTotal),NULL,0,bces_rulearray+BCESFieldIndexQtyTotal);	/* 成交量 */
		AddField((void*)&OI,sizeof(OI),NULL,0,bces_rulearray+BCESFieldIndexOI);	/* 空盘量 */
		AddField((void*)&Amount,sizeof(Amount),NULL,0,bces_rulearray+BCESFieldIndexAmount);	/* 成交额 */
		AddField((void*)ExchangeID,sizeof(ExchangeID),NULL,0,bces_rulearray+BCESFieldIndexExchangeID);	/* 交易所号 */
		AddField((void*)&BidPrice,sizeof(BidPrice),NULL,0,bces_rulearray+BCESFieldIndexBidPrice);	/* 叫买价 */
		AddField((void*)&BidQty,sizeof(BidQty),NULL,0,bces_rulearray+BCESFieldIndexBidQty);	/* 叫买量 */
		AddField((void*)&AskPrice,sizeof(AskPrice),NULL,0,bces_rulearray+BCESFieldIndexAskPrice);	/* 叫卖价 */
		AddField((void*)&AskQty,sizeof(AskQty),NULL,0,bces_rulearray+BCESFieldIndexAskQty);	/* 叫卖量 */
		AddField((void*)&HighLimit,sizeof(HighLimit),NULL,0,bces_rulearray+BCESFieldIndexHighLimit);	/* 涨停板价 */
		AddField((void*)&LowLimit,sizeof(LowLimit),NULL,0,bces_rulearray+BCESFieldIndexLowLimit);	/* 跌停板价 */
		return *this;
	}
	void Clean(){
		memset((char*)this+sizeof(CBMLFields)+sizeof(m_fieldarray_TickLineData),0x00,sizeof(CBCESFieldsTickLineData)-sizeof(CBMLFields)-sizeof(m_fieldarray_TickLineData));
	}

	BML_FIELD_INFO m_fieldarray_TickLineData[13];

	// Field
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


#endif /* __BCES_FIELD_DEFINE_H__ */
