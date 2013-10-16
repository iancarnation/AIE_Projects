///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			PlayState.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			play state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#include "GameState.h"

class PlayState : public GameState
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
		void Update(GameEngine* a_opGame);
		// renders things to the screen
		void Draw(GameEngine* a_opGame);

		static PlayState* Instance(); //**verify that this is implemented correctly in cpp**

	protected:
		PlayState() { }

	private:
		static PlayState m_PlayState;
		//**reference has pointer to background?**

		int m_iBg;	 // background sprite ID 
};

#endif