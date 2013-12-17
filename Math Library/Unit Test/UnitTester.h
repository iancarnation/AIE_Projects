///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			UnitTester.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Top level of Unit Testing Library, Contains list of UnitTestGroup instances
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _UNITTESTER_H_
#define _UNITTESTER_H_

#include "UnitTestGroup.h"

class UnitTester
{
	public:
		UnitTester() {}
		~UnitTester() {}

		void AddUnitTestGroup(UnitTestGroup a_oTestGroup) 
		{
			m_olUnitTestGroups.push_back(a_oTestGroup);
		}

		bool DoTests()
		{
			for (list<UnitTestGroup>::iterator itGroup = m_olUnitTestGroups.begin(); itGroup != m_olUnitTestGroups.end(); itGroup++)
				for (list<UnitTest>::iterator it = itGroup->begin(); itGroup != itGroup->end(); it++)
					it.DoTest();
		}

	private:
		list<UnitTestGroup> m_olUnitTestGroups;
};


#endif