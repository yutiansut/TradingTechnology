#include "BCESQuotApiImp.h"
#include "BCESQuotApi.h"

CBCESQuotApi *CBCESQuotApi::CreateBCESQuotApi()
{
	return new CBCESQuotApiImp();
}
CBCESQuotApi::~CBCESQuotApi()
{
}
