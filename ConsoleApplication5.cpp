#include <iostream>
#include <fstream>
using namespace std;


double *CreateArr(int);
void FillArr(double*, int);
void PrintArr(double*, int);
void f2(double*&, int&, double f);
void f3(double*&, int&, double f);
void f4(double*&, int&);
void f5(double*&, int&);
void f6(double*&, int&);
void f8(double*& arr, int &n);
void f7(double*& arr, int &n, double f, double x);
void Menu(double*&, int&);
void number_menu(double &f);
int N();

int main() {
	setlocale(LC_ALL, "Ru");
	int n = N();
	double *arr = CreateArr(n);
	FillArr(arr, n);




	cout << "Исходный массив:\n";
	PrintArr(arr, n);
	Menu(arr, n);
	delete[] arr;//очистка памяти 
}

double *CreateArr(int n) {
	double *arr = new double[n];// Выделение памяти для массива
	return arr;
}

void PrintArr(double* arr, int n) {//Вывод массива
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void FillArr(double* arr, int n) {
	int N();
	fstream ar("D:\\lab1\\array.txt", ios::in);
	for (int i = 0; i < n; i++)
	{
		ar >> arr[i];
	}
	ar.close();
}
int N()
{
	double a;
	int n = 0;
	fstream ar("D:\\lab1\\array.txt", ios::in);
	while (ar >> a)
	{
		n++;
	}
	ar.close();
	return n;
}


void Menu(double*& arr, int &n)
{
	double f;
	int key;

	do
	{
		cout << " ----- " << endl;
		cout << " 1 - добавить элемент в конец массива" << endl;
		cout << " 2 - добавить элемент в начало массива" << endl;
		cout << " 3 - добавить элемент на k-ую позицию в массиве" << endl;
		cout << " 4 - удалить последний элемент массива" << endl;
		cout << " 5 - удалить первый элемент массива" << endl;
		cout << " 6 - удалить k-ый элемент массива" << endl;
		cout << " 7 - добавить элемент массива после первого встреченного элемента с заданным значением" << endl;
		cout << " 8 - удалить все элементы массива с заданным значением" << endl;
		cout << " 0 - выход" << endl;
		cout << " ----- " << endl;

		cin >> key;

		switch (key)
		{
		case 1:    number_menu(f); f3(arr, n, f); PrintArr(arr, n); break;
		case 2:    number_menu(f); f2(arr, n, f); PrintArr(arr, n); break;
		case 3:    number_menu(f); f3(arr, n, f); PrintArr(arr, n); break;
		case 4:     f4(arr, n); PrintArr(arr, n); break;
		case 5:     f5(arr, n); PrintArr(arr, n); break;
		case 6:     f6(arr, n); PrintArr(arr, n); break;
		case 7:   double x; cout << "Введите элемент массива, после которого хотите добавить значение: "; cin >> x;
			number_menu(f); f7(arr, n, f, x); PrintArr(arr, n); break;
		case 8:    f8(arr, n); PrintArr(arr, n); break;
		case 0:     cout << "До свидания" << endl; return;
		default:    cout << "--->Ошибка, попробуйте снова... " << endl;
		}
	} while (key);
}
void f2(double *&arr, int &n, double f) {
	double *buff = new double[n + 1];
	buff[0] = f;
	for (int i = 1; i < n + 1; i++) {
		buff[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buff;
	n++;
}
void f3(double *&arr, int &n, double f)
{
	int k;
	cout << "Введите k: ";
	cin >> k;
	if (k >= 0 && k <= n + 1)
	{
		double* buff = new double[n + 1];
		for (int i = 0; i < k - 1; i++) {
			buff[i] = arr[i];
		}
		buff[k - 1] = f;
		for (int i = k; i < n + 1; i++) {
			buff[i] = arr[i - 1];
		}
		delete[] arr;
		arr = buff;
		n++;
	}
	else   cout << "Ошибка\n";
}
void f4(double *&arr, int &n) {
	n--;
	double *buff = new double[n];
	for (int i = 0; i < n; i++) {
		buff[i] = arr[i];
	}
	delete[] arr;
	arr = buff;
}
void f5(double *&arr, int &n) {
	n--;
	double *buff = new double[n];
	for (int i = 0; i < n; i++) {
		buff[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buff;
}
void f6(double *&arr, int& n)
{
	int k;
	cout << "Введите k: ";
	cin >> k;
	if (k >= 0 && k <= n)
	{
		double *buff = new double[n - 1];
		for (int i = 0; i < k - 1; i++) {
			buff[i] = arr[i];
		}
		n--;
		for (int i = k - 1; i < n + 1; i++) {
			buff[i] = arr[i + 1];
		}
		delete[] arr;
		arr = buff;
	}
	else   cout << "Ошибка\n";
}

void number_menu(double &f)
{
	int m = 1;
	cout << "Какое значение хотите поставить?" << endl;
	cout << "1 - случайно сгенерированное" << endl;
	cout << "2 - введенное с клавиатуры" << endl;
	cin >> m;
	switch (m)
	{
	case 1:
	{
		f = 1.0 + 4.0*rand() / (float)RAND_MAX;;
		m = 0;
		break;
	}
	case 2:
	{
		cout << "Введите значение: ";
		cin >> f;
		m = 0;
		break;
	}
	default:
	{
		cout << "Ошибка, попытайтесь снова" << endl;
		break;
	}
	}
}
void f7(double*& arr, int &n, double f, double x)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			k++;
			break;
		}

	}
	if (k > 0)
	{
		double* buff = new double[n + 1];
		for (int i = 0; i < k+1 ; i++)
		{
			buff[i] = arr[i];
		}
		n++;
		buff[k+1] = f;
		for (int i = k+2; i < n; i++) {
			buff[i] = arr[i-1];
		}
		delete[] arr;
		arr = buff;
	}
	else cout << "Элемент не найден" << endl;
}
void f8(double*& arr, int &n)
{
	double x;
	cout << "Введите элемент, который хотите удалить: "; cin >> x;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			k++;
		}
	}
	if (k > 0)
	{
		k = 0;
		double* buff = new double[n - k];
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == x)
			{
				k++;
			}
			else buff[i - k] = arr[i];
		}
		n -= k;
		delete[] arr;
		arr = buff;
	}
	else cout << "Элемент не найден\n";
}