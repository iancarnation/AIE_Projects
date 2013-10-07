///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2D.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector2D.h"
#include <string> 

//////////////////////////////-- CONSTRUCTION / DESTRUCTION --////////////////////////////////////////////////////////////

// default constructor
Vector2D::Vector2D ()
{
	x = 0;
	y = 0;
}

// constructor that takes in position values
Vector2D::Vector2D (float x, float y)
{
	x = x;
	y = y;
}

// destructor
Vector2D::~Vector2D ()
{

}

//////////////////////////////-- MATHS --////////////////////////////////////////////////////////////

// subtracts a scalar from a vector, returns new vector
Vector2D Vector2D::operator - (float s)
{
	Vector2D vTemp;
	vTemp.x = this->x - s;
	vTemp.y = this->y - s;
	return vTemp;
}

// adds a scalar to a vector, returns new vector
Vector2D Vector2D::operator + (float s)
{
	Vector2D vTemp;
	vTemp.x = this->x + s;
	vTemp.y = this->y + s;
	return vTemp;
}

// multiplies a vector by a scalar, returns new vector
Vector2D Vector2D::operator * (float s)
{
	Vector2D vTemp;
	vTemp.x = this->x * s;
	vTemp.y = this->y * s;
	return vTemp;
}

// subtracts one vector from another, returns new vector
Vector2D Vector2D::operator - (const Vector2D &v2)
{
	Vector2D vTemp;
	vTemp.x = this->x - v2.x;
	vTemp.y = this->y - v2.y;
	return vTemp;
}

// adds one vector to another, returns new vector
Vector2D Vector2D::operator + (const Vector2D &v2)
{
	Vector2D vTemp;
	vTemp.x = this->x + v2.x;
	vTemp.y = this->y + v2.y;
	return vTemp;
}

//////////////////////////////-- GET / SET --////////////////////////////////////////////////////////////

// returns x value
float Vector2D::GetX()
{
	return this->x;
}

// returns y value
float Vector2D::GetY()
{
	return this->y;
}

// sets x value
void Vector2D::SetX(float x)
{
	this->x = x;
}

// sets y value
void Vector2D::SetY(float y)
{
	this->y = y;
}
