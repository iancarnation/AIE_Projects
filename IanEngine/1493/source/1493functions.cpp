///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			1493funtions.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			A SHMUP game based on the Capcom game, "1943: The Battle of Midway"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "1493functions.h"

// global variables 
movableObject player = {PLAYER_W, PLAYER_H, PLAYER_X, PLAYER_Y, 0, 0, -1, true, 0};
movableObject a_cBalls[20];

double timeWaited = 0.0;
bool fired = false;

// declare sprite identifier variables
unsigned int bgImage = -1;
unsigned int menuImage = -1;
unsigned int loseImage = -1;
unsigned int winImage = -1;

// int iPlayer1Score = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         Main Game Functions         ////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Initialize all game variables
void initGame()
{
	srand(time(0));	

	// Initialize game objects
	genProjectileArray(a_cBalls);

	// enemy a_enemy[3]; 

	// Load sprites using CreateSprite() function

	// add menu
	/*menuImage = CreateSprite("./images/menu.png", SCREEN_X, SCREEN_Y, true);
	MoveSprite(menuImage, SCREEN_X>>1, SCREEN_Y>>1);

	winImage = CreateSprite("./images/winImage1.png", SCREEN_X, SCREEN_Y, true);
	MoveSprite(winImage1, SCREEN_X>>1, SCREEN_Y>>1);

	loseImage = CreateSprite("./images/winImage2.png", SCREEN_X, SCREEN_Y, true);
	MoveSprite(winImage2, SCREEN_X>>1, SCREEN_Y>>1);*/


	// add background, then center it
	bgImage = CreateSprite("./images/bgImage.png", SCREEN_X, SCREEN_Y, true);
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);
	
	// add player and player projectiles
	player.sprite = CreateSprite( "./images/playerImage.png", PLAYER_W, PLAYER_H, true );

	
	// add enemies
}
// &&&&&&&&&&& Game State: Menu &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// main menu, should have start, exit, and high score selections
void mainMenu(GAME_STATE &currentState)
{
	DrawSprite(menuImage);

		if (IsKeyDown(GLFW_KEY_ENTER))
		{
			currentState = GAME_STATE_PLAY;
		}
		else if (IsKeyDown('Q'))
		{
			currentState = GAME_STATE_SHUTDOWN;
		}
}

// &&&&&&&&&&& Game State: Play &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// checks if the player has won, takes in and modifies currentState with a reference
void checkPlayerWin(GAME_STATE &currentState)
{
	/*if (iPlayer1Score == 10)
		{
			currentState = GAME_STATE_P1WIN;
		}
	else if (iPlayer2Score == 10)
		{
			currentState = GAME_STATE_P2WIN;
		}*/
}

// updates game logic
void updateGame()
{
	double dTime = GetDeltaTime();
	//check if player is attacking
	checkFire(player, dTime);
	// update player position 
	playerMovement(player);
	// update projectiles
	updateProjectiles(a_cBalls);
	// test for player screen collision

	// move sprites
	MoveSprite(player.sprite, player.position.x, player.position.y);
	moveSpriteArray(a_cBalls);
}

// draws each frame of the game
void drawGame()
{
	//DrawSprite(player.sprite);
	//DrawSprite(player1.sprite);
	//DrawSprite(player2.sprite);

	// draw the score

	DrawSprite(bgImage);
	DrawSprite(player.sprite);
	drawSpriteArray(a_cBalls);

}

// &&&&&&&&&&& Game State: Win &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void winScreen (GAME_STATE &currentState)
{
	//// draw screen for win state

	//// provide menu options
	//if (IsKeyDown(GLFW_KEY_ENTER))
	//{
	//	currentState = GAME_STATE_PLAY;
	//	iplayerScore = 0;
	//	iPlayer2Score = 0;
	//}
	//else if (IsKeyDown('Q'))
	//{
	//	currentState = GAME_STATE_SHUTDOWN;
	//}	
}

// &&&&&&&&&&& Game State: Lose &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void loseScreen (GAME_STATE &currentstate)
{
	// draw screen for lose state

	// provide menu options
}

// &&&&&&&&&&& Game State: Shut Down &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// destroy all the sprites and clean up any memory
void destroyGame() 
{
	DestroySprite(bgImage);
	DestroySprite(player.sprite);
	// loop through and destroy projectile arrays
	
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//      Functions to Move Stuff        /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// uses IsKeyDown function of the framework for moving player with keyboard
void playerMovement(movableObject &player)
{
	if (IsKeyDown('W'))
	{
		player.position.y -= PLAYER_MOVEMENT_FACTOR;
	}
	else if (IsKeyDown('S'))
	{
		player.position.y += PLAYER_MOVEMENT_FACTOR;
	}
	if (IsKeyDown('A'))
	{
		player.position.x -= PLAYER_MOVEMENT_FACTOR;
	}
	else if (IsKeyDown('D'))
	{
		player.position.x += PLAYER_MOVEMENT_FACTOR;
	}
}

// checks for fire button and triggers projectile sprites
void checkFire(movableObject &player, double dTime)
{
	// set minimum waiting time between shots (while button held down)
	double threshold = 0.25; 

	// if the fire key is released, allow another successive shot 
		if (glfwGetKey(',') == GLFW_RELEASE)
		{
			fired = false;
			timeWaited = 0;
		}

	// if 
	if (fired)
	{
		// add the delta time to the total time since the last shot
		timeWaited += dTime;

		// if the time since the last shot is greater than the threshold
		if (timeWaited >= threshold)
		{
			fired = false;
			timeWaited = 0;
		}
	}
	// cycle the rotating ammo slot
	if (player.ammoSlot > 20)
			player.ammoSlot = 0;

	if (IsKeyDown(','))
	{
		if (!fired)
		{
			a_cBalls[player.ammoSlot].alive = true;
			fired = true;
			player.ammoSlot += 1;
		}
	}
}

// fills an array of with objects of type projectile
void genProjectileArray(movableObject *projArray)
{
	for (int i=0; i<=20; i++)
	{
		movableObject projectile = { 20, 20, SCREEN_X + 10, 0, 0, 0, -1, false, 0};
		projectile.sprite = CreateSprite( "./images/cannonBall.png", 10, 10, true );
		projArray[i] = projectile;
	}
}

// checks if projectile has been triggered or moved off screen and moves it accordingly
void updateProjectiles(movableObject *projArray)
{
	for (int i=0; i<=20; i++)
	{
		if (projArray[i].alive)
		{
			// if the projectile has not already been launched (still in holding area where projectiles are generated)
			if (projArray[i].position.y == 0 && projArray[i].position.x == SCREEN_X+10)
			{
			projArray[i].position.x = player.position.x;	// projectile's position is player's
			projArray[i].position.y = player.position.y;	// current position
			projArray[i].velocity.y = -2;					// projectile moves up
			}

			// update projectile's position
			projArray[i].position = vectorAdd(projArray[i].position, projArray[i].velocity);
		}

		// if projectile goes off screen, it's !alive, y velocity is 0, and goes back to holding area
		if (projArray[i].position.y < 0)
		{
			projArray[i].alive = false;
			projArray[i].position.x = SCREEN_X + 10;
			projArray[i].position.y = 0;
			projArray[i].velocity.y = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//      Utility Functions       ////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// **change to DrawAllSprites()**
void drawSpriteArray(movableObject *spriteArray)
{
	for (int i=0; i<20; i++)
	{
		DrawSprite(spriteArray[i].sprite);
	}
}

// **change to MoveAllSprites**
void moveSpriteArray(movableObject *spriteArray)
{
	for (int i=0; i<20; i++)
	{
		MoveSprite(spriteArray[i].sprite, spriteArray[i].position.x, spriteArray[i].position.y);
	}
}