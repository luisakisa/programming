#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int size();
void newMatr(double**& M, int n, int m);//создание матрицы
void delMatr(double**& M, int n, int m);//удаление матрицы
void printMatr(double** M, int n, int m, const char* namematr);//вывод матрицы
void printVect(double* x, int n, const char* namematr);//вывод переменных
bool minor(double**& M, int n, int m, double &Det);//приведение к ступенчатому виду
void permutation(double**& M, int n, int m, int k, double &Det);//перестановка строк местами
bool solve(double **&M, double *x, int n, int m, double &Det);
double det(double** M, int n);//Определитель
void choice(double**& M, int n, int m);//Погрешность
void copy(double**& M, int n, int m, double** M1);//дублируем матрицу
double check(double** M1, int n, int m, double *x);
bool reverb(double** A, int n, int m, double &Det, double**& rev);//обратная матрица
void checkRev(double** M1, double** M2, int n1, int m1, int n2, int m2);
int main()
{
	int n;
	double Det = 1;
	cout << "Enter size matrix: "; n = size();
	int m = n + 1;
	double **A;
	double **A1;
	double **rev;
	double *x = new double[n];
	newMatr(A, n, m);
	choice(A, n, m);
	newMatr(A1, n, m);
	copy(A, n, m, A1);
	newMatr(rev, n, n);
	printMatr(A, n, m, "A");
	if (solve(A, x, n, m, Det))
	{
		printVect(x, n, "x");
		cout << "delta = " << check(A1, n, m, x) << endl << endl;
	}
	else cout << "no single solution" << endl;
	cout << "det = " << Det * det(A, n) << endl;
	if (reverb(A1, n, m, Det, rev))
	{
		printMatr(rev, n, n, "rev");
		checkRev(A1, rev, n, m - 1, n, n);
	}
	else cout << "no reverse" << endl;
	delMatr(A, n, m);
	delMatr(A1, n, m);
	delMatr(rev, n, n);
	delete[] x;
	x = NULL;
	return 0;
}
int size()
{
	float n;
	do
	{
		cin >> n;
		if (n <= 0 || (n - (int)n))
			cout << " ---Error, try again..." << endl;
	} while (n <= 0 || (n - (int)n));
	return n;
}
void newMatr(double**& M, int n, int m)
{
	M = new double*[n];
	for (int i = 0; i < n; i++)
		M[i] = new double[m];
}
void delMatr(double**& M, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete[] M[i];
	delete[] M;
}
void printMatr(double** M, int n, int m, const char* namematr)
{
	cout << endl << " " << namematr << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(15) << M[i][j];
		cout << endl;
	}
	cout << endl;
}
void printVect(double* x, int n, const char* namematr)
{
	cout << endl << " " << namematr << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << x[i];
		cout << endl;
	}
	cout << endl;
}
void permutation(double**& M, int n, int m, int k, double &Det)
{
	for (int i = k + 1; i < n; i++)
	{
		if (M[i][k] != 0)
		{
			double temp;
			for (int i1 = 0; i1 < m; i1++)
			{
				temp = M[k][i1];
				M[k][i1] = M[i][i1];
				M[i][i1] = temp;
			}
			Det *= -1;
			break;
		}
	}
}
bool minor(double**& M, int n, int m, double &Det)
{
	for (int i = 0; i < n; i++)
	{
		if (M[i][i] == 0) permutation(M, n, m, i, Det);
		if (M[i][i] == 0) return false;
		for (int i1 = i + 1; i1 < n; i1++)
			for (int i2 = i + 1; i2 < m; i2++)
				M[i1][i2] = M[i][i] * M[i1][i2] - M[i][i2] * M[i1][i];
		for (int j = i + 1; j < n; j++)
		{
			M[j][i] = 0;
		}
	}
	return true;
}
bool solve(double **&M, double *x, int n, int m, double &Det)
{
	double res = 0;
	if (!minor(M, n, m, Det)) return false;
	for (int i = n - 1; i >= 0; i--)
	{
		res = 0;
		for (int j = i + 1; j <= n - 1; j++)
			res = res - x[j] * M[i][j];
		res += M[i][n];
		x[i] = res / M[i][i];
	}
	return true;
}
double det(double** M, int n)
{
	double det = 1;
	for (int i = 0; i < n; i++)
	{
		if (M[i][i] == 0) return 0;
		det *= M[i][i] / pow(M[i][i], n - 1 - i);
	}
	return det;
}
void choice(double**& M, int n, int m)
{
	int k;
	cout << "Enter number: " << endl;
	cout << "1 to get matrix from file " << endl;
	cout << "2 to get random matrix " << endl;
	cout << "3 to get single matrix " << endl;
	cout << "4 to get zero matrix " << endl;
	cout << "5 to get Gilbert matrix " << endl;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		fstream A("array.txt", ios::in);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A >> M[i][j];
		A.close();
		break;
	}
	case 2:
	{
		double a, b;
		srand(time(0));
		a = -10;
		b = 10;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				M[i][j] = a + ((double)rand() / RAND_MAX) * (b - a);
			}
		break;
	}
	case 3:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (i == j) M[i][j] = 1;
				else M[i][j] = 0;
		break;
	}
	case 4:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M[i][j] = 0;
		break;
	}
	case 5:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M[i][j] = 1. / (i + j + 1);
		break;
	}
	}
}
void copy(double**& M, int n, int m, double** M1)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M1[i][j] = M[i][j];
}
double check(double** M1, int n, int m, double *x)
{
	double delta = 0;
	double s;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int k = 0; k < m - 1; k++)
			s += M1[i][k] * x[k];
		if (fabs(M1[i][m - 1] - s) > delta) delta = fabs(M1[i][m - 1] - s);
	}
	return delta;
}
bool reverb(double** M, int n, int m, double &Det, double**& rev)
{
	double *x = new double[n];
	bool metka = true;
	for (int i = 0; i < n; i++)
	{
		double** buff;
		newMatr(buff, n, m);
		copy(M, n, m, buff);
		for (int j = 0; j < n; j++)
		{
			if (i == j) buff[j][m - 1] = 1;
			else buff[j][m - 1] = 0;
		}
		if (!solve(buff, x, n, m, Det)) metka = false;
		for (int j = 0; j < n; j++)
			rev[j][i] = x[j];
		delMatr(buff, n, m);
	}
	delete[] x;
	x = NULL;
	return metka;
}
void checkRev(double** M1, double** M2, int n1, int m1, int n2, int m2) {
	double** buff;
	newMatr(buff, n1, m2);
	double S;
	if (m1 != n2)
	{
		cout << "error" << endl;
		delMatr(buff, n1, m2);
	}
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m2; j++)
		{
			S = 0;
			for (int k = 0; k < m1; k++)
				S += M1[i][k] * M2[k][j];
			buff[i][j] = S;
		}
	printMatr(buff, n1, m2, "check");
	delMatr(buff, n1, m2);
}