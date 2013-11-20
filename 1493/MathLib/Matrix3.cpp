///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			3x3 Matrix Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix3.h"

// default constructor
Matrix3::Matrix3()
{
	for(int i=0; i<2; i++)
		for(int j=0; i<2; j++)
			m_afMatrix[i][j] = 0;
}	

// constructor with values, stores as 2D or 1D array, or as separate float variables
Matrix3::Matrix3(float a_f00, float a_f01, float a_f02,
				 float a_f10, float a_f11, float a_f12,
				 float a_f20, float a_f21, float a_f22)  
{
	m_afMatrix[0][0] = a_f00; m_afMatrix[0][1] = a_f01; m_afMatrix[0][2] = a_f02;
	m_afMatrix[1][0] = a_f10; m_afMatrix[1][1] = a_f11; m_afMatrix[1][2] = a_f12;
	m_afMatrix[2][0] = a_f20; m_afMatrix[2][1] = a_f21; m_afMatrix[2][2] = a_f22; 
}

// destructor
Matrix3::~Matrix3()	
{

}
