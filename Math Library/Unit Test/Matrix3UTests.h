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

// sets translation of the matrix (replaces curr. translation) -------------------------------------------------------------
class M3SetTranslationTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, Vector3 a_oV, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		Vector3 m_oTransVector;
		Matrix3 m_oResult;
};

// sets the rotation of the matrix (replaces curr. rotation) -------------------------------------------------------------
class M3SetRotationTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, float a_fA, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		float m_fAngle;
		Matrix3 m_oResult;
};

// sets scale of the matrix (replaces curr. matrix) -------------------------------------------------------------
class M3SetScaleTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, float a_fS, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		float m_fScale;
		Matrix3 m_oResult;
};

// rotate and scales a directional vector -------------------------------------------------------------
class M3TransformVectorTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fA, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fAngle, m_fScale;
		Vector3 m_oResult;
};

// rotate, scale and translate a point -------------------------------------------------------------
class M3Transform2DPointTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fA, float a_fS, Vector3 a_oTrV, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector, m_oTransVector;
		float m_fAngle, m_fScale;
		Vector3 m_oResult;
};

// creates an identity matrix -------------------------------------------------------------
class M3CreateIdentityTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		Matrix3 m_oResult;
};

// creates new rotation matrix with 0,0 translation -------------------------------------------------------------
class M3CreateRotationTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, float a_fA, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		float m_fAngle;
		Matrix3 m_oResult;
};

// creates new scale matrix -------------------------------------------------------------
class M3CreateScaleTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, float a_fS, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		float m_fScale;
		Matrix3 m_oResult;
};

// creates new translation matrix with 0 rotation -------------------------------------------------------------
class M3CreateTranslationTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, Vector3 a_oV, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		Vector3 m_oTransVector;
		Matrix3 m_oResult;
};

// creates orthographic projection matrix for given cardinal axis -------------------------------------------------------------
class M3CreateCardinalOrthoTest : public UnitTest
{
	public:
		void SetData(Matrix3 a_oM, char a_cAxis, Matrix3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix3 m_oMatrix;
		char m_cAxis;
		Matrix3 m_oResult;
};




#endif