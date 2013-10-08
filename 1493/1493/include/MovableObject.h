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
	public:
		MovableObject();	// default constructor
		MovableObject(float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition, float a_fXvelocity, float a_fYelocity, bool a_bAlive);	// constructor with **something** provided?
		~ MovableObject();	// destructor

		void Draw();		// calls the DrawSprite function from the AIE Framework
		void Move();		// calls the MoveSprite function from the AIE Framework
		void Destroy();		// calls the DestroySprite function from the AIE Framework

	private:
		float m_fWidth, m_fHeight;
		int m_iSprite;
		int m_iAmmoSlot;
		bool m_bAlive;
		Vector2D m_oPosition;
		Vector2D m_oVelocity;

};

#endif