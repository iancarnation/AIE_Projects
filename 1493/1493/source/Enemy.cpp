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
	m_bFiring = false;
	m_dTimeWaited = 0;

	for (int i=0; i<20; i++)
	{
		m_aProjectiles[i] = Projectile("Projectile", 10, 10, HOLDING_AREA, ZERO_VELOCITY, -500000, false, "./images/cannonBall.png");
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
	Behavior();
	UpdateEdges();
	Sprite::Update();
	UpdateProjectiles();
}

void Enemy::Draw()
{
	Sprite::Draw();
	DrawProjectiles();
}

// enemy movement logic
void Enemy::Movement()
{
	m_oPosition += m_oVelocity;
}

// weapons control / logic
void Enemy::Abilities(double a_dDeltaTime)
{
	// set minimum waiting time between shots (while button held down)
	double threshold = 0.25; 

	if (!m_bFiring && IsOnScreen())
	{
		Projectile& orCurrentProj = m_aProjectiles[m_iAmmoSlot];

		orCurrentProj.SetAlive(true);
		orCurrentProj.SetPosition(m_oPosition);		// projectile's position is current player's position
		orCurrentProj.GetVelocity().SetY(- orCurrentProj.GetMoveFactor());		// projectile has upward Y velocity
		m_bFiring = true;
		m_iAmmoSlot += 1;
		//reset = true;
	}
	
	// firing delay logic
	if (m_bFiring)
	{
		// add the delta time to the total time since the last shot
		m_dTimeWaited += a_dDeltaTime;

		// if the time since the last shot is greater than the threshold
		if (m_dTimeWaited >= threshold)
		{
			m_bFiring = false;
			m_dTimeWaited = 0;
		}
	}
	// cycle the rotating ammo slot
	if (m_iAmmoSlot == 19)
			m_iAmmoSlot = 0;
}

// enemy spawn initialization
void Enemy::Spawn(Vector2D& a_oStart,  Vector2D& a_oVelocity)
{
	SetAlive(true);
	SetPosition(a_oStart);
	SetVelocity(a_oVelocity);
}

void Enemy::UpdateProjectiles()
{
	for (int i=0; i<20; i++)
	{
		if (m_aProjectiles[i].IsAlive())
			m_aProjectiles[i].Update();
	}
}

// checks if projectile has been triggered or moved off screen and moves it accordingly
void Enemy::DrawProjectiles()
{
	for (int i=0; i<20; i++)
	{
		if (m_aProjectiles[i].IsAlive())
			m_aProjectiles[i].Draw();
	}
}

//// screen edge collision
//void Enemy::ScreenCollision()
//{
//	if (GetEdge(TOP) > SCREEN_Y && (GetPosition().GetX() <= SCREEN_X && GetPosition().GetX() > 0) &&
//		GetEdge(BOTTOM) > SCREEN_Y)
//	{
//		SetAlive(false);
//		SetPosition(HOLDING_AREA);
//		SetVelocity(ZERO_VELOCITY);
//	}
//}
