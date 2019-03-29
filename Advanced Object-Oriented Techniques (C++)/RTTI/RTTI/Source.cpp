#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Klasy.h"

using namespace std;

Vehicle * GenerateRandomObject();

int main()
{
	srand(time(0));
	Vehicle * v;
	Car * c;
	RacingCar * r;

	for (int i = 0; i < 10; i++)
	{
		cout << "\n" << "Pojazd " << i << "\n";
		v = GenerateRandomObject();
		cout << "Obiekt jest typu: " << typeid(*v).name() << "\n";
		v->printSpeed();
		if (c = dynamic_cast<Car*>(v))
			c->showBrand();
		if (r = dynamic_cast<RacingCar*>(v))
			r->checkFuel();
	}
	



	return 0;
}

Vehicle * GenerateRandomObject()
{
	Vehicle * vv;
	switch (rand() % 3)
	{
	case 0: vv = new Vehicle(rand() % 400);
		break;
	case 1: vv = new Car(rand() % 400, nazwy[rand() % 10]);
		break;
	case 2: vv = new RacingCar(rand() % 400, nazwy[rand() % 10], rand() % 20);
		break;
	default: 
		vv = nullptr;
		break;
	}
	return vv;
}