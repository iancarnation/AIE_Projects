///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			XMLinterface.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			XML file input and output
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "XMLinterface.h"

XML::XML()
{

}

// load file for TinyXML
TiXmlDocument XML::Load(const char* a_filename)
{
	TiXmlDocument doc(a_filename);

	bool loadOkay = doc.LoadFile();

	// Error check
	if (!loadOkay)
		cout<< "file is missing\n";

	return doc;
}

// read data and plug into variables
void XML::Read(TiXmlDocument doc, Settings& a_rSettings)
{
	// get the root node (Settings)
	TiXmlNode * pSettings = doc.FirstChild("Settings");
	TiXmlElement * pSettingsElement = pSettings->ToElement();

	// first child element (GameDifficulty)
	TiXmlElement * pDifficultyElement = pSettingsElement->FirstChildElement("GameDifficulty");
	const char * cDifficulty = pDifficultyElement->Attribute("difficulty");

	// next element..
	TiXmlElement * pDisplayElement = pDifficultyElement->NextSiblingElement("Display");
	const char * cWidth = pDisplayElement->Attribute("width");
	const char * cHeight = pDisplayElement->Attribute("height");
	const char * cFullScrn = pDisplayElement->Attribute("fullscreen");

	// Sound
	TiXmlElement * pSoundElement = pDisplayElement->NextSiblingElement("Sound");
	const char * cMasterVol = pSoundElement->Attribute("masterVolume");
	const char * cSoundFX = pSoundElement->Attribute("soundEffects");
	const char * cMusic = pSoundElement->Attribute("music");
	const char * cVoice = pSoundElement->Attribute("voice");
	const char * cMicLev = pSoundElement->Attribute("micLevel");

	// Mouse
	TiXmlElement * pMouseElement = pSoundElement->NextSiblingElement("MouseSettings");
	const char * cXsense = pMouseElement->Attribute("Xsense");
	const char * cYsense = pMouseElement->Attribute("Ysense");
	const char * cInv = pMouseElement->Attribute("inversed");

	// Keys
	TiXmlElement * pKeysElement = pMouseElement->NextSiblingElement("KeySettings");
	const char * cForward = pKeysElement->Attribute("forward");
	const char * cBackward = pKeysElement->Attribute("backward");
	const char * cLeft = pKeysElement->Attribute("left");
	const char * cRight = pKeysElement->Attribute("right");
	const char * cFire = pKeysElement->Attribute("fire");

//---------------------------------------------------------------------------------------------
	// update structure variables

	// Difficulty
	a_rSettings.Difficulty.iDifficulty = atoi(cDifficulty);

	// Display
	a_rSettings.Display.iWidth = atoi(cWidth);
	a_rSettings.Display.iHeight = atoi(cHeight);
	if (strcmp(cFullScrn, "false") == 0)
		a_rSettings.Display.bFullscreen = false;
	else if (strcmp(cFullScrn, "true") == 0)
		a_rSettings.Display.bFullscreen = true;
	else
		cout<< "Invalid Fullscreen attribute!\n";

	// Sound
	a_rSettings.Sound.fMasterVolume = atof(cMasterVol);
	a_rSettings.Sound.fSoundEffects = atof(cSoundFX);
	a_rSettings.Sound.fMusic = atof(cMusic);
	a_rSettings.Sound.fVoice = atof(cVoice);
	a_rSettings.Sound.fMicLevel = atof(cMicLev);

	// Mouse
	a_rSettings.Mouse.fXsense = atof(cXsense);
	a_rSettings.Mouse.fYsense = atof(cYsense);
	if (strcmp(cInv, "false") == 0)
		a_rSettings.Mouse.bInversed = false;
	else if (strcmp(cInv, "true") == 0)
		a_rSettings.Mouse.bInversed = true;
	else
		cout<< "Invalid Inversed attribute!\n";

	// Keys
	a_rSettings.Keys.cForward = *cForward;
	a_rSettings.Keys.cBackward = *cBackward;
	a_rSettings.Keys.cLeft = *cLeft;
	a_rSettings.Keys.cRight = *cRight;
	a_rSettings.Keys.cFire = *cFire;

}

// save variable data into file
void XML::Write()
{

}

void XML::Print(const Settings& GameSettings)
{
	// Difficulty
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

	// Display
	cout<< "\n\nDisplay Settings:\n";
	cout<< "\nWidth: " << GameSettings.Display.iWidth;
	cout<< "\nHeight: " << GameSettings.Display.iHeight;
	cout<< "\nFullscreen: ";
	if (GameSettings.Display.bFullscreen)
		cout<< "True\n";
	else
		cout<< "False\n";

	// Sound
	cout<< "\n\nSound Settings:\n";
	cout<< "\nMaster Volume: " << GameSettings.Sound.fMasterVolume;
	cout<< "\nSound Effects: " << GameSettings.Sound.fSoundEffects;
	cout<< "\nMusic: " << GameSettings.Sound.fMusic;
	cout<< "\nVoice: " << GameSettings.Sound.fVoice;
	cout<< "\nMicLevel: " << GameSettings.Sound.fMicLevel << "\n";

	// Mouse
	cout<< "\n\nMouse Settings:\n";
	cout<< "\nX Sensitivity: " << GameSettings.Mouse.fXsense;
	cout<< "\nY Sensitivity: " << GameSettings.Mouse.fYsense;
	cout<< "\nInversed: ";
	if (GameSettings.Mouse.bInversed)
		cout<< "True\n";
	else
		cout<< "False\n";

	// Keys
	cout<< "\n\nKeyboard Settings:\n";
	cout<< "\nForward: " << GameSettings.Keys.cForward;
	cout<< "\nBackward: " << GameSettings.Keys.cBackward;
	cout<< "\nLeft: " << GameSettings.Keys.cLeft;
	cout<< "\nRight: " << GameSettings.Keys.cRight;
	cout<< "\nFire: " << GameSettings.Keys.cFire << "\n";

	cout<< "\nSatisfied?";
	char satisfaction;
	cin>> satisfaction;
}

XML::~XML()
{

}