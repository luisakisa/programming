#include "Server2.h"
#include "Server.h"
using namespace std;

void Server2::Func(int c){
    cout<< a+b+c;
}
HRESULT_ Server2::QueryInterface(IID_ Iid, void **ppv){
   if(Iid == 0){
        *ppv = (IUnknown*)((IY*)this);
        return 0;
    }
    else if(Iid == 1){
        *ppv = (IX*)this;
        return 0;
    }
    else if(Iid == 2){
        *ppv = (IY*)this;
        return 0;
    }
    else{
        *ppv= NULL;
        return 1;
    }
}
void Server2::Func2(){
    cout<< a*b;
}
Server2::~Server2()
{
    cout<<"Server2 is deleted";
}
ULONG_ Server2::addRef(){
    count++;
    cout<<"Pointer++";
}; 
ULONG_ Server2::Release(){
    count--;
    cout<<"Pointer--";
    if (count==0){
        delete this;
        cout<<"Pointers are deleted";
    }
}   
Server2::Server2()
{
    addRef();
} 