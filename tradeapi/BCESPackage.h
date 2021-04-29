#ifndef __BCES_PACKAGE_H__
#define __BCES_PACKAGE_H__

#include "os.h"
#include "BMLPackage.h"
#include "BCESFieldDefine.h"

class CBMLPackage;
class CBMLField;
class CBCESPackage:public CBMLPackage
{
public:
	CBCESPackage();

	int Init(const char* buffer, unsigned int length);	// For UnPack
	int Init(UINT RequestID,char* buffer,unsigned int size); // For Pack

	UINT GetRequestID(){return m_Head.RequestID;}
	UINT GetEndFlag(){return m_Head.EndFlag;}
	char* GetBuffer(){return m_bces_buffer;}
	unsigned int GetLength(){return m_bces_length;}
	int LengthPlus(unsigned int n);
	void SetEndFlag(BCESFieldTypeEndFlag EndFlag);

	char *m_bces_buffer;
	unsigned int m_bces_length;
	unsigned int m_bces_size;
	CBCESFieldsHead m_Head;
};

#endif /* __BCES_PACKAGE_H__ */
