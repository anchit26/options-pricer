// power with left shift
#include <stdio.h>

int main()
{
	double inputNumber;
	int inputPower;
	long long int shiftedNum;
	long double result;

	// user input
	printf("Input number for multiplication: ");
	scanf_s("%lf", &inputNumber);

	printf("Input power: ");
	scanf_s("%d", &inputPower);

	// calculate
	shiftedNum = (long long int)1 << inputPower;
	result = inputNumber * shiftedNum;
	printf("Result: %Lf", result);
	return 0;
}