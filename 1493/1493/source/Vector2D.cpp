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
	m_fX = 0;
	m_fY = 0;
}

// constructor that takes in position values
Vector2D::Vector2D (float a_fX, float a_fY)
{
	m_fX = a_fX;
	m_fY = a_fY;
}

// destructor
Vector2D::~Vector2D ()
{

}

//////////////////////////////-- MATHS --////////////////////////////////////////////////////////////

// subtracts a scalar from a vector, returns new vector
Vector2D Vector2D::operator - (float a_fS)
{
	Vector2D vTemp;
	vTemp.m_fX = this->m_fX - a_fS;
	vTemp.m_fY = this->m_fY - a_fS;
	return vTemp;
}

// adds a scalar to a vector, returns new vector
Vector2D Vector2D::operator + (float a_fS)
{
	Vector2D vTemp;
	vTemp.m_fX = this->m_fX + a_fS;
	vTemp.m_fY = this->m_fY + a_fS;
	return vTemp;
}

// multiplies a vector by a scalar, returns new vector
Vector2D Vector2D::operator * (float a_fS)
{
	Vector2D vTemp;
	vTemp.m_fX = this->m_fX * a_fS;
	vTemp.m_fY = this->m_fY * a_fS;
	return vTemp;
}

// subtracts one vector from another, returns new vector
Vector2D Vector2D::operator - (const Vector2D& a_rV2)
{
	Vector2D vTemp;
	vTemp.m_fX = this->m_fX - a_rV2.m_fX;
	vTemp.m_fY = this->m_fY - a_rV2.m_fY;
	return vTemp;
}

// adds one vector to another, returns new vector
Vector2D Vector2D::operator + (const Vector2D& a_rV2)
{
	Vector2D vTemp;
	vTemp.m_fX = this->m_fX + a_rV2.m_fX;
	vTemp.m_fY = this->m_fY + a_rV2.m_fY;
	return vTemp;
}

//////////////////////////////-- GET / SET --////////////////////////////////////////////////////////////

// returns x value
float Vector2D::GetX()
{
	return this->m_fX;
}

// returns y value
float Vector2D::GetY()
{
	return this->m_fY;
}

// sets x value
void Vector2D::SetX(float a_fX)
{
	this->m_fX = a_fX;
}

// sets y value
void Vector2D::SetY(float a_fY)
{
	this->m_fY = a_fY;
}
