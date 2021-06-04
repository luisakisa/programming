#include <iostream>
#include "Flower.h"
using namespace std;
Flower* Init(Flower A)
{
  Flower* B = new Flower;
  *B = A;
  return B;
}
void Del(Flower* A)
{
  delete A;
}
void A_Print(Flower* A)
{
  cout << endl << endl;
  cout << "Cost: " << A->cost << endl;
  cout << "Color: " << A->color << endl;
  cout << "Quantity: " << A->quantity << endl;
  cout << "Kind: " << A->kind << endl;
  cout << endl << endl;
}
