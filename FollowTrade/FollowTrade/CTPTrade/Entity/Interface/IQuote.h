#pragma once
#include "Entity/Entity.h"

class IQuote
{
public:
	IQuote() {};
	virtual ~IQuote() {};

public://Interface
	virtual void OnTick(const CThostFtdcDepthMarketDataField *pDepthMarketData) {};

};