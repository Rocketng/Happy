// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__95FD0BC9_6AB0_4FF0_B757_E89B336BF211__INCLUDED_)
#define AFX_RGB_H__95FD0BC9_6AB0_4FF0_B757_E89B336BF211__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	CRGB(double,double,double);
	virtual ~CRGB();
	friend CRGB operator+(const CRGB &,const CRGB &);
	friend CRGB operator-(const CRGB &,const CRGB &);
	friend CRGB operator*(const CRGB &,const CRGB &);
	friend CRGB operator*(const CRGB &,double);
	friend CRGB operator*(double,const CRGB &);
	friend CRGB operator/(const CRGB &,double);
	friend CRGB operator+=(CRGB &,CRGB &);
	friend CRGB operator-=(CRGB &,CRGB &);
	friend CRGB operator*=(CRGB &,CRGB &);
	friend CRGB operator/=(CRGB &,double);
	void Normalize();    //归一化到[0,1]区间
public:
	double red;     //红色分量
	double green;   //绿色分量
	double blue;    //蓝色分量

};

#endif // !defined(AFX_RGB_H__95FD0BC9_6AB0_4FF0_B757_E89B336BF211__INCLUDED_)
