///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			XML.h
// Author:			Ian Rich
// Date Created:	2013
// Brief:			XML file input and output
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _XML_H_
#define _XML_H_

struct GameDifficulty
{
	int iDifficulty;
};

struct DisplaySettings
{
	int iWidth, iHeight;
	bool bFullscreen;
};

struct SoundSettings
{
	float fMasterVolume, fSoundEffects,
		  fMusic, fVoice, fMicLevel;
};

struct MouseSettings
{
	float fXsense, fYsense;
	bool bInversed;
};

struct KeySettings
{
	char cForward, cBackward, cLeft, cRight, cFire;
};

struct Settings
{
	GameDifficulty Difficulty;
	DisplaySettings Display;
	SoundSettings Sound;
	MouseSettings Mouse;
	KeySettings Keys;
};


#endif