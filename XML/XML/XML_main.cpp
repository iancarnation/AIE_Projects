

#include "stdafx.h"
#include "XMLinterface.h"
#include <iostream>
using namespace std;

void main(_TCHAR* argv[])
{
	XML Interface;
	Settings GameSettings;
	TiXmlDocument doc = Interface.Load("settings.xml");
	
	Interface.Read(doc, GameSettings);

	Interface.Print(GameSettings);
}