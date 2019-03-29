#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
	int speed;
public:
	Vehicle(int speed_ = 0) { speed = speed_; }

	virtual void printSpeed()
	{
		cout << "Predkosc wynosi: " << speed << "\n";
	}

};

class Car : public Vehicle
{
private:
	string brand;
public:
	Car(int speed_ = 0, string brand_ = 0) : Vehicle(speed_)
	{
		brand = brand_;
	}

	virtual void showBrand()
	{
		cout << "Marka tego samochodu to: " << brand << "\n";
	}
};

class RacingCar : public Car
{
private:
	int fuel;
public:
	RacingCar(int speed_ = 0, string brand_ = 0, int fuel_ = 0) : Car(speed_, brand_)
	{
		fuel = fuel_;
	}
	virtual void checkFuel()
	{
		if (fuel < 5)
			cout << "Stan paliwa: " << fuel << " Zalecamy tankowanie!" << "\n";
		else
			cout << "Stan paliwa: " << fuel << "\n";
	}

};

string nazwy[10] = { "BMW", "OPEL", "SKODA", "TOYOTA", "CITROEN", "FERRARI", "HONDA", "TESLA", "VOLVO", "PORSHE" };