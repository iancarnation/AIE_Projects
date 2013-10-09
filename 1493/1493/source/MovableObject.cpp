///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			MovableObject.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Movable Object Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include "MovableObject.h"

// default constructor
MovableObject::MovableObject()
{
	SetType("Default");
	m_fWidth = 10;
	m_fHeight = 10;
	m_oPosition = Vector2D();
	m_oVelocity = Vector2D();
	m_iSprite = -1;
	m_iAmmoSlot = 0;
	m_bAlive = false;
	m_sTextureFile = "";
	
}

// default constructor with type name provided
MovableObject::MovableObject(char *a_cNewType)
{
	SetType(a_cNewType);
	m_fWidth = 10;
	m_fHeight = 10;
	m_oPosition = Vector2D();
	m_oVelocity = Vector2D();
	m_iSprite = -1;
	m_iAmmoSlot = 0;
	m_bAlive = false;
	m_sTextureFile = "";
	
}
// constructor that takes in values
MovableObject::MovableObject(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition,
							 float a_fXvelocity, float a_fYvelocity, bool a_bAlive, string a_sTextureFile)
{
	SetType(a_cNewType);
	m_fWidth = a_fWidth;
	m_fHeight = a_fHeight;
	m_oPosition = Vector2D(a_fXposition, a_fYposition); // check on these **
	m_oVelocity = Vector2D(a_fXvelocity, a_fYvelocity);
	m_iSprite = -1;	
	m_iAmmoSlot = 0;
	m_bAlive = a_bAlive;
	m_sTextureFile = a_sTextureFile;
}

// calls the DrawSprite function from the AIE Framework
void MovableObject::Draw()
{
	DrawSprite(this->m_iSprite);
}

// calls the MoveSprite function from the AIE Framework
void MovableObject::Move()
{
	MoveSprite(this->m_iSprite, this->m_oPosition.GetX(), this->m_oPosition.GetY());
}

// calls the DrawSprite function from the AIE Framework
void MovableObject::Destroy()
{
	DestroySprite(this->m_iSprite);
}

// gives the object a 'type' name as a char array
void MovableObject::SetType(char *a_cNewType)
{
	// copy NewType into m_cType
	strcpy(m_cType,a_cNewType);
}

// returns the 'type' as a char array
char* MovableObject::GetType()
{
	return this->m_cType;
}