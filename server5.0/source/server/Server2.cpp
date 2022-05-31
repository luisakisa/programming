#include <iostream>

#include "Server2.h"

using namespace std;

HRESULT __stdcall Server2::QueryInterface(const IID& iid, void** ppv){
    cout << "Server2::QueryInterface" << endl;

    if (iid == IID_IUnknown)
    {
        *ppv = (IUnknown*)(IEnterIntMatrix*)this;
    }
    else if (iid == IID_IEnterIntMatrix)
    {
        *ppv = (IEnterIntMatrix*)this;
    }
    else if (iid == IID_ITransposeMatrix)
    {
        *ppv = (ITransposeAndPrintAnyMatrix*)this;
    }
    else if (iid == IID_IDispatch)
    {
        *ppv = (IDispatch*)this;
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }

    this->AddRef();
    return S_OK;
}
Server2::Server2()
{
    cout<<"Server2 constructed";
}
Server2::~Server2()
{
    cout<<"Server2 is deleted";
}
ULONG __stdcall Server2::AddRef(){
    count++;
    cout<<"Server2::counter++";
    return S_OK;
}; 
ULONG __stdcall Server2::Release(){
    count--;
    cout<<"Server2::counter--";
    if (count==0){
        delete this;
        cout<<"Server2::Pointers are deleted";
    }
    return S_OK;
}

void Server2::allocateMemoryForMatrix() {

}

void Server2::clearMemoryForMatrix() {

}

void Server2::enterMatrix(int n, int m) {

}

void Server2::transposeMatrix() {

}

void Server2::printMatrix() {

}

//IDispatch (Begin)
HRESULT __stdcall Server2::GetTypeInfoCount(UINT* pctinfo)
{
    cout << "Server2::GetTypeInfoCount" << endl;
    return S_OK;
}

HRESULT __stdcall Server2::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
    cout << "Server2::GetTypeInfo" << endl;
    return S_OK;
}

HRESULT __stdcall Server2::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                                        LCID lcid, DISPID* rgDispId)
{
    cout << "Server2::GetIDsOfNames" << endl;
    if (cNames!=1) {
        return E_NOTIMPL;
    }

    //const wchar_t* src = rgszNames[0];
    //char* dest = new char[32];
    //wcstombs(dest,src,32);
    //printf(dest); printf("\n");

    if (wcscmp(rgszNames[0], L"allocateMemoryForMatrix") == 0)
    {
        rgDispId[0] = 1;
    }
    else if (wcscmp(rgszNames[0], L"clearMemoryForMatrix") == 0)
    {
        rgDispId[0] = 2;
    }
    else if (wcscmp(rgszNames[0], L"enterMatrix") == 0)
    {
        rgDispId[0] = 3;
    }
    else if (wcscmp(rgszNames[0], L"transposeMatrix") == 0)
    {
        rgDispId[0] = 4;
    }
    else if (wcscmp(rgszNames[0], L"printMatrix") == 0)
    {
        rgDispId[0] = 5;
    }

    return S_OK;
}

HRESULT __stdcall Server2::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                                    EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    cout << "Server2::Invoke" << endl;

    if (dispIdMember == 1)
    {
        allocateMemoryForMatrix();
    }
    else if (dispIdMember == 2)
    {
        clearMemoryForMatrix();
    }
    else if (dispIdMember == 3)
    {
        DISPPARAMS param = *pDispParams;
        VARIANT n = (param.rgvarg)[0];
        VariantChangeType(&n, &n, 0, VT_INT);

        VARIANT m = (param.rgvarg)[1];
        VariantChangeType(&m, &m, 0, VT_INT);

        enterMatrix(n.intVal, m.intVal);
    }
    else if (dispIdMember == 4)
    {
        transposeMatrix();
    }
    else if (dispIdMember == 5)
    {
        printMatrix();
    }
    else
    {
      return E_NOTIMPL;
    }
    return S_OK;
}
//IDispatch (End)