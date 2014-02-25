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
		dTime = GetDeltaTime();

		oGame.HandleEvents();
		oGame.Update(dTime);
		oGame.Draw();
	}
	while (oGame.Running() && FrameworkUpdate() == false);

	// cleanup the engine
	oGame.Cleanup();
}
