#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct rabbit
{
	string kind;
	double weight;
	float height;
	int age;
};
struct stack
{
	struct node
	{
		rabbit data;
		node *prev;
	};
	node *top = NULL;
	int count = 0;
	bool push(rabbit);
	bool pop(rabbit&);
	void info();
};
bool stack::push(rabbit dt)
{
	if (!top)
	{
		top = new node;
		top->prev = NULL;
		count = 1;
	}
	else
	{
		node *temp;
		temp = new node;
		temp->prev = top;
		top = temp;
		count++;
	}
	top->data = dt;
	return true;
}
bool stack::pop(rabbit& dt)
{
	if (!top) return false;
	node *temp = top->prev;
	dt = top->data;
	delete top;
	top = temp;
	count--;
	return true;
}
void stack::info()
{
	if (!top) cout << "stack is empty" << endl;
	else
	{
		cout << endl << "stack info: " << endl;
		cout << "\tstack size = " << count << endl;
		cout << "\ttop kind = " << top->data.kind << endl;
		cout << "\ttop weight = " << top->data.weight << endl;
		cout << "\ttop height = " << top->data.height << endl;
		cout << "\ttop age = " << top->data.age << endl << endl;
	}
}
void print(stack &S, stack &V)
{
	rabbit dt;
	while (S.count)
	{
		S.pop(dt);
		cout << "\tkind = " << dt.kind << endl;
		cout << "\tweight = " << dt.weight << endl;
		cout << "\theight = " << dt.height << endl;
		cout << "\tage = " << dt.age << endl << endl;
		V.push(dt);
	}
	while (V.count)
	{
		V.pop(dt);
		S.push(dt);
	}
}
int main()
{
	stack S;
	stack V;
	rabbit dt;
	ifstream file("rab.txt");
	string line;
	while (getline(file, line))
	{
		istringstream line_F(line);
		line_F >> dt.kind >> dt.weight >> dt.height >> dt.age;
		S.push(dt);
	}
	file.close();
	int m = 1;
	while (m)
	{
		S.info();
		cout << "1. add to basket" << endl;
		cout << "2. pull from basket" << endl;
		cout << "3. clear basket" << endl;
		cout << "4. show basket contents" << endl;
		cout << "0. exit" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
		{
			system("cls");
			cout << "enter product specifications:" << endl;
			cout << "kind = "; cin >> dt.kind;
			cout << "weight = "; cin >> dt.weight;
			cout << "height = "; cin >> dt.height;
			cout << "age = "; cin >> dt.age;
			S.push(dt);
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			rabbit dt_x;
			bool metka = false;
			cout << "enter product specifications:" << endl;
			cout << "kind = "; cin >> dt_x.kind;
			cout << "weight = "; cin >> dt_x.weight;
			cout << "height = "; cin >> dt_x.height;
			cout << "age = "; cin >> dt_x.age;
			while (S.count)
			{
				S.pop(dt);
				if (dt.kind != dt_x.kind || dt.weight != dt_x.weight || dt.height != dt_x.height || dt.age != dt_x.age)
				{
					V.push(dt);
				}
				else
				{
					metka = true;
					break;
				}
			}
			if (!metka) cout << "product not found" << endl;
			while (V.count)
			{
				V.pop(dt);
				S.push(dt);
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			while (S.count)
			{
				S.pop(dt);
			}
			break;
		}
		case 4:
		{
			system("cls");
			print(S, V);
			system("pause");
			system("cls");
			break;
		}
		}
	}
}