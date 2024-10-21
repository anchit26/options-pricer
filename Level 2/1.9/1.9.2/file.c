#include "file.h"

// open file
FILE* OpenFile(char* fName)
{
	FILE* file;
	
	// open file using fopen with write access
	if (fopen_s(&file, fName, "w"))
	{
		printf("error in opening file\n");
		return NULL;
	}
	// return file handle on success
	return file;
}

// write to file
int WriteToFile(FILE* f, char* content)
{
	// write to file using fprintf
	if (fprintf(f, "%s\n", content) < 0)
	{
		printf("error in writing to file");
		return 1;
	}
	return 0;
}

// close file
void CloseFile(FILE* f)
{
	// close file
	fclose(f);
}