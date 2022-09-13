#include "IClassFactory.h"
#include "Variables.h"
#include "Server.h"
#include "Server2.h"
#include <iostream>

using namespace std;

Factory::Factory(CLSID server) : s(server) {}

Factory::~Factory()
{
    cout << "Factory is deleted" << endl;
}

HRESULT __stdcall Factory::CreateInstance(IUnknown *pUnknownOuter, const IID &iid, void **ppv)
{
    cout << "Factory::CreateInstance" << endl;
    if (pUnknownOuter != NULL)
    {
        return E_NOTIMPL;
    }

    if (s == CLSID_Server1)
    {
        Server *server = new Server();
        return server->QueryInterface(iid, ppv);
    }
    else if (s == CLSID_Server2)
    {
        Server2 *server2 = new Server2();
        return server2->QueryInterface(iid, ppv);
    }

    return E_NOTIMPL;
}

ULONG __stdcall Factory::AddRef()
{
    count++;
    cout << "Factory::counter++" << endl;
    return S_OK;
}

ULONG __stdcall Factory::Release()
{
    count--;
    cout << "Factory::counter--" << endl;
    if (count == 0)
    {
        cout << "Factory::point is del" << endl;
        delete this;
    }
    return S_OK;
}

HRESULT __stdcall Factory::QueryInterface(const IID& iid, void **ppv)
{
    cout << "Factory::QueryInterface" << endl;
    if (iid == IID_IUnknown)
    {
        *ppv = (IUnknown*)(IClassFactory*)this;
    }
    else if (iid == IID_IClassFactory)
    {
        *ppv = (IClassFactory*)this;
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    
    this->AddRef();

    return S_OK;
}

HRESULT __stdcall Factory::LockServer(BOOL bLock)
{
    cout << "Factory::LockServer" << endl;
    return S_OK;
}