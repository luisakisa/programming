#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct product_group
{
	int quantity;
	double price;
};
struct MyQueue
{
	struct Node
	{
		product_group data;
		Node* next;
	};
	Node* First = NULL;
	int count = 0;
	double full_cost = 0;
	double full_quantity = 0;
	double income = 0;
	bool push(product_group);
	bool pop(product_group&);
	void Delete(product_group&);
	void Info();
};
bool MyQueue::push(product_group dt)
{
	if (!First)
	{
		First = new Node;
		First->next = NULL;
		First->data = dt;
		count = 1;
		full_cost += dt.price * dt.quantity;
		full_quantity += dt.quantity;
	}
	else
	{
		Node* temp;
		temp = First;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new Node;
		temp->next->data = dt;
		temp->next->next = NULL;
		count++;
		full_cost += dt.price * dt.quantity;
		full_quantity += dt.quantity;
	}
	return true;
}
bool MyQueue::pop(product_group& dt)
{
	if (!First) return false;
	Node* temp = First->next;
	dt = First->data;
	delete First;
	First = temp;
	count--;
	return true;
}
void MyQueue::Info()
{
	if (!First) cout << "warehouse is empty" << endl;
	else
	{
		cout << endl << "Info " << endl;
		cout << "\tNumbers of products group = " << count << endl;
		cout << "\tFirst quantity = " << First->data.quantity << endl;
		cout << "\tFirst price = " << First->data.price <<  endl;
		cout << "\tNumbers of products = " << full_quantity << endl;
	}
}
bool check(MyQueue Q, product_group dt_x)
{
	product_group dt;
	MyQueue::Node* a;
	a = Q.First;
	int k = 0;
	while (a->data.price <= dt_x.price & k != Q.count & dt_x.quantity <= Q.full_quantity)
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
	MyQueue Q;
	product_group dt;
	product_group dt_x;
	ifstream file("prod.txt");
	string line;
	while (getline(file, line))
	{
		istringstream line_F(line);
		line_F >> dt.quantity >> dt.price;
		Q.push(dt);
	}
	file.close();
	int m = 1;
	while (m)
	{
		Q.Info();
		cout << "1. Receipt" << endl;
		cout << "2. Sell" << endl;
		cout << "3. Report" << endl;
		cout << "0. Exit" << endl;
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
			dt = Q.First->data;
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
						Q.First->data.quantity = dt.quantity;
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
						dt = Q.First->data;
					}
				}
				cout << "Completed" << endl;
			}
			else cout << "Was not made :(" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Number of product = " << Q.count << endl;
			cout << "Product price = " << Q.full_cost << endl;
			cout << "Income from sale = " << Q.income << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
	Q.Delete(dt);
	return 0;

}
void MyQueue::Delete(product_group& G)
{
	while (count != 0)
		pop(G);
}
