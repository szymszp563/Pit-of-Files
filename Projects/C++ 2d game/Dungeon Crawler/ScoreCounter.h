#pragma once
#include "EnemyObject.h"
class EnemyObject;//szit o ktory mnie nie pytajcie
class Delegate;

class ScoreCounter //system punktow
{
	int score; //wynik ogolny
	int timer; //licznik do odmierzania czasu. Co sekunde od sumy punktow odejmowane jest 1
	void countScore(); //a ta funkcja to robi ^
public:
	ScoreCounter();

	void incrementTimer() { timer++; }; //inkrementowanie timera w 60 fpsach (w metodzie update playera)
	void defeatMonster(EnemyObject * enemy); //w cpp
	void openChest(); //dodaje punkty po zebraniu skrzynki
	void hitByMonster(EnemyObject * enemy); // w cpp
	void resetScoreCounter();

	int getScore(); //zwraca wyliczony wynik (chwilowo jest cout-owany w playerze w metodzie update ale trzeba to wyciagnac i wyswietlic na dolnym pasku gry

	~ScoreCounter();
};

