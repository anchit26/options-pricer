#include <stdio.h>

int main()
{
    int num_chars, num_words, num_newlines;
    char curr_char, last_char;

    // initialize 
    last_char = ' ';
    num_chars = 0;
    num_words = 0;
    num_newlines = 1;

    printf("Enter input\n");
    // read first input
    curr_char = getchar();

    while (1)
    {
        // break on Ctrl + D
        if (curr_char == 4)
        {
            break;
        }

        switch (curr_char)
        {
        case '\n':
            // count newline for every newline char
            num_newlines++;
            break;

        case ' ':
            // do nothing for spaces, handled in default case
            break;

        default:
            // count word for every new character which 
            // follows a space or a newline
            if (last_char == ' ' || last_char == '\n')
            {
                num_words++;
            }
            break;
        }

        // count character for every new char
        num_chars++;
        last_char = curr_char; // store the current char
        curr_char = getchar(); // read a new char
    }

    // output
    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of newlines: %d\n", num_newlines);

    return 0;
}
