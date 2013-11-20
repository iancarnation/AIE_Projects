///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector3.h"
#include <string> 
#include <iostream>
using namespace std;

//////////////////////////////-- CONSTRUCTION / DESTRUCTION --////////////////////////////////////////////////////////////

// default constructor
Vector3::Vector3 ()
{
	m_fX = 0;
	m_fY = 0;
	m_fZ = 1;
	m_fThreshold = .0005;
	//cout<< "Default Vector Constructed!\n";
}

// copy constructor
Vector3::Vector3(const Vector3& a_rVecSource)
{
	m_fX = a_rVecSource.m_fX;
	m_fY = a_rVecSource.m_fY;
	m_fZ = a_rVecSource.m_fZ;
	m_fThreshold = .0005;
}

// constructor that takes in x and y values
Vector3::Vector3 (float a_fX, float a_fY, float a_fZ)
{
	m_fX = a_fX;
	m_fY = a_fY;
	m_fZ = a_fZ;
	m_fThreshold = .0005;
	//cout<< "Vector constructed with given values " << a_fX << " and " << a_fY <<"!\n";
}

// destructor
Vector3::~Vector3 ()
{
	//cout<< "Vector Destroyed, Muhahah!\n";
}

//////////////////////////////-- MATHS --////////////////////////////////////////////////////////////

// sets one vector equal to another
Vector3 Vector3::operator = (const Vector3& a_rVecSource)
{
	m_fX = a_rVecSource.m_fX;
	m_fY = a_rVecSource.m_fY;
	m_fZ = a_rVecSource.m_fZ;

	// return the existing object to allow for chaining
	return *this;
}
// subtracts a scalar from a vector, returns new vector
Vector3 Vector3::operator - (float a_fS)
{
	Vector3 vTemp;
	vTemp.m_fX = this->m_fX - a_fS;
	vTemp.m_fY = this->m_fY - a_fS;
	vTemp.m_fZ = this->m_fZ - a_fS;
	return vTemp;
}

// adds a scalar to a vector, returns new vector
Vector3 Vector3::operator + (float a_fS)
{
	Vector3 vTemp;
	vTemp.m_fX = this->m_fX + a_fS;
	vTemp.m_fY = this->m_fY + a_fS;
	vTemp.m_fZ = this->m_fZ + a_fS;
	return vTemp;
}

// multiplies a vector by a scalar, returns new vector
Vector3 Vector3::operator * (float a_fS)
{
	Vector3 vTemp;
	vTemp.m_fX = this->m_fX * a_fS;
	vTemp.m_fY = this->m_fY * a_fS;
	vTemp.m_fZ = this->m_fZ * a_fS;
	return vTemp;
}

// sets a vector equal to itself minus a scalar
void Vector3::operator -= (float a_fS)
{
	m_fX -= a_fS;
	m_fY -= a_fS;
	m_fZ -= a_fS;
}

// sets a vector equal to itself plus a scalar
void Vector3::operator += (float a_fS)
{
	m_fX += a_fS;
	m_fY += a_fS;
	m_fZ += a_fS;
}

// sets a vector equal to itself multiplied by a scalar
void Vector3::operator *= (float a_fS)
{
	m_fX *= a_fS;
	m_fY *= a_fS;
	m_fZ *= a_fS;
}

// subtracts one vector from another, returns new vector
Vector3 Vector3::operator - (const Vector3& a_rV2)
{
	Vector3 vTemp;
	vTemp.m_fX -= a_rV2.m_fX;
	vTemp.m_fY -= a_rV2.m_fY;
	vTemp.m_fZ -= a_rV2.m_fZ;
	return vTemp;
}

// adds one vector to another, returns new vector
Vector3 Vector3::operator + (const Vector3& a_rV2)
{
	Vector3 vTemp;
	vTemp.m_fX += a_rV2.m_fX;
	vTemp.m_fY += a_rV2.m_fY;
	vTemp.m_fZ += a_rV2.m_fZ;
	return vTemp;
}

// sets a vector equal to itself minus another vector
void Vector3::operator -= (Vector3& a_rV2)
{
	m_fX -= a_rV2.m_fX;
	m_fY -= a_rV2.m_fY;
	m_fZ -= a_rV2.m_fZ;
}

// sets a vector equal to itself plus another vector
void Vector3::operator += (Vector3& a_rV2)
{
	m_fX += a_rV2.m_fX;
	m_fY += a_rV2.m_fY;
	m_fZ += a_rV2.m_fZ;
}

// tests vector equality, returns bool
bool Vector3::operator == (const Vector3& a_rV2)
{
	if ((this->m_fX - a_rV2.m_fX < this->m_fThreshold) && (this->m_fY - a_rV2.m_fY < this->m_fThreshold) && (this->m_fZ - a_rV2.m_fZ < this->m_fThreshold))
		return true;
	else
		return false;
}

// returns magnitude of vector
float Vector3::GetMagnitude() const
{
	return sqrt(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ);
}

// normalize a vector
void Vector3::Normalize()
{
	float s = GetMagnitude();
	m_fX = m_fX / s;
	m_fY = m_fY / s;
	m_fZ = m_fZ / s;
}

// returns a normalized version of vector
Vector3 Vector3::ReturnNormalized() const
{
	float fMag = GetMagnitude();
	Vector3 vec(m_fX / fMag, m_fY / fMag, m_fZ / fMag);
	return vec;
}

// gets distance bethween two points
float Vector3::GetDistance(const Vector3 a_rV2) const
{
	return sqrt((a_rV2.m_fX - m_fX) * (a_rV2.m_fX - m_fX) + (a_rV2.m_fY - m_fY) * (a_rV2.m_fY - m_fY) + (a_rV2.m_fZ - m_fZ) * (a_rV2.m_fZ - m_fZ));
}

// dot product of 2 vectors
float Vector3::Dot(const Vector3& a_rV2) const
{
	return (m_fX * a_rV2.m_fX) + (m_fY * a_rV2.m_fY) + (m_fZ * a_rV2.m_fZ);
}

// cross product of 2 vectors
Vector3 Vector3::Cross(const Vector3& a_rV2) const
{
	return Vector3(m_fY * a_rV2.m_fZ - m_fZ * a_rV2.m_fY, 
				   m_fZ * a_rV2.m_fX - m_fX * a_rV2.m_fZ,
				   m_fX * a_rV2.m_fY - m_fY * a_rV2.m_fX);
}

// calculates angle between two vectors
float Vector3::GetAngle(const Vector3& a_rV2) const
{
	Vector3 V1 = this->ReturnNormalized();
	float dot = V1.Dot(a_rV2.ReturnNormalized());
	return acos(dot);
}
