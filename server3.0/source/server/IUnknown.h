#pragma once
using IID_=  const int;
using HRESULT_= const int;
using ULONG_= const int;
typedef int  CLSID_;
const HRESULT_ S_OK__ = 1000;
const HRESULT_ S_FALSE__ = -1000;
const HRESULT_ E_NOINTERFACE__ = -1;
const CLSID_ clsidServ = 12;
class IUnknown//запрос указателя на другой интерфейс 
{
public:
    virtual HRESULT_ QueryInterface(IID_ Iid, void **ppv)=0;
    virtual ULONG_ addRef()=0;
    virtual ULONG_ Release()=0;
};


