// Point class
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

	// initialize object using default constructor
	Point p;

	// set coordinates
	p.SetX(x);
	p.SetY(y);

	// description
	std::cout << p.ToString() << std::endl;

	// print info using getters
	std::cout << "x coordinate: " << p.GetX() << std::endl;
	std::cout << "y coordinate: " << p.GetY() << std::endl;

	return 0;
}
