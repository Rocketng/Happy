// Test3.h : main header file for the TEST3 application
//

#if !defined(AFX_TEST3_H__8E7351BE_59B3_43A8_8C20_D1B3B789805F__INCLUDED_)
#define AFX_TEST3_H__8E7351BE_59B3_43A8_8C20_D1B3B789805F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest3App:
// See Test3.cpp for the implementation of this class
//

class CTest3App : public CWinApp
{
public:
	CTest3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST3_H__8E7351BE_59B3_43A8_8C20_D1B3B789805F__INCLUDED_)
