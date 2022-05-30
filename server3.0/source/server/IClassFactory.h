#pragma once

#include "IUnknown.h"

using namespace std;

class IClassFactory_ : public IUnknown_
{
public:
    virtual HRESULT_ CreateInstance(IID_ iid, void** ppv) = 0;
    virtual ~IClassFactory_() {}
};


class Factory : public IClassFactory_
{
private:
    CLSID_ s; // const int
    int count = 0;

public:

    Factory(CLSID_ server);
    ~Factory();
    // получаем ид интерфейса IEnterIntMatrix или ITransposeAndPrintAnyMatrix и указатель на СЕРВЕР с этим интерфейсом
    HRESULT_ CreateInstance(IID_ iid, void** ppv);
    HRESULT_ QueryInterface(IID_ Iid, void **ppv);

    ULONG_ addRef();

    ULONG_ Release();
};

