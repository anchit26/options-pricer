// const functions
#include "point.hpp"
#include <iostream>

int main()
{
	// constant point
	const Point cp(1.5, 3.9);
	
	// compiler error
	//cp.X(4.5);

	std::cout << "Point x coordinate: " << cp.X() << std::endl;
	return 0;
}
