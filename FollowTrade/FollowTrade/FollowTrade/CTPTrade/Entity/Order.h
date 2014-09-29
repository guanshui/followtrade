#pragma once
#include <string>
#include "Interface/IOrder.h"

using namespace std;

class COrder: public IOrder
{
public:
	COrder();
	virtual ~COrder();

public://Assign
	virtual void Assign( const IOrder &Order);
	virtual void Clear();

public://Mumber
	virtual void SetOrderID( int nOrderID);					//设置单号
	virtual int GetOrderID() const;								//获取单号
	virtual void SetSymbol( string strSymbol);					//设置MT合约
	virtual string GetSymbol() const;								//获取MT合约
	virtual void SetOrderLocalID(string strOrderLocalID);			//报单服务器ID
	virtual string GetOrderLocalID() const;							//报单服务器DI
	virtual void SetVolume( double dVolume);						//设置当前量
	virtual double GetVolume() const;								//获取当前量
	virtual void SetInitVolume( double dInitVolume);				//设置初始量
	virtual double GetInitVolume() const;							//获取初始量
	virtual void SetRemaindVolume( double dRemaindVolume);		//设置余留量
	virtual double GetRemaindVolume() const;						//获取余留量
	virtual void SetPrice( double dPrice);						//设置报价
	virtual double GetPrice() const;								//获取报价
	virtual void SetSLPrice( double dSLPrice);					//设置止损价
	virtual double GetSLPrice() const;								//获取止损价
	virtual void SetTPPrice( double dTPPrice);					//设置止盈价
	virtual double GetTPPrice() const;								//获取止盈价
	virtual void SetInsertTime( long long lInsertTime);			//设置报单时间
	virtual long long GetInsertTime() const;						//获取报单时间
	virtual void SetIsCloseYesterday( bool bIsCloseYesterday);	//设置是否平昨
	virtual bool GetIsCloseYesterday() const;						//获取是否平昨
	virtual void SetFrontID( int nFrontID);						//设置前置服务器ID
	virtual int GetFrontID() const;									//获取前置服务器ID
	virtual void SetSession( int nSession);						//设置会话ID
	virtual int GetSession() const;									//获取会话ID
	virtual void SetComment( string strComment);					//设置备注
	virtual string GetComment() const;								//获取备注
	virtual void SetType( EOrderType eType);						//设置类型
	virtual EOrderType GetType() const;								//获取类型
	virtual void SetAction( EOrderAction eAction);				//设置动作
	virtual EOrderAction GetAction() const;							//获取动作
	virtual void SetFlags( EOrderFlags eFlags);					//设置标志
	virtual EOrderFlags GetFlags() const;							//获取标志
	virtual void SetStatus( EOrderStatus eStatus);				//设置状态
	virtual EOrderStatus GetStatus() const;							//获取状态
	virtual void SetResult( EOrderResult eResult);				//设置结果
	virtual EOrderResult GetResult() const;							//获取结果

private:
	int m_nOrderID;					//单号
	string m_strExchangeID;				//交易(所报单)ID
	string m_strSymbol;					//合约
	string m_strOrderLocalID;			//报单服务器ID
	double m_dVolume;					//当前量
	double m_dInitVolume;				//初始量
	double m_dRemainVolume;				//余留量
	double m_dPrice;					//报价
	double m_dSLPrice;					//止损价
	double m_dTPPrice;					//止盈价
	long long m_lInsertTime;			//报单时间
	bool m_bIsCloseYesterday;			//是否平昨
	int m_nFrontID;						//前置服务器ID
	int m_nSession;						//会话ID
	string m_strComment;				//备注
	EOrderType m_eType;					//类型
	EOrderAction m_eAction;				//动作
	EOrderFlags m_eFlags;				//标志
	EOrderStatus m_eStatus;				//状态
	EOrderResult m_eResult;				//结果
};

