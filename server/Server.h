#pragma once
#include <iostream>
#include "IX.h"
#include "IY.h"
class Server: public IX, public IY
{
private:
    int a, b;
public:
    Server(/* args */);
    ~Server();
    void Func(int c);
    void Func2();
};


