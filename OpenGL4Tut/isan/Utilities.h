#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <GL/glew.h>
#include <FreeImage.h> 
#include <GLFW/glfw3.h>
#include <iostream>

unsigned int LoadTexture(const char* a_szTexture, unsigned int a_uiFormat /* = 
GL_RGBA */, unsigned int* a_uiWidth /* = nullptr */, unsigned int* a_uiHeight /* = 
nullptr */, unsigned int* a_uiBPP /* = nullptr*/);

#endif