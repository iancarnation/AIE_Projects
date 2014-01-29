#ifndef _TEXT_FILE_READER_H_
#define _TEXT_FILE_READER_H_
#include <string>
#include <istream>
#include <fstream>
/*
Usage 
	 std::string vString, fString;
	 const char *vs, *fs;

// Read source code from files
	vString = textFileReader("./resources/exampleVert.glsl");
	fString = textFileReader("./resources/exampleFrag.glsl");

	vs = vString.c_str();
	fs = fString.c_str();

	// Set shader source
*/

std::string textFileReader(const char* a_szFileName);
#endif