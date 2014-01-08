///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			CommonFunctionUTests.h
// Author:			Ian Rich
// Date Created:	2014
// Brief:			Test Common Math Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _COMMONFUNCTIONUTESTS_H_
#define _COMMONFUNCTIONUTESTS_H_

#include "UnitTest.h"
#include "CommonFunctions.h"

// linear interpolation for scalar values -------------------------------------------------------------
class LerpScalarTest : public UnitTest
{
	public:
		void SetData(float a_fStart, float a_fEnd, float a_fT, float a_fExpResult);		
		virtual bool DoTest(); 
	
	private:
		float m_fStart, m_fEnd, m_fT, m_fResult;
};

// convert angle from degrees to radians -------------------------------------------------------------
class DegToRadTest : public UnitTest
{
	public:
		void SetData(float a_fAngle, float a_fExpResult);		
		virtual bool DoTest(); 
	
	private:
		float m_fAngle, m_fResult;
};

// convert angle from radians to degrees -------------------------------------------------------------
class RadToDegTest : public UnitTest
{
	public:
		void SetData(float a_fAngle, float a_fExpResult);		
		virtual bool DoTest(); 
	
	private:
		float m_fAngle, m_fResult;
};

// Testing scalar value for Power of Two (shift to nearest power of two) -------------------------------------------------------------
class NextPower2Test : public UnitTest
{
	public:
		void SetData(int a_iValue, int a_iExpResult);		
		virtual bool DoTest(); 
	
	private:
		int m_iValue, m_iResult;
};

#endif