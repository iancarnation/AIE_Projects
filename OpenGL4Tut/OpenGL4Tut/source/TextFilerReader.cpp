#include <TextFileReader.h>

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
