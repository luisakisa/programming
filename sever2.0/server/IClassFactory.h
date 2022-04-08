#pragma once
#include "IUnknown.h"
#include "Server.h"
#include "Server2.h"
#include <iostream>
using namespace std;

class IClassFactory_: public IUnknown
{
private:
    CLSID_ s; // const int
    int count =0 ;

public:

    IClassFactory_(CLSID_ server) : s(server)
    {
        addRef();
    }
   ~IClassFactory_()
{
    cout<<"ClassFactory is deleted"<<endl;
}
    // получаем ид интерфейса IEnterIntMatrix или ITransposeAndPrintAnyMatrix и указатель на СЕРВЕР с этим интерфейсом
    HRESULT_ CreateInstance(IID_ iid, void** ppv){
        if (s == 1){
            if (iid == 1){
                *ppv = (IEnterIntMatrix*)(new Server());
                return 0;
            }
        }
        else if (s == 2){
            if (iid == 1){
                *ppv = (IEnterIntMatrix*)(new Server2());
                return 0;
            }
            else if (iid == 2){
                *ppv = (ITransposeAndPrintAnyMatrix*)(new Server2());
                return 0;
            }
        }
        return 1;
    }
HRESULT_ QueryInterface(IID_ Iid, void **ppv){};
ULONG_ addRef(){
    count++;
    cout<<"pointer++"<<endl;
};
ULONG_ Release(){
    count--;
    cout<<"pointer--"<<endl;
    if (count==0){
        cout<<"point is del"<<endl;
        delete this;
    }
};
};

