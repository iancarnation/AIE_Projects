///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			EnvironmentObj.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			EnvironmentObj Class, inherits from Sprite Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "EnvironmentObj.h"

// default constructor
EnvironmentObj::EnvironmentObj()
{

}

// constructor with parameters
EnvironmentObj::EnvironmentObj(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
			 : Sprite (a_cNewType, a_fWidth, a_fHeight, a_Position, a_Velocity, a_fMoveFactor, 
					   a_bAlive, a_cpTextureName)
{

}

// destructor
EnvironmentObj::~EnvironmentObj()
{

}

void EnvironmentObj::Update()
{
	m_oPosition += m_oVelocity;
	Sprite::Update();
}

void EnvironmentObj::Draw()
{
	Sprite::Draw();
}