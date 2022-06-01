#include "IClassFactory.h"
#include "IUnknown.h"
#include "Server.h"
#include "Server2.h"

Factory::Factory(CLSID_ server) : s(server)
{
    addRef();
}

Factory::~Factory()
{
    cout<<"ClassFactory is deleted"<<endl;
}

HRESULT_ Factory::CreateInstance(IID_ iid, void** ppv){
    if (s == SERVER1_CLSID){
        if (iid == ENTER_MATRIX_IID){
            *ppv = (IEnterIntMatrix*)(new Server());
            return 0;
        }
    }
    else if (s == SERVER2_CLSID){
        if (iid == ENTER_MATRIX_IID){
            *ppv = (IEnterIntMatrix*)(new Server2());
            return 0;
        }
        else if (iid == TRANSPOSE_MATRIX_IID){
            *ppv = (ITransposeAndPrintAnyMatrix*)(new Server2());
            return 0;
        }
    }
    return 1;
}

ULONG_ Factory::addRef(){
    count++;
    cout<<"pointer++"<<endl;
}

ULONG_ Factory::Release(){
    count--;
    cout<<"pointer--"<<endl;
    if (count==0){
        cout<<"point is del"<<endl;
        delete this;
    }
}

HRESULT_ Factory::QueryInterface(IID_ Iid, void **ppv){}