// TradeObject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// #include "Quote.h"
// #include "Trade.h"
// #include "Entity/Entity.h"
// #include <vector>
// 
// using namespace std;
// 
// // const char *gpTradeServer = "tcp://sim-front1.ctp.shcifco.com:31205";
// // const char *gpQuoteServer = "tcp://zjzx-md1.ctp.shcifco.com:41213";
// // const char *gpBrokerID = "1002";
// // const char *gpInvestorID = "00000005";
// // const char *gpPassword = "123456";
// 
// const char *gpTradeServer = "tcp://sim-front1.ctp.shcifco.com:31205";
// const char *gpQuoteServer = "tcp://140.206.102.161:41213";
// const char *gpBrokerID = "1002";
// const char *gpInvestorID = "00000005";
// const char *gpPassword = "123456";
// 
// int _tmain(int argc, _TCHAR* argv[])
// {
// 	CTrade Trade;
// 	CQuote Quote;
// 	
// 	bool bResult = Trade.Initialize(gpTradeServer, gpInvestorID, gpPassword, gpBrokerID);
// 
// 	
// 	Sleep(1100);	//查询间隔时间
// 	CAccount Account;
// 	bResult = Trade.GetAccount(Account);
// 
// 	Sleep(1100);	//查询间隔时间
// 	vector<COrder> vecOrder;
// 	bResult = Trade.GetOrder(vecOrder);
// 
// 	Sleep(1100);	//查询间隔时间
// 	vector<CPosition> vecPosition;
// 	bResult = Trade.GetPosition(vecPosition);
// 
// 	Sleep(1100);	//查询间隔时间
// 	map<string, CSymbol> mapSymbol;
// 	bResult = Trade.GetSymbol(mapSymbol);
// 
// 	vector<CSymbol> vecSymbol;
// 	
// 	for (map<string, CSymbol>::iterator itSymbol = mapSymbol.begin(); mapSymbol.end() != itSymbol; ++itSymbol)
// 	{
// 		vecSymbol.push_back(itSymbol->second);
// 	}
// 
// 	Sleep(2000);
// 	
// 	//挂单:Symbol, Flags, Type, Price, Volume, isColseYesterday.
// 	COrder InsertOrder;
// 	InsertOrder.SetOrderID(100);
// 	InsertOrder.SetSymbol("IF1408");
// 	InsertOrder.SetFlags(IOrder::OrderFlagsOpen);
// 	InsertOrder.SetType(IOrder::OrderTypeBuy);
// 	InsertOrder.SetPrice(2230);
// 	InsertOrder.SetVolume(10);
// 	InsertOrder.SetIsCloseYesterday(false);
// 
// 	bResult = Trade.OrderInsert(InsertOrder);
// 
// 	//撤单:Symbol, OrderID, FrontID, SessionID.
// 	COrder DeleteOrder;
// 	DeleteOrder.SetSymbol("IF1408");
// 	DeleteOrder.SetOrderID(100);
// 	DeleteOrder.SetFrontID(0);
// 	DeleteOrder.SetSession(0);
// 
// 	Trade.OrderDelete(DeleteOrder);
// 
// 
// 	Quote.SetSymbol(vecSymbol);
// 
// 	bResult = Quote.Initialize(gpQuoteServer);
// 
// 	while (true)
// 	{
// 		Sleep(1000);
// 	}
// 
// 	return 0;
// }

