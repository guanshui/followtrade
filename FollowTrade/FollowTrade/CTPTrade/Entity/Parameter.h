#pragma once
#include <windows.h>

typedef struct S_EVENT_PARAMETER
{
	HANDLE hEvent;
	bool bSuccess;
	void *pValue;
}SEventParameter, *PSEventParameter;