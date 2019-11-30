// Fill.h: interface for the CFill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILL_H__3F677749_A076_4BA0_ACF7_D88EEF9FB575__INCLUDED_)
#define AFX_FILL_H__3F677749_A076_4BA0_ACF7_D88EEF9FB575__INCLUDED_
#include "Pi2.h"
#include "P2.h"
#include "AET.h"
#include "Bucket.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFill  
{
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CPi2 *p,int);     //��ʼ��
	void CreateBucket();            //����Ͱ
	void CreateEdge();              //�߱�
	void AddET(CAET *);             //�ϲ�ET��
	void ETOrder();                 //ET������
	void Gouraud(CDC *);            //�������
	void ClearMemory();             //�����ڴ�
	void DeleteAETChain(CAET *pAET);    //ɾ���߱�
protected:
	int PNum;   //�������
	CPi2 *P;    //�������궯̬����
	CAET *pHeadE,*pCurrentE,*pEdge;  //��Ч�߱�ڵ�ָ��
	CBucket *pHeadB,*pCurrentB;      //Ͱ��ڵ�ָ��
};

#endif // !defined(AFX_FILL_H__3F677749_A076_4BA0_ACF7_D88EEF9FB575__INCLUDED_)
