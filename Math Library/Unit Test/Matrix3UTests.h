///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3UTests.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test Matrix3 functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _MATRIX3UTESTS_H_
#define _MATRIX3UTESTS_H_

#include "UnitTest.h"
#include "Matrix3.h"
#include "CommonFunctions.h"

//######################## Matrix3 Operator Tests ###############################################

// multiplies two matrices -------------------------------------------------------------
class M3MultTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM1, Matrix3 a_oM2, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix1, m_oMatrix2;
		Matrix3 m_oResult;
};

// matrix * vector = vector -------------------------------------------------------------
class M3MultVectorTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, Vector3 a_oV, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		Vector3 m_oVector, m_oResult;
};

// multiplies matrix by scalar -------------------------------------------------------------
class M3MultScalarTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, float a_fS, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		float m_fScalar;
		Matrix3 m_oResult;
};

// tests matrix equality -------------------------------------------------------------
class M3EqualTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM1, Matrix3 a_oM2, bool a_bExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix1, m_oMatrix2;
		bool m_bResult;
};

//######################## Matrix3 Function Tests ###############################################

// returns the translation of the matrix as a vector -------------------------------------------------------------
class M3GetTranslationsTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		Vector3 m_oResult;
};

// returns rotation of the matrix -------------------------------------------------------------
class M3GetRotationTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, float a_fExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		float m_fResult;
};





#endif