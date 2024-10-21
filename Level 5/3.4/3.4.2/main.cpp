// shape base class
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

	std::cout << "Shape ID: " << s.ID() << std::endl; // ID of the shape.
	std::cout << "Point ID: " << p.ID() << std::endl; // ID of the point. Does this work? YES public access during inheritance
	std::cout << "Line ID: " << l.ID() << std::endl; // ID of the line. Does this work? YES public access during inheritance

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? YES
	std::cout << sp->ToString() << std::endl; // What is printed? ID of the Point (Shape's ToString() called)

	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	std::cout << p2 << ", " << p2.ID() << std::endl; 
	// Is the ID copied if you do not call the base class assignment in point?
	// No, if base class assignment not called, ID not copied
}

// one output of the program
/*
ID: 41
Point(10.0, 20.0)
Line from Point(1.0, 2.0) to Point(3.0, 4.0)
Shape ID: 41
Point ID: 18467
Line ID: 19169
ID: 18467
Point(10, 20), 18467
*/