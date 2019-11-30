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
	void SetPoint(CPi2 *p,int);     //初始化
	void CreateBucket();            //创建桶
	void CreateEdge();              //边表
	void AddET(CAET *);             //合并ET表
	void ETOrder();                 //ET表排序
	void Gouraud(CDC *);            //填充多边形
	void ClearMemory();             //清理内存
	void DeleteAETChain(CAET *pAET);    //删除边表
protected:
	int PNum;   //顶点个数
	CPi2 *P;    //顶点坐标动态数组
	CAET *pHeadE,*pCurrentE,*pEdge;  //有效边表节点指针
	CBucket *pHeadB,*pCurrentB;      //桶表节点指针
};

#endif // !defined(AFX_FILL_H__3F677749_A076_4BA0_ACF7_D88EEF9FB575__INCLUDED_)
