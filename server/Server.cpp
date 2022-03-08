#include <iostream>
#include "Server.h"


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

