#ifndef __BCES_FIELDTYPE_DEFINE_H__
#define __BCES_FIELDTYPE_DEFINE_H__

#include "OSTypeDefine.h"

/* TypeDefine */
typedef CHAR            BCESFieldTypeTableName[51];                /*表名*/
typedef CHAR            BCESFieldTypeTableOperation;           /*表操作*/
typedef USHORT          BCESFieldTypeServiceNo;                /*指令编码*/
typedef UINT            BCESFieldTypeRequestID;                /*请求编号*/
typedef UINT            BCESFieldTypeEndFlag;                  /*结束标记*/
typedef UINT            BCESFieldTypeFlowID;                   /*流编号*/
typedef UINT            BCESFieldTypePkgNo;                    /*报文序号*/
typedef CHAR            BCESFieldTypeInvestorID[16];               /*投资者号*/
typedef CHAR            BCESFieldTypePassword[21];                 /*密码*/
typedef CHAR            BCESFieldTypeOrderID[31];                  /*订单号*/
typedef CHAR            BCESFieldTypeMatchID[31];                  /*成交号*/
typedef CHAR            BCESFieldTypePosiID[31];                   /*持仓号*/
typedef CHAR            BCESFieldTypeInstrumentID[16];             /*合约号*/
typedef DOUBLE          BCESFieldTypePrice;                    /*价格*/
typedef UINT            BCESFieldTypeQty;                      /*数量*/
typedef USHORT          BCESFieldTypeRspNo;                    /*应答编码*/
typedef CHAR            BCESFieldTypeRspDesc[257];                  /*应答描述*/
typedef CHAR            BCESFieldTypeDate[11];                     /*日期*/
typedef CHAR            BCESFieldTypeTime[9];                     /*时间*/
typedef CHAR            BCESFieldTypeDescription[65];              /*描述*/
typedef CHAR            BCESFieldTypeFlag;                     /*标志*/
typedef ULONG           BCESFieldTypeQtyTotal;                 /*总量*/
typedef CHAR            BCESFieldTypeVarietyID[11];                /*品种代码*/
typedef DOUBLE          BCESFieldTypeAmount;                   /*金额*/
typedef DOUBLE          BCESFieldTypeRate;                     /*比率*/
typedef CHAR            BCESFieldTypeInstrumentName[31];           /*合约名称*/
typedef CHAR            BCESFieldTypeMarketStatusDesc[31];         /*市场状态描述*/
typedef CHAR            BCESFieldTypeOrderStatusDesc[31];          /*市场状态描述*/
typedef CHAR            BCESFieldTypeDateTime[20];                 /*日期时间*/
typedef UINT            BCESFieldTypePoints;                   /*点差*/
typedef CHAR            BCESFieldTypeTitle[101];                    /*标题*/
typedef CHAR            BCESFieldTypeBulletinID[16];               /*公告编号*/
typedef CHAR            BCESFieldTypeNoticeID[16];                 /*通知编号*/
typedef CHAR            BCESFieldTypeContent[501];                  /*内容*/
typedef CHAR            BCESFieldTypeUserID[16];                   /*用户号*/
typedef CHAR            BCESFieldTypeURL[1025];                      /*网址*/
typedef CHAR            BCESFieldTypeFundIOStatusDesc[257];         /*出入金状态描述*/
typedef CHAR            BCESFieldTypeFundIOSeqno[31];              /*出入金流水号*/
typedef CHAR            BCESFieldTypeBankID[11];                   /*银行代码*/
typedef CHAR            BCESFieldTypeBankAccountID[41];            /*银行账号*/
typedef CHAR            BCESFieldTypeBankAccountName[101];          /*银行户名*/
typedef CHAR            BCESFieldTypeBankNameAccountID[141];        /*银行户名及账号*/
typedef CHAR            BCESFieldTypeReportData[1001];               /*报表内容*/
typedef CHAR            BCESFieldTypeName[51];                     /*姓名*/
typedef UINT            BCESFieldTypeRankingNum;               /*排名*/
typedef CHAR            BCESFieldTypeAddress[101];                  /*地址*/
typedef CHAR            BCESFieldTypeIP[101];                       /*IP地址*/
typedef CHAR            BCESFieldTypeGoodsName[31];                /*品种大类*/
typedef UINT            BCESFieldTypeVersionNo;                /*版本号*/
typedef CHAR            BCESFieldTypeDeliveryID[31];               /*交收交割编号*/
typedef CHAR            BCESFieldTypeTaxNo[31];                    /*税务登记号*/
typedef CHAR            BCESFieldTypePhoneNo[21];                  /*电话号码*/
typedef CHAR            BCESFieldTypeCredentialNo[51];             /*证件号*/
typedef CHAR            BCESFieldTypePostCode[21];                 /*邮编*/
typedef CHAR            BCESFieldTypeEmail[51];                    /*电子邮箱*/
typedef CHAR            BCESFieldTypeAdviserID[16];                /*顾问号*/
typedef CHAR            BCESFieldTypeQuesAnswContent[1025];          /*行情提问/回答内容*/
typedef CHAR            BCESFieldTypeQuestionID[31];               /*提问编号*/
typedef CHAR            BCESFieldTypePlateName[31];                /*板块*/
typedef CHAR            BCESFieldTypeExchangeID[17];               /*交易所号*/
typedef ULONG           BCESFieldTypeSessionID;                /*会话编号*/
typedef CHAR            BCESFieldTypeOrderRef[31];                 /*报单引用*/
typedef CHAR            BCESFieldTypePaySeqno[31];                 /*支付流水号*/
typedef CHAR            BCESFieldTypeAccountID[31];                /*资金账号*/
typedef CHAR            BCESFieldTypeOrderSysID[31];               /*交易所订单号*/
typedef UINT            BCESFieldTypeCTPFrontID;               /*CTP前置编号*/
typedef UINT            BCESFieldTypeCTPSessionID;             /*CTP会话编号*/
typedef CHAR            BCESFieldTypeCTPOrderRef[31];              /*CTP报单引用*/
typedef UINT            BCESFieldTypeAppNo;                    /*应用编号*/

/* ConstDefine */
/* 流编号 */
#define BCESConstFlowIDOnline                          0                    /*在线流*/
#define BCESConstCommentFlowIDOnline                          "在线流"
#define BCESConstFlowIDPrivate                          1                    /*私有流*/
#define BCESConstCommentFlowIDPrivate                          "私有流"
#define BCESConstFlowIDPublic                          2                    /*公有流*/
#define BCESConstCommentFlowIDPublic                          "公有流"

/* 结束标记 */
#define BCESConstEndFlagNotEOF                         1                    /*未结束*/
#define BCESConstCommentEndFlagNotEOF                         "未结束"
#define BCESConstEndFlagEOF                         0                    /*已结束*/
#define BCESConstCommentEndFlagEOF                         "已结束"

/* 表操作 */
#define BCESConstTableOperationInsert                  1                    /*插入*/
#define BCESConstCommentTableOperationInsert                  "插入"
#define BCESConstTableOperationUpdate                  2                    /*更新*/
#define BCESConstCommentTableOperationUpdate                  "更新"
#define BCESConstTableOperationDelete                  3                    /*删除*/
#define BCESConstCommentTableOperationDelete                  "删除"

/* 应答编码 */
#define BCESConstRspNoSucceed                           0                    /*成功*/
#define BCESConstCommentRspNoSucceed                           "成功"
#define BCESConstRspNoServiceNotSupported                           1000                 /*不提供此服务*/
#define BCESConstCommentRspNoServiceNotSupported                           "不提供此服务"
#define BCESConstRspNoNetworkProblem                           1001                 /*系统通讯故障，请稍候再试*/
#define BCESConstCommentRspNoNetworkProblem                           "系统通讯故障，请稍候再试"
#define BCESConstRspNoNotLogined                           1002                 /*未登录*/
#define BCESConstCommentRspNoNotLogined                           "未登录"
#define BCESConstRspNoDupLogin                           1003                 /*重复登录*/
#define BCESConstCommentRspNoDupLogin                           "重复登录"
#define BCESConstRspNoPasswordWrong                           1004                 /*密码错误*/
#define BCESConstCommentRspNoPasswordWrong                           "密码错误"
#define BCESConstRspNoUserPasswordWrong                           1005                 /*用户名或密码错误*/
#define BCESConstCommentRspNoUserPasswordWrong                           "用户名或密码错误"
#define BCESConstRspNoInstrumentNotExists                           1006                 /*合约不存在*/
#define BCESConstCommentRspNoInstrumentNotExists                           "合约不存在"
#define BCESConstRspNoInvalidOrderParam                           1007                 /*报单参数有错*/
#define BCESConstCommentRspNoInvalidOrderParam                           "报单参数有错"
#define BCESConstRspNoPositionNotExists                           1008                 /*持仓不存在*/
#define BCESConstCommentRspNoPositionNotExists                           "持仓不存在"
#define BCESConstRspNoPositionQtyNotEnough                           1009                 /*持仓不足*/
#define BCESConstCommentRspNoPositionQtyNotEnough                           "持仓不足"
#define BCESConstRspNoOrderNotExists                           1010                 /*订单不存在*/
#define BCESConstCommentRspNoOrderNotExists                           "订单不存在"
#define BCESConstRspNoOrderFilledOrCanceled                           1011                 /*订单已成交或已撤消*/
#define BCESConstCommentRspNoOrderFilledOrCanceled                           "订单已成交或已撤消"
#define BCESConstRspNoPositionClosed                           1012                 /*已全部平仓*/
#define BCESConstCommentRspNoPositionClosed                           "已全部平仓"
#define BCESConstRspNoInvalidProfitLossStopParam                           1013                 /*止赢止损参数错误*/
#define BCESConstCommentRspNoInvalidProfitLossStopParam                           "止赢止损参数错误"
#define BCESConstRspNoFundNotEnough                           1014                 /*资金不足*/
#define BCESConstCommentRspNoFundNotEnough                           "资金不足"
#define BCESConstRspNoMarketNotTrading                           1015                 /*当前状态不允许交易*/
#define BCESConstCommentRspNoMarketNotTrading                           "当前状态不允许交易"
#define BCESConstRspNoNoRights                           1016                 /*未开通商品交易权限*/
#define BCESConstCommentRspNoNoRights                           "未开通商品交易权限"

/* 买卖标志 */
#define BCESConstBSFlagBuy                          'B'                  /*买*/
#define BCESConstCommentBSFlagBuy                          "买"
#define BCESConstBSFlagSell                          'S'                  /*卖*/
#define BCESConstCommentBSFlagSell                          "卖"
#define BCESConstBSFlagExecute                          'X'                  /*行权*/
#define BCESConstCommentBSFlagExecute                          "行权"

/* 开平标志 */
#define BCESConstOCFlagOpen                          'O'                  /*开*/
#define BCESConstCommentOCFlagOpen                          "开"
#define BCESConstOCFlagClose                          'C'                  /*平*/
#define BCESConstCommentOCFlagClose                          "平"
#define BCESConstOCFlagCloseToday                          'T'                  /*平今*/
#define BCESConstCommentOCFlagCloseToday                          "平今"
#define BCESConstOCFlagForceClose                          'F'                  /*强平*/
#define BCESConstCommentOCFlagForceClose                          "强平"

/* 价格类型 */
#define BCESConstPriceTypeNormal                       'N'                  /*限价*/
#define BCESConstCommentPriceTypeNormal                       "限价"
#define BCESConstPriceTypeMarket                       'M'                  /*市价*/
#define BCESConstCommentPriceTypeMarket                       "市价"
#define BCESConstPriceTypeStop                       'S'                  /*Stop*/
#define BCESConstCommentPriceTypeStop                       "Stop"
#define BCESConstPriceTypeLimit                       'L'                  /*Limit*/
#define BCESConstCommentPriceTypeLimit                       "Limit"

/* 订单状态 */
#define BCESConstOrderStatusInserting                     'A'                  /*申报中*/
#define BCESConstCommentOrderStatusInserting                     "申报中"
#define BCESConstOrderStatusInserted                     'I'                  /*已报入*/
#define BCESConstCommentOrderStatusInserted                     "已报入"
#define BCESConstOrderStatusFilled                     'F'                  /*全部成交*/
#define BCESConstCommentOrderStatusFilled                     "全部成交"
#define BCESConstOrderStatusPartialFilled                     'P'                  /*部分成交*/
#define BCESConstCommentOrderStatusPartialFilled                     "部分成交"
#define BCESConstOrderStatusCanceled                     'C'                  /*已撤消*/
#define BCESConstCommentOrderStatusCanceled                     "已撤消"
#define BCESConstOrderStatusWaiting                     'W'                  /*未触发*/
#define BCESConstCommentOrderStatusWaiting                     "未触发"

/* 合约类型 */
#define BCESConstInstrumentTypeSpot                  'S'                  /*现货*/
#define BCESConstCommentInstrumentTypeSpot                  "现货"
#define BCESConstInstrumentTypeFutures                  'F'                  /*期货*/
#define BCESConstCommentInstrumentTypeFutures                  "期货"
#define BCESConstInstrumentTypeOptions                  'O'                  /*期权*/
#define BCESConstCommentInstrumentTypeOptions                  "期权"
#define BCESConstInstrumentTypeEquity                  'E'                  /*股票*/
#define BCESConstCommentInstrumentTypeEquity                  "股票"

/* 市场状态 */
#define BCESConstMarketStatusNotOpen                    '0'                  /*未开市*/
#define BCESConstCommentMarketStatusNotOpen                    "未开市"
#define BCESConstMarketStatusOpen                    '1'                  /*开市*/
#define BCESConstCommentMarketStatusOpen                    "开市"
#define BCESConstMarketStatusBegin                    '2'                  /*开盘*/
#define BCESConstCommentMarketStatusBegin                    "开盘"
#define BCESConstMarketStatusEnd                    '3'                  /*收盘*/
#define BCESConstCommentMarketStatusEnd                    "收盘"
#define BCESConstMarketStatusClose                    '4'                  /*收市*/
#define BCESConstCommentMarketStatusClose                    "收市"
#define BCESConstMarketStatusSectionEnd                    '5'                  /*节收盘*/
#define BCESConstCommentMarketStatusSectionEnd                    "节收盘"
#define BCESConstMarketStatusAuctionApply                    '6'                  /*集合竞价申报*/
#define BCESConstCommentMarketStatusAuctionApply                    "集合竞价申报"
#define BCESConstMarketStatusAuctionMatch                    '7'                  /*集合竞价撮合*/
#define BCESConstCommentMarketStatusAuctionMatch                    "集合竞价撮合"

/* 合约状态 */
#define BCESConstInstrumentStatusTrading                'T'                  /*已上市*/
#define BCESConstCommentInstrumentStatusTrading                "已上市"
#define BCESConstInstrumentStatusSuspended                'S'                  /*停牌*/
#define BCESConstCommentInstrumentStatusSuspended                "停牌"
#define BCESConstInstrumentStatusClosed                'C'                  /*到期*/
#define BCESConstCommentInstrumentStatusClosed                "到期"

/* 报价单位 */
#define BCESConstPriceUnitGram                       '0'                  /*克*/
#define BCESConstCommentPriceUnitGram                       "克"
#define BCESConstPriceUnitKilogram                       '1'                  /*千克*/
#define BCESConstCommentPriceUnitKilogram                       "千克"
#define BCESConstPriceUnitTon                       '2'                  /*吨*/
#define BCESConstCommentPriceUnitTon                       "吨"
#define BCESConstPriceUnitBucket                       '3'                  /*桶*/
#define BCESConstCommentPriceUnitBucket                       "桶"
#define BCESConstPriceUnitTon2                       '4'                  /*2吨*/
#define BCESConstCommentPriceUnitTon2                       "2吨"

/* 手续费类型 */
#define BCESConstFeeTypeAmount                         'A'                  /*固定金额*/
#define BCESConstCommentFeeTypeAmount                         "固定金额"
#define BCESConstFeeTypeRatio                         'R'                  /*按比率*/
#define BCESConstCommentFeeTypeRatio                         "按比率"

/* 出入金方向 */
#define BCESConstFundIODirectionIn                 '0'                  /*入金*/
#define BCESConstCommentFundIODirectionIn                 "入金"
#define BCESConstFundIODirectionOut                 '1'                  /*出金*/
#define BCESConstCommentFundIODirectionOut                 "出金"

/* 出入金状态 */
#define BCESConstFundIOStatusInserted                    '0'                  /*处理中*/
#define BCESConstCommentFundIOStatusInserted                    "处理中"
#define BCESConstFundIOStatusComplete                    '1'                  /*成功*/
#define BCESConstCommentFundIOStatusComplete                    "成功"
#define BCESConstFundIOStatusCanceled                    '2'                  /*失败*/
#define BCESConstCommentFundIOStatusCanceled                    "失败"
#define BCESConstFundIOStatusVerifing                    '3'                  /*待审核*/
#define BCESConstCommentFundIOStatusVerifing                    "待审核"

/* 支付方向 */
#define BCESConstPayDirectionIn                    '0'                  /*收款*/
#define BCESConstCommentPayDirectionIn                    "收款"
#define BCESConstPayDirectionOut                    '1'                  /*付款*/
#define BCESConstCommentPayDirectionOut                    "付款"

/* 出入金方式 */
#define BCESConstFundIOMethodAuto                    '0'                  /*自动*/
#define BCESConstCommentFundIOMethodAuto                    "自动"
#define BCESConstFundIOMethodManual                    '1'                  /*手工*/
#define BCESConstCommentFundIOMethodManual                    "手工"

/* 交易行为 */
#define BCESConstTradeActionPoints                     '0'                  /*服务器故障成交测试*/
#define BCESConstCommentTradeActionPoints                     "服务器故障成交测试"
#define BCESConstTradeActionPointsTxt                     '4'                  /*服务器故障提醒测试*/
#define BCESConstCommentTradeActionPointsTxt                     "服务器故障提醒测试"
#define BCESConstTradeActionWaitSeconds                     '1'                  /*网络故障成交测试*/
#define BCESConstCommentTradeActionWaitSeconds                     "网络故障成交测试"
#define BCESConstTradeActionWaitSecondsTxt                     '5'                  /*网络故障提醒测试*/
#define BCESConstCommentTradeActionWaitSecondsTxt                     "网络故障提醒测试"
#define BCESConstTradeActionSilent                     '2'                  /*网络服务器无响应测试*/
#define BCESConstCommentTradeActionSilent                     "网络服务器无响应测试"
#define BCESConstTradeActionTransfer                     '3'                  /*对冲*/
#define BCESConstCommentTradeActionTransfer                     "对冲"

/* 币种 */
#define BCESConstCurrencyRMB                        '0'                  /*人民币*/
#define BCESConstCommentCurrencyRMB                        "人民币"
#define BCESConstCurrencyUSD                        '1'                  /*美元*/
#define BCESConstCommentCurrencyUSD                        "美元"

/* 保证金率类型 */
#define BCESConstMarginRateTypeAmount                  'A'                  /*固定金额*/
#define BCESConstCommentMarginRateTypeAmount                  "固定金额"
#define BCESConstMarginRateTypeRatio                  'R'                  /*按比率*/
#define BCESConstCommentMarginRateTypeRatio                  "按比率"

/* 隔夜费类型 */
#define BCESConstOverNightFeeTypeAmount                'A'                  /*固定金额*/
#define BCESConstCommentOverNightFeeTypeAmount                "固定金额"
#define BCESConstOverNightFeeTypeRatio                'R'                  /*按比率*/
#define BCESConstCommentOverNightFeeTypeRatio                "按比率"

/* 收费类型 */
#define BCESConstFeeFlagSingle                         'S'                  /*单边*/
#define BCESConstCommentFeeFlagSingle                         "单边"
#define BCESConstFeeFlagdouble                         'D'                  /*双边*/
#define BCESConstCommentFeeFlagdouble                         "双边"

/* 系统模式 */
#define BCESConstSysModeMarket                         '0'                  /*做市*/
#define BCESConstCommentSysModeMarket                         "做市"
#define BCESConstSysModeMatch                         '1'                  /*撮合*/
#define BCESConstCommentSysModeMatch                         "撮合"
#define BCESConstSysModeMarketMatch                         '2'                  /*做市撮合*/
#define BCESConstCommentSysModeMarketMatch                         "做市撮合"

/* 条件类型 */
#define BCESConstConditionTypePrice                   'P'                  /*现价*/
#define BCESConstCommentConditionTypePrice                   "现价"
#define BCESConstConditionTypeBid                   'B'                  /*叫买价*/
#define BCESConstCommentConditionTypeBid                   "叫买价"
#define BCESConstConditionTypeAsk                   'A'                  /*叫卖价*/
#define BCESConstCommentConditionTypeAsk                   "叫卖价"

/* 条件方法 */
#define BCESConstConditionMethodEqual                 '0'                  /*等于*/
#define BCESConstCommentConditionMethodEqual                 "等于"
#define BCESConstConditionMethodMore                 '1'                  /*大于*/
#define BCESConstCommentConditionMethodMore                 "大于"
#define BCESConstConditionMethodMoreEqual                 '2'                  /*大于等于*/
#define BCESConstCommentConditionMethodMoreEqual                 "大于等于"
#define BCESConstConditionMethodLess                 '3'                  /*小于*/
#define BCESConstCommentConditionMethodLess                 "小于"
#define BCESConstConditionMethodLessEqual                 '4'                  /*小于等于*/
#define BCESConstCommentConditionMethodLessEqual                 "小于等于"
#define BCESConstConditionMethodNone                 '5'                  /*无*/
#define BCESConstCommentConditionMethodNone                 "无"

/* 签约状态 */
#define BCESConstAccountBindStatusProcessing               '0'                  /*处理中*/
#define BCESConstCommentAccountBindStatusProcessing               "处理中"
#define BCESConstAccountBindStatusSucceeded               '1'                  /*成功*/
#define BCESConstCommentAccountBindStatusSucceeded               "成功"
#define BCESConstAccountBindStatusFailed               '2'                  /*失败*/
#define BCESConstCommentAccountBindStatusFailed               "失败"

/* 产品编号 */
#define BCESConstProductTypeTradeClient                     '0'                  /*交易客户端*/
#define BCESConstCommentProductTypeTradeClient                     "交易客户端"
#define BCESConstProductTypeQuotClient                     '1'                  /*行情客户端*/
#define BCESConstCommentProductTypeQuotClient                     "行情客户端"
#define BCESConstProductTypeQuickClient                     '2'                  /*快速下单客户端*/
#define BCESConstCommentProductTypeQuickClient                     "快速下单客户端"
#define BCESConstProductTypeAdminClient                     '3'                  /*管理客户端*/
#define BCESConstCommentProductTypeAdminClient                     "管理客户端"
#define BCESConstProductTypeAgentClient                     '4'                  /*代理商客户端*/
#define BCESConstCommentProductTypeAgentClient                     "代理商客户端"
#define BCESConstProductTypeMarketClient                     '5'                  /*做市商测试工具*/
#define BCESConstCommentProductTypeMarketClient                     "做市商测试工具"
#define BCESConstProductTypeAnonymousClient                     '6'                  /*匿名客户端*/
#define BCESConstCommentProductTypeAnonymousClient                     "匿名客户端"
#define BCESConstProductTypeQuotProduct                     '7'                  /*行情产品*/
#define BCESConstCommentProductTypeQuotProduct                     "行情产品"

/* 交收交割状态 */
#define BCESConstDeliveryStatusApplyed                  '0'                  /*已申请*/
#define BCESConstCommentDeliveryStatusApplyed                  "已申请"
#define BCESConstDeliveryStatusVerifed                  '1'                  /*已确认*/
#define BCESConstCommentDeliveryStatusVerifed                  "已确认"
#define BCESConstDeliveryStatusPayed                  '2'                  /*已付款*/
#define BCESConstCommentDeliveryStatusPayed                  "已付款"
#define BCESConstDeliveryStatusCompleted                  '3'                  /*已成交*/
#define BCESConstCommentDeliveryStatusCompleted                  "已成交"

/* 发票标识 */
#define BCESConstInvoiceFlagYES                     '1'                  /*是*/
#define BCESConstCommentInvoiceFlagYES                     "是"
#define BCESConstInvoiceFlagNO                     '0'                  /*否*/
#define BCESConstCommentInvoiceFlagNO                     "否"

/* 发票类型 */
#define BCESConstInvoiceTypeVAT                     '0'                  /*增值税*/
#define BCESConstCommentInvoiceTypeVAT                     "增值税"
#define BCESConstInvoiceTypeCommon                     '1'                  /*普通*/
#define BCESConstCommentInvoiceTypeCommon                     "普通"
#define BCESConstInvoiceTypeSpecial                     '2'                  /*专用*/
#define BCESConstCommentInvoiceTypeSpecial                     "专用"

/* 证件类型 */
#define BCESConstCredentialTypeID                  '0'                  /*身份证*/
#define BCESConstCommentCredentialTypeID                  "身份证"
#define BCESConstCredentialTypePassport                  '1'                  /*护照*/
#define BCESConstCommentCredentialTypePassport                  "护照"

/* 支付服务类型 */
#define BCESConstPayServerTypeEcpss                   '0'                  /*汇潮支付*/
#define BCESConstCommentPayServerTypeEcpss                   "汇潮支付"
#define BCESConstPayServerTypeAllPayIn                   '1'                  /*通联支付*/
#define BCESConstCommentPayServerTypeAllPayIn                   "通联支付"
#define BCESConstPayServerTypeABC                   '2'                  /*农行*/
#define BCESConstCommentPayServerTypeABC                   "农行"

/* 提问/回答标志 */
#define BCESConstQuesAnswFlagQuestion                    'Q'                  /*提问*/
#define BCESConstCommentQuesAnswFlagQuestion                    "提问"
#define BCESConstQuesAnswFlagAnswer                    'A'                  /*回答*/
#define BCESConstCommentQuesAnswFlagAnswer                    "回答"

/* 投资者顾问标志 */
#define BCESConstInvestorAdviserFlagInvestor             'I'                  /*投资者*/
#define BCESConstCommentInvestorAdviserFlagInvestor             "投资者"
#define BCESConstInvestorAdviserFlagAdviser             'A'                  /*顾问*/
#define BCESConstCommentInvestorAdviserFlagAdviser             "顾问"

/* 交易所号 */
#define BCESConstExchangeIDNONE                      ""                   /*交易所*/
#define BCESConstCommentExchangeIDNONE                      "交易所"
#define BCESConstExchangeIDSHFE                      "SHFE"               /*上海期货交易所*/
#define BCESConstCommentExchangeIDSHFE                      "上海期货交易所"
#define BCESConstExchangeIDDCE                      "DCE"                /*大连商品交易所*/
#define BCESConstCommentExchangeIDDCE                      "大连商品交易所"
#define BCESConstExchangeIDCZCE                      "CZCE"               /*郑州商品交易所*/
#define BCESConstCommentExchangeIDCZCE                      "郑州商品交易所"
#define BCESConstExchangeIDCFFEX                      "CFFEX"              /*中国金融期货交易所*/
#define BCESConstCommentExchangeIDCFFEX                      "中国金融期货交易所"
#define BCESConstExchangeIDINE                      "INE"                /*上海国际能源交易中心*/
#define BCESConstCommentExchangeIDINE                      "上海国际能源交易中心"

/* 投资者角色 */
#define BCESConstInvestorRoleAdviser                    'A'                  /*顾问*/
#define BCESConstCommentInvestorRoleAdviser                    "顾问"
#define BCESConstInvestorRoleStudent                    'S'                  /*学员*/
#define BCESConstCommentInvestorRoleStudent                    "学员"
#define BCESConstInvestorRoleInvestor                    'I'                  /*投资者*/
#define BCESConstCommentInvestorRoleInvestor                    "投资者"

/* 投资者标志 */
#define BCESConstInvestorFlagImportant                    'I'                  /*重要*/
#define BCESConstCommentInvestorFlagImportant                    "重要"
#define BCESConstInvestorFlagCommon                    'C'                  /*普通*/
#define BCESConstCommentInvestorFlagCommon                    "普通"

/* K线类型 */
#define BCESConstKLineType1S                       '0'                  /*1秒线*/
#define BCESConstCommentKLineType1S                       "1秒线"
#define BCESConstKLineType5S                       '1'                  /*5秒线*/
#define BCESConstCommentKLineType5S                       "5秒线"
#define BCESConstKLineType15S                       '2'                  /*15秒线*/
#define BCESConstCommentKLineType15S                       "15秒线"
#define BCESConstKLineType1D                       '3'                  /*1日线*/
#define BCESConstCommentKLineType1D                       "1日线"
#define BCESConstKLineType1M                       '4'                  /*1分线*/
#define BCESConstCommentKLineType1M                       "1分线"
#define BCESConstKLineType5M                       '5'                  /*5分线*/
#define BCESConstCommentKLineType5M                       "5分线"
#define BCESConstKLineType15M                       '6'                  /*15分线*/
#define BCESConstCommentKLineType15M                       "15分线"


/* MacroDefine */
#define BCESMacroBCESPackageSize                7000                 /*BCES数据包大小*/
#define BCESMacroAPIPackageSize                 8192                 /*API数据包大小*/
#define BCESMacroFlowResumeMethodRestart        1                    /*从交易日开始重传*/
#define BCESMacroFlowResumeMethodResume         2                    /*从上次断点续传*/
#define BCESMacroFlowResumeMethodQuick          3                    /*从最新点传输*/

#endif /* __BCES_FIELDTYPE_DEFINE_H__ */
