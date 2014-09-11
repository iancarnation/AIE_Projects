#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#include "GameEngine.h"
#include "GameState.h"
#include "MenuState.h"
#include "Sprite.h"
#include "EnvironmentObj.h"
#include "Player.h"
#include "Enemy.h"
#include <list>
#include <map>

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
	void Update(GameEngine* a_opGame, double dt);
	// renders things to the screen
	void Draw(GameEngine* a_opGame);


	static PlayState* Instance(); //**verify that this is implemented correctly in cpp**

protected:
	PlayState();

private:
	static PlayState m_PlayState;

	vector<EnvironmentObj> m_EnvironList;
	vector<Player> m_PlayerList;
	map<string, list<Enemy>> m_mEnemyList;

	list<Enemy> m_EnemyA1List;
	list<Enemy> m_EnemyA2List;
	list<Enemy> m_EnemyA3List;

	// initializes enemy objects
	void InitEnemies();
	// triggers enemy spawns based on player's distance from level start
	void EnemySpawnCheck();
	// Check for collisions
	void CollisionChecks();
};

#endif