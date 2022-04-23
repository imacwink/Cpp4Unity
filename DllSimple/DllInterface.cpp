#include "pch.h"
#include "DllInterface.h"

void(*Debug::Log)(char* cMsg, int iSize);

extern "C" DLL_INTERFACE_EXPORT float UnityCallCpp_CalcDistance(float fSrcEntityX, float fSrcEntityY, float fDstEntityX, float fDstEntityY)
{
    UnityCSharpLog("UnityCallCpp_CalcDistance has been called");
	return sqrt((fSrcEntityX - fDstEntityX) * (fSrcEntityX - fDstEntityX) + (fSrcEntityY - fDstEntityY) * (fSrcEntityY - fDstEntityY));
}

extern "C" DLL_INTERFACE_EXPORT void UnityCallCpp_InitDelegate(void(*Log)(char* cMsg, int iSize))
{
    Debug::Log = Log;
    UnityCSharpLog("UnityCallCpp_InitDelegate:Log has initialized");
}