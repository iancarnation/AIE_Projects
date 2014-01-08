// Math Library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Static Constants.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <iostream>
using namespace std;

int main()
{
	char satisfaction;

	Matrix3 DefMatrix;
	Matrix3 GivMatrix(1,0,2,
					  0,1,3,
					  0,0,1);

	cout<< "Default Matrix:\n";
	DefMatrix.Print();
	cout<< "Given Matrix:\n";
	GivMatrix.Print();

	cout<< "Given Matrix Rotation:\n";
	cout<< GivMatrix.GetRotation() << "\n";

	cout<< "\nGiven Matrix Translations:\n";
	cout<< GivMatrix.GetTranslations().m_fX << GivMatrix.GetTranslations().m_fY<< GivMatrix.GetTranslations().m_fZ << "\n";

	Vector3 trans(4,6,1);
	GivMatrix.SetTranslation(trans);
	cout<< "\nWith New Translations:\n";
	GivMatrix.Print();

	float Angle = 90*(PI/180);
	GivMatrix.SetRotation(Angle);
	cout<< "\nWith New Rotation\n";
	GivMatrix.Print();

	cout<< "\nBasic Test Matrices\n";
	Matrix3 Mtrans(1, 0, 2,
				   0, 3, 3,
				   0, 0, 1);

	Matrix3 Morig(1, 2, 4, 
			      2, 1, 7,
			      0, 0, 1);

	cout<< "\nOriginal Matrix\n";
	Morig.Print();
	cout<< "\nTransformation Matrix\n";
	Mtrans.Print();

	cout<< "\nOriginal multiplied by transformation with *:\n";
	Morig = Morig * Mtrans;
	Morig.Print();
	cout<< "\nSatisfied? ";
	cin>> satisfaction;

	Vector4 M4TestVectorA(3,6,1,1), M4TestVectorT(4,2,2,2);
	Matrix4 TestMatrix4A(1,1,0,1,2,3,2,0,4,0,1,2,0,0,0,1);

	Matrix4 Dummy;
	Dummy.TransformPoint(M4TestVectorA, PI/2, 2, 'x', M4TestVectorT);

	return 0;
}

