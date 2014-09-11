#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include "AIE.h"
//#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <GL/glfw.h>

struct vector2d
{
	float x;
	float y;
};

//
struct movableObject
{
	int width;
	int height;
	vector2d position;
	vector2d velocity;
	int sprite;
	bool alive;
	int ammoSlot;
};

// enumeration scheme for main game loop switch statement
typedef enum GAME_STATE
{
	GAME_STATE_MENU,
	GAME_STATE_PLAY,
	GAME_STATE_WIN,
	GAME_STATE_LOSE,
	GAME_STATE_SHUTDOWN,
};

// function prototypes

////////////////////////////////////////////////
//         Main Loop Functions                //
////////////////////////////////////////////////
void initGame();
void destroyGame();
void updateGame();
void drawGame();

////////////////////////////////////////////////
//         Game State Functions               //
////////////////////////////////////////////////
// functions used to control individual game state loops nested within the main loop
// functions take in a reference to the currentState variable of the main game loop's switch statement

// &&&&&&&&&&& Game State: Menu &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// main menu, should have start, exit, and high score selections
void mainMenu(GAME_STATE &currentState);

// &&&&&&&&&&& Game State: Play &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// checks if the player has won, takes in and modifies currentState accordingly
void checkPlayerWin(GAME_STATE &currentState);
// updates game logic
void updateGame();
// draws each frame of the game
void drawGame();

// &&&&&&&&&&& Game State: Win &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// displays a win screen, provides menu options and modifies currentState accordingly
void winScreen(GAME_STATE &currentState);

// &&&&&&&&&&& Game State: Lose &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// displays a lose screen, provides menu options and modifies currentState accordingly
void loseScreen(GAME_STATE &currentState);

// &&&&&&&&&&& Game State: Shut Down &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// destroy all the sprites and clean up any memory
void destroyGame();

/////////////////////////////////////////
//      Functions to Move Stuff        //
/////////////////////////////////////////

// uses IsKeyDown function of framework for moving player with keyboard
void playerMovement(movableObject &player);
// checks for fire button and triggers projectile sprites
void checkFire(movableObject &player, double time);
// fills an array of with objects of type projectile
void genProjectileArray(movableObject *projArray);
// checks if projectile has been triggered or moved off screen and moves it accordingly
void updateProjectiles(movableObject *projArray);

/////////////////////////////////////////
//      Utility Functions              //
/////////////////////////////////////////
vector2d vectorAdd(vector2d &v, vector2d &v2);
void drawSpriteArray(movableObject *spriteArray);
void moveSpriteArray(movableObject *spriteArray);


#endif