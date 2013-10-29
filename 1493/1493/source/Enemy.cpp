///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Enemy.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Enemy Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Enemy.h"

// default constructor
Enemy::Enemy()
{

}

// constructor with parameters
Enemy::Enemy(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_Position, a_Velocity, a_fMoveFactor, 
					   a_bAlive, a_cpTextureName)
{
	bool m_bFiring = false;

	for (int i=0; i<=20; i++)
	{
		m_aProjectiles[i] = Projectile("Projectile", 10, 10, HOLDING_AREA, ZERO_VELOCITY, 1, true, "./images/cannonBall.png");
	}
}

// destructor
Enemy::~Enemy()
{

}

// checks for input from user and initiates appropriate action
void Enemy::Behavior()
{
	Movement();
	Abilities(GetDeltaTime());
}

void Enemy::Update()
{
	Sprite::Update();
}

void Enemy::Draw()
{
	Sprite::Draw();
}

// enemy movement logic
void Enemy::Movement()
{

}

// weapons control / logic
void Enemy::Abilities(double a_dDeltaTime)
{
	
}