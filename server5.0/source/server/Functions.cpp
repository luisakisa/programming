#include "Functions.h"

#include "Variables.h"
#include "IClassFactory.h"

#include <iostream>

/*
    1 аргумент - ид сервера (1 или 2)
    2 аргумент - ид фабрики (3)
    3 аргумент - указатель на фабрику, которая конструируется в этой функции
*/
HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv) {
    std::cout << "GetClassObject" << std::endl;
    
    if (clsid == CLSID_Server1 || clsid == CLSID_Server2) {
        IClassFactory* factory = new Factory(clsid);
        return factory->QueryInterface(iid, ppv);
    }
    else
    {
        *ppv = NULL;
        return E_NOTIMPL;
    }
    
}