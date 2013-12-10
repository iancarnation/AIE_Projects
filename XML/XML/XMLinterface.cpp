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
	TiXmlElement * pDisplayElement = pSettingsElement->NextSiblingElement("Display");
	const char * cWidth = pDisplayElement->Attribute("width");
	const char * cHeight = pDisplayElement->Attribute("height");
	const char * cFullScrn = pDisplayElement->Attribute("fullscreen");

	// update structure variables
	// Difficulty
	a_rSettings.Difficulty.iDifficulty = atoi(cDifficulty);

	// Display
	a_rSettings.Display.iWidth = atoi(cWidth);
	a_rSettings.Display.iHeight = atoi(cHeight);
	if (cFullScrn == "false")
		a_rSettings.Display.bFullscreen = false;
	else
		a_rSettings.Display.bFullscreen = true;

	// Sound
}

// save variable data into file
void XML::Write()
{

}

XML::~XML()
{

}