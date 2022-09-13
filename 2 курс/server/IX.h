#pragma once
#include "IUnknown.h"
class IX: public IUnknown
{
    public:
    virtual void Func(int c) = 0;
    
};
HRESULT_ CreateInstance(CLSID_ clsid,IID_ IId, void** ppv);