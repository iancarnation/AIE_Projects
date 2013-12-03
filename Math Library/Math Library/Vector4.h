///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector4.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			3D Vector Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <math.h>

class Vector4
{
	public: 
		Vector4();													// default constructor
		Vector4(const Vector4& a_rVecSource);						// copy constructor
		Vector4(float a_fX, float a_fY, float a_fZ, float a_fW);	// constructor that takes in x and y values
		~ Vector4();												// destructor

		Vector4 operator = (const Vector4& a_rVecSource); // sets one vector equal to another
		Vector4 operator - (float a_fS);		// subtracts a scalar from a vector, returns new vector
		Vector4 operator + (float a_fS);		// adds a scalar to a vector, returns new vector
		Vector4 operator * (float a_fS);		// multiplies a vector by a scalar, returns new vector
		void operator -= (float a_fS);			// sets a vector equal to itself minus a scalar
		void operator += (float a_fS);			// sets a vector equal to itself plus a scalar
		void operator *= (float a_fS);			// sets a vector equal to itself multiplied by a scalar
		Vector4 operator - (const Vector4& a_rV2);	// subtracts one vector from another, returns new vector
		Vector4 operator + (const Vector4& a_rV2);	// adds one vector to another, returns new vector
		void operator -= (Vector4& a_rV2);		// sets a vector equal to itself minus another vector
		void operator += (Vector4& a_rV2);		// sets a vector equal to itself plus another vector
		bool operator == (const Vector4& a_rV2);	// tests vector equality
		
		float GetMagnitude() const;				// returns magnitude of vector
		void Normalize();						// normalize a vector
		Vector4 ReturnNormalized() const;		// returns a normalized copy of vector	
		float GetDistance(const Vector4 a_rV2) const;	// calculates distance bethween two vectors
		float Dot(const Vector4& a_rV2) const;		// dot product of 2 vectors
		Vector4 Cross(const Vector4& a_rV2) const;	// cross product of 2 vectors
		float GetAngle(const Vector4& a_rV2) const;	// calculates angle between two vectors
		Vector4 Lerp(const Vector4 a_VA, const Vector4 a_VB, const float a_t);	// linearly interpolates between two vectors by amount t
			
		float m_fX, m_fY, m_fZ, m_fW;	// coordinate variables
};

#endif