///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Player.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Player Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AIE.h"
#include "KeyCodes.h"
#include "Sprite.h"
#include <list>
using namespace std;

class Player: public Sprite
{
	public:
		Player();		// default consructor
		Player(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_position, 
			   Vector2D a_velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);		// constructor with parameters 
		~ Player();		// destructor
		
		// checks for input from user and initiates appropriate action
		void Input();
		void Update();
		void Draw();

	private:
		// checks for fire button and triggers projectile sprites
		void CheckFire(double a_dDeltaTime);

		bool m_bFired;
		double m_dTimeWaited;
		Sprite m_aProjectiles [20];
};

#endif