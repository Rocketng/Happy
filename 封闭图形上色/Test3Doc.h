// Test3Doc.h : interface of the CTest3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST3DOC_H__198B275C_A571_4FB7_99E9_18C27157691E__INCLUDED_)
#define AFX_TEST3DOC_H__198B275C_A571_4FB7_99E9_18C27157691E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest3Doc : public CDocument
{
protected: // create from serialization only
	CTest3Doc();
	DECLARE_DYNCREATE(CTest3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST3DOC_H__198B275C_A571_4FB7_99E9_18C27157691E__INCLUDED_)
