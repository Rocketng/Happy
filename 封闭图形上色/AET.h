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
	double x;    //当前扫描线与有效边交点的X坐标
	int yMax;    //边得最大Y值
	double k;    //斜率的倒数（X的增量）
	CPi2 ps;     //边的起点
	CPi2 pe;     //边的终点
	CAET *pNext;

};

#endif // !defined(AFX_AET_H__C889CB13_94B6_436E_A7CF_B95D8C24338D__INCLUDED_)
