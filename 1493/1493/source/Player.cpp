///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Player.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Player Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include "KeyCodes.h"
#include "Player.h"

// default constructor
Player::Player()
{

}

// constructor with parameters
Player::Player(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition, 
			   float a_fXvelocity, float a_fYvelocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_fXposition, a_fYposition, 
					   a_fXvelocity, a_fYvelocity, a_fMoveFactor, a_bAlive, a_cpTextureName)
{
	
}

// destructor
Player::~Player()
{

}

// checks for input from user and initiates appropriate action
void Player::Input()
{
	// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
	if (IsKeyDown('W'))
	{
		GetPosition().SetY(GetPosition().GetY() - GetMoveFactor());
	}
	if (IsKeyDown('S'))
	{
		GetPosition().SetY(GetPosition().GetY() + GetMoveFactor());
	}
	if (IsKeyDown('A'))
	{
		GetPosition().SetX(GetPosition().GetX() - GetMoveFactor());
	}
	if (IsKeyDown('D'))
	{
		GetPosition().SetX(GetPosition().GetX() + GetMoveFactor());
	}

}

void Player::Update()
{
	Input();
	Sprite::Update();
}

void Player::Draw()
{
	Sprite::Draw();
}