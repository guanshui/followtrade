#pragma once
#include "MessageAPIStruct.h"

class CMessageAPI
{
public:
	enum MyMessage
	{
		WM_LoginError = WM_USER + 1,
		WM_Logining,
		WM_LogingSucess,
		WM_BrokerEmpty,
		WM_TradeServerEmpty,
		WM_TraderInvestorIDEmpty,
		WM_TraderPasswordEmpty,
		WM_FollowerInvestorIDEmpty,
		WM_FollowerPasswordEmpty,
		WM_NewTradeStateError,
		WM_TraderLoginError,
		WM_FollowerLoginError,
		WM_TradeObjectError,
		WM_InitingUsedOrder,
		WM_GetTraderOrderError,
		WM_InitUsedOrderSuccess,
		WM_InitingFollowerOrder,
		WM_GetFollowerOrderError,
		WM_InitFollowerOrderSuccess,
		WM_FollowingInsertOrder,
		WM_FollowingDeleteOrder,
		WM_SendInsertOrder,
		WM_SendDeleteOrder,
		WM_FollowInsertOrderInfo,
		WM_FollowDeleteOrderInfo,
	};
public:
	CMessageAPI();
	virtual ~CMessageAPI();

public://Trade Message
	static LRESULT LoginError(IN int nInvestorID);
	static LRESULT Logining(IN int nInvestorID);
	static LRESULT LoginSuccess(IN int nInvestorID);
	static LRESULT BrokerEmpty();
	static LRESULT TradeServerEmpty();
	static LRESULT TraderInvestorIDEmpty();
	static LRESULT TraderPasswordEmpty();
	static LRESULT FollowerInvestorIDEmpty();
	static LRESULT FollowerPasswordEmpty();
	static LRESULT NewTradeStateError();
	static LRESULT TraderLoginError();
	static LRESULT FollowerLoginError();
	static LRESULT TradeObjectError();
	static LRESULT InitingUsedOrder();
	static LRESULT GetTraderOrderError();
	static LRESULT InitUsedOrderSuccess();
	static LRESULT InitingFollowerOrder();
	static LRESULT GetFollowerOrderError();
	static LRESULT InitFollowerOrderSuccess();
	static LRESULT FollowingInsertOrder();
	static LRESULT FollowingDeleteOrder();
	static LRESULT SendInsertOrder(IN bool bSuccess);
	static LRESULT SendDeleteOrder(IN bool bSuccess);
	static LRESULT FollowInsertOrderInfo(IN const char *pInfo);
	static LRESULT FollowDeleteOrderInfo(IN const char *pInfo);
};