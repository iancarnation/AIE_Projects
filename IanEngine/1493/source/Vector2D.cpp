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

// copy constructor
Vector2D::Vector2D(const Vector2D& a_rVecSource)
{
	m_fX = a_rVecSource.m_fX;
	m_fY = a_rVecSource.m_fY;
	m_fThreshold = .0005;
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

// sets one vector equal to another
Vector2D Vector2D::operator = (const Vector2D& a_rVecSource)
{
	m_fX = a_rVecSource.m_fX;
	m_fY = a_rVecSource.m_fY;

	// return the existing object to allow for chaining
	return *this;
}
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

// divides a vector by a scalar, returns new vector
Vector2D Vector2D::operator / (float a_fS)
{
	Vector2D vTemp;
	vTemp.m_fX = this->m_fX / a_fS;
	vTemp.m_fY = this->m_fY / a_fS;
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

// sets a vector equal to itself divided by a scalar
void Vector2D::operator /= (float a_fS)
{
	m_fX /= a_fS;
	m_fY /= a_fS;
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
bool Vector2D::operator == (const Vector2D& a_rV2)
{
	if ((this->m_fX - a_rV2.m_fX < this->m_fThreshold) && (this->m_fY - a_rV2.m_fY < this->m_fThreshold))
		return true;
	else
		return false;
}

// returns magnitude of vector
float Vector2D::GetMagnitude() const
{
	return sqrt(m_fX * m_fX + m_fY * m_fY);
}

// normalize a vector
void Vector2D::Normalize()
{
	float s = GetMagnitude();
	m_fX = m_fX / s;
	m_fY = m_fY / s;
}

// returns a normalized version of vector
Vector2D Vector2D::ReturnNormalized() const
{
	float fMag = GetMagnitude();
	Vector2D vec(m_fX / fMag, m_fY / fMag);
	return vec;
}

// gets distance bethween two points
float Vector2D::GetDistance(const Vector2D a_rV2) const
{
	return sqrt((a_rV2.m_fX - m_fX) * (a_rV2.m_fX - m_fX) + (a_rV2.m_fY - m_fY) * (a_rV2.m_fY - m_fY));
}

// dot product of 2 vectors
float Vector2D::Dot(const Vector2D& a_rV2) const
{
	return (this->m_fX * a_rV2.m_fX) + (this->m_fY * a_rV2.m_fY);
}

// calculates angle between two vectors
float Vector2D::GetAngle(const Vector2D& a_rV2) const
{
	Vector2D V1 = this->ReturnNormalized();
	float dot = V1.Dot(a_rV2.ReturnNormalized());
	return acos(dot);
}

// truncates a vector
//void Vector2D::Truncate(float max)
//{
//	float i = max / GetMagnitude();
//	if (i < 1.0)
//		i = 1.0;
//
//	m_fX *= i;
//	m_fY *= i;
//}

void Vector2D::CapAtMax(float max)
{
	if (m_fX < 0)
		if (m_fX < -max)
			m_fX = -max;
	if (m_fX > 0)
		if (m_fX > max)
			m_fX = max;
	if (m_fY < 0)
		if (m_fY < -max)
			m_fY = -max;
	if (m_fY > 0)
		if (m_fY > max)
			m_fY = max;
}
