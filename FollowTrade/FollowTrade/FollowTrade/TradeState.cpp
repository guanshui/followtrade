#include "stdafx.h"
#include "TradeState.h"


CTradeState::CTradeState()
	:m_pTrader(NULL), m_pFollower(NULL), m_pFollowParamter(NULL)
{
}

CTradeState::~CTradeState()
{

}

void CTradeState::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	if (NULL != pOrder && NULL != m_pTrader && !m_pTrader->GetInvestorID().compare(pOrder->InvestorID))
	{
		Follow(*pOrder);
	}
}

void CTradeState::OnRtnTrade(CThostFtdcTradeField *pTrade)
{

}

bool CTradeState::SetTrade(IN CTrade *pTrader, IN CTrade *pFollower, IN PFollowParamter pFollowParamter)
{

	if (NULL == pTrader  || NULL == pFollower || NULL == pFollowParamter)
	{
		CMessageAPI::TradeObjectError();
		return false;
	}

	if (true != InitUsedOrder(pTrader))
	{
		return false;
	}

	m_pTrader = pTrader;
	m_pFollower = pFollower;
	m_pFollowParamter = pFollowParamter;

	return true;
}

bool CTradeState::IsInvalidOrderStatus(IN IOrder::EOrderStatus OrderStatus)
{
	bool bResult(true);

	switch (OrderStatus)
	{
	case IOrder::OrderStatusSubmitted:
	case IOrder::OrderStatusAccepted:
	case IOrder::OrderStatusDonePartial:
		{
			bResult = false;
		}
		break;
	default:
		break;
	}

	return bResult;
}

bool CTradeState::IsUsedOrder(IN CThostFtdcOrderField OrderField)
{
	for (vector<UsedOrder>::iterator itUsedOrder = m_vecUsedOrder.begin(); m_vecUsedOrder.end() != itUsedOrder; ++itUsedOrder)
	{
		if (itUsedOrder->nFrontID == OrderField.FrontID
			&& itUsedOrder->nSessionID == OrderField.SessionID
			&& itUsedOrder->nOrderRef == atoi(OrderField.OrderRef))
		{
			return true;
		}
	}

	UsedOrder UsedParamter;
	ZeroMemory(&UsedParamter, sizeof(UsedParamter));

	UsedParamter.nFrontID = OrderField.FrontID;
	UsedParamter.nSessionID = OrderField.SessionID;
	UsedParamter.nOrderRef = atoi(OrderField.OrderRef);

	m_vecUsedOrder.push_back(UsedParamter);

	return false;
}

bool CTradeState::InitUsedOrder(IN CTrade *pTrader)
{
	if (NULL == pTrader)
	{
		return false;
	}

	CMessageAPI::InitingUsedOrder();
	
	vector<COrder> vecTraderOrder;

	if (true != pTrader->GetOrder(vecTraderOrder))
	{
		CMessageAPI::GetTraderOrderError();
		return false;
	}

	for (vector<COrder>::iterator itOrder = vecTraderOrder.begin(); vecTraderOrder.end() != itOrder; ++itOrder)
	{
		UsedOrder usedOrder;
		ZeroMemory(&usedOrder, sizeof(usedOrder));

		usedOrder.nFrontID = itOrder->GetFrontID();
		usedOrder.nSessionID = itOrder->GetSession();
		usedOrder.nOrderRef = itOrder->GetOrderID();

		m_vecUsedOrder.push_back(usedOrder);
	}

	CMessageAPI::InitUsedOrderSuccess();

	return true;
}

bool CTradeState::Log_InsertOrder(IN COrder InOrder)
{
	char Info[1000] = {0};
	string strOrderType(" ");
	string strOrderFlags(" ");

	switch (InOrder.GetType())
	{
	case IOrder::OrderTypeBuy:
		{
			strOrderType = " 买……";
		}
		break;
	case IOrder::OrderTypeSell:
		{
			strOrderType = " 卖……";
		}
		break;
	default:
		break;
	}

	switch (InOrder.GetFlags())
	{
	case IOrder::OrderFlagsOpen:
		{
			strOrderFlags = " 开仓,";
		}
		break;
	case IOrder::OrderFlagsClose:
		{
			strOrderFlags = "平仓,";
		}
		break;
	default:
		break;
	}
	
	sprintf_s(Info, "报单信息::合约:%s, 报价:%.02f, 量:%.02f, ", 
		InOrder.GetSymbol().c_str(),
		InOrder.GetPrice(),
		InOrder.GetVolume());

	string strInfo(Info);
	strInfo += strOrderFlags + strOrderType;

	CMessageAPI::FollowInsertOrderInfo(strInfo.c_str());

	return true;
}

bool CTradeState::Log_DeleteOrder(IN COrder DelOrder)
{
	char Info[1000] = {0};

	sprintf_s(Info, "撤单信息::合约:%s, 本地单号:%d, 会话号:%d, 前置机号:%d",
		DelOrder.GetSymbol().c_str(),
		DelOrder.GetOrderID(),
		DelOrder.GetSession(),
		DelOrder.GetFrontID());

	CMessageAPI::FollowDeleteOrderInfo(Info);

	return true;
}

void CTradeState::Follow(IN CThostFtdcOrderField OrderField)
{
	if (NULL != m_pTrader && NULL != m_pFollower)
	{
		//TODO::根据下单的情况下单
		switch (OrderField.OrderSubmitStatus)
		{
		case THOST_FTDC_OSS_InsertSubmitted:
			{
				if (!IsUsedOrder(OrderField))
				{
					CMessageAPI::FollowingInsertOrder();
					InsertOrder(OrderField);
				}
			}
			break;
		default:
			break;
		}

		switch (OrderField.OrderStatus)
		{
		case THOST_FTDC_OST_PartTradedNotQueueing:	
		case THOST_FTDC_OST_NoTradeNotQueueing:
		case THOST_FTDC_OST_Canceled:
			{
				CMessageAPI::FollowingDeleteOrder();
				DeleteOrder(OrderField);
			}
			break;
		default:
			break;
		}
	}
}

bool CTradeState::InsertOrder(IN CThostFtdcOrderField OrderField)
{
	if (NULL != m_pFollower)
	{
		COrder InOrder;
		InOrder.SetOrderID(m_pFollower->GetOrderRef());
		InOrder.SetSymbol(OrderField.InstrumentID);
		InOrder.SetPrice(OrderField.LimitPrice);
		InOrder.SetVolume(OrderField.VolumeTotal);

		switch (OrderField.Direction)
		{//买/卖
		case THOST_FTDC_D_Buy:
			{
				if (m_pFollowParamter->isReverse)
				{
					InOrder.SetType(IOrder::OrderTypeSell);
				}
				else
				{
					InOrder.SetType(IOrder::OrderTypeBuy);
				}
			}
			break;
		case THOST_FTDC_D_Sell:
			{
				if (m_pFollowParamter->isReverse)
				{
					InOrder.SetType(IOrder::OrderTypeBuy);
				}
				else
				{
					InOrder.SetType(IOrder::OrderTypeSell);
				}
			}
			break;
		default:
			break;
		}

		if(THOST_FTDC_OF_Open == OrderField.CombOffsetFlag[0])
		{
			InOrder.SetFlags(IOrder::OrderFlagsOpen);
		}
		else
		{
			InOrder.SetFlags(IOrder::OrderFlagsClose);

			if (THOST_FTDC_OF_CloseToday == OrderField.CombOffsetFlag[0])
			{
				InOrder.SetIsCloseYesterday(false);
			}
			else
			{
				InOrder.SetIsCloseYesterday(true);
			}
		}

		//添加关系
		m_mapTradeRel[atoi(OrderField.OrderRef)] = InOrder.GetOrderID();

		Log_InsertOrder(InOrder);

		bool bSuccess = m_pFollower->OrderInsert(InOrder);

		CMessageAPI::SendInsertOrder(bSuccess);

		return bSuccess;
	}

	return false;
}

bool CTradeState::DeleteOrder(IN CThostFtdcOrderField OrderField)
{
	if (NULL != m_pFollower)
	{
		map<int, int>::iterator itTradeRel = m_mapTradeRel.find(atoi(OrderField.OrderRef));

		if (m_mapTradeRel.end() != itTradeRel)
		{
			COrder DelOrder;
			DelOrder.SetSymbol(OrderField.InstrumentID);
			DelOrder.SetOrderID(itTradeRel->second);
			DelOrder.SetFrontID(m_pFollower->GetFrontID());
			DelOrder.SetSession(m_pFollower->GetSessionID());

			Log_DeleteOrder(DelOrder);

			bool bSuccess = m_pFollower->OrderDelete(DelOrder);

			CMessageAPI::SendDeleteOrder(bSuccess);

			return bSuccess;
		}
	}

	return false;
}