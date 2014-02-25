#define GL_LOG_FILE "gl.log"
#ifndef __GLLOG_
#define __GLLOG_
#include<time.h>
#include<fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

bool restart_gl_log(); 

bool gl_log(const char* message, const char* filename, int line);

void printShaderInfoLog(GLuint obj);

void printProgramInfoLog(GLuint obj);

#endif