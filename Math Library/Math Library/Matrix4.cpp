///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix4.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			4x4 Matrix Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix4.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// default constructor
Matrix4::Matrix4()
{
	m11 = 0; m12 = 0; m13 = 0; 
	m21 = 0; m22 = 0; m23 = 0; 
	m31 = 0; m32 = 0; m33 = 0; 
}	

// constructor with values, stores as 2D or 1D array, or as separate float variables
Matrix4::Matrix4(float a11, float a12, float a13,
				 float a21, float a22, float a23,
				 float a31, float a32, float a33)
{
	m11 = a11; m12 = a12; m13 = a13; 
	m21 = a21; m22 = a22; m23 = a23; 
	m31 = a31; m32 = a32; m33 = a33; 
}

// destructor
Matrix4::~Matrix4()	
{

}

// multiplies two matrices
Matrix4 Matrix4::operator * (const Matrix4& a_rM2) const
{
	Matrix4 r;  // result

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
Vector3 Matrix4::operator * (const Vector3& a_rV2) const
{
	Vector3 r;	// result

	r.m_fX = m11*a_rV2.m_fX + m12*a_rV2.m_fY + m13*a_rV2.m_fZ;
	r.m_fY = m21*a_rV2.m_fX + m22*a_rV2.m_fY + m23*a_rV2.m_fZ;
	r.m_fZ = m31*a_rV2.m_fX + m32*a_rV2.m_fY + m33*a_rV2.m_fZ;

	return r;
}

// multiplies matrix by scalar
Matrix4 Matrix4::operator * (const float a_fScalar) const 			
{
	Matrix4 r;	// result

	r.m11 = m11 * a_fScalar; r.m12 = m12 * a_fScalar; r.m13 = m13 * a_fScalar; 
	r.m21 = m21 * a_fScalar; r.m22 = m22 * a_fScalar; r.m23 = m23 * a_fScalar; 
	r.m31 = m31 * a_fScalar; r.m32 = m32 * a_fScalar; r.m33 = m33 * a_fScalar;

	return r;
}

Matrix4 Matrix4::CreateIdentity() const
{
	return Matrix4(1,0,0,
				   0,1,0,
				   0,0,1);
}

// creates new rotation matrix with 0,0 translation
Matrix4 Matrix4::CreateRotation(float a_fAngle) const
{
	return Matrix4(cos(a_fAngle),-sin(a_fAngle),0,
				   sin(a_fAngle),cos(a_fAngle),0,
				   0			,0			  ,1);	
}

// creates new translation matrix with 0 rotation
Matrix4 Matrix4::CreateTranslation(Vector3 a_TransVector) const
{
	return Matrix4(1,0,a_TransVector.m_fX,
				   0,1,a_TransVector.m_fY,
				   0,0,a_TransVector.m_fZ);
}

// returns the translation of the matrix as a vector
Vector3 Matrix4::GetTranslations()
{
	return Vector3(m13, m23, m33);
}

// returns rotation of the matrix
float Matrix4::GetRotation()
{
	return atan(- m12 / m11);
}

// sets translation of the matrix (replaces curr. translation)
void Matrix4::SetTranslation(Vector3 a_TransVector)
{
	Matrix4 TranslationMatrix = CreateTranslation(a_TransVector);
	*this = *this * TranslationMatrix;
}

// sets the rotation of the matrix (replaces curr. rotation)
void Matrix4::SetRotation(float a_fAngle)
{
	Matrix4 RotMatrix = CreateRotation(a_fAngle);
	*this = *this * RotMatrix;
}

// sets scale of the matrix (replaces curr. matrix)
void Matrix4::SetScale(float a_fScale)
{
	Matrix4 ScaleMatrix(a_fScale, 0		  , 0,
						0		, a_fScale, 0,
						0		, 0		  , 1);

	*this = *this * ScaleMatrix;
}

// rotate and scales a directional vector
void Matrix4::TransformVector(Vector3& a_rV, float a_fAngle, float a_fScale)
{
	Vector3 TempVec;
	Matrix4 TM = CreateRotation(a_fAngle);		// create rotation matrix
	TM.SetScale(a_fScale);						// multiply rotation matrix by scale matrix
	
	TempVec.m_fX = TM.m11*a_rV.m_fX + TM.m12*a_rV.m_fY + TM.m13*a_rV.m_fZ;
	TempVec.m_fY = TM.m21*a_rV.m_fX + TM.m22*a_rV.m_fY + TM.m23*a_rV.m_fZ;
	TempVec.m_fZ = TM.m31*a_rV.m_fX + TM.m32*a_rV.m_fY + TM.m33*a_rV.m_fZ;

	Vector3.m_fX = TempVec.m_fX;
	Vector3.m_fY = TempVec.m_fY;
	Vector3.m_fZ = TempVec.m_fZ;
}

//// rotate, scale and translate a point  **not done!!*****
//void Matrix4::TransformPoint(float a_fAngle, float a_fScale)
//{
//	Matrix4 RotMatrix = CreateRotation(a_fAngle);
//	Matrix4 ScaleMatrix(a_fScale, 0		  , 0,
//						0		, a_fScale, 0,
//						0		, 0		  , 1);
//
//	Matrix4 TransformMatrix = RotMatrix * ScaleMatrix;
//
//	*this = *this * TransformMatrix;
//}

// cout matrix
void Matrix4::Print()
{
	cout<< "[" << setprecision(2) << m11 << "]" << "[" << setprecision(2)  << m12 << "]" << "[" << setprecision(2)  << m13 << "]\n"
		<< "[" << setprecision(2)  << m21 << "]" << "[" << setprecision(2)  << m22 << "]" << "[" << setprecision(2)  << m23 << "]\n"
		<< "[" << setprecision(2)  << m31 << "]" << "[" << setprecision(2)  << m32 << "]" << "[" << setprecision(2)  << m33 << "]\n";

	cout<< endl;
}
