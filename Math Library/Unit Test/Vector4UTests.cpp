///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector4UTests.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test vector4 functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector4UTests.h"

// tests vector equality, returns bool -------------------------------------------------------------
void VecEqualTest::SetData(Vector4 a_oV1, Vector4 a_oV2, bool a_bExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_bResult = a_bExpResult;
}

bool VecEqualTest::DoTest()
{
	bool Result = (m_oVector1 == m_oVector2);
	cout<< "\n---------------VecEqualTest---------------\n";
	return (Result == m_bResult);
}

// returns magnitude of vector -------------------------------------------------------------
void MagnitudeTest::SetData(Vector4 a_oVector, float a_fExpResult)
{
	m_oVector = a_oVector;
	m_fResult = a_fExpResult;
}

bool MagnitudeTest::DoTest()
{
	float Result = m_oVector.GetMagnitude();
	cout<< "\n---------------MagnitudeTest---------------\n";
	return AreEqual(Result, m_fResult);
}

// returns a normalized version of vector -------------------------------------------------------------
void RetNormalizedTest::SetData(Vector4 a_oVector, Vector4 a_oExpResult)
{
	m_oVector = a_oVector;
	m_oResult = a_oExpResult;
}

bool RetNormalizedTest::DoTest()
{
	Vector4 TempVec = m_oVector.ReturnNormalized();
	cout<< "\n---------------RetNormalizedTest---------------\n";
	return (TempVec == m_oResult);
}
