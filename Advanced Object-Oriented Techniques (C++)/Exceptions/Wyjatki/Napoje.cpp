#include "Napoje.h"
#include <iostream>


void Napoje::Raport()
{
	float procent;
	procent = (float)produkty_sprawne / ((float)produkty_sprawne + (float)produkty_wadliwe) * 100;
	if (procent == 0)
		throw 2;
	else
		std::cout << "Procent sprawnych produktow: " << procent << "\n";
}

Napoje::~Napoje()
{
}
