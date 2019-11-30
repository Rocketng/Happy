// Test3View.h : interface of the CTest3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST3VIEW_H__DF206B51_C6AC_4DC3_896D_4D789A755424__INCLUDED_)
#define AFX_TEST3VIEW_H__DF206B51_C6AC_4DC3_896D_4D789A755424__INCLUDED_
#include "P2.h"
#include "Pi2.h"
#include "Line.h"
#include "RGB.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest3View : public CView
{
protected: // create from serialization only
	CTest3View();
	DECLARE_DYNCREATE(CTest3View)

// Attributes
public:
	CTest3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest3View)
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
	void FillPolygon(CDC* pDC);
	void DrawPolygon(CDC* pDC);
	void DrawGraph();
	void ReadPoint();
	virtual ~CTest3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest3View)
	afx_msg void OnDrawpic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int bBlue;
	int bGreen;
	int bRed;
	bool bFill;
	CP2 P[7];
	CPi2 Pl[7];
};


#ifndef _DEBUG  // debug version in Test3View.cpp
inline CTest3Doc* CTest3View::GetDocument()
   { return (CTest3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST3VIEW_H__DF206B51_C6AC_4DC3_896D_4D789A755424__INCLUDED_)
