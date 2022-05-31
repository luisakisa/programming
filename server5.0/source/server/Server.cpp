#include <iostream>
#include <iomanip>
#include <windows.h>
#include <OleAuto.h>

#include "Server.h"

using namespace std;

const char* PATH_TO_DLL = "./pathToDLL.txt";

Server::Server()
{
    cout << "Server created" << endl;
}

Server::~Server()
{
    clearMemoryForMatrix();
    cout<<"Server is deleted"<<endl;
}

HRESULT __stdcall Server::QueryInterface(const IID& iid, void** ppv){
    cout << "Server::QueryInterface" << endl;

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

ULONG __stdcall Server::AddRef() {
    count++;
    cout << "Server::counter++" << endl;
    return S_OK;
}; 

ULONG __stdcall Server::Release() {
    count--;
    cout << "Server::pointer--" << endl;
    if (count==0){
        cout << "Serever::pointers are deleted" << endl;
        delete this;
    }
    return S_OK;
}

void __stdcall Server::allocateMemoryForMatrix() {
    matr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matr[i] = new int[m];
    }
}

void __stdcall Server::clearMemoryForMatrix() {
    for (int i = 0; i < n; i++)
    {
        delete[] matr[i];
    }
    delete[] matr;
}

void __stdcall Server::enterMatrix(int n, int m) {
    this->n = n;
    this->m = m;
    allocateMemoryForMatrix();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Enter element with index:" << i << " " << j << std::endl;
            std::cin >> matr[i][j];
        }
    }
}

void __stdcall Server::transposeMatrix() {
    int buff;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            buff = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = buff;
        }
    }
}

void __stdcall Server::printMatrix() {
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << std::setw(15) << matr[i][j];
        std::cout << std::endl;
    }
};


//IDispatch (Begin)
HRESULT __stdcall Server::GetTypeInfoCount(UINT* pctinfo)
{
    cout << "Server::GetTypeInfoCount" << endl;
    return S_OK;
}

HRESULT __stdcall Server::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
    cout << "Server::GetTypeInfo" << endl;
    return S_OK;
}

HRESULT __stdcall Server::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                                        LCID lcid, DISPID* rgDispId)
{
    cout << "Server::GetIDsOfNames" << endl;
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

HRESULT __stdcall Server::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                                    EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    cout << "Server::Invoke" << endl;

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