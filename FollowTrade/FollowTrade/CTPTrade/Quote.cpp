#include "stdafx.h"
#include <iostream>
#include "Quote.h"


CQuote::CQuote(IQuote *pQuoteInterface /* = NULL */)
	:m_QuoteSPI(this),
	m_pQuoteInterface(pQuoteInterface)
{
}

CQuote::~CQuote()
{
}

///初始化
bool CQuote::Initialize(string strQuoteServer)
{
	return m_QuoteSPI.Initialize(strQuoteServer);
}

void CQuote::SetSymbol(const vector<CSymbol> &vecSymbol)
{
	m_QuoteSPI.SetSymbol(vecSymbol);
}

//=========CallBack=========//
//Tick回调事件
void CQuote::OnTick(const CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	if (NULL != pDepthMarketData)
	{
		if (NULL != m_pQuoteInterface)
		{
			m_pQuoteInterface->OnTick(pDepthMarketData);
		}

		//printf
		cout<<pDepthMarketData->InstrumentID <<":	" << pDepthMarketData->LastPrice << endl;
	}
}