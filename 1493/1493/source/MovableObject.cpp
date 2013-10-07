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
	width = 10;
	height = 10;
	sprite = -1;
	ammoSlot = 0;
	alive = false;
	position = Vector2D();
	velocity = Vector2D();
}

// constructor that takes in values
// not sure if I need this???
MovableObject::MovableObject (float width, float height, bool alive, Vector2D position, Vector2D velocity)
{
	width = width;
	height = height;
	sprite = -1;	
	ammoSlot = 0;
	alive = alive;
	position = position; // check on these **
	velocity = velocity;
}

// calls the DrawSprite function from the AIE Framework
void MovableObject::Draw()
{
	DrawSprite(this->sprite);
}

// calls the MoveSprite function from the AIE Framework
void MovableObject::Move()
{
	MoveSprite(this->sprite, this->position.GetX(), this->position.GetY());
}

// calls the DrawSprite function from the AIE Framework
void MovableObject::Destroy()
{
	DestroySprite(this->sprite);
}