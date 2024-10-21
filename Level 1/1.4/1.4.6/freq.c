#include <stdio.h>

int main()
{
    int freq[5] = { 0 }; // array to store freq of digits 0-4
    int freq_others = 0;
    char input_char;
    int i;

    printf("Enter input\n");
    do 
    {
        input_char = getchar();
        if (input_char == EOF)
        {
            break;
        }

        switch (input_char)
        {
        case '0':
            freq[0]++;
            break;
        case '1':
            freq[1]++;
            break;
        case '2':
            freq[2]++;
            break;
        case '3':
            freq[3]++;
            break;
        case '4':
            freq[4]++;
            break;
        default:
            freq_others++;

        }
    } while (1);

    printf("+---------+-----------+\n");
    printf("|  Count  | Frequency |\n");
    printf("+---------+-----------+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|    %d    |    %5d   |\n", i, freq[i]);
    }
    printf("|  Others  |    %5d   |\n", freq_others);
    printf("+---------+-----------+\n");

    return 0;
}
