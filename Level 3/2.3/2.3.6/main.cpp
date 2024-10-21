// circle class
#include "circle.hpp"
#include <iostream>

int main()
{
	// centre of circle
	Point centre(1, 2);
	double radius = 3;

	// circle object initialization using parametrized constructor
	Circle circle(centre, radius);

	// circle info
	std::cout << circle.ToString() << std::endl;
	
	// centre
	std::cout << "Centre of the circle: " << circle.CentrePoint().ToString() 
		<< std::endl;

	// diamter
	std::cout << "Diameter of the circle: " << circle.Diameter() << std::endl;

	// area of the circle
	std::cout << "Area of the circle is: " << circle.Area() << std::endl;

	return 0;
}
