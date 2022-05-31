#include <iostream>
#include <windows.h>
#include "Manager.h"

using namespace std;

typedef HRESULT __stdcall (*DllGetClassObjectType)(const CLSID &clsid, const IID &iid, void **ppv);

extern "C" __declspec(dllexport) HRESULT GetClassObject(const CLSID &clsid, const IID &iid, void **ppv)
{
    printf("Manager::GetClassObject\n");

    try
    {
        DllGetClassObjectType DllGetClassObject;

        HINSTANCE h;

        h = LoadLibrary("./build/Server.dll");

        if (!h)
        {
            throw "Server.dll not found";
        }

        DllGetClassObject = (DllGetClassObjectType)GetProcAddress(h, "DllGetClassObject");

        if (!DllGetClassObject)
        {
            std::cout << "DllGetClassObject not found" << std::endl;
            throw "cant load DllGetClassObject from Server.dll";
        }
        return DllGetClassObject(clsid, iid, ppv);
    }
    catch (const char* ex)
    {
        cout << "manager::exception: " << ex << endl;
        return E_UNEXPECTED;
    }
    catch (...)
    {
        cout << "manager::exception unknounw error" << endl;
        return E_UNEXPECTED;
    }
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
