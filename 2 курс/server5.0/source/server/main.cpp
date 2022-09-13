#include <windows.h>
#include <iostream>

#include "Functions.h"

STDAPI __declspec(dllexport) DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    std::cout << "DllGetClassObject" << std::endl;
    return GetClassObject(clsid, iid, ppv);
}


BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

STDAPI __declspec(dllexport) DllRegisterServer()
{
    return S_OK;
}
STDAPI __declspec(dllexport) DllUnregisterServer()
{
    
    return S_OK;
}
STDAPI __declspec(dllexport) DllCanUnloadNow()
{
    return S_OK;
}