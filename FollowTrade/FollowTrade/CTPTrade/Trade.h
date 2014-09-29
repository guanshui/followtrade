#pragma once
#include "TradeSPI.h"
#include "Entity/Entity.h"
#include "Entity/Interface/ITrade.h"
#include <vector>

using namespace std;

class CTrade
{
public:
	CTrade(ITrade *pTradeInterface = NULL);
	virtual ~CTrade();

public://Initialize
	bool Initialize(const char *pTradeServer, const char *pTradeLogin, const char *pTradePassword, const char *pTradeBroker);

public://OnCallBack
	///报单录入请求响应
	void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单操作请求响应
	void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单录入错误回报
	void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	///报单操作错误回报
	void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	///报单通知
	void OnRtnOrder(CThostFtdcOrderField *pOrder);
	///成交通知
	void OnRtnTrade(CThostFtdcTradeField *pTrade);
	///错误应答
	void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

public://API
	bool OrderInsert(IN COrder &Order);
	bool OrderDelete(IN const COrder &Order);

public://Get/Set
	bool GetOrder(OUT vector<COrder> &vecOrder);
	bool GetPosition(OUT vector<CPosition> &vecPosition);
	bool GetAccount(OUT CAccount &Account);
	bool GetSymbol(IN map<string, CSymbol> &mapSymbol);
	int GetOrderRef();
	int GetFrontID();
	int GetSessionID();
	string GetInvestorID();
	string GetLoginTime();
	string GetLoginDate();

private://private
	bool IsErrorRspInfo(IN CThostFtdcRspInfoField *pRspInfo);

private:
	ITrade *m_pTradeInterface;

private:
	CTradeSPI m_TradeSPI;
};