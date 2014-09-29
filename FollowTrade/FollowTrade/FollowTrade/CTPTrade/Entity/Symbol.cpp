#include "stdafx.h"
#include "Symbol.h"

CSymbol::CSymbol()
	:m_dContractSize(0),
	m_dTickSize(0),
	m_dMaxVolume(0),
	m_dMinVolume(0),
	m_dVolumeStep(0),
	m_dLongMarginRate(0),
	m_dShortMarginRate(0),
	m_dUpperLimitPrice(0),
	m_dLowerLimitPrice(0)
{
}

CSymbol::~CSymbol()
{
}

//============Assign============//
void CSymbol::Assign(IN const CSymbol &Symbol)
{
	SetSymbol(Symbol.GetSymbol());
	SetExchangeName(Symbol.GetExchangeName());
	SetContractSize(Symbol.GetContractSize());
	SetTickSize(Symbol.GetTickSize());
	SetMaxVolume(Symbol.GetMaxVolume());
	SetMinVolume(Symbol.GetMinVolume());
	SetVolumeStep(Symbol.GetVolumeStep());
	SetLongMarginRate(Symbol.GetLongMarginRate());
	SetShortMarginRate(Symbol.GetShortMarginRate());
	SetUpperLimitPrice(Symbol.GetUpperLimitPrice());
	SetLowerLimitPrice(Symbol.GetLowerLimitPrice());
}

void CSymbol::Clear()
{
	CSymbol Symbol;
	Assign(Symbol);
}

//============Mumber============//
void CSymbol::SetSymbol(IN string strSymbol)
{
	m_strSymbol = strSymbol;
}

string CSymbol::GetSymbol() const
{
	return m_strSymbol;
}

void CSymbol::SetExchangeName(IN string strExchangeName)
{
	m_strExchangeName = strExchangeName;
}

string CSymbol::GetExchangeName() const
{
	return m_strExchangeName;
}

void CSymbol::SetContractSize(IN double dContractSize)
{
	m_dContractSize = dContractSize;
}

double CSymbol::GetContractSize() const
{
	return m_dContractSize;
}

void CSymbol::SetTickSize(IN double dTickSize)
{
	m_dTickSize = dTickSize;
}

double CSymbol::GetTickSize() const
{
	return m_dTickSize;
}

void CSymbol::SetMaxVolume(IN double dMaxVolume)
{
	m_dMaxVolume = dMaxVolume;
}

double CSymbol::GetMaxVolume() const
{
	return m_dMaxVolume;
}

void CSymbol::SetMinVolume(IN double dMinVolume)
{
	m_dMinVolume = dMinVolume;
}

double CSymbol::GetMinVolume() const
{
	return m_dMinVolume;
}

void CSymbol::SetVolumeStep(IN double dVolumeStep)
{
	m_dVolumeStep = dVolumeStep;
}

double CSymbol::GetVolumeStep() const
{
	return m_dVolumeStep;
}

void CSymbol::SetLongMarginRate(IN double dLongMarginRate)
{
	m_dLongMarginRate = dLongMarginRate;
}

double CSymbol::GetLongMarginRate() const
{
	return m_dLongMarginRate;
}

void CSymbol::SetShortMarginRate(IN double dShortMarginRate)
{
	m_dShortMarginRate = dShortMarginRate;
}

double CSymbol::GetShortMarginRate() const
{
	return m_dShortMarginRate;
}

void CSymbol::SetUpperLimitPrice(IN double dUpperLimitPrice)
{
	m_dUpperLimitPrice = dUpperLimitPrice;
}

double CSymbol::GetUpperLimitPrice() const
{
	return m_dUpperLimitPrice;
}

void CSymbol::SetLowerLimitPrice(IN double dLowerLimitPrice)
{
	m_dLowerLimitPrice = dLowerLimitPrice;
}

double CSymbol::GetLowerLimitPrice() const
{
	return m_dLowerLimitPrice;
}