// print through macros
#include "defs.h"

int main()
{
	// initialize variables
	int a = 5;
	int b = 10;

	// print
	PRINT1(a);
	PRINT2(a, b);

	return 0;
}