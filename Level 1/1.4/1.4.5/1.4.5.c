#include <stdio.h>

int main()
{
    float temp_c_start, temp_c_end; // celsius temperatures
    float step; // step size
    float temp_c, temp_f;

    // initialize params
    temp_c_start = 0;
    temp_c_end = 19;
    step = 1;

    printf("+-------------+---------------+\n");
    printf("|  Celsius    |   Fahrenheit  |\n");
    printf("+-------------+---------------+\n");

    for (temp_c = temp_c_start; temp_c <= temp_c_end; temp_c += step)
    {
        temp_f = (9.0f / 5.0f * temp_c) +  32.0f;
        printf("| %10.1f   | %10.1f   |\n", temp_c, temp_f);
        temp_c += step;
    }
    printf("+--------------+--------------+\n");

    return 0;
}
