// BinaryFilesExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct record
{
	char callNumber[15];
	char title[20];
	char author[30];
	int bookStatus;
};

ifstream::pos_type size;
char * memblock;

void Load()
{
	// OPEN library.dat
	fstream fin("library.dat", ios::in | ios::binary | ios::ate);	// ate flag positions get pointer at end of file, so when tellg() is called, the size of the file is obtained
	// IF library.dat is found and opened THEN
	if (fin.is_open())
	{
	//// READ the binary data into an array from library.dat and THEN close the file
		size = fin.tellg();
		memblock = new char [size];
		fin.seekg(0, ios::beg);			// set get pointer at beginning of file
		fin.read(memblock, size);		// read file
		fin.close();

		cout<< "file content read into memory\n";

		delete[] memblock;
	}
	
	// ELSE
	else
	{
	//// OPEN library.txt
		string line;
		ifstream tin("library.txt", ios::ate);
	//// IF library.txt is not found and opened THEN
		if (!tin.is_open())
			cout<<"Files could not be opened / found, have a nice day!\n";
	////// PRINT an error message and exit the program
	//// ELSE
		else
		{
	////// READ the text file into the array and then close the text file
			size = tin.tellg();
			memblock = new char[size];
			tin.seekg(0, ios::beg);

			for(int i=0; !tin.eof(); i++)
			{
				tin >> memblock[i];
			}

			tin.close();

	////// CREATE and open the binary file library.dat
			fstream fout("library.dat", ios::out | ios::binary);
	////// WRITE the contents of your library records array to the binary file, then close the file
			fout.write(memblock,size);
			fout.close();
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Load();
	return 0;
}

