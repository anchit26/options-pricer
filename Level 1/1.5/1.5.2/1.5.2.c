#include <stdio.h>
#include "factorial.h"

int main()
{
	int num = 20;
	printf("%d! = %lld", num, factorial(num));
	return 0;
}