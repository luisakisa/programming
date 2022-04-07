#include "IX.h"
#include "IY.h"
#include "Functions.h"
#include "IClassFactory.h"
#include <iostream>
using namespace std;

/**
    IID_
    ИД интерфейсов
    IX - 1
    IY - 2
    IClassFactory - 3
*/

int main()
{
    CLSID_ Server = 1;
    IID_ IClassFactory = 3;
    const int  S_OK = 0;
    IClassFactory_ *pF = NULL;
    HRESULT_ res = GetClassObject(Server, IClassFactory, (void**)&pF);
    if (res == S_OK){
        IX* pX = NULL;
        HRESULT_ res = pF->CreateInstance(1, (void**)&pX); 
        pX->Func(2);
        pX->Release();
    }
    pF->Release();
    
}
