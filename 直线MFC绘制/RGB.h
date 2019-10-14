// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__2E10CA2F_7CE3_4A13_99DA_E8BABBA90547__INCLUDED_)
#define AFX_RGB_H__2E10CA2F_7CE3_4A13_99DA_E8BABBA90547__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	CRGB(double ,double,double);
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

#endif // !defined(AFX_RGB_H__2E10CA2F_7CE3_4A13_99DA_E8BABBA90547__INCLUDED_)
