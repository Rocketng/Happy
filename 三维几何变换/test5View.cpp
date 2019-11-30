// test5View.cpp : implementation of the CTest5View class
//

#include "stdafx.h"
#include "test5.h"

#include "test5Doc.h"
#include "test5View.h"
#include "math.h"
#include "Line.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest5View

IMPLEMENT_DYNCREATE(CTest5View, CView)

BEGIN_MESSAGE_MAP(CTest5View, CView)
	//{{AFX_MSG_MAP(CTest5View)
	ON_COMMAND(Left, OnLeft)
	ON_COMMAND(Right, OnRight)
	ON_COMMAND(Up, OnUp)
	ON_COMMAND(Down, OnDown)
	ON_COMMAND(Front, OnFront)
	ON_COMMAND(Back, OnBack)
	ON_COMMAND(Increase, OnIncrease)
	ON_COMMAND(Decrease, OnDecrease)
	ON_COMMAND(Rxaxis, OnRxaxis)
	ON_COMMAND(Ryaxis, OnRyaxis)
	ON_COMMAND(Rzaxis, OnRzaxis)
	ON_COMMAND(Rxoy, OnRxoy)
	ON_COMMAND(Ryoz, OnRyoz)
	ON_COMMAND(Rxoz, OnRxoz)
	ON_COMMAND(Sxplus, OnSxplus)
	ON_COMMAND(Syplus, OnSyplus)
	ON_COMMAND(Szplus, OnSzplus)
	ON_COMMAND(Reset, OnReset)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest5View construction/destruction

CTest5View::CTest5View()
{
	// TODO: add construction code here

}

CTest5View::~CTest5View()
{
}

BOOL CTest5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View drawing

void CTest5View::OnDraw(CDC* pDC)
{
	CTest5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	this->ReadPoint();
	trans.SetMat(P,8);
	this->ReadFace();
	this->DrawObject(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View printing

BOOL CTest5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View diagnostics

#ifdef _DEBUG
void CTest5View::AssertValid() const
{
	CView::AssertValid();
}

void CTest5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest5Doc* CTest5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest5Doc)));
	return (CTest5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest5View message handlers

void CTest5View::ReadPoint()
{
	double a = 100;
	//顶点的三维坐标（x,y,z）
	P[0].x = 0;P[0].y = 0;P[0].z = 0;
	P[1].x = a;P[1].y = 0;P[1].z = 0;
	P[2].x = a;P[2].y = a;P[2].z = 0;
	P[3].x = 0;P[3].y = a;P[3].z = 0;
	P[4].x = 0;P[4].y = 0;P[4].z = a;
	P[5].x = a;P[5].y = 0;P[5].z = a;
	P[6].x = a;P[6].y = a;P[6].z = a;
	P[7].x = 0;P[7].y = a;P[7].z = a;
}

void CTest5View::ReadFace()
{
	F[0].SetNum(4);
	F[0].vI[0] = 4;
	F[0].vI[1] = 5;
	F[0].vI[2] = 6;
	F[0].vI[3] = 7;   //前面

	F[1].SetNum(4);
	F[1].vI[0] = 0;
	F[1].vI[1] = 3;
	F[1].vI[2] = 2;
	F[1].vI[3] = 1;  //后面

	F[2].SetNum(4);
	F[2].vI[0] = 0;
	F[2].vI[1] = 4;
	F[2].vI[2] = 7;
	F[2].vI[3] = 3;  //左边

	F[3].SetNum(4);
	F[3].vI[0] = 1;
	F[3].vI[1] = 2;
	F[3].vI[2] = 6;
	F[3].vI[3] = 5;  //右边

	F[4].SetNum(4);
	F[4].vI[0] = 2;
	F[4].vI[1] = 3;
	F[4].vI[2] = 7;
	F[4].vI[3] = 6;  //顶面

	F[5].SetNum(4);
	F[5].vI[0] = 0;
	F[5].vI[1] = 1;
	F[5].vI[2] = 5;
	F[5].vI[3] = 4; //底面
}

void CTest5View::OnLeft() 
{
	// TODO: Add your command handler code here
	trans.Translate(-10,0,0);
	DoubleBuffer();
}

void CTest5View::OnRight() 
{
	// TODO: Add your command handler code here
	trans.Translate(10,0,0);
	DoubleBuffer();
}

void CTest5View::OnUp() 
{
	// TODO: Add your command handler code here
	trans.Translate(0,10,0);
	DoubleBuffer();
}

void CTest5View::OnDown() 
{
	// TODO: Add your command handler code here
	trans.Translate(0,-10,0);
	DoubleBuffer();
	
}

void CTest5View::OnFront() 
{
	// TODO: Add your command handler code here
	trans.Translate(0,0,10);
	DoubleBuffer();
}

void CTest5View::OnBack() 
{
	// TODO: Add your command handler code here
	trans.Translate(0,0,-10);
	DoubleBuffer();
}

void CTest5View::OnIncrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(2,2,2);
    DoubleBuffer();
}

void CTest5View::OnDecrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(0.5,0.5,0.5);
	DoubleBuffer();
}

void CTest5View::OnRxaxis() 
{
	// TODO: Add your command handler code here
	trans.Rotatex(30,P[0]);
	DoubleBuffer();
}

void CTest5View::OnRyaxis() 
{
	// TODO: Add your command handler code here
	trans.Rotatey(30,P[0]);
	DoubleBuffer();
}

void CTest5View::OnRzaxis() 
{
	// TODO: Add your command handler code here
	trans.Rotatez(30,P[0]);
	DoubleBuffer();
}

void CTest5View::OnRxoy() 
{
	// TODO: Add your command handler code here
	trans.ReflectXOY();
	DoubleBuffer();
}

void CTest5View::OnRyoz() 
{
	// TODO: Add your command handler code here
	trans.ReflectYOZ();
	DoubleBuffer();
}

void CTest5View::OnRxoz() 
{
	// TODO: Add your command handler code here
	trans.ReflactZOX();
	DoubleBuffer();
}

void CTest5View::OnSxplus() 
{
	// TODO: Add your command handler code here
	trans.ShearX(1,1);
	DoubleBuffer();
}

void CTest5View::OnSyplus() 
{
	// TODO: Add your command handler code here
	trans.ShearY(1,1);
	DoubleBuffer();
}

void CTest5View::OnSzplus() 
{
	// TODO: Add your command handler code here
	trans.ShearZ(1,1);
	DoubleBuffer();
}

void CTest5View::OnReset() 
{
	// TODO: Add your command handler code here
	this->ReadPoint();
	trans.SetMat(P,8);
	this->ReadFace();
	this->DoubleBuffer();	
}

void CTest5View::DoubleBuffer()//双缓冲
{
	
	CRect rect;//定义客户区
	GetClientRect(&rect);//获得客户区的大小
	CDC *pDC=GetDC();    
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//屏幕中心为原点

	CDC MemDC;//内存DC
	CBitmap NewBitmap,*pOldBitmap;//内存中承载图像的临时位图
	MemDC.CreateCompatibleDC(pDC);//建立与屏幕pDC兼容的MemDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//创建兼容位图 
	pOldBitmap=MemDC.SelectObject(&NewBitmap); //将兼容位图选入MemDC 
	MemDC.FillSolidRect(&rect,pDC->GetBkColor());//按原来背景填充客户区，否则是黑色 
	MemDC.SetMapMode(MM_ANISOTROPIC);//MemDC自定义坐标系

	MemDC.SetWindowExt(rect.Width(),rect.Height());
	MemDC.SetViewportExt(rect.Width(),-rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
		
	DrawPolygon(&MemDC);   //将变换后的图形存入内存MemDC中
	
	pDC->BitBlt(-rect.Width()/2,-rect.Height()/2,rect.Width(),rect.Height(),&MemDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//将内存位图拷贝到屏幕
	MemDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
	ReleaseDC(pDC);//释放DC
	
}

void CTest5View::ObliqueProject(CP3 p)
{
	ScreenP.x = p.x - p.z/sqrt(2);
	ScreenP.y = p.y - p.z/sqrt(2);
}

void CTest5View::DrawObject(CDC *pDC){  //绘制初始化图形以及坐标轴

	GetClientRect (&rect);
	pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);

	CLine *line = new CLine;
	/*
	CP2 t;
	for(int i=0;i<4;i++){
		if(i==0){
			line->MoveTo(pDC,trans.POld[i]);
			t = P[i];
		}else{
			line->LineTo(pDC,trans.POld[i]);
		}
	}
	line->LineTo(pDC,t);//形成闭合图形
	*/
	for(int i=0;i<6;i++){
		CP2 t;
		for(int j=0;j<4;j++){
			if(j==0){
				this->ObliqueProject(P[F[i].vI[j]]);
				line->MoveTo(pDC,ScreenP);
				t = ScreenP;
			}else{
				this->ObliqueProject(P[F[i].vI[j]]);
				line->LineTo(pDC,ScreenP);
			}
		}
		line->LineTo(pDC,t);
	}
	//绘制坐标线
	CP2 a,b,c,d;
	a.x = 0;
	a.y = 0;
	b.x = 0;
	b.y = rect.Height()/2;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,b);
	c.x = rect.Width()/2;
	c.y = 0;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,c);
	d.x = -rect.Height()/2;
	d.y = -rect.Height()/2;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,d);
	delete line;
}

void CTest5View::DrawPolygon(CDC *pDC){ //绘制变换后的图形

	CLine *line = new CLine;
	for(int i=0;i<6;i++){
		CP2 t;
		for(int j=0;j<4;j++){
			if(j==0){
				this->ObliqueProject(P[F[i].vI[j]]);
				line->MoveTo(pDC,ScreenP);
				t = ScreenP;
			}else{
				this->ObliqueProject(P[F[i].vI[j]]);
				line->LineTo(pDC,ScreenP);
			}
		}
		line->LineTo(pDC,t);
	}
	
	//绘制坐标线
	CP2 a,b,c,d;
	a.x = 0;
	a.y = 0;
	b.x = 0;
	b.y = rect.Height()/2;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,b);
	c.x = rect.Width()/2;
	c.y = 0;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,c);
	d.x = -rect.Height()/2;
	d.y = -rect.Height()/2;
	line->MoveTo(pDC,a);
	line->LineTo(pDC,d);

	delete line;
}


