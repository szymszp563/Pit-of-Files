#include "Enemy.h"
#include "Spell.h"


Enemy::Enemy()
{
}

void Enemy::init(float x, float y, float velX, float velY)
{
	Player::init(x, y, velX, velY);
	this->image = al_load_bitmap("troll_run_small.png");

	//Inicjalizacja zmiennych animacji
	this->frameCount = 0;
	this->frameDelay = 2;
	this->maxFrame = 7;
	this->curFrame = 0;

	//boundX/10 bo tyle jest zdjêæ
	boundX = al_get_bitmap_width(image) / maxFrame;
	boundY = al_get_bitmap_height(image);
	al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));
	setID(ENEMY);
	HP = 75; //¿eby sprawdzic czy wyswietlanie paska HP dobrze dziala

}

void Enemy::runToPlayer(float x, float y, float bnd_y)
{
	float difference = this->x - x;
	int border = 10;

	this->dirX = 0;

	if ((y > this->y+border && y < this->y + this->boundY -border) || (y + bnd_y > this->y +border && y + bnd_y < this->y + this->boundY-border))
	{
		if (difference < 150 && difference > 30)
		{
			this->moveLeft();
		}
		else if (difference > -150 && difference < -30)
		{
			this->moveRight();
		}
	}
}

void Enemy::ProcessCollision(Collidable* otherObject)
{
	Player::ProcessCollision(otherObject);
}

void Enemy::getDamage(int dmg)
{
	HP -= dmg;
}

Enemy::~Enemy()
{
}
