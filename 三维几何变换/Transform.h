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
	void SetMat(CP3 *,int);   //初始化
	void Identity();   //初始化矩阵
	void Translate(double,double,double);  //平移变换矩阵
	void Scale(double,double,double); //比例变换矩阵
	void Scale(double,double,double,CP3);
	void Rotatex(double);  //旋转变换矩阵 X轴
	void Rotatex(double,CP3);
	void Rotatey(double);  //旋转变换矩阵 Y轴
	void Rotatey(double,CP3);
	void Rotatez(double);  //旋转变换矩阵 Z轴
	void Rotatez(double,CP3);
	void ReflectX();   //X轴的反射
	void ReflectY();   //Y轴的反射
	void ReflectZ();   //Z轴的反射
	void ReflectXOY();
	void ReflectYOZ();
	void ReflactZOX();
	void ShearX(double,double);  //x反向错切
	void ShearY(double,double);  
	void ShearZ(double,double);
	void MultiMatrix();   //矩阵相乘

public:
	double T[4][4];
	CP3* POld;
	int num;
};

#endif // !defined(AFX_TRANSFORM_H__626FF090_CEB7_4DA9_B902_799C8E55CB51__INCLUDED_)
