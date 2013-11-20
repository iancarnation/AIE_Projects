///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			3x3 Matrix Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _UV_H_
#define _UV_H_

#include "Vector3.h"

class Matrix3
{
	public:
		Matrix3();					// default constructor
		Matrix3(float a_f0, float a_f3, float a_f6,
				float a_f1, float a_f4, float a_f7,
				float a_f2, float a_f5, float a_f8);  // const. with values
		~Matrix3();					// destructor
		
		Vector3 GetTranslations();	// returns the translation of the matrix as a vector
		float GetRotation();		// returns rotation of the matrix
		void SetTranslation(Vector3 a_TransVector);		// sets translation of the matrix (replaces curr. translation)
		void SetRotation(float a_fAngle);			// sets the rotation of the matrix (replaces curr. rotation)
		void TransformVector(float a_fAngle, float a_fScale);		// rotate and scales a directional vector
		void TransformPoint();		// rotate, scale and translate a point

		void Print();				// cout matrix

		float m_afMatrix [9];		/* 3x3 matrix stored as a 1d array
									   in column major order.. [0][3][6]
														       [1][4][7]
														       [2][5][8] */
	private:
		Matrix3 CreateIdentity();	// creates the appropriate identity matrix
		Matrix3 CreateRotation(float a_fAngle);		// creates new rotation matrix with 0,0 translation
		Matrix3 CreateTranslation(Vector3 a_TransVector);	// creates new translation matrix with 0 rotation
};

#endif