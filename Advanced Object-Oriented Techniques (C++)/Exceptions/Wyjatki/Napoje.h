#pragma once
#include "Produkcja.h"
class Napoje : public Produkcja
{
private:
	int produkty_wadliwe;
	int produkty_sprawne;
public:
	Napoje(string name = 0, int wadliwe = 0, int sprawne = 0) : Produkcja(name)
	{
		produkty_wadliwe = wadliwe;
		produkty_sprawne = sprawne;
	}
	virtual void Raport();
	~Napoje();
};

