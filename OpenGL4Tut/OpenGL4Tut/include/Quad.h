#ifndef _QUAD_
#define _QUAD_

#include <GL\glew.h> //Or wherever your Glew is located
#include <GLLog.h> //For logging… stuff
#include <TextFileReader.h>

class Quad
{
public:
	Quad(void);
	~Quad(void);

	GLuint m_VBO;
	GLuint m_VAO;
	GLuint m_EBO;
	
	GLuint m_FragmentShader;
	GLuint m_VertexShader;

	GLuint m_ShaderProgram;

	void Draw();
private:

};
#endif // _QUAD_
