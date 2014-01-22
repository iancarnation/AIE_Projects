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

std::string textFileReader(const char* a_szFileName) {
 
    std::string FileContents;
	std::ifstream FileStream;
 
	FileStream.open(a_szFileName, std::ios::in);
	if (FileStream.is_open()) {
        std::string Line = "";
			while(getline(FileStream,Line))
				FileContents += "\n" + Line;
			FileStream.close();
    }
	else
	{
		printf("Error: Failed to open file '%s'!\n",a_szFileName);
	}

	return FileContents;
}

