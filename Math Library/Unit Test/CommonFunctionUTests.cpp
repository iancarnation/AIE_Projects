///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			CommonFunctionUTests.cpp
// Author:			Ian Rich
// Date Created:	2014
// Brief:			Test Common Math Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CommonFunctionUTests.h"

// linear interpolation for scalar values -------------------------------------------------------------
void LerpScalarTest::SetData(float a_fStart, float a_fEnd, float a_fT, float a_fExpResult)
{
	m_fStart = a_fStart;
	m_fEnd = a_fEnd;
	m_fT = a_fT;
	m_fResult = a_fExpResult;
}

bool LerpScalarTest::DoTest()
{
	float Result = LerpScalar(m_fStart, m_fEnd, m_fT);
	cout<< "\n---------------LerpScalarTest---------------\n";
	return (Result == m_fResult);
}

// convert angle from degrees to radians -------------------------------------------------------------
void DegToRadTest::SetData(float a_fAngle, float a_fExpResult)
{
	m_fAngle = a_fAngle;
	m_fResult = a_fExpResult;
}

bool DegToRadTest::DoTest()
{
	float Result = DegToRad(m_fAngle);
	cout<< "\n---------------DegToRadTest---------------\n";
	return (Result == m_fResult);
}

// convert angle from radians to degrees -------------------------------------------------------------
void RadToDegTest::SetData(float a_fAngle, float a_fExpResult)
{
	m_fAngle = a_fAngle;
	m_fResult = a_fExpResult;
}

bool RadToDegTest::DoTest()
{
	float Result = RadToDeg(m_fAngle);
	cout<< "\n---------------RadToDegTest---------------\n";
	return (Result == m_fResult);
}

// Testing scalar value for Power of Two (shift to nearest power of two) -------------------------------------------------------------
void NextPower2Test::SetData(int a_iValue, int a_iExpResult)
{
	m_iValue = a_iValue;
	m_iResult = a_iExpResult;
}

bool NextPower2Test::DoTest()
{
	NextPower2(m_iValue);
	cout<< "\n---------------NextPower2Test---------------\n";
	return (m_iValue == m_iResult);
}