// Test2View.cpp : implementation of the CTest2View class
//

#include "stdafx.h"
#include "Test2.h"

#include "Test2Doc.h"
#include "Test2View.h"
#include "Line.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest2View

IMPLEMENT_DYNCREATE(CTest2View, CView)

BEGIN_MESSAGE_MAP(CTest2View, CView)
	//{{AFX_MSG_MAP(CTest2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2View construction/destruction

CTest2View::CTest2View()
{
	// TODO: add construction code here

}

CTest2View::~CTest2View()
{
}

BOOL CTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View drawing

void CTest2View::OnDraw(CDC* pDC)
{
	CTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	GetClientRect(&rect);  //获得客户区矩形的大小
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View printing

BOOL CTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View diagnostics

#ifdef _DEBUG
void CTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest2Doc* CTest2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest2Doc)));
	return (CTest2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest2View message handlers

void CTest2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//编辑消息映射函数
	p0.x = point.x;
	p0.y = point.y;
	p0.x = p0.x - rect.Width()/2;   //设置坐标系向自定义坐标系转换
	p0.y = rect.Height()/2 - p0.y;

	CView::OnLButtonDown(nFlags, point);
}

void CTest2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	CLine * line = new CLine;
	CDC * pDC = GetDC();    //定义设备上下文指针
	/*
	pDC->SetMapMode(MM_ANISOTROPIC);     //自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());   //设置窗口比例
	pDC->SetViewportExt(rect.Width(),-rect.Height());  //设置视区比例，x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);  //设置客户区中心坐标原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);   //矩形与客户区重合
	*/

	pDC->SetMapMode(MM_ANISOTROPIC);    //自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());   //设置窗口比例
	pDC->SetViewportExt(rect.Width(),-rect.Height());  //设置视区比例，且Y轴向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2); //设置客户区中心坐标为坐标原点
	rect.OffsetRect(-rect.Width(),-rect.Height());   //矩形与客户区重合

	p1.x = p1.x-rect.Width()/2;
	p1.y = rect.Height()/2-p1.y;
	line->MoveTo(pDC,p0);
	line->LineTo(pDC,p1);
	delete line;
	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}
