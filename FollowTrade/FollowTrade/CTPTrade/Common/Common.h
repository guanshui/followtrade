#pragma once
#include <windows.h>
#include <string>
using namespace std;

#define F_SafeDelete(p) {if(NULL != p) delete p; p = NULL;}
#define F_SafeDeleteArray(p) {if(NULL != p) delete[] p; p = NULL;}
#define F_GetLength(p) (sizeof(p)/sizeof(p[0]))
#define MAX(A, B) ((A) > (B)?(A):(B))
#define MIN(A, B) ((A) > (B)?(B):(A))

//type convert
string DoubleToString(IN double dData);
string UINT64ToString(IN UINT64 uData);

//code convert
std::wstring CToW(std::string strC);
std::string WToC(std::wstring strW);