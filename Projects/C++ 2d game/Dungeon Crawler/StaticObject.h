#pragma once
#include "CollidableObject.h"
#include "Collidable.h"
class StaticObject : public CollidableObject, public Collidable
{
public:
	StaticObject();
	void render(float shift);
	void collided(int objectID);
	float GetPosX();//z collidable
	float GetPosY();//z collidable
	float getBoundX();
	float getBoundY();
	int IDnum();//z collidable
	void kill() 
	{ 
		setID(Enums::IDS::NTH);
		image = NULL;
	}
	//float GetSize();//mo¿e siê przyda, a mo¿e nie
	void ProcessCollision(Collidable* otherObject);//z collidable
	~StaticObject();
};

