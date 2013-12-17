///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTestGroup.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Contains list of UnitTest instances
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _UNITTESTGROUP_H_
#define _UNITTESTGROUP_H_

#include "UnitTest.h"
#include <list>

class UnitTestGroup
{
	public:
		UnitTestGroup() {}
		~UnitTestGroup() {}

		void AddUnitTest(UnitTest* a_opTest) 
		{
			m_olUnitTests.push_back(a_opTest);
		}

	private:
		list<UnitTest> m_olUnitTests;
};


#endif