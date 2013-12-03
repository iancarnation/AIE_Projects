///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector4.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			3D Vector Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector4.h"
#include "Static Constants.h"
#include <string>
#include <iostream>
using namespace std;

//////////////////////////////-- CONSTRUCTION / DESTRUCTION --////////////////////////////////////////////////////////////

// default constructor
Vector4::Vector4 ()
{
	m_fX = 0;
	m_fY = 0;
	m_fZ = 0;
	m_fW = 1;
	//cout<< "Default Vector Constructed!\n";
}

// copy constructor
Vector4::Vector4(const Vector4& a_rVecSource)
{
	m_fX = a_rVecSource.m_fX;
	m_fY = a_rVecSource.m_fY;
	m_fZ = a_rVecSource.m_fZ;
	m_fW = a_rVecSource.m_fW;
}

// constructor that takes in x and y values
Vector4::Vector4 (float a_fX, float a_fY, float a_fZ, float a_fW)
{
	m_fX = a_fX;
	m_fY = a_fY;
	m_fZ = a_fZ;
	m_fW = a_fW;
	//cout<< "Vector constructed with given values " << a_fX << " and " << a_fY <<"!\n";
}

// destructor
Vector4::~Vector4 ()
{
	//cout<< "Vector Destroyed, Muhahah!\n";
}

//////////////////////////////-- MATHS --////////////////////////////////////////////////////////////

// sets one vector equal to another
Vector4 Vector4::operator = (const Vector4& a_rVecSource)
{
	m_fX = a_rVecSource.m_fX;
	m_fY = a_rVecSource.m_fY;
	m_fZ = a_rVecSource.m_fZ;
	m_fW = a_rVecSource.m_fW;

	// return the existing object to allow for chaining
	return *this;
}
// subtracts a scalar from a vector, returns new vector
Vector4 Vector4::operator - (float a_fS)
{
	Vector4 vTemp;
	vTemp.m_fX = this->m_fX - a_fS;
	vTemp.m_fY = this->m_fY - a_fS;
	vTemp.m_fZ = this->m_fZ - a_fS;
	vTemp.m_fW = this->m_fW - a_fS;
	return vTemp;
}

// adds a scalar to a vector, returns new vector
Vector4 Vector4::operator + (float a_fS)
{
	Vector4 vTemp;
	vTemp.m_fX = this->m_fX + a_fS;
	vTemp.m_fY = this->m_fY + a_fS;
	vTemp.m_fZ = this->m_fZ + a_fS;
	vTemp.m_fW = this->m_fW + a_fS;
	return vTemp;
}

// multiplies a vector by a scalar, returns new vector
Vector4 Vector4::operator * (float a_fS)
{
	Vector4 vTemp;
	vTemp.m_fX = this->m_fX * a_fS;
	vTemp.m_fY = this->m_fY * a_fS;
	vTemp.m_fZ = this->m_fZ * a_fS;
	vTemp.m_fW = this->m_fW * a_fS;
	return vTemp;
}

// sets a vector equal to itself minus a scalar
void Vector4::operator -= (float a_fS)
{
	m_fX -= a_fS;
	m_fY -= a_fS;
	m_fZ -= a_fS;
	m_fW -= a_fS;
}

// sets a vector equal to itself plus a scalar
void Vector4::operator += (float a_fS)
{
	m_fX += a_fS;
	m_fY += a_fS;
	m_fZ += a_fS;
	m_fW += a_fS;
}

// sets a vector equal to itself multiplied by a scalar
void Vector4::operator *= (float a_fS)
{
	m_fX *= a_fS;
	m_fY *= a_fS;
	m_fZ *= a_fS;
	m_fW *= a_fS;
}

// subtracts one vector from another, returns new vector
Vector4 Vector4::operator - (const Vector4& a_rV2)
{
	Vector4 vTemp;
	vTemp.m_fX -= a_rV2.m_fX;
	vTemp.m_fY -= a_rV2.m_fY;
	vTemp.m_fZ -= a_rV2.m_fZ;
	vTemp.m_fW -= a_rV2.m_fW;
	return vTemp;
}

// adds one vector to another, returns new vector
Vector4 Vector4::operator + (const Vector4& a_rV2)
{
	Vector4 vTemp;
	vTemp.m_fX += a_rV2.m_fX;
	vTemp.m_fY += a_rV2.m_fY;
	vTemp.m_fZ += a_rV2.m_fZ;
	vTemp.m_fW += a_rV2.m_fW;
	return vTemp;
}

// sets a vector equal to itself minus another vector
void Vector4::operator -= (Vector4& a_rV2)
{
	m_fX -= a_rV2.m_fX;
	m_fY -= a_rV2.m_fY;
	m_fZ -= a_rV2.m_fZ;
	m_fW -= a_rV2.m_fW;
}

// sets a vector equal to itself plus another vector
void Vector4::operator += (Vector4& a_rV2)
{
	m_fX += a_rV2.m_fX;
	m_fY += a_rV2.m_fY;
	m_fZ += a_rV2.m_fZ;
	m_fW += a_rV2.m_fW;
}

// tests vector equality, returns bool
bool Vector4::operator == (const Vector4& a_rV2)
{
	if ((this->m_fX - a_rV2.m_fX < THRESHOLD) && (this->m_fY - a_rV2.m_fY < THRESHOLD) && (this->m_fZ - a_rV2.m_fZ < THRESHOLD) && (this->m_fW - a_rV2.m_fW < THRESHOLD))
		return true;
	else
		return false;
}

// returns magnitude of vector
float Vector4::GetMagnitude() const
{
	return sqrt(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ + m_fW * m_fW);
}

// normalize a vector
void Vector4::Normalize()
{
	float s = GetMagnitude();
	m_fX = m_fX / s;
	m_fY = m_fY / s;
	m_fZ = m_fZ / s;
	m_fW = m_fW / s;
}

// returns a normalized version of vector
Vector4 Vector4::ReturnNormalized() const
{
	float fMag = GetMagnitude();
	Vector4 vec(m_fX / fMag, m_fY / fMag, m_fZ / fMag, m_fW / fMag);
	return vec;
}

// gets distance bethween two points
float Vector4::GetDistance(const Vector4 a_rV2) const
{
	return sqrt((a_rV2.m_fX - m_fX) * (a_rV2.m_fX - m_fX) + (a_rV2.m_fY - m_fY) * (a_rV2.m_fY - m_fY) + (a_rV2.m_fZ - m_fZ) * (a_rV2.m_fZ - m_fZ) + (a_rV2.m_fW - m_fW) * (a_rV2.m_fW - m_fW));
}

// dot product of 2 vectors
float Vector4::Dot(const Vector4& a_rV2) const
{
	return (m_fX * a_rV2.m_fX) + (m_fY * a_rV2.m_fY) + (m_fZ * a_rV2.m_fZ) + (m_fW * a_rV2.m_fW);
}

// cross product of 2 vectors
Vector4 Vector4::Cross(const Vector4& a_rV2) const
{
	return Vector4(m_fY * a_rV2.m_fZ - m_fZ * a_rV2.m_fY, 
				   m_fZ * a_rV2.m_fX - m_fX * a_rV2.m_fZ,
				   m_fX * a_rV2.m_fY - m_fY * a_rV2.m_fX);
}

// calculates angle between two vectors
float Vector4::GetAngle(const Vector4& a_rV2) const
{
	Vector4 V1 = this->ReturnNormalized();
	float dot = V1.Dot(a_rV2.ReturnNormalized());
	return acos(dot);
}

// linearly interpolates between two vectors for parameter t in range 0 to 1
Vector4 Vector4::Lerp(Vector4 a_VA, Vector4 a_VB, float a_t)
{
	return a_VA*(1-a_t) + a_VB*a_t;
}