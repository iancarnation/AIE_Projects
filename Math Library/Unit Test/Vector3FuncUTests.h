///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3FuncUTests.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test vector functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _VECTOR3FUNCUTESTS_H_
#define _VECTOR3FUNCUTESTS_H_

#include "UnitTest.h"
#include "Vector3.h"

// returns magnitude of vector -------------------------------------------------------------
class MagnitudeTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oVector, float a_fExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		float m_fResult;
};


// returns a normalized version of vector -------------------------------------------------------------
class RetNormalizedTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oVector, Vector3 a_oExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector;
		Vector3 m_oResult;
};

// gets distance between two points -------------------------------------------------------------
class DistanceTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		float m_fResult;
};

// dot product of 2 vectors -------------------------------------------------------------
class DotTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		float m_fResult;
};

// cross product of 2 vectors -------------------------------------------------------------
class CrossTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		Vector3 m_oResult;
};

// calculates angle between two vectors -------------------------------------------------------------
class GetAngleTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		float m_fResult;
};

// linearly interpolates between two vectors for parameter t in range 0 to 1 -------------------------------------------------------------
class LerpTest : public UnitTest
{
	public:
		void SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fT, Vector3 a_oExpResult);
		virtual bool DoTest(); 
	
	private:
		Vector3 m_oVector1;
		Vector3 m_oVector2;
		float m_fT;
		Vector3 m_oResult;
};


#endif