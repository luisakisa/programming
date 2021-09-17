#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
struct Pie
{
  string filling;
  float weight;
  string restaurant;
  float price;
};
Pie* Init(Pie);
void Del(Pie*);
void A_Print(Pie*);
Pie* Init(Pie A)
{
  Pie* B = new Pie;
  *B = A;
  return B;
}
void Del(Pie* A)
{
  delete A;
}
void A_Print(Pie* A)
{
  cout << endl << endl;
  cout << "Filling: " << A->filling << endl;
  cout << "Weight: " << A->weight << endl;
  cout << "Restaurant: " << A->restaurant << endl;
  cout << "Price: " << A->price << endl;
  cout << endl << endl;
}
struct Tree
{
  Pie* data;
  Tree* left;
  Tree* right;
};
bool sort_str(string a, string b)
{
  vector <string> v = {a, b};
  sort(v.begin(), v.end());
  if(v[0] == a) return true;
  else return false;
}
void Add_price(Tree*& T, Pie* data)
{
  if(!T)
  {
    T = new Tree;
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    return;
  }
  if(data->price < T->data->price) Add_price(T->left, data);
  else Add_price(T->right, data);
}
void Add_color(Tree*& T, Pie* data)
{
  if(!T)
  {
    T = new Tree;
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    return;
  }
  if(sort_str(data->filling, T->data->filling)) Add_color(T->left, data);
  else Add_color(T->right, data);
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
void Print_price(Tree* T, float price)
{
  if(!T) return;
  Print_price(T->left, price);
  if(T->data->price < price) A_Print(T->data);
  Print_price(T->right, price);
}
void Print_color(Tree* T, char a)
{
  if(!T) return;
  Print_color(T->left, a);
  if(T->data->filling[0] == a) A_Print(T->data);
  Print_color(T->right, a);
}
int main()
{
    Pie A;
    Tree* T = NULL;
    int m = 1;
    while (m)
    {
        ifstream file("Flowers.txt");
        string line;
        system("cls");
        cout << endl << endl;
        cout << "1. Sort by filling" << endl;
        cout << "2. Sort by price" << endl;
        cout << "3. Show pies at a price below the specified price" << endl;
        cout << "4. Show pies whose filling starts with your letter" << endl;
        cout << "0. Exit" << endl << endl;
        cin >> m;
        switch (m)
        {
        case 1:
        {
            while (getline(file, line))
            {
                istringstream line_F(line);
                line_F >> A.filling >> A.weight >> A.restaurant >> A.price;
                Add_color(T, Init(A));
            }
            system("cls");
            Print(T);
            system("pause");
            break;
        }
        case 2:
        {
            while (getline(file, line))
            {
                istringstream line_F(line);
                line_F >> A.filling >> A.weight >> A.restaurant >> A.price;
                Add_price(T, Init(A));
            }
            system("cls");
            Print(T);
            system("pause");
            break;
        }
        case 3:
        {
            float price;
            cout << "Price = "; cin >> price;
            while (getline(file, line))
            {
                istringstream line_F(line);
                line_F >> A.filling >> A.weight >> A.restaurant >> A.price;
                Add_price(T, Init(A));
            }
            system("cls");
            Print_price(T, price);
            system("pause");
            break;
        }
        case 4:
        {
            char a;
            cout << "Letter = "; cin >> a;
            while (getline(file, line))
            {
                istringstream line_F(line);
                line_F >> A.filling >> A.weight >> A.restaurant >> A.price;
                Add_color(T, Init(A));
            }
            system("cls");
            Print_color(T, a);
            system("pause");
            break;
        }
        }
        Delete(T);
        file.close();
    }
    return 0;
}
