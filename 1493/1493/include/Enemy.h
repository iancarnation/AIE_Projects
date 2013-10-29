///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Enemy.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Enemy Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Sprite.h"
#include "Projectile.h"

class Enemy: public Sprite
{
	public:
		Enemy();		// default consructor
		Enemy(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);		// constructor with parameters 
		~ Enemy();		// destructor
		
		// controls enemy movement and attack behavior
		void Behavior();
		void Update();
		void Draw();

	private:
		// enemy movement logic
		void Movement();
		// weapons control / logic
		void Abilities(double a_dDeltaTime);
	
		bool m_bFiring;
		//double m_dTimeWaited;
		Projectile m_aProjectiles[20];
};

#endif