#include <iostream>
using namespace std;
#ifndef Flower_h
#define Flower_h
struct Flower
{
    double cost;
    string color;
    int quantity;
    string kind;
};
Flower* Init(Flower);
void Del(Flower*);
void A_Print(Flower*);
#endif
