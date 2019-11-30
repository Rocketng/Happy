// Test4View.h : interface of the CTest4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST4VIEW_H__A099E325_6ACF_4B33_9F98_35B7A5B8D108__INCLUDED_)
#define AFX_TEST4VIEW_H__A099E325_6ACF_4B33_9F98_35B7A5B8D108__INCLUDED_

#include "P2.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Transform.h"
#include "Line.h"

class CTest4View : public CView
{
protected: // create from serialization only
	CTest4View();
	DECLARE_DYNCREATE(CTest4View)

// Attributes
public:
	CTest4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest4View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CP2 P[4];    //点表
	CRect rect;  //定义客户区
	void DoubleBuffer(); //双缓冲
	void ReadPoint();    //读入顶点列表
	void DrawObject(CDC *);  //绘制图形
	void DrawPolygon(CDC *pDC);  //绘制多边形
	virtual ~CTest4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CTransform trans;
	//{{AFX_MSG(CTest4View)
	afx_msg void OnDown();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnUp();
	afx_msg void OnIncrease();
	afx_msg void OnDecrease();
	afx_msg void OnClockwise();
	afx_msg void OnAntiCLockwise();
	afx_msg void OnXaxis();
	afx_msg void OnYaxis();
	afx_msg void OnOrg();
	afx_msg void OnXDirectionPlus();
	afx_msg void OnXDirectionNeg();
	afx_msg void OnYDirectionPlus();
	afx_msg void OnYDirectionNeg();
	afx_msg void OnRestore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Test4View.cpp
inline CTest4Doc* CTest4View::GetDocument()
   { return (CTest4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST4VIEW_H__A099E325_6ACF_4B33_9F98_35B7A5B8D108__INCLUDED_)
