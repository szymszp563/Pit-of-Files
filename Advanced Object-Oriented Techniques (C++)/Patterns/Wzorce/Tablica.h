#pragma once
#include <ctime>
#include <math.h>
#include<iostream>
#include "Funkcje.h"

using namespace std;

template<class T, int i>

class Tablica
{
private:
	T tab[i];

public:
	Tablica()
	{
		srand(time(0));
		for (int j = 0; j < i; j++)
		{
			tab[j] = rand() % 5000;
			tab[j] = tab[j] / 100;
		}

	}


	void sortuj()
	{
		for (int j = 0; j < i; j++)
			for (int k = 0; k < i - 1; k++)
			{
				if (tab[k] > tab[k + 1])
					zmien(tab[k], tab[k + 1]);
			}
	}

	void wypisz()
	{
		cout << "Wszystkie elementy tablicy " << i << " elementowej:" << endl;
		for (int j = 0; j < i; j++)
			cout << j << " elemnet tablicy: " << tab[j] << endl;
	}

	T pokaz(int j)
	{
		return tab[j];
	}

};