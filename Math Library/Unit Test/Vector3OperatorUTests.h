///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3OperatorUTests.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test overloaded operators for vector3 class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _VECTOR3OPERATORUTESTS_H_
#define _VECTOR3OPERATORUTESTS_H_

#include "UnitTest.h"
#include "Vector3.h"

// Subtract scalar from vector -------------------------------------------------------------
class SubScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// Add scalar to vector -------------------------------------------------------------
class AddScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// Multiply vector by scalar -------------------------------------------------------------
class MultScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// Divide vector by scalar -------------------------------------------------------------
class DivScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// sets a vector equal to itself minus a scalar -------------------------------------------------------------
class SubEqualScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// sets a vector equal to itself plus a scalar -------------------------------------------------------------
class AddEqualScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// sets a vector equal to itself multiplied by a scalar -------------------------------------------------------------
class MultEqualScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// sets a vector equal to itself divided by a scalar -------------------------------------------------------------
class DivEqualScalarTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV, float a_fS, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fScalar;
		Vector3 m_oResult;
};

// subtracts one vector from another, returns new vector -------------------------------------------------------------
class VecSubTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		Vector3 m_oResult;
};

// adds one vector to another, returns new vector -------------------------------------------------------------
class VecAddTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		Vector3 m_oResult;
};

// sets one vector equal to another -------------------------------------------------------------
class VecSetEqualTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		Vector3 m_oResult;
};

// sets a vector equal to itself minus another vector -------------------------------------------------------------
class VecSubEqualTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		Vector3 m_oResult;
};

// sets a vector equal to itself plus another vector -------------------------------------------------------------
class VecAddEqualTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		Vector3 m_oResult;
};

// tests vector equality, returns bool -------------------------------------------------------------
class VecEqualTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, bool a_bExpResult);		
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		bool m_bResult;
};



#endif
