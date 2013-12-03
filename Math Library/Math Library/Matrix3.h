///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			3x3 Matrix Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _UV_H_
#define _UV_H_

#include "Vector3.h"

class Matrix3
{
	public:
		Matrix3();										// default constructor
		Matrix3(float a11, float a12, float a13,
				float a21, float a22, float a23,
				float a31, float a32, float a33);	// const. with values
		~Matrix3();										// destructor
		
		Matrix3 operator * (const Matrix3& a_rM2) const;						// multiplies two matrices
		Vector3 operator * (const Vector3& a_rV2) const;						// matrix * vector = vector
		Matrix3 operator * (const float a_fScalar) const;						// multiplies matrix by scalar
		
		Vector3 GetTranslations();									// returns the translation of the matrix as a vector
		float GetRotation();										// returns rotation of the matrix
		void SetTranslation(Vector3 a_TransVector);					// sets translation of the matrix (replaces curr. translation)
		void SetRotation(float a_fAngle);							// sets the rotation of the matrix (replaces curr. rotation)
		void SetScale(float a_fScale);								// sets scale of the matrix (replaces curr. matrix)
		void TransformVector(Vector3 a_vector, float a_fAngle, float a_fScale);		// rotate and scales a directional vector
		//void TransformPoint(float a_fAngle, float a_fScale);		// rotate, scale and translate a point

		void Print();				// cout matrix

		float m11, m12, m13,
			  m21, m22, m23,
			  m31, m32, m33;		// 3x3 matrix stored as individual floats
	private:
		Matrix3 CreateIdentity() const;							// creates the appropriate identity matrix
		Matrix3 CreateRotation(float a_fAngle) const;				// creates new rotation matrix with 0,0 translation
		Matrix3 CreateTranslation(Vector3 a_TransVector) const;	// creates new translation matrix with 0 rotation
};

#endif