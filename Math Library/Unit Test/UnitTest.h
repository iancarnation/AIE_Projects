///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTest.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Unit Testing class prototypes
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _UNITTEST_H_
#define _UNITTEST_H_

#include <list>
#include <memory>
using namespace std;

// Unit Test base class
class UnitTest
{
	public:
		UnitTest();
		~UnitTest();

		virtual bool DoTest() = 0;
};

// Contains list of UnitTest instances
class UnitTestGroup
{
	public:
		UnitTestGroup();
		~UnitTestGroup();

		void AddUnitTest(UnitTest* a_opTest);	// add test to group list

		list<UnitTest> m_olUnitTests;
};

// Top level of Unit Testing Library, Contains list of UnitTestGroup instances
class UnitTester
{
	public:
		UnitTester();
		~UnitTester();

		void AddUnitTestGroup(UnitTestGroup a_oTestGroup); // add test group to master list
		bool DoTests(); 

		list<UnitTestGroup> m_olUnitTestGroups;
};
#endif