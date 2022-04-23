using UnityEngine;

public class STBoot : MonoBehaviour
{
    void Start()
    {
        STDllInterface.UnityCallCpp_InitDelegate(STDllInterface.LogDelegateData);

        Vector2 vSrcPos = new Vector2(0.0f, 0.0f);
        Vector2 vDstPos = new Vector2(0.0f, 5.0f);
        Debug.Log("Unity CalcDistance:" + (vDstPos - vSrcPos).magnitude);
        Debug.Log("C++ CalcDistance:" + STDllInterface.UnityCallCpp_CalcDistance(vSrcPos.x, vSrcPos.y, vDstPos.x, vDstPos.y));
    }
}
