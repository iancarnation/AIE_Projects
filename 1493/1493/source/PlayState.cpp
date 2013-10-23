///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			PlayState.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			play state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayState.h"

PlayState PlayState::m_PlayState; // **has to do with singleton?**

// default constructor
PlayState::PlayState()
{
	

}

// to be executed first upon entering the state
void PlayState::Init()
{

	// load sprites
	Sprite oBGimage("Background", SCREEN_X, SCREEN_Y, SCREEN_CENTER, ZERO_VELOCITY, 0, true, "./images/bgImage.png");
	//MoveSprite(oBGimage.GetSpriteId(), 1024>>1, 768>>1);
	m_SpriteList.push_back(oBGimage);

	Player oPlayer("Player", 40, 70, Vector2D(400, 500), ZERO_VELOCITY, 1, true, "./images/playerImage.png");
	//MoveSprite(oPlayer.GetSpriteId(), 1024>>1, 768>>1);
	m_PlayerList.push_back(oPlayer);
	//** reference calls SDL_Surface* temp = SDL_LoadBMP("play.bmp");
	//					 bg = SDL_DisplayFormat(temp);
	//					 SDL_FreeSurface(temp)**

	printf("PlayState Init\n");

}

// to be executed when state is popped from end of stack
void PlayState::Cleanup()
{
	// **clean stuff? (sprite & fader?)**
	for each(Sprite s in m_SpriteList)
	{
		s.Destroy();
	}
	
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
	if (IsKeyDown('M'))
		{
			a_opGame->PushState(MenuState::Instance());
		}
	if (IsKeyDown('Q'))
		{
			a_opGame->Quit();
		}

	// look for player input for movement control
}

void PlayState::Update(GameEngine* a_opGame)
{
	for(list<Sprite>::iterator it = m_SpriteList.begin(); it != m_SpriteList.end(); it++)
	{
		it->Update();
	}
	for (list<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		it->Update();
	}
	// call update functions for all objects?
}

void PlayState::Draw(GameEngine* a_opGame)
{
	// reference project calls SDL_BlitSurface(bg, NULL, game->screen, NULL);
	//						   SDL_UpdateRect(game->screen, 0, 0, 0, 0);
	// ^^ probably irrelevant??

	// call draw functions of all movable objects?
	for (list<Sprite>::iterator it = m_SpriteList.begin(); it != m_SpriteList.end(); it++)
	{
		it->Draw();
	}
	for (list<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		it->Draw();
	}
	//DrawSprite(oPlayer.Get
}



PlayState* PlayState::Instance()
{
	return &m_PlayState;
}
