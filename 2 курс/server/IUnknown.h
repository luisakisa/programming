#pragma once
using IID_=  const int;
using HRESULT_= const int;
using CLSID_= const int;
class IUnknown
{
public:
    virtual HRESULT_ QueryInterface(IID_ Iid, void **ppv)=0;
    
};


