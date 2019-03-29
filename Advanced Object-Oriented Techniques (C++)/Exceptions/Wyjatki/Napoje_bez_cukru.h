#pragma once
#include "Napoje.h"
class Napoje_bez_cukru : public Napoje
{
private:
	int ilosc_kalorii;
	int pojemnosc_w_g;
public:
	Napoje_bez_cukru(string name = 0, int wadliwe = 0, int sprawne = 0, int kalorie = 0, int pojemnosc = 0) : Napoje(name, wadliwe, sprawne)
	{
		ilosc_kalorii = kalorie;
		pojemnosc_w_g = pojemnosc;
	}

	virtual void Raport2();
	~Napoje_bez_cukru();
};

