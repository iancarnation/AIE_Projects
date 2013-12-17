///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTestMain.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Unit Test Main
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UnitTest.h"
#include "Vector3OperatorUTests.h"
#include "Vector3FuncUTests.h"

int main()
{
	// top-level test object
	UnitTester oTester;

	Vector3 TestVector1, TestVector2(2.2,8.6,4.3); // default constructor (values are zero) and an argued constructor

	//######################## Vector3 Operator Tests ###############################################

	// Subtract scalar from vector -------------------------------------------------------------
	UnitTestGroup oSubScalarTests;

	SubScalarTest oSubScalarTestOne, oSubScalarTestTwo, oSubScalarTestThree, oSubScalarTestFour;

	oSubScalarTestOne.SetData(TestVector1, -1.35, Vector3(1.35,1.35,1.35));
	oSubScalarTestTwo.SetData(TestVector1, 1.35, Vector3(-1.35,-1.35,-1.35));
	oSubScalarTestThree.SetData(TestVector2, -1.35, Vector3(3.55,9.95,5.65));
	oSubScalarTestFour.SetData(TestVector2, 1.35, Vector3(0.85,7.25,2.95));

	oSubScalarTests.AddUnitTest(&oSubScalarTestOne);
	oSubScalarTests.AddUnitTest(&oSubScalarTestTwo);
	oSubScalarTests.AddUnitTest(&oSubScalarTestThree);
	oSubScalarTests.AddUnitTest(&oSubScalarTestFour);
	oTester.AddUnitTestGroup(oSubScalarTests);

	// Add scalar to vector -------------------------------------------------------------
	UnitTestGroup oAddScalarTests;

	SubScalarTest oAddScalarTestOne, oAddScalarTestTwo, oAddScalarTestThree, oAddScalarTestFour;

	oAddScalarTestOne.SetData(TestVector1, -1.35, Vector3(-1.35,-1.35,-1.35));
	oAddScalarTestTwo.SetData(TestVector1, 1.35, Vector3(1.35,1.35,1.35));
	oAddScalarTestThree.SetData(TestVector2, -1.35, Vector3(0.85,7.25,2.95));
	oAddScalarTestFour.SetData(TestVector2, 1.35, Vector3(3.55,9.95,5.65));

	oAddScalarTests.AddUnitTest(&oAddScalarTestOne);
	oAddScalarTests.AddUnitTest(&oAddScalarTestTwo);
	oAddScalarTests.AddUnitTest(&oAddScalarTestThree);
	oAddScalarTests.AddUnitTest(&oAddScalarTestFour);
	oTester.AddUnitTestGroup(oAddScalarTests);

	bool AllTestsSucceed = oTester.DoTests();

	if(!AllTestsSucceed)
		return -1;	// Failed!

	return 0;	// All Tests Succeeded!
}