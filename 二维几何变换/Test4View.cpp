// Test4View.cpp : implementation of the CTest4View class
//

#include "stdafx.h"
#include "Test4.h"

#include "Test4Doc.h"
#include "Test4View.h"
#include "Line.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest4View

IMPLEMENT_DYNCREATE(CTest4View, CView)

BEGIN_MESSAGE_MAP(CTest4View, CView)
	//{{AFX_MSG_MAP(CTest4View)
	ON_COMMAND(Down, OnDown)
	ON_COMMAND(Left, OnLeft)
	ON_COMMAND(Right, OnRight)
	ON_COMMAND(Up, OnUp)
	ON_COMMAND(Increase, OnIncrease)
	ON_COMMAND(Decrease, OnDecrease)
	ON_COMMAND(Clockwise, OnClockwise)
	ON_COMMAND(AntiCLockwise, OnAntiCLockwise)
	ON_COMMAND(Xaxis, OnXaxis)
	ON_COMMAND(Yaxis, OnYaxis)
	ON_COMMAND(Org, OnOrg)
	ON_COMMAND(XDirectionPlus, OnXDirectionPlus)
	ON_COMMAND(XDirectionNeg, OnXDirectionNeg)
	ON_COMMAND(YDirectionPlus, OnYDirectionPlus)
	ON_COMMAND(YDirectionNeg, OnYDirectionNeg)
	ON_COMMAND(Restore, OnRestore)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest4View construction/destruction

CTest4View::CTest4View()
{
	// TODO: add construction code here

}

CTest4View::~CTest4View()
{
}

BOOL CTest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest4View drawing

void CTest4View::OnDraw(CDC* pDC)
{
	CTest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	this->ReadPoint();
	CP2 *p = new CP2[4];
	p[0] = P[0];
	p[1] = P[1];
	p[2] = P[2];
	p[3] = P[3];
	trans.SetMat(p,4);  //���ó�ʼ����ͼ��

	this->DrawObject(pDC);
//	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CTest4View printing

BOOL CTest4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest4View diagnostics

#ifdef _DEBUG
void CTest4View::AssertValid() const
{
	CView::AssertValid();
}

void CTest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest4Doc* CTest4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest4Doc)));
	return (CTest4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest4View message handlers

void CTest4View::ReadPoint()
{
	P[0].x = -150;
	P[0].y = -100;
	P[1].x = 150;
	P[1].y = -100;
	P[2].x = 150;
	P[2].y = 100;
	P[3].x = -150;
	P[3].y = 100;
}

void CTest4View::OnDown() 
{
	// TODO: Add your command handler code here
	trans.Translate(0,-10);
//	Invalidate(false);      //������������ֱ�ӻ�
	DoubleBuffer();  //˫����
	
}

void CTest4View::OnLeft() 
{
	// TODO: Add your command handler code here
	trans.Translate(-10,0);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnRight() 
{
	// TODO: Add your command handler code here
	trans.Translate(10,0);
    DoubleBuffer();  //˫����
}

void CTest4View::OnUp() 
{
	// TODO: Add your command handler code here
	trans.Translate(0,10);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnIncrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(1.5,1.5);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnDecrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(0.5,0.5);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnClockwise() 
{
	// TODO: Add your command handler code here
	CP2 p =(P[0]+P[2])/2;
	trans.Rotate(-30,p);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnAntiCLockwise() 
{
	// TODO: Add your command handler code here
	CP2 p = (P[0]+P[2])/2;
	trans.Rotate(30,p);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnXaxis() 
{
	// TODO: Add your command handler code here
	trans.ReflectX();
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnYaxis() 
{
	// TODO: Add your command handler code here
	trans.ReflectY();
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnOrg() 
{
	// TODO: Add your command handler code here
	trans.ReflectOrg();
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnXDirectionPlus() 
{
	// TODO: Add your command handler code here
	trans.Shear(0,1);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnXDirectionNeg() 
{
	// TODO: Add your command handler code here
	trans.Shear(0,-1);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnYDirectionPlus() 
{
	// TODO: Add your command handler code here
	trans.Shear(1,0);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnYDirectionNeg() 
{
	// TODO: Add your command handler code here
	trans.Shear(-1,0);
//	Invalidate(false);
	DoubleBuffer();  //˫����
}

void CTest4View::OnRestore()    //ͼ�θ�ԭ
{
	// TODO: Add your command handler code here
	this->ReadPoint();
	CP2 *p = new CP2[4];
	p[0] = P[0];
	p[1] = P[1];
	p[2] = P[2];
	p[3] = P[3];
	trans.SetMat(p,4);  //���ó�ʼ����ͼ��
	DoubleBuffer();  //˫����
}

void CTest4View::DoubleBuffer()//˫����
{
	
	CRect rect;//����ͻ���
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	CDC *pDC=GetDC();    
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//��Ļ����Ϊԭ��

	CDC MemDC;//�ڴ�DC
	CBitmap NewBitmap,*pOldBitmap;//�ڴ��г���ͼ�����ʱλͼ
	MemDC.CreateCompatibleDC(pDC);//��������ĻpDC���ݵ�MemDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//��������λͼ 
	pOldBitmap=MemDC.SelectObject(&NewBitmap); //������λͼѡ��MemDC 
	MemDC.FillSolidRect(&rect,pDC->GetBkColor());//��ԭ���������ͻ����������Ǻ�ɫ 
	MemDC.SetMapMode(MM_ANISOTROPIC);//MemDC�Զ�������ϵ

	MemDC.SetWindowExt(rect.Width(),rect.Height());
	MemDC.SetViewportExt(rect.Width(),-rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
		
	DrawPolygon(&MemDC);   //���任���ͼ�δ����ڴ�MemDC��
	
	pDC->BitBlt(-rect.Width()/2,-rect.Height()/2,rect.Width(),rect.Height(),&MemDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//���ڴ�λͼ��������Ļ
	MemDC.SelectObject(pOldBitmap);//�ָ�λͼ
	NewBitmap.DeleteObject();//ɾ��λͼ
	ReleaseDC(pDC);//�ͷ�DC
	
}

void CTest4View::DrawObject(CDC *pDC){  //���Ƴ�ʼ��ͼ���Լ�������

	GetClientRect (&rect);
	pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);

	CLine *line = new CLine;
	CP2 t;
	for(int i=0;i<4;i++){
		if(i==0){
			line->MoveTo(pDC,trans.POld[i]);
			t = P[i];
		}else{
			line->LineTo(pDC,trans.POld[i]);
		}
	}
	line->LineTo(pDC,t);//�γɱպ�ͼ��
	//����������
	CP2 a,b,c,d;
	a.x = b.x = 0;
	a.y = rect.Height()/2;
	b.y = -rect.Height()/2;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,b);
	c.y = d.y = 0;
	c.x = -rect.Width()/2;
	d.x = rect.Width()/2;
	line->MoveTo(pDC,c);
	line->LineTo(pDC,d);

	delete line;
}

void CTest4View::DrawPolygon(CDC *pDC){ //���Ʊ任���ͼ��

	CLine *line = new CLine;
	CP2 t;
	for(int i=0;i<4;i++){
		if(i==0){
			line->MoveTo(pDC,trans.POld[i]);
			t = trans.POld[i];
		}else{
			line->LineTo(pDC,trans.POld[i]);
		}
	}
	line->LineTo(pDC,t);//�γɱպ�ͼ��
	//����������
	CP2 a,b,c,d;
	a.x = b.x = 0;
	a.y = rect.Height()/2;
	b.y = -rect.Height()/2;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,b);
	c.y = d.y = 0;
	c.x = -rect.Width()/2;
	d.x = rect.Width()/2;
	line->MoveTo(pDC,c);
	line->LineTo(pDC,d);

	delete line;
}


