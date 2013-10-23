///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Projectile.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Projectile Class Definition, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Sprite.h"

class Projectile: public Sprite
{
	public:
		Projectile();	// default constructor
		Projectile(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition, 
					  float a_fXvelocity, float a_fYvelocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);		// constructor with parameters 
		~Projectile();	// destructor

		void Update();
		void Draw();

		
}

#endif