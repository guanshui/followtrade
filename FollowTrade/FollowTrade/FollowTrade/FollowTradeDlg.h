
// FollowTradeDlg.h : header file
//

#pragma once
#include "CTPTrade/Trade.h"
#include "FollowParamter.h"
#include "TradeState.h"
#include "CTPTrade/Common/Common.h"
#include "DialogLogin.h"
#include "DialogStatus.h"
#include "TestDialog.h"
#include "MessageAPI.h"


// CFollowTradeDlg dialog
class CFollowTradeDlg : public CDialogEx
{
// Construction
public:
	CFollowTradeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FOLLOWTRADE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
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

private:
	CDialogLogin *m_pDialogLogin;
	CDialogStatus *m_pDialogStatus;
public:
	bool InitSubDialog();
	bool DeleteSubDialog();
	bool InitLoginDialog();
	bool InitStatusDialog();

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
