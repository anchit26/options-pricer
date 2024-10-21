#include "factorial.h"

long long int factorial(int num)
{
	// terminating condition
	if (num == 0 || num == 1)
	{
		return 1;
	}

	return num * factorial(num - 1);
}