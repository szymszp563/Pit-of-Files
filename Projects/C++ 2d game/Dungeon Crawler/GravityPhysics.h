#pragma once

struct Counter
{
	//const int power = 4;
	int current = 0;
	const int max = 10;
};


class GravityPhysics
{
public:
	int gravity_force = 45;
	bool is_jumping = false;
	//bool jump_lock = false;
	Counter jumping;
	GravityPhysics();
	virtual void updateGravityAndJumping()=0;
	~GravityPhysics();
};

