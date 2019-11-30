// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__9C3CA94D_E48E_44AE_B780_4930F977A32B__INCLUDED_)
#define AFX_RGB_H__9C3CA94D_E48E_44AE_B780_4930F977A32B__INCLUDED_

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
	void Normalize();    //��һ����[0,1]����
public:
	double red;     //��ɫ����
	double green;   //��ɫ����
	double blue;    //��ɫ����

};

#endif // !defined(AFX_RGB_H__9C3CA94D_E48E_44AE_B780_4930F977A32B__INCLUDED_)
