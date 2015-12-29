// scanerDlg.h : header file
//

#if !defined(AFX_SCANERDLG_H__42156582_AED7_4A88_9EB7_76EFDF5881CB__INCLUDED_)
#define AFX_SCANERDLG_H__42156582_AED7_4A88_9EB7_76EFDF5881CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScanerDlg dialog

class CScanerDlg : public CDialog
{
// Construction
public:
	CScanerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScanerDlg)
	enum { IDD = IDD_SCANER_DIALOG };
	CString	m_FilePath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScanerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScanerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCANERDLG_H__42156582_AED7_4A88_9EB7_76EFDF5881CB__INCLUDED_)
