// constructors as conversion operator
#include "point.hpp"
#include <iostream>

int main()
{
	// create a point
	Point p(1.0, 1.0);

	// Implicit conversion (w/o 'explicit' keyword)
	/*if (p == 1.0) 
		std::cout << "Equal!" << std::endl;
	else 
		std::cout << "Not equal" << std::endl;*/


	// explicit conversion
	if (p == (Point)1.0)
		std::cout << "Equal!" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	return 0;
}