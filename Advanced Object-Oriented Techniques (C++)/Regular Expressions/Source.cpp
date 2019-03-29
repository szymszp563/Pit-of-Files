#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <ctime>
#include <sstream> 

using namespace std;


class Osoba
{
private:
	string imie;
	string nazwisko;
	string kod_pocztowy;
	string NIP;
	string email;

public:
	Osoba() {}
	void dodaj_imie(string name)
	{
		regex r("[a-zA-Z]{2,15}");
		if (regex_match(name, r))
		{
			imie = name;
		}
		else
			cout << "nie poprawne imie" << endl;
	}

	void dodaj_nazwisko(string surname)
	{
		regex r("[a-zA-Z]{2,20}");
		if (regex_match(surname, r))
		{
			nazwisko = surname;
		}
		else 
			cout << "nie poprawne nazwisko" << endl;
	}

	void dodaj_kod_pocztowy(string postal)
	{
		regex r("\\d{2}-\\d{3}");
		if (regex_match(postal, r))
		{
			kod_pocztowy = postal;
		}
		else
			cout << "nie poprawny kod pocztowy " << endl;
	}

	void dodaj_NIP(string nIIP)
	{
		regex r("(\\d{3}-\\d{3}-\\d{2}-\\d{2})|(\\d{3}-\\d{2}-\\d{2}-\\d{3})");
		
		if (regex_match(nIIP, r))
		{
			NIP = nIIP;
		}
		else
			cout << "nie poprawny NIP " << endl;
	}

	void dodaj_email(string mail)
	{
		regex r("\\w+\\@\\w+\\.(pl|com)");
		if (regex_match(mail, r))
		{
			email = mail;
		}
		else
			cout << "nie poprawny email " << endl;
	}

	void get_email_details()
	{
		regex r1("(\\w+)@(\\w+)");
		smatch w;
		regex_search(email, w, r1);
		cout << "email:" << email << ":" << endl;
		cout << "Nazwa uzytkownika: " << w[1].str() << endl;
		cout << "domena: " << w[2].str() << endl;
	}

	void wczytaj_lotnisko(string miasto)
	{
		fstream plik;
		plik.open("lotniska.txt");
		if (!plik.good())
			cout << "nie znaleziono pliku!";
		string baza_lotnisk;
		getline(plik, baza_lotnisk);
		regex r("([A-Z][a-z]+|[A-Z][a-z]+_[A-Z][a-z]+)\\s([A-Z]{3})\\s([A-Z]{4})");
		sregex_iterator p(baza_lotnisk.cbegin(), baza_lotnisk.cend(), r);
		sregex_iterator e;
		for (;p != e;p++)
		{
			if (!p->str(1).compare(miasto))
				cout << "miasto: " << miasto << ", IATA: " << p->str(2) << ", ICAO: " << p->str(3) << endl;
		}

		plik.close();


	}

	~Osoba() {}
};

class Flight
{
private:
	string numer_rej;
	string lotnisko_wylotu;
	string lotnisko_przylotu;


public:
	string lotnisko[10];
	string rej[10];
	Flight() 
	{

		fstream plik;
		plik.open("icao.txt");
		if (!plik.good())
			cout << "nie znaleziono pliku!" << endl << endl;
		
		int i = 0;
		while (true)
		{
			plik >> lotnisko[i] >> rej[i];
			i++;
			if (!plik.good())
				break;
		}
		plik.close();
		srand(time(NULL));
		lotnisko_przylotu = lotnisko[rand() % 10];
		lotnisko_wylotu = lotnisko[rand() % 10];
		std::ostringstream pom(std::ostringstream::ate);
		pom << rej[rand() % 10];
		pom << rand() % 999;
		numer_rej = pom.str();
		
	}

	void wypisz()
	{
		cout << "Dane samolotu:" << endl << "nr_rej: " << numer_rej << endl;
		cout << "lotnisko wylotu: " << lotnisko_wylotu << endl;
		cout << "lotnisko przylotu: " << lotnisko_przylotu << endl;
	}

	void zmien()
	{
		//regex r("([A-Z]{3})(\\d{1,3})");
		regex r("[A-Z]{3}");
		for (int i = 0; i < 10; i++)
		{
			if (lotnisko_przylotu[0]==lotnisko[i][0] && lotnisko_przylotu[1] == lotnisko[i][1] && lotnisko_przylotu[2] == lotnisko[i][2] && lotnisko_przylotu[3] == lotnisko[i][3])
			{
				numer_rej = regex_replace(numer_rej, r, rej[i]);
				break;
			}
		}
	}

	~Flight() {}


};


int main(void)
{
	Osoba os1;
	Osoba os2;
	os1.dodaj_imie("Tomek");
	os1.dodaj_nazwisko("JANKOwski");
	os1.dodaj_kod_pocztowy("45-317");
	os1.dodaj_NIP("412-536-12-26");
	os1.dodaj_email("szysz3542456@gma6il.com");

	os2.dodaj_imie("S1m");
	os2.dodaj_nazwisko("JANKO@wski");
	os2.dodaj_kod_pocztowy("45-31117");
	os2.dodaj_NIP("42-536-12-26");
	os2.dodaj_email("szysz3542456@gma6il.cpom");

	os1.get_email_details();

	os2.wczytaj_lotnisko("Warszawa_Modlin");

	Flight lot1;
	lot1.wypisz();
	lot1.zmien();
	cout << "po zmianie: " << endl;
	lot1.wypisz();

	Flight lot2;
	lot2.wypisz();
	lot2.zmien();
	cout << "po zmianie: " << endl;
	lot2.wypisz();

	Flight lot3;
	lot3.wypisz();
	lot3.zmien();
	cout << "po zmianie: " << endl;
	lot3.wypisz();

	Flight lot4;
	lot4.wypisz();
	lot4.zmien();
	cout << "po zmianie: " << endl;
	lot4.wypisz();

	Flight lot5;
	lot5.wypisz();
	lot5.zmien();
	cout << "po zmianie: " << endl;
	lot5.wypisz();

	


	return 0;
}