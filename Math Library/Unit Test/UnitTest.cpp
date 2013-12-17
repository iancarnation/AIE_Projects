///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTest.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Unit Testing class definitions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UnitTest.h"

// UnitTest: Unit Test base class ------------------------------------------------------

UnitTest::UnitTest() {}
UnitTest::~UnitTest() {}

// UnitTestGroup: Contains list of UnitTest instances -----------------------------------------------

UnitTestGroup::UnitTestGroup() {}
UnitTestGroup::~UnitTestGroup() {}

// add test to group list
void UnitTestGroup::AddUnitTest(UnitTest* a_opTest)
{
	m_olUnitTests.push_back(*a_opTest);
}

// UnitTester: Top level of Unit Testing Library, Contains list of UnitTestGroup instances -----------------------

UnitTester::UnitTester() {}
UnitTester::~UnitTester() {}

// add test group to master list
void UnitTester::AddUnitTestGroup(UnitTestGroup a_oTestGroup) 
{
	m_olUnitTestGroups.push_back(a_oTestGroup);
}

bool UnitTester::DoTests()
{
	for (list<UnitTestGroup>::iterator itGroup = m_olUnitTestGroups.begin(); itGroup != m_olUnitTestGroups.end(); itGroup++)
		for (list<UnitTest>::iterator it = itGroup->m_olUnitTests.begin(); it != itGroup->m_olUnitTests.end(); it++)
			it->DoTest();
}