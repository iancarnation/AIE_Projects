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
void NextPower2(int a_value)
{
	bool b;

	b = (a_value & (a_value-1)) == 0;		// determines whether value is a power of 2

	if (!b)									// if not, shifts to the next highest power of 2
	{
		a_value --;
		a_value |= a_value >> 1;
		a_value |= a_value >> 2;
		a_value |= a_value >> 4;
		a_value |= a_value >> 8;
		a_value |= a_value >> 16;
		a_value ++;
	}
}

// tests float equality
bool AreEqual(const float a_F1, const float a_F2)
{
	if (( abs( abs(a_F1) - abs(a_F2) ) < THRESHOLD ))
		return true;
	else
		return false;
}

// converts hex code to rgb floats and returns vector4 with alpha as well
Vector4 HexToRGB(string a_sHexCode, float a_fAlpha)
{
	int iHexCode = 0;

	sscanf(a_sHexCode.c_str(), "%x", &iHexCode);

	Vector4 TempVector;
	TempVector.m_fX = ((iHexCode >> 16) & 0xFF) / 255;
	TempVector.m_fY = ((iHexCode >> 8) & 0xFF) / 255;
	TempVector.m_fZ = (iHexCode & 0xFF) / 255;
	TempVector.m_fW = a_fAlpha;

	return TempVector;
}