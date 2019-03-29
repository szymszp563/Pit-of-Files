#include "EnemyObject.h"


EnemyObject::EnemyObject()
{
	deleg = new Delegate();
}
/*
void EnemyObject::runToPlayer(float x, float y, float bnd_y)
{
float difference = this->x - x;
int border = 10;

this->dirX = 0;

if ((y > this->y + border && y < this->y + this->boundY - border) || (y + bnd_y > this->y + border && y + bnd_y < this->y + this->boundY - border))
{
if (difference < 400 && difference > 10) //150//30
{
this->moveLeft();
}
else if (difference > -400 && difference < -10)
{
this->moveRight();
}
}
}

*/
void EnemyObject::update()
{
	LivingObject::update();
	if (cooldown > 0)
		cooldown--;
	if (HP <= 0)
		deleg->action(this);
}

void EnemyObject::initv2(ScoreCounter * scounter, float x, float y, float velX, float velY, std::string imageName, Enums::IDS id, int _maxFrame) //musialem dodac v2 zeby zrobic delegata
{
	LivingObject::init(x, y, velX, velY, imageName, id, _maxFrame);
	deleg = new Delegate(scounter);
}

void EnemyObject::ProcessCollision(Collidable* otherObject)
{
	//=====================================================================================================================================
	//al_draw_rectangle(otherObject->GetPosX() - shift, otherObject->GetPosY(), otherObject->GetPosX() + otherObject->getBoundX() - shift,
	//otherObject->GetPosY() + otherObject->getBoundY(), al_map_rgb(255, 0, 255), 3.0); //rysuje zeby sprawdzic dokladnie granicy bitmap
	//=================================================================================================================================

	float xplsr = GetPosX() + (getBoundX() / 2); // wspolrzedna x srodka playera
	float yplsr = GetPosY() + (getBoundY() / 2); // wspolrzedna y srodka playera
	float xoosr = otherObject->GetPosX() + (otherObject->getBoundX() / 2); //to samo otherObject
	float yoosr = otherObject->GetPosY() + (otherObject->getBoundY() / 2); //to samo otherObject
	float plb = getBoundX() / 2; //nowe bound playera
	float oob = otherObject->getBoundX() / 2; // nowe bound otherObject

	bool col = false;

	if (xplsr + plb > xoosr - oob &&
		xplsr - plb < xoosr + oob &&
		yplsr + plb > yoosr - oob &&
		yplsr - plb < yoosr + oob)
		col = true;

	bool from_top = yplsr < yoosr && abs(abs(yplsr - yoosr) - (oob + plb))<16;
	bool from_bottom = yplsr > yoosr && abs(abs(yplsr - yoosr) - (oob + plb))<11;
	bool from_left = xplsr < xoosr && abs(abs(xplsr - xoosr) - (oob + plb))<6;
	bool from_right = xplsr > xoosr && abs(abs(xplsr - xoosr) - (oob + plb))<6;

	//NAJPIERW IF Z COL A POTEM IFY Z ID!!! trzeba tak zrobic :D

	if (otherObject->IDnum() == Enums::IDS::SPIKES)
	{
		if (col && from_top)
			HP = 0;
	}
	if (otherObject->IDnum() == Enums::IDS::GHOST)
	{
		if (col && (from_left || from_right || from_top))
			otherObject->kill();
	}
	if (otherObject->IDnum() == Enums::IDS::TRAP)
	{
		if (col && from_top)
			otherObject->kill();
	}
	if (otherObject->IDnum() == Enums::IDS::PLATFORM)
	{

		if (col)
		{

			if (from_top)
			{
				if (dirY == 0)
				{
					y -= 10;
					gravityOn = false;
					int tempy = y / otherObject->getBoundY();
					y = tempy * otherObject->getBoundY() + otherObject->getBoundY() - boundY;
				}
				else
				{
					gravityOn = true;
					y -= velY*dirY;
					y -= 10;
				}
				gravityOn = true;

				touchedGround = true;
			}
			else if (from_bottom)
			{
				moveDown();
				isJumping = false;
				jumpReset();
			}
			else if (from_left)
			{
				moveLeft();
				//key[RIGHT] = false; //jak to wykomentujemy to mozna trzymac skok+kierunek i dziala ale za to ³apie kolizje przy wskakiwaniu na sciane
			}
			else if (from_right)
			{
				moveRight();
				//key[LEFT] = false;// to samo
			}
		}
		col = false;
	}
}

/*
void EnemyObject::getDamage(int dmg)
{
HP -= dmg;
}
*/


EnemyObject::~EnemyObject()
{
}
