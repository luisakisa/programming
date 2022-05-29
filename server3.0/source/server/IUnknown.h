#pragma once
using IID_=  const int;
using HRESULT_= const int;
using ULONG_= const int;
typedef int  CLSID_;
const CLSID_ CLS_ID_SERV = 12;
class IUnknown_//запрос указателя на другой интерфейс 
{
public:
    virtual HRESULT_ QueryInterface(IID_ Iid, void **ppv)=0;
    virtual ULONG_ addRef()=0;
    virtual ULONG_ Release()=0;
    virtual ~IUnknown_() {};
};


