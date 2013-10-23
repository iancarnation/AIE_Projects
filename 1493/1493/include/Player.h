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
#include <string>
using namespace std;

class Player: public Sprite
{
	public:
		Player();		// default consructor
		Player(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition, 
					  float a_fXvelocity, float a_fYvelocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);		// constructor with parameters 
		~ Player();		// destructor
		
		// checks for input from user and initiates appropriate action
		void Input();
		void Update();
		void Draw();

	private:
		// projectile array
		// current ammo slot
};

#endif