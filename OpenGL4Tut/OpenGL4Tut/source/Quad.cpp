#include "Quad.h"


Quad::Quad(void)
{

	
	//Default Shaders for Default constructor

	const char * VertexShader =	// Vertex Shaders deal with objects in 3D space
		"#version 330\n"
		"layout(location = 0) in vec3 position;"
		"layout(location = 1) in vec4 color;"
		//"in vec2 texcoord;"
		"out vec4 vColor;"
		"void main() {"
		"	vColor = color;"
		"	gl_Position = vec4 (position, 1.0);"
		"}";

	const char * FragmentShader =	// Fragment Shaders dela with pixel data
		"#version 330\n"
		"in vec4 vColor;"
		//"in vec2 texcoord;"
		"out vec4 outColour;"
		"void main () {"
		"	outColour = vColor;"
		"}";
	// Compile Vertex Shader
	m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_VertexShader, 1, &VertexShader, NULL);
	glCompileShader(m_VertexShader);
	printShaderInfoLog(m_VertexShader);

	// Compile Fragment Shader
	m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_FragmentShader, 1, &FragmentShader, NULL);
	glCompileShader(m_FragmentShader);
	printShaderInfoLog(m_FragmentShader);

	// Link Shaders into Shader Program
	m_ShaderProgram = glCreateProgram();

	glAttachShader(m_ShaderProgram, m_FragmentShader);
	glAttachShader(m_ShaderProgram, m_VertexShader);

	glLinkProgram(m_ShaderProgram);
	printProgramInfoLog(m_ShaderProgram);

	glUseProgram(m_ShaderProgram);

	// Create VAO
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	// Create Buffers
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	GLfloat points[] = 
	{
		-0.5f,  0.5f,  0.0f,  0.0f, 1.0f,  0.0f, 1.0,
		 0.5f,  0.5f,  0.0f,  0.0f, 0.0f,  1.0f, 1.0,
		-0.5f, -0.5f,  0.0f,  1.0f, 0.0f,  0.0f, 1.0,
		 0.5f, -0.5f,  0.0f,  1.0f, 1.0f,  1.0f ,1.0
	};
	glBufferData(GL_ARRAY_BUFFER,sizeof(points),points,	GL_STATIC_DRAW);
	// Specify layout of vertex data
	char *attribute_name = "position";
	GLint posAttrib = glGetAttribLocation(m_ShaderProgram, attribute_name);
	if (posAttrib == -1) {
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
	}
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 7*(sizeof(float)), 0);

	attribute_name = "color";
	GLint colAttrib = glGetAttribLocation(m_ShaderProgram, attribute_name);
	if (colAttrib == -1) {
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
	}
	glEnableVertexAttribArray(colAttrib);

	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 7*(sizeof(float)),  (void*)(3 * sizeof(GLfloat)));

	glGenBuffers(1, &m_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	GLuint elements[] =
	{
		0,1,2,3
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements), elements, GL_STATIC_DRAW);

	/*		glGenBuffers(1, &m_UBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_UBO);
	GLfloat UVs[] = 
	{
	0.0f,  0.0f,	// Top-left
	1.0f,  0.0f,	// Top-right
	0.0f,  1.0f,	// Bottom-right
	1.0f,  1.0f	// Bottom-left
	};

	glBufferData(GL_ARRAY_BUFFER,	// target
	sizeof(UVs),		// size
	UVs,				// data
	GL_STATIC_DRAW
	);
	GLint texAttrib = glGetAttribLocation(m_ShaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
	*/
	/*
	// Load Texture
	glGenTextures(1, m_Texture);

	int width, height;
	unsigned char * image;

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Texture[0]);
	image = SOIL_load_image(m_cTexturePath, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glUniform1i(glGetUniformLocation(m_ShaderProgram, "texKitten"), 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// CREATE TRANSLATION MATRIX
	//m_uniModel = glGetUniformLocation(m_ShaderProgram, "model");

	// CREATE VIEW MATRIX
	/*	glm::mat4 view = glm::lookAt( glm::vec3(1.2f, 1.2f, 1.2f), // camera position
	glm::vec3(0.0f, 0.0f, 0.0f), // point centered on screen
	glm::vec3(0.0f, 0.0f, 1.0f) // "Up Axis" or in this case, Z, making XY the ground
	);

	GLint uniView = glGetUniformLocation(m_ShaderProgram, "view");
	glUniformMatrix4fv(uniView, // location
	1,		// num of things
	GL_FALSE, // not normalized
	glm::value_ptr(view)); // converts shti

	// PROJECTION MATRIX
	glm::mat4 proj = glm::perspective(45.0f,			// vertical FOV
	640.0f / 480.0f,	// Screen Aspect Ratio
	1.0f,				// near plane
	10.0f				// far plane
	);
	m_uniProj = glGetUniformLocation(m_ShaderProgram, "proj");
	glUniformMatrix4fv( m_uniProj, //location of uniform
	1,
	GL_FALSE,
	glm::value_ptr(proj)
	);
	*/
}


Quad::~Quad(void)
{

}

void Quad::Draw()
{
	glUseProgram(m_ShaderProgram);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBindVertexArray(m_VAO);

	glDrawElements(GL_TRIANGLE_STRIP, 6,GL_UNSIGNED_INT,0);	

}