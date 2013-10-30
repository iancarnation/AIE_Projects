///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			PlayState.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			play state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayState.h"
#include "DeathState.h"

PlayState PlayState::m_PlayState; // **has to do with singleton?**

// default constructor
PlayState::PlayState()
{
	
}

// to be executed first upon entering the state
void PlayState::Init()
{

	// load environment objects
	EnvironmentObj oBGimage("Background", SCREEN_X, SCREEN_Y * 8, Vector2D(SCREEN_X/2, SCREEN_Y), Vector2D(0, 0.1), 0, true, "./images/bgImage.png");
	//MoveSprite(oBGimage.GetSpriteId(), 1024>>1, 768>>1);
	m_EnvironList.push_back(oBGimage);

	// load player object(s)
	Player oPlayer("Player", 30, 90, Vector2D(400, 500), ZERO_VELOCITY, 1, true, "./images/Player.png");
	//MoveSprite(oPlayer.GetSpriteId(), 1024>>1, 768>>1);
	m_PlayerList.push_back(oPlayer);

	// load enemy objects
	InitEnemies();

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
	// check for enemy spawn trigger point
	EnemySpawnCheck();

	// update Environment Objects
	for (vector<EnvironmentObj>::iterator it = m_EnvironList.begin(); it != m_EnvironList.end(); it++)
	{
		it->Update();
	}

	// update Player Objects
	for (vector<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		it->Update();
	}

	// update Enemy objects
	for (map < string, list<Enemy> >::iterator mapIt = m_mEnemyList.begin(); mapIt != m_mEnemyList.end(); mapIt++)
	{
		for (list<Enemy>::iterator it = mapIt->second.begin(); it != mapIt->second.end(); it++)
			it->Update();
	}

	// Check for collisions
	CollisionChecks();

	// Check for player death
	if (m_PlayerList[0].GetHealth() == 0)
		a_opGame->ChangeState(DeathState::Instance());
}

void PlayState::Draw(GameEngine* a_opGame)
{
	// reference project calls SDL_BlitSurface(bg, NULL, game->screen, NULL);
	//						   SDL_UpdateRect(game->screen, 0, 0, 0, 0);
	// ^^ probably irrelevant??

	// draw Environment objects
	for (vector<EnvironmentObj>::iterator it = m_EnvironList.begin(); it != m_EnvironList.end(); it++)
	{
		it->Draw();
	}

	// draw Player objects
	for (vector<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		it->Draw();
	}

	// draw Enemy objects
	for (map < string, list<Enemy> >::iterator mapIt = m_mEnemyList.begin(); mapIt != m_mEnemyList.end(); mapIt++)
	{
		for (list<Enemy>::iterator it = mapIt->second.begin(); it != mapIt->second.end(); it++)
			it->Draw();
	}

	// draw player health
	static char c_PlayerHealth[4] = {'\n'};
	//// load string
	sprintf(c_PlayerHealth, "%d", m_PlayerList[0].GetHealth());
	//// draw the string
	DrawString(c_PlayerHealth, 950, 700, SColour(0,0,0,255));
}

// initializes enemy objects
void PlayState::InitEnemies()
{
	// Enemy Type A Group 1
	for (int i=0; i<5; i++)
	{
		Enemy oEnemyA1("EnemyA1", 40, 70, HOLDING_AREA, ZERO_VELOCITY, 1, false, "./images/EnemyA.png");
		m_EnemyA1List.push_back(oEnemyA1);
	}

	m_mEnemyList["EnemyA1"] = m_EnemyA1List;

	// Enemy Type A Group 2
	for (int i=0; i<5; i++)
	{
		Enemy oEnemyA2("EnemyA2", 40, 70, HOLDING_AREA, ZERO_VELOCITY, 1, false, "./images/EnemyA.png");
		m_EnemyA2List.push_back(oEnemyA2);
	}

	m_mEnemyList["EnemyA2"] = m_EnemyA2List;

	// Enemy Type A Group 3
	for (int i=0; i<7; i++)
	{
		Enemy oEnemyA3("EnemyA3", 40, 70, HOLDING_AREA, ZERO_VELOCITY, 1, false, "./images/EnemyA.png");
		m_EnemyA3List.push_back(oEnemyA3);
	}

	m_mEnemyList["EnemyA3"] = m_EnemyA3List;
}

// triggers enemy spawns based on player's distance from level start
void PlayState::EnemySpawnCheck()
{
	EnvironmentObj& orBG = m_EnvironList[0];
	Player& orPlayer = m_PlayerList[0];

	list<Enemy>& A1 = m_mEnemyList.at("EnemyA1");
	list<Enemy>& A2 = m_mEnemyList.at("EnemyA2");
	list<Enemy>& A3 = m_mEnemyList.at("EnemyA3");

	// Group A1
	//// if the bottom of the background image passes through the 4000th pixel
	if (orBG.GetEdge(BOTTOM) > 4000 && orBG.GetEdge(BOTTOM) < 4001)
	{
		Vector2D startPos(100,-50), offset(100,0), velocity(0, 0.2);

		// trigger first group
		for (list<Enemy>::iterator it = A1.begin(); it != A1.end(); it++)
		{
			it->Spawn(startPos, velocity);
			startPos += offset;
		}
	}

	// Group A2
	if (orBG.GetEdge(BOTTOM) > 4500 && orBG.GetEdge(BOTTOM) < 4501)
	{
		Vector2D startPos(1000,-50), offset(-100,0), velocity(-0.25, 0.2);

		// trigger second group
		for (list<Enemy>::iterator it = A2.begin(); it != A2.end(); it++)
		{
			it->Spawn(startPos, velocity);
			startPos += offset;
		}
	}

	// Group A3
	if (orBG.GetEdge(BOTTOM) > 5000 && orBG.GetEdge(BOTTOM) < 5001)
	{
		Vector2D startPos(50,-50), offset(100,0), velocity(0.25, 0.2);

		// trigger second group
		for (list<Enemy>::iterator it = A3.begin(); it != A3.end(); it++)
		{
			it->Spawn(startPos, velocity);
			startPos += offset;
		}
	}
}

// Check for collisions
void PlayState::CollisionChecks()
{
	// check Player's projectile collisions
	//// iterate through vector of player objects
	for (vector<Player>::iterator it = m_PlayerList.begin(); it != m_PlayerList.end(); it++)
	{
		// iterate through player's projectiles
		for (int i=0; i<20; i++)
		{
			Projectile& orCurrentProj = it->GetProjectiles()[i];

			// if projectile is alive
			if (orCurrentProj.IsAlive())
			{
				// iterate through master map of enemy lists
				for (map < string, list<Enemy> >::iterator mapIt = m_mEnemyList.begin(); mapIt != m_mEnemyList.end(); mapIt++)
				{
					// iterate through list of enemy objects
					for (list<Enemy>::iterator it = mapIt->second.begin(); it != mapIt->second.end(); it++)
					{	
						// if the enemy object is colliding with the current projectile:
						if (it->IsCollidingWith(&orCurrentProj))
						{
							orCurrentProj.Die();	// kill projectile
							it->Die();				// kill enemy
						}
					}
				}
			}
		}
	}

	// check Enemy's projectile collisions
	//// iterate through master map of enemy lists
	for (map < string, list<Enemy> >::iterator mapIt = m_mEnemyList.begin(); mapIt != m_mEnemyList.end(); mapIt++)
	{
		// iterate through list of enemy objects
		for (list<Enemy>::iterator it = mapIt->second.begin(); it != mapIt->second.end(); it++)
		{
			// iterate through enemy's projectiles
			for (int i=0; i<20; i++)
			{
				Projectile& orCurrentProj = it->GetProjectiles()[i];

				// if projectile is colliding with player
				if (orCurrentProj.IsAlive() && orCurrentProj.IsCollidingWith(&m_PlayerList[0]))
				{
					orCurrentProj.Die();		// kill projectile
					m_PlayerList[0].SetHealth(-1);	// reduce player's health
				}
			}
		}
	}
}

PlayState* PlayState::Instance()
{
	return &m_PlayState;
}
