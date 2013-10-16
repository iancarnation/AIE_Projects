///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			IntroState.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Game Introduction state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include "GameEngine.h"
#include "GameState.h"
#include "IntroState.h"
#include "PlayState.h"
#include "MovableObject.h"

IntroState IntroState::m_IntroState; // **has to do with singleton?**

// default constructor
IntroState::IntroState()
{

}

// to be executed first upon entering the state
void IntroState::Init()
{
	// load intro sprite
	MovableObject introImage("TestImage", 800, 600, 400, 300, 0, 0, true, "./images/IntroState.png");
	m_bg = introImage.GetSpriteId();
	MoveSprite(m_bg, 800>>1, 600>>1);
	// do something to make a "fade"

	// run the fade

	printf("IntroState Init\n");

}

// to be executed when state is popped from end of stack
void IntroState::Cleanup()
{
	// **clean stuff? (sprite & fader?)**
	DestroySprite(m_bg);

	printf("IntroState Cleanup\n");
}

void IntroState::Pause()
{
	printf("IntroState Pause\n");
}

void IntroState::Resume()
{
	printf("IntroState Resume\n");
}

void IntroState::HandleEvents(GameEngine* a_opGame)
{
	// look for key presses to quit or go to the menu??
}

void IntroState::Update(GameEngine* a_opGame)
{
	// decrement the alpha of the fader covering the background

	// feed alpha value to the fader
}

void IntroState::Draw(GameEngine* a_opGame)
{
	// reference project uses Blit from SDL, look that up and compare with GLFW?

	// draw the background image??  check out ref. **
	DrawSprite(m_bg);
}

IntroState* IntroState::Instance()
{
	return &m_IntroState;
}
