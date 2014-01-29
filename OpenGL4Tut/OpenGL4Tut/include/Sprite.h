#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Utilities.h"
#include "Quad.h"
#include <SOIL.h>

class Sprite: public Quad
{
public:
	Sprite(void);
	~Sprite(void);
Sprite( const char* a_pTexture, int a_iWidth, int a_iHeight, tbyte::Vector4 a_v4Color,GLFWwindow* );
	void Draw();
	void Input();
	
	void SetVertexData( Vertex* a_vertexData );
	const Vertex* GetVertexData() const;

private:
	
	Vertex m_aoVerts[4];

	float * modelMatrix;

	tbyte::Vector2 m_v2Scale;
	tbyte::Vector3 m_v3Position;
	tbyte::Vector4 m_v4SpriteColor;



	tbyte::Vector2 m_minUVCoords;
	tbyte::Vector2 m_maxUVCoords;
	tbyte::Vector2 m_uvScale;
	tbyte::Vector2 m_uvOffset;	


	unsigned int m_uiTexture;
	GLFWwindow * GameWindow;
	//used later
	unsigned int	m_uSourceBlendMode;
	unsigned int	m_uDestinationBlendMode;
	int tex_loc;
	int matrix_location;
};


inline void	Sprite::SetVertexData( Vertex* a_vertexData )
{
	memcpy( &m_aoVerts, a_vertexData, sizeof(Vertex) * 4 );
}

inline const Vertex* Sprite::GetVertexData() const
{
	return static_cast<const Vertex*>( m_aoVerts );
}


#endif
