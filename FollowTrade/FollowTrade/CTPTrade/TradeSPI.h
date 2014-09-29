#pragma once
#include "CTPAPI/ThostFtdcTraderApi.h"
#include "CTPAPI/ThostFtdcUserApiDataType.h"
#include "CTPAPI/ThostFtdcUserApiStruct.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <map>
#include <vector>
#include "Entity/Entity.h"
#include "Common/Common.h"

using namespace std;

class CTrade;

class CTradeSPI: public CThostFtdcTraderSpi
{
public:
	CTradeSPI(CTrade *pTrade);
	~CTradeSPI();

public://Initialize
	bool Initialize(const char *pTradeServer, const char *pTradeLogin, const char *pTradePassword, const char *pTradeBroker);

public://Event
	///建立连接完成的响应事件
	void OnFrontConnected();
	///断开连接的响应事件
	void OnFrontDisconnected(int nReason);
	///登录请求响应
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///登出请求响应
	void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///投资者结算结果确认响应
	void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单录入请求响应
	void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单操作请求响应
	void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单录入错误回报
	void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	///报单操作错误回报
	void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	///报单通知
	void OnRtnOrder(CThostFtdcOrderField *pOrder);
	///成交通知
	void OnRtnTrade(CThostFtdcTradeField *pTrade);
	///错误应答
	void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///请求查询合约响应
	void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///请求查询行情响应
	void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///请求查询报单响应
	void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///请求查询投资者持仓响应
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///请求查询资金账户响应
	void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

private://Common
	bool IsErrorRspInfo(IN CThostFtdcRspInfoField *pRspInfo);					//是否错误信息
	int GetRequestID();															//获取请求ID
	void SetOrderRef(IN int nOrderRef);											//设置报单引用
	string GetOrderRef();														//获取报单引用
	string GetCTPString(IN const char *pString, IN int nLength);				//因为CTP API不靠谱，不能直接赋值给string以免越界。

public://Request
	bool OrderInsert(IN COrder &Order);
	bool OrderDelete(IN const COrder &Order);

public://Get
	bool GetInstrument(IN vector<CThostFtdcInstrumentField> &vecInstrumentField);
	bool GetMarketData(IN vector<CThostFtdcDepthMarketDataField> &vecMarketDataField);
	bool GetSymbol(IN map<string, CSymbol> &mapSymbol);
	bool GetOrder(OUT vector<COrder> &vecOrder);
	bool GetPosition(OUT vector<CPosition> &vecPosition);
	bool GetAccount(OUT CAccount &Account);
	int GetOrderRef_Int();
	int GetFrontID();
	int GetSessionID();
	string GetInvestorID();
	string GetLoginTime();
	string GetLoginDate();

private://Fill
	bool FillSymbolByInstrument(OUT CSymbol &Symbol, IN const CThostFtdcInstrumentField &InstrumentField);
	bool FillSymbolByMarketData(OUT CSymbol &Symbol, IN const CThostFtdcDepthMarketDataField &MarketDataField);
	bool FillInputOrderFieldByOrder(OUT CThostFtdcInputOrderField &InputOrderField, IN const COrder &Order);
	bool FillInputOrderActionFieldByOrder(OUT CThostFtdcInputOrderActionField &InputOrderActionField, IN const COrder &Order);
	bool FillOrderByOrderField(OUT COrder &Order, IN const CThostFtdcOrderField &OrderField);
	bool FillPositionByPositionField(OUT CPosition &Position, IN const CThostFtdcInvestorPositionField &PositionField);
	bool FillAccountByTradingAccountField(OUT CAccount &Account, IN const CThostFtdcTradingAccountField &AccountField);


private://Temp
	map<int, vector<CThostFtdcInstrumentField>> m_mapInstrumentFieldTemp;		//查询合约的缓存,KEY：nRequestID
	map<int, vector<CThostFtdcDepthMarketDataField>> m_mapMarketDataFieldTemp;	//查询市场深度的缓存,KEY：nRequestID
	map<int, vector<CThostFtdcOrderField>> m_mapOrderTemp;						//查询报单的缓存,KEY：nRequestID
	map<int, vector<CThostFtdcInvestorPositionField>> m_mapPositionTemp;		//查询仓位的缓存,KEY：nRequestID
	map<int, vector<CThostFtdcTradingAccountField>> m_mapAccountTemp;			//查询账户的缓存,KEY：nRequestID
private:
	map<HANDLE, SEventParameter> m_mapEventParameter;							//事件路由,KEY:事件的句柄
private:
	CThostFtdcTraderApi *m_pTradeAPI;
private:
	CTrade *m_pTrade;	
	CONFIG m_Config;
	CThostFtdcRspUserLoginField m_UserLoginField;	//CTP用户信息
private:
	HANDLE m_hLoginEvent;		//登录事件
	bool m_bLoginSuccess;		//判断登录是否成功
private:
	int m_nRequestID;			//请求号
	int m_nOrderRef;			//向CTP的报单引用

};