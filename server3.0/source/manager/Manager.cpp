#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Manager.h"

typedef H_RESULT (*FunctionType)(CLSID_, IID_, void **);
HINSTANCE h;

int GetModulePath(std::string &path, CLSID_ clsid)
{
    std::fstream file("pathToDLL.txt");
    if (!file)
    {
        return -1;
    }
    std::string s;
    CLS_ID fileCLS_ID;

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

H_RESULT Co_GetClassObject(CLS_ID clsid, I_ID iid_IClassFactory, void **ppv)
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
    GetClassObject_(clsid, iid_IClassFactory, ppv);
}

extern "C" H_RESULT __declspec(dllexport) Co_CreateInstance(CLS_ID clsid, I_ID iid, void **ppv)
{
    IClassFactory_ *pIFact = NULL;
    Co_GetClassObject(clsid, iid_IClassFactory, (void **)&pIFact);
    pIFact->CreateInstance(iid_IEnter, ppv);
    pIFact->Release();
}
STDAPI __declspec(dllexport) DllCanUnloadNow()
{
    return FreeLibrary(h);
}
