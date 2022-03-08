#include "Server2.h"
using namespace std;
void Server2::Func(int c){
    cout<< a+b+c;
}
int Server2::QueryInterface(int Iid, void **ppv){
    if(Iid == 2){
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