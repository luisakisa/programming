#include <iostream>
#include <algorithm>
#include <vector>
#include "Flower.h"
#include "Tree.h"
using namespace std;
bool sort_str(string a, string b)
{
  vector <string> v = {a, b};
  sort(v.begin(), v.end());
  if(v[0] == a) return true;
  else return false;
}
void Add_cost(Tree*& T, Flower* data)
{
  if(!T)
  {
    T = new Tree;
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    return;
  }
  if(data->cost < T->data->cost) Add_cost(T->left, data);
  else Add_cost(T->right, data);
}
void Add_kind(Tree*& T, Flower* data)
{
  if(!T)
  {
    T = new Tree;
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    return;
  }
  if(sort_str(data->kind, T->data->kind)) Add_kind(T->left, data);
  else Add_kind(T->right, data);
}
void Print(Tree* T)
{
  if(!T) return;
  Print(T->left);
  A_Print(T->data);
  Print(T->right);
}
void Delete(Tree*& T)
{
  if(T)
  {
    if(T->left) Delete (T->left);
    if(T->right) Delete(T->right);
    Del(T->data);
    delete T;
    T = NULL;
  }
}
void Print_cost(Tree* T, float cost)
{
  if(!T) return;
  Print_cost(T->left, cost);
  if(T->data->cost < cost) A_Print(T->data);
  Print_cost(T->right, cost);
}
void Print_kind(Tree* T, char a)
{
  if(!T) return;
  Print_kind(T->left, a);
  if(T->data->kind[0] == a) A_Print(T->data);
  Print_kind(T->right, a);
}
