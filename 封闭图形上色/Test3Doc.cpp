// Test3Doc.cpp : implementation of the CTest3Doc class
//

#include "stdafx.h"
#include "Test3.h"

#include "Test3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest3Doc

IMPLEMENT_DYNCREATE(CTest3Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest3Doc, CDocument)
	//{{AFX_MSG_MAP(CTest3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest3Doc construction/destruction

CTest3Doc::CTest3Doc()
{
	// TODO: add one-time construction code here

}

CTest3Doc::~CTest3Doc()
{
}

BOOL CTest3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest3Doc serialization

void CTest3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTest3Doc diagnostics

#ifdef _DEBUG
void CTest3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest3Doc commands
