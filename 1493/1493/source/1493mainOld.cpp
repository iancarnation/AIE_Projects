///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			1493main.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			A SHMUP game based on the Capcom game, "1943: The Battle of Midway"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "1493functions.h"

// main game loop
int main( int argc, char* argv[] )
{	
	// Initialize Game Framework
	Initialise(SCREEN_X, SCREEN_Y, false );

	initGame();

	// set game state to menu
	GAME_STATE currentState = GAME_STATE_PLAY;
		
	do 
	{
		// switch statement for game states
		switch (currentState)
		{
			case GAME_STATE_MENU:
				mainMenu(currentState);
				break;
			case GAME_STATE_PLAY:
				checkPlayerWin(currentState);
				ClearScreen();
				updateGame();
				drawGame();
				break;
			case GAME_STATE_WIN:
				winScreen(currentState);
				break;
			case GAME_STATE_LOSE:
				loseScreen(currentState);
				break;
	
		};
	} 
	while ( FrameworkUpdate() == false );
			
				destroyGame();
				Shutdown();
				
	return 0;
}

