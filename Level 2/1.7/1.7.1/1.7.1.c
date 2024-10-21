// swap integers
#include <stdio.h>
#include "swap.h"

int main()
{
	// initialize variables
	int num1 = 123;
	int num2 = 456;

	// before swap
	printf("Before swap | num1: %d, num2: %d\n", num1, num2);
	
	// swap
	swap(&num1, &num2);
	
	// after swap
	printf("After swap  | num1: %d, num2: %d\n", num1, num2);

	return 0;
}