// inline getters and setters
#include "point.hpp"
#include <iostream>

int main()
{
	Point p(1, 2);

	std::cout << p.ToString() << std::endl;

	// getter test
	std::cout << "Point x coordinate: " << p.X() << std::endl;

	// setter test
	std::cout << "Setting Point x coordinate to 5" << std::endl;
	p.X(5);
	std::cout << "Point x coordinate post setter: " << p.X() << std::endl;

	return 0;
}
