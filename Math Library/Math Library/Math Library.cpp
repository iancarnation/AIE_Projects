// Math Library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix3.h"
#include <iostream>
using namespace std;

int main()
{
	char satisfaction;

	Matrix3 DefMatrix;
	Matrix3 GivMatrix(1,4,7,
					  2,5,8,
					  3,6,9);

	cout<< "Default Matrix:\n";
	DefMatrix.Print();
	cout<< "Given Matrix:\n";
	GivMatrix.Print();

	cout<< "Given Matrix Rotation:\n";
	cout<< GivMatrix.GetRotation() << "\n";

	cout<< "Given Matrix Translations:\n";
	cout<< GivMatrix.GetTranslations().m_fX << GivMatrix.GetTranslations().m_fY<< GivMatrix.GetTranslations().m_fZ << "\n";

	Vector3 trans(1,1,1);
	GivMatrix.SetTranslation(trans);
	cout<< "With New Translations:\n";
	GivMatrix.Print();



	cout<< "Satisfied? ";
	cin>> satisfaction;

	return 0;
}

