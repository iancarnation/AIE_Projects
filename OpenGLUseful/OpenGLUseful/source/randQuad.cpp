/////////////////////////////////////////////////////////////////////////////////////////////
// Quad.cpp
// makes quads (as triangle strips)
/////////////////////////////////////////////////////////////////////////////////////////////

#include "randQuad.h"
#include <stdlib.h>
#include <time.h>

RandQuad::RandQuad()
{
	srand(time(NULL));
	float randStartX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float randStartY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float off = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);		// offset

	// set up vertices
	m_fPoints[0] = randStartX;         m_fPoints[1] = randStartY;          m_fPoints[2] = 0.0f;
	m_fPoints[3] = m_fPoints[0];       m_fPoints[4] = m_fPoints[1] - off;  m_fPoints[5] = 0.0f;
	m_fPoints[6] = m_fPoints[0] + off; m_fPoints[7] = m_fPoints[1];        m_fPoints[8] = 0.0f;
	m_fPoints[9] = m_fPoints[6];       m_fPoints[10] = m_fPoints[7] - off; m_fPoints[11] = 0.0f;

	//// set up color
	//m_fColors[0] = (rand()%100) / 100; m_fColors[1] = (rand()%100) / 100;m_fColors[2] = (rand()%100) / 100;
	//m_fColors[3] = (rand()%100) / 100; m_fColors[4] = (rand()%100) / 100;m_fColors[5] = (rand()%100) / 100;
	//m_fColors[6] = (rand()%100) / 100; m_fColors[7] = (rand()%100) / 100;m_fColors[8] = (rand()%100) / 100;
	//m_fColors[9] = (rand()%100) / 100; m_fColors[10] = (rand()%100) / 100;m_fColors[11] = (rand()%100) / 100;

	// fill up attribute obj with vertex and color VBOs
	m_VAO = 0;
	LoadVAO();
}

RandQuad::~RandQuad()
{}

void RandQuad::LoadVAO()
{
	GLuint pointsVBO = 0;
	glGenBuffers (1, &pointsVBO);
	glBindBuffer (GL_ARRAY_BUFFER, pointsVBO);
	glBufferData (GL_ARRAY_BUFFER,sizeof (m_fPoints), m_fPoints, GL_STATIC_DRAW);

	glGenVertexArrays (1, &m_VAO);
	glBindVertexArray (m_VAO);
	glBindBuffer (GL_ARRAY_BUFFER, pointsVBO);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); 

	glEnableVertexAttribArray (0);

}