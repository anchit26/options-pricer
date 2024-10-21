// dayname.c
#include "dayname.h"

// DayName
void DayName(int dayNum)
{
	const char *days[7] = {
		"SUNDAY", // Day 0
		"MONDAY", // Day 1
		"TUESDAY", // Day 2
		"WEDNESDAY", // Day 3
		"THURSDAY", // Day 4
		"FRIDAY", // Day 5
		"SATURDAY" // Day 6
	};

	// Check if dayNum is within the valid range (1 to 7)
	if (dayNum < 1 || dayNum > 7) {
		printf("Invalid day number\n");
		return;
	}

	// convert for zero-indexed array
	dayNum--;

	// print the day name
	printf("Today is %s\n", days[dayNum]);
}