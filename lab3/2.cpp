#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct product
{
	int quantity;
	double price;
};
struct stock
{
	struct node
	{
		product data;
		node* next;
	};
	node* first = NULL;
	int count = 0;
	double full_cost = 0;
	double income = 0;
	bool push(product);
	bool pop(product&);
	void info();
};
bool stock::push(product dt)
{
	if (!first)
	{
		first = new node;
		first->next = NULL;
		first->data = dt;
		count = 1;
		full_cost += dt.price * dt.quantity;
	}
	else
	{
		node *temp;
		temp = first;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new node;
		temp->next->data = dt;
		temp->next->next = NULL;
		count++;
		full_cost += dt.price * dt.quantity;
	}
	return true;
}
bool stock::pop(product& dt)
{
	if (!first) return false;
	node* temp = first->next;
	dt = first->data;
	delete first;
	first = temp;
	count--;
	return true;
}
void stock::info()
{
	if (!first) cout << "The warehouse is empty" << endl;
	else
	{
		cout << endl << "Info: " << endl;
		cout << "\tNumber of products group = " << count << endl;
		cout << "\tFirst quantity = " << first->data.quantity << endl;
		cout << "\tFirst price = " << first->data.price << endl << endl;
	}
}
bool check(stock Q, product dt_x)
{
	product dt;
	stock::node *a;
	a = Q.first;
	int k = 0;
	while (a->data.price <= dt_x.price & k != Q.count)
	{
		dt.price = a->data.price;
		dt.quantity = a->data.quantity;
		if (dt_x.quantity <= dt.quantity)
		{
			dt_x.quantity = 0;
		}
		else
		{
			dt_x.quantity -= dt.quantity;
		}
		if (dt_x.quantity == 0)
		{
			return true;
		}
		else
		{
			if (k < Q.count)
			{
				k++;
				a = a->next;
			}
			else return false;
		}
	}
	return false;
}
int main()
{
	stock Q;

	product dt_x;
	product dt, dt1 = { 5,20.5 }, dt2 = { 10,15.5 };


	Q.push(dt1);
	Q.push(dt2);
	int m = 1;
	while (m)
	{
		Q.info();
		cout << "1. receipt" << endl;
		cout << "2. sell" << endl;
		cout << "3. report" << endl;
		cout << "0. exit" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
		{
			system("cls");
			cout << "Enter the price and quantity of the product:" << endl;
			cout << "Quantity = "; cin >> dt.quantity;
			cout << "Price = "; cin >> dt.price;
			Q.push(dt);
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Enter the price and quantity of the product:" << endl;
			cout << "Quantity = "; cin >> dt_x.quantity;
			cout << "Price = "; cin >> dt_x.price;
			dt = Q.first->data;
			if (check(Q, dt_x))
			{
				while (dt_x.quantity)
				{
					if (dt_x.quantity <= dt.quantity)
					{
						Q.income += dt_x.quantity * (dt_x.price - dt.price);
						Q.full_cost -= dt.price * dt_x.quantity;
						dt.quantity -= dt_x.quantity;
						dt_x.quantity = 0;
						Q.first->data.quantity = dt.quantity;
					}
					else
					{
						Q.income += dt.quantity * (dt_x.price - dt.price);
						Q.full_cost -= dt.price * dt.quantity;
						dt_x.quantity -= dt.quantity;
						dt.quantity = 0;
					}
					if (dt.quantity == 0)
					{
						Q.pop(dt);
						dt = Q.first->data;
					}
				}
				cout << "Completed" << endl;
			}
			else cout << "Сannot be done" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Count = " << Q.count << endl;
			cout << "Full cost = " << Q.full_cost << endl;
			cout << "Income = " << Q.income << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}

