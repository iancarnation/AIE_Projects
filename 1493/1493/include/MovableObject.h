///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			MovableObject.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Movable Object Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _MOVABLEOBJECT_H_
#define _MOVABLEOBJECT_H_

#include "Vector2D.h"

class MovableObject
{
	private:
		float width, height;
		int sprite;
		int ammoSlot;
		bool alive;
		Vector2D position;
		Vector2D velocity;

	public:
		MovableObject();	// default constructor
		MovableObject(float width, float height, bool alive, Vector2D position, Vector2D velocity);	// constructor with **something** provided?
		~ MovableObject();	// destructor
		void Draw();		// calls the DrawSprite function from the AIE Framework
		void Move();		// calls the MoveSprite function from the AIE Framework
		void Destroy();		// calls the DestroySprite function from the AIE Framework
};

#endif