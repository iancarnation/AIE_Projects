#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include "GameEngine.h"
//#include "KeyCodes.h"
#include "AIE.h"
class GameState
{
public:
	// to be executed first upon entering the state
	virtual void Init() = 0;
	// to be executed when state is popped from end of stack
	virtual void Cleanup() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	// handles responses to inputs
	virtual void HandleEvents(GameEngine* a_opGame) = 0;
	// occurs each frame
	virtual void Update(GameEngine* a_opGame, double dt) = 0;
	// renders things to the screen
	virtual void Draw(GameEngine* a_opGame) = 0;
	void ChangeState(GameEngine* a_opGame, GameState* a_opState)
	{
		a_opGame->ChangeState(a_opState);
	}
protected:
	// protected constructor for making Singleton
	GameState() { }
};
#endif