///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Player.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Player Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Player.h"

// default constructor
Player::Player()
{

}

// constructor with parameters
Player::Player(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition, 
			   float a_fXvelocity, float a_fYvelocity, bool a_bAlive, const char* a_cpTextureName)
{
	Sprite (a_cNewType, a_fWidth, a_fHeight, a_fXposition, a_fYposition, 
			a_fXvelocity, a_fYvelocity, a_bAlive, a_cpTextureName);
}

// destructor
Player::~Player()
{

}

//// checks for input from user and initiates appropriate action
//void Player::PlayerInput()
//{
//	if (IsKeyDown('Q'))
//		{
//			a_opGame->Quit();
//		}
//	if (IsKeyDown(GLFW_KEY_ESC))
//		{
//			a_opGame->PopState();
//		}
//}