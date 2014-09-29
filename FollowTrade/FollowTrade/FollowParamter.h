#pragma once

//跟随参数
typedef struct _FOLLOW_PARAMTER_
{
	bool isReverse;
}FollowParamter, *PFollowParamter;

//已经跟随的报单
typedef struct _USED_ORDER_
{
	int nFrontID;
	int nSessionID;
	int nOrderRef;
}UsedOrder, *PUsedOrder;

// Sleep(1010);
// vector<COrder> vecOrderTrade;
// int ntrade = m_pTrader->GetOrder(vecOrderTrade);
// 
// vector<COrder> vecOrder;	
// int nfollow = m_pFollower->GetOrder(vecOrder);
// COrder testOrder;
// testOrder.SetOrderID(m_pTrader->GetOrderRef());
// testOrder.SetSymbol("i1505");
// testOrder.SetFlags(IOrder::OrderFlagsOpen);
// testOrder.SetType(IOrder::OrderTypeSell);
// testOrder.SetPrice(580);
// testOrder.SetVolume(10);
// 
// int bResult = m_pTrader->OrderInsert(testOrder);
// 
// Sleep(2000);
// vector<COrder> vecOrderTrade2;
// int ntrade2 = m_pTrader->GetOrder(vecOrderTrade2);
// 
// vector<COrder> vecOrder2;	
// int nfollow2 = m_pFollower->GetOrder(vecOrder2);
// 
// COrder delOrder;
// delOrder.SetSymbol("i1505");
// delOrder.SetOrderID(testOrder.GetOrderID());
// delOrder.SetFrontID(m_pTrader->GetFrontID());
// delOrder.SetSession(m_pTrader->GetSessionID());
// 
// int bDelResult = m_pTrader->OrderDelete(delOrder);
// 
// Sleep(2000);
// vector<COrder> vecOrderTrade3;
// int ntrade3 = m_pTrader->GetOrder(vecOrderTrade3);
// 
// vector<COrder> vecOrder3;	
// int nfollow3 = m_pFollower->GetOrder(vecOrder3);