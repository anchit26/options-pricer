// function overloading
#include "point.hpp"
#include <iostream>

int main()
{
	// using parametrized constructor
	Point p1(3, 4);

	// using overloaded setters
	Point p2;
	p2.X(1);
	p2.Y(2);

	// distance from a point 
	std::cout << "Distance of " << p1.ToString() << " from " 
		<< p2.ToString() << " is " << p1.Distance(p2) << std::endl;

	// distance from origin using function overloading
	std::cout << "Distance of " << p1.ToString() << " from Point(0, 0) is " 
		<< p1.Distance() << std::endl;

	return 0;
}