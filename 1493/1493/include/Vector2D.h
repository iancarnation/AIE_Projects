///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2D.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

class Vector2D
{
	private:		
		float x, y;			// coordinate variables

	public: 
		Vector2D();					// default constructor
		Vector2D(float x, float y);	// constructor that takes in position values
		~ Vector2D();				// destructor

		Vector2D operator - (float s);		// subtracts a scalar from a vector, returns new vector
		Vector2D operator + (float s);		// adds a scalar to a vector, returns new vector
		Vector2D operator * (float s);		// multiplies a vector by a scalar, returns new vector
		Vector2D operator - (const Vector2D &v2);	// subtracts one vector from another, returns new vector
		Vector2D operator + (const Vector2D &v2);	// adds one vector to another, returns new vector

		float GetX();	// returns x value
		float GetY();	// returns y value
		void SetX(float x);	// sets x value
		void SetY(float y);	// sets y value
};

#endif