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
	Matrix3 GivMatrix(4,5,6,2,3,5,7,8,9);

	cout<< "Default Matrix:\n";
	DefMatrix.Print();
	cout<< "Given Matrix:\n";
	GivMatrix.Print();

	cout<< "Satisfied? ";
	cin>> satisfaction;

	return 0;
}

