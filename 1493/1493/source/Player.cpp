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
Player::Player(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_position, 
			   Vector2D a_velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_position, a_velocity, a_fMoveFactor, 
					   a_bAlive, a_cpTextureName)
{
	bool m_bFired = false;

	for (int i=0; i<=20; i++)
	{
		m_aProjectiles[i] = Sprite("Projectile", 10, 10, HOLDING_AREA, ZERO_VELOCITY, 1, true, "./images/cannonBall.png");
	}
}

// destructor
Player::~Player()
{

}

// checks for input from user and initiates appropriate action
void Player::Input()
{
	// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
	if (IsKeyDown('W') || IsKeyDown(GLFW_KEY_UP))
	{
		GetPosition().SetY(GetPosition().GetY() - GetMoveFactor());
	}
	if (IsKeyDown('S') || IsKeyDown(GLFW_KEY_DOWN))
	{
		GetPosition().SetY(GetPosition().GetY() + GetMoveFactor());
	}
	if (IsKeyDown('A') || IsKeyDown(GLFW_KEY_LEFT))
	{
		GetPosition().SetX(GetPosition().GetX() - GetMoveFactor());
	}
	if (IsKeyDown('D') || IsKeyDown(GLFW_KEY_RIGHT))
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

// checks for fire button and triggers projectile sprites
void Player::CheckFire(double a_dDeltaTime)
{
	// set minimum waiting time between shots (while button held down)
	double threshold = 0.25; 

	// if the fire key is released, allow another successive shot 
		if (glfwGetKey(',') == GLFW_RELEASE)
		{
			m_bFired = false;
			m_dTimeWaited = 0;
		}

	// if 
	if (m_bFired)
	{
		// add the delta time to the total time since the last shot
		m_dTimeWaited += a_dDeltaTime;

		// if the time since the last shot is greater than the threshold
		if (m_dTimeWaited >= threshold)
		{
			m_bFired = false;
			m_dTimeWaited = 0;
		}
	}
	// cycle the rotating ammo slot
	if (m_iAmmoSlot > 20)
			m_iAmmoSlot = 0;

	if (IsKeyDown(','))
	{
		if (!m_bFired)
		{
			m_aProjectiles[m_iAmmoSlot].m_bAlive = true; //fix
			m_bFired = true;
			m_iAmmoSlot += 1;
		}
	}
}