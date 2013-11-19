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
			   Vector2D a_Velocity, Vector2D a_Force, float a_fMass, float a_fMovementForce, bool a_bAlive, const char* a_cpTextureName, float a_fSheetSlices)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_Position, a_Velocity, a_Force, a_fMass, a_fMovementForce, 
					   a_bAlive, a_cpTextureName, a_fSheetSlices)
{
	m_bFiring = false;
	m_dTimeWaited = 0;
	m_iTicker = 0;

	for (int i=0; i<20; i++)
	{
		m_aProjectiles[i] = Projectile("Projectile", 10, 10, HOLDING_AREA, ZERO_VELOCITY, Vector2D(), 20, -1, false, "./images/cannonBall.png", 1);
	}
}

// destructor
Enemy::~Enemy()
{

}

// checks for input from user and initiates appropriate action
void Enemy::Behavior(Vector2D& a_oPlayerPos)
{
	Movement();
	Abilities(GetDeltaTime(), a_oPlayerPos);
}

void Enemy::Update(Vector2D& a_oPlayerPos)
{
	Behavior(a_oPlayerPos);
	UpdateEdges();
	Sprite::Update();
	UpdateProjectiles();
	ScreenCollision();
}

void Enemy::Draw()
{
	Sprite::Draw();
	DrawProjectiles();
}

// enemy movement logic
void Enemy::Movement()
{
	m_oPosition += m_oVelocity * m_fMovementForce;
}

// weapons control / logic
void Enemy::Abilities(double a_dDeltaTime, Vector2D& a_oPlayerPos)
{
	// set minimum waiting time between shots (while button held down)
	int iTickThreshold = 1000; 

	if (!m_bFiring && IsOnScreen())
	{
		Projectile& orCurrentProj = m_aProjectiles[m_iAmmoSlot];

		orCurrentProj.SetAlive(true);
		orCurrentProj.SetPosition(m_oPosition);		// projectile's position is current player's position
		orCurrentProj.SetVelocityToward(a_oPlayerPos);		// projectile has velocity towards player
		m_bFiring = true;
		m_iAmmoSlot += 1;
		//reset = true;
	}

	// firing delay logic
	if (m_bFiring)
	{
		// increment ticker
		m_iTicker ++;

		// if the time since the last shot is greater than the threshold
		if (m_iTicker >= iTickThreshold)
		{
			m_bFiring = false;
			m_iTicker = 0;
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

// returns projectile array
Projectile* Enemy::GetProjectiles()
{
	return m_aProjectiles;
}

void Enemy::UpdateProjectiles()
{
	for (int i=0; i<20; i++)
	{
		if (m_aProjectiles[i].IsAlive())
			m_aProjectiles[i].Update(dTime);
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

// screen edge collision
void Enemy::ScreenCollision()
{
	if (IsOnScreen())
		if(!IsOnScreen())
			Die();
}

//// death animation
//void Enemy::DeathAnim()
//{
//	double timer = 0;
//	double gapSize = 100000000;
//
//	SetSpriteUVCoordinates(GetSpriteId(), 0.25, 0, 0.5, 1);
//
//	while (true)
//	{
//		timer ++;
//			
//		if (timer == gapSize *2)
//			SetSpriteUVCoordinates(GetSpriteId(), 0.5, 0, 0.75, 1);
//
//		if (timer == gapSize * 3)
//			SetSpriteUVCoordinates(GetSpriteId(), 0.75, 0, 1, 1);
//
//		if (timer== gapSize * 4)
//			break;
//	}
//}