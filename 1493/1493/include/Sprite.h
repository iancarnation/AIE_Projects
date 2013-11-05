///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Sprite.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			Sprite (Renderable/Movable) Object Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "AIE.h"
#include "KeyCodes.h"
#include "Vector2D.h"
#include "StaticConstants.h"
#include <string>
#include <math.h>

//#include <GL/glfw.h>

using namespace std;

class Sprite
{
	public:
		Sprite();					// default constructor
		Sprite(char *a_cNewType);	// default constructor with type name provided
		Sprite(char *a_cNewType, float a_fWidth, float a_fHeight, Vector2D a_Position, 
			   Vector2D a_Velocity, float a_fMoveFactor, bool a_bAlive, const char* a_cpTextureName);	// constructor with **something** provided?
		virtual ~ Sprite();					// destructor

		virtual void Update();		// run functions for changing state of objects
		void Move();				// calls the MoveSprite function from the AIE Framework
		void Draw();				// calls the DrawSprite function from the AIE Framework
		void Destroy();				// calls the DestroySprite function from the AIE Framework
		
		char* GetType();			// returns the 'type' as char array
		void SetType(char *a_cNewType);		// gives the object a 'type' name as a char array
		int& GetSpriteId();			 // returns the sprite ID
		Vector2D& GetPosition();	// returns the position vector
		Vector2D& GetVelocity();	// returns the velocity vector
		void SetPosition(Vector2D a_oPos);
		void SetVelocity(Vector2D a_oVel);
		void SetVelocityToward(const Vector2D a_rV2);		// calculates velocity for going towards a certain vector

		float& GetMoveFactor();		// returns the increment by which a sprite will move
		bool IsAlive();				// returns whether the sprite is "alive"(visible) or not
		void SetAlive(bool a_bValue);		// changes "alive" marker
		float& GetEdge(Boundary edge);		// returns an object's edge value
		void UpdateEdges();			// updates the values of object boundaries
		bool IsOnScreen();			// is object on the screen?
		bool IsCollidingWith(Sprite* a_sprite2);	// sprite collision
		void Die();		// "kills" projectile and returns it to holding area

	protected:
		char m_cType[20];
		float m_fWidth, m_fHeight;
		int m_iSpriteId;
		int m_iAmmoSlot;
		bool m_bAlive;
		Vector2D m_oPosition;
		Vector2D m_oVelocity;
		float m_fMoveFactor;
		const char* m_cpTextureName;

		float m_fTop, m_fBottom, m_fLeft, m_fRight;

		double m_dDeltaTime;
};

#endif
