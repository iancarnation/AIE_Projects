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
Player::Player(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_Position, a_Velocity, a_fMoveFactor, 
					   a_bAlive, a_cpTextureName)
{
	m_bFiring = false;
	m_dTimeWaited = 0;

	for (int i=0; i<20; i++)
	{
		m_aProjectiles[i] = Projectile("Projectile", 10, 10, HOLDING_AREA, ZERO_VELOCITY, 2, false, "./images/cannonBall.png");
	}
}

// destructor
Player::~Player()
{

}

// checks for input from user and initiates appropriate action
void Player::Input()
{
	Movement();
	Abilities(GetDeltaTime());
}

void Player::Update()
{
	Input();
	Sprite::Update();
	UpdateProjectiles(m_oPosition);
}

void Player::Draw()
{
	Sprite::Draw();
	DrawProjectiles();
}

// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
void Player::Movement()
{
	// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
	if (IsKeyDown('W') || IsKeyDown(GLFW_KEY_UP))
	{
		m_oPosition.SetY(m_oPosition.GetY() - m_fMoveFactor);
	}
	if (IsKeyDown('S') || IsKeyDown(GLFW_KEY_DOWN))
	{
		m_oPosition.SetY(m_oPosition.GetY() + m_fMoveFactor);
	}
	if (IsKeyDown('A') || IsKeyDown(GLFW_KEY_LEFT))
	{
		m_oPosition.SetX(m_oPosition.GetX() - m_fMoveFactor);
	}
	if (IsKeyDown('D') || IsKeyDown(GLFW_KEY_RIGHT))
	{
		m_oPosition.SetX(m_oPosition.GetX() + m_fMoveFactor);
	}
}

// check for fire input / firing timing control 
void Player::Abilities(double a_dDeltaTime)
{
	// set minimum waiting time between shots (while button held down)
	double threshold = 0.1; 
	bool reset = false;


	if (IsKeyDown(','))
	{
		if (!m_bFiring)
		{
			Projectile& orCurrentProj = m_aProjectiles[m_iAmmoSlot];

			orCurrentProj.SetAlive(true);
			orCurrentProj.SetPosition(m_oPosition);		// projectile's position is current player's position
			orCurrentProj.GetVelocity().SetY(- orCurrentProj.GetMoveFactor());		// projectile has upward Y velocity
			m_bFiring = true;
			m_iAmmoSlot += 1;
			//reset = true;
		}
	}

	// if 
	if (m_bFiring)
	{
		// add the delta time to the total time since the last shot
		m_dTimeWaited += a_dDeltaTime;

		// if the time since the last shot is greater than the threshold
		if (m_dTimeWaited >= threshold)
		{
			m_bFiring = false;
			m_dTimeWaited = 0;
		}
	}
	// cycle the rotating ammo slot
	if (m_iAmmoSlot == 19)
			m_iAmmoSlot = 0;

		// if the fire key is released, allow another successive shot 
	//if(reset)	
	/*if (glfwGetKey(',') == GLFW_RELEASE)
		{
			m_bFiring = false;
			m_dTimeWaited = 0;
			reset = false;
		}*/
}

// checks if projectile has been triggered or moved off screen and moves it accordingly
void Player::UpdateProjectiles(Vector2D& a_oPosition)
{
	for (int i=0; i<20; i++)
	{
		if (m_aProjectiles[i].IsAlive())
			m_aProjectiles[i].Update(a_oPosition);
	}
}

// checks if projectile has been triggered or moved off screen and moves it accordingly
void Player::DrawProjectiles()
{
	for (int i=0; i<20; i++)
	{
		if (m_aProjectiles[i].IsAlive())
			m_aProjectiles[i].Draw();
	}
}