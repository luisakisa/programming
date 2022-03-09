#include <iostream>
#include "Server.h"
#include "Server2.h"

using namespace std;

void Server::Func(int c)
{
    cout << a + b + c;
}

void Server::Func2()
{
    cout << a * b;
}

Server::Server(/* args */)
{
    a = 5;
    b = 3;
}

Server::~Server()
{
}
HRESULT_ Server::QueryInterface(IID_ Iid, void **ppv){
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
 

