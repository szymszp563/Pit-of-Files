#include "PlayableObject.h"
#include "EnemyObject.h"
#include <iostream>



PlayableObject::PlayableObject()
{
	SCounter = new ScoreCounter();
}

void PlayableObject::jump()
{
	dirY = -1;
	y += 4 * velY*dirY;
}

void PlayableObject::jumpUpdate()
{
	if (++jumpCount >= jumpDelay)
	{
		if (++curJump >= maxJump)
		{
			curJump = 0;
			isJumping = false;
		}

		jumpCount = 0;
	}
}

//wiadomo reset jumpu
void PlayableObject::jumpReset()
{
	jumpCount = 0;
	curJump = 0;
	isJumping = false;
}

void PlayableObject::ProcessCollision(Collidable* otherObject)//z collidable
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
	if (otherObject->IDnum() == Enums::IDS::ENEMY)
	{
		if (col)
		{
			EnemyObject * enem;
			if (enem = dynamic_cast<EnemyObject*>(otherObject))
			{
				int enemy_attack = enem->attack();
				if (enemy_attack)
				{
					HP -= enemy_attack;
					SCounter->hitByMonster(enem);
				}
				
			}
		}
	}
	if (otherObject->IDnum() == Enums::IDS::LADDER)
	{
		if (col)
		{
			onLdr = true;
			gravityOn = false;
		}
	}
	if (otherObject->IDnum() == Enums::IDS::CHEST)
	{
		if (col)
		{
			additional_damage += 5;
			ad_cooldown = 600;
			HP += 5;
			SCounter->openChest();
			otherObject->kill();
		}
	}
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
	if (otherObject->IDnum() == Enums::IDS::DOOR)
	{
		if (col)
			ended = true;
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

void PlayableObject::moveLeft()
{
	dirX = -1;
	int oldx = x;//mo¿na teleportowaæ gracza
	x += velX*dirX;
	shift += x - oldx;//velX*dirX;
}

void PlayableObject::moveRight()
{
	dirX = 1;
	int oldx = x;//mo¿na teleportowaæ gracza
	x += velX*dirX;
	shift += x - oldx;//velX*dirX;
}

void PlayableObject::moveDown()
{
	dirY = 1;
	y += velY*dirY;
}

void PlayableObject::moveUp()
{
	dirY = -1;
	y += velY*dirY;
}

void PlayableObject::update()
{
	LivingObject::update();
	if (ad_cooldown <= 0)
	{
		ad_cooldown = 0;
		additional_damage = 0;
	}
	else
		ad_cooldown--;
	SCounter->incrementTimer();
	std::cout << SCounter->getScore() << std::endl;
}

ScoreCounter * PlayableObject::getScoreCounter()
{
	return SCounter;
}

PlayableObject::~PlayableObject()
{
}
