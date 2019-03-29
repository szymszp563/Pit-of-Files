#include "CollidableObject.h"



CollidableObject::CollidableObject()
{
	alive = true;
	collidable = true;
}



bool CollidableObject::checkCollisions(CollidableObject *otherObject) //pozmieniac bo teraz x,y nie wskazuje srodka tylko lewy gorny rog bitmapy
{
	float oX = otherObject->getX();
	float oY = otherObject->getY();

	int obX = otherObject->getBoundX();
	int obY = otherObject->getBoundY();

	if (x + boundX > oX - obX &&
		x - boundX < oX + obX &&
		y + boundY > oY - obY &&
		y - boundY < oY + obY)
		return true;
	else
		return false;
}

void CollidableObject::collided(int objectID)
{}

bool CollidableObject::isCollidable()
{
	return alive && collidable;
}


CollidableObject::~CollidableObject()
{
}
