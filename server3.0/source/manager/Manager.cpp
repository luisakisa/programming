#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Manager.h"
#include "../server/Functions.h"
#include "../server/IClassFactory.h"

typedef HRESULT_ (*FunctionType)(CLSID_, IID_, void **);
HINSTANCE h;

const char* PATH_TO_DLL = "./pathToDLL.txt";

int GetModulePath(std::string &path, CLSID_ clsid)
{
    std::fstream file(PATH_TO_DLL);
    if (!file)
    {
        return -1;
    }
    std::string s;
    CLSID_ fileCLS_ID;

    while (getline(file, s))
    {
        std::istringstream is(s, std::istringstream::in);
        is >> fileCLS_ID;
        if (fileCLS_ID == clsid)
        {
            is >> path;
            break;
        }
    }
    file.close();
    return 0;
}

HRESULT_ Co_GetClassObject(CLSID_ clsid, IID_ IClassFactory, void **ppv)
{
    FunctionType GetClassObject_;
    std::string path;
    GetModulePath(path, clsid);
    std::cout<<path<<std::endl;
    std::wstring stemp = std::wstring(path.begin(), path.end());
    LPCWSTR lpcPath = stemp.c_str();

    h = LoadLibraryW(lpcPath);
    if (!h)
    {
        std::cout << "no dll" << std::endl;
    }
    GetClassObject_ = (FunctionType)GetProcAddress(h, "DLL_GetClassObject");
    if (!GetClassObject_)
    {
        std::cout << "no dll func" << std::endl;
    }
    GetClassObject_(clsid, IClassFactory, ppv);
}

extern "C" HRESULT_ __declspec(dllexport) Co_CreateInstance(CLSID_ serverClsid, IID_ clientIid, void **ppv)
{
    IClassFactory_ *pIFact = NULL;
    Co_GetClassObject(serverClsid, ICLASS_FACTORY_IID, (void **)&pIFact);
    pIFact->CreateInstance(clientIid, ppv);
    pIFact->Release();
}
STDAPI __declspec(dllexport) DllCanUnloadNow()
{
    return FreeLibrary(h);
}
