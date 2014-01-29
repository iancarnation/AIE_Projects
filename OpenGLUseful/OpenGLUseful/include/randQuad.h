/////////////////////////////////////////////////////////////////////////////////////////////
// Quad.h
// makes quads (as triangle strips)
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _RANDQUAD_H_
#define _RANDQUAD_H_

#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class RandQuad
{
public: 
	RandQuad();
	~RandQuad();

	GLuint m_VAO;

private:
	void LoadVAO();

	GLfloat m_fPoints[12];
	//GLfloat m_fColors[12];
	
};

#endif