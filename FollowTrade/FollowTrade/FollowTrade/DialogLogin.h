#pragma once
#include "CTPTrade/Trade.h"
#include "FollowParamter.h"
#include "TradeState.h"
#include "CTPTrade/Common/Common.h"
#include "CTPTrade/Thread/Thread.h"
#include "MessageAPI.h"

// CDialogLogin dialog

class CDialogLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogLogin)

public:
	CDialogLogin(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogLogin();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private://MyMember
	CTradeState *m_pTradeState;
	CTrade *m_pTrader;
	CTrade *m_pFollower;
	FollowParamter m_FollowParamter;
private://thread of messages processing
	static UINT __stdcall ProcessThreadWrapper(IN LPVOID param);
	void ProcessThread(void);
private://thread of messages processing
	CThread m_Thread;	
	volatile long m_Thread_workflag;	//flag of processing thread
private://MyFunction
	void DisableAllWindow();
	void Clear();
	void ControlLoginButton(IN CString csTest, IN bool bEnable);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheckReverse();
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonExtend();
};
