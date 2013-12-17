///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3FuncUTests.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test vector functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector3FuncUTests.h"

// Subtract scalar from vector -------------------------------------------------------------
void MagnitudeTest::SetData(Vector3 a_oVector, float a_fExpResult)
{
	m_oVector = a_oVector;
	m_fResult = a_fExpResult;
}

bool MagnitudeTest::DoTest()
{
	float Result = m_oVector.GetMagnitude();
	return (Result == m_fResult);
}

// returns a normalized version of vector -------------------------------------------------------------
void RetNormalizedTest::SetData(Vector3 a_oVector, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_oResult = a_oExpResult;
}

bool RetNormalizedTest::DoTest()
{
	m_oVector.ReturnNormalized();
	return (m_oVector == m_oResult);
}

// gets distance between two points -------------------------------------------------------------
void DistanceTest::SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_fResult = a_fExpResult;
}

bool DistanceTest::DoTest()
{
	float Result = m_oVector1.GetDistance(m_oVector2);
	return (Result == m_fResult);
}

// dot product of 2 vectors -------------------------------------------------------------
void DotTest::SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_fResult = a_fExpResult;
}

bool DotTest::DoTest()
{
	float Result = m_oVector1.Dot(m_oVector2);
	return (Result == m_fResult);
}

// cross product of 2 vectors -------------------------------------------------------------
void CrossTest::SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_oResult = a_oExpResult;
}

bool CrossTest::DoTest()
{
	Vector3 Result = m_oVector1.Cross(m_oVector2);
	return (Result == m_oResult);
}

// calculates angle between two vectors -------------------------------------------------------------
void GetAngleTest::SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_fResult = a_fExpResult;
}

bool GetAngleTest::DoTest()
{
	float Result = m_oVector1.GetAngle(m_oVector2);
	return (Result == m_fResult);
}

// linearly interpolates between two vectors for parameter t in range 0 to 1 -------------------------------------------------------------
void LerpTest::SetData(Vector3 a_oV1, Vector3 a_oV2, float a_fT, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_fT = a_fT;
	m_oResult = a_oExpResult;
}

bool LerpTest::DoTest()
{
	Vector3 Result = Result.Lerp(m_oVector1, m_oVector2, m_fT);
	return (Result == m_oResult);
}