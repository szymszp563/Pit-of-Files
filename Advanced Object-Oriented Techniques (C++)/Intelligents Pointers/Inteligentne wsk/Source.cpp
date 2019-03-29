#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Miasto
{	
public:
	string nazwa;
	vector <shared_ptr<Miasto>>listaMiast;

	Miasto(string s)
	{
		nazwa = s;
	}

	void pokazInfo()
	{
		if (this == nullptr)
		{
			cout << "Wskaznik jest pusty!" << endl << endl;
		}
		else
		{
			cout << this->nazwa << endl << endl;
		}
	}

	void wypisz()
	{
		vector<shared_ptr<Miasto>>::iterator iter;

		cout << "Siec miast dla miasta " << nazwa << ":" << endl;

		for (iter = listaMiast.begin(); iter < listaMiast.end(); ++iter)
		{
			cout << (*iter)->nazwa << endl;
		}
		cout << endl;
	}

	void dodaj(shared_ptr<Miasto> mptr)
	{
		listaMiast.push_back(mptr);
	}

	void sprawdz(shared_ptr<Miasto>ptr)
	{
		if (ptr.use_count() > 2)
		{
			cout << "Liczba referencji wieksza niz 2! Jest ich: " << ptr.use_count() << endl << endl;
		}

		else
		{
			cout << "Liczba referencji mniejsza lub rowna 2! Jest ich: " << ptr.use_count() << endl << endl;
		}
	}

	~Miasto()
	{
		cout << "Usunieto misto!" << " Atak bombowy na " << nazwa << " zakonczony sukcesem!" << endl;
	}
};

int main()
{
	unique_ptr<Miasto>m1(new Miasto("Opole"));
	unique_ptr<Miasto>m2(new Miasto("Krakow"));
	unique_ptr<Miasto>m3(new Miasto("Warszawa"));

	cout << m1.get() << " jest wskaznikiem miasta: ";
	m1->pokazInfo();
	cout << endl;

	cout << m2.get() << " jest wskaznikiem miasta: ";
	m2->pokazInfo();
	cout << endl;

	cout << m3.get() << " jest wskaznikiem miasta: ";
	m3->pokazInfo();
	cout << endl;

	shared_ptr<Miasto>m22 = move(m2);

	cout << m2.get() << " jest wskaznikiem miasta: ";
	m2->pokazInfo();
	cout << endl;

	cout << m22.get() << " jest wskaznikiem miasta: ";
	m22->pokazInfo();
	cout << endl;

	m2->sprawdz(m22);
	shared_ptr<Miasto>m222 = m22;
	m2->sprawdz(m22);

	m2->sprawdz(m22);
	weak_ptr<Miasto>wm2 = m22;
	wm2.lock()->pokazInfo();
	m2->sprawdz(m22);

	shared_ptr<Miasto>m4(new Miasto("Gliwice"));
	shared_ptr<Miasto>m5(new Miasto("Katowice"));
	shared_ptr<Miasto>m6(new Miasto("Zamosc"));
	m4->dodaj(m22);
	m4->dodaj(m5);
	m4->dodaj(m6);
	m4->wypisz();

	m1->sprawdz(m22);
	m1->sprawdz(m222);
	m1->sprawdz(m4);
	m1->sprawdz(m5);
	m1->sprawdz(m6);

	return 0;
}