// TestDialog.cpp : implementation file
//

#include "stdafx.h"
#include "FollowTrade.h"
#include "TestDialog.h"
#include "afxdialogex.h"


// CTestDialog dialog

IMPLEMENT_DYNAMIC(CTestDialog, CDialogEx)

CTestDialog::CTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDialog::IDD, pParent)
{

}

CTestDialog::~CTestDialog()
{
}

void CTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTestDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCL, &CTestDialog::OnBnClickedCancl)
END_MESSAGE_MAP()


// CTestDialog message handlers


BOOL CTestDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CTestDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CTestDialog::OnBnClickedCancl()
{
	// TODO: Add your control notification handler code here
	exit(0);
}
