#include "Sprite.h"

Sprite::Sprite()
{}

Sprite::~Sprite()
{}

Sprite::Sprite(/*const char* a_cpType,*/ const char* a_cpTexture, /*float a_fSheetSlices(won't need with XML sheet info?),*/ int a_iWidth, int a_iHeight, Vector4 a_v4Color, 
			   /*Vector3 a_v3Velocity,*/ /*Vector3 a_v3Force(gone with new physics?),*/ /*float a_fMass,*/ /*float a_fMovementPower(move to Entity child),*/ /*bool a_bAlive,*/ GLFWwindow* window)
{
	GameWindow = window;

	m_v3Scale = Vector3(a_iWidth, a_iHeight, 1);
	m_v3Position = Vector3(g_gl_width/2, g_gl_height/2, 0);

	modelMatrix = new Matrix4();

	*modelMatrix = modelMatrix->CreateIdentity();

		modelMatrix->m14 = m_v3Position.m_fX;
		modelMatrix->m24 = m_v3Position.m_fY;
		modelMatrix->m34 = m_v3Position.m_fZ;
	
		proj_location = glGetUniformLocation(m_ShaderProgram, "projection");

	LoadVertShader("./resources/VertexShader.glsl");
	LoadFragShader("./resources/FragmentShader.glsl");
	LinkShaders();

	// After all the shader stuff
	m_v4SpriteColor = a_v4Color;

	m_aoVerts[0].Pos = Vector3(-0.5f, 0.5f, 0.0f);
	m_aoVerts[1].Pos = Vector3( 0.5f, 0.5f, 0.0f);
	m_aoVerts[2].Pos = Vector3(-0.5f,-0.5f, 0.0f);
	m_aoVerts[3].Pos = Vector3( 0.5f,-0.5f, 0.0f);
	
	m_aoVerts[0].Color = m_v4SpriteColor;
	m_aoVerts[1].Color = m_v4SpriteColor;
	m_aoVerts[2].Color = m_v4SpriteColor;
	m_aoVerts[3].Color = m_v4SpriteColor;

	m_aoVerts[0].UV = Vector3(0.0f, 0.0f, 1.0f);
	m_aoVerts[1].UV = Vector3(1.0f, 0.0f, 1.0f);
	m_aoVerts[2].UV = Vector3(0.0f, 1.0f, 1.0f);
	m_aoVerts[3].UV = Vector3(1.0f, 1.0f, 1.0f);

	//m_aoVerts[0].UV[0] = 0.0f;m_aoVerts[0].UV[1] = 0.0f;
	//m_aoVerts[1].UV[0] = 1.0f;m_aoVerts[1].UV[1] = 0.0f;
	//m_aoVerts[2].UV[0] = 0.0f;m_aoVerts[2].UV[1] = 1.0f;
	//m_aoVerts[3].UV[0] = 1.0f;m_aoVerts[3].UV[1] = 1.0f;

	GLuint elements[] = 
	{
		0,1,2,3
	};

	// Gen Buffers
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
	glGenVertexArrays(1, &m_VAO);

	// Bind Buffers
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	
	// Put Data into buffers
	glBufferData(GL_ARRAY_BUFFER, 4* sizeof(Vertex), m_aoVerts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	
	// Enable some attributes
	GLint posAttrib = glGetAttribLocation(m_ShaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	GLint colAttrib = glGetAttribLocation(m_ShaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	GLint uvAttrib = glGetAttribLocation(m_ShaderProgram, "texcoord");
	glEnableVertexAttribArray(uvAttrib);

	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(uvAttrib,  2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(7 * sizeof(float)));//check for extra value
	
	glBindVertexArray(0);

	matrix_location = glGetUniformLocation (m_ShaderProgram, "matrix");

	m_uiTexture = 0;
	m_minUVCoords = Vector3(0.f, 0.f, 0.f);
	m_maxUVCoords = Vector3(1.f, 1.f, 0.f); //???
	
	m_uvScale = Vector3(1.f, 1.f, 1.f);
	m_uvOffset = Vector3(0.f, 0.f, 0.f);

	m_uSourceBlendMode = GL_SRC_ALPHA;
	m_uDestinationBlendMode = GL_ONE_MINUS_SRC_ALPHA;

	glGenTextures(1, &m_uiTexture);
	glActiveTexture (GL_TEXTURE0);

	int width, height;
	unsigned char* image = SOIL_load_image(a_cpTexture, &width, &height, 0, SOIL_LOAD_RGBA);
	glBindTexture( GL_TEXTURE_2D,m_uiTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	tex_loc = glGetUniformLocation (m_ShaderProgram, "diffuseTexture");
	glUseProgram (m_ShaderProgram);
	glUniform1i (tex_loc, 0); // use active texture 0
}

void Sprite::Draw()
{
	glBlendFunc(m_uSourceBlendMode, m_uDestinationBlendMode);
	glUseProgram(m_ShaderProgram);
	glActiveTexture(GL_TEXTURE0);
	
	glUniform1i(tex_loc, 0);

	modelMatrix->m11 = m_v3Scale.m_fX;
	modelMatrix->m22 = m_v3Scale.m_fY;
	modelMatrix->m14 = m_v3Position.m_fX;
	modelMatrix->m24 = m_v3Position.m_fY;
	modelMatrix->m34 = m_v3Position.m_fZ;

	Matrix4 MVP = (*Ortho * *modelMatrix);

	glUniformMatrix4fv(matrix_location, 1, GL_TRUE, &MVP.m11);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);
}

void Sprite::Input()
{
	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_W))
		m_v3Position += Vector3(0.0f, 1.0f, 0.0f);

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_A))
		m_v3Position += Vector3(-1.0f, 0.0f, 0.0f);

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_S))
		m_v3Position += Vector3(0.0f, -1.0f, 0.0f);

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_D))
		m_v3Position += Vector3(1.0f, 0.0f, 0.0f);

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_O))
		m_v3Scale *= 1.01f;

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_K))
		m_v3Scale *= 0.99f;
}

//// setup UV Coordinates, creates a vector of 'Slices' of a sprite sheet
//void Sprite::UVSetup(float a_fSheetSlices)
//{
//	float fOffset = 1.0/a_fSheetSlices;			// X distance between slices
//	float fMin = 0.0f;							// current top-left corner of slice
//	float fMax = fOffset;						// current bottom-right corner of slice
//	// for each slice of the sprite sheet
//	for (int i=0; i<int(a_fSheetSlices); i++)
//	{
//		// construct UV coordinate set
//		UV Slice;
//		Slice.Umin = fMin;
//		Slice.Vmin = 0.0f;
//		Slice.Umax = fMax;
//		Slice.Vmax = 1.0f;
//		// add to sprite sheet vector
//		m_vSpriteSheet.push_back(Slice);
//		// increment min and max cursors
//		fMin += fOffset;
//		fMax += fOffset;
//	}
//
//}
