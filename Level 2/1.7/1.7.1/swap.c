// swap.c
#include "swap.h"

// Swap two integers in-place
void swap(int* x, int* y)
{
	int temp = *x; // store temporary copy
	*x = *y; // put second integer value at first integer memory location
	*y = temp; // put first integer value at second integer memory location
}