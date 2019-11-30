// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__38564EF7_2934_4608_9B0B_3DEFEE684756__INCLUDED_)
#define AFX_LINE_H__38564EF7_2934_4608_9B0B_3DEFEE684756__INCLUDED_
#include "P2.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC *,CP2); //移到指定位置
	void MoveTo(CDC *,double,double);
	void LineTo(CDC *,CP2);  //绘制直线不含终点
	void LineTo(CDC *,double,double);
public:
	CP2 P0;   //起点
	CP2 P1;   //终点


};

#endif // !defined(AFX_LINE_H__38564EF7_2934_4608_9B0B_3DEFEE684756__INCLUDED_)
