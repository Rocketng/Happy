// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__21F96584_2F07_4D05_BE20_AC66767D74A9__INCLUDED_)
#define AFX_LINE_H__21F96584_2F07_4D05_BE20_AC66767D74A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "p2.h"

class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC *,CP2); //�Ƶ�ָ��λ��
	void MoveTo(CDC *,double,double);
	void LineTo(CDC *,CP2);  //����ֱ�߲����յ�
	void LineTo(CDC *,double,double);
public:
	CP2 P0;   //���
	CP2 P1;   //�յ�

};

#endif // !defined(AFX_LINE_H__21F96584_2F07_4D05_BE20_AC66767D74A9__INCLUDED_)
