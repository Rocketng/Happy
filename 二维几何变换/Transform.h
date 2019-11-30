// Transform.h: interface for the CTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_H__EDC554C4_EDB7_431B_936B_FA1ACA0D5B31__INCLUDED_)
#define AFX_TRANSFORM_H__EDC554C4_EDB7_431B_936B_FA1ACA0D5B31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CTransform   //��ά���α任
{
public:
	CTransform();
	virtual ~CTransform();
	void SetMat(CP2 *,int);
	void Identity();
	void Translate(double,double);    //ƽ�Ʊ任����
	void Scale(double,double);        //�����任����
	void Scale(double,double,CP2);    //���������һ��ı����任����
	void Rotate(double);              //��ת�任����
	void Rotate(double,CP2);          //���������һ�����ת�任����
	void ReflectOrg();                //ԭ�㷴��任����
	void ReflectX();                  //X�ᷴ��任����
	void ReflectY();                  //Y�ᷴ��任����
	void Shear(double,double);        //���б任����
	void MultiMatrix();               //�������
public:
	double T[3][3];
	CP2 * POld;
	int num;

};

#endif // !defined(AFX_TRANSFORM_H__EDC554C4_EDB7_431B_936B_FA1ACA0D5B31__INCLUDED_)
