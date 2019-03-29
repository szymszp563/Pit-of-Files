#include <iostream>

#include "Tablica.h"

using namespace std;

int main()
{
	Tablica<int, 9>tab1;
	Tablica<double, 11>tab2;
	double sto = 100;
	double sto1 = 100;
	tab1.wypisz();
	tab1.sortuj();
	tab1.wypisz();
	tab2.wypisz();
	tab2.sortuj();
	tab2.wypisz();

	for (int n = 0; n < 9; n++)
	{
		try
		{
			sto = dziel<int>(100, tab1.pokaz(n));
			cout << "wynik dzielenia: " << n << " elementu tablicy typu int: " << sto << endl;
		}
		catch (const char * s)
		{
			cout << s << endl;
		}
	}

	for (int n = 0; n < 11; n++)
	{
		try
		{
			sto1 = dziel<double>(100, tab2.pokaz(n));
			cout << "wynik dzielenia: " << n << " elementu tablicy typu double: " << sto1 << endl;
		}
		catch (const char * s)
		{
			cout << s << endl;
		}
	}
	
	int itab1[10] = { 0, 3, 0, 6, 4, 0, 6, 1, 5, 9 };//0 - 306 - 40615 - 2 <-testowany rzeczywisty numer, ostatnia liczba to oczekiwany wynik
	int itab2[13] = { 9, 7, 8, 8, 3, 7, 1, 8, 1, 5, 1, 0, 4 };//978-83-7181-510-2

	itab1[9] = isbn<10>(itab1);
	itab2[12] = isbn<13>(itab2);

	cout << "numer isbn dla tablicy 10-cio elementowej: " << itab1[9] << endl;
	cout << "numer isbn dla tablicy 13-to elementowej: " << itab2[12] << endl;

	auto lambda = [](double x)->double
	{
		return x*x;
	};

	cout << "lambda robi kwadrat liczby 5: " << lambda(5) << endl;
	cout << "lambda robi kwadrat liczby 55.55: " << lambda(55.55) << endl;

	return 0;
}