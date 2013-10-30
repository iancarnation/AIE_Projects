///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Player.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Player Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Sprite.h"
#include "Projectile.h"
#include <list>
//#include <GL/glfw.h>

class Player: public Sprite
{
	public:
		Player();		// default consructor
		Player(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);		// constructor with parameters 
		~ Player();		// destructor
		
		// checks for input from user and initiates appropriate action
		void Input();
		void Update();
		void Draw();
		int GetHealth() const;			// returns player health
		void SetHealth(int a_iAmt);		// changes player's health by given amount
		Projectile* GetProjectiles();	// returns projectile array

	private:
		// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
		void Movement();
		// check for fire input / firing timing control 
		void Abilities(double a_dDeltaTime);
		// checks if projectile has been triggered or moved off screen and moves it accordingly
		void UpdateProjectiles();
		void DrawProjectiles();

		bool m_bFiring;
		double m_dTimeWaited;
		Projectile m_aProjectiles[20];
		int m_iHealth;
};

#endif