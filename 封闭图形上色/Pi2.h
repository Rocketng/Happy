// Pi2.h: interface for the CPi2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI2_H__4EE0EE67_F28C_41C9_9E55_E59322538825__INCLUDED_)
#define AFX_PI2_H__4EE0EE67_F28C_41C9_9E55_E59322538825__INCLUDED_
#include "RGB.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPi2  
{
public:
	CPi2();
	CPi2(double ,int);
	virtual ~CPi2();
public:
	double x;
	int y;
	CRGB c;
};

#endif // !defined(AFX_PI2_H__4EE0EE67_F28C_41C9_9E55_E59322538825__INCLUDED_)
