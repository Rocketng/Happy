// test5View.h : interface of the CTest5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST5VIEW_H__9712CF26_8CC3_4DB8_8F47_B89758E42C39__INCLUDED_)
#define AFX_TEST5VIEW_H__9712CF26_8CC3_4DB8_8F47_B89758E42C39__INCLUDED_

#include "Face.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"
#include "Transform.h"
#include "P2.h"

class CTest5View : public CView
{
protected: // create from serialization only
	CTest5View();
	DECLARE_DYNCREATE(CTest5View)

// Attributes
public:
	CTest5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest5View)
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
	void ObliqueProject(CP3 p);
	CFace F[6];
	CP3 P[8];
	CTransform trans;
	CP2 ScreenP;
	CRect rect;  //定义客户区
	void ReadFace();
	void ReadPoint();
	virtual ~CTest5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void DoubleBuffer();
	void DrawObject(CDC*);
	void DrawPolygon(CDC*);

// Generated message map functions
protected:
	//{{AFX_MSG(CTest5View)
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnFront();
	afx_msg void OnBack();
	afx_msg void OnIncrease();
	afx_msg void OnDecrease();
	afx_msg void OnRxaxis();
	afx_msg void OnRyaxis();
	afx_msg void OnRzaxis();
	afx_msg void OnRxoy();
	afx_msg void OnRyoz();
	afx_msg void OnRxoz();
	afx_msg void OnSxplus();
	afx_msg void OnSyplus();
	afx_msg void OnSzplus();
	afx_msg void OnReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test5View.cpp
inline CTest5Doc* CTest5View::GetDocument()
   { return (CTest5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST5VIEW_H__9712CF26_8CC3_4DB8_8F47_B89758E42C39__INCLUDED_)
