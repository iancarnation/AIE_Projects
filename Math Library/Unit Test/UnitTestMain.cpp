///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTestMain.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Unit Test Main
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UnitTest.h"
#include "Vector3FuncUTests.h"
#include "Vector3OperatorUTests.h"
#include "Vector4UTests.h"
#include "Matrix3UTests.h"
#include "Matrix4UTests.h"


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

	// normalize a vector -------------------------------------------------------------
	UnitTestGroup oNormalizeTests;

	NormalizeTest oNormalizeTestOne, oNormalizeTestTwo, oNormalizeTestThree, oNormalizeTestFour;

	oNormalizeTestOne.SetData(Vector3(1,1,1), Vector3(0.5773,0.5773,0.5773));
	oNormalizeTestTwo.SetData(TestVector2, Vector3(0.2230,0.8719,0.4359));
	oNormalizeTestThree.SetData(TestVector3, Vector3(0.1690,0.5071,0.8452));
	oNormalizeTestFour.SetData(TestVector4, Vector3(-0.3204,0.5628,-0.762));

	oNormalizeTests.AddUnitTest(&oNormalizeTestOne);
	oNormalizeTests.AddUnitTest(&oNormalizeTestTwo);
	oNormalizeTests.AddUnitTest(&oNormalizeTestThree);
	oNormalizeTests.AddUnitTest(&oNormalizeTestFour);
	oTester.AddUnitTestGroup(oNormalizeTests);

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

	//######################## Vector4 Tests ###############################################

	Vector4 TestVector4A, 
			TestVector4B(2.2,8.6,4.3,1), 
			TestVector4C(1.1,3.3,5.5,1),
			TestVector4D(-3.7,6.5,-8.8,1); // default constructor (values are zero) and argued constructors

	// tests vector equality, returns bool -------------------------------------------------------------
	UnitTestGroup oV4EqualTests;

	V4EqualTest oV4EqualTestOne, oV4EqualTestTwo, oV4EqualTestThree, oV4EqualTestFour;

	oV4EqualTestOne.SetData(TestVector4A, TestVector4B, false);
	oV4EqualTestTwo.SetData(TestVector4A, Vector4(0,0,0,0),true);
	oV4EqualTestThree.SetData(TestVector4B, TestVector4C, false);
	oV4EqualTestFour.SetData(TestVector4B, Vector4(2.2,8.6,4.3,1),true);

	oV4EqualTests.AddUnitTest(&oV4EqualTestOne);
	oV4EqualTests.AddUnitTest(&oV4EqualTestTwo);
	oV4EqualTests.AddUnitTest(&oV4EqualTestThree);
	oV4EqualTests.AddUnitTest(&oV4EqualTestFour);
	oTester.AddUnitTestGroup(oV4EqualTests);

	// normalize a vector -------------------------------------------------------------
	UnitTestGroup oV4NormalizeTests;

	V4NormalizeTest oV4NormalizeTestOne, oV4NormalizeTestTwo, oV4NormalizeTestThree, oV4NormalizeTestFour;

	oV4NormalizeTestOne.SetData(Vector4(1,1,1,1), Vector4(0.5,0.5,0.5,0.5));
	oV4NormalizeTestTwo.SetData(TestVector4B, Vector4(0.2219, 0.8674, 0.4337, 0.1009));
	oV4NormalizeTestThree.SetData(TestVector4C, Vector4(0.1670, 0.5012, 0.8353, 0.1519));
	oV4NormalizeTestFour.SetData(TestVector4D, Vector4(-0.3192, 0.5607, -0.7591, 0.08626));

	oV4NormalizeTests.AddUnitTest(&oV4NormalizeTestOne);
	oV4NormalizeTests.AddUnitTest(&oV4NormalizeTestTwo);
	oV4NormalizeTests.AddUnitTest(&oV4NormalizeTestThree);
	oV4NormalizeTests.AddUnitTest(&oV4NormalizeTestFour);
	oTester.AddUnitTestGroup(oV4NormalizeTests);

	// normalize a vector -------------------------------------------------------------
	UnitTestGroup oV4RetNormalizedTests;

	V4RetNormalizedTest oV4RetNormalizedTestOne, oV4RetNormalizedTestTwo, oV4RetNormalizedTestThree, oV4RetNormalizedTestFour;

	oV4RetNormalizedTestOne.SetData(Vector4(1,1,1,1), Vector4(0.5,0.5,0.5,0.5));
	oV4RetNormalizedTestTwo.SetData(TestVector4B, Vector4(0.2219, 0.8674, 0.4337, 0.1009));
	oV4RetNormalizedTestThree.SetData(TestVector4C, Vector4(0.1670, 0.5012, 0.8353, 0.1519));
	oV4RetNormalizedTestFour.SetData(TestVector4D, Vector4(-0.3192, 0.5607, -0.7591, 0.08626));

	oV4RetNormalizedTests.AddUnitTest(&oV4RetNormalizedTestOne);
	oV4RetNormalizedTests.AddUnitTest(&oV4RetNormalizedTestTwo);
	oV4RetNormalizedTests.AddUnitTest(&oV4RetNormalizedTestThree);
	oV4RetNormalizedTests.AddUnitTest(&oV4RetNormalizedTestFour);
	oTester.AddUnitTestGroup(oV4RetNormalizedTests);

	//// converts hex code to rgb floats and returns vector4 with alpha as well -------------------------------------------------------------
	//UnitTestGroup oV4HexToRGBTests;

	//V4HexToRGBTest oV4HexToRGBTestOne, oV4HexToRGBTestTwo, oV4HexToRGBTestThree, oV4HexToRGBTestFour;

	//oV4HexToRGBTestOne.SetData("0xFFFFFF", 1, Vector4(1,1,1,1));
	//oV4HexToRGBTestTwo.SetData("0x3333CC", 0.5, Vector4(0.2,0.2,0.8,0.5));
	//oV4HexToRGBTestThree.SetData("0x7FFFD4", 0.3, Vector4(0.4980,1.0,0.8314,0.3));
	//oV4HexToRGBTestFour.SetData("0x006400", 0.643, Vector4(0,0.3922,0,0.643));

	//oV4HexToRGBTests.AddUnitTest(&oV4HexToRGBTestOne);
	//oV4HexToRGBTests.AddUnitTest(&oV4HexToRGBTestTwo);
	//oV4HexToRGBTests.AddUnitTest(&oV4HexToRGBTestThree);
	//oV4HexToRGBTests.AddUnitTest(&oV4HexToRGBTestFour);
	//oTester.AddUnitTestGroup(oV4HexToRGBTests);

	//######################## Matrix3 Operator Tests ###############################################

	Matrix3 TestMatrix3A(1,1,0,2,3,2,0,0,1), 
			TestMatrix3B(2,2,0,1,1,1,0,0,1),
			TestMatrix3C(-2,3,1,0,-1,2,0,0,2),
			TestMatrix3D(0,3,5,-2,1,6,0,0,1);

	Vector3 M3TestVectorA(3,6,1),
			M3TestVectorB(1,3,0),
			M3TestVectorC(2,0,2),
			M3TestVectorD(0,6,1), 
			M3TestVectorT(4,2,2);


	// multiplies two matrices -------------------------------------------------------------
	UnitTestGroup oM3MultTests;

	M3MultTest oM3MultTestOne, oM3MultTestTwo, oM3MultTestThree, oM3MultTestFour;

	oM3MultTestOne.SetData(TestMatrix3A, TestMatrix3B, Matrix3(3,3,1,7,7,5,0,0,1));
	oM3MultTestTwo.SetData(TestMatrix3A, TestMatrix3C, Matrix3(-2,2,3,-4,3,12,0,0,2));
	oM3MultTestThree.SetData(TestMatrix3B, TestMatrix3C, Matrix3(-4,4,6,-2,2,5,0,0,2));
	oM3MultTestFour.SetData(TestMatrix3B, TestMatrix3D, Matrix3(-4,8,22,-2,4,12,0,0,1));

	oM3MultTests.AddUnitTest(&oM3MultTestOne);
	oM3MultTests.AddUnitTest(&oM3MultTestTwo);
	oM3MultTests.AddUnitTest(&oM3MultTestThree);
	oM3MultTests.AddUnitTest(&oM3MultTestFour);
	oTester.AddUnitTestGroup(oM3MultTests);

	// matrix * vector = vector -------------------------------------------------------------
	UnitTestGroup oM3MultVectorTests;

	M3MultVectorTest oM3MultVectorTestOne, oM3MultVectorTestTwo, oM3MultVectorTestThree, oM3MultVectorTestFour;

	oM3MultVectorTestOne.SetData(TestMatrix3A, M3TestVectorA, Vector3(9,26,1));
	oM3MultVectorTestTwo.SetData(TestMatrix3B, M3TestVectorA, Vector3(18,10,1));
	oM3MultVectorTestThree.SetData(TestMatrix3C, M3TestVectorA, Vector3(13,-4,2));
	oM3MultVectorTestFour.SetData(TestMatrix3D, M3TestVectorA, Vector3(23,6,1));

	oM3MultVectorTests.AddUnitTest(&oM3MultVectorTestOne);
	oM3MultVectorTests.AddUnitTest(&oM3MultVectorTestTwo);
	oM3MultVectorTests.AddUnitTest(&oM3MultVectorTestThree);
	oM3MultVectorTests.AddUnitTest(&oM3MultVectorTestFour);
	oTester.AddUnitTestGroup(oM3MultVectorTests);

	// multiplies matrix by scalar -------------------------------------------------------------
	UnitTestGroup oM3MultScalarTests;

	M3MultScalarTest oM3MultScalarTestOne, oM3MultScalarTestTwo, oM3MultScalarTestThree, oM3MultScalarTestFour;

	oM3MultScalarTestOne.SetData(TestMatrix3A, 3, Matrix3(3,3,0,6,9,6,0,0,3));
	oM3MultScalarTestTwo.SetData(TestMatrix3B, 3, Matrix3(6,6,0,3,3,3,0,0,3));
	oM3MultScalarTestThree.SetData(TestMatrix3C, 3, Matrix3(-6,9,3,0,-3,6,0,0,6));
	oM3MultScalarTestFour.SetData(TestMatrix3D, 3, Matrix3(0,9,15,-6,3,18,0,0,3));

	oM3MultScalarTests.AddUnitTest(&oM3MultScalarTestOne);
	oM3MultScalarTests.AddUnitTest(&oM3MultScalarTestTwo);
	oM3MultScalarTests.AddUnitTest(&oM3MultScalarTestThree);
	oM3MultScalarTests.AddUnitTest(&oM3MultScalarTestFour);
	oTester.AddUnitTestGroup(oM3MultScalarTests);

	// tests matrix equality -------------------------------------------------------------
	UnitTestGroup oM3EqualTests;

	M3EqualTest oM3EqualTestOne, oM3EqualTestTwo, oM3EqualTestThree, oM3EqualTestFour;

	oM3EqualTestOne.SetData(TestMatrix3A, TestMatrix3B, false);
	oM3EqualTestTwo.SetData(TestMatrix3A, Matrix3(1,1,0,2,3,2,0,0,1), true);
	oM3EqualTestThree.SetData(TestMatrix3B, TestMatrix3C, false);
	oM3EqualTestFour.SetData(TestMatrix3B, Matrix3(2,2,0,1,1,1,0,0,1), true);

	oM3EqualTests.AddUnitTest(&oM3EqualTestOne);
	oM3EqualTests.AddUnitTest(&oM3EqualTestTwo);
	oM3EqualTests.AddUnitTest(&oM3EqualTestThree);
	oM3EqualTests.AddUnitTest(&oM3EqualTestFour);
	oTester.AddUnitTestGroup(oM3EqualTests);

	//######################## Matrix3 Function Tests ###############################################

	// returns the translation of the matrix as a vector -------------------------------------------------------------
	UnitTestGroup oM3GetTranslationsTests;

	M3GetTranslationsTest oM3GetTranslationsTestOne, oM3GetTranslationsTestTwo, oM3GetTranslationsTestThree, oM3GetTranslationsTestFour;

	oM3GetTranslationsTestOne.SetData(TestMatrix3A, Vector3(0,2,1));
	oM3GetTranslationsTestTwo.SetData(TestMatrix3B, Vector3(0,1,1));
	oM3GetTranslationsTestThree.SetData(TestMatrix3C, Vector3(1,2,2));
	oM3GetTranslationsTestFour.SetData(TestMatrix3D, Vector3(5,6,1));

	oM3GetTranslationsTests.AddUnitTest(&oM3GetTranslationsTestOne);
	oM3GetTranslationsTests.AddUnitTest(&oM3GetTranslationsTestTwo);
	oM3GetTranslationsTests.AddUnitTest(&oM3GetTranslationsTestThree);
	oM3GetTranslationsTests.AddUnitTest(&oM3GetTranslationsTestFour);
	oTester.AddUnitTestGroup(oM3GetTranslationsTests);

	// returns rotation of the matrix -------------------------------------------------------------
	UnitTestGroup oM3GetRotationTests;

	M3GetRotationTest oM3GetRotationTestOne, oM3GetRotationTestTwo, oM3GetRotationTestThree, oM3GetRotationTestFour;

	oM3GetRotationTestOne.SetData(TestMatrix3A, -0.7854);
	oM3GetRotationTestTwo.SetData(TestMatrix3B, -0.7854);
	oM3GetRotationTestThree.SetData(TestMatrix3C, 0.9828);
	oM3GetRotationTestFour.SetData(Matrix3(1,3,5,-2,1,6,0,0,1), -1.2490);

	oM3GetRotationTests.AddUnitTest(&oM3GetRotationTestOne);
	oM3GetRotationTests.AddUnitTest(&oM3GetRotationTestTwo);
	oM3GetRotationTests.AddUnitTest(&oM3GetRotationTestThree);
	oM3GetRotationTests.AddUnitTest(&oM3GetRotationTestFour);
	oTester.AddUnitTestGroup(oM3GetRotationTests);

	// sets translation of the matrix (replaces curr. translation) -------------------------------------------------------------
	UnitTestGroup oM3SetTranslationTests;

	M3SetTranslationTest oM3SetTranslationTestOne, oM3SetTranslationTestTwo, oM3SetTranslationTestThree, oM3SetTranslationTestFour;

	oM3SetTranslationTestOne.SetData(TestMatrix3A, M3TestVectorA, Matrix3(1,1,9,2,3,26,0,0,1));
	oM3SetTranslationTestTwo.SetData(TestMatrix3B, M3TestVectorA, Matrix3(2,2,18,1,1,10,0,0,1));
	oM3SetTranslationTestThree.SetData(TestMatrix3C, M3TestVectorA, Matrix3(-2,3,13,0,-1,-4,0,0,2));
	oM3SetTranslationTestFour.SetData(TestMatrix3D, M3TestVectorA, Matrix3(0,3,23,-2,1,6,0,0,1));

	oM3SetTranslationTests.AddUnitTest(&oM3SetTranslationTestOne);
	oM3SetTranslationTests.AddUnitTest(&oM3SetTranslationTestTwo);
	oM3SetTranslationTests.AddUnitTest(&oM3SetTranslationTestThree);
	oM3SetTranslationTests.AddUnitTest(&oM3SetTranslationTestFour);
	oTester.AddUnitTestGroup(oM3SetTranslationTests);

	// sets rotation of the matrix (replaces curr. rotation) -------------------------------------------------------------
	UnitTestGroup oM3SetRotationTests;

	M3SetRotationTest oM3SetRotationTestOne, oM3SetRotationTestTwo, oM3SetRotationTestThree, oM3SetRotationTestFour;

	oM3SetRotationTestOne.SetData(TestMatrix3A, PI/2, Matrix3(1,-1,0,3,-2,2,0,0,1));
	oM3SetRotationTestTwo.SetData(TestMatrix3B, PI/2, Matrix3(2,-2,0,1,-1,1,0,0,1));
	oM3SetRotationTestThree.SetData(TestMatrix3C, PI/2, Matrix3(3,2,1,-1,0,2,0,0,2));
	oM3SetRotationTestFour.SetData(TestMatrix3D, PI/2, Matrix3(3,0,5,1,2,6,0,0,1));

	oM3SetRotationTests.AddUnitTest(&oM3SetRotationTestOne);
	oM3SetRotationTests.AddUnitTest(&oM3SetRotationTestTwo);
	oM3SetRotationTests.AddUnitTest(&oM3SetRotationTestThree);
	oM3SetRotationTests.AddUnitTest(&oM3SetRotationTestFour);
	oTester.AddUnitTestGroup(oM3SetRotationTests);

	// sets scale of the matrix (replaces curr. matrix) -------------------------------------------------------------
	UnitTestGroup oM3SetScaleTests;

	M3SetScaleTest oM3SetScaleTestOne, oM3SetScaleTestTwo, oM3SetScaleTestThree, oM3SetScaleTestFour;

	oM3SetScaleTestOne.SetData(TestMatrix3A, 2, Matrix3(2,2,0,4,6,2,0,0,1));
	oM3SetScaleTestTwo.SetData(TestMatrix3B, 2, Matrix3(4,4,0,2,2,1,0,0,1));
	oM3SetScaleTestThree.SetData(TestMatrix3C, 2, Matrix3(-4,6,1,0,-2,2,0,0,2));
	oM3SetScaleTestFour.SetData(TestMatrix3D, 2, Matrix3(0,6,5,-4,2,6,0,0,1));

	oM3SetScaleTests.AddUnitTest(&oM3SetScaleTestOne);
	oM3SetScaleTests.AddUnitTest(&oM3SetScaleTestTwo);
	oM3SetScaleTests.AddUnitTest(&oM3SetScaleTestThree);
	oM3SetScaleTests.AddUnitTest(&oM3SetScaleTestFour);
	oTester.AddUnitTestGroup(oM3SetScaleTests);

	// rotate and scales a directional vector -------------------------------------------------------------
	UnitTestGroup oM3TransformVectorTests;

	M3TransformVectorTest oM3TransformVectorTestOne, oM3TransformVectorTestTwo, oM3TransformVectorTestThree, oM3TransformVectorTestFour;

	oM3TransformVectorTestOne.SetData(M3TestVectorA, PI/2, 4, Vector3(-24,12,1));
	oM3TransformVectorTestTwo.SetData(M3TestVectorB, PI/2, 4, Vector3(-12,4,0));
	oM3TransformVectorTestThree.SetData(M3TestVectorC, PI/2, 4, Vector3(0,8,2));
	oM3TransformVectorTestFour.SetData(M3TestVectorD, PI/2, 4, Vector3(-24,0,1));

	oM3TransformVectorTests.AddUnitTest(&oM3TransformVectorTestOne);
	oM3TransformVectorTests.AddUnitTest(&oM3TransformVectorTestTwo);
	oM3TransformVectorTests.AddUnitTest(&oM3TransformVectorTestThree);
	oM3TransformVectorTests.AddUnitTest(&oM3TransformVectorTestFour);
	oTester.AddUnitTestGroup(oM3TransformVectorTests);


	// rotate, scale and translate a point -------------------------------------------------------------
	UnitTestGroup oM3Transform2DPointTests;

	M3Transform2DPointTest oM3Transform2DPointTestOne, oM3Transform2DPointTestTwo, oM3Transform2DPointTestThree, oM3Transform2DPointTestFour;

	oM3Transform2DPointTestOne.SetData(M3TestVectorA, PI/2, 4, M3TestVectorT, Vector3(-16,14,1));
	oM3Transform2DPointTestTwo.SetData(M3TestVectorB, PI/2, 4, M3TestVectorT,  Vector3(-12,4,0));
	oM3Transform2DPointTestThree.SetData(M3TestVectorC, PI/2, 4, M3TestVectorT,  Vector3(-4,10,1));
	oM3Transform2DPointTestFour.SetData(M3TestVectorD, PI/2, 4, M3TestVectorT,  Vector3(-16,8,1));

	oM3Transform2DPointTests.AddUnitTest(&oM3Transform2DPointTestOne);
	oM3Transform2DPointTests.AddUnitTest(&oM3Transform2DPointTestTwo);
	oM3Transform2DPointTests.AddUnitTest(&oM3Transform2DPointTestThree);
	oM3Transform2DPointTests.AddUnitTest(&oM3Transform2DPointTestFour);
	oTester.AddUnitTestGroup(oM3Transform2DPointTests);

	// creates an identity matrix -------------------------------------------------------------
	UnitTestGroup oM3CreateIdentityTests;

	M3CreateIdentityTest oM3CreateIdentityTestOne, oM3CreateIdentityTestTwo, oM3CreateIdentityTestThree, oM3CreateIdentityTestFour;

	oM3CreateIdentityTestOne.SetData(TestMatrix3A, Matrix3(1,0,0,0,1,0,0,0,1));
	oM3CreateIdentityTestTwo.SetData(TestMatrix3B, Matrix3(1,0,0,0,1,0,0,0,1));
	oM3CreateIdentityTestThree.SetData(TestMatrix3C, Matrix3(1,0,0,0,1,0,0,0,1));
	oM3CreateIdentityTestFour.SetData(TestMatrix3D, Matrix3(1,0,0,0,1,0,0,0,1));

	oM3CreateIdentityTests.AddUnitTest(&oM3CreateIdentityTestOne);
	oM3CreateIdentityTests.AddUnitTest(&oM3CreateIdentityTestTwo);
	oM3CreateIdentityTests.AddUnitTest(&oM3CreateIdentityTestThree);
	oM3CreateIdentityTests.AddUnitTest(&oM3CreateIdentityTestFour);
	oTester.AddUnitTestGroup(oM3CreateIdentityTests);

	// creates new rotation matrix with 0,0 translation -------------------------------------------------------------
	UnitTestGroup oM3CreateRotationTests;

	M3CreateRotationTest oM3CreateRotationTestOne, oM3CreateRotationTestTwo, oM3CreateRotationTestThree, oM3CreateRotationTestFour;

	oM3CreateRotationTestOne.SetData(TestMatrix3A, PI/2, Matrix3(0,-1,0,1,0,0,0,0,1));
	oM3CreateRotationTestTwo.SetData(TestMatrix3B, PI/2, Matrix3(0,-1,0,1,0,0,0,0,1));
	oM3CreateRotationTestThree.SetData(TestMatrix3C, PI/2, Matrix3(0,-1,0,1,0,0,0,0,1));
	oM3CreateRotationTestFour.SetData(TestMatrix3D, PI/2, Matrix3(0,-1,0,1,0,0,0,0,1));

	oM3CreateRotationTests.AddUnitTest(&oM3CreateRotationTestOne);
	oM3CreateRotationTests.AddUnitTest(&oM3CreateRotationTestTwo);
	oM3CreateRotationTests.AddUnitTest(&oM3CreateRotationTestThree);
	oM3CreateRotationTests.AddUnitTest(&oM3CreateRotationTestFour);
	oTester.AddUnitTestGroup(oM3CreateRotationTests);

	// creates new scale matrix -------------------------------------------------------------
	UnitTestGroup oM3CreateScaleTests;

	M3CreateScaleTest oM3CreateScaleTestOne, oM3CreateScaleTestTwo, oM3CreateScaleTestThree, oM3CreateScaleTestFour;

	oM3CreateScaleTestOne.SetData(TestMatrix3A, 2, Matrix3(2,0,0,0,2,0,0,0,1));
	oM3CreateScaleTestTwo.SetData(TestMatrix3B, 3, Matrix3(3,0,0,0,3,0,0,0,1));
	oM3CreateScaleTestThree.SetData(TestMatrix3C, 4, Matrix3(4,0,0,0,4,0,0,0,1));
	oM3CreateScaleTestFour.SetData(TestMatrix3D, -2, Matrix3(-2,0,0,0,-2,0,0,0,1));

	oM3CreateScaleTests.AddUnitTest(&oM3CreateScaleTestOne);
	oM3CreateScaleTests.AddUnitTest(&oM3CreateScaleTestTwo);
	oM3CreateScaleTests.AddUnitTest(&oM3CreateScaleTestThree);
	oM3CreateScaleTests.AddUnitTest(&oM3CreateScaleTestFour);
	oTester.AddUnitTestGroup(oM3CreateScaleTests);

	// creates new translation matrix with 0 rotation -------------------------------------------------------------
	UnitTestGroup oM3CreateTranslationTests;

	M3CreateTranslationTest oM3CreateTranslationTestOne, oM3CreateTranslationTestTwo, oM3CreateTranslationTestThree, oM3CreateTranslationTestFour;

	oM3CreateTranslationTestOne.SetData(TestMatrix3A, M3TestVectorA, Matrix3(1,0,3,0,1,6,0,0,1));
	oM3CreateTranslationTestTwo.SetData(TestMatrix3B, M3TestVectorB, Matrix3(1,0,1,0,1,3,0,0,0));
	oM3CreateTranslationTestThree.SetData(TestMatrix3C, M3TestVectorC, Matrix3(1,0,2,0,1,0,0,0,2));
	oM3CreateTranslationTestFour.SetData(TestMatrix3D, M3TestVectorD, Matrix3(1,0,0,0,1,6,0,0,1));

	oM3CreateTranslationTests.AddUnitTest(&oM3CreateTranslationTestOne);
	oM3CreateTranslationTests.AddUnitTest(&oM3CreateTranslationTestTwo);
	oM3CreateTranslationTests.AddUnitTest(&oM3CreateTranslationTestThree);
	oM3CreateTranslationTests.AddUnitTest(&oM3CreateTranslationTestFour);
	oTester.AddUnitTestGroup(oM3CreateTranslationTests);

	// creates orthographic projection matrix for given cardinal axis -------------------------------------------------------------
	UnitTestGroup oM3CreateCardinalOrthoTests;

	M3CreateCardinalOrthoTest oM3CreateCardinalOrthoTestOne, oM3CreateCardinalOrthoTestTwo, oM3CreateCardinalOrthoTestThree, oM3CreateCardinalOrthoTestFour;

	oM3CreateCardinalOrthoTestOne.SetData(TestMatrix3A, 'x', Matrix3(1,0,0,0,0,0,0,0,1));
	oM3CreateCardinalOrthoTestTwo.SetData(TestMatrix3B, 'y', Matrix3(0,0,0,0,1,0,0,0,1));
	oM3CreateCardinalOrthoTestThree.SetData(TestMatrix3C, 'x', Matrix3(1,0,0,0,0,0,0,0,1));
	oM3CreateCardinalOrthoTestFour.SetData(TestMatrix3D, 'y', Matrix3(0,0,0,0,1,0,0,0,1));

	oM3CreateCardinalOrthoTests.AddUnitTest(&oM3CreateCardinalOrthoTestOne);
	oM3CreateCardinalOrthoTests.AddUnitTest(&oM3CreateCardinalOrthoTestTwo);
	oM3CreateCardinalOrthoTests.AddUnitTest(&oM3CreateCardinalOrthoTestThree);
	oM3CreateCardinalOrthoTests.AddUnitTest(&oM3CreateCardinalOrthoTestFour);
	oTester.AddUnitTestGroup(oM3CreateCardinalOrthoTests);


	//######################## Matrix4 Operator Tests ###############################################

	Matrix4 TestMatrix4A(1,1,0,1,2,3,2,0,4,0,1,2,0,0,0,1), 
			TestMatrix4B(2,2,0,1,1,1,1,1,0,3,0,2,0,0,0,1),
			TestMatrix4C(-2,3,1,2,0,-1,2,3,1,-2,1,2,0,0,0,2),
			TestMatrix4D(0,3,5,4,-2,1,6,1,-3,2,-1,0,0,0,0,2);

	Vector4 M4TestVectorA(3,6,1,1),
			M4TestVectorB(1,3,0,0),
			M4TestVectorC(2,0,2,2),
			M4TestVectorD(0,6,1,1), 
			M4TestVectorT(4,2,2,2);


	// multiplies two matrices -------------------------------------------------------------
	UnitTestGroup oM4MultTests;

	M4MultTest oM4MultTestOne, oM4MultTestTwo, oM4MultTestThree, oM4MultTestFour;

	oM4MultTestOne.SetData(TestMatrix4A, TestMatrix4B, Matrix4(3,3,1,3,7,13,3,9,8,11,0,8,0,0,0,1));
	oM4MultTestTwo.SetData(TestMatrix4A, TestMatrix4C, Matrix4(-2,2,3,7,-2,-1,10,17,-7,10,5,14,0,0,0,2));
	oM4MultTestThree.SetData(TestMatrix4B, TestMatrix4C, Matrix4(-4,4,6,12,-1,0,4,9,0,-3,6,13,0,0,0,2));
	oM4MultTestFour.SetData(TestMatrix4B, TestMatrix4D, Matrix4(-4,8,22,12,-5,6,10,7,-6,3,18,7,0,0,0,2));

	oM4MultTests.AddUnitTest(&oM4MultTestOne);
	oM4MultTests.AddUnitTest(&oM4MultTestTwo);
	oM4MultTests.AddUnitTest(&oM4MultTestThree);
	oM4MultTests.AddUnitTest(&oM4MultTestFour);
	oTester.AddUnitTestGroup(oM4MultTests);

	// matrix * vector = vector -------------------------------------------------------------
	UnitTestGroup oM4MultVectorTests;

	M4MultVectorTest oM4MultVectorTestOne, oM4MultVectorTestTwo, oM4MultVectorTestThree, oM4MultVectorTestFour;

	oM4MultVectorTestOne.SetData(TestMatrix4A, M4TestVectorA, Vector4(10,26,15,1));
	oM4MultVectorTestTwo.SetData(TestMatrix4B, M4TestVectorA, Vector4(19,11,20,1));
	oM4MultVectorTestThree.SetData(TestMatrix4C, M4TestVectorA, Vector4(15,-1,-6,2));
	oM4MultVectorTestFour.SetData(TestMatrix4D, M4TestVectorA, Vector4(27,7,2,2));

	oM4MultVectorTests.AddUnitTest(&oM4MultVectorTestOne);
	oM4MultVectorTests.AddUnitTest(&oM4MultVectorTestTwo);
	oM4MultVectorTests.AddUnitTest(&oM4MultVectorTestThree);
	oM4MultVectorTests.AddUnitTest(&oM4MultVectorTestFour);
	oTester.AddUnitTestGroup(oM4MultVectorTests);

	// multiplies matrix by scalar -------------------------------------------------------------
	UnitTestGroup oM4MultScalarTests;

	M4MultScalarTest oM4MultScalarTestOne, oM4MultScalarTestTwo, oM4MultScalarTestThree, oM4MultScalarTestFour;

	oM4MultScalarTestOne.SetData(TestMatrix4A, 3, Matrix4(3,3,0,3,6,9,6,0,12,0,3,6,0,0,0,3));
	oM4MultScalarTestTwo.SetData(TestMatrix4B, 3, Matrix4(6,6,0,3,3,3,3,3,0,9,0,6,0,0,0,3));
	oM4MultScalarTestThree.SetData(TestMatrix4C, 3, Matrix4(-6,9,3,6,0,-3,6,9,3,-6,3,6,0,0,0,6));
	oM4MultScalarTestFour.SetData(TestMatrix4D, 3, Matrix4(0,9,15,12,-6,3,18,3,-9,6,-3,0,0,0,0,6));

	oM4MultScalarTests.AddUnitTest(&oM4MultScalarTestOne);
	oM4MultScalarTests.AddUnitTest(&oM4MultScalarTestTwo);
	oM4MultScalarTests.AddUnitTest(&oM4MultScalarTestThree);
	oM4MultScalarTests.AddUnitTest(&oM4MultScalarTestFour);
	oTester.AddUnitTestGroup(oM4MultScalarTests);

	// tests matrix equality -------------------------------------------------------------
	UnitTestGroup oM4EqualTests;

	M4EqualTest oM4EqualTestOne, oM4EqualTestTwo, oM4EqualTestThree, oM4EqualTestFour;

	oM4EqualTestOne.SetData(TestMatrix4A, TestMatrix4B, false);
	oM4EqualTestTwo.SetData(TestMatrix4A, Matrix4(1,1,0,1,2,3,2,0,4,0,1,2,0,0,0,1), true);
	oM4EqualTestThree.SetData(TestMatrix4B, TestMatrix4C, false);
	oM4EqualTestFour.SetData(TestMatrix4B, Matrix4(2,2,0,1,1,1,1,1,0,3,0,2,0,0,0,1), true);

	oM4EqualTests.AddUnitTest(&oM4EqualTestOne);
	oM4EqualTests.AddUnitTest(&oM4EqualTestTwo);
	oM4EqualTests.AddUnitTest(&oM4EqualTestThree);
	oM4EqualTests.AddUnitTest(&oM4EqualTestFour);
	oTester.AddUnitTestGroup(oM4EqualTests);

	//######################## Matrix4 Function Tests ###############################################

	// returns the translation of the matrix as a vector -------------------------------------------------------------
	UnitTestGroup oM4GetTranslationsTests;

	M4GetTranslationsTest oM4GetTranslationsTestOne, oM4GetTranslationsTestTwo, oM4GetTranslationsTestThree, oM4GetTranslationsTestFour;

	oM4GetTranslationsTestOne.SetData(TestMatrix4A, Vector4(1,0,2,1));
	oM4GetTranslationsTestTwo.SetData(TestMatrix4B, Vector4(1,1,2,1));
	oM4GetTranslationsTestThree.SetData(TestMatrix4C, Vector4(2,3,2,2));
	oM4GetTranslationsTestFour.SetData(TestMatrix4D, Vector4(4,1,0,2));

	oM4GetTranslationsTests.AddUnitTest(&oM4GetTranslationsTestOne);
	oM4GetTranslationsTests.AddUnitTest(&oM4GetTranslationsTestTwo);
	oM4GetTranslationsTests.AddUnitTest(&oM4GetTranslationsTestThree);
	oM4GetTranslationsTests.AddUnitTest(&oM4GetTranslationsTestFour);
	oTester.AddUnitTestGroup(oM4GetTranslationsTests);

	//*** To be added when actually attempting 3D stuff ***
	//// returns rotation of the matrix -------------------------------------------------------------
	//UnitTestGroup oM4GetRotationTests;

	//M4GetRotationTest oM4GetRotationTestOne, oM4GetRotationTestTwo, oM4GetRotationTestThree, oM4GetRotationTestFour;

	//oM4GetRotationTestOne.SetData(TestMatrix4A, -0.7854);
	//oM4GetRotationTestTwo.SetData(TestMatrix4B, -0.7854);
	//oM4GetRotationTestThree.SetData(TestMatrix4C, 0.9828);
	//oM4GetRotationTestFour.SetData(Matrix4(1,3,5,-2,1,6,0,0,1), -1.2490);

	//oM4GetRotationTests.AddUnitTest(&oM4GetRotationTestOne);
	//oM4GetRotationTests.AddUnitTest(&oM4GetRotationTestTwo);
	//oM4GetRotationTests.AddUnitTest(&oM4GetRotationTestThree);
	//oM4GetRotationTests.AddUnitTest(&oM4GetRotationTestFour);
	//oTester.AddUnitTestGroup(oM4GetRotationTests);

	// sets translation of the matrix (replaces curr. translation) -------------------------------------------------------------
	UnitTestGroup oM4SetTranslationTests;

	M4SetTranslationTest oM4SetTranslationTestOne, oM4SetTranslationTestTwo, oM4SetTranslationTestThree, oM4SetTranslationTestFour;

	oM4SetTranslationTestOne.SetData(TestMatrix4A, M4TestVectorA, Matrix4(1,1,9,2,3,26,0,0,1));
	oM4SetTranslationTestTwo.SetData(TestMatrix4B, M4TestVectorA, Matrix4(2,2,18,1,1,10,0,0,1));
	oM4SetTranslationTestThree.SetData(TestMatrix4C, M4TestVectorA, Matrix4(-2,3,13,0,-1,-4,0,0,2));
	oM4SetTranslationTestFour.SetData(TestMatrix4D, M4TestVectorA, Matrix4(0,3,23,-2,1,6,0,0,1));

	oM4SetTranslationTests.AddUnitTest(&oM4SetTranslationTestOne);
	oM4SetTranslationTests.AddUnitTest(&oM4SetTranslationTestTwo);
	oM4SetTranslationTests.AddUnitTest(&oM4SetTranslationTestThree);
	oM4SetTranslationTests.AddUnitTest(&oM4SetTranslationTestFour);
	oTester.AddUnitTestGroup(oM4SetTranslationTests);

	//// sets rotation of the matrix (replaces curr. rotation) -------------------------------------------------------------
	//UnitTestGroup oM4SetRotationTests;

	//M4SetRotationTest oM4SetRotationTestOne, oM4SetRotationTestTwo, oM4SetRotationTestThree, oM4SetRotationTestFour;

	//oM4SetRotationTestOne.SetData(TestMatrix4A, PI/2, Matrix4(1,-1,0,3,-2,2,0,0,1));
	//oM4SetRotationTestTwo.SetData(TestMatrix4B, PI/2, Matrix4(2,-2,0,1,-1,1,0,0,1));
	//oM4SetRotationTestThree.SetData(TestMatrix4C, PI/2, Matrix4(3,2,1,-1,0,2,0,0,2));
	//oM4SetRotationTestFour.SetData(TestMatrix4D, PI/2, Matrix4(3,0,5,1,2,6,0,0,1));

	//oM4SetRotationTests.AddUnitTest(&oM4SetRotationTestOne);
	//oM4SetRotationTests.AddUnitTest(&oM4SetRotationTestTwo);
	//oM4SetRotationTests.AddUnitTest(&oM4SetRotationTestThree);
	//oM4SetRotationTests.AddUnitTest(&oM4SetRotationTestFour);
	//oTester.AddUnitTestGroup(oM4SetRotationTests);

	//// sets scale of the matrix (replaces curr. matrix) -------------------------------------------------------------
	//UnitTestGroup oM4SetScaleTests;

	//M4SetScaleTest oM4SetScaleTestOne, oM4SetScaleTestTwo, oM4SetScaleTestThree, oM4SetScaleTestFour;

	//oM4SetScaleTestOne.SetData(TestMatrix4A, 2, Matrix4(2,2,0,4,6,2,0,0,1));
	//oM4SetScaleTestTwo.SetData(TestMatrix4B, 2, Matrix4(4,4,0,2,2,1,0,0,1));
	//oM4SetScaleTestThree.SetData(TestMatrix4C, 2, Matrix4(-4,6,1,0,-2,2,0,0,2));
	//oM4SetScaleTestFour.SetData(TestMatrix4D, 2, Matrix4(0,6,5,-4,2,6,0,0,1));

	//oM4SetScaleTests.AddUnitTest(&oM4SetScaleTestOne);
	//oM4SetScaleTests.AddUnitTest(&oM4SetScaleTestTwo);
	//oM4SetScaleTests.AddUnitTest(&oM4SetScaleTestThree);
	//oM4SetScaleTests.AddUnitTest(&oM4SetScaleTestFour);
	//oTester.AddUnitTestGroup(oM4SetScaleTests);

	//// rotate and scales a directional vector -------------------------------------------------------------
	//UnitTestGroup oM4TransformVectorTests;

	//M4TransformVectorTest oM4TransformVectorTestOne, oM4TransformVectorTestTwo, oM4TransformVectorTestThree, oM4TransformVectorTestFour;

	//oM4TransformVectorTestOne.SetData(M4TestVectorA, PI/2, 4, Vector3(-24,12,1));
	//oM4TransformVectorTestTwo.SetData(M4TestVectorB, PI/2, 4, Vector3(-12,4,0));
	//oM4TransformVectorTestThree.SetData(M4TestVectorC, PI/2, 4, Vector3(0,8,2));
	//oM4TransformVectorTestFour.SetData(M4TestVectorD, PI/2, 4, Vector3(-24,0,1));

	//oM4TransformVectorTests.AddUnitTest(&oM4TransformVectorTestOne);
	//oM4TransformVectorTests.AddUnitTest(&oM4TransformVectorTestTwo);
	//oM4TransformVectorTests.AddUnitTest(&oM4TransformVectorTestThree);
	//oM4TransformVectorTests.AddUnitTest(&oM4TransformVectorTestFour);
	//oTester.AddUnitTestGroup(oM4TransformVectorTests);


	//// rotate, scale and translate a point -------------------------------------------------------------
	//UnitTestGroup oM4Transform2DPointTests;

	//M4Transform2DPointTest oM4Transform2DPointTestOne, oM4Transform2DPointTestTwo, oM4Transform2DPointTestThree, oM4Transform2DPointTestFour;

	//oM4Transform2DPointTestOne.SetData(M4TestVectorA, PI/2, 4, M4TestVectorT, Vector3(-16,14,1));
	//oM4Transform2DPointTestTwo.SetData(M4TestVectorB, PI/2, 4, M4TestVectorT,  Vector3(-12,4,0));
	//oM4Transform2DPointTestThree.SetData(M4TestVectorC, PI/2, 4, M4TestVectorT,  Vector3(-4,10,1));
	//oM4Transform2DPointTestFour.SetData(M4TestVectorD, PI/2, 4, M4TestVectorT,  Vector3(-16,8,1));

	//oM4Transform2DPointTests.AddUnitTest(&oM4Transform2DPointTestOne);
	//oM4Transform2DPointTests.AddUnitTest(&oM4Transform2DPointTestTwo);
	//oM4Transform2DPointTests.AddUnitTest(&oM4Transform2DPointTestThree);
	//oM4Transform2DPointTests.AddUnitTest(&oM4Transform2DPointTestFour);
	//oTester.AddUnitTestGroup(oM4Transform2DPointTests);

	//// creates an identity matrix -------------------------------------------------------------
	//UnitTestGroup oM4CreateIdentityTests;

	//M4CreateIdentityTest oM4CreateIdentityTestOne, oM4CreateIdentityTestTwo, oM4CreateIdentityTestThree, oM4CreateIdentityTestFour;

	//oM4CreateIdentityTestOne.SetData(TestMatrix4A, Matrix4(1,0,0,0,1,0,0,0,1));
	//oM4CreateIdentityTestTwo.SetData(TestMatrix4B, Matrix4(1,0,0,0,1,0,0,0,1));
	//oM4CreateIdentityTestThree.SetData(TestMatrix4C, Matrix4(1,0,0,0,1,0,0,0,1));
	//oM4CreateIdentityTestFour.SetData(TestMatrix4D, Matrix4(1,0,0,0,1,0,0,0,1));

	//oM4CreateIdentityTests.AddUnitTest(&oM4CreateIdentityTestOne);
	//oM4CreateIdentityTests.AddUnitTest(&oM4CreateIdentityTestTwo);
	//oM4CreateIdentityTests.AddUnitTest(&oM4CreateIdentityTestThree);
	//oM4CreateIdentityTests.AddUnitTest(&oM4CreateIdentityTestFour);
	//oTester.AddUnitTestGroup(oM4CreateIdentityTests);

	//// creates new rotation matrix with 0,0 translation -------------------------------------------------------------
	//UnitTestGroup oM4CreateRotationTests;

	//M4CreateRotationTest oM4CreateRotationTestOne, oM4CreateRotationTestTwo, oM4CreateRotationTestThree, oM4CreateRotationTestFour;

	//oM4CreateRotationTestOne.SetData(TestMatrix4A, PI/2, Matrix4(0,-1,0,1,0,0,0,0,1));
	//oM4CreateRotationTestTwo.SetData(TestMatrix4B, PI/2, Matrix4(0,-1,0,1,0,0,0,0,1));
	//oM4CreateRotationTestThree.SetData(TestMatrix4C, PI/2, Matrix4(0,-1,0,1,0,0,0,0,1));
	//oM4CreateRotationTestFour.SetData(TestMatrix4D, PI/2, Matrix4(0,-1,0,1,0,0,0,0,1));

	//oM4CreateRotationTests.AddUnitTest(&oM4CreateRotationTestOne);
	//oM4CreateRotationTests.AddUnitTest(&oM4CreateRotationTestTwo);
	//oM4CreateRotationTests.AddUnitTest(&oM4CreateRotationTestThree);
	//oM4CreateRotationTests.AddUnitTest(&oM4CreateRotationTestFour);
	//oTester.AddUnitTestGroup(oM4CreateRotationTests);

	//// creates new scale matrix -------------------------------------------------------------
	//UnitTestGroup oM4CreateScaleTests;

	//M4CreateScaleTest oM4CreateScaleTestOne, oM4CreateScaleTestTwo, oM4CreateScaleTestThree, oM4CreateScaleTestFour;

	//oM4CreateScaleTestOne.SetData(TestMatrix4A, 2, Matrix4(2,0,0,0,2,0,0,0,1));
	//oM4CreateScaleTestTwo.SetData(TestMatrix4B, 3, Matrix4(3,0,0,0,3,0,0,0,1));
	//oM4CreateScaleTestThree.SetData(TestMatrix4C, 4, Matrix4(4,0,0,0,4,0,0,0,1));
	//oM4CreateScaleTestFour.SetData(TestMatrix4D, -2, Matrix4(-2,0,0,0,-2,0,0,0,1));

	//oM4CreateScaleTests.AddUnitTest(&oM4CreateScaleTestOne);
	//oM4CreateScaleTests.AddUnitTest(&oM4CreateScaleTestTwo);
	//oM4CreateScaleTests.AddUnitTest(&oM4CreateScaleTestThree);
	//oM4CreateScaleTests.AddUnitTest(&oM4CreateScaleTestFour);
	//oTester.AddUnitTestGroup(oM4CreateScaleTests);

	//// creates new translation matrix with 0 rotation -------------------------------------------------------------
	//UnitTestGroup oM4CreateTranslationTests;

	//M4CreateTranslationTest oM4CreateTranslationTestOne, oM4CreateTranslationTestTwo, oM4CreateTranslationTestThree, oM4CreateTranslationTestFour;

	//oM4CreateTranslationTestOne.SetData(TestMatrix4A, M4TestVectorA, Matrix4(1,0,3,0,1,6,0,0,1));
	//oM4CreateTranslationTestTwo.SetData(TestMatrix4B, M4TestVectorB, Matrix4(1,0,1,0,1,3,0,0,0));
	//oM4CreateTranslationTestThree.SetData(TestMatrix4C, M4TestVectorC, Matrix4(1,0,2,0,1,0,0,0,2));
	//oM4CreateTranslationTestFour.SetData(TestMatrix4D, M4TestVectorD, Matrix4(1,0,0,0,1,6,0,0,1));

	//oM4CreateTranslationTests.AddUnitTest(&oM4CreateTranslationTestOne);
	//oM4CreateTranslationTests.AddUnitTest(&oM4CreateTranslationTestTwo);
	//oM4CreateTranslationTests.AddUnitTest(&oM4CreateTranslationTestThree);
	//oM4CreateTranslationTests.AddUnitTest(&oM4CreateTranslationTestFour);
	//oTester.AddUnitTestGroup(oM4CreateTranslationTests);

	//// creates orthographic projection matrix for given cardinal axis -------------------------------------------------------------
	//UnitTestGroup oM4CreateCardinalOrthoTests;

	//M4CreateCardinalOrthoTest oM4CreateCardinalOrthoTestOne, oM4CreateCardinalOrthoTestTwo, oM4CreateCardinalOrthoTestThree, oM4CreateCardinalOrthoTestFour;

	//oM4CreateCardinalOrthoTestOne.SetData(TestMatrix4A, 'x', Matrix4(1,0,0,0,0,0,0,0,1));
	//oM4CreateCardinalOrthoTestTwo.SetData(TestMatrix4B, 'y', Matrix4(0,0,0,0,1,0,0,0,1));
	//oM4CreateCardinalOrthoTestThree.SetData(TestMatrix4C, 'x', Matrix4(1,0,0,0,0,0,0,0,1));
	//oM4CreateCardinalOrthoTestFour.SetData(TestMatrix4D, 'y', Matrix4(0,0,0,0,1,0,0,0,1));

	//oM4CreateCardinalOrthoTests.AddUnitTest(&oM4CreateCardinalOrthoTestOne);
	//oM4CreateCardinalOrthoTests.AddUnitTest(&oM4CreateCardinalOrthoTestTwo);
	//oM4CreateCardinalOrthoTests.AddUnitTest(&oM4CreateCardinalOrthoTestThree);
	//oM4CreateCardinalOrthoTests.AddUnitTest(&oM4CreateCardinalOrthoTestFour);
	//oTester.AddUnitTestGroup(oM4CreateCardinalOrthoTests);






	
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