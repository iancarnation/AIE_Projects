#include "AIE.h"
#include "GameEngine.h"
#include "IntroState.h"
#include "Utilities.h"
int main(int argc, char* argv[])
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
	} while (oGame.Running() && FrameworkUpdate() == false);
	// cleanup the engine
	oGame.Cleanup();
}