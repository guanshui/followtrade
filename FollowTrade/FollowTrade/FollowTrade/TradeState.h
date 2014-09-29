#pragma once
#include "CTPTrade/Entity/Interface/ITrade.h"
#include "CTPTrade/Common/Common.h"
#include "CTPTrade/Trade.h"
#include "FollowParamter.h"
#include "MessageAPI.h"

class CTradeState: public ITrade
{
public:
	CTradeState();
	virtual ~CTradeState();

private://follow
	CTrade *m_pTrader;
	CTrade *m_pFollower;
	PFollowParamter m_pFollowParamter;

private:
	vector<UsedOrder> m_vecUsedOrder;	//Key:OrderRef
	map<int, int> m_mapTradeRel;		//Key:Trade.OrderRef

public://interface
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
	
public:
	bool SetTrade(IN CTrade *pTrader, IN CTrade *pFollower, IN PFollowParamter pFollowParamter);

private://
	bool IsInvalidOrderStatus(IN IOrder::EOrderStatus OrderStatus);
	bool IsUsedOrder(IN CThostFtdcOrderField OrderField);
	bool InitUsedOrder(IN CTrade *pTrader);
	bool Log_InsertOrder(IN COrder InOrder);
	bool Log_DeleteOrder(IN COrder DelOrder);

private://follow
	void Follow(IN CThostFtdcOrderField OrderField);
	bool InsertOrder(IN CThostFtdcOrderField OrderField);
	bool DeleteOrder(IN CThostFtdcOrderField OrderField);
};