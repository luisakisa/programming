#pragma once

#include <windows.h>

class Factory : public IClassFactory
{
private:
    CLSID s; // const int
    int count = 0;

public:

    Factory(CLSID server);
    virtual ~Factory();

    // получаем ид интерфейса IEnterIntMatrix или ITransposeAndPrintAnyMatrix и указатель на СЕРВЕР с этим интерфейсом
    HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
    HRESULT __stdcall LockServer(BOOL bLock);

    HRESULT __stdcall QueryInterface(const IID& iid, void **ppv);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
};

