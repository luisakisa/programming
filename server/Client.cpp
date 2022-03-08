#include "IX.h"
#include "IY.h"
#include <iostream>
int main()
{
    IX* s = CreateInstance();
    IY* s2 = NULL;
    int res = s->QueryInterface(2, (void**)&s2);
    if(res!=0){

    }
    s2->Func2();
    return 0;
}