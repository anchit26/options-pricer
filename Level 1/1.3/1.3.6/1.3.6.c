// Arithmetic v/s Logical Shift
#include <stdio.h>

int main()
{
	int inputNum, shiftedNum;

	// user input
	printf("Enter an integer: ");
	scanf_s("%d", &inputNum);

	printf("%s shift\n", inputNum < 0 ? "Arithmetic" : "Either, arithmetic or " 
		"logical");

	// right shift
	shiftedNum = inputNum >> 2;
	printf("Shifted Number: %d\n", shiftedNum);
	return 0;
}