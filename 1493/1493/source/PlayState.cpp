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
	EnvironmentObj oBGimage("Background", SCREEN_X, SCREEN_Y * 8, SCREEN_CENTER, Vector2D(0, 0.1), 0, true, "./images/bgImage.png");
	//MoveSprite(oBGimage.GetSpriteId(), 1024>>1, 768>>1);
	m_EnvironList.push_back(oBGimage);

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
	for each(EnvironmentObj e in m_EnvironList)
	{
		e.Destroy();
	}

	for each(Player p in m_PlayerList)
	{
		p.Destroy();
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
	for (list<EnvironmentObj>::iterator it = m_EnvironList.begin(); it != m_EnvironList.end(); it++)
	{
		it->Update();
	}
	for (list<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		it->Update();
	}

}

void PlayState::Draw(GameEngine* a_opGame)
{
	// reference project calls SDL_BlitSurface(bg, NULL, game->screen, NULL);
	//						   SDL_UpdateRect(game->screen, 0, 0, 0, 0);
	// ^^ probably irrelevant??

	// call draw functions of all movable objects?
	for (list<EnvironmentObj>::iterator it = m_EnvironList.begin(); it != m_EnvironList.end(); it++)
	{
		it->Draw();
	}
	for (list<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		it->Draw();
	}
	//DrawSprite(oPlayer.Get
}

// triggers enemy spawns based on player's distance from level start
void PlayState::EnemyTrigger(EnvironmentObj& a_bg, Player& a_player)
{
	if (a_bg.GetEdge(BOTTOM) - a_player.GetEdge(TOP) > 20)
	{
		// trigger first wave
	}
}


PlayState* PlayState::Instance()
{
	return &m_PlayState;
}
