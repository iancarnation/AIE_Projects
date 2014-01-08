///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			CommonFunctions.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Common Math Functionality for Library
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _COMMONFUNCTIONS_H_
#define _COMMONFUNCTIONS_H_

#include "Static Constants.h"
#include "Vector4.h"
#include <math.h>

float LerpScalar(float a_start, float a_end, float a_t);	// linear interpolation for scalar values
float DegToRad(float a_angle);		// convert angle from degrees to radians
float RadToDeg(float a_angle);		// convert angle from radians to degrees
void NextPower2(int& a_irValue);		// Testing scalar value for Power of Two (shift to nearest power of two)
bool AreEqual(const float a_F1, const float a_F2);	// tests float equality

#endif