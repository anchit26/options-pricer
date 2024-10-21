#include <stdio.h>

int main()
{
    float temp_f_start, temp_f_end; // Fahrenheit temperatures
    float step; // step size
    float temp_c, temp_f;

    // initialize params
    temp_f_start = 0;
    temp_f_end = 300;
    step = 20;

    printf("+-------------+---------------+\n");
    printf("| Fahrenheit   |   Celsius    |\n");
    printf("+-------------+---------------+\n");

    temp_f = temp_f_start;
    while (temp_f <= temp_f_end)
    {
        temp_c = (5.0f / 9.0f) * (temp_f - 32.0f);
        printf("| %10.1f   | %10.1f   |\n", temp_f, temp_c);
        temp_f += step;
    }
    printf("+--------------+--------------+\n");

    return 0;
}
