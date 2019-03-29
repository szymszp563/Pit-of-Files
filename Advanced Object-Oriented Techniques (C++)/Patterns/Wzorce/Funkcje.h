#pragma once
template <class L>
L dziel(L a1, L a2)
{
	if (a2 == 0.0)
		throw "Nie dziel przez zero :( ";
	return a1 / a2;
}

template <class B>
void zmien(B & b1, B & b2)
{
	B buff = b1;
	b1 = b2;
	b2 = buff;
}

template <int i>
int isbn(int tbl[])
{
	return 0;
};

template<>
int isbn<10>(int tbl[])
{
	int wynik = 0;
	for (int j = 0; j < 9; j++)
	{
		wynik += (j + 1)*tbl[j];
	}
	return wynik % 11;
};

template<>
int isbn<13>(int tbl[])
{
	int wynik1 = 0;
	int wynik2 = 0;
	int wynik3;
	for (int j = 0; j < 12; j += 2)
		wynik1 += tbl[j];
	for (int j = 1; j < 13; j += 2)
		wynik2 += tbl[j];
	wynik3 = (10 - (wynik1 + 3 * wynik2) % 10);
	if (wynik3 == 10)
		return 0;
	return (10 - (wynik1 + 3 * wynik2) % 10);
};