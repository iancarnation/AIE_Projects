///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2D.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector2D.h"
#include <string> 
#include <iostream>
using namespace std;

//////////////////////////////-- CONSTRUCTION / DESTRUCTION --////////////////////////////////////////////////////////////

// default constructor
Vector2D::Vector2D ()
{
	m_fX = 0.0;
	m_fY = 0.0;
	m_fThreshold = .0005;
	//cout<< "Default Vector Constructed!\n";
}

// constructor that takes in x and y values
Vector2D::Vector2D (float a_fX, float a_fY)
{
	m_fX = a_fX;
	m_fY = a_fY;
	m_fThreshold = .0005;
	//cout<< "Vector constructed with given values " << a_fX << " and " << a_fY <<"!\n";
}

// destructor
Vector2D::~Vector2D ()
{
	//cout<< "Vector Destroyed, Muhahah!\n";
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

// sets a vector equal to itself minus a scalar
void Vector2D::operator -= (float a_fS)
{
	m_fX -= a_fS;
	m_fY -= a_fS;
}

// sets a vector equal to itself plus a scalar
void Vector2D::operator += (float a_fS)
{
	m_fX += a_fS;
	m_fY += a_fS;
}

// sets a vector equal to itself multiplied by a scalar
void Vector2D::operator *= (float a_fS)
{
	m_fX *= a_fS;
	m_fY *= a_fS;
}

// subtracts one vector from another, returns new vector
Vector2D Vector2D::operator - (const Vector2D& a_rV2)
{
	Vector2D vTemp;
	vTemp.m_fX -= a_rV2.m_fX;
	vTemp.m_fY -= a_rV2.m_fY;
	return vTemp;
}

// adds one vector to another, returns new vector
Vector2D Vector2D::operator + (const Vector2D& a_rV2)
{
	Vector2D vTemp;
	vTemp.m_fX += a_rV2.m_fX;
	vTemp.m_fY += a_rV2.m_fY;
	return vTemp;
}

// sets a vector equal to itself minus another vector
void Vector2D::operator -= (Vector2D& a_rV2)
{
	m_fX -= a_rV2.m_fX;
	m_fY -= a_rV2.m_fY;
}

// sets a vector equal to itself plus another vector
void Vector2D::operator += (Vector2D& a_rV2)
{
	m_fX += a_rV2.m_fX;
	m_fY += a_rV2.m_fY;
}

// tests vector equality, returns bool
bool Vector2D::Equals(const Vector2D& a_rV2)
{
	if ((this->m_fX - a_rV2.m_fX < this->m_fThreshold) && (this->m_fY - a_rV2.m_fY < this->m_fThreshold))
		return true;
	else
		return false;
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
