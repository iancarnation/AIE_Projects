

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

	cout<< "\nDifficulty: ";
	switch(GameSettings.Difficulty.iDifficulty)
	{
	case 0:
		cout<< "Easy Peasy Lemon Squeezy\n";
		break;
	case 1:
		cout<< "Normal Schmormal\n";
		break;
	case 2:
		cout<< "Hardy Boyz in da Hood\n";
		break;
	};

	cout<< "\nDisplay Settings:\n";
	cout<< "\nWidth: " << GameSettings.Display.iWidth;
	cout<< "\nHeight: " << GameSettings.Display.iHeight;
	cout<< "\nFullsreen: " << GameSettings.Display.bFullscreen;

}