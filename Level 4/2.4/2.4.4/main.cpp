// friends
#include "point.hpp"
#include "line.hpp"
#include <iostream>

int main()
{
	// create a point
	Point p1(2, 3);

	// print point using << operator
	std::cout << p1 << std::endl;

	// create a line
	Point p2(0, 0);
	Line line(p1, p2);

	// print line using << operator
	std::cout << line << std::endl;

	return 0;
}