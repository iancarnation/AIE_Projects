///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Matrix4UTests.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test Matrix4 functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix4UTests.h"

//######################## Matrix4 Operator Tests ###############################################

// multiplies two matrices -------------------------------------------------------------
void M4MultTest::SetData(Matrix4 a_oM1, Matrix4 a_oM2, Matrix4 a_oExpResult)
{
	m_oMatrix1 = a_oM1;
	m_oMatrix2 = a_oM2;
	m_oResult = a_oExpResult;
}

bool M4MultTest::DoTest()
{
	Matrix4 Result = m_oMatrix1 * m_oMatrix2;
	cout<< "\n---------------M4MultTest---------------\n";
	return (Result == m_oResult);
}

// matrix * vector = vector -------------------------------------------------------------
void M4MultVectorTest::SetData(Matrix4 a_oM, Vector4 a_oV, Vector4 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oVector = a_oV;
	m_oResult = a_oExpResult;
}

bool M4MultVectorTest::DoTest()
{
	Vector4 Result = m_oMatrix * m_oVector;
	cout<< "\n---------------M4MultVectorTest---------------\n";
	return (Result == m_oResult);
}

// multiplies matrix by scalar -------------------------------------------------------------
void M4MultScalarTest::SetData(Matrix4 a_oM, float a_fS, Matrix4 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_fScalar = a_fS;
	m_oResult = a_oExpResult;
}

bool M4MultScalarTest::DoTest()
{
	Matrix4 Result = m_oMatrix * m_fScalar;
	cout<< "\n---------------M4MultScalarTest---------------\n";
	return (Result == m_oResult);
}

// tests matrix equality -------------------------------------------------------------
void M4EqualTest::SetData(Matrix4 a_oM1, Matrix4 a_oM2, bool a_bExpResult)
{
	m_oMatrix1 = a_oM1;
	m_oMatrix2 = a_oM2;
	m_bResult = a_bExpResult;
}

bool M4EqualTest::DoTest()
{
	bool Result = (m_oMatrix1 == m_oMatrix2);
	cout<< "\n---------------M4EqualTest---------------\n";
	return (Result == m_bResult);
}

//######################## Matrix4 Function Tests ###############################################

// returns the translation of the matrix as a vector -------------------------------------------------------------
void M4GetTranslationsTest::SetData(Matrix4 a_oM, Vector4 a_oExpResult)
{
	m_oMatrix = a_oM;
	m_oResult = a_oExpResult;
}

bool M4GetTranslationsTest::DoTest()
{
	Vector4 Result = m_oMatrix.GetTranslations();
	cout<< "\n---------------M4GetTranslationsTest---------------\n";
	return (Result == m_oResult);
}

// returns rotation of the matrix -------------------------------------------------------------
void M4GetRotationTest::SetData(Matrix4 a_oM, float a_fExpResult)
{
	m_oMatrix = a_oM;
	m_fResult = a_fExpResult;
}

bool M4GetRotationTest::DoTest()
{
	float Result = m_oMatrix.GetRotation();
	cout<< "\n---------------M4GetRotationTest---------------\n";
	return AreEqual(Result,m_fResult);
}

//// sets translation of the matrix (replaces curr. translation) -------------------------------------------------------------
//void M4SetTranslationTest::SetData(Matrix4 a_oM, Vector4 a_oV, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_oTransVector = a_oV;
//	m_oResult = a_oExpResult;
//}
//
//bool M4SetTranslationTest::DoTest()
//{
//	m_oMatrix.SetTranslation(m_oTransVector);
//	cout<< "\n---------------M4SetTranslationTest---------------\n";
//	return (m_oMatrix == m_oResult);
//}
//
//// sets the rotation of the matrix (replaces curr. rotation) -------------------------------------------------------------
//void M4SetRotationTest::SetData(Matrix4 a_oM, float a_fA, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_fAngle = a_fA;
//	m_oResult = a_oExpResult;
//}
//
//bool M4SetRotationTest::DoTest()
//{
//	m_oMatrix.SetRotation(m_fAngle);
//	cout<< "\n---------------M4SetRotationTest---------------\n";
//	return (m_oMatrix == m_oResult);
//}
//
//// sets scale of the matrix (replaces curr. matrix) -------------------------------------------------------------
//void M4SetScaleTest::SetData(Matrix4 a_oM, float a_fS, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_fScale = a_fS;
//	m_oResult = a_oExpResult;
//}
//
//bool M4SetScaleTest::DoTest()
//{
//	m_oMatrix.SetScale(m_fScale);
//	cout<< "\n---------------M4SetScaleTest---------------\n";
//	return (m_oMatrix == m_oResult);
//}
//
//// rotate and scales a directional vector -------------------------------------------------------------
//void M4TransformVectorTest::SetData(Vector4 a_oV, float a_fA, float a_fS, Vector4 a_oExpResult)
//{
//	m_oVector = a_oV;
//	m_fAngle = a_fA;
//	m_fScale = a_fS;
//	m_oResult = a_oExpResult;
//}
//
//bool M4TransformVectorTest::DoTest()
//{
//	Matrix4 Dummy;
//	Dummy.TransformVector(m_oVector, m_fAngle, m_fScale);
//	cout<< "\n---------------M4TransformVectorTest---------------\n";
//	return (m_oVector == m_oResult);
//}
//
//// rotate, scale and translate a point -------------------------------------------------------------
//void M4TransformPointTest::SetData(Vector4 a_oV, float a_fA, float a_fS, Vector4 a_oTrV, Vector4 a_oExpResult)
//{
//	m_oVector = a_oV;
//	m_fAngle = a_fA;
//	m_fScale = a_fS;
//	m_oTransVector = a_oTrV;
//	m_oResult = a_oExpResult;
//}
//
//bool M4TransformPointTest::DoTest()
//{
//	Matrix4 Dummy;
//	Dummy.TransformPoint(m_oVector, m_fAngle, m_fScale, m_oTransVector);
//	cout<< "\n---------------M4Transform2DPointTest---------------\n";
//	return (m_oVector == m_oResult);
//}
//
//// creates the appropriate identity matrix -------------------------------------------------------------
//void M4CreateIdentityTest::SetData(Matrix4 a_oM, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_oResult = a_oExpResult;
//}
//
//bool M4CreateIdentityTest::DoTest()
//{
//	Matrix4 Result = m_oMatrix.CreateIdentity();
//	cout<< "\n---------------M4CreateIdentityTest---------------\n";
//	return (Result == m_oResult);
//}
//
//// creates new rotation matrix with 0,0 translation -------------------------------------------------------------
//void M4CreateRotationTest::SetData(Matrix4 a_oM, float a_fA, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_fAngle = a_fA;
//	m_oResult = a_oExpResult;
//}
//
//bool M4CreateRotationTest::DoTest()
//{
//	Matrix4 Result = m_oMatrix.CreateRotation(m_fAngle);
//	cout<< "\n---------------M4CreateRotationTest---------------\n";
//	return (Result == m_oResult);
//}
//
//// creates new scale matrix -------------------------------------------------------------
//void M4CreateScaleTest::SetData(Matrix4 a_oM, float a_fS, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_fScale = a_fS;
//	m_oResult = a_oExpResult;
//}
//
//bool M4CreateScaleTest::DoTest()
//{
//	Matrix4 Result = m_oMatrix.CreateScale(m_fScale);
//	cout<< "\n---------------M4CreateScaleTest---------------\n";
//	return (Result == m_oResult);
//}
//
//// creates new translation matrix with 0 rotation -------------------------------------------------------------
//void M4CreateTranslationTest::SetData(Matrix4 a_oM, Vector4 a_oV, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_oTransVector = a_oV;
//	m_oResult = a_oExpResult;
//}
//
//bool M4CreateTranslationTest::DoTest()
//{
//	Matrix4 Result = m_oMatrix.CreateTranslation(m_oTransVector);
//	cout<< "\n---------------M4CreateTranslationTest---------------\n";
//	return (Result == m_oResult);
//}
//
//// creates orthographic projection matrix for given cardinal axis -------------------------------------------------------------
//void M4CreateCardinalOrthoTest::SetData(Matrix4 a_oM, char a_cAxis, Matrix4 a_oExpResult)
//{
//	m_oMatrix = a_oM;
//	m_cAxis = a_cAxis;
//	m_oResult = a_oExpResult;
//}
//
//bool M4CreateCardinalOrthoTest::DoTest()
//{
//	Matrix4 Result = m_oMatrix.CreateCardinalOrthoProj(m_cAxis);
//	cout<< "\n---------------M4CreateCardinalOrthoTest---------------\n";
//	return (Result == m_oResult);
//}





