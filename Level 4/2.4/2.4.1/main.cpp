// Basic operator overloading
#include "point.hpp"
#include <iostream>

int main()
{
	// create a point
	Point p1(2, 3);
	std::cout << p1.ToString() << std::endl;

	// negate the point
	std::cout << "negate: " << (-p1).ToString() << std::endl;

	// scale the point
	std::cout << "scale: " << (p1 * 2).ToString() << std::endl;

	// add a point
	Point p2(1, 1);
	std::cout << "add " << p2.ToString() << ": " << (p1 + p2).ToString()
		<< std::endl;

	// compare equality
	std::cout << "Compare: " << ((p1 == p2) ? "Equal" : "Unequal") << std::endl;

	// self-assignment
	p1 = p1;

	// assignment
	Point p3 = p1;
	std::cout << "Assignment: " << p3.ToString() << std::endl;

	// scale coordinates and assign
	std::cout << "Scale and assign: " << (p1 *= 2).ToString() << std::endl;

	return 0;
}