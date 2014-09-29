// DialogLogin.cpp : implementation file
//

#include "stdafx.h"
#include "FollowTrade.h"
#include "DialogLogin.h"
#include "afxdialogex.h"

const char *gpTradeServer = "tcp://sim-front1.ctp.shcifco.com:31205";
const char *gpQuoteServer = "tcp://140.206.102.161:41213";
const char *gpBrokerID = "1002";
const char *gpInvestorID = "00000005";
const char *gpPassword = "123456";


// CDialogLogin dialog

IMPLEMENT_DYNAMIC(CDialogLogin, CDialogEx)

CDialogLogin::CDialogLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogLogin::IDD, pParent),
	m_pTrader(NULL),
	m_pFollower(NULL),
	m_pTradeState(NULL)
{
	ZeroMemory(&m_FollowParamter, sizeof(m_FollowParamter));
}

CDialogLogin::~CDialogLogin()
{
}

void CDialogLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialogEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CHECK_REVERSE, &CDialogLogin::OnBnClickedCheckReverse)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CDialogLogin::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_EXTEND, &CDialogLogin::OnBnClickedButtonExtend)
END_MESSAGE_MAP()


// CDialogLogin message handlers


void CDialogLogin::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


BOOL CDialogLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//==============MyFunction==============
void CDialogLogin::DisableAllWindow()
{
	CWnd *pWndBrokerID = GetDlgItem(IDC_EDIT_BROKERID);
	if (NULL != pWndBrokerID)
	{
		pWndBrokerID->EnableWindow(FALSE);
	}

	CWnd *pWndTradeServer = GetDlgItem(IDC_EDIT_TRADESERVER);
	if (NULL != pWndTradeServer)
	{
		pWndTradeServer->EnableWindow(FALSE);
	}

	CWnd *pWndTradeLogin = GetDlgItem(IDC_EDIT_TRADELOGIN);
	if (NULL != pWndTradeLogin)
	{
		pWndTradeLogin->EnableWindow(FALSE);
	}

	CWnd *pWndTradePassword = GetDlgItem(IDC_EDIT_TRADEPASSWORD);
	if (NULL != pWndTradePassword)
	{
		pWndTradePassword->EnableWindow(FALSE);
	}

	CWnd *pWndFollowLogin = GetDlgItem(IDC_EDIT_FOLLOWLOGIN);
	if (NULL != pWndFollowLogin)
	{
		pWndFollowLogin->EnableWindow(FALSE);
	}

	CWnd *pWndFollowPassword = GetDlgItem(IDC_EDIT_FOLLOWPASSWORD);
	if (NULL != pWndFollowPassword)
	{
		pWndFollowPassword->EnableWindow(FALSE);
	}

	CWnd *pWndCheckReverse = GetDlgItem(IDC_CHECK_REVERSE);
	if (NULL != pWndCheckReverse)
	{
		pWndCheckReverse->EnableWindow(FALSE);
	}
}

void CDialogLogin::Clear()
{
	F_SafeDelete(m_pTradeState);
	F_SafeDelete(m_pTrader);
	F_SafeDelete(m_pFollower);
}

void CDialogLogin::ControlLoginButton(IN CString csTest, IN bool bEnable)
{
	CButton *pLoginButton = (CButton*)GetDlgItem(IDC_BUTTON_LOGIN);
	if (NULL != pLoginButton)
	{
		if (!csTest.IsEmpty())
		{
			pLoginButton->SetWindowText(csTest.GetString());
		}

		pLoginButton->EnableWindow(bEnable);
	}
}

void CDialogLogin::OnBnClickedCheckReverse()
{
	// TODO: Add your control notification handler code here

	m_FollowParamter.isReverse = BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_REVERSE);
}

void CDialogLogin::OnBnClickedButtonLogin()
{
	// TODO: Add your control notification handler code here

	m_Thread.Start(ProcessThreadWrapper, this, 262144);
}

//=========================thread=========================//
UINT __stdcall CDialogLogin::ProcessThreadWrapper(LPVOID param)
{
	CDialogLogin *pThis=reinterpret_cast<CDialogLogin*>(param);
	if(pThis!=NULL) pThis->ProcessThread();

	return 0;
}

void CDialogLogin::ProcessThread()
{
	ControlLoginButton("ÕýÔÚµÇÂ¼", false);

	Clear();

	CString csBrokerID;
	GetDlgItemText(IDC_EDIT_BROKERID, csBrokerID);
	//csBrokerID = gpBrokerID;
	if (csBrokerID.IsEmpty())
	{
		CMessageAPI::BrokerEmpty();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	CString csTradeServer;
	GetDlgItemText(IDC_EDIT_TRADESERVER, csTradeServer);
	csTradeServer = gpTradeServer;
	if (csTradeServer.IsEmpty())
	{
		CMessageAPI::TradeServerEmpty();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	CString csTraderInvestorID;
	GetDlgItemText(IDC_EDIT_TRADELOGIN, csTraderInvestorID);
	csTraderInvestorID = "00000034";
	if (csTraderInvestorID.IsEmpty())
	{
		CMessageAPI::TraderInvestorIDEmpty();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	CString csTraderPassword;
	GetDlgItemText(IDC_EDIT_TRADEPASSWORD, csTraderPassword);
	csTraderPassword = gpPassword;
	if (csTraderPassword.IsEmpty())
	{
		CMessageAPI::TraderPasswordEmpty();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	CString csFollowerInvestorID;
	GetDlgItemText(IDC_EDIT_FOLLOWLOGIN, csFollowerInvestorID);
	csFollowerInvestorID = "00000043";
	if (csFollowerInvestorID.IsEmpty())
	{
		CMessageAPI::FollowerInvestorIDEmpty();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	CString csFollowerPassword;
	GetDlgItemText(IDC_EDIT_FOLLOWPASSWORD, csFollowerPassword);
	csFollowerPassword = gpPassword;
	if (csFollowerPassword.IsEmpty())
	{
		CMessageAPI::FollowerPasswordEmpty();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	m_pTradeState = new CTradeState();
	if (NULL == m_pTradeState)
	{
		CMessageAPI::NewTradeStateError();
		ControlLoginButton("µÇÂ¼", true);
		return;
	}

	m_pTrader = new CTrade(m_pTradeState);

	if (NULL != m_pTrader)
	{
		if (true != m_pTrader->Initialize(csTradeServer.GetString(), csTraderInvestorID.GetString(), csTraderPassword.GetString(), csBrokerID.GetString()))
		{
			CMessageAPI::TraderLoginError();
			F_SafeDelete(m_pTrader);
			ControlLoginButton("µÇÂ¼", true);
			return;
		}
		else
		{
			CMessageAPI::LoginSuccess(atoi(m_pTrader->GetInvestorID().c_str()));

			{//ÊÔÓÃ°æ:ÊÔÓÃÊ±¼äÅÐ¶Ï
				string strDate = m_pTrader->GetLoginDate();

				if (20141019 < atoi(strDate.c_str()))
				{
					//ÊÔÓÃÆÚµ½ÁË
					exit(0);
				}

			}
		}
	}

	Sleep(1020);

	m_pFollower = new CTrade(m_pTradeState);

	if (NULL != m_pFollower)
	{
		if (true != m_pFollower->Initialize(csTradeServer.GetString(), csFollowerInvestorID.GetString(), csFollowerPassword.GetString(), csBrokerID.GetString()))
		{
			CMessageAPI::FollowerLoginError();
			F_SafeDelete(m_pFollower);
			ControlLoginButton("µÇÂ¼", true);
			return;
		}
		else
		{
			CMessageAPI::LoginSuccess(atoi(m_pFollower->GetInvestorID().c_str()));
		}
	}


	//ÉèÖÃ½»Ò×¶ÔÏó
	bool bSuccess = m_pTradeState->SetTrade(m_pTrader, m_pFollower, &m_FollowParamter);
	
	if (true == bSuccess)
	{
		ControlLoginButton("µÇÂ¼³É¹¦", false);
	}
	else
	{
		ControlLoginButton("µÇÂ¼", true);
	}
}

void CDialogLogin::OnBnClickedButtonExtend()
{
	// TODO: Add your control notification handler code here
}
