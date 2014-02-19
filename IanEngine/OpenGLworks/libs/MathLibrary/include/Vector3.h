///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <math.h>

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT Vector3
{
	public: 
		Vector3();							// default constructor
		Vector3(const Vector3& a_rVecSource);		// copy constructor
		Vector3(float a_fX, float a_fY, float a_fZ);	// constructor that takes in x and y values
		~ Vector3();						// destructor

		Vector3 operator - (float a_fS);		// subtracts a scalar from a vector, returns new vector
		Vector3 operator + (float a_fS);		// adds a scalar to a vector, returns new vector
		Vector3 operator * (float a_fS);		// multiplies a vector by a scalar, returns new vector
		Vector3 operator / (float a_fS);		// divides a vector by a scalar, returns new vector
		void operator -= (float a_fS);			// sets a vector equal to itself minus a scalar
		void operator += (float a_fS);			// sets a vector equal to itself plus a scalar
		void operator *= (float a_fS);			// sets a vector equal to itself multiplied by a scalar
		void operator /= (float a_fS);			// sets a vector equal to itself divided by a scalar
		Vector3 operator - (const Vector3& a_rV2);	// subtracts one vector from another, returns new vector
		Vector3 operator + (const Vector3& a_rV2);	// adds one vector to another, returns new vector
		Vector3 operator = (const Vector3& a_rVecSource); // sets one vector equal to another
		void operator -= (Vector3& a_rV2);		// sets a vector equal to itself minus another vector
		void operator += (Vector3& a_rV2);		// sets a vector equal to itself plus another vector
		bool operator == (const Vector3& a_rV2);	// tests vector equality
		
		float GetMagnitude() const;				// returns magnitude of vector
		void Normalize();						// normalize a vector
		Vector3 ReturnNormalized() const;		// returns a normalized copy of vector	
		float GetDistance(const Vector3 a_rV2) const;	// calculates distance bethween two vectors
		float Dot(const Vector3& a_rV2) const;		// dot product of 2 vectors
		Vector3 Cross(const Vector3& a_rV2) const;	// cross product of 2 vectors
		float GetAngle(const Vector3& a_rV2) const;	// calculates angle between two vectors
		Vector3 Lerp(const Vector3 a_VA, const Vector3 a_VB, const float a_t);	// linearly interpolates between two vectors by amount t
			
		float m_fX, m_fY, m_fZ;	// coordinate variables
};

#endif