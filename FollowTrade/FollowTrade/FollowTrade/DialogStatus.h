#pragma once
#include "MessageAPI.h"
#include <string>

using namespace std;


// CDialogStatus dialog

class CDialogStatus : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogStatus)

public:
	CDialogStatus(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogStatus();

// Dialog Data
	enum { IDD = IDD_DIALOG_STATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private://Message
	afx_msg LRESULT LoginError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT Logining(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT LoginSuccess(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT BrokerEmpty(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT TradeServerEmpty(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT TraderInvestorIDEmpty(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT TraderPasswordEmpty(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowerInvestorIDEmpty(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowerPasswordEmpty(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT NewTradeStateError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT TraderLoginError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowerLoginError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT TradeObjectError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT InitingUsedOrder(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT GetTraderOrderError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT InitUsedOrderSuccess(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT InitingFollowerOrder(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT GetFollowerOrderError(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT InitFollowerOrderSuccess(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowingInsertOrder(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowingDeleteOrder(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SendInsertOrder(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SendDeleteOrder(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowInsertOrderInfo(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT FollowDeleteOrderInfo(WPARAM wParam,LPARAM lParam);

private://Funcion
	void InsertMessageList(IN string strMessage);

private:
	bool InitStatusList();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
};
