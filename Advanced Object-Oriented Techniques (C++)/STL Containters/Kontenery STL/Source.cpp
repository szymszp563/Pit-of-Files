#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

#include "Klasy.h"

using namespace std;

void wypisz_pesel(stack<vector<int>> pesele)
{
	vector<int>pesel = pesele.top();
	for (vector<int>::iterator iter = pesel.begin(); iter != pesel.end(); ++iter)
	{
		cout << *iter;
	}
}

int main()
{
	srand(time(0));
	Obywatel o1(1, 1, 1901, 'K');
	Obywatel o2(96, 3, 1943, 'k');//b³êdny dzieñ
	Obywatel o3(31, 21, 1993, 'M');//b³êdny miesi¹c
	Obywatel o4(12, 12, 996, 'K');//b³êdny rok
	Obywatel o5(18, 11, 2001, 'M');
	Obywatel o6(7, 9, 1999, 'J');//b³êdna p³eæ
	Obywatel o7(9, 2, 1996, 'm');

	vector<Obywatel> ob_vec;
	ob_vec.push_back(o1);
	ob_vec.push_back(o2);
	ob_vec.push_back(o3);
	ob_vec.push_back(o4);
	ob_vec.push_back(o5);
	ob_vec.push_back(o6);
	ob_vec.push_back(o7);
	vector<Obywatel>::iterator iter = ob_vec.begin();

	while(iter != ob_vec.end())
	{		
		try
		{
			iter->check_date();
			iter->check_sex();
			++iter;
		}
		
		catch (int i)
		{
			switch (i)
			{
			case 1: cout << "Podano niepoprawna date, obywatel zostanie usuniety!" << endl;
				iter = ob_vec.erase(iter);
				break;
			case 2: cout << "Podano niepoprawna plec, obywatel zostanie usuniety!" << endl;
				iter = ob_vec.erase(iter);
				break;
			default: cout << "default in switch" << endl;
				break;
			}
		}		
	}

	stack<vector<int>> pesele;
	pesele.push(o7.pesel());
	pesele.push(o5.pesel());
	pesele.push(o1.pesel());

	map<int, Obywatel>mapa_obywateli;
	
	mapa_obywateli.insert(pair<int, Obywatel>(1, o1));
	mapa_obywateli.insert(pair<int, Obywatel>(2, o5));
	mapa_obywateli.insert(pair<int, Obywatel>(3, o7));

	for (map<int, Obywatel>::iterator it = mapa_obywateli.begin(); it != mapa_obywateli.end(); it++)
	{
		cout << it->first << ". "; 
		(it->second).show_date();
		wypisz_pesel(pesele);
		auto lambda = [](vector<int> v)->int //zlicza wyst¹pienie liczby 9
		{
			return count(v.begin(), v.end(), 9);
		};
		cout << " " << lambda(pesele.top()) << endl;
		pesele.pop();
	}

	if (pesele.empty())
	{
		cout << "Stos jest juz pusty! :) " << endl;
	}
	else
		cout << "Cos poszlo nie tak przy usuwaniu elementow stosu.. :(" << endl;
	
	iter = ob_vec.begin();
	while (!ob_vec.empty())
	{
		iter = ob_vec.erase(iter);
	}
	if (ob_vec.empty())
	{
		cout << "Wektor obiektow jest juz pusty! :) " << endl;
	}
	else
		cout << "Cos poszlo nie tak przy usuwaniu elementow wektora.. :(" << endl;


	vector<int>sort_me;
	for (int i = 0; i < 15; i++)
	{
		sort_me.push_back(rand()%5000);
	}

	sort(sort_me.begin(), sort_me.end(), Funktor_sort());
	for (vector<int>::iterator ii = sort_me.begin(); ii != sort_me.end(); ++ii)
	{
		cout << *ii << " ";
	}

	return 0;
}