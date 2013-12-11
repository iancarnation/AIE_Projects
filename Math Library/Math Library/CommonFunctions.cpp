///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			CommonFunctions.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Common Math Functionality for Library
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CommonFunctions.h"

// linear interpolation for scalar values
float LerpScalar(float a_start, float a_end, float a_t)
{
	return a_start*(1-a_t) + a_end*a_t;
}

// convert angle from degrees to radians
float DegToRad(float a_angle)
{
	return a_angle * (PI/180);
}

// convert angle from radians to degrees
float RadToDeg(float a_angle)
{
	return a_angle * (180/PI);
}

// Testing scalar value for Power of Two (shift to nearest power of two)
bool TestPower2(float a_value)
{

}