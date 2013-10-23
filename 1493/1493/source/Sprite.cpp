///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Sprite.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Movable Object Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
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
	
	m_iSpriteId = CreateSprite(m_cpTextureName, m_fWidth, m_fHeight, true);  //delete?
}
// constructor that takes in values
Sprite::Sprite(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition,
							 float a_fXvelocity, float a_fYvelocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName)
{
	SetType(a_cNewType);
	m_fWidth = a_fWidth;
	m_fHeight = a_fHeight;
	m_oPosition = Vector2D(a_fXposition, a_fYposition); // check on these **
	m_oVelocity = Vector2D(a_fXvelocity, a_fYvelocity);
	m_fMoveFactor = a_fMoveFactor;
	//m_iSpriteId = -1;	//**figure out where to initialize/check for this
	m_iAmmoSlot = 0;
	m_bAlive = a_bAlive;
	m_cpTextureName = a_cpTextureName;

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
	strcpy(m_cType,a_cNewType);
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

// returns the increment by which a sprite will move
float& Sprite::GetMoveFactor()
{
	return m_fMoveFactor;
}