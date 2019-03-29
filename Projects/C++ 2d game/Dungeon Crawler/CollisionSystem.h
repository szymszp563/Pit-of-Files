#pragma once
#include <vector>
#include "Collidable.h"
#include "Enums.h"
#include "StaticObject.h"
#include <fstream>


class CollisionSystem
{
private:
	std::vector<Collidable*> objectList;//lista obiekt�w, kt�re mog� mie� kolizje
	
public:
	void AddToCollisinList(Collidable* object);//dodanie do listy obiekt�w
	void RemoveFromCollisionList(Collidable* object);//wywalenie z listy obiekt�w
	void ProcessCollisionList();//wywo�ujemy to w momencie ruchu, wtedy sprawdzamy vector obiekt�w, kt�re mog� mie� kolizje
	int sizeofmap()//raczej si� nie przyda
	{
		std::ifstream file;
		file.open("maptest.txt");
		int size;
		char ch;
		file >> size;
		file.close();
		return size;
	}
	std::vector<std::vector<StaticObject*>> map1;//aby �atwo przejrze� map�. Mo�e inne pomys�y??
	void clearVectors()
	{
		objectList.clear();
		map1.clear();
	}
	

};