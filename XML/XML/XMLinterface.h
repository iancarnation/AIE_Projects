///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			XMLinterface.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			XML file input and output
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _XMLINTERFACE_H_
#define _XMLINTERFACE_H_

#include <iostream>
#include "tinystr.h"
#include "tinyxml.h"
#include "XML.h"
using namespace std;

class XML
{
	public:
		
		XML();
		TiXmlDocument Load(const char* filename);	// load file for TinyXML
		void Read(TiXmlDocument doc, Settings& a_rSettings);		// read data and plug into variables
		void Write();		// save variable data into file
		void Print(const Settings& a_rSettings);
		~XML();
};

#endif