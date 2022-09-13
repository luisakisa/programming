#include <iostream>

#include "Server2.h"
#include "Server.h"
using namespace std;

HRESULT_ Server2::QueryInterface(IID_ Iid, void **ppv){
   if(Iid == 0){
        *ppv = (IUnknown_*)((ITransposeAndPrintAnyMatrix*)this);
        return 0;
    }
    else if(Iid == ENTER_MATRIX_IID){
        *ppv = (IEnterIntMatrix*)this;
        return 0;
    }
    else if(Iid == TRANSPOSE_MATRIX_IID){
        *ppv = (ITransposeAndPrintAnyMatrix*)this;
        return 0;
    }
    else{
        *ppv= NULL;
        return 1;
    }
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
