#pragma once
#include <string>

using namespace std;

class IOrder
{
public:
	IOrder() {};
	virtual ~IOrder() {};

public:
	enum EOrderType
	{
		OrderTypeInvalid = 0,	//无效
		OrderTypeBuy,			//买
		OrderTypeSell			//卖
	};
	enum EOrderAction
	{
		OrderActionInvalid = 0,	//无效
		OrderActionInstant,		//立即执行
		OrderActionPending,		//挂单
		OrderActionMarket,		//市价
		OrderActionRemove		//撤单
	};
	enum EOrderFlags
	{
		OrderFlagsInvalid = 0,	//无效
		OrderFlagsOpen,			//开仓
		OrderFlagsClose			//平仓
	};
	enum EOrderStatus
	{
		OrderStatusInvalid = 0,	//无效
		OrderStatusSubmitted,	//提交
		OrderStatusAccepted,	//接受
		OrderStatusRejected,	//拒绝
		OrderStatusCancel,		//取消
		OrderStatusDonePartial,	//部分成交
		OrderStatusDone			//全部成交
	};
	enum EOrderResult
	{
		OrderResultInvalid = 0,	//无效
		OrderResultAllTraded,	//已全部成交
		OrderResultTrading,		//正在交易中
		OrderResultNotQueueing,	//已退出交易
		OrderResultCanceled		//已取消
	};

public://Assign
	virtual void Assign( const IOrder &Order) = 0;
	virtual void Clear() = 0;

public://Mumber
	virtual void SetOrderID( int uOrderID) = 0;					//设置单号
	virtual int GetOrderID() const = 0;								//获取单号
	virtual void SetSymbol( string strSymbol) = 0;					//设置MT合约
	virtual string GetSymbol() const = 0;								//获取MT合约
	virtual void SetOrderLocalID(string strOrderLocalID) = 0;			//报单服务器ID
	virtual string GetOrderLocalID() const = 0;								//报单服务器DI
	virtual void SetVolume( double dVolume) = 0;						//设置当前量
	virtual double GetVolume() const = 0;								//获取当前量
	virtual void SetInitVolume( double dInitVolume) = 0;				//设置初始量
	virtual double GetInitVolume() const = 0;							//获取初始量
	virtual void SetRemaindVolume( double dRemaindVolume) = 0;		//设置余留量
	virtual double GetRemaindVolume() const = 0;						//获取余留量
	virtual void SetPrice( double dPrice) = 0;						//设置报价
	virtual double GetPrice() const = 0;								//获取报价
	virtual void SetSLPrice( double dSLPrice) = 0;					//设置止损价
	virtual double GetSLPrice() const = 0;								//获取止损价
	virtual void SetTPPrice( double dTPPrice) = 0;					//设置止盈价
	virtual double GetTPPrice() const = 0;								//获取止盈价
	virtual void SetInsertTime( long long lInsertTime) = 0;			//设置报单时间
	virtual long long GetInsertTime() const = 0;						//获取报单时间
	virtual void SetIsCloseYesterday( bool bIsCloseYesterday) = 0;	//设置是否平昨
	virtual bool GetIsCloseYesterday() const = 0;						//获取是否平昨
	virtual void SetFrontID( int nFrontID) = 0;						//设置前置服务器ID
	virtual int GetFrontID() const = 0;									//获取前置服务器ID
	virtual void SetSession( int nSession) = 0;						//设置会话ID
	virtual int GetSession() const = 0;									//获取会话ID
	virtual void SetComment( string strComment) = 0;					//设置备注
	virtual string GetComment() const = 0;								//获取备注
	virtual void SetType( EOrderType eType) = 0;						//设置类型
	virtual EOrderType GetType() const = 0;								//获取类型
	virtual void SetAction( EOrderAction eAction) = 0;				//设置动作
	virtual EOrderAction GetAction() const = 0;							//获取动作
	virtual void SetFlags( EOrderFlags eFlags) = 0;					//设置标志
	virtual EOrderFlags GetFlags() const = 0;							//获取标志
	virtual void SetStatus( EOrderStatus eStatus) = 0;				//设置状态
	virtual EOrderStatus GetStatus() const = 0;							//获取状态
	virtual void SetResult( EOrderResult eResult) = 0;				//设置结果
	virtual EOrderResult GetResult() const = 0;							//获取结果
};