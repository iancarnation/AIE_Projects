///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			3x3 Matrix Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _UV_H_
#define _UV_H_

class Matrix3
{
	public:
		Matrix3();		// default constructor
		Matrix3(float a_f00, float a_f01, float a_f02,
				 float a_f10, float a_f11, float a_f12,
				 float a_f20, float a_f21, float a_f22);  // const. with values
		~Matrix3();		// destructor

		float m_afMatrix [2][2];
};

#endif