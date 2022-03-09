#include "IX.h"
#include "IY.h"
#include <iostream>
using namespace std;

int main()
{
    IX* ppv;
    HRESULT_ res = CreateInstance(1, 1, (void**)&ppv);
    if(res != 0)
    {
        cout << "Error";
        return 0;
    }
    ppv->Func(3);
}
