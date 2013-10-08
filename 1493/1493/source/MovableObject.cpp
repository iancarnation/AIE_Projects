///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			MovableObject.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Movable Object Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include "MovableObject.h"

// default constructor
MovableObject::MovableObject ()
{
	m_fWidth = 10;
	m_fHeight = 10;
	m_oPosition = Vector2D();
	m_oVelocity = Vector2D();
	m_iSprite = -1;
	m_iAmmoSlot = 0;
	m_bAlive = false;
	
}

// constructor that takes in values
MovableObject::MovableObject (float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition,
							  float a_fXvelocity, float a_fYelocity, bool a_bAlive)
{
	m_fWidth = a_fWidth;
	m_fHeight = a_fHeight;
	m_oPosition = Vector2D(a_fXposition, a_fYposition); // check on these **
	m_oVelocity = Vector2D(a_fXvelocity, a_fYelocity);
	m_iSprite = -1;	
	m_iAmmoSlot = 0;
	m_bAlive = a_bAlive;
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