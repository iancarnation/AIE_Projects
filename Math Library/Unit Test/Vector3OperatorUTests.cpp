///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3OperatorUTests.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test overloaded operators for vector3 class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector3OperatorUTests.h"

// Subtract scalar from vector -------------------------------------------------------------
void SubScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool SubScalarTest::DoTest()
{
	Vector3 Result = m_oVector - m_fScalar;
	return (Result == m_oResult);
}

// Add scalar to vector -------------------------------------------------------------
void AddScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool AddScalarTest::DoTest()
{
	Vector3 Result = m_oVector + m_fScalar;
	return (Result == m_oResult);
}

// Multiply vector by scalar -------------------------------------------------------------
void MultScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool MultScalarTest::DoTest()
{
	Vector3 Result = m_oVector * m_fScalar;
	return (Result == m_oResult);
}

// Divide vector by scalar -------------------------------------------------------------
void DivScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool DivScalarTest::DoTest()
{
	Vector3 Result = m_oVector / m_fScalar;
	return (Result == m_oResult);
}

// sets a vector equal to itself minus a scalar -------------------------------------------------------------
void SubEqualScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool SubEqualScalarTest::DoTest()
{
	m_oVector -= m_fScalar;
	return (m_oVector == m_oResult);
}

// sets a vector equal to itself plus a scalar -------------------------------------------------------------
void AddEqualScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool AddEqualScalarTest::DoTest()
{
	m_oVector += m_fScalar;
	return (m_oVector == m_oResult);
}

// sets a vector equal to itself multiplied by a scalar -------------------------------------------------------------
void MultEqualScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool MultEqualScalarTest::DoTest()
{
	m_oVector *= m_fScalar;
	return (m_oVector == m_oResult);
}

// sets a vector equal to itself divided by a scalar -------------------------------------------------------------
void DivEqualScalarTest::SetData(Vector3 a_oVector, float a_fScalar, Vector3 a_oExpResult)
{
	m_oVector = a_oVector;
	m_fScalar = a_fScalar;
	m_oResult = a_oExpResult;
}

bool DivEqualScalarTest::DoTest()
{
	m_oVector /= m_fScalar;
	return (m_oVector == m_oResult);
}

// subtracts one vector from another, returns new vector -------------------------------------------------------------
void VecSubTest::SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_oResult = a_oExpResult;
}

bool VecSubTest::DoTest()
{
	Vector3 Result = m_oVector1 - m_oVector2;
	return (Result == m_oResult);
}

// adds one vector to another, returns new vector -------------------------------------------------------------
void VecAddTest::SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_oResult = a_oExpResult;
}

bool VecAddTest::DoTest()
{
	Vector3 Result = m_oVector1 + m_oVector2;
	return (Result == m_oResult);
}

// sets one vector equal to another -------------------------------------------------------------
void VecSetEqualTest::SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_oResult = a_oExpResult;
}

bool VecSetEqualTest::DoTest()
{
	m_oVector1 = m_oVector2;
	return (m_oVector1 == m_oResult);
}


// sets a vector equal to itself minus another vector -------------------------------------------------------------
void VecSubEqualTest::SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_oResult = a_oExpResult;
}

bool VecSubEqualTest::DoTest()
{
	m_oVector1 -= m_oVector2;
	return (m_oVector1 == m_oResult);
}

// sets a vector equal to itself plus another vector -------------------------------------------------------------
void VecAddEqualTest::SetData(Vector3 a_oV1, Vector3 a_oV2, Vector3 a_oExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_oResult = a_oExpResult;
}

bool VecAddEqualTest::DoTest()
{
	m_oVector1 += m_oVector2;
	return (m_oVector1 == m_oResult);
}

// tests vector equality, returns bool -------------------------------------------------------------
void VecEqualTest::SetData(Vector3 a_oV1, Vector3 a_oV2, bool a_bExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_bResult = a_bExpResult;
}

bool VecEqualTest::DoTest()
{
	bool Result = (m_oVector1 == m_oVector2);
	return (Result == m_bResult);
}