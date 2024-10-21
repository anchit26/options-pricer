// Prefix decrement vs Postfix decrement
#include <stdio.h>

int main()
{
	int i;

	// prefix
	i = 10;
	printf("-------- Prefix (--i) --------\n");
	printf("Start    :   i = %d\n", i);
	printf("Prefixed : --i = %d\n", --i);
	printf("End      :   i = %d\n", i);
	printf("------------------------------\n");
	
	// postfix
	i = 10;
	printf("-------- Postfix (i--) -------\n");
	printf("Start    : i   = %d\n", i);
	printf("Postfixed: i-- = %d\n", i--);
	printf("End      : i   = %d\n", i);
	printf("------------------------------\n");

	return 0;
}

/*
--------Prefix(--i)--------
Start    :   i = 10
Prefixed : --i = 9
End : i = 9
------------------------------
--------Postfix(i--)------ -
Start : i = 10
Postfixed : i-- = 10
End : i = 9
------------------------------
*/