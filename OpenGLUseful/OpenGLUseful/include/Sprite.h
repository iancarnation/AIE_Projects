#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Quad.h"
#include "Vertex.h"
#include <FreeImage.h>
#include "MathLibrary.h"
#include "Utilities.h"

class Sprite: public Quad
{
public:
	Sprite(void);
	~Sprite(void);
	Sprite( const char*, int, int, Vector4, GLFWwindow*);
	void Draw();
	void Input();
private:
	Vertex m_aoVerts[4];
	float * modelMatrix;

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
	int tex_loc;
	int matrix_location;
};

#endif