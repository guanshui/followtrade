#pragma once
#include "CTPAPI/ThostFtdcMdApi.h"
#include "CTPAPI/ThostFtdcUserApiDataType.h"
#include "CTPAPI/ThostFtdcUserApiStruct.h"
#include "Entity/Entity.h"
#include "Thread/Thread.h"
#include <vector>

using namespace std;

class CQuote;

class CQuoteSPI: public CThostFtdcMdSpi
{
public:
	CQuoteSPI(CQuote *pQuote);
	virtual ~CQuoteSPI();

public:
	///初始化
	bool Initialize(string strQuoteServer);

public:
	void SetSymbol(const vector<CSymbol> &vecSymbol);
	bool Subscribe();

private:
	///建立连接完成的响应事件
	void OnFrontConnected();
	///登录请求响应
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///深度行情通知
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

private://thread of messages processing
	static UINT __stdcall ProcessThreadWrapper(IN LPVOID param);
	void ProcessThread(void);
private://thread of messages processing
	CThread m_Thread;	
	volatile long m_Thread_workflag;	//flag of processing thread

private:
	vector<CSymbol> m_vecSymbol;
private:
	CQuote *m_pQuote;				//行情类
	CThostFtdcMdApi *m_pQuoteAPI;	//行情API
};
