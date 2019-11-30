// Test3View.cpp : implementation of the CTest3View class
//

#include "stdafx.h"
#include "Test3.h"

#include "Test3Doc.h"
#include "Test3View.h"
#include "Fill.h"
#include "math.h"
#define Round(x) (int)(floor(x+0.5))

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest3View

IMPLEMENT_DYNCREATE(CTest3View, CView)

BEGIN_MESSAGE_MAP(CTest3View, CView)
	//{{AFX_MSG_MAP(CTest3View)
	ON_COMMAND(IDM_DRAWPIC, OnDrawpic)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest3View construction/destruction

CTest3View::CTest3View()
{
	// TODO: add construction code here
	bFill = false;  //��ʼ��Ϊ0

}

CTest3View::~CTest3View()
{
}

BOOL CTest3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest3View drawing

void CTest3View::OnDraw(CDC* pDC)
{
	CTest3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	ReadPoint();
	DrawGraph();
}

/////////////////////////////////////////////////////////////////////////////
// CTest3View printing

BOOL CTest3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest3View diagnostics

#ifdef _DEBUG
void CTest3View::AssertValid() const
{
	CView::AssertValid();
}

void CTest3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest3Doc* CTest3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest3Doc)));
	return (CTest3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest3View message handlers

void CTest3View::ReadPoint()
{
	P[0].x = 50; P[0].y = 100;
	P[1].x = -150; P[1].y = 300;
	P[2].x = -250; P[2].y = 50;
	P[3].x = -150; P[3].y = -250;
	P[4].x = 0; P[4].y = -50;
	P[5].x = 100; P[5].y = -250;
	P[6].x = 300; P[6].y = 150;
}

void CTest3View::DrawGraph()
{
	CRect rect;
	GetClientRect (&rect);
	CDC* pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	if(!bFill)
		DrawPolygon(pDC);  //���ƶ����
	else
		FillPolygon(pDC);  //�������
	ReleaseDC(pDC);    //�ͷ�DC
}

void CTest3View::DrawPolygon(CDC *pDC)
{
	CLine * line = new CLine;
	CP2 t;
	for(int i=0;i<7;i++){//���ƶ����
		if(i==0){
			line->MoveTo(pDC,P[i]);
			t = P[i];
		}else{
			line->LineTo(pDC,P[i]);
		}
	}
	line->LineTo(pDC,t);  //�պ϶����
	delete line;
}

void CTest3View::FillPolygon(CDC *pDC)
{
	for(int i=0;i<7;i++){ // ת�洢�������꣬y����ȡΪ����
		Pl[i].x = P[i].x;
		Pl[i].y = Round(P[i].y);
		Pl[i].c = CRGB(bRed/255.0,bGreen/255.0,bBlue/255.0);
	}
	CFill *fill = new CFill;
	fill->SetPoint(Pl,7);  //��ʼ��Fill����
	fill->CreateBucket();  //����Ͱ��
	fill->CreateEdge();    //�����߱�
	fill->Gouraud(pDC);    //�������
	delete fill;           //�����ڴ�
}

void CTest3View::OnDrawpic() 
{
	// TODO: Add your command handler code here
	COLORREF GetClr = RGB(0,0,0);  //��ɫ����ɫ
	CColorDialog ccd(GetClr,CC_SOLIDCOLOR);  //������ɫ�Ի������
	if(IDOK == ccd.DoModal())
		GetClr = ccd.GetColor();
	else
		return;
	bRed = GetRValue(GetClr);  //��ȡ��ɫ����
	bGreen = GetGValue(GetClr);  //��ȡ��ɫ����
	bBlue = GetBValue(GetClr);   //��ȡ��ɫ����
	bFill = true;
	Invalidate();
}
