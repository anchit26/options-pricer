// file.h
#ifndef FILE_H
#define FILE_H

#include <stdio.h>

/**
 * @brief Opens a file
 * @param fName File Name
 * @return file handle if successful, NULL on failure
*/
FILE* OpenFile(char* fName);

/**
 * @brief Writes to a file from the top
 * @param f file handle
 * @param content content to write
 * @return 0 on success, 1 on failure
*/
int WriteToFile(FILE *f, char* content);

/**
 * @brief closes a file
 * @param f file handle
*/
void CloseFile(FILE* f);

#endif // !FILE_H
