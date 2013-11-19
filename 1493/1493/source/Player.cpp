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
			   Vector2D a_Velocity, Vector2D a_Force, float a_fMass, float a_fMovementForce, bool a_bAlive, const char* a_cpTextureName, float a_fSheetSlices)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_Position, a_Velocity, a_Force, a_fMass, a_fMovementForce, 
					   a_bAlive, a_cpTextureName, a_fSheetSlices)
{
	m_bFiring = false;
	m_dTimeWaited = 0;
	m_iHealth = 100;

	for (int i=0; i<20; i++)
	{
		m_aProjectiles[i] = Projectile("Arrow", 5, 30, HOLDING_AREA, ZERO_VELOCITY, Vector2D(), 200, 1, false, "./images/arrow.png", 1);
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
	Abilities();
}

void Player::Update(double dt)
{
	dTime = dt;
	Input();
	//physics calculation
	Physics();
	UpdateEdges();
	ScreenCollision();
	Sprite::Update();
	UpdateProjectiles();

}

void Player::Draw()
{
	Sprite::Draw();
	DrawProjectiles();

	// draw player velocity
	static char c_PlayerVel[4] = {'\n'};
	//// load string
	sprintf(c_PlayerVel, "Velocity: %f, %f", GetVelocity().m_fX, GetVelocity().m_fY);
	//// draw the string
	DrawString(c_PlayerVel, 80, 700, SColour(0,0,0,255));
}

// returns player health
int Player::GetHealth() const
{
	return m_iHealth;
}

// changes player's health by given amount
void Player::SetHealth(int a_iAmt)
{
	m_iHealth += a_iAmt;
	// change health display
}

// returns projectile array
Projectile* Player::GetProjectiles()
{
	return m_aProjectiles;
}

// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
void Player::Movement()
{
	// player movement: gets the relevant position value and adjusts it by its "MovementFactor"
	if (IsKeyDown('W') || IsKeyDown(GLFW_KEY_UP))
	{
		m_oForce.m_fY -= m_fMovementForce;
	}

	if (IsKeyDown('S') || IsKeyDown(GLFW_KEY_DOWN))
	{
		m_oForce.m_fY += m_fMovementForce;
	}
	if (IsKeyDown('A') || IsKeyDown(GLFW_KEY_LEFT))
	{
		m_oForce.m_fX -= m_fMovementForce;
		SetUV(0);
	}
	else if (glfwGetKey('A') == GLFW_RELEASE)
		SetUV(1);

	if (IsKeyDown('D') || IsKeyDown(GLFW_KEY_RIGHT))
	{
		m_oForce.m_fX += m_fMovementForce;
		SetUV(2);
	}
	/*else if (glfwGetKey('D') == GLFW_RELEASE)
		SetSpriteUVCoordinates(m_iSpriteId, 0.33, 0, 0.66, 1);	*/// doesn't work in conjunction with the 'A' release check ??


	///  -------------------  Test Control Scheme 2 -------------------------------------------

}

// check for fire input / firing timing control 
void Player::Abilities()
{
	// set minimum waiting time between shots (while button held down)
	double threshold = 0.1;

	if (IsKeyDown(','))
	{
		if (!m_bFiring)
		{
			Projectile& orCurrentProj = m_aProjectiles[m_iAmmoSlot];

			orCurrentProj.SetAlive(true);
			orCurrentProj.SetPosition(m_oPosition);		// projectile's position is current player's position
			orCurrentProj.GetVelocity().m_fY -= orCurrentProj.GetMoveFactor();		// projectile has upward Y velocity
			m_bFiring = true;
			m_iAmmoSlot += 1;
			//reset = true;
		}
	}

	// if 
	if (m_bFiring)
	{
		// add the delta time to the total time since the last shot
		m_dTimeWaited += dTime;

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
void Player::UpdateProjectiles()
{
	for (int i=0; i<20; i++)
	{
		if (m_aProjectiles[i].IsAlive())
			m_aProjectiles[i].Update(dTime);
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

// physics calculation / limit checks
void Player::Physics()
{
	m_oPosition += m_oVelocity * dTime;
	m_oVelocity += (m_oForce / m_fMass) * dTime;
	m_oVelocity *= DRAG;
	m_oForce *= DRAG;
	m_oForce.CapAtMax(15 * m_fMovementForce);

//	m_oVelocity.Truncate(2);
}

// checks for screen edge collision, keep player on screen
void Player::ScreenCollision()
{
	if (m_fTop < 0)
	{
		m_oForce.m_fY = 0;
		m_oVelocity.m_fY = 0;
		m_oPosition.m_fY = m_fHeight / 2;
	}
	if (m_fBottom > SCREEN_Y)
	{
		m_oForce.m_fY = 0;
		m_oVelocity.m_fY = 0;
		m_oPosition.m_fY = SCREEN_Y - m_fHeight / 2;
	}
	if (m_fLeft < 0)
	{
		m_oForce.m_fX = 0;
		m_oVelocity.m_fX = 0;
		m_oPosition.m_fX = m_fWidth / 2;
	}
	if (m_fRight > SCREEN_X)
	{
		m_oForce.m_fX = 0;
		m_oVelocity.m_fX = 0;
		m_oPosition.m_fX = SCREEN_X - m_fWidth / 2;
	}
}