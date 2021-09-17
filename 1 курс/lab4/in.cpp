#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct product
{
	string brand;
	double cost;
    int mileage;
    double weight;
  
};
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
void PrintBinaryFile(char* data, int n)
{
  fstream f_out("out.dat", ios::app | ios::binary);
  f_out.write((char*) &n, sizeof(int));
  f_out.write(data, n);
  f_out.close();
}
int main()
{
  char* data;
  int n = 0;
  product A[3] =
  {
    {"toyota", 23.2 , 23, 23.2},
    {"citroen", 22.2, 22, 22.2},
    {"honda", 21.2, 21, 21.2}
  };
  for(int i = 0; i < 3; i++)
  {
    GetSeria(data, n, A[i]);
    PrintBinaryFile(data, n);
    delete[] data;
  }
}
