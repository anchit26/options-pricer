// Calling base class functionality
#include "shape.hpp"
#include "line.hpp"
#include "point.hpp"
#include "circle.hpp"

#include <iostream>
using namespace AnchitAgarwal::CAD;

int main() 
{

	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.

	std::cout << s.ToString() << std::endl; // Print shape.
	std::cout << p.ToString() << std::endl; // Print point.
	std::cout << l.ToString() << std::endl; // Print line

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? YES
	std::cout << sp->ToString() << std::endl; // What is printed? ID of the Point (Point's ToString() called)
}
