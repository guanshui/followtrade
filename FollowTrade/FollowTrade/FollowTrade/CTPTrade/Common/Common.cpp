#include "stdafx.h"
#include "Common.h"

#pragma warning(disable:4996)

string DoubleToString(IN double dData)
{
	char Data[50] = {0};
	sprintf(Data, "%f", dData);

	return Data;
}

string UINT64ToString(IN UINT64 uData)
{
	char Data[50] = {0};

	sprintf(Data, "%I64u", uData);

	return Data;
}

std::wstring CToW(std::string strC)
{
	int nSize = (strC.length() + 1) * sizeof(char);
	WCHAR *pW = new WCHAR[nSize];
	ZeroMemory(pW, sizeof(WCHAR) * nSize);

	MultiByteToWideChar(CP_ACP, 0, strC.c_str(), strC.length(), pW, strC.length());

	std::wstring strW(pW);

	F_SafeDeleteArray(pW);

	return strW;
}

std::string WToC(std::wstring strW)
{
	int nSize = (strW.length() + 1) * sizeof(WCHAR);
	char *pC = new char[nSize];
	ZeroMemory(pC, nSize);

	WideCharToMultiByte(CP_ACP, 0, strW.c_str(), strW.length(), pC, nSize - 1, "", FALSE);

	std::string strC(pC);

	F_SafeDeleteArray(pC);

	return strC;
}