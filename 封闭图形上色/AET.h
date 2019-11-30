// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__C889CB13_94B6_436E_A7CF_B95D8C24338D__INCLUDED_)
#define AFX_AET_H__C889CB13_94B6_436E_A7CF_B95D8C24338D__INCLUDED_
#include "Pi2.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAET  
{
public:
	CAET();
	virtual ~CAET();
public:
	double x;    //��ǰɨ��������Ч�߽����X����
	int yMax;    //�ߵ����Yֵ
	double k;    //б�ʵĵ�����X��������
	CPi2 ps;     //�ߵ����
	CPi2 pe;     //�ߵ��յ�
	CAET *pNext;

};

#endif // !defined(AFX_AET_H__C889CB13_94B6_436E_A7CF_B95D8C24338D__INCLUDED_)
