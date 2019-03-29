#pragma once
#include "GameObject.h"
class CollidableObject : public GameObject
{
private:
	bool alive;//do wyrzucenia
	bool collidable;//do wyrzucenia - daæ do collidable
	

public:
	bool getAlive() { return alive; }//do wyrzucenia
	void setAlive(bool alive) { CollidableObject::alive = alive; }//do wyrzucenia

	bool getCollidable() { return collidable; }//do wyrzucenia
	void setCollidable(bool collidable) { CollidableObject::collidable = collidable; }//do wyrzucenia

	bool checkCollisions(CollidableObject *otherObject);//do wyrzucenia
	void virtual collided(int objectID);//do wyrzucenia
	bool isCollidable();//do wyrzucenia
	CollidableObject();
	~CollidableObject();

};

