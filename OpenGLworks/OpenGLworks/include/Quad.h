
#ifndef _QUAD_
#define _QUAD_

#include <GL/glew.h>
#include "GLlog.h"
#include "TextFileReader.h"



class Quad
{
public:
	Quad(void);
	~Quad(void);
	GLuint m_VBO; // vertex buffer
	GLuint m_EBO; // element buffer
	GLuint m_VAO; // vertex attributes
	GLuint m_FragmentShader;
	GLuint m_VertexShader;
	GLuint m_ShaderProgram;

	void Draw();
private:
};
#endif