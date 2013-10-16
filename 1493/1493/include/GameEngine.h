///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			GameEngine.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Engine for management of a game state stack and framework functionality
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/, http://www.dreamincode.net/forums/topic/118898-state-management/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// *** Maybe refactor this into just a game state manager?? ***

#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

// **need AIE header or any others??**

#include <vector>
using namespace std;

class GameState;

class GameEngine
{
	public: 
		// initialize the framework **is this needed?**
		void Init();
		// clean up all the states and *shut down?*  **check redundancy with Quit()**
		void Cleanup();

		// removes current state from the stack and adds new state to end of stack
		void ChangeState(GameState* a_opState);
		// pauses the current state and adds new state to end of stack
		void PushState(GameState* a_opState);
		// removes the state at the end of the stack and sets current state to previous state on stack
		void PopState();

		// handles responses to inputs
		void HandleEvents();
		// occurs each frame
		void Update();
		// renders things to the screen
		void Draw();

		// returns whether the game is running or not (m_bRunning)
		bool Running();
		// stops the game from running
		void Quit();

	private:
		// the state stack
		vector<GameState*> v_oStateStack;

		// whether the game is running or not
		bool m_bRunning;
};

#endif