#pragma once

using IID_=  const int;
using HRESULT_= const int;
using ULONG_= const int;
using CLSID_ = int;

const CLSID_ SERVER1_CLSID = 1;
const CLSID_ SERVER2_CLSID = 2;
const IID_ ENTER_MATRIX_IID = 1;
const IID_ TRANSPOSE_MATRIX_IID = 2; 
const IID_ ICLASS_FACTORY_IID = 3;
const int S_OK_ = 0;

class IUnknown_//запрос указателя на другой интерфейс 
{
public:
    virtual HRESULT_ QueryInterface(IID_ Iid, void **ppv)=0;
    virtual ULONG_ addRef()=0;
    virtual ULONG_ Release()=0;
    virtual ~IUnknown_() {};
};


