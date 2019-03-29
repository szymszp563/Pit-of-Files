#include "Player.h"
#include <cmath>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>



Player::Player():MovingObject(), Collidable()
{
}

void Player::init(float x, float y, float velX, float velY)//trzeba wzbogacic o te wszystkie rzeczy do animacji
{
	this->x = x;
	this->y = y;
	this->velX = velX;
	this->velY = velY;
	this->image = al_load_bitmap("klatk-big.png");

	//Inicjalizacja zmiennych animacji
	this->frameCount = 0;
	this->frameDelay = 2;
	this->maxFrame = 10;
	this->curFrame = 0;

	//boundX/10 bo tyle jest zdjêæ
	boundX = al_get_bitmap_width(image) / maxFrame;
	boundY = al_get_bitmap_height(image);

	al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));
	setID(PLAYER);
	for (int i = 0; i < COUNT; i++)
		key[i] = false;
	HP = 100;
}

Player::~Player()
{
}


void Player::moveLeft()
{
	dirX = -1;
	int oldx = x;//mo¿na teleportowaæ gracza
	x += velX*dirX;
	shift += x - oldx;//velX*dirX;
}

void Player::moveRight()
{
	dirX = 1;
	int oldx = x;//mo¿na teleportowaæ gracza
	x += velX*dirX;
	shift += x - oldx;//velX*dirX;
}

void Player::moveDown()
{
	dirY = 1;
	y += velY*dirY;
}

void Player::moveUp()
{
	dirY = -1;
	y += velY*dirY;
}

void Player::jump()
{
	dirY = -1;
	y += 4*velY*dirY;
}

void Player::update()
{
	//
	
}
float Player::getShift()
{
	return shift;
}
void Player::render(float shift) //to bêdzie bogatsze. Czy mo¿na zrobiæ to po prostu w MovingObject?
{
	al_draw_bitmap(image, x - shift, y, 0);
	al_draw_rectangle(x - shift, y, x - shift + boundX, y + boundY, al_map_rgb(255, 0, 255), 3.0);//rysuje zeby sprawdzic granice playera
}

//reset animacji
void Player::resetAnimation()
{
	this->frameCount = 0;
	this->curFrame = 0;
}

float Player::GetPosX()//z collidable
{
	return x;
}
float Player::GetPosY()//z collidable
{
	return y;
}
float Player::getBoundX()//z collidable
{
	return boundX;
}
float Player::getBoundY()//z collidable
{
	return boundY;
}
void Player::resetXDir()
{
	dirX = 0;
}
void Player::resetYDir()
{
	dirY = 0;
}
int Player::IDnum()//z collidable
{
	return getID();
}
/*float Player::GetSize()
{
}//mo¿e siê przyda, a mo¿e nie*/
void Player::ProcessCollision(Collidable* otherObject)//z collidable
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

	if (otherObject->IDnum() == LADDER)
	{
		if (col)
		{
			onLdr = true;
			gravityOn = false;
		}
	}
	if (otherObject->IDnum() == SPIKES)
	{
		if (col && from_top)
			HP = 0;
	}
	if (otherObject->IDnum() == GHOST)
	{
		if (col && (from_left||from_right||from_top))
			otherObject->kill();
	}
	if (otherObject->IDnum() == TRAP)
	{
		if (col && from_top)
			otherObject->kill();
	}
	if (otherObject->IDnum() == PLATFORM)
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

//aktualizacja animacji
void Player::updateAnimation()
{
	if (++frameCount >= frameDelay)
	{
		if (++curFrame >= maxFrame)
			curFrame = 0;

		frameCount = 0;
	}
}

//rysowanie gracza z animacja i bez zaleznie od ruchu
void Player::renderAnimated(float shift)
{
	float xx = x - shift;
	float space = 10;
	//=====================================================================================================================================
	//al_draw_rectangle(x - shift, y, x - shift + boundX, y + boundY, al_map_rgb(255, 0, 255), 3.0);//rysuje zeby sprawdzic granice playera
	//=====================================================================================================================================

	if (dirX == 1)
	{
		al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, 0);
		facingRight = true;
	}
	else if (dirX == -1)
	{
		al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y,ALLEGRO_FLIP_HORIZONTAL);
		facingRight = false;
	}
	else if(facingRight == true)al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, 0);
	else if(facingRight == false )al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, ALLEGRO_FLIP_HORIZONTAL);

	if (dirX == 0 && dirY == 0)
	{
		this->resetAnimation();
	}

	al_draw_line(xx, this->y - space, xx + this->boundX, this->y - space, al_map_rgb(255, 0, 0), space / 2);
	float hp_line = (this->HP / 100.0)*boundX;
	al_draw_line(xx, this->y - space, xx + hp_line, this->y - space, al_map_rgb(0, 255, 0), space / 2);
}

//z kolejna klatka updatuje czy skok ma sie zakonczyc czy jeszcze nie
void Player::jumpUpdate()
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
void Player::jumpReset()
{
	jumpCount = 0;
	curJump = 0;
	isJumping = false;
}