///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			StaticConstants.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Static Constant Variables
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _STATICCONSTANTS_H_
#define _STATICCONSTANTS_H_

#include "Vector2D.h"

	static const float SCREEN_X = 1024;
	static const float SCREEN_Y = 768;
	static const Vector2D SCREEN_CENTER(SCREEN_X/2, SCREEN_Y/2);
	static const Vector2D HOLDING_AREA(SCREEN_X + 50, SCREEN_Y + 50);
	static const Vector2D ZERO_VELOCITY;

	enum Boundary { TOP, BOTTOM, LEFT, RIGHT };

#endif