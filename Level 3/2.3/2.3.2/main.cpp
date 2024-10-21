// pass by reference
#include "point.hpp"
#include <iostream>

int main()
{
	// take user input 
	double x, y;
	std::cout << "Enter x coordinate: ";
	std::cin >> x;

	std::cout << "Enter y coordinate: ";
	std::cin >> y;

	// using parametrized constructor
	Point p1(x, y);

	// distance from a point
	Point p2;
	p2.SetX(1);
	p2.SetY(1);

	std::cout << "Distance of " << p1.ToString() << " from " <<
		p2.ToString() << " is " << p1.Distance(p2) << std::endl;

	return 0;
}
