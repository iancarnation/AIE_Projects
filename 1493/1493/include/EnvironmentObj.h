///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			EnvironmentObj.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			EnvironmentObj Class Definition, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _ENVIRONMENTOBJ_H_
#define _ENVIRONMENTOBJ_H_

#include "Sprite.h"

class EnvironmentObj: public Sprite
{
	public:
		EnvironmentObj();	// default constructor
		EnvironmentObj(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
				   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);		// constructor with parameters 
		~EnvironmentObj();	// destructor

		void Update();
		void Draw();	
};

#endif