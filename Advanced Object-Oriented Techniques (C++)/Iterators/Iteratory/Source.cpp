#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	fstream plik_tekst;
	fstream plik_slownik;
	plik_tekst.open("tekst.txt", ios::in);
	plik_slownik.open("slownik.txt");
	if (!plik_tekst.good())
		cout << "Nie udalo sie otworzyc pliku tekst.txt :(" << endl;
	if (!plik_slownik.good())
		cout << "Nie udalo sie otworzyc pliku slwonik.txt :(" << endl;

	deque<string>tekst;
	deque<string>slownik;
	deque<string>slownik1;
	copy(istream_iterator<string>(plik_tekst), istream_iterator<string>(), back_inserter(tekst));
	copy(istream_iterator<string>(plik_slownik), istream_iterator<string>(), back_inserter(slownik));
	copy(slownik.begin(), slownik.end(), back_inserter(slownik1));
	ostream_iterator<string> strumien(cout, " ");//do wypisania ca³oœci tekstu
	copy(tekst.begin(), tekst.end(), strumien);
	cout << endl << endl;
	deque<string>::iterator it1;
	deque<string>::iterator it2;
	deque<string>::iterator it3;


	it1 = slownik.begin();
	while (!slownik.empty())//wypisujemy znalezione elementy ze s³ownika
	{
		it2 = find_first_of(slownik.begin(), slownik.end(), tekst.begin(), tekst.end());
		cout << *it2 << " " << *(it2 + 1) << endl;
		it1 = slownik.erase(it1);
		it1 = slownik.erase(it1);
	}

	cout << endl << endl;

	it1 = slownik1.begin();
	while (!slownik1.empty())//dodajemy do tekstu opis znalezionych elementów ze s³ownika
	{
		it2 = find_first_of(slownik1.begin(), slownik1.end(), tekst.begin(), tekst.end());
		it3 = find(tekst.begin(), tekst.end(), *it2);
		tekst.insert(it3+1, *(it2 + 1));
		it1 = slownik1.erase(it1);
		it1 = slownik1.erase(it1);
	}

	copy(tekst.begin(), tekst.end(), strumien);

	auto lambda = [](deque<string> v)->int//liczy liczbê osób w tekœcie
	{
		return count(v.begin(), v.end(), "(osoba)");
	};

	cout << endl << endl << "liczba osob w pliku tekst.txt: " << lambda(tekst) << endl << endl;
	return 0;
}