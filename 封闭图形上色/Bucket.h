// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__FE6545C6_36DF_406E_A3E5_789882160DD6__INCLUDED_)
#define AFX_BUCKET_H__FE6545C6_36DF_406E_A3E5_789882160DD6__INCLUDED_
#include "AET.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBucket  
{
public:
	CBucket();
	virtual ~CBucket();
public:
	int ScanLine;   //ɨ����
	CAET *pET;      //Ͱ�ϵı߱�ָ��
	CBucket *pNext;
};

#endif // !defined(AFX_BUCKET_H__FE6545C6_36DF_406E_A3E5_789882160DD6__INCLUDED_)
