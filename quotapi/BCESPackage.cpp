#include "BCESPackage.h"

CBCESPackage::CBCESPackage()
{
	m_bces_buffer=NULL;
	m_bces_length=0;
	m_bces_size=0;
}

int CBCESPackage::Init(const char* buffer, unsigned int length)
{
	m_bces_buffer=(char*)buffer;
	m_bces_size=0;
	m_bces_length=length;

	CBMLPackage::Init(m_bces_buffer,0,m_bces_length);
	GetFields(&m_Head,(USHORT)BCESFieldNoHead);

	CBMLPackage Package;
	GetPackage(BCESFieldNoBody,&Package);
	
	CBMLPackage::Init(Package.m_buffer,0,Package.m_length);
	
	return 0;
}

int CBCESPackage::Init(UINT RequestID,char* buffer,unsigned int size)
{
	m_bces_buffer=buffer;
	m_bces_size=size;
	m_bces_length=0;

	m_Head.RequestID=RequestID;
	m_Head.EndFlag=0;

	CBMLPackage::Init(m_bces_buffer,m_bces_size,0);

	// Head
	PutFields(&m_Head,BCESFieldNoHead);
	
	// Body
	CBMLPackage Package;
	PutPackage(BCESFieldNoBody,&Package);

	CBMLPackage::Init(Package.m_buffer,Package.m_size,0);

	return 0;
}

int CBCESPackage::LengthPlus(unsigned int n)
{
	CBMLPackage::LengthPlus(n);
	if(m_bces_length>=40){
		// process for package body
		UINT length=m_length;
		length=htonl(length);
		memcpy(m_buffer-sizeof(length),&length,sizeof(length));
	}

	m_bces_length+=n;

	return 0;
}

void CBCESPackage::SetEndFlag(BCESFieldTypeEndFlag EndFlag)
{
	CBMLPackage Package;
	CBMLPackage Head;

	Package.Init(m_bces_buffer,m_bces_size,m_bces_length);
	Package.GetPackage((USHORT)BCESFieldNoHead,&Head);

	m_Head.EndFlag=EndFlag;
	m_Head.Pack(Head.m_buffer,Head.m_length);
}
