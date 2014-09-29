#pragma once
#include "../../CTPAPI/ThostFtdcUserApiStruct.h"

class ITrade
{
public:
	ITrade() {};
	virtual ~ITrade() {};

public://interface
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) {};
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) {};

};