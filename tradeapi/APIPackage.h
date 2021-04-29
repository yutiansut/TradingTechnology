#ifndef __API_PACKAGE_H__
#define __API_PACKAGE_H__

#include "os.h"
#include "BMLPackage.h"
#include "BCESFieldDefine.h"

class CBMLPackage;
class CBMLField;
class CAPIPackage:public CBMLPackage
{
public:
	CAPIPackage();

	int Init(const char* buffer, unsigned int length);	// For UnPack
	int Init(USHORT ServiceNo,UINT RequestID,UINT EndFlag,char* buffer,unsigned int size); // For Pack
	int Pack(const CBMLField* Field,CBMLPackage* Package);
	int Pack(USHORT No,CBMLPackage* Package);

	USHORT GetServiceNo(){return m_Head.ServiceNo;}
	UINT GetRequestID(){return m_Head.RequestID;}
	UINT GetEndFlag(){return m_Head.EndFlag;}
	char* GetBuffer(){return m_api_buffer;}
	unsigned int GetLength(){return m_api_length;}
	int LengthPlus(unsigned int n);
	void SetEndFlag(BCESFieldTypeEndFlag EndFlag);

	char *m_api_buffer;
	unsigned int m_api_length;
	unsigned int m_api_size;
	CBCESFieldsApiHead m_Head;
};

#endif /* __API_PACKAGE_H__ */
