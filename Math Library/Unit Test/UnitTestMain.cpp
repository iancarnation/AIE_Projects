///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTestMain.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Unit Test Main
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UnitTestMainFunctions.h"

int main(int argc, char* argv[])
{
	// top-level test object
	UnitTester oTester;

	Vector3 TestVector1, 
			TestVector2(2.2,8.6,4.3), 
			TestVector3(1.1,3.3,5.5),
			TestVector4(-3.7,6.5,-8.8); // default constructor (values are zero) and argued constructors

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

	AddScalarTest oAddScalarTestOne, oAddScalarTestTwo, oAddScalarTestThree, oAddScalarTestFour;

	oAddScalarTestOne.SetData(TestVector1, -1.35, Vector3(-1.35,-1.35,-1.35));
	oAddScalarTestTwo.SetData(TestVector1, 1.35, Vector3(1.35,1.35,1.35));
	oAddScalarTestThree.SetData(TestVector2, -1.35, Vector3(0.85,7.25,2.95));
	oAddScalarTestFour.SetData(TestVector2, 1.35, Vector3(3.55,9.95,5.65));

	oAddScalarTests.AddUnitTest(&oAddScalarTestOne);
	oAddScalarTests.AddUnitTest(&oAddScalarTestTwo);
	oAddScalarTests.AddUnitTest(&oAddScalarTestThree);
	oAddScalarTests.AddUnitTest(&oAddScalarTestFour);
	oTester.AddUnitTestGroup(oAddScalarTests);

	// Multiply vector by scalar -------------------------------------------------------------
	UnitTestGroup oMultScalarTests;

	MultScalarTest oMultScalarTestOne, oMultScalarTestTwo, oMultScalarTestThree, oMultScalarTestFour;

	oMultScalarTestOne.SetData(TestVector1, -1.35, Vector3(0,0,0));
	oMultScalarTestTwo.SetData(TestVector1, 1.35, Vector3(0,0,0));
	oMultScalarTestThree.SetData(TestVector2, -1.35, Vector3(-2.97,-11.61,-5.805));
	oMultScalarTestFour.SetData(TestVector2, 1.35, Vector3(2.97,11.61,5.805));

	oMultScalarTests.AddUnitTest(&oMultScalarTestOne);
	oMultScalarTests.AddUnitTest(&oMultScalarTestTwo);
	oMultScalarTests.AddUnitTest(&oMultScalarTestThree);
	oMultScalarTests.AddUnitTest(&oMultScalarTestFour);
	oTester.AddUnitTestGroup(oMultScalarTests);

	// Divide vector by scalar -------------------------------------------------------------
	UnitTestGroup oDivScalarTests;

	DivScalarTest oDivScalarTestOne, oDivScalarTestTwo, oDivScalarTestThree, oDivScalarTestFour;

	oDivScalarTestOne.SetData(TestVector1, -1.35, Vector3(0,0,0));
	oDivScalarTestTwo.SetData(TestVector1, 1.35, Vector3(0,0,0));
	oDivScalarTestThree.SetData(TestVector2, -1.35, Vector3(-1.6296,-6.3704,-3.1852));
	oDivScalarTestFour.SetData(TestVector2, 1.35, Vector3(1.6296,6.3704,3.1852));

	oDivScalarTests.AddUnitTest(&oDivScalarTestOne);
	oDivScalarTests.AddUnitTest(&oDivScalarTestTwo);
	oDivScalarTests.AddUnitTest(&oDivScalarTestThree);
	oDivScalarTests.AddUnitTest(&oDivScalarTestFour);
	oTester.AddUnitTestGroup(oDivScalarTests);

	// set a vector equal to itself minus a scalar -------------------------------------------------------------
	UnitTestGroup oSubEqualScalarTests;

	SubEqualScalarTest oSubEqualScalarTestOne, oSubEqualScalarTestTwo, oSubEqualScalarTestThree, oSubEqualScalarTestFour;

	oSubEqualScalarTestOne.SetData(TestVector1, -1.35, Vector3(1.35,1.35,1.35));
	oSubEqualScalarTestTwo.SetData(TestVector1, 1.35, Vector3(-1.35,-1.35,-1.35));
	oSubEqualScalarTestThree.SetData(TestVector2, -1.35, Vector3(3.55,9.95,5.65));
	oSubEqualScalarTestFour.SetData(TestVector2, 1.35, Vector3(0.85,7.25,2.95));

	oSubEqualScalarTests.AddUnitTest(&oSubEqualScalarTestOne);
	oSubEqualScalarTests.AddUnitTest(&oSubEqualScalarTestTwo);
	oSubEqualScalarTests.AddUnitTest(&oSubEqualScalarTestThree);
	oSubEqualScalarTests.AddUnitTest(&oSubEqualScalarTestFour);
	oTester.AddUnitTestGroup(oSubEqualScalarTests);

	// sets a vector equal to itself plus a scalar -------------------------------------------------------------
	UnitTestGroup oAddEqualScalarTests;

	AddEqualScalarTest oAddEqualScalarTestOne, oAddEqualScalarTestTwo, oAddEqualScalarTestThree, oAddEqualScalarTestFour;

	oAddEqualScalarTestOne.SetData(TestVector1, -1.35, Vector3(-1.35,-1.35,-1.35));
	oAddEqualScalarTestTwo.SetData(TestVector1, 1.35, Vector3(1.35,1.35,1.35));
	oAddEqualScalarTestThree.SetData(TestVector2, -1.35, Vector3(0.85,7.25,2.95));
	oAddEqualScalarTestFour.SetData(TestVector2, 1.35, Vector3(3.55,9.95,5.65));

	oAddEqualScalarTests.AddUnitTest(&oAddEqualScalarTestOne);
	oAddEqualScalarTests.AddUnitTest(&oAddEqualScalarTestTwo);
	oAddEqualScalarTests.AddUnitTest(&oAddEqualScalarTestThree);
	oAddEqualScalarTests.AddUnitTest(&oAddEqualScalarTestFour);
	oTester.AddUnitTestGroup(oAddEqualScalarTests);

	// sets a vector equal to itself multiplied by a scalar -------------------------------------------------------------
	UnitTestGroup oMultEqualScalarTests;

	MultEqualScalarTest oMultEqualScalarTestOne, oMultEqualScalarTestTwo, oMultEqualScalarTestThree, oMultEqualScalarTestFour;

	oMultEqualScalarTestOne.SetData(TestVector1, -1.35, Vector3(0,0,0));
	oMultEqualScalarTestTwo.SetData(TestVector1, 1.35, Vector3(0,0,0));
	oMultEqualScalarTestThree.SetData(TestVector2, -1.35, Vector3(-2.97,-11.61,-5.805));
	oMultEqualScalarTestFour.SetData(TestVector2, 1.35, Vector3(2.97,11.61,5.805));

	oMultEqualScalarTests.AddUnitTest(&oMultEqualScalarTestOne);
	oMultEqualScalarTests.AddUnitTest(&oMultEqualScalarTestTwo);
	oMultEqualScalarTests.AddUnitTest(&oMultEqualScalarTestThree);
	oMultEqualScalarTests.AddUnitTest(&oMultEqualScalarTestFour);
	oTester.AddUnitTestGroup(oMultEqualScalarTests);

	// sets a vector equal to itself divided by a scalar -------------------------------------------------------------
	UnitTestGroup oDivEqualScalarTests;

	DivEqualScalarTest oDivEqualScalarTestOne, oDivEqualScalarTestTwo, oDivEqualScalarTestThree, oDivEqualScalarTestFour;

	oDivEqualScalarTestOne.SetData(TestVector1, -1.35, Vector3(0,0,0));
	oDivEqualScalarTestTwo.SetData(TestVector1, 1.35, Vector3(0,0,0));
	oDivEqualScalarTestThree.SetData(TestVector2, -1.35, Vector3(-1.6296,-6.3704,-3.1852));
	oDivEqualScalarTestFour.SetData(TestVector2, 1.35, Vector3(1.6296,6.3704,3.1852));

	oDivEqualScalarTests.AddUnitTest(&oDivEqualScalarTestOne);
	oDivEqualScalarTests.AddUnitTest(&oDivEqualScalarTestTwo);
	oDivEqualScalarTests.AddUnitTest(&oDivEqualScalarTestThree);
	oDivEqualScalarTests.AddUnitTest(&oDivEqualScalarTestFour);
	oTester.AddUnitTestGroup(oDivEqualScalarTests);

	// subtracts one vector from another, returns new vector -------------------------------------------------------------
	UnitTestGroup oVecSubTests;

	VecSubTest oVecSubTestOne, oVecSubTestTwo, oVecSubTestThree, oVecSubTestFour;

	oVecSubTestOne.SetData(TestVector1, TestVector2, Vector3(-2.2,-8.6,-4.3));
	oVecSubTestTwo.SetData(TestVector1, TestVector3, Vector3(-1.1,-3.3,-5.5));
	oVecSubTestThree.SetData(TestVector2, TestVector1, Vector3(2.2,8.6,4.3));
	oVecSubTestFour.SetData(TestVector2, TestVector3, Vector3(1.1,5.3,-1.2));

	oVecSubTests.AddUnitTest(&oVecSubTestOne);
	oVecSubTests.AddUnitTest(&oVecSubTestTwo);
	oVecSubTests.AddUnitTest(&oVecSubTestThree);
	oVecSubTests.AddUnitTest(&oVecSubTestFour);
	oTester.AddUnitTestGroup(oVecSubTests);

	// adds one vector to another, returns new vector -------------------------------------------------------------
	UnitTestGroup oVecAddTests;

	VecAddTest oVecAddTestOne, oVecAddTestTwo, oVecAddTestThree, oVecAddTestFour;

	oVecAddTestOne.SetData(TestVector1, TestVector2, Vector3(2.2,8.6,4.3));
	oVecAddTestTwo.SetData(TestVector1, TestVector3, Vector3(1.1,3.3,5.5));
	oVecAddTestThree.SetData(TestVector2, TestVector1, Vector3(2.2,8.6,4.3));
	oVecAddTestFour.SetData(TestVector2, TestVector3, Vector3(3.3,11.9,9.8));

	oVecAddTests.AddUnitTest(&oVecAddTestOne);
	oVecAddTests.AddUnitTest(&oVecAddTestTwo);
	oVecAddTests.AddUnitTest(&oVecAddTestThree);
	oVecAddTests.AddUnitTest(&oVecAddTestFour);
	oTester.AddUnitTestGroup(oVecAddTests);

	// sets one vector equal to another -------------------------------------------------------------
	UnitTestGroup oVecSetEqualTests;

	VecSetEqualTest oVecSetEqualTestOne, oVecSetEqualTestTwo, oVecSetEqualTestThree, oVecSetEqualTestFour;

	oVecSetEqualTestOne.SetData(TestVector1, TestVector2, Vector3(2.2,8.6,4.3));
	oVecSetEqualTestTwo.SetData(TestVector1, TestVector3, Vector3(1.1,3.3,5.5));
	oVecSetEqualTestThree.SetData(TestVector2, TestVector1, Vector3(0,0,0));
	oVecSetEqualTestFour.SetData(TestVector2, TestVector3, Vector3(1.1,3.3,5.5));

	oVecSetEqualTests.AddUnitTest(&oVecSetEqualTestOne);
	oVecSetEqualTests.AddUnitTest(&oVecSetEqualTestTwo);
	oVecSetEqualTests.AddUnitTest(&oVecSetEqualTestThree);
	oVecSetEqualTests.AddUnitTest(&oVecSetEqualTestFour);
	oTester.AddUnitTestGroup(oVecSetEqualTests);

	// sets a vector equal to itself minus another vector -------------------------------------------------------------
	UnitTestGroup oVecSubEqualTests;

	VecSubEqualTest oVecSubEqualTestOne, oVecSubEqualTestTwo, oVecSubEqualTestThree, oVecSubEqualTestFour;

	oVecSubEqualTestOne.SetData(TestVector1, TestVector2, Vector3(-2.2,-8.6,-4.3));
	oVecSubEqualTestTwo.SetData(TestVector1, TestVector3, Vector3(-1.1,-3.3,-5.5));
	oVecSubEqualTestThree.SetData(TestVector2, TestVector1, Vector3(2.2,8.6,4.3));
	oVecSubEqualTestFour.SetData(TestVector2, TestVector3, Vector3(1.1,5.3,-1.2));

	oVecSubEqualTests.AddUnitTest(&oVecSubEqualTestOne);
	oVecSubEqualTests.AddUnitTest(&oVecSubEqualTestTwo);
	oVecSubEqualTests.AddUnitTest(&oVecSubEqualTestThree);
	oVecSubEqualTests.AddUnitTest(&oVecSubEqualTestFour);
	oTester.AddUnitTestGroup(oVecSubEqualTests);

	// sets a vector equal to itself plus another vector -------------------------------------------------------------
	UnitTestGroup oVecAddEqualTests;

	VecAddEqualTest oVecAddEqualTestOne, oVecAddEqualTestTwo, oVecAddEqualTestThree, oVecAddEqualTestFour;

	oVecAddEqualTestOne.SetData(TestVector1, TestVector2, Vector3(2.2,8.6,4.3));
	oVecAddEqualTestTwo.SetData(TestVector1, TestVector3, Vector3(1.1,3.3,5.5));
	oVecAddEqualTestThree.SetData(TestVector2, TestVector1, Vector3(2.2,8.6,4.3));
	oVecAddEqualTestFour.SetData(TestVector2, TestVector3, Vector3(3.3,11.9,9.8));

	oVecAddEqualTests.AddUnitTest(&oVecAddEqualTestOne);
	oVecAddEqualTests.AddUnitTest(&oVecAddEqualTestTwo);
	oVecAddEqualTests.AddUnitTest(&oVecAddEqualTestThree);
	oVecAddEqualTests.AddUnitTest(&oVecAddEqualTestFour);
	oTester.AddUnitTestGroup(oVecAddEqualTests);

	// tests vector equality, returns bool -------------------------------------------------------------
	UnitTestGroup oVecEqualTests;

	VecEqualTest oVecEqualTestOne, oVecEqualTestTwo, oVecEqualTestThree, oVecEqualTestFour;

	oVecEqualTestOne.SetData(TestVector1, TestVector2, false);
	oVecEqualTestTwo.SetData(TestVector1, Vector3(0.0,0.0,0.0),true);
	oVecEqualTestThree.SetData(TestVector2, TestVector3, false);
	oVecEqualTestFour.SetData(TestVector2, Vector3(2.2,8.6,4.3),true);

	oVecEqualTests.AddUnitTest(&oVecEqualTestOne);
	oVecEqualTests.AddUnitTest(&oVecEqualTestTwo);
	oVecEqualTests.AddUnitTest(&oVecEqualTestThree);
	oVecEqualTests.AddUnitTest(&oVecEqualTestFour);
	oTester.AddUnitTestGroup(oVecEqualTests);

	//######################## Vector3 Function Tests ###############################################

	// returns magnitude of vector -------------------------------------------------------------
	UnitTestGroup oMagnitudeTests;

	MagnitudeTest oMagnitudeTestOne, oMagnitudeTestTwo, oMagnitudeTestThree, oMagnitudeTestFour;

	oMagnitudeTestOne.SetData(TestVector1, 0);
	oMagnitudeTestTwo.SetData(TestVector2, 9.86357);
	oMagnitudeTestThree.SetData(TestVector3, 6.50769);
	oMagnitudeTestFour.SetData(TestVector4, 11.549);

	oMagnitudeTests.AddUnitTest(&oMagnitudeTestOne);
	oMagnitudeTests.AddUnitTest(&oMagnitudeTestTwo);
	oMagnitudeTests.AddUnitTest(&oMagnitudeTestThree);
	oMagnitudeTests.AddUnitTest(&oMagnitudeTestFour);
	oTester.AddUnitTestGroup(oMagnitudeTests);

	// returns a normalized version of vector -------------------------------------------------------------
	UnitTestGroup oRetNormalizedTests;

	RetNormalizedTest oRetNormalizedTestOne, oRetNormalizedTestTwo, oRetNormalizedTestThree, oRetNormalizedTestFour;

	oRetNormalizedTestOne.SetData(Vector3(1,1,1), Vector3(0.5773,0.5773,0.5773));
	oRetNormalizedTestTwo.SetData(TestVector2, Vector3(0.2230,0.8719,0.4359));
	oRetNormalizedTestThree.SetData(TestVector3, Vector3(0.1690,0.5071,0.8452));
	oRetNormalizedTestFour.SetData(TestVector4, Vector3(-0.3204,0.5628,-0.762));

	oRetNormalizedTests.AddUnitTest(&oRetNormalizedTestOne);
	oRetNormalizedTests.AddUnitTest(&oRetNormalizedTestTwo);
	oRetNormalizedTests.AddUnitTest(&oRetNormalizedTestThree);
	oRetNormalizedTests.AddUnitTest(&oRetNormalizedTestFour);
	oTester.AddUnitTestGroup(oRetNormalizedTests);

	// gets distance between two points -------------------------------------------------------------
	UnitTestGroup oDistanceTests;

	DistanceTest oDistanceTestOne, oDistanceTestTwo, oDistanceTestThree, oDistanceTestFour;

	oDistanceTestOne.SetData(TestVector1, TestVector2, 9.8636);
	oDistanceTestTwo.SetData(TestVector1, TestVector3, 6.5077);
	oDistanceTestThree.SetData(TestVector2, TestVector3, 5.5444);
	oDistanceTestFour.SetData(TestVector2, TestVector4, 14.520);

	oDistanceTests.AddUnitTest(&oDistanceTestOne);
	oDistanceTests.AddUnitTest(&oDistanceTestTwo);
	oDistanceTests.AddUnitTest(&oDistanceTestThree);
	oDistanceTests.AddUnitTest(&oDistanceTestFour);
	oTester.AddUnitTestGroup(oDistanceTests);

	// dot product of 2 vectors -------------------------------------------------------------
	UnitTestGroup oDotTests;

	DotTest oDotTestOne, oDotTestTwo, oDotTestThree, oDotTestFour;

	oDotTestOne.SetData(TestVector1, TestVector2, 0);
	oDotTestTwo.SetData(TestVector1, TestVector3, 0);
	oDotTestThree.SetData(TestVector2, TestVector3, 54.45);
	oDotTestFour.SetData(TestVector2, TestVector4, 9.92);

	oDotTests.AddUnitTest(&oDotTestOne);
	oDotTests.AddUnitTest(&oDotTestTwo);
	oDotTests.AddUnitTest(&oDotTestThree);
	oDotTests.AddUnitTest(&oDotTestFour);
	oTester.AddUnitTestGroup(oDotTests);

	// cross product of 2 vectors -------------------------------------------------------------
	UnitTestGroup oCrossTests;

	CrossTest oCrossTestOne, oCrossTestTwo, oCrossTestThree, oCrossTestFour;

	oCrossTestOne.SetData(TestVector1, TestVector2, Vector3(0,0,0));
	oCrossTestTwo.SetData(TestVector1, TestVector3, Vector3(0,0,0));
	oCrossTestThree.SetData(TestVector2, TestVector3, Vector3(33.11,-7.37,-2.2));
	oCrossTestFour.SetData(TestVector2, TestVector4, Vector3(-103.63, 3.45, 46.12));

	oCrossTests.AddUnitTest(&oCrossTestOne);
	oCrossTests.AddUnitTest(&oCrossTestTwo);
	oCrossTests.AddUnitTest(&oCrossTestThree);
	oCrossTests.AddUnitTest(&oCrossTestFour);
	oTester.AddUnitTestGroup(oCrossTests);

	// calculates angle between two vectors -------------------------------------------------------------
	UnitTestGroup oGetAngleTests;

	GetAngleTest oGetAngleTestOne, oGetAngleTestTwo, oGetAngleTestThree, oGetAngleTestFour;

	oGetAngleTestOne.SetData(Vector3(1,1,1), TestVector2, 0.4870);
	oGetAngleTestTwo.SetData(Vector3(1,1,1), TestVector3, 0.4987);
	oGetAngleTestThree.SetData(TestVector2, TestVector3, 0.5580);
	oGetAngleTestFour.SetData(TestVector2, TestVector4, 1.4836);

	oGetAngleTests.AddUnitTest(&oGetAngleTestOne);
	oGetAngleTests.AddUnitTest(&oGetAngleTestTwo);
	oGetAngleTests.AddUnitTest(&oGetAngleTestThree);
	oGetAngleTests.AddUnitTest(&oGetAngleTestFour);
	oTester.AddUnitTestGroup(oGetAngleTests);

	// linearly interpolates between two vectors for parameter t in range 0 to 1 -------------------------------------------------------------
	UnitTestGroup oLerpTests;

	LerpTest oLerpTestOne, oLerpTestTwo, oLerpTestThree, oLerpTestFour;

	oLerpTestOne.SetData(TestVector1, TestVector2, 2, Vector3(4.4,17.2,8.6));
	oLerpTestTwo.SetData(TestVector1, TestVector3, 2,  Vector3(2.2,6.6,11));
	oLerpTestThree.SetData(TestVector2, TestVector3, 2,  Vector3(0,-2,6.7));
	oLerpTestFour.SetData(TestVector2, TestVector4, 2,  Vector3(-9.6,4.4,-21.9));

	oLerpTests.AddUnitTest(&oLerpTestOne);
	oLerpTests.AddUnitTest(&oLerpTestTwo);
	oLerpTests.AddUnitTest(&oLerpTestThree);
	oLerpTests.AddUnitTest(&oLerpTestFour);
	oTester.AddUnitTestGroup(oLerpTests);


	
	bool AllTestsSucceed = oTester.DoTests();
	char satisfaction;

	if(!AllTestsSucceed)
	{
		cout<< "\nFailed :(\n";
		cout<< "\nSatisfied?\n";
		cin>> satisfaction;
		return -1;	// Failed!
	}

	cout<< "\nAll Tests Succeeded Success!!!!!\n";
	cout<< "\nSatisfied?\n";
	cin>> satisfaction;
	return 0;	// All Tests Succeeded!
}