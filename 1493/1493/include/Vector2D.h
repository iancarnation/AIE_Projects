///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2D.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <math.h>

class Vector2D
{
	public: 
		Vector2D();							// default constructor
		Vector2D(const Vector2D& a_rVecSource);		// copy constructor
		Vector2D(float a_fX, float afY);	// constructor that takes in x and y values
		~ Vector2D();						// destructor

		Vector2D operator = (const Vector2D& a_rVecSource); // sets one vector equal to another
		Vector2D operator - (float a_fS);		// subtracts a scalar from a vector, returns new vector
		Vector2D operator + (float a_fS);		// adds a scalar to a vector, returns new vector
		Vector2D operator * (float a_fS);		// multiplies a vector by a scalar, returns new vector
		void operator -= (float a_fS);			// sets a vector equal to itself minus a scalar
		void operator += (float a_fS);			// sets a vector equal to itself plus a scalar
		void operator *= (float a_fS);			// sets a vector equal to itself multiplied by a scalar
		Vector2D operator - (const Vector2D& a_rV2);	// subtracts one vector from another, returns new vector
		Vector2D operator + (const Vector2D& a_rV2);	// adds one vector to another, returns new vector
		void operator -= (Vector2D& a_rV2);		// sets a vector equal to itself minus another vector
		void operator += (Vector2D& a_rV2);		// sets a vector equal to itself plus another vector
		bool operator == (const Vector2D& a_rV2);	// tests vector equality
		
		float GetMagnitude() const;				// returns magnitude of vector
		void Normalize();						// normalize a vector
		Vector2D ReturnNormalized() const;		// returns a normalized version of vector	
		float GetDistance(const Vector2D a_rV2) const;	// calculates distance bethween two vectors
		float Dot(const Vector2D& a_rV2) const;		// dot product of 2 vectors
		float GetAngle(const Vector2D& a_rV2) const;	// calculates angle between two vectors

		float GetX() const;	// returns x value
		float GetY() const;	// returns y value
		void SetX(float a_fX);	// sets x value
		void SetY(float a_fY);	// sets y value
	
	private:		
		float m_fX, m_fY;	// coordinate variables
		float m_fThreshold;	// float comparison threshold

};

#endif

