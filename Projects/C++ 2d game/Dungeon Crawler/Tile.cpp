#include "Tile.h"



Tile::Tile()
{
}

Tile::Tile(float x, float y, int boundX, int boundY, int id, ALLEGRO_BITMAP * bmp)
{
	GameObject::init(x, y, boundX, boundY);
	GameObject::setID(id);
	image = bmp;
}

/*float Tile::GetPosX()
{
	return x;
}
float Tile::GetPosY()
{
	return y;
}
int Tile::IDnum()
{
	return getID();
}*/
/*float Tile::GetSize()
{
}//mo�e si� przyda, a mo�e nie. MO�E SI� PRZYDAC, JE�LI B�DZIEMY ITEROWAC TYLKO W OBREBIE ROMIARU OBIEKTU(PRZY KOLIZJACH)*/
/*void Tile::ProcessCollision(Collidable* otherObject)
{


}*/

Tile::~Tile()
{

}
