///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			3x3 Matrix Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix3.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// default constructor
Matrix3::Matrix3()
{
	m11 = 0; m12 = 0; m13 = 0; 
	m21 = 0; m22 = 0; m23 = 0; 
	m31 = 0; m32 = 0; m33 = 0; 
}	

// constructor with values, stores as 2D or 1D array, or as separate float variables
Matrix3::Matrix3(float a11, float a12, float a13,
				 float a21, float a22, float a23,
				 float a31, float a32, float a33)
{
	m11 = a11; m12 = a12; m13 = a13; 
	m21 = a21; m22 = a22; m23 = a23; 
	m31 = a31; m32 = a32; m33 = a33; 
}

// destructor
Matrix3::~Matrix3()	
{

}

// multiplies two matrices
Matrix3 Matrix3::operator * (const Matrix3& a_rM2) const
{
	Matrix3 r;  // result

	r.m11 = m11*a_rM2.m11 + m12*a_rM2.m21 + m13*a_rM2.m31;
	r.m12 = m11*a_rM2.m12 + m12*a_rM2.m22 + m13*a_rM2.m32;
	r.m13 = m11*a_rM2.m13 + m12*a_rM2.m23 + m13*a_rM2.m33;

	r.m21 = m21*a_rM2.m11 + m22*a_rM2.m21 + m23*a_rM2.m31;
	r.m22 = m21*a_rM2.m12 + m22*a_rM2.m22 + m23*a_rM2.m32;
	r.m23 = m21*a_rM2.m13 + m22*a_rM2.m23 + m23*a_rM2.m33;

	r.m31 = m31*a_rM2.m11 + m32*a_rM2.m21 + m33*a_rM2.m31;
	r.m32 = m31*a_rM2.m12 + m32*a_rM2.m22 + m33*a_rM2.m32;
	r.m33 = m31*a_rM2.m13 + m32*a_rM2.m23 + m33*a_rM2.m33;

	return r;
}

// matrix * vector = vector
Vector3 Matrix3::operator * (const Vector3& a_rV2) const
{
	Vector3 r;	// result

	r.m_fX = m11*a_rV2.m_fX + m12*a_rV2.m_fY + m13*a_rV2.m_fZ;
	r.m_fY = m21*a_rV2.m_fX + m22*a_rV2.m_fY + m23*a_rV2.m_fZ;
	r.m_fZ = m31*a_rV2.m_fX + m32*a_rV2.m_fY + m33*a_rV2.m_fZ;

	return r;
}

// multiplies matrix by scalar
Matrix3 Matrix3::operator * (const float a_fScalar) const 			
{
	Matrix3 r;	// result

	r.m11 = m11 * a_fScalar; r.m12 = m12 * a_fScalar; r.m13 = m13 * a_fScalar; 
	r.m21 = m21 * a_fScalar; r.m22 = m22 * a_fScalar; r.m23 = m23 * a_fScalar; 
	r.m31 = m31 * a_fScalar; r.m32 = m32 * a_fScalar; r.m33 = m33 * a_fScalar;

	return r;
}

// tests matrix equality
bool Matrix3::operator == (const Matrix3& a_rM2) const
{
	return (AreEqual(m11,a_rM2.m11) && AreEqual(m12,a_rM2.m12) && AreEqual(m13,a_rM2.m13) && 
			AreEqual(m12,a_rM2.m12) && AreEqual(m22,a_rM2.m22) && AreEqual(m23,a_rM2.m23) && 
			AreEqual(m13,a_rM2.m13) && AreEqual(m32,a_rM2.m32) && AreEqual(m33,a_rM2.m33));
}

Matrix3 Matrix3::CreateIdentity()
{
	return Matrix3(1,0,0,
				   0,1,0,
				   0,0,1);
}

// creates new rotation matrix with 0,0 translation
Matrix3 Matrix3::CreateRotation(float a_fAngle)
{
	return Matrix3(cos(a_fAngle),-sin(a_fAngle),0,
				   sin(a_fAngle),cos(a_fAngle),0,
				   0			,0			  ,1);	
}

// creates new scale matrix
Matrix3 Matrix3::CreateScale(float a_fScale)
{
	return Matrix3(a_fScale, 0		 , 0,
				   0	   , a_fScale, 0,
				   0	   , 0		 , 1);
}

// creates new translation matrix with 0 rotation
Matrix3 Matrix3::CreateTranslation(Vector3 a_TransVector)
{
	return Matrix3(1,0,a_TransVector.m_fX,
				   0,1,a_TransVector.m_fY,
				   0,0,a_TransVector.m_fZ);
}

// creates orthographic projection matrix for given cardinal axis
Matrix3 Matrix3::CreateCardinalOrthoProj(char a_axis)
{
	switch(a_axis)
	{
	case 'x':
		return Matrix3(1,0,0,
					   0,0,0,
					   0,0,1); break;
	case 'y':
		return Matrix3(0,0,0,
					   0,1,0,
					   0,0,1); break;
	};
}

// returns the translation of the matrix as a vector
Vector3 Matrix3::GetTranslations()
{
	return Vector3(m13, m23, m33);
}

// returns rotation of the matrix
float Matrix3::GetRotation()
{
	return atan(- m12 / m11);
}

// sets translation of the matrix (replaces curr. translation)
void Matrix3::SetTranslation(Vector3 a_TransVector)
{
	Matrix3 TranslationMatrix = CreateTranslation(a_TransVector);
	*this = *this * TranslationMatrix;
}

// sets the rotation of the matrix (replaces curr. rotation)
void Matrix3::SetRotation(float a_fAngle)
{
	Matrix3 RotMatrix = CreateRotation(a_fAngle);
	*this = *this * RotMatrix;
}

// sets scale of the matrix (replaces curr. matrix)
void Matrix3::SetScale(float a_fScale)
{
	Matrix3 ScaleMatrix = CreateScale(a_fScale);

	*this = *this * ScaleMatrix;
}

// rotate and scales a directional vector
void Matrix3::TransformVector(Vector3& a_rV, float a_fAngle, float a_fScale)
{
	Vector3 TempVec;
	Matrix3 TM = CreateRotation(a_fAngle);		// create rotation matrix
	TM.SetScale(a_fScale);						// multiply rotation matrix by scale matrix

	/*	Transformed vector = Translation Matrix (TM) * referenced vector (a_rV)

		[x]	  [11][12][13]   [x]
		[y]	= [21][22][23] * [y]
		[z]	  [31][32][33]   [z]   */
	
	TempVec.m_fX = TM.m11*a_rV.m_fX + TM.m12*a_rV.m_fY + TM.m13*a_rV.m_fZ;
	TempVec.m_fY = TM.m21*a_rV.m_fX + TM.m22*a_rV.m_fY + TM.m23*a_rV.m_fZ;
	TempVec.m_fZ = TM.m31*a_rV.m_fX + TM.m32*a_rV.m_fY + TM.m33*a_rV.m_fZ;
	
	// change referenced vector
	a_rV = TempVec;
}

// rotate, scale and translate a point **not sure about **
void Matrix3::Transform2DPoint(Vector3& a_rV, float a_fAngle, float a_fScale, Vector3 a_TransVector)
{
	Matrix3 RotMatrix = CreateRotation(a_fAngle);
	Matrix3 ScaleMatrix = CreateScale(a_fScale);
	Matrix3 TlateMatrix = CreateTranslation(a_TransVector);

	Matrix3 TM = RotMatrix * ScaleMatrix * TlateMatrix;

	Vector3 TempVec;

	TempVec.m_fX = TM.m11*a_rV.m_fX + TM.m12*a_rV.m_fY + TM.m13*a_rV.m_fZ; // supposed to just add last element? http://www.scratchapixel.com/lessons/3d-basic-lessons/lesson-4-geometry/transforming-points-and-vectors/
	TempVec.m_fY = TM.m21*a_rV.m_fX + TM.m22*a_rV.m_fY + TM.m23*a_rV.m_fZ;
	TempVec.m_fZ = TM.m31*a_rV.m_fX + TM.m32*a_rV.m_fY + TM.m33*a_rV.m_fZ;

	if (TempVec.m_fZ != 1 && TempVec.m_fZ != 0)
	{
		TempVec.m_fX /= TempVec.m_fZ;
		TempVec.m_fY /= TempVec.m_fZ;
		TempVec.m_fZ /= TempVec.m_fZ;
	}

	a_rV = TempVec;
}

// cout matrix
void Matrix3::Print()
{
	cout<< "[" << setprecision(2) << m11 << "]" << "[" << setprecision(2)  << m12 << "]" << "[" << setprecision(2)  << m13 << "]\n"
		<< "[" << setprecision(2)  << m21 << "]" << "[" << setprecision(2)  << m22 << "]" << "[" << setprecision(2)  << m23 << "]\n"
		<< "[" << setprecision(2)  << m31 << "]" << "[" << setprecision(2)  << m32 << "]" << "[" << setprecision(2)  << m33 << "]\n";

	cout<< endl;
}
