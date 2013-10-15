
#include "gameengine.h"
#include "introstate.h"

int main ( int argc, char *argv[] )
{
	CGameEngine game;

	// initialize the engine
	game.Init( "Engine Test v1.0" );

	// load the intro
	game.ChangeState( CIntroState::Instance() );

	// main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	// cleanup the engine
	game.Cleanup();

	return 0;
}
