#include <iostream>
#include <fstream>
#include <sstream>
#include "Flower.h"
#include "Tree.h"
using namespace std;
int main()
{
    Flower A;
    Tree* T = NULL;
    int m = 1;
    while (m)
    {
        ifstream file("Flowers.txt");
        string line;
        system("cls");
        cout << endl << endl;
        cout << "1. Sort by kind" << endl;
        cout << "2. Sort by cost" << endl;
        cout << "3. Show Flowers cheaper than the specified cost" << endl;
        cout << "4. Show Flowers that start with the specified letter" << endl;
        cout << "0. Exit" << endl << endl;
        cin >> m;
        switch (m)
        {
        case 1:
        {
            while (getline(file, line))
            {
                istringstream line_F(line);
                line_F >> A.cost >> A.color >> A.quantity >> A.kind;
                Add_kind(T, Init(A));
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
                line_F >> A.cost >> A.color >> A.quantity >> A.kind;
                Add_cost(T, Init(A));
            }
            system("cls");
            Print(T);
            system("pause");
            break;
        }
        case 3:
        {
            float cost;
            cout << "cost = "; cin >> cost;
            while (getline(file, line))
            {
                istringstream line_F(line);
                line_F >> A.cost >> A.color >> A.quantity >> A.kind;
                Add_cost(T, Init(A));
            }
            system("cls");
            Print_kind(T, cost);
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
                line_F >> A.cost >> A.color >> A.quantity >> A.kind;
                Add_kind(T, Init(A));
            }
            system("cls");
            Print_kind(T, a);
            system("pause");
            break;
        }
        }
        Delete(T);
        file.close();
    }
    return 0;
}
