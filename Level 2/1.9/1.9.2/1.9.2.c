#include "file.h"

#define MAX_LINE_LENGTH 1000 // max string length in one line
#define MAX_FILENAME_LENGTH 50 // max filename length

/**
 * @brief clears input buffer
 * loops until a newline character or 
 * Ctrl + A found
*/
void clearInputBuffer();

int main()
{
	// declare variables
	char input;
	char output[MAX_LINE_LENGTH];
	int i = 0;
	char fileName[MAX_FILENAME_LENGTH];
	FILE* file;

	// read filename from console
	printf("Enter the file name: ");
	scanf_s("%s", fileName, MAX_FILENAME_LENGTH);
	clearInputBuffer();

	// open file
	file = OpenFile(fileName);
	if (file == NULL)
	{
		printf("error in opening file\n");
		return 1;
	}

	while ((input = getchar()) != 1)  // check for Ctrl + A
	{
		switch (input)
		{
		case '\n':
			// Newline character detection
			// null-terminate the string
			output[i] = '\0';
			// write to file
			if (WriteToFile(file, output) == 1) 
			{
				printf("error in writing to file\n");
				return 1;
			}
			i = 0;  // reset index for the next line
			break;
		default:
			// Default
			if (i == MAX_LINE_LENGTH - 1) {  // max chars check
				printf("max chars reached\n");
				return 1;
			}
			// put read character into output string
			output[i] = input;
			// increase index
			i++;
		}
	}

	printf("CTRL + A is a correct ending.\n");
	CloseFile(file); // close file
	return 0;
}

// Function to clear the input buffer
void clearInputBuffer() {
	char c;
	// loop until newline or Ctrl + A (ASCII 1) found
	while ((c = getchar()) != '\n' && c != 1);
}