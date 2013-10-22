///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Sprite.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Movable Object Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Vector2D.h"
#include <string>
using namespace std;

class Sprite
{
	public:
		Sprite();					// default constructor
		Sprite(char *a_cNewType);	// default constructor with type name provided
		Sprite(char *a_cNewType, float a_fWidth, float a_fHeight, float a_fXposition, float a_fYposition, 
					  float a_fXvelocity, float a_fYvelocity, bool a_bAlive, const char* a_cpTextureName);	// constructor with **something** provided?
		~ Sprite();					// destructor

		void Draw();		// calls the DrawSprite function from the AIE Framework
		void Move();		// calls the MoveSprite function from the AIE Framework
		void Destroy();		// calls the DestroySprite function from the AIE Framework
		void SetType(char *a_cNewType);		// gives the object a 'type' name as a char array
		char* GetType();	// returns the 'type' as char array
		int GetSpriteId(); // returns the sprite ID

	private:
		char m_cType[20];
		float m_fWidth, m_fHeight;
		int m_iSpriteId;
		int m_iAmmoSlot;
		bool m_bAlive;
		Vector2D m_oPosition;
		Vector2D m_oVelocity;
		const char* m_cpTextureName;
};

#endif
