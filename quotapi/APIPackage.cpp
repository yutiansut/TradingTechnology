#include "APIPackage.h"

CAPIPackage::CAPIPackage()
{
	m_api_buffer=NULL;
	m_api_length=0;
	m_api_size=0;
}

int CAPIPackage::Init(const char* buffer, unsigned int length)
{
	m_api_buffer=(char*)buffer;
	m_api_size=0;
	m_api_length=length;

	CBMLPackage::Init(m_api_buffer,0,m_api_length);
	GetFields(&m_Head,(USHORT)BCESFieldNoApiHead);

	CBMLPackage Package;
	GetPackage(BCESFieldNoApiBody,&Package);
	
	CBMLPackage::Init(Package.m_buffer,0,Package.m_length);
	
	return 0;
}

int CAPIPackage::Init(USHORT ServiceNo,UINT RequestID,UINT EndFlag,char* buffer,unsigned int size)
{
	m_api_buffer=buffer;
	m_api_size=size;
	m_api_length=0;

	m_Head.ServiceNo=ServiceNo;
	m_Head.RequestID=RequestID;
	m_Head.EndFlag=EndFlag;

	CBMLPackage::Init(m_api_buffer,m_api_size,0);

	// Head
	PutFields(&m_Head,BCESFieldNoApiHead);
	
	// Body
	CBMLPackage Package;
	PutPackage(BCESFieldNoApiBody,&Package);

	CBMLPackage::Init(Package.m_buffer,Package.m_size,0);

	return 0;
}

int CAPIPackage::LengthPlus(unsigned int n)
{
	CBMLPackage::LengthPlus(n);
	if(m_api_length>=50){
		// process for package body
		UINT length=m_length;
		length=htonl(length);
		memcpy(m_buffer-sizeof(length),&length,sizeof(length));
	}

	m_api_length+=n;

	return 0;
}

void CAPIPackage::SetEndFlag(BCESFieldTypeEndFlag EndFlag)
{
	CBMLPackage Package;
	CBMLPackage Head;

	Package.Init(m_api_buffer,m_api_size,m_api_length);
	Package.GetPackage((USHORT)BCESFieldNoApiHead,&Head);

	m_Head.EndFlag=EndFlag;
	m_Head.Pack(Head.m_buffer,Head.m_length);
}
