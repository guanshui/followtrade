#pragma once
#include <string>
#include <vector>
#include "QuoteSPI.h"
#include "Entity/Entity.h"
#include "Entity/Interface/IQuote.h"

using namespace std;

class CQuote
{
public:
	CQuote(IQuote *pQuoteInterface = NULL);
	virtual ~CQuote();

public:
	///初始化
	bool Initialize(string strQuoteServer);
	//设置合约
	void SetSymbol(const vector<CSymbol> &vecSymbol);

public://CallBack
	//Tick回调事件
	void OnTick(const CThostFtdcDepthMarketDataField *pDepthMarketData);

private:
	CQuoteSPI m_QuoteSPI;	//行情SPI对象
private:
	IQuote *m_pQuoteInterface;
};