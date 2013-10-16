///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			PlayState.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			play state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include "GameEngine.h"
#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"

PlayState PlayState::m_PlayState; // **has to do with singleton?**

// default constructor
PlayState::PlayState()
{

}

// to be executed first upon entering the state
void PlayState::Init()
{
	// load sprites

	//** reference calls SDL_Surface* temp = SDL_LoadBMP("play.bmp");
	//					 bg = SDL_DisplayFormat(temp);
	//					 SDL_FreeSurface(temp)**

	printf("PlayState Init\n");

}

// to be executed when state is popped from end of stack
void Cleanup()
{
	// **clean stuff? (sprite & fader?)**
	
	printf("PlayState Cleanup\n");
}

void PlayState::Pause()
{
	// store the current velocity of everything
	// set all velocities to 0
	// maybe fog or gray-out all graphics
    // play sound and pause music
	// show pause menu or main menu
	printf("PlayState Pause\n");
}

void PlayState::Resume()
{
	// when exit menu or press escape, remove fog and restore previous velocity information

	printf("PlayState Resume\n");
}

void PlayState::HandleEvents(GameEngine* a_opGame)
{
	// look for key presses to quit or go to the menu

	// look for player input for movement control
}

void PlayState::Update(GameEngine* a_opGame)
{
	// call update functions for all movable objects?
}

void PlayState::Draw(GameEngine* a_opGame)
{
	// reference project calls SDL_BlitSurface(bg, NULL, game->screen, NULL);
	//						   SDL_UpdateRect(game->screen, 0, 0, 0, 0);
	// ^^ probably irrelevant??

	// call draw functions of all movable objects?
	DrawSprite(temp);
}

PlayState* PlayState::Instance()
{
	return &m_PlayState;
}
