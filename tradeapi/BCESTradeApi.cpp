#include "BCESTradeApiImp.h"
#include "BCESTradeApi.h"

CBCESTradeApi *CBCESTradeApi::CreateBCESTradeApi()
{
	return new CBCESTradeApiImp();
}
CBCESTradeApi::~CBCESTradeApi()
{
}
