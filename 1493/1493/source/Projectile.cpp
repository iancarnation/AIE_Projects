///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Projectile.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Projectile Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Projectile.h"

// default constructor
Projectile::Projectile()
{

}

// constructor with parameters
Projectile::Projectile(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, Vector2D a_Force, float a_fMass, float a_fMovementForce, bool a_bAlive, const char* a_cpTextureName)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_Position, a_Velocity, a_Force, a_fMass, a_fMovementForce, 
					   a_bAlive, a_cpTextureName)
{

}

// destructor
Projectile::~Projectile()
{

}

void Projectile::Update(double dt)
{
	dTime = dt;
	// update projectile's position
	m_oPosition += m_oVelocity * m_fMovementForce;

	UpdateEdges();
	
	// if projectile goes off screen, it's no longer alive, velocity = 0, and is returned to holding area
	if (IsAlive() && !IsOnScreen())
	{
		Die();
	}
	
	// run the Superclass update function (MoveSprite)
	Sprite::Update();
}

void Projectile::Draw()
{
	Sprite::Draw();
}

//void Projectile::Die()
//{
//	Sprite::Die();
//}