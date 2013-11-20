///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			3x3 Matrix Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix3.h"
#include <iostream>
#include <math.h>
using namespace std;

// default constructor
Matrix3::Matrix3()
{
	for(int i=0; i<9; i++)
		m_afMatrix[i] = 0;
}	

// constructor with values, stores as 2D or 1D array, or as separate float variables
Matrix3::Matrix3(float a_f0, float a_f1, float a_f2,
				float a_f3, float a_f4, float a_f5,
				float a_f6, float a_f7, float a_f8)  
{
	m_afMatrix[0] = a_f0; m_afMatrix[3] = a_f3; m_afMatrix[6] = a_f6;
	m_afMatrix[1] = a_f1; m_afMatrix[4] = a_f4; m_afMatrix[7] = a_f7;
	m_afMatrix[2] = a_f2; m_afMatrix[5] = a_f5; m_afMatrix[8] = a_f8;
}

// destructor
Matrix3::~Matrix3()	
{

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
				   sin(a_fAngle) ,cos(a_fAngle),0,
				   0			 ,0			   ,1);	
}

// creates new translation matrix with 0 rotation
Matrix3 Matrix3::CreateTranslation(Vector3 a_TransVector)
{
	return Matrix3(1,0,a_TransVector.m_fX,
				   0,1,a_TransVector.m_fY,
				   0,0,a_TransVector.m_fZ);
}

// returns the translation of the matrix as a vector
Vector3 Matrix3::GetTranslations()
{
	return Vector3(m_afMatrix[6], m_afMatrix[7], m_afMatrix[8]);
}

// returns rotation of the matrix
float Matrix3::GetRotation()
{
	return atan(-m_afMatrix[3] / m_afMatrix[0]);
}

// sets translation of the matrix (replaces curr. translation)
void Matrix3::SetTranslation(Vector3 a_TransVector)
{
	Matrix3 TransMatrix = CreateTranslation(a_TransVector);
	this-> *= TransMatrix;
}

// sets the rotation of the matrix (replaces curr. rotation)
void Matrix3::SetRotation(float a_fAngle)
{
	Matrix3 RotMatrix = CreateRotation(a_fAngle);
	this-> *= RotMatrix;
}

// rotate and scales a directional vector
void Matrix3::TransformVector(float a_fAngle, float a_fScale)
{
	Matrix3 RotMatrix = CreateRotation(a_fAngle);
	Matrix3 ScaleMatrix(a_fScale, 0		  , 0,
						0		, a_fScale, 0,
						0		, 0		  , a_fScale);

	Matrix3 TransMatrix = RotMatrix * ScaleMatrix;

	this-> * TransMatrix;
}

// rotate, scale and translate a point
void Matrix3::TransformPoint()
{

}

// cout matrix
void Matrix3::Print()
{
	cout<< "[" << m_afMatrix[0] << "]" << "[" << m_afMatrix[3] << "]" << "[" << m_afMatrix[6] << "]\n"
		<< "[" << m_afMatrix[1] << "]" << "[" << m_afMatrix[4] << "]" << "[" << m_afMatrix[7] << "]\n"
		<< "[" << m_afMatrix[2] << "]" << "[" << m_afMatrix[5] << "]" << "[" << m_afMatrix[8] << "]\n";

	cout<< endl;
}
