#pragma once
#include <windows.h>
#include <string>

using namespace std;

class CSymbol
{
public:
	CSymbol();
	virtual ~CSymbol();

public://Assign
	virtual void Assign(IN const CSymbol &Symbol);
	virtual void Clear();

public://Mumber
	virtual void SetSymbol(IN string strSymbol);						//设置交易所合约
	virtual string GetSymbol() const;									//获取交易所合约
	virtual void SetExchangeName(IN string strExchangeName);			//设置交易所名称
	virtual string GetExchangeName() const;								//获取交易所名称
	virtual void SetContractSize(IN double dContractSize);				//设置合约大小
	virtual double GetContractSize() const;								//获取合约大小
	virtual void SetTickSize(IN double dTickSize);						//设置Tick大小(价格最小倍数)
	virtual double GetTickSize() const;									//获取Tick大小(价格最小倍数)
	virtual void SetMaxVolume(IN double dMaxVolume);					//设置最大持有量
	virtual double GetMaxVolume() const;								//获取最大持有量
	virtual void SetMinVolume(IN double dMinVolume);					//设置最小持有量
	virtual double GetMinVolume() const;								//获取最小持有量
	virtual void SetVolumeStep(IN double dVolumeStep);					//设置量的最小倍数
	virtual double GetVolumeStep() const;								//获取量的最小倍数
	virtual void SetLongMarginRate(IN double dLongMarginRate);			//设置多仓的保证金率
	virtual double GetLongMarginRate() const;							//获取多仓的保证金率
	virtual void SetShortMarginRate(IN double dShortMarginRate);		//设置空仓的保证金率
	virtual double GetShortMarginRate() const;							//获取空仓的保证金率
	virtual void SetUpperLimitPrice(IN double dUpperLimitPrice);		//设置涨停价
	virtual double GetUpperLimitPrice() const;							//获取涨停价
	virtual void SetLowerLimitPrice(IN double dLowerLimitPrice);		//设置跌停价
	virtual double GetLowerLimitPrice() const;							//获取跌停价

private:
	string m_strSymbol;				//交易所合约
	string m_strExchangeName;		//交易所名称
	double m_dContractSize;			//合约大小
	double m_dTickSize;				//Tick大小(价格最小倍数)
	double m_dMaxVolume;			//最大持有量
	double m_dMinVolume;			//最小持有量
	double m_dVolumeStep;			//量的最小倍数
	double m_dLongMarginRate;		//多仓的保证金率
	double m_dShortMarginRate;		//空仓的保证金率
	double m_dUpperLimitPrice;		//涨停价
	double m_dLowerLimitPrice;		//跌停价
};