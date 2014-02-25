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
#include <string>
using namespace std;

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT Vector4
{
	public: 
		Vector4();													// default constructor
		Vector4(const Vector4& a_rVecSource);						// copy constructor
		Vector4(float a_fX, float a_fY, float a_fZ, float a_fW);	// constructor that takes in x and y values
		~ Vector4();												// destructor
		
		bool operator == (const Vector4& a_rV2);	// tests vector equality

		float GetMagnitude() const; 			// returns magnitude of vector
		void Normalize();						// normalize a vector
		Vector4 ReturnNormalized() const;		// returns a normalized copy of vector	
		Vector4 HexToRGB(int a_iHexCode);		// converts hex code to rgb floats and returns vector4 with alpha as well, expects ARGB
		Vector4 RGBToFloat();						// converts rgb values to values ranging from 0 to 1

		float m_fX, m_fY, m_fZ, m_fW;			// coordinate variables
};

#endif
