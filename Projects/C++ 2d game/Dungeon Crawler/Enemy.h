#pragma once
#include "Player.h"
class Enemy : public Player
{

public:

	Enemy();
	void init(float x, float y, float velX, float velY);
	void runToPlayer(float x, float y, float bnd_y);
	void ProcessCollision(Collidable* otherObject);
	void getDamage(int dmg);
	~Enemy();
};

