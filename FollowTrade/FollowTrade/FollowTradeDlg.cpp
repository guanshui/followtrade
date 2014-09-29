
// FollowTradeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FollowTrade.h"
#include "FollowTradeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFollowTradeDlg dialog



CFollowTradeDlg::CFollowTradeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFollowTradeDlg::IDD, pParent),
	m_pDialogLogin(NULL),
	m_pDialogStatus(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CFollowTradeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFollowTradeDlg, CDialogEx)
	//MyMessage
	ON_MESSAGE(CMessageAPI::WM_LoginError, LoginError)
	ON_MESSAGE(CMessageAPI::WM_Logining, Logining)
	ON_MESSAGE(CMessageAPI::WM_LogingSucess, LoginSuccess)
	ON_MESSAGE(CMessageAPI::WM_BrokerEmpty, BrokerEmpty)
	ON_MESSAGE(CMessageAPI::WM_TradeServerEmpty, TradeServerEmpty)
	ON_MESSAGE(CMessageAPI::WM_TraderInvestorIDEmpty, TraderInvestorIDEmpty)
	ON_MESSAGE(CMessageAPI::WM_TraderPasswordEmpty, TraderPasswordEmpty)
	ON_MESSAGE(CMessageAPI::WM_FollowerInvestorIDEmpty, FollowerInvestorIDEmpty)
	ON_MESSAGE(CMessageAPI::WM_FollowerPasswordEmpty, FollowerPasswordEmpty)
	ON_MESSAGE(CMessageAPI::WM_NewTradeStateError, NewTradeStateError)
	ON_MESSAGE(CMessageAPI::WM_TraderLoginError, TraderLoginError)
	ON_MESSAGE(CMessageAPI::WM_FollowerLoginError, FollowerLoginError)
	ON_MESSAGE(CMessageAPI::WM_TradeObjectError, TradeObjectError)
	ON_MESSAGE(CMessageAPI::WM_InitingUsedOrder, InitingUsedOrder)
	ON_MESSAGE(CMessageAPI::WM_GetTraderOrderError, GetTraderOrderError)
	ON_MESSAGE(CMessageAPI::WM_InitUsedOrderSuccess, InitUsedOrderSuccess)
	ON_MESSAGE(CMessageAPI::WM_InitingFollowerOrder, InitingFollowerOrder)
	ON_MESSAGE(CMessageAPI::WM_GetFollowerOrderError, GetFollowerOrderError)
	ON_MESSAGE(CMessageAPI::WM_InitFollowerOrderSuccess, InitFollowerOrderSuccess)
	ON_MESSAGE(CMessageAPI::WM_FollowingInsertOrder, FollowingInsertOrder)
	ON_MESSAGE(CMessageAPI::WM_FollowingDeleteOrder, FollowingDeleteOrder)
	ON_MESSAGE(CMessageAPI::WM_SendInsertOrder, SendInsertOrder)
	ON_MESSAGE(CMessageAPI::WM_SendDeleteOrder, SendDeleteOrder)
	ON_MESSAGE(CMessageAPI::WM_FollowInsertOrderInfo, FollowInsertOrderInfo)
	ON_MESSAGE(CMessageAPI::WM_FollowDeleteOrderInfo, FollowDeleteOrderInfo)
	//MyMessage
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_WM_SIZE()
END_MESSAGE_MAP()


// CFollowTradeDlg message handlers

BOOL CFollowTradeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitSubDialog();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFollowTradeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFollowTradeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFollowTradeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFollowTradeDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	if (NULL != m_pDialogLogin)
	{
		m_pDialogLogin->MoveWindow(0, 0, 400, cy);
	}

	if (NULL != m_pDialogStatus)
	{
		m_pDialogStatus->MoveWindow(400, 0, cx - 400, cy);
	}
}

//===============MessageFunction===============
LRESULT CFollowTradeDlg::LoginError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_LoginError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::Logining(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_Logining, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::LoginSuccess(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_LogingSucess, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::BrokerEmpty(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_BrokerEmpty, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::TradeServerEmpty(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_TradeServerEmpty, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::TraderInvestorIDEmpty(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_TraderInvestorIDEmpty, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::TraderPasswordEmpty(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_TraderPasswordEmpty, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowerInvestorIDEmpty(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_FollowerInvestorIDEmpty, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowerPasswordEmpty(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_FollowerPasswordEmpty, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::NewTradeStateError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_NewTradeStateError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::TraderLoginError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_TraderLoginError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowerLoginError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_FollowerLoginError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::TradeObjectError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_TradeObjectError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::InitingUsedOrder(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_InitingUsedOrder, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::GetTraderOrderError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_GetTraderOrderError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::InitUsedOrderSuccess(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_InitUsedOrderSuccess, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::InitingFollowerOrder(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_InitingFollowerOrder, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::GetFollowerOrderError(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_GetFollowerOrderError, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::InitFollowerOrderSuccess(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_InitFollowerOrderSuccess, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowingInsertOrder(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_FollowingInsertOrder, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowingDeleteOrder(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_FollowingDeleteOrder, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::SendInsertOrder(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_SendInsertOrder, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::SendDeleteOrder(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->PostMessage(CMessageAPI::WM_SendDeleteOrder, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowInsertOrderInfo(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->SendMessage(CMessageAPI::WM_FollowInsertOrderInfo, wParam, lParam);
	}

	return 0;
}

LRESULT CFollowTradeDlg::FollowDeleteOrderInfo(WPARAM wParam,LPARAM lParam)
{
	if (NULL != m_pDialogStatus)
	{
		return m_pDialogStatus->SendMessage(CMessageAPI::WM_FollowDeleteOrderInfo, wParam, lParam);
	}

	return 0;
}

//===============MyFunction===============
bool CFollowTradeDlg::InitSubDialog()
{
	InitLoginDialog();
	InitStatusDialog();
	return true;
}

bool CFollowTradeDlg::DeleteSubDialog()
{
	if (NULL != m_pDialogLogin)
	{
		m_pDialogLogin->DestroyWindow();
		F_SafeDelete(m_pDialogLogin);
	}

	if (NULL != m_pDialogStatus)
	{
		m_pDialogStatus->DestroyWindow();
		F_SafeDelete(m_pDialogStatus);
	}

	return true;
}
bool CFollowTradeDlg::InitLoginDialog()
{
	if (NULL == m_pDialogLogin)
	{
		m_pDialogLogin = new CDialogLogin();
		m_pDialogLogin->Create(CDialogLogin::IDD, this);
		m_pDialogLogin->ShowWindow(SHOW_OPENWINDOW);

		RECT rtClient = {0};
		GetClientRect(&rtClient);
		m_pDialogLogin->MoveWindow(rtClient.left, rtClient.top, 400, rtClient.bottom);
	}

	return true;
}

bool CFollowTradeDlg::InitStatusDialog()
{
	if (NULL == m_pDialogStatus)
	{
		m_pDialogStatus = new CDialogStatus();
		m_pDialogStatus->Create(CDialogStatus::IDD, this);
		m_pDialogStatus->ShowWindow(SHOW_OPENWINDOW);

		RECT rtClient = {0};
		GetClientRect(&rtClient);
		m_pDialogStatus->MoveWindow(400, rtClient.top, rtClient.right - 400, rtClient.bottom);
	}

	return true;
}