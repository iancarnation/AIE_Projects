///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix3UTests.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test Matrix3 functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix3UTests.h"

//######################## Matrix3 Operator Tests ###############################################

// multiplies two matrices -------------------------------------------------------------
void M3MultTest::SetData(Matrix3 a_oM1, Matrix3 a_oM2, Matrix3 a_oExpResult)
{
	m_oMatrix1 = a_oM1;
	m_oMatrix2 = a_oM2;
	m_oResult = a_oExpResult;
}

bool M3MultTest::DoTest()
{
	Matrix3 Result = m_oMatrix1 * m_oMatrix2;
	cout<< "\n---------------M3MultTest---------------\n";
	return (Result == m_oResult);
}

// matrix * vector = vector -------------------------------------------------------------
void M3MultVectorTest::SetData(Matrix3 a_oM, Vector3 a_oV, Vector3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oVector = a_oV;
	m_oResult = a_oExpResult;
}

bool M3MultVectorTest::DoTest()
{
	Vector3 Result = m_oMatrix * m_oVector;
	cout<< "\n---------------M3MultVectorTest---------------\n";
	return (Result == m_oResult);
}

// multiplies matrix by scalar -------------------------------------------------------------
void M3MultScalarTest::SetData(Matrix3 a_oM, float a_fS, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_fScalar = a_fS;
	m_oResult = a_oExpResult;
}

bool M3MultScalarTest::DoTest()
{
	Matrix3 Result = m_oMatrix * m_fScalar;
	cout<< "\n---------------M3MultScalarTest---------------\n";
	return (Result == m_oResult);
}

// tests matrix equality -------------------------------------------------------------
void M3EqualTest::SetData(Matrix3 a_oM1, Matrix3 a_oM2, bool a_bExpResult)
{
	m_oMatrix1 = a_oM1;
	m_oMatrix2 = a_oM2;
	m_bResult = a_bExpResult;
}

bool M3EqualTest::DoTest()
{
	bool Result = (m_oMatrix1 == m_oMatrix2);
	cout<< "\n---------------M3EqualTest---------------\n";
	return (Result == m_bResult);
}

//######################## Matrix3 Function Tests ###############################################

// returns the translation of the matrix as a vector -------------------------------------------------------------
void M3GetTranslationsTest::SetData(Matrix3 a_oM, Vector3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oResult = a_oExpResult;
}

bool M3GetTranslationsTest::DoTest()
{
	Vector3 Result = m_oMatrix.GetTranslations();
	cout<< "\n---------------M3GetTranslationsTest---------------\n";
	return (Result == m_oResult);
}

// returns the translation of the matrix as a vector -------------------------------------------------------------
void M3GetTranslationsTest::SetData(Matrix3 a_oM, Vector3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oResult = a_oExpResult;
}

bool M3GetTranslationsTest::DoTest()
{
	Vector3 Result = m_oMatrix.GetTranslations();
	cout<< "\n---------------M3GetTranslationsTest---------------\n";
	return (Result == m_oResult);
}