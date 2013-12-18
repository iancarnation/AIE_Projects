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

// returns rotation of the matrix -------------------------------------------------------------
void M3GetRotationTest::SetData(Matrix3 a_oM, float a_fExpResult)
{
	m_oMatrix = a_oM;
	m_fResult = a_fExpResult;
}

bool M3GetRotationTest::DoTest()
{
	float Result = m_oMatrix.GetRotation();
	cout<< "\n---------------M3GetRotationTest---------------\n";
	return AreEqual(Result,m_fResult);
}

// sets translation of the matrix (replaces curr. translation) -------------------------------------------------------------
void M3SetTranslationTest::SetData(Matrix3 a_oM, Vector3 a_oV, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oTransVector = a_oV;
	m_oResult = a_oExpResult;
}

bool M3SetTranslationTest::DoTest()
{
	m_oMatrix.SetTranslation(m_oTransVector);
	cout<< "\n---------------M3SetTranslationTest---------------\n";
	return (m_oMatrix == m_oResult);
}

// sets the rotation of the matrix (replaces curr. rotation) -------------------------------------------------------------
void M3SetRotationTest::SetData(Matrix3 a_oM, float a_fA, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_fAngle = a_fA;
	m_oResult = a_oExpResult;
}

bool M3SetRotationTest::DoTest()
{
	m_oMatrix.SetRotation(m_fAngle);
	cout<< "\n---------------M3SetRotationTest---------------\n";
	return (m_oMatrix == m_oResult);
}

// sets scale of the matrix (replaces curr. matrix) -------------------------------------------------------------
void M3SetScaleTest::SetData(Matrix3 a_oM, float a_fS, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_fScale = a_fS;
	m_oResult = a_oExpResult;
}

bool M3SetScaleTest::DoTest()
{
	m_oMatrix.SetScale(m_fScale);
	cout<< "\n---------------M3SetScaleTest---------------\n";
	return (m_oMatrix == m_oResult);
}

// rotate and scales a directional vector -------------------------------------------------------------
void M3TransformVectorTest::SetData(Vector3 a_oV, float a_fA, float a_fS, Vector3 a_oExpResult)
{
	m_oVector = a_oV;
	m_fAngle = a_fA;
	m_fScale = a_fS;
	m_oResult = a_oExpResult;
}

bool M3TransformVectorTest::DoTest()
{
	Matrix3 Dummy;
	Dummy.TransformVector(m_oVector, m_fAngle, m_fScale);
	cout<< "\n---------------M3TransformVectorTest---------------\n";
	return (m_oVector == m_oResult);
}

// rotate, scale and translate a point -------------------------------------------------------------
void M3Transform2DPointTest::SetData(Vector3 a_oV, float a_fA, float a_fS, Vector3 a_oTrV, Vector3 a_oExpResult)
{
	m_oVector = a_oV;
	m_fAngle = a_fA;
	m_fScale = a_fS;
	m_oTransVector = a_oTrV;
	m_oResult = a_oExpResult;
}

bool M3Transform2DPointTest::DoTest()
{
	Matrix3 Dummy;
	Dummy.Transform2DPoint(m_oVector, m_fAngle, m_fScale, m_oTransVector);
	cout<< "\n---------------M3Transform2DPointTest---------------\n";
	return (m_oVector == m_oResult);
}

// creates the appropriate identity matrix -------------------------------------------------------------
void M3CreateIdentityTest::SetData(Matrix3 a_oM, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oResult = a_oExpResult;
}

bool M3CreateIdentityTest::DoTest()
{
	Matrix3 Result = m_oMatrix.CreateIdentity();
	cout<< "\n---------------M3CreateIdentityTest---------------\n";
	return (Result == m_oResult);
}

// creates new rotation matrix with 0,0 translation -------------------------------------------------------------
void M3CreateRotationTest::SetData(Matrix3 a_oM, float a_fA, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_fAngle = a_fA;
	m_oResult = a_oExpResult;
}

bool M3CreateRotationTest::DoTest()
{
	Matrix3 Result = m_oMatrix.CreateRotation(m_fAngle);
	cout<< "\n---------------M3CreateRotationTest---------------\n";
	return (Result == m_oResult);
}

// creates new scale matrix -------------------------------------------------------------
void M3CreateScaleTest::SetData(Matrix3 a_oM, float a_fS, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_fScale = a_fS;
	m_oResult = a_oExpResult;
}

bool M3CreateScaleTest::DoTest()
{
	Matrix3 Result = m_oMatrix.CreateScale(m_fScale);
	cout<< "\n---------------M3CreateScaleTest---------------\n";
	return (Result == m_oResult);
}

// creates new translation matrix with 0 rotation -------------------------------------------------------------
void M3CreateTranslationTest::SetData(Matrix3 a_oM, Vector3 a_oV, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oTransVector = a_oV;
	m_oResult = a_oExpResult;
}

bool M3CreateTranslationTest::DoTest()
{
	Matrix3 Result = m_oMatrix.CreateTranslation(m_oTransVector);
	cout<< "\n---------------M3CreateTranslationTest---------------\n";
	return (Result == m_oResult);
}

// creates orthographic projection matrix for given cardinal axis -------------------------------------------------------------
void M3CreateCardinalOrthoTest::SetData(Matrix3 a_oM, char a_cAxis, Matrix3 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_cAxis = a_cAxis;
	m_oResult = a_oExpResult;
}

bool M3CreateCardinalOrthoTest::DoTest()
{
	Matrix3 Result = m_oMatrix.CreateCardinalOrthoProj(m_cAxis);
	cout<< "\n---------------M3CreateCardinalOrthoTest---------------\n";
	return (Result == m_oResult);
}





