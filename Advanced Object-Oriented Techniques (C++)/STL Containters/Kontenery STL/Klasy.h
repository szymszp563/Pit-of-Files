#pragma once
#include <ctime>
using namespace std;

class Obywatel
{
private:
	int day;
	int month;
	int year;
	char sex;
public:
	Obywatel(int _day, int _month, int _year, char _sex)
	{
		day = _day;
		month = _month;
		year = _year;
		sex = _sex;
	}

	void check_date()
	{
		if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2099)
			throw 1;
	}

	int check_sex()
	{
		if (sex == 'k' || sex == 'K')
			return 1;
		if (sex == 'm' || sex == 'M')
			return 0;
		else
			throw 2;
	}
	
	vector<int> pesel()
	{
		vector<int> _pesel;
		
		/*Liczby peselu dla roku*/
		int yyear = year - 1900;
		int smallyyear = yyear / 10;
		_pesel.push_back(smallyyear);
		_pesel.push_back(yyear - smallyyear * 10);
		
		/*Liczby peselu dla miesi¹ca*/
		if (year < 2000)
		{
			int smallmonth = month / 10;
			_pesel.push_back(smallmonth);
			_pesel.push_back(month - smallmonth * 10);
		}
		else
		{
			int mmonth = month + 20;
			int smallmonth = mmonth / 10;
			_pesel.push_back(smallmonth);
			_pesel.push_back(mmonth - smallmonth * 10);
		}

		/*Liczby peselu dla dni*/
		int smallday = day / 10;
		_pesel.push_back(smallday);
		_pesel.push_back(day - smallday * 10);

		/*Liczby peselu losowe*/
		_pesel.push_back(rand() % 9);
		_pesel.push_back(rand() % 9);
		_pesel.push_back(rand() % 9);
	
		/*Liczba peselu dla p³ci*/
		if (this->check_sex() == 1)
		{
			int a = 2 * (rand() % 9);
			if (a > 9)
				_pesel.push_back(a - 10);
			else
				_pesel.push_back(a);
		}
		else
		{
			int a = 1 + 2 * (rand() % 9);
			if (a > 9)
				_pesel.push_back(a - 10);
			else
				_pesel.push_back(a);
		}

		/*Liczba peselu dla sumy kontrolnej*/
		int suma = _pesel[0] + _pesel[1] * 3 + _pesel[2] * 7 + _pesel[3] * 9 + _pesel[4] + _pesel[5] * 3 + _pesel[6] * 7 + _pesel[7] * 9 + _pesel[8] + _pesel[9] * 3;
		int suma2 = 10 - (suma % 10);
		if (suma2 == 10)
			_pesel.push_back(0);
		else
			_pesel.push_back(suma2);

		return _pesel;		
	}

	void show_date()
	{
		cout << day << "-" << month << "-" << year << " ";
	}
};

class Funktor_sort
{

public:
	bool operator ()(int a, int b)
	{
		return a < b;
	}
};