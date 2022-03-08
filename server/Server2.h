#pragma once
#include <iostream>
#include "IX.h"
#include "IY.h"

class Server2: public IX, public IY
{
    private:
    int a, b;
    public:
    Server2();
    ~ Server2();
    void Func(int c);
    void Func2();
    int QueryInterface(int Iid, void **ppv);
};