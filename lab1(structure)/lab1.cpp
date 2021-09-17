#include <iostream>
#include <fstream>

using namespace std;

void fillarr(int* arr, int& n);


struct datetime {
	int second, minute, hour, day, month, year;
	int* MONTH = new int[12];

	void out();
	void getNext(int& m1);
	void getPrev(int& m2);

};

void month_fill(datetime day_of_month);

int main()
{
	int n = 0;
	int* arr = new int[255];
	fillarr(arr, n);

	datetime* date_list = new datetime[n];

	for (int i = 0; i < n; i += 6)
	{
		date_list[i / 6].second = arr[i];
		date_list[i / 6].minute = arr[i + 1];
		date_list[i / 6].hour = arr[i + 2];
		date_list[i / 6].day = arr[i + 3];
		date_list[i / 6].month = arr[i + 4];
		date_list[i / 6].year = arr[i + 5];
		month_fill(date_list[i / 6]);
	}

	delete new int[255];
	for (int j = 0; j < n/6; j++) {
		if (date_list[j].second < 1 || date_list[j].second > 59 || date_list[j].minute < 1 || date_list[j].minute > 59 || date_list[j].hour < 1 || date_list[j].hour > 23 || date_list[j].month < 1 || date_list[j].month > 12 || date_list[j].year < 1 || date_list[j].day < 1 || (date_list[j].month == 1 || date_list[j].month == 3 || date_list[j].month == 5 || date_list[j].month == 7 || date_list[j].month == 8 || date_list[j].month == 10 || date_list[j].month == 12) && date_list[j].day > 31 || (date_list[j].month == 4 || date_list[j].month == 6 || date_list[j].month == 9 || date_list[j].month == 11) && date_list[j].day > 30 || (date_list[j].month == 2 && date_list[j].year % 4 == 0 && date_list[j].day > 29) || (date_list[j].month == 2 && date_list[j].year % 4 != 0 && date_list[j].day > 28))   {
			cout << "Data is incorrect" << endl;
			return 0;
		}
	}

	int m1 = 1;
	int m2 = 1;

	int ch = 0;

	for (int i = 0; i < n / 6; i++) {
		cout << i + 1 << endl;
		date_list[i].out();
		date_list[i].getNext(m1);
		date_list[i].out();
		date_list[i].getPrev(m2);
		date_list[i].out();

		if (!m1 || !m2) {
			int l = 0;
			if (i < n / 6) {
				date_list[i] = date_list[i + 1];
				i++;
				l++;
			}
			ch++;
			i -= l;
		}
	}
	cout << "Variant 9" << endl;
	for (int i = 0; i < n / 6 - ch; i++) {
		cout << i + 1 << endl;
		date_list[i].day += 1;
		date_list[i].out();
		date_list[i].getNext(m1);
		date_list[i].out();
		date_list[i].getPrev(m2);
		date_list[i].out();
	}

	delete new datetime[n];

	return 0;
}

void datetime::out() {
	cout << second << ":" << minute << ":" << hour << ", " << day << "." << month << "." << year << endl;
}
void fillarr(int* arr, int& n)
{
	ifstream A("data_array.txt", ios::in);
	if (!A)
	{
		cout << "File is empty" << endl;
	}
	else {
		while (!A.eof())
		{
			A >> arr[n];
			n++;
		}
	}
	A.close();
}

void datetime::getNext(int& metka) {
	day++;
	metka = 1;
	if (day > MONTH[month - 1])
	{
		metka = 0;
		month++;
		if (month > 12)
		{
			year++;
			month = 1;
		}
		day = 1;
	}

}
void datetime::getPrev(int& metka)
{
	for (int i = 0; i < 2; i++) {
		day--;
		metka = 1;
		if (day < 1)
		{
			metka = 0;
			month--;
			if (month < 1)
			{
				year--;
				if (year % 4 == 0)
				{
					MONTH[1] = 29;
				}
				else
				{
					MONTH[1] = 28;
				}
				month = 12;
			}
			day = MONTH[month - 1];

		}
	}
}
void month_fill(datetime d)
{
	d.MONTH[0] = 31;
	if (d.year % 4 == 0) 
	{
		d.MONTH[1] = 29; //Високосный
	}
	else
	{
		d.MONTH[1] = 28;//Не високосный
	}
	d.MONTH[2] = 31;
	d.MONTH[3] = 30;
	d.MONTH[4] = 31;
	d.MONTH[5] = 30;
	d.MONTH[6] = 31;
	d.MONTH[7] = 31;
	d.MONTH[8] = 30;
	d.MONTH[9] = 31;
	d.MONTH[10] = 30;
	d.MONTH[11] = 31;
}