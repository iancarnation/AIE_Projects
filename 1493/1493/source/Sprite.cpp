///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Sprite.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Sprite (Renderable/Movable) Object Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Sprite.h"

// default constructor
Sprite::Sprite()
{
	SetType("Default");
	m_fWidth = 10;
	m_fHeight = 10;
	m_oPosition = Vector2D();
	m_oVelocity = Vector2D();
	m_fMoveFactor = 1;
	m_iSpriteId = -1; //**figure out where to initialize/check for this
	m_iAmmoSlot = 0;
	m_bAlive = false;
	m_cpTextureName = "";
	m_dDeltaTime = GetDeltaTime();

	m_fTop = m_oPosition.GetY() - (m_fHeight / 2);
	m_fBottom = m_oPosition.GetY() + (m_fHeight / 2);
	m_fLeft = m_oPosition.GetX() - (m_fWidth / 2);
	m_fRight = m_oPosition.GetX() + (m_fWidth / 2);
}

// default constructor with type name provided
Sprite::Sprite(char *a_cNewType)
{
	SetType(a_cNewType);
	m_fWidth = 10;
	m_fHeight = 10;
	m_oPosition = Vector2D();
	m_oVelocity = Vector2D();
	m_fMoveFactor = 1;
	//m_iSpriteId = -1; //**figure out where to initialize/check for this
	m_iAmmoSlot = 0;
	m_bAlive = false;
	m_cpTextureName = "";
	m_dDeltaTime = GetDeltaTime();

	m_fTop = m_oPosition.GetY() - (m_fHeight / 2);
	m_fBottom = m_oPosition.GetY() + (m_fHeight / 2);
	m_fLeft = m_oPosition.GetX() - (m_fWidth / 2);
	m_fRight = m_oPosition.GetX() + (m_fWidth / 2);

	m_iSpriteId = CreateSprite(m_cpTextureName, m_fWidth, m_fHeight, true);  //delete?
}
// constructor that takes in values
Sprite::Sprite(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
{
	SetType(a_cNewType);
	m_fWidth = a_fWidth;
	m_fHeight = a_fHeight;
	m_oPosition = a_Position; // check on these **
	m_oVelocity = a_Velocity;
	m_fMoveFactor = a_fMoveFactor;
	//m_iSpriteId = -1;	//**figure out where to initialize/check for this
	m_iAmmoSlot = 0;
	m_bAlive = a_bAlive;
	m_cpTextureName = a_cpTextureName;
	m_dDeltaTime = GetDeltaTime();

	m_fTop = m_oPosition.GetY() - (m_fHeight / 2);
	m_fBottom = m_oPosition.GetY() + (m_fHeight / 2);
	m_fLeft = m_oPosition.GetX() - (m_fWidth / 2);
	m_fRight = m_oPosition.GetX() + (m_fWidth / 2);

	m_iSpriteId = CreateSprite(m_cpTextureName, m_fWidth, m_fHeight, true); //delete?
	
}

// destructor
Sprite::~Sprite ()
{
	//cout<< "Vector Destroyed, Muhahah!\n";
}

// run functions for changing state of objects
void Sprite::Update()
{
	Move();
}

// calls the MoveSprite function from the AIE Framework
void Sprite::Move()
{
	MoveSprite(m_iSpriteId, m_oPosition.GetX(), m_oPosition.GetY());
}

// calls the DrawSprite function from the AIE Framework
void Sprite::Draw()
{
	DrawSprite(m_iSpriteId);
}

// calls the DrawSprite function from the AIE Framework
void Sprite::Destroy()
{
	DestroySprite(m_iSpriteId);
}

// returns the 'type' as a char array
char* Sprite::GetType()
{
	return m_cType;
}

// gives the object a 'type' name as a char array
void Sprite::SetType(char *a_cNewType)
{
	// copy NewType into m_cType
	strcpy_s(m_cType,a_cNewType);
}

int& Sprite::GetSpriteId()
{
	return m_iSpriteId;
}

// returns the position vector
Vector2D& Sprite::GetPosition()
{
	return m_oPosition;
}

// returns the velocity vector
Vector2D& Sprite::GetVelocity()
{
	return m_oVelocity;
}

void Sprite::SetPosition(Vector2D a_oPos)
{
	m_oPosition = a_oPos;
}

void Sprite::SetVelocity(Vector2D a_oVel)
{
	m_oVelocity = a_oVel;
}

// returns the increment by which a sprite will move
float& Sprite::GetMoveFactor()
{
	return m_fMoveFactor;
}

// returns whether the sprite is "alive"(visible) or not
bool Sprite::IsAlive()
{
	return m_bAlive;
}

// changes "alive" marker
void Sprite::SetAlive(bool a_bValue)
{
	m_bAlive = a_bValue;
}

float& Sprite::GetEdge(Boundary a_edge)
{
	switch(a_edge)
	{
	case TOP:
		return m_fTop;
		break;
	case BOTTOM:
		return m_fBottom;
		break;
	case LEFT:
		return m_fLeft;
		break;
	case RIGHT:
		return m_fRight;
		break;
	};
}

// updates the values of object boundaries
void Sprite::UpdateEdges()
{
	m_fTop = m_oPosition.GetY() - (m_fHeight / 2);
	m_fBottom = m_oPosition.GetY() + (m_fHeight / 2);
	m_fLeft = m_oPosition.GetX() - (m_fWidth / 2);
	m_fRight = m_oPosition.GetX() + (m_fWidth / 2);
}

// is sprite on screen?
bool Sprite::IsOnScreen()
{
	if (m_fTop > 0 && m_fBottom < SCREEN_Y && m_fLeft > 0 && m_fRight < SCREEN_X)
		return true;
	else
		return false;
}