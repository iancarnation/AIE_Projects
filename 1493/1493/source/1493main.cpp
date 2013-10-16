///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			1493main.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			main loop
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include "GameEngine.h"
#include "IntroState.h"
#include "1493functions.h"

int main( int argc, char* argv[] )
{
	GameEngine oGame;

	// initialize engine
	oGame.Init();

	// load the intro
	oGame.ChangeState(IntroState::Instance());

	// main loop
	do
	{
		oGame.HandleEvents();
		oGame.Update();
		oGame.Draw();
	}
	while ( FrameworkUpdate() == false );

	oGame.Cleanup();
}
