#include <stdio.h>

int main()
{
	int num_chars, num_words, num_newlines;
	char curr_char, last_char;

	// initialize 
	last_char = ' ';
	num_chars = 0;
	num_words = 0;
	num_newlines = 0;

	printf("Enter input\n");

	do
	{
		// read a new char
		curr_char = getchar();

		// break on Ctrl + D 
		if (curr_char == 4)
		{
			break;
		}

		// count newline for every newline char
		if (curr_char == '\n')
		{
			num_newlines++;
		}

		// count word for every new character which 
		// follows a space or a newline
		if ((curr_char != '\n' && curr_char != ' ') &&
			(last_char == ' ' || last_char == '\n'))
		{
			num_words++;
		}

		// count character for every new char
		num_chars++;
		last_char = curr_char; // store the current char
	} while (1);

	// output
	printf("Number of characters: %d\n", num_chars);
	printf("Number of words: %d\n", num_words);
	printf("Number of newlines: %d\n", num_newlines);
	return 0;
}