#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
struct product //car
{
	string brand;
	double cost;
	int mileage;
	double weight;

};

struct node { int n; char* data; node* next; };

struct myqueue
{
	node* first = NULL;
	int count = 0;
	bool push(char*, int);
	bool pop(char*&, int&);
	void info();


};
bool myqueue::push(char* data, int n)
{
	if (!first)
	{
		first = new node;
		first->next = NULL;
		first->data = data;
		count = 1;
		first->n = n;
		first->data = new char[n];
		for (int i = 0; i < n; i++) {
			first->data[i] = data[i];
		}
	}
	else
	{
		node* temp;
		temp = first;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new node;
		temp->next->data = new char[n];

		temp->next->next = NULL;
		temp->next->n = n;
		for (int i = 0; i < n; i++) {
			temp->next->data[i] = data[i];

		}
		count++;

	}
	return true;
}
bool myqueue::pop(char*& data, int &n)
{
	if (!first) return false;
	node* temp = first->next;
	n = first->n;
	for (int i = 0; i < n; i++)
	{
		data[i] = first->data[i];

	}
	delete first->data;
	delete first;
	first = temp;
	count--;
	return true;
}
void myqueue::info()
{
	if (!first)
	{
		cout << "--->queue is empty" << endl;
	}
	else
	{
		cout << endl << "queue info: " << endl;
		cout << "\tQueue size = " << count << endl;

	}
}
void GetSeria(char*& data, int& n, product a)
{
	size_t s = a.brand.size();

	int n0 = sizeof(size_t);
	int n1 = s;
	int n2 = sizeof(double);
	int n3 = sizeof(int);
	int n4 = n2;

	n = n0 + n1 + n2 + n3 + n4;

	data = new char[n];

	char* d0 = reinterpret_cast<char*>(&s);
	char* d1 = const_cast<char*>(a.brand.c_str());
	char* d2 = reinterpret_cast<char*>(&a.cost);
	char* d3 = reinterpret_cast<char*>(&a.mileage);
	char* d4 = reinterpret_cast<char*>(&a.weight);

	for (int i = 0; i < n0; i++) data[i] = d0[i];
	for (int i = 0; i < n1; i++) data[i + n0] = d1[i];
	for (int i = 0; i < n2; i++) data[i + n0 + n1] = d2[i];
	for (int i = 0; i < n3; i++) data[i + n0 + n1 + n2] = d3[i];
	for (int i = 0; i < n4; i++) data[i + n0 + n1 + n2 + n3] = d4[i];

}
void GetDeSeria(char* data, int n, product& a)
{
	int n0, n1, n2, n3, n4;
	n0 = sizeof(size_t);
	n2 = sizeof(double);
	n3 = sizeof(int);
	n4 = sizeof(double);

	size_t p = *reinterpret_cast<size_t*>(data);
	n1 = p;

	string ss(data + n0, p);
	a.brand = ss;
	a.cost = *reinterpret_cast<double*>(data + n0 + n1);
	a.mileage = *reinterpret_cast<int*>(data + n0 + n1 + n2);
	a.weight = *reinterpret_cast<double*>(data + n0 + n1 + n2 + n3);
}
void show(product b)
{
	cout << "Car:";
	cout << "\t brand:" << b.brand
		<< "\t cost:" << b.cost
		<< "\t mileage:" << b.mileage
		<< "\t weight:" << b.weight << endl;

}
bool InputBinaryFile(myqueue &Q)
{
	fstream f_in("out.dat", ios::in | ios::binary);
	if (!f_in)
	{
		return false;
	}
	product A;
	int n = 0;
	while (!f_in.eof())
	{
		if (f_in.read((char*)&n, sizeof(int)))
		{
			char* data = new char[n];
			f_in.read(data, n);
			GetDeSeria(data, n, A);
			delete[] data;
			GetSeria(data, n, A);
			Q.push(data, n);
		}
	}
	f_in.close();
	return true;
}
int main()
{
	myqueue Q;
	char* data;
	int n = 0;
	int m = 1;
	product A;
	InputBinaryFile(Q);
	while (m)
	{
		cout << "1. Add" << endl;
		cout << "2. Pull out" << endl;
		cout << "3. Clear" << endl;
		cout << "0. Exit" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
		{
			system("cls");
			cout << "Enter product specifications:" << endl;
			cout << "Brand = "; cin >> A.brand;
			cout << "Cost = "; cin >> A.cost;
			cout << "Mileage = "; cin >> A.mileage;
			cout << "Weight = "; cin >> A.weight;
			GetSeria(data, n, A);
			Q.push(data, n);
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			product A_x;
			bool metka = false;
			cout << "Enter product specifications:" << endl;
			cout << "Brand = "; cin >> A_x.brand;
			cout << "Cost = "; cin >> A_x.cost;
			cout << "Mileage = "; cin >> A_x.mileage;
			cout << "Weight = "; cin >> A_x.weight;
			int Y = Q.count;
			for (int i = 0; i < Y; i++)
			{
				Q.pop(data, n);
				GetDeSeria(data, n, A);
				delete[] data;
				if (A.brand != A_x.brand || A.cost != A_x.cost || A.mileage != A_x.mileage || A.weight != A_x.weight)
				{
					GetSeria(data, n, A);
					Q.push(data, n);
				}
				else
				{
					metka = true;
					break;
				}
				
			}
			if (!metka) cout << "Product not found" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			while (Q.count)
			{
				Q.pop(data, n);
				GetDeSeria(data, n, A);
				delete[] data;
				cout << "Brand = " << A.brand << endl;
				cout << "Cost = " << A.cost << endl;
				cout << "Mileage = " << A.mileage << endl;
				cout << "Weight = " << A.weight << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		}
	}
	while (Q.count)
	{
		Q.pop(data, n);
		delete[] data;
	}
	return 0;
}