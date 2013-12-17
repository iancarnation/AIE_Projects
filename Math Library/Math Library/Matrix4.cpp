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
	m11 = 0; m12 = 0; m13 = 0; m14 = 0; 
	m21 = 0; m22 = 0; m23 = 0; m24 = 0; 
	m31 = 0; m32 = 0; m33 = 0; m34 = 0; 
	m41 = 0; m42 = 0; m43 = 0; m44 = 0;
}	

// constructor with values, stores as 2D or 1D array, or as separate float variables
Matrix4::Matrix4(float a11, float a12, float a13, float a14,
				 float a21, float a22, float a23, float a24,
				 float a31, float a32, float a33, float a34,
				 float a41, float a42, float a43, float a44)
{
	m11 = a11; m12 = a12; m13 = a13; m14 = a14; 
	m21 = a21; m22 = a22; m23 = a23; m24 = a24; 
	m31 = a31; m32 = a32; m33 = a33; m34 = a34; 
	m41 = a41; m42 = a42; m43 = a43; m44 = a44; 
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
Vector4 Matrix4::operator * (const Vector4& a_rV2) const
{
	Vector4 r;	// result

	r.m_fX = m11*a_rV2.m_fX + m12*a_rV2.m_fY + m13*a_rV2.m_fZ + m14*a_rV2.m_fW;
	r.m_fY = m21*a_rV2.m_fX + m22*a_rV2.m_fY + m23*a_rV2.m_fZ + m24*a_rV2.m_fW;
	r.m_fZ = m31*a_rV2.m_fX + m32*a_rV2.m_fY + m33*a_rV2.m_fZ + m34*a_rV2.m_fW;
	r.m_fW = m41*a_rV2.m_fX + m42*a_rV2.m_fY + m43*a_rV2.m_fZ + m44*a_rV2.m_fW;

	return r;
}

// multiplies matrix by scalar
Matrix4 Matrix4::operator * (const float a_fScalar) const 			
{
	Matrix4 r;	// result

	r.m11 = m11 * a_fScalar; r.m12 = m12 * a_fScalar; r.m13 = m13 * a_fScalar; r.m14 = m14 * a_fScalar;
	r.m21 = m21 * a_fScalar; r.m22 = m22 * a_fScalar; r.m23 = m23 * a_fScalar; r.m24 = m24 * a_fScalar;
	r.m31 = m31 * a_fScalar; r.m32 = m32 * a_fScalar; r.m33 = m33 * a_fScalar; r.m34 = m34 * a_fScalar;
	r.m41 = m41 * a_fScalar; r.m42 = m42 * a_fScalar; r.m43 = m43 * a_fScalar; r.m44 = m44 * a_fScalar;

	return r;
}

Matrix4 Matrix4::CreateIdentity()
{
	return Matrix4(1,0,0,0,
				   0,1,0,0,
				   0,0,1,0,
				   0,0,0,1);
}

// creates new rotation matrix with 0,0 translation around given cardinal axis
Matrix4 Matrix4::CreateRotation(float a_fAngle, char a_cAxis)
{
	float C = cos(a_fAngle);
	float S = sin(a_fAngle);

	switch(a_cAxis)
	{
	case 'x':
		return Matrix4(1, 0, 0, 0,
					   0, C, S, 0,
					   0,-S, C, 0,
					   0, 0, 0, 1);
		break;

	case 'y':
		return Matrix4(C, 0,-S, 0,
					   0, 1, 0, 0,
					   S, 0, C, 0,
					   0, 0, 0, 1);
		break;

	case 'z':
		return Matrix4(C, S, 0, 0,
					  -S, C, 0, 0,
					   0, 0, 1, 0,
					   0, 0, 0, 1);	
		break;
	};
}

// creates new scale matrix
Matrix4 Matrix4::CreateScale(float a_fScale)
{
	return Matrix4(a_fScale, 0		 , 0       , 0,
				   0	   , a_fScale, 0       , 0,
				   0	   , 0		 , a_fScale, 0,
				   0       , 0       , 0       , 1);
}

// creates new translation matrix with 0 rotation
Matrix4 Matrix4::CreateTranslation(Vector4 a_TransVector)
{
	return Matrix4(1,0,0,a_TransVector.m_fX,
				   0,1,0,a_TransVector.m_fY,
				   0,0,1,a_TransVector.m_fZ,
				   0,0,0,a_TransVector.m_fW);
}

// creates new orthographic projection matrix for projecting onto given plane
Matrix4 Matrix4::CreateOrthoProj(plane3D PLANE)
{
	switch(PLANE)
	{
	case XY:
		return Matrix4(1,0,0,0,
					   0,1,0,0,
					   0,0,0,0,
					   0,0,0,1); break;
	case XZ:
		return Matrix4(1,0,0,0,
					   0,0,0,0,
					   0,0,1,0,
					   0,0,0,1); break;
	case YZ:
		return Matrix4(0,0,0,0,
					   0,1,0,0,
					   0,0,1,0,
					   0,0,0,1); break;
	};
}

// returns the translation of the matrix as a vector
Vector4 Matrix4::GetTranslations()
{
	return Vector4(m13, m23, m33, m43);
}

// returns rotation of the matrix relative to given cardinal axis
float Matrix4::GetRotation(char a_cAxis)
{
	switch(a_cAxis)
	{
	case 'x':
		return atan(-m23 / m22);
		break;
	case 'y':
		return atan(-m13 / m11); // might be wrong ***
		break;
	case 'z':
		return atan(-m12 / m11);
		break;
	};
	
}

// sets translation of the matrix (replaces curr. translation)
void Matrix4::SetTranslation(Vector4 a_TransVector)
{
	Matrix4 TranslationMatrix = CreateTranslation(a_TransVector);
	*this = *this * TranslationMatrix;
}

// sets the rotation of the matrix (replaces curr. rotation)
void Matrix4::SetRotation(float a_fAngle, char a_cAxis)
{
	Matrix4 RotMatrix = CreateRotation(a_fAngle, a_cAxis);
	*this = *this * RotMatrix;
}

// sets scale of the matrix (replaces curr. matrix)
void Matrix4::SetScale(float a_fScale)
{
	Matrix4 ScaleMatrix = CreateScale(a_fScale);

	*this = *this * ScaleMatrix;
}

// rotate and scales a directional vector
void Matrix4::TransformVector(Vector4& a_rV, float a_fAngle, char a_cAxis, float a_fScale)
{
	Vector4 TempVec;
	Matrix4 TM = CreateRotation(a_fAngle, a_cAxis);		// create rotation matrix
	TM.SetScale(a_fScale);								// multiply rotation matrix by scale matrix
	
	TempVec.m_fX = TM.m11*a_rV.m_fX + TM.m12*a_rV.m_fY + TM.m13*a_rV.m_fZ + TM.m13*a_rV.m_fW;
	TempVec.m_fY = TM.m21*a_rV.m_fX + TM.m22*a_rV.m_fY + TM.m23*a_rV.m_fZ + TM.m23*a_rV.m_fW;
	TempVec.m_fZ = TM.m31*a_rV.m_fX + TM.m32*a_rV.m_fY + TM.m33*a_rV.m_fZ + TM.m33*a_rV.m_fW;
	TempVec.m_fW = TM.m41*a_rV.m_fX + TM.m42*a_rV.m_fY + TM.m43*a_rV.m_fZ + TM.m43*a_rV.m_fW;

	a_rV.m_fX = TempVec.m_fX;
	a_rV.m_fY = TempVec.m_fY;
	a_rV.m_fZ = TempVec.m_fZ;
	a_rV.m_fW = TempVec.m_fW;
}

// rotate, scale and translate a point
void Matrix4::TransformPoint(Vector4& a_rV, float a_fAngle, char a_cAxis, float a_fScale, Vector4 a_TransVector)
{
	Vector4 TempVec;
	Matrix4 TM =  CreateRotation(a_fAngle, a_cAxis);	// create rotation matrix
	TM.SetScale(a_fScale);								// multiply rotation matrix by scale matrix
	TM.SetTranslation(a_TransVector);					// multiply transformation matrix by translation matrix

	TempVec.m_fX = TM.m11*a_rV.m_fX + TM.m12*a_rV.m_fY + TM.m13*a_rV.m_fZ + TM.m13*a_rV.m_fW;
	TempVec.m_fY = TM.m21*a_rV.m_fX + TM.m22*a_rV.m_fY + TM.m23*a_rV.m_fZ + TM.m23*a_rV.m_fW;
	TempVec.m_fZ = TM.m31*a_rV.m_fX + TM.m32*a_rV.m_fY + TM.m33*a_rV.m_fZ + TM.m33*a_rV.m_fW;
	TempVec.m_fW = TM.m41*a_rV.m_fX + TM.m42*a_rV.m_fY + TM.m43*a_rV.m_fZ + TM.m43*a_rV.m_fW;

	if (TempVec.m_fW !=1 && TempVec.m_fW !=0)
	{
		TempVec.m_fX = TempVec.m_fX / TempVec.m_fW;
		TempVec.m_fY = TempVec.m_fY / TempVec.m_fW;
		TempVec.m_fZ = TempVec.m_fZ / TempVec.m_fW;
	}

	a_rV.m_fX = TempVec.m_fX;
	a_rV.m_fY = TempVec.m_fY;
	a_rV.m_fZ = TempVec.m_fZ;
	a_rV.m_fW = TempVec.m_fW;
}

// cout matrix
void Matrix4::Print()
{
	cout<< "[" << setprecision(2) << m11 << "]" << "[" << setprecision(2)  << m12 << "]" << "[" << setprecision(2)  << m13 << "]" << "[" << setprecision(2)  << m14 << "]\n"
		<< "[" << setprecision(2) << m21 << "]" << "[" << setprecision(2)  << m22 << "]" << "[" << setprecision(2)  << m23 << "]" << "[" << setprecision(2)  << m24 << "]\n"
		<< "[" << setprecision(2) << m31 << "]" << "[" << setprecision(2)  << m32 << "]" << "[" << setprecision(2)  << m33 << "]" << "[" << setprecision(2)  << m34 << "]\n"
		<< "[" << setprecision(2) << m41 << "]" << "[" << setprecision(2)  << m42 << "]" << "[" << setprecision(2)  << m43 << "]" << "[" << setprecision(2)  << m44 << "]\n";

	cout<< endl;
}
