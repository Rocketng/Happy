// Transform.h: interface for the CTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_H__626FF090_CEB7_4DA9_B902_799C8E55CB51__INCLUDED_)
#define AFX_TRANSFORM_H__626FF090_CEB7_4DA9_B902_799C8E55CB51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"
#include "P2.h"

class CTransform  
{
public:
	CTransform();
	virtual ~CTransform();
	void SetMat(CP3 *,int);   //��ʼ��
	void Identity();   //��ʼ������
	void Translate(double,double,double);  //ƽ�Ʊ任����
	void Scale(double,double,double); //�����任����
	void Scale(double,double,double,CP3);
	void Rotatex(double);  //��ת�任���� X��
	void Rotatex(double,CP3);
	void Rotatey(double);  //��ת�任���� Y��
	void Rotatey(double,CP3);
	void Rotatez(double);  //��ת�任���� Z��
	void Rotatez(double,CP3);
	void ReflectX();   //X��ķ���
	void ReflectY();   //Y��ķ���
	void ReflectZ();   //Z��ķ���
	void ReflectXOY();
	void ReflectYOZ();
	void ReflactZOX();
	void ShearX(double,double);  //x�������
	void ShearY(double,double);  
	void ShearZ(double,double);
	void MultiMatrix();   //�������

public:
	double T[4][4];
	CP3* POld;
	int num;
};

#endif // !defined(AFX_TRANSFORM_H__626FF090_CEB7_4DA9_B902_799C8E55CB51__INCLUDED_)
