#pragma once
#include "MovingObject.h"
#include "Collidable.h"
#include "Physics.h"
#include "Globals.h"
class Player : public MovingObject, public Collidable, public Physics
{
private:
	float shift = 0;
public:
	Player();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();

	bool onLdr = false;

	void jump();//trzeba dopracowaæ
	void update();

	void kill() { setID(NTH); };
	//resetowanie czy jest na drabinie i grawitacji
	void resetStuff()
	{
		onLdr = false;
		gravityOn = true;
		touchedGround = false;
	}

	void jumpReset();

	float getShift();
	
	
	void jumpUpdate();
	
	void init(float x, float y, float velX, float velY);
	void render(float shift);

	void resetAnimation();

	void updateAnimation();

	void renderAnimated(float shift);

	void resetXDir();
	void resetYDir();
	int getDirX()
	{
		return dirX;
	}
	int getDirY()
	{
		return dirY;
	}

	bool getFacing()
	{
		return facingRight;
	}
	float GetPosX();//z collidable
	float GetPosY();//z collidable
	float getBoundX();//z collidable
	float getBoundY();//z collidable
	int IDnum();//z collidable
	//float GetSize();//mo¿e siê przyda, a mo¿e nie
	void ProcessCollision(Collidable* otherObject); // z collidable
	int key[COUNT];//byæ mo¿e tak zoregramy kierunek, ale s³aby pomys³, bo potworki i tak nie chodz¹ z klawiatury, chocia¿ fajnie jakby dzia³a³o cokolwiek
	~Player();
};

