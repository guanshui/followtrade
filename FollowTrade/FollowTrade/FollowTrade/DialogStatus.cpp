// DialogStatus.cpp : implementation file
//

#include "stdafx.h"
#include "FollowTrade.h"
#include "DialogStatus.h"
#include "afxdialogex.h"
#include "ListHeade.h"

SListHeade StatusListHeade[] =
{
	{"时间",80},
	{"账户",80},
	{"消息",400},
};

// CDialogStatus dialog

IMPLEMENT_DYNAMIC(CDialogStatus, CDialogEx)

CDialogStatus::CDialogStatus(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogStatus::IDD, pParent)
{

}

CDialogStatus::~CDialogStatus()
{
}

void CDialogStatus::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogStatus, CDialogEx)
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
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDialogStatus message handlers


void CDialogStatus::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	CWnd *pStatusList = GetDlgItem(IDC_LIST_STATUS);
	if (NULL != pStatusList)
	{
		pStatusList->MoveWindow(0, 0, cx, cy);
	}
}


BOOL CDialogStatus::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	InitStatusList();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

bool CDialogStatus::InitStatusList()
{
	CListCtrl *pStatusList = (CListCtrl*)GetDlgItem(IDC_LIST_STATUS);
	if (NULL != pStatusList)
	{
		RECT ret = {0};
		GetClientRect(&ret);
		pStatusList->MoveWindow(&ret);

		pStatusList->ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
		pStatusList->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);

		for (int nIndex(0); sizeof(StatusListHeade)/sizeof(StatusListHeade[0]) > nIndex; ++nIndex)
		{
			pStatusList->InsertColumn(nIndex, StatusListHeade[nIndex].pString, LVCFMT_LEFT, StatusListHeade[nIndex].nWidth);
		}
	}

	return true;
}

//===============MessageFunction===============
LRESULT CDialogStatus::LoginError(WPARAM wParam,LPARAM lParam)
{
	char Message[1000] = {0};
	sprintf_s(Message, "%08d 登录错误……", (int)wParam);
	InsertMessageList(Message);
	return 0;
}

LRESULT CDialogStatus::Logining(WPARAM wParam,LPARAM lParam)
{
	char Message[1000] = {0};
	sprintf_s(Message, "%08d 正在登录……", (int)wParam);
	InsertMessageList(Message);

	return 0;
}

LRESULT CDialogStatus::LoginSuccess(WPARAM wParam,LPARAM lParam)
{
	char Message[1000] = {0};
	sprintf_s(Message, "%08d 登录成功……", (int)wParam);
	InsertMessageList(Message);
	return 0;
}

LRESULT CDialogStatus::BrokerEmpty(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("期货商ID不能为空……");
	return 0;
}

LRESULT CDialogStatus::TradeServerEmpty(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("交易服务器地址不能为空……");
	return 0;
}

LRESULT CDialogStatus::TraderInvestorIDEmpty(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("交易账户不能为空……");
	return 0;
}

LRESULT CDialogStatus::TraderPasswordEmpty(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("交易账户密码不能为空……");
	return 0;
}

LRESULT CDialogStatus::FollowerInvestorIDEmpty(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("跟随账户不能为空……");
	return 0;
}

LRESULT CDialogStatus::FollowerPasswordEmpty(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("跟随账户密码不能为空……");
	return 0;
}

LRESULT CDialogStatus::NewTradeStateError(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("申请跟随服务错误……");
	return 0;
}

LRESULT CDialogStatus::TraderLoginError(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("交易账户登录错误……");
	return 0;
}

LRESULT CDialogStatus::FollowerLoginError(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("跟随账户登录错误……");
	return 0;
}

LRESULT CDialogStatus::TradeObjectError(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("申请跟随对象错误……");
	return 0;
}

LRESULT CDialogStatus::InitingUsedOrder(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("正在初始化已跟随报单……");
	return 0;
}

LRESULT CDialogStatus::GetTraderOrderError(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("获取交易账户报单错误……");
	return 0;
}

LRESULT CDialogStatus::InitUsedOrderSuccess(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("初始化已跟随报单成功……");
	return 0;
}

LRESULT CDialogStatus::InitingFollowerOrder(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("正在初始化跟随账户报单……");
	return 0;
}

LRESULT CDialogStatus::GetFollowerOrderError(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("获取跟随账户报单……");
	return 0;
}

LRESULT CDialogStatus::InitFollowerOrderSuccess(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("初始化跟随账户报单成功……");
	return 0;
}

LRESULT CDialogStatus::FollowingInsertOrder(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("正在跟随报单……");
	return 0;
}

LRESULT CDialogStatus::FollowingDeleteOrder(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList("正在跟随撤单……");
	return 0;
}

LRESULT CDialogStatus::SendInsertOrder(WPARAM wParam,LPARAM lParam)
{
	char Message[1000] = {0};
	sprintf_s(Message, "发送报单%s……", (0 == (int)wParam) ?"失败":"成功");
	InsertMessageList(Message);
	return 0;
}

LRESULT CDialogStatus::SendDeleteOrder(WPARAM wParam,LPARAM lParam)
{
	char Message[1000] = {0};
	sprintf_s(Message, "发送撤单%s……", (0 == (int)wParam) ?"失败":"成功");
	InsertMessageList(Message);
	return 0;
}

LRESULT CDialogStatus::FollowInsertOrderInfo(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList((const char*)wParam);
	return 0;
}

LRESULT CDialogStatus::FollowDeleteOrderInfo(WPARAM wParam,LPARAM lParam)
{
	InsertMessageList((const char*)wParam);
	return 0;
}

//===============Function===============
void CDialogStatus::InsertMessageList(IN string strMessage)
{
	CTime CurrentTime = CTime::GetCurrentTime();

	CListCtrl *pStatusList = (CListCtrl*)GetDlgItem(IDC_LIST_STATUS);

	if (NULL != pStatusList)
	{
		int nIndex = pStatusList->GetItemCount();
		pStatusList->InsertItem(nIndex, CurrentTime.Format("%H:%M:%S"));
		pStatusList->SetItemText(nIndex, 2, strMessage.c_str());
		pStatusList->EnsureVisible(nIndex, FALSE); 
	}
}