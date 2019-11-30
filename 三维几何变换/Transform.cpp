// Transform.cpp: implementation of the CTransform class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test5.h"
#include "Transform.h"
#include "math.h"
#define PI 3.1415926535

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTransform::CTransform()
{

}

CTransform::~CTransform()
{

}

void CTransform::SetMat(CP3 *p,int n){
	POld = p;
	num = n;
}

void CTransform::Identity(){   //��λ����
	T[0][0]=T[1][1]=T[2][2]=T[3][3] = 1.0;
	T[0][1]=T[0][2]=T[0][3] = 0;
	T[1][0]=T[1][2]=T[1][3] = 0;
	T[2][0]=T[2][1]=T[2][3] = 0;
	T[3][0]=T[3][1]=T[3][2] = 0;
}

void CTransform::Translate(double tx,double ty,double tz){    //ƽ�Ʊ任����
	Identity();
	T[3][0] = tx;
	T[3][1] = ty;
	T[3][2] = tz;
	MultiMatrix();
}

void CTransform::Scale(double sx,double sy,double sz){ //�����任����
	Identity();
	T[0][0] = sx;
	T[1][1] = sy;
	T[2][2] = sz;
	MultiMatrix();
}

void CTransform::Scale(double sx,double sy,double sz,CP3 p){ //�����任����,�̶���
	Translate(-p.x,-p.y,-p.z);
	Scale(sx,sy,sz);
	Translate(p.x,p.y,p.z);
}

void CTransform::Rotatex(double beta){  //��ת�任���� X��
	Identity();
	double rad = beta*PI/180;
	T[1][1] = cos(rad);
	T[1][2] = sin(rad);
	T[2][1] = -sin(rad);
	T[2][2] = cos(rad);
	MultiMatrix();
}
	
void CTransform::Rotatex(double beta,CP3 p){
	Translate(-p.x,-p.y,-p.z);
	Rotatex(beta);
	Translate(p.x,p.y,p.z);
}

void CTransform::Rotatey(double beta){ //��ת�任���� Y��
	Identity();
	double rad = beta*PI/180;
	T[0][0] = cos(rad);
	T[0][2] = -sin(rad);
	T[2][0] = sin(rad);
	T[2][2] = cos(rad);
	MultiMatrix();
}
	
void CTransform::Rotatey(double beta,CP3 p){
	Translate(-p.x,-p.y,-p.z);
	Rotatey(beta);
	Translate(p.x,p.y,p.z);
}

void CTransform::Rotatez(double beta){ //��ת�任���� Z��
	Identity();
	double rad = beta*PI/180;
	T[0][0] = cos(rad);
	T[0][1] = sin(rad);
	T[1][0] = -sin(rad);
	T[1][1] = cos(rad);
	MultiMatrix();
}

void CTransform::Rotatez(double beta,CP3 p){
	Translate(-p.x,-p.y,-p.z);
	Rotatez(beta);
	Translate(p.x,p.y,p.z);
}

void CTransform::ReflectX(){   //X��ķ���
	Identity();
	T[1][1] = -1;
	T[2][2] = -1;
	MultiMatrix();
}

void CTransform::ReflectY(){   //Y��ķ���
	Identity();
	T[0][0] = -1;
	T[2][2] = -1;
	MultiMatrix();
}

void CTransform::ReflectZ(){   //Z��ķ���
	Identity();
	T[0][0] = -1;
	T[1][1] = -1;
	MultiMatrix();
}

void CTransform::ReflectXOY(){
	Identity();
	T[2][2] = -1;
	MultiMatrix();
}

void CTransform::ReflectYOZ(){
	Identity();
	T[0][0] = -1;
	MultiMatrix();
}

void CTransform::ReflactZOX(){
	Identity();
	T[1][1] = -1;
	MultiMatrix();
}

void CTransform::ShearX(double d,double g){  //x�������
	Identity();
	T[1][0] = d;
	T[2][0] = g;
	MultiMatrix();
}

void CTransform::ShearY(double b,double h){
	Identity();
	T[0][1] = b;
	T[2][1] = h;
	MultiMatrix();
}
void CTransform::ShearZ(double c,double f){
	Identity();
	T[0][2] = c;
	T[1][2] = f;
	MultiMatrix();
}

void CTransform::MultiMatrix(){               //�������
	CP3 *PNew = new CP3[num];
	for(int i=0;i<num;i++){
		PNew[i] = POld[i];
	}
	for(int j=0;j<num;j++){
		POld[j].x = PNew[j].x*T[0][0]+PNew[j].y*T[1][0]+PNew[j].z*T[2][0]+PNew[j].w*T[3][0];
		POld[j].y = PNew[j].x*T[0][1]+PNew[j].y*T[1][1]+PNew[j].z*T[2][1]+PNew[j].w*T[3][1];
		POld[j].z = PNew[j].x*T[0][2]+PNew[j].y*T[1][2]+PNew[j].z*T[2][2]+PNew[j].w*T[3][2];
	}
	delete []PNew;
}