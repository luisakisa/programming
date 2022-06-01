#pragma once

#include <windows.h>

#include "IEnterIntMatrix.h"
#include "ITransposeAndPrintAnyMatrix.h"

class Server2 : public IEnterIntMatrix, public ITransposeAndPrintAnyMatrix, public IDispatch
{
private:
    int count = 0;

public:
    Server2();
    virtual ~Server2();

    HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();

    void __stdcall allocateMemoryForMatrix();
    void __stdcall clearMemoryForMatrix();
    void __stdcall enterMatrix(int n, int m);
    void __stdcall transposeMatrix();
    void __stdcall printMatrix();

    HRESULT __stdcall GetTypeInfoCount(UINT *pctinfo);
    HRESULT __stdcall GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
    HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
    HRESULT __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult,
                             EXCEPINFO *pExcepInfo, UINT *puArgErr);
};