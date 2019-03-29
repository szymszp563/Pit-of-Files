#include "StaticObject.h"



StaticObject::StaticObject():CollidableObject(), Collidable()
{
}

void StaticObject::render(float shift)
{
	GameObject::render(shift);
	if (image != NULL)
		al_draw_bitmap(image, x - shift, y, 0);
}

void StaticObject::collided(int objectID)
{
	CollidableObject::collided(objectID);
	//if(objectID==PLAYER)..... itd
}
float StaticObject::GetPosX()//z collidable
{
	return x;
}
float StaticObject::GetPosY()//z collidable
{
	return y;
}
float StaticObject::getBoundX()
{
	return boundX;
}
float StaticObject::getBoundY()
{
	return boundY;
}
int StaticObject::IDnum()//z collidable
{
	return getID();
}
/*float Tile::GetSize()
{
}//mo¿e siê przyda, a mo¿e nie. MO¯E SIÊ PRZYDAC, JEŒLI BÊDZIEMY ITEROWAC TYLKO W OBREBIE ROMIARU OBIEKTU(PRZY KOLIZJACH)*/
void StaticObject::ProcessCollision(Collidable* otherObject)//z collidable nic nie musi póki co robiæ
{


}

StaticObject::~StaticObject()
{
}
