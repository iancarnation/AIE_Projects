///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix4UTests.h
// Author:			Ian Rich
// Date Created:	2014
// Brief:			Test Matrix4 functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _MATRIX4UTESTS_H_
#define _MATRIX4UTESTS_H_

#include "UnitTest.h"
#include "Matrix4.h"
#include "CommonFunctions.h"

//######################## Matrix4 Operator Tests ###############################################

// multiplies two matrices -------------------------------------------------------------
class M4MultTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM1, Matrix4 a_oM2, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix1, m_oMatrix2;
		Matrix4 m_oResult;
};

// matrix * vector = vector -------------------------------------------------------------
class M4MultVectorTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, Vector4 a_oV, Vector4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		Vector4 m_oVector, m_oResult;
};

// multiplies matrix by scalar -------------------------------------------------------------
class M4MultScalarTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, float a_fS, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		float m_fScalar;
		Matrix4 m_oResult;
};

// tests matrix equality -------------------------------------------------------------
class M4EqualTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM1, Matrix4 a_oM2, bool a_bExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix1, m_oMatrix2;
		bool m_bResult;
};

//######################## Matrix4 Function Tests ###############################################

// returns the translation of the matrix as a vector -------------------------------------------------------------
class M4GetTranslationsTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, Vector4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		Vector4 m_oResult;
};

//*** To be added when actually attempting 3D stuff ***
//// returns rotation of the matrix -------------------------------------------------------------
//class M4GetRotationTest : public UnitTest
//{
//	public:
//		void SetData(Matrix4 a_oM, float a_fExpResult);		
//		virtual bool DoTest(); 
//	
//	private:
//		Matrix4 m_oMatrix;
//		float m_fResult;
//};

// sets translation of the matrix (replaces curr. translation) -------------------------------------------------------------
class M4SetTranslationTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, Vector4 a_oV, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		Vector4 m_oTransVector;
		Matrix4 m_oResult;
};

// sets the rotation of the matrix (replaces curr. rotation) -------------------------------------------------------------
class M4SetRotationTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, float a_fA, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		float m_fAngle;
		Matrix4 m_oResult;
};

// sets scale of the matrix (replaces curr. matrix) -------------------------------------------------------------
class M4SetScaleTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, float a_fS, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		float m_fScale;
		Matrix4 m_oResult;
};

// rotate and scales a directional vector -------------------------------------------------------------
class M4TransformVectorTest : public UnitTest
{
	public:
		void SetData(Vector4 a_oV, float a_fA, float a_fS, Vector4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector4 m_oVector;
		float m_fAngle, m_fScale;
		Vector4 m_oResult;
};

// rotate, scale and translate a point -------------------------------------------------------------
class M4TransformPointTest : public UnitTest
{
	public:
		void SetData(Vector4 a_oV, float a_fA, float a_fS, Vector4 a_oTrV, Vector4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector4 m_oVector, m_oTransVector;
		float m_fAngle, m_fScale;
		Vector4 m_oResult;
};

// creates an identity matrix -------------------------------------------------------------
class M4CreateIdentityTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		Matrix4 m_oResult;
};

// creates new rotation matrix with 0,0 translation -------------------------------------------------------------
class M4CreateRotationTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, float a_fA, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		float m_fAngle;
		Matrix4 m_oResult;
};

// creates new scale matrix -------------------------------------------------------------
class M4CreateScaleTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, float a_fS, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		float m_fScale;
		Matrix4 m_oResult;
};

// creates new translation matrix with 0 rotation -------------------------------------------------------------
class M4CreateTranslationTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, Vector4 a_oV, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		Vector4 m_oTransVector;
		Matrix4 m_oResult;
};

// creates orthographic projection matrix for given cardinal axis -------------------------------------------------------------
class M4CreateCardinalOrthoTest : public UnitTest
{
	public:
		void SetData(Matrix4 a_oM, char a_cAxis, Matrix4 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Matrix4 m_oMatrix;
		char m_cAxis;
		Matrix4 m_oResult;
};




#endif