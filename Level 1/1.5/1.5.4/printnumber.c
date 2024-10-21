#include "printnumber.h"

void printnumber(int num)
{
	// INT_MIN edge case
	if (num == INT_MIN)
	{
		putchar('-');
		printnumber(abs(num / 10));
		putchar('8'); // hardcode print of INT_MIN's last digit
		return;
	}

	// negative integer case
	if (num < 0)
	{
		putchar('-');
		num = abs(num);
	}

	// recurse
	if (num / 10 != 0) {
		printnumber(num / 10);
	}

	// print the last digit
	putchar(num % 10 + '0');
}