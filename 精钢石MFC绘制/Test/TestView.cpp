// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(IDM_DRAWPIC, OnDrawpic)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::OnDrawpic() 
{
	// TODO: Add your command handler code here
	CInputDlg dlg;
	if(IDOK==dlg.DoModal()){   //���öԻ���ģ�飬�ж��Ƿ񵥻�OK��ť
		n = dlg.m_n;           //�ȷֵ����
		r = dlg.m_r;           //rΪԲ�İ뾶
	}else return;
	RedrawWindow();   //�ػ洰��
	P = new CP2[n];   //��̬����һλ����
	Diamond();        //���û��ƽ��ʯͼ������
	delete []P;       //�ͷ������ڴ�ռ�
	
}

void CTestView::Diamond()
{
	CDC * pDC = GetDC();    //�����豸������ָ��
	CRect rect;             //������ζ���
	GetClientRect(&rect);  //��ÿͻ������εĴ�С
	pDC->SetMapMode(MM_ANISOTROPIC);    //�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());   //���ô��ڱ���
	pDC->SetViewportExt(rect.Width(),-rect.Height());  //����������������Y������
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2); //���ÿͻ�����������Ϊ����ԭ��
	
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);   //������ͻ����غ�
	CPen NewPen,* pOldPen;   //���廭��
	NewPen.CreatePen(PS_SOLID,1,RGB(0,255,0));   //������ɫ����
	pOldPen = pDC->SelectObject(&NewPen);  //����ɫ����ѡ���豸������

	double Alpha,Theta;        //������ʯͼ������ʼ�Ǻ͵ȷֽ�
	Theta = 2*PI/n;            //�ȷֽ�
	Alpha = PI/2-Theta;        //��ʼ��
	
	for(int i=0;i<n;i++){      //����ȷֵ�����
		P[i].x = r*cos(i*Theta+Alpha);
		P[i].y = r*sin(i*Theta+Alpha);
	}
	for(i=0;i<=n-2;i++){   //�������Ӹ��ȷֵ�
		for(int j=i+1;j<=n-1;j++){
			pDC->MoveTo(Round(P[i].x),Round(P[i].y));
			pDC->LineTo(Round(P[j].x),Round(P[j].y));
		}
	}

	pDC->SelectObject(pOldPen);  //�ָ��豸�������е�ԭ����    
	NewPen.DeleteObject();       //ɾ���ѳ�����״̬�Ļ���
	ReleaseDC(pDC);              //�ͷ��豸������ָ��

}
