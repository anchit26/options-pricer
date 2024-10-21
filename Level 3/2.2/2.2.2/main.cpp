// distance functions
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
	Point p1;

	// set coordinates
	p1.SetX(x);
	p1.SetY(y);

	// description
	std::cout << p1.ToString() << std::endl;

	// print info using getters
	std::cout << "x coordinate: " << p1.GetX() << std::endl;
	std::cout << "y coordinate: " << p1.GetY() << std::endl;

	// distance from origin
	std::cout << "Distance of Point " << p1.ToString() << " from origin: "
		<< p1.DistanceOrigin() << std::endl;

	// distance from a point
	Point p2;
	p2.SetX(1);
	p2.SetY(1);
	std::cout << "Distance of Point " << p1.ToString() << " from " <<
		p2.ToString() << " is " << p1.Distance(p2) << std::endl;

	return 0;
}
