#include "stdafx.h"
#include "Order.h"

COrder::COrder()
	:m_nOrderID(0),
	m_dVolume(0),
	m_dInitVolume(0),
	m_dRemainVolume(0),
	m_dPrice(0),
	m_dSLPrice(0),
	m_dTPPrice(0),
	m_lInsertTime(0),
	m_bIsCloseYesterday(false),
	m_nFrontID(0),
	m_nSession(0),
	m_eType(EOrderType::OrderTypeInvalid),
	m_eAction(EOrderAction::OrderActionInvalid),
	m_eFlags(EOrderFlags::OrderFlagsInvalid),
	m_eStatus(EOrderStatus::OrderStatusInvalid),
	m_eResult(EOrderResult::OrderResultInvalid)
{
}

COrder::~COrder()
{
}

//============Assign============//
void COrder::Assign( const IOrder &Order)
{
	SetOrderID(Order.GetOrderID());
	SetSymbol(Order.GetSymbol());
	SetOrderLocalID(Order.GetOrderLocalID());
	SetVolume(Order.GetVolume());
	SetInitVolume(Order.GetInitVolume());
	SetRemaindVolume(Order.GetRemaindVolume());
	SetPrice(Order.GetPrice());
	SetSLPrice(Order.GetSLPrice());
	SetTPPrice(Order.GetTPPrice());
	SetInsertTime(Order.GetInsertTime());
	SetType(Order.GetType());
	SetAction(Order.GetAction());
	SetFlags(Order.GetFlags());
	SetStatus(Order.GetStatus());
	SetResult(Order.GetResult());
}

void COrder::Clear()
{
	COrder Order;
	Assign(Order);
}

//============Mumber============//
void COrder::SetOrderID( int nOrderID)
{
	m_nOrderID = nOrderID;
}

int COrder::GetOrderID() const
{
	return m_nOrderID;
}

void COrder::SetSymbol( string strSymbol)
{
	m_strSymbol = strSymbol;
}

string COrder::GetSymbol() const
{
	return m_strSymbol;
}

void COrder::SetOrderLocalID(string strOrderLocalID)
{
	m_strOrderLocalID = strOrderLocalID;
}

string COrder::GetOrderLocalID() const
{
	return m_strOrderLocalID;
}

void COrder::SetVolume( double dVolume)
{
	m_dVolume = dVolume;
}

double COrder::GetVolume() const
{
	return m_dVolume;
}

void COrder::SetInitVolume( double dInitVolume)
{
	m_dInitVolume = dInitVolume;
}

double COrder::GetInitVolume() const
{
	return m_dInitVolume;
}

void COrder::SetRemaindVolume( double dRemaindVolume)
{
	m_dRemainVolume = dRemaindVolume;
}

double COrder::GetRemaindVolume() const
{
	return m_dRemainVolume;
}

void COrder::SetPrice( double dPrice)
{
	m_dPrice = dPrice;
}

double COrder::GetPrice() const
{
	return m_dPrice;
}

void COrder::SetSLPrice( double dSLPrice)
{
	m_dSLPrice = dSLPrice;
}

double COrder::GetSLPrice() const
{
	return m_dSLPrice;
}

void COrder::SetTPPrice( double dTPPrice)
{
	m_dTPPrice = dTPPrice;
}

double COrder::GetTPPrice() const
{
	return m_dTPPrice;
}

void COrder::SetInsertTime( long long lInsertTime)
{
	m_lInsertTime = lInsertTime;
}

long long COrder::GetInsertTime() const
{
	return m_lInsertTime;
}

void COrder::SetIsCloseYesterday( bool bIsCloseYesterday)
{
	m_bIsCloseYesterday = bIsCloseYesterday;
}

bool COrder::GetIsCloseYesterday() const
{
	return m_bIsCloseYesterday;
}

void COrder::SetFrontID( int nFrontID)
{
	m_nFrontID = nFrontID;
}

int COrder::GetFrontID() const
{
	return m_nFrontID;
}

void COrder::SetSession( int nSession)
{
	m_nSession = nSession;
}

int COrder::GetSession() const
{
	return m_nSession;
}

void COrder::SetComment( string strComment)
{
	m_strComment = strComment;
}

string COrder::GetComment() const
{
	return m_strComment;
}

void COrder::SetType( EOrderType eType)
{
	m_eType = eType;
}

COrder::EOrderType  COrder::GetType() const
{
	return m_eType;
}

void COrder::SetAction( EOrderAction eAction)
{
	m_eAction = eAction;
}

COrder::EOrderAction COrder::GetAction() const
{
	return m_eAction;
}

void COrder::SetFlags( EOrderFlags eFlags)
{
	m_eFlags = eFlags;
}

COrder::EOrderFlags COrder::GetFlags() const
{
	return m_eFlags;
}

void COrder::SetStatus( EOrderStatus eStatus)
{
	m_eStatus = eStatus;
}

COrder::EOrderStatus COrder::GetStatus() const
{
	return m_eStatus;
}

void COrder::SetResult( EOrderResult eResult)
{
	m_eResult = eResult;
}

COrder::EOrderResult COrder::GetResult() const
{
	return m_eResult;
}