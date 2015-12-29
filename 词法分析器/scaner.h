// scaner.h : main header file for the SCANER application
//

#if !defined(AFX_SCANER_H__AC6C46C8_8C56_4AFD_8C2B_3E2057F21DF7__INCLUDED_)
#define AFX_SCANER_H__AC6C46C8_8C56_4AFD_8C2B_3E2057F21DF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScanerApp:
// See scaner.cpp for the implementation of this class
//

class CScanerApp : public CWinApp
{
public:
	CScanerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScanerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScanerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCANER_H__AC6C46C8_8C56_4AFD_8C2B_3E2057F21DF7__INCLUDED_)
