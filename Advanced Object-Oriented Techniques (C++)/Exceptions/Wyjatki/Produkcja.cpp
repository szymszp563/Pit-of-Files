#include "Produkcja.h"
#include <iostream>

Produkcja::Produkcja(string name)
{
	nazwa_towaru = name;
}

void Produkcja::Pokaz_nazwe()
{
	std::cout << "Nazwa towaru: " << nazwa_towaru << "\n";
}

Produkcja::~Produkcja()
{
}
