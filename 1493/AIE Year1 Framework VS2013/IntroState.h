#ifndef _INTROSTATE_H_
#define _INTROSTATE_H_
#include "GameState.h"
class IntroState : public GameState
{
public:
	// to be executed first upon entering the state
	void Init();
	// to be executed when state is popped from end of stack
	void Cleanup();
	void Pause();
	void Resume();
	// handles responses to inputs
	void HandleEvents(GameEngine* a_opGame);
	// occurs each frame
	void Update(GameEngine* a_opGame, double dt);
	// renders things to the screen
	void Draw(GameEngine* a_opGame);
	static IntroState* Instance(); //**verify that this is implemented correctly in cpp**
protected:
	IntroState() { }
private:
	static IntroState m_IntroState;
	int m_iAlpha; //**used for fading out intro**
	int m_iBG;	// background sprite ID
};
#endif