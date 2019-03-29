#include <iostream>
#include "Napoje_bez_cukru.h"


void Napoje_bez_cukru::Raport2()
{
	float kalorie_na_sto = (float)ilosc_kalorii / (float)pojemnosc_w_g * 100;
	if (pojemnosc_w_g == 0)
		throw 3;
	else
		std::cout << "Ilosc kalorii na 100g produktu: " << kalorie_na_sto << "\n";
}

Napoje_bez_cukru::~Napoje_bez_cukru()
{
}
