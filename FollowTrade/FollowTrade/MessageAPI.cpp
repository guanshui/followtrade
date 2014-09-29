#include "stdafx.h"
#include "MessageAPI.h"

CMessageAPI::CMessageAPI()
{
}

CMessageAPI::~CMessageAPI()
{
}

LRESULT CMessageAPI::LoginError(IN int nInvestorID)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_LoginError, nInvestorID);
	}

	return 0;
}

LRESULT CMessageAPI::Logining(IN int nInvestorID)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_Logining, nInvestorID);
	}

	return 0;
}

LRESULT CMessageAPI::LoginSuccess(IN int nInvestorID)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_LogingSucess, nInvestorID);
	}

	return 0;
}

LRESULT CMessageAPI::BrokerEmpty()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_BrokerEmpty);
	}

	return 0;
}

LRESULT CMessageAPI::TradeServerEmpty()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_TradeServerEmpty);
	}

	return 0;
}

LRESULT CMessageAPI::TraderInvestorIDEmpty()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_TraderInvestorIDEmpty);
	}

	return 0;
}

LRESULT CMessageAPI::TraderPasswordEmpty()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_TraderPasswordEmpty);
	}

	return 0;
}

LRESULT CMessageAPI::FollowerInvestorIDEmpty()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_FollowerInvestorIDEmpty);
	}

	return 0;
}

LRESULT CMessageAPI::FollowerPasswordEmpty()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_FollowerPasswordEmpty);
	}

	return 0;
}

LRESULT CMessageAPI::NewTradeStateError()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_NewTradeStateError);
	}

	return 0;
}

LRESULT CMessageAPI::TraderLoginError()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_TraderLoginError);
	}

	return 0;
}

LRESULT CMessageAPI::FollowerLoginError()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_FollowerLoginError);
	}

	return 0;
}

LRESULT CMessageAPI::TradeObjectError()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_TradeObjectError);
	}

	return 0;
}

LRESULT CMessageAPI::InitingUsedOrder()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_InitingUsedOrder);
	}

	return 0;
}

LRESULT CMessageAPI::GetTraderOrderError()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_GetTraderOrderError);
	}

	return 0;
}

LRESULT CMessageAPI::InitUsedOrderSuccess()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_InitUsedOrderSuccess);
	}

	return 0;
}

LRESULT CMessageAPI::InitingFollowerOrder()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_InitingFollowerOrder);
	}

	return 0;
}

LRESULT CMessageAPI::GetFollowerOrderError()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_GetFollowerOrderError);
	}

	return 0;
}

LRESULT CMessageAPI::InitFollowerOrderSuccess()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_InitFollowerOrderSuccess);
	}

	return 0;
}

LRESULT CMessageAPI::FollowingInsertOrder()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_FollowingInsertOrder);
	}

	return 0;
}

LRESULT CMessageAPI::FollowingDeleteOrder()
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_FollowingDeleteOrder);
	}

	return 0;
}

LRESULT CMessageAPI::SendInsertOrder(IN bool bSuccess)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_SendInsertOrder, bSuccess);
	}

	return 0;
}

LRESULT CMessageAPI::SendDeleteOrder(IN bool bSuccess)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->PostMessage(WM_SendDeleteOrder, bSuccess);
	}

	return 0;
}

LRESULT CMessageAPI::FollowInsertOrderInfo(IN const char *pInfo)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->SendMessage(WM_FollowInsertOrderInfo, (WPARAM)pInfo, strlen(pInfo));
	}

	return 0;
}

LRESULT CMessageAPI::FollowDeleteOrderInfo(IN const char *pInfo)
{
	CWnd *pWnd = AfxGetApp()->m_pMainWnd;

	if (NULL != pWnd)
	{
		return pWnd->SendMessage(WM_FollowDeleteOrderInfo, (WPARAM)pInfo, strlen(pInfo));
	}

	return 0;
}
