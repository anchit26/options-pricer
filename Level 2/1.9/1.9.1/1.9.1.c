#include <stdio.h>

#define MAX_LINE_LENGTH 1000 // max string length in one line

int main()
{
	// declare variables
	char input;
	char output[MAX_LINE_LENGTH];
	int i = 0;

	while ((input = getchar()) != 1)  // check for Ctrl + A
	{
		switch (input)
		{
		case '\n':
			// Newline character detection
			
			// null-terminate the string
			output[i] = '\0'; 
			// print the output
			printf("%s\n", output);
			// reset index for the next line
			i = 0;  
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
	return 0;
}
