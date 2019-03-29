#pragma once
#include "StaticObject.h"
class Tile : public StaticObject
{
public:
	Tile();
	Tile(float x, float y, int boundX, int boundY, int id, ALLEGRO_BITMAP * bmp);
	/*float GetPosX();
	float GetPosY();
	int IDnum();
	//float GetSize();//mo¿e siê przyda, a mo¿e nie
	void ProcessCollision(Collidable* otherObject);*/
	~Tile();
};

