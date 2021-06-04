#include <iostream>
#include "Flower.h"
using namespace std;
#ifndef Tree_h
#define Tree_h
struct Tree
{
  Flower* data;
  Tree* left;
  Tree* right;
};
bool sort_str(string, string);
void Add_cost(Tree*&, Flower*);
void Add_kind(Tree*&, Flower*);
void Print(Tree*);
void Delete(Tree*&);
void Print_cost(Tree*, float);
void Print_kind(Tree*, char);
#endif
