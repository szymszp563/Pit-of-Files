#pragma once
#include <string>
using namespace std;

class Produkcja
{
private:
	string nazwa_towaru;
public:
	Produkcja(string name = 0);
	virtual void Pokaz_nazwe();
	~Produkcja();
};

