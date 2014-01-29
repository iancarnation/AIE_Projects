/*
Starting foundations for getting started with OpenGL
GLFW3, GLEW,Window creation 

*/

//Besure to include the correct linkers 
//glew32.lib glfw3dll.lib opengl32.lib
#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>

#include <stdio.h>

int notmain1()
{
    //open an OS window using GLFW
    if(!glfwInit())
    {
        fprintf (stderr,"ERROR: could not start GLFW3\n");
        return 1;
    }

    GLFWwindow * window = glfwCreateWindow(640,480,"Hello Triangle",NULL,NULL);
    if (!window) {
        fprintf (stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    //start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get version info
    const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString (GL_VERSION); // version as a string
    printf ("Renderer: %s\n", renderer);
    printf ("OpenGL version supported %s\n", version);

    // tell GL to only draw onto a pixel if the shape is closer to the viewer
    glEnable (GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer"

    /* OTHER STUFF GOES HERE NEXT */
	
  float points[] = 
    {
        0.0f,0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        -0.5f,-0.5f,0.0f,

    };
    GLuint VBO = 0;
    glGenBuffers (1, &VBO);
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points, GL_STATIC_DRAW);

	GLuint VAO = 0;
glGenVertexArrays (1, &VAO);
glBindVertexArray (VAO);
glEnableVertexAttribArray (0);
glBindBuffer (GL_ARRAY_BUFFER, VBO);
glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);

const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"void main () {"
"  gl_Position = vec4 (vp, 1.0);"
"}";

const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main () {"
"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
"}";

//Create a shader
GLuint vs = glCreateShader (GL_VERTEX_SHADER);
//put the actual char* into the shader 
glShaderSource (vs, 1, &vertex_shader, NULL);
//Compile the shader 
glCompileShader (vs);


GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
glShaderSource (fs, 1, &fragment_shader, NULL);
glCompileShader (fs);


//Create the container that holds your shaders
GLuint shaderProgram = glCreateProgram ();
//attach the shaders you compiled
glAttachShader (shaderProgram, fs);
glAttachShader (shaderProgram, vs);
//this is links the shaders together, its kinda like a compile
glLinkProgram (shaderProgram);

while (!glfwWindowShouldClose (window)) {
  // wipe the drawing surface clear
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram (shaderProgram);
  glBindVertexArray (VAO);
  // draw points 0-3 from the currently bound VAO with current in-use shader
  glDrawArrays (GL_TRIANGLES, 0, 3);
  // update other events like input handling 
  glfwPollEvents ();
  // put the stuff we've been drawing onto the display
  glfwSwapBuffers (window);
}

    // close GL context and any other GLFW resources
    glfwTerminate();
    return 0;


}
