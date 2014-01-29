#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "GLlog.h"

// keep track of widow size for thigs like the wirwport and the mouse cursor
int g_gl_width = 640;
int g_gl_height = 480;

// a call-back function
void glfw_window_size_callback (GLFWwindow* window, int width, int height)
{
	g_gl_width = width;
	g_gl_height = height;

	/* update any perspective matrices used here */
}

void glfw_error_callback (int error, const char* description) 
{
	fputs (description, stderr);
	gl_log (description, __FILE__, __LINE__);
}

void _update_fps_counter (GLFWwindow* window)
{
	static double previous_seconds = glfwGetTime();
	static int frame_count;
	double current_seconds = glfwGetTime();
	double elapsed_seconds = current_seconds - previous_seconds;
	if (elapsed_seconds > 0.25)
	{
		previous_seconds = current_seconds;
		double fps = (double)frame_count / elapsed_seconds;
		char tmp[128];
		sprintf (tmp, "opengl @ fps: %.21f", fps);
		glfwSetWindowTitle (window, tmp);
		frame_count = 0;
	}
	frame_count++;
}

int main()
{
	// open an OS window using GLFW
	if(!glfwInit())
	{
		fprintf (stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}
	char message[256];
	sprintf (message, "starting GLFW %s", glfwGetVersionString());
	assert (gl_log (message, __FILE__, __LINE__));
	glfwSetErrorCallback (glfw_error_callback);

	// Anti-Aliasing
	glfwWindowHint (GLFW_SAMPLES, 4);

	// get the primary monitor
	GLFWmonitor* mon = glfwGetPrimaryMonitor();

	// this lets us use the video mode for the monitor we pass
	const GLFWvidmode* vmode = glfwGetVideoMode(mon);
		
	//GLFWwindow* window2 = glfwCreateWindow(vmode->width, vmode->height, "Extended GL Init",mon/* mon*/, NULL);
	//	if (!window2)
	//		{
	//			fprintf (stderr, "ERROR: could not open window with GLFW3\n");
	//			glfwTerminate();
	//			return 1;
	//		}

	//glfwSetWindowSize (window2, vmode->width, vmode->height);
	//glfwMakeContextCurrent (window2);

	GLFWwindow * window = glfwCreateWindow(640,480,"Hello Triangle", NULL, NULL);
		if (!window)
		{
			fprintf (stderr, "ERROR: could not open window with GLFW3\n");
			glfwTerminate();
			return 1;
		}

	glfwMakeContextCurrent(window);
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
	// get version info
	const GLubyte* renderer = glGetString (GL_RENDERER);	// get renderer string
	const GLubyte* version = glGetString (GL_VERSION);		// version as a string
	printf ("Renderer: %s\n", renderer);
	printf ("OpenGL version supported %s\n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable (GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc (GL_LESS);
	// depth-testing interprets a smaller value as "closer"
		
	float triPoints[]  = 
	{
		0.0f, 0.5f, 0.0f, 
		0.5f,-0.5f, 0.0f,
	   -0.5f,-0.5f, 0.0f
	};
	GLuint VBO = 0;
	glGenBuffers (1, &VBO);
	glBindBuffer (GL_ARRAY_BUFFER, VBO);
	glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), triPoints, GL_STATIC_DRAW);
	glBindBuffer (GL_ARRAY_BUFFER, 0);
	GLuint VAO = 0;
	glGenVertexArrays (1, &VAO);
	glBindVertexArray (VAO);
	glEnableVertexAttribArray (0);
	glBindBuffer (GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); 
	glBindBuffer (GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// add another shape
	GLfloat sqrPoints[] = 
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f
		
	   /*-0.7f, 0.0f, 0.0f,
	   -0.4f, 0.9f, 0.0f,
		0.3f, 0.3f, 0.0f,
		0.5f, 0.8f, 0.0f*/

	   /*-0.9f, 0.0f, 0.0f,
	   -0.9f, 0.9f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.9f, 0.0f*/
	};
	GLuint sVBO = 0;
	glGenBuffers (1, &sVBO);
	glBindBuffer (GL_ARRAY_BUFFER, sVBO);
	glBufferData (GL_ARRAY_BUFFER,sizeof (sqrPoints), sqrPoints, GL_STATIC_DRAW);
	glBindBuffer (GL_ARRAY_BUFFER, 0);
	GLuint sVAO = 0;
	glGenVertexArrays (1, &sVAO);
	glBindVertexArray (sVAO);
	
	glBindBuffer (GL_ARRAY_BUFFER, sVBO);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); 
	glEnableVertexAttribArray (0);
	glBindBuffer (GL_ARRAY_BUFFER, 0);

	const char* vertex_shader = 
	"#version 330\n"
	"in vec3 vp;"
	"void main () {"
	" gl_Position = vec4 (vp, 1.0);"
	"}";

	const char* fragment_shader = 
	"#version 330\n"
	"out vec4 frag_colour;"
	"void main () {" 
	" float lerpValue = gl_FragCoord.y / 480.0f;"
	" frag_colour = mix(vec4 (1.0f, 1.0f, 1.0f, 1.0f), vec4 (0.5, 0.0, 0.5, 1.0), lerpValue);"
	"}";

	const char* fragment_shader_square = 
	"#version 330\n"
	"out vec4 frag_colour;"
	"void main () {"
	" float lerpValue = gl_FragCoord.y / 480.0f;"
	" frag_colour = mix(vec4 (1.0f, 1.0f, 1.0f, 1.0f), vec4 (0.6, 0.2, 0.4, 1.0), lerpValue);"
	"}";

	// Create a shader
	GLuint vs = glCreateShader (GL_VERTEX_SHADER);
	// put actual char* into the shader
	glShaderSource (vs, 1, &vertex_shader, NULL);
	// compile the shader
	glCompileShader(vs);
	printShaderInfoLog(vs);
	GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs, 1, &fragment_shader, NULL);
	glCompileShader (fs);
	printShaderInfoLog(fs);
	// create the container that holds your shaders
	GLuint shaderProgram = glCreateProgram ();
	// attach the shaders you compiled
	glAttachShader (shaderProgram, fs);
	glAttachShader (shaderProgram, vs);
	// this links the shaders together, its kinda like a compile
	glLinkProgram (shaderProgram);
	printProgramInfoLog(shaderProgram);

	GLuint fss = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fss, 1, &fragment_shader_square, NULL);
	glCompileShader (fss);
	printShaderInfoLog(fss);

	// new shader program for square
	GLuint squareShaderProgram = glCreateProgram ();
	// attach the shaders you compiled
	glAttachShader (squareShaderProgram, fss);
	glAttachShader (squareShaderProgram, vs);
	// this links the shaders together, its kinda like a compile
	glLinkProgram (squareShaderProgram);
	printProgramInfoLog(squareShaderProgram);

	while (!glfwWindowShouldClose (window)) 
	{
		_update_fps_counter (window);
		// wipe the drawing surface clear
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport (0,0, g_gl_width, g_gl_height);

		glUseProgram (shaderProgram);
		glBindVertexArray (VAO);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays (GL_TRIANGLES, 0, 3);
		glBindVertexArray (0);

		glUseProgram (squareShaderProgram);
		glBindVertexArray (sVAO);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays (GL_TRIANGLE_STRIP, 0, 4);
		glBindBuffer (GL_ARRAY_BUFFER, 0);

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers (window);	
	}



	// close GL context and any other GLFW resources
	glfwTerminate();


	char* pause = "not";
	std::cin>> pause;

	return 0;
}
