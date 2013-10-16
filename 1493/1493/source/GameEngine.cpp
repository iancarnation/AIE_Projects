///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			GameEngine.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Engine for management of a game state stack and framework functionality
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/, http://www.dreamincode.net/forums/topic/118898-state-management/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// *** Maybe refactor this into just a game state manager?? ***

#include "AIE.h"
#include "GameEngine.h"
#include "GameState.h"

// initialize the framework **is this needed?**
void GameEngine::Init()
{
	Initialise(800, 600, false);

	printf("GameEngine Init\n");
}

// clean up all the states and *shut down?*  **check redundancy with Quit()**
void GameEngine::Cleanup()
{
	// cleanup all the states
	while (!v_oStateStack.empty())
	{
		v_oStateStack.back()->Cleanup();
		v_oStateStack.pop_back();
	}

	printf("GameEngine Cleanup\n");

	// destroy sprites and clean memory
	////DestroySprite(); // **need to create**
	//shutdown Framework
	Shutdown();
}

// removes current state from the stack and adds new state to end of stack
void GameEngine::ChangeState(GameState* a_opState)
{
	// cleanup the current state
	if (!v_oStateStack.empty())
	{
		v_oStateStack.back()->Cleanup();
		v_oStateStack.pop_back();
	}

	// store and init the new state
	v_oStateStack.push_back(a_opState);
	v_oStateStack.back()->Init();
}

// pauses the current state and adds new state to end of stack
void GameEngine::PushState(GameState* a_opState)
{
	// pause current state
	if (!v_oStateStack.empty())
		v_oStateStack.back()->Pause();

	// store and init the new state
	v_oStateStack.push_back(a_opState);
	v_oStateStack.back()->Init();
}

// removes the state at the end of the stack and sets current state to previous state on stack
void GameEngine::PopState()
{
	// cleanup the current state
	if (!v_oStateStack.empty())
	{
		v_oStateStack.back()->Cleanup();
		v_oStateStack.pop_back();
	}

	// resume previous state
	if (!v_oStateStack.empty())
		v_oStateStack.back()->Resume();
}

// handles responses to inputs
void GameEngine::HandleEvents()
{
	// let the state handle events
	v_oStateStack.back()->HandleEvents(this);
}

// occurs each frame
void GameEngine::Update()
{
	// let the state update the game
	v_oStateStack.back()->Update(this);
}

// renders things to the screen
void GameEngine::Draw()
{
	// let the state draw the screen
	v_oStateStack.back()->Draw(this);
}

// returns whether the game is running or not (m_bRunning)
bool GameEngine::Running()
{
	return this->m_bRunning;
}

// stops the game from running
void GameEngine::Quit()
{
	this->m_bRunning = false;
}