#include <iostream>
#include "Vector2D.h"

using namespace std;

// subtract a scalar from a vector
bool SubScalarFromVector(Vector2D& a_rDefault, Vector2D& a_rGiven, float a_fS, 
						 Vector2D& a_rExpected1, Vector2D& a_rExpected2)
{
	bool bPassed1 = false, bPassed2 = false;

	// test default
	cout<< "Subtracting Scalar From Default Vector: ";
	Vector2D oTempVector = a_rDefault - a_fS;
	if (oTempVector.Equals(a_rExpected1))
	{
		cout<<"Success!!\n\n";
		bPassed1 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected1.GetX() << "," << a_rExpected1.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	// test given
	cout<< "Subtracting Scalar From Given Vector: ";
	oTempVector = a_rGiven - a_fS;
	if (oTempVector.Equals(a_rExpected2))
	{
		cout<<"Success!!\n\n";
		bPassed2 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected2.GetX() << "," << a_rExpected2.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	if (bPassed1 && bPassed2)
		return true;
	else
		return false;
}

// add a scalar to a vector
bool AddScalarToVector(Vector2D& a_rDefault, Vector2D& a_rGiven, float a_fS,
						 Vector2D& a_rExpected1, Vector2D& a_rExpected2)
{
	bool bPassed1 = false, bPassed2 = false;

	// test default
	cout<< "Adding Scalar to Default Vector: ";
	Vector2D oTempVector = a_rDefault + a_fS;
	if (oTempVector.Equals(a_rExpected1))
	{
		cout<<"Success!!\n\n";
		bPassed1 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected1.GetX() << "," << a_rExpected1.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	// test given
	cout<< "Adding Scalar to Given Vector: ";
	oTempVector = a_rGiven + a_fS;
	if (oTempVector.Equals(a_rExpected2))
	{
		cout<<"Success!!\n\n";
		bPassed2 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected2.GetX() << "," << a_rExpected2.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	if (bPassed1 && bPassed2)
		return true;
	else
		return false;
}

// multiply a vector by a scalar
bool MultiplyScalarByVector(Vector2D& a_rDefault, Vector2D& a_rGiven, float a_fS,
						 Vector2D& a_rExpected1, Vector2D& a_rExpected2)
{
	bool bPassed1 = false, bPassed2 = false;

	// test default
	cout<< "Multiplying Scalar by Default Vector: ";
	Vector2D oTempVector = a_rDefault * a_fS;
	if (oTempVector.Equals(a_rExpected1))
	{
		cout<<"Success!!\n\n";
		bPassed1 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected1.GetX() << "," << a_rExpected1.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	// test given
	cout<< "Multiplying Scalar by Given Vector: ";
	oTempVector = a_rGiven * a_fS;
	if (oTempVector.Equals(a_rExpected2))
	{
		cout<<"Success!!\n\n";
		bPassed2 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected2.GetX() << "," << a_rExpected2.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	if (bPassed1 && bPassed2)
		return true;
	else
		return false;
}

// subtract one vector from another
bool SubVectorFromVector(Vector2D& a_rDefault, Vector2D& a_rGiven, Vector2D& a_rSubtractor,
						 Vector2D& a_rExpected1, Vector2D& a_rExpected2)
{
	bool bPassed1 = false, bPassed2 = false;

	// test default
	cout<< "Subtracting Subtractor Vector From Default Vector: ";
	Vector2D oTempVector = a_rDefault - a_rSubtractor;
	if (oTempVector.Equals(a_rExpected1))
	{
		cout<<"Success!!\n\n";
		bPassed1 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected1.GetX() << "," << a_rExpected1.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	// test given
	cout<< "Subtracting Subtractor Vector From Given Vector: ";
	oTempVector = a_rGiven - a_rSubtractor;
	if (oTempVector.Equals(a_rExpected2))
	{
		cout<<"Success!!\n\n";
		bPassed2 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected2.GetX() << "," << a_rExpected2.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	if (bPassed1 && bPassed2)
		return true;
	else
		return false;
}

// add one vector to another
bool Add2Vectors(Vector2D& a_rDefault, Vector2D& a_rGiven, Vector2D& a_rAdder,
						 Vector2D& a_rExpected1, Vector2D& a_rExpected2)
{
	bool bPassed1 = false, bPassed2 = false;

	// test default
	cout<< "Adding Adder Vector to Default Vector: ";
	Vector2D oTempVector = a_rDefault + a_rAdder;
	if (oTempVector.Equals(a_rExpected1))
	{
		cout<<"Success!!\n\n";
		bPassed1 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected1.GetX() << "," << a_rExpected1.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	// test given
	cout<< "Adding Adder Vector to Given Vector: ";
	oTempVector = a_rGiven + a_rAdder;
	if (oTempVector.Equals(a_rExpected2))
	{
		cout<<"Success!!\n\n";
		bPassed2 = true;
	}
	else
		cout<<"Failed :(\n\n";

	cout<< "Expected (" << a_rExpected2.GetX() << "," << a_rExpected2.GetY() << ")\n";
	cout<< "Result:  (" << oTempVector.GetX() << "," << oTempVector.GetY() << ")\n\n";

	if (bPassed1 && bPassed2)
		return true;
	else
		return false;
}

// tests getter and setter functions
void TestGetSet(Vector2D& a_rDefault, Vector2D& a_rGiven)
{
	cout<< "\n////////  Testing Getters and Setters //////////////\n";
	// test getter functions
	cout<< "---Current Values---\n";
	cout<< "Default Vector: (" << a_rDefault.GetX() << "," << a_rDefault.GetY() << ")\n";
	cout<< "Given Vector:   (" << a_rGiven.GetX() << "," << a_rGiven.GetY() << ")\n";

	// test setter functions
	a_rDefault.SetX(1.1);
	a_rDefault.SetY(1.1);
	a_rGiven.SetX(3.3);
	a_rGiven.SetY(3.3);

	cout<< "---Newly Set Values---\n";
	cout<< "Default Vector: (" << a_rDefault.GetX() << "," << a_rDefault.GetY() << ")\n";
	cout<< "Given Vector:   (" << a_rGiven.GetX() << "," << a_rGiven.GetY() << ")\n";

	// reset values
	a_rDefault.SetX(0.0);
	a_rDefault.SetY(0.0);
	a_rGiven.SetX(2.2);
	a_rGiven.SetY(8.6);

	cout<< "---Reset Values---\n";
	cout<< "Default Vector: (" << a_rDefault.GetX() << "," << a_rDefault.GetY() << ")\n";
	cout<< "Given Vector:   (" << a_rGiven.GetX() << "," << a_rGiven.GetY() << ")\n";
	cout<< "///////////////////////////////////////////////////////////////////////\n\n";
}

// test math operations
void TestMaths(Vector2D& a_rDefault, Vector2D& a_rGiven)
{
	// --------- subtract a scalar from a vector ---------------
	// Test 1
	if (SubScalarFromVector(a_rDefault, a_rGiven, -1.35, Vector2D(1.35,1.35), Vector2D(3.55,9.95)))
		cout<< "\nTest 1 Passed!\n\n";
 	else
		cout<< "\nTest 1 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

	// Test 2
	if (SubScalarFromVector(a_rDefault, a_rGiven, 6.66, Vector2D(-6.66,-6.66), Vector2D(-4.46,1.94)))
		cout<< "\nTest 2 Passed!\n\n";
	else
		cout<< "\nTest 2 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

	// --------- add a scalar to a vector ---------------
	// Test 1
	if (AddScalarToVector(a_rDefault, a_rGiven, -1.35, Vector2D(-1.35,-1.35), Vector2D(0.85,7.25)))
		cout<< "\nTest 1 Passed!\n\n";
	else
		cout<< "\nTest 1 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

	// Test 2
	if (AddScalarToVector(a_rDefault, a_rGiven, 6.66, Vector2D(6.66,6.66), Vector2D(8.86,15.26)))
		cout<< "\nTest 2 Passed!\n\n";
	else
		cout<< "\nTest 2 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

		// --------- multiply scalar by vector ---------------
	// Test 1
	if (MultiplyScalarByVector(a_rDefault, a_rGiven, -1.35, Vector2D(0,0), Vector2D(-2.97,-11.61)))
		cout<< "\nTest 1 Passed!\n\n";
	else
		cout<< "\nTest 1 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

	// Test 2
	if (MultiplyScalarByVector(a_rDefault, a_rGiven, 6.66, Vector2D(0,0), Vector2D(14.652,57.276)))
		cout<< "\nTest 2 Passed!\n\n";
	else
		cout<< "\nTest 2 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

		// --------- subtract vector from a vector ---------------
	// Test 1
	if (SubVectorFromVector(a_rDefault, a_rGiven, Vector2D(-1.35,2.22), Vector2D(1.35,-2.22), Vector2D(3.55,6.38)))
		cout<< "\nTest 1 Passed!\n\n";
	else
		cout<< "\nTest 1 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

	// Test 2
	if (SubVectorFromVector(a_rDefault, a_rGiven, Vector2D(6.66,3.33), Vector2D(-6.66,-3.33), Vector2D(-4.46,5.27)))
		cout<< "\nTest 2 Passed!\n\n";
	else
		cout<< "\nTest 2 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";

			// --------- add one vector to another vector ---------------
	// Test 1
	if (Add2Vectors(a_rDefault, a_rGiven, Vector2D(-1.35,2.22), Vector2D(-1.35,2.22), Vector2D(0.85,10.82)))
		cout<< "\nTest 1 Passed!\n\n";
	else
		cout<< "\nTest 1 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";
	// Test 2
	if (Add2Vectors(a_rDefault, a_rGiven, Vector2D(6.66,3.33), Vector2D(6.66,3.33), Vector2D(8.86,11.93)))
		cout<< "\nTest 2 Passed!\n\n";
	else
		cout<< "\nTest 2 Failed :(\n\n";
	cout<< "---------------------------------------------------------------------\n";
}

int main( int argc, char* argv[] )
{
	char satisfaction;

	// construct a default vector2D, and one with given values
	Vector2D oDefaultV2D, oGivenV2D(2.2, 8.6);

	// test Get and Set functions
	TestGetSet(oDefaultV2D, oGivenV2D);

	// test math operations
	TestMaths(oDefaultV2D, oGivenV2D);

	// stop execution exit for review
	cout<< "\nAre you satisfied with the results, Dr. Amazing? (y/n): ";
	cin>> satisfaction;

	if (satisfaction == 'y')
		cout<< "Ok then, peace out homie.";
	else
		cout<< "Too bad, better fix something you dumshit :)";

	return 0;
}