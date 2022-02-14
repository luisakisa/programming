#include <iostream>
#include <fstream>

using namespace std;


class datetime {
public:
	int MONTH[12];
	int second, minute, hour, day, month, year;
	bool getNext();
	bool getPrev();
	void month_fill();
	datetime(int s, int m, int h, int d, int mn, int y);
	datetime() {};
	~datetime() {};
};
class base {
private:
	int n = 0;
	datetime* date_list = new datetime[255];

public:
	void out(const datetime&);
	void fillarr();
	void all_dates();
	~base();
};
base::~base() {
	delete[] date_list;
}
class application {
public:
	void start();
private:
	void print_menu();
};

datetime::datetime(int s, int m, int h, int d, int mn, int y) {
	second = s;
	minute = m; hour = h; day = d; month = mn; year = y;
	month_fill();
};

void application::print_menu() {
	int m = 1;
	while (m)
	{
		cout << "What do you want to do?" << endl;
		cout << "1. Show all dates" << endl;
		cout << "0. Exit" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
		{
			system("cls");
			base b;
			b.fillarr();
			b.all_dates();
			system("pause");
			system("cls");
			break;
		}
		}
	}
}
int main()
{
	application app;
	app.start();
	return 0;
}

void application::start() {
	print_menu();
}

void base::out(const datetime& a) {
	cout << a.second << ":" << a.minute << ":" << a.hour << ", " << a.day << "." << a.month << "." << a.year << endl;
}
void base::all_dates() {
	for (int j = 0; j < n; j++) {
		if (date_list[j].second < 1 || date_list[j].second > 59 ||
			date_list[j].minute < 1 || date_list[j].minute > 59 ||
			date_list[j].hour < 1 || date_list[j].hour > 23 ||
			date_list[j].month < 1 || date_list[j].month > 12 ||
			date_list[j].year < 1 || date_list[j].day < 1 ||
			date_list[j].MONTH[date_list[j].month - 1] < date_list[j].day) {

			cout << "Date is incorrect" << endl;
			out(date_list[j]);
			return;
		}
	}

	int ch = 0;

	for (int i = 0; i < n; i++) {
		cout << i + 1 << endl;
		out(date_list[i]);
		bool m1, m2;
		m1 = date_list[i].getNext();
		out(date_list[i]);
		m2 = date_list[i].getPrev();
		out(date_list[i]);

		if (!m1 || !m2) {
			int l = 0;
			if (i < n) {
				date_list[i] = date_list[i + 1];
				i++;
				l++;
			}
			ch++;
			i -= l;
		}
	}


	cout << "Variant 9" << endl;
	for (int i = 0; i < n - ch; i++) {
		cout << i + 1 << endl;
		date_list[i].day += 1;
		out(date_list[i]);
		date_list[i].getNext();
		out(date_list[i]);
		date_list[i].getPrev();
		out(date_list[i]);
	}
}

void base::fillarr()
{
	ifstream A("data_array.txt");
	if (!A)
	{
		cout << "File is empty" << endl;
	}
	else {
		while (!A.eof())
		{
			int second, minute, hour, day, month, year;
			A >> second >> minute >> hour >> day >> month >> year;
			datetime a(second, minute, hour, day, month, year);
			date_list[n] = a;
			n++;

		}
	}
	A.close();

}

bool datetime::getNext() {
	day++;
	bool metka = true;
	if (day > MONTH[month - 1])
	{
		metka = false;
		month++;
		if (month > 12)
		{
			year++;
			month = 1;
		}
		day = 1;
	}
	return metka;
}
bool datetime::getPrev()
{
	bool metka;
	for (int i = 0; i < 2; i++) {
		day--;
		metka = true;
		if (day < 1)
		{
			metka = false;
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
	return metka;
}
void datetime::month_fill()
{
	MONTH[0] = 31;
	if (year % 4 == 0)
	{
		MONTH[1] = 29; //Високосный
	}
	else
	{
		MONTH[1] = 28;//Не високосный
	}
	MONTH[2] = 31;
	MONTH[3] = 30;
	MONTH[4] = 31;
	MONTH[5] = 30;
	MONTH[6] = 31;
	MONTH[7] = 31;
	MONTH[8] = 30;
	MONTH[9] = 31;
	MONTH[10] = 30;
	MONTH[11] = 31;

}
