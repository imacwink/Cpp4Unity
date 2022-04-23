#pragma once
#include<math.h>
#include<string.h>
#include<iostream>

#define DLL_INTERFACE_EXPORT __declspec(dllexport)
#define UnityCSharpLog(strLogMsg)  char strLogMsgTemp[512] = { 0 }; sprintf_s(strLogMsgTemp, "%s", strLogMsg); Debug::Log(strLogMsgTemp,strlen(strLogMsg));

class Debug
{
public:
    static void (*Log)(char* cMsg, int iSize);
};

extern "C" DLL_INTERFACE_EXPORT float UnityCallCpp_CalcDistance(float fSrcEntityX, float fSrcEntityY, float fDstEntityX, float fDstEntityY);
extern "C" DLL_INTERFACE_EXPORT void UnityCallCpp_InitDelegate(void (*Log)(char* cMsg, int iSize));