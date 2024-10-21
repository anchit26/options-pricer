/* Calculate the length of a string */

#include <stdio.h>
#include <string.h>

#define MAXLINE 30

/**
 * @brief returns string length ending at \0
 * 
 * Function expects string ending with '\0'.
 * Uses pointer arithmetic over type char (1 byte)
 * to calculate length.
 * 
 * @param str 
 * @return string length
*/
int Length(char str[]);

int main()
{
	char string[MAXLINE + 1]; // Line of maximum 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

// Length
int Length(char str[])
{
	// initialize end with array start
	char* end = str;
	
	// iterate until string termination found
	while (*end != '\0')
		++end;
	
	// return string length
	return end - str;
}