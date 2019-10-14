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
	ON_WM_MOUSEMOVE()
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
	m_bDrawing = false;

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
	m_bDrawing = true;
	p0.x = point.x;
	p0.y = point.y;
	p0.x = p0.x - rect.Width()/2;   //设置坐标系向自定义坐标系转换
	p0.y = rect.Height()/2 - p0.y;
	p1.x = p0.x;
	p1.y = p0.y;
	
	//MessageBox();

	CView::OnLButtonDown(nFlags, point);
}

void CTest2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bDrawing)
		return;
	m_bDrawing = false;

	p1.x = point.x;
	p1.y = point.y;
	CLine * line = new CLine;
	CDC * pDC = GetDC();    //定义设备上下文指针

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

void CTest2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bDrawing)
		return;
	
	CDC * pDC = GetDC();    //定义设备上下文指针
	pDC->SetMapMode(MM_ANISOTROPIC);    //自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());   //设置窗口比例
	pDC->SetViewportExt(rect.Width(),-rect.Height());  //设置视区比例，且Y轴向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2); //设置客户区中心坐标为坐标原点
	rect.OffsetRect(-rect.Width(),-rect.Height());   //矩形与客户区重合
	pDC->SelectStockObject(NULL_BRUSH);
	CPen NewPen,* pOldPen;   //定义画笔
	NewPen.CreatePen(PS_SOLID,1,RGB(255,0,0));   //创建蓝色画笔
	pOldPen = pDC->SelectObject(&NewPen);  //将蓝色画笔选入设备上下文
	pDC->SetROP2(R2_NOTXORPEN);   //执行到这一句话的时候，
	//画面上已有前一次响应鼠标移动事件时画出的直线，这句代码把之前的直线擦掉
	
	pDC->MoveTo(p0.x,p0.y);
	pDC->LineTo(p1.x,p1.y);
   
	p1.x = point.x;
	p1.y = point.y;
	p1.x = p1.x-rect.Width()/2;
	p1.y = rect.Height()/2-p1.y;

	pDC->MoveTo(p0.x,p0.y);
	pDC->LineTo(p1.x,p1.y);

	
	pDC->SelectObject(pOldPen);  //恢复设备上下文中的原画笔
	NewPen.DeleteObject(); //删除已成自由状态的画笔
	ReleaseDC(pDC);

	CView::OnMouseMove(nFlags, point);
}
