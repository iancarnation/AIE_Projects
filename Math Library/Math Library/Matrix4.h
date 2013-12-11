///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix4.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			4x4 Matrix Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _UV_H_
#define _UV_H_

#include "Vector4.h"

class Matrix4
{
	public:
		Matrix4();												// default constructor
		Matrix4(float a11, float a12, float a13, float a14,
				float a21, float a22, float a23, float a24,
				float a31, float a32, float a33, float a34,
				float a41, float a42, float a43, float a44);	// const. with values
		~Matrix4();												// destructor
		
		Matrix4 operator * (const Matrix4& a_rM2) const;			// multiplies two matrices
		Vector4 operator * (const Vector4& a_rV2) const;			// matrix * vector = vector
		Matrix4 operator * (const float a_fScalar) const;			// multiplies matrix by scalar
		
		Vector4 GetTranslations();									// returns the translation of the matrix as a vector
		float GetRotation(char a_cAxis);							// returns rotation of the matrix
		void SetTranslation(Vector4 a_TransVector);					// sets translation of the matrix (replaces curr. translation)
		void SetRotation(float a_fAngle, char a_cAxis);				// sets the rotation of the matrix (replaces curr. rotation)
		void SetScale(float a_fScale);								// sets scale of the matrix (replaces curr. matrix)
		void TransformVector(Vector4& a_rV, float a_fAngle, char a_cAxis, float a_fScale);		// rotate and scales a directional vector
		//void TransformPoint(float a_fAngle, float a_fScale);		// rotate, scale and translate a point

		void Print();				// cout matrix

		float m11, m12, m13, m14,
			  m21, m22, m23, m24,
			  m31, m32, m33, m34,
			  m41, m42, m43, m44;		// 3x3 matrix stored as individual floats
	private:
		Matrix4 CreateIdentity() const;							// creates the appropriate identity matrix
		Matrix4 CreateRotation(float a_fAngle, char a_cAxis) const;				// creates new rotation matrix with 0,0 translation
		Matrix4 CreateTranslation(Vector4 a_TransVector) const;	// creates new translation matrix with 0 rotation
};

#endif