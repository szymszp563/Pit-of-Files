#include <iostream>
#include <vector>

#include "Produkcja.h"
#include "Napoje.h"
#include "Napoje_bez_cukru.h"
using namespace std;


int main()
{
	Napoje *n;//zmienna do dynamic cast
	Napoje_bez_cukru *nbc;

	vector <Produkcja*> fabryka;
	//Produkowane produkty
	Produkcja krzeslo("klonowe");
	Produkcja korek("korek");
	Napoje cola("coca", 9, 1003);
	Napoje soczek("Tymbark", 12, 159);
	Napoje smoothie("Zielony Jack", 10, 0);
	Napoje_bez_cukru coke("Cola Zero", 3, 1932, 230, 1000);
	Napoje_bez_cukru pepsi("Pepsi MAX", 7, 4500, 10, 1500);
	Napoje_bez_cukru fuel("Diesel", 3, 0, 300, 100);
	Napoje_bez_cukru cappy("Pusciak", 3, 7, 10, 0);
	fabryka.push_back(&krzeslo);
	fabryka.push_back(&korek);
	fabryka.push_back(&cola);
	fabryka.push_back(&soczek);
	fabryka.push_back(&smoothie);
	fabryka.push_back(&coke);
	fabryka.push_back(&pepsi);
	fabryka.push_back(&fuel);
	fabryka.push_back(&cappy);

	for (int i = 0; i < fabryka.size(); i++)//iterujemy po wszystkich produktach
	{
		try
		{
			cout << "\n" << "Produkt " << i << "\n";
			fabryka[i]->Pokaz_nazwe();//nazwe posiada kazdy produkt
			if (n = dynamic_cast<Napoje*>(fabryka[i]))//dla klasy napoje funkcjonalnosc Raport()
				n->Raport();
			else
				cout << "Brak produkowanych produktow!" << "\n";
			if (nbc = dynamic_cast<Napoje_bez_cukru*>(fabryka[i]))
				nbc->Raport2();
		}

		catch (int i)//wyjatki dla metod produktow
		{
			switch (i)
			{
				case 2: cout << "Brak napojow zdatnych!" << "\n";
					break;
				case 3: cout << "Napoj jest pusty!" << "\n";
					break;
				default:
					cout << "Default" << "\n";
					break;
			}
		
		}
		catch (bad_alloc& b)
		{
			cout << "Nie udalo sie zaalokowac pamieci!";
			b.what();
		}
		catch (bad_cast& c)
		{
			cout << "dynamic cast nie wyszedl!:(";
			c.what();
		}
			
	}

	return 0;
}