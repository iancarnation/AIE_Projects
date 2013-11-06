///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			MenuState.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			menu state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include "GameState.h"

class MenuState : public GameState
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
		void Update(GameEngine* a_opGame,double dt);
		// renders things to the screen
		void Draw(GameEngine* a_opGame);

		static MenuState* Instance(); //**verify that this is implemented correctly in cpp**

	protected:
		MenuState() { }

	private:
		static MenuState m_MenuState;
		//**reference has pointer to background?**

		int m_iBG;	 // background sprite ID m_iBg
};

#endif