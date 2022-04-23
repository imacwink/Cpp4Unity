using AOT;
using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class STDllInterface
{
    public delegate void LogDelegate(IntPtr pMsg, int iSize);

    [DllImport("DllSimple")]
    public static extern float UnityCallCpp_CalcDistance(float fSrcEntityX, float fSrcEntityY, float fDstEntityX, float fDstEntityY);

    [DllImport("DllSimple")]
    public static extern float UnityCallCpp_InitDelegate(LogDelegate logDelegate);


    [MonoPInvokeCallback(typeof(LogDelegate))]
    public static void LogDelegateData(IntPtr pMsg, int iSize)
    {
        Debug.Log(Marshal.PtrToStringAnsi(pMsg, iSize));
    }
}