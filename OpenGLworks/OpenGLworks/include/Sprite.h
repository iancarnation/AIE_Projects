#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Quad.h"
#include "Vertex.h"
#include "MathLibrary.h"
#include "Utilities.h"
#include <SOIL.h>

class Sprite: public Quad
{
public:
	Sprite(void);
	~Sprite(void);
	Sprite(const char*, int, int, Vector4, GLFWwindow*);

	//unsigned int CreateSprite(const char* a_pTextureName, int a_iWidth, int a_iHeight, bool a_bDrawFromCenter = true/*, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF)*/ );
	//void MoveSprite(unsigned int a_uiSpriteID, float a_fXPos, float a_fYPos);
	//void RotateSprite(unsigned int a_uiSpriteID, float a_fRotation);
	//void DestroySprite(unsigned int a_uiSpriteID);
	//void DrawSprite(unsigned int a_uiSpriteID);
	//void SetSpriteUVCoord(unsigned int a_uiSpriteID, float a_minUCoord, float a_minVCoord, float a_maxUCoord, float a_maxVCoord);
	//void GetSpriteUVCoord(unsigned int a_uiSpriteID, float& a_minUCoord, float& a_minVCoord, float& a_maxUCoord, float& a_maxVCoord);
	//void SetSpriteScale(unsigned int a_uiSpriteID, float&a_fWidth, float& a_fHeight);
	//void GetSpriteScale(unsigned int a_uiSpriteID, float&a_fWidth, float& a_fHeight);

	void Draw();
	void Input(); // move to 'movable object' child class

	void UVSetup();
	

private:
	Vertex m_aoVerts[4];
	Matrix4 * modelMatrix;

	Vector3 m_v3Scale;
	Vector3 m_v3Position;
	Vector4 m_v4SpriteColor;

	unsigned int m_uiTexture;
	GLFWwindow * GameWindow;
	// used later
	Vector3 m_minUVCoords;
	Vector3 m_maxUVCoords;
	Vector3 m_uvScale;
	Vector3 m_uvOffset;

	unsigned int m_uSourceBlendMode;
	unsigned int m_uDestinationBlendMode;
	int tex_loc, matrix_location, proj_location;
};

#endif