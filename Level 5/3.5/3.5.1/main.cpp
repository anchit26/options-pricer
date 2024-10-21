// polymorphic ToString() function
#include "shape.hpp"
#include "line.hpp"
#include "point.hpp"
#include "circle.hpp"

#include <iostream>
using namespace AnchitAgarwal::CAD;

int main() 
{

	Point p(10, 20); // Create point.

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? YES
	std::cout << sp->ToString() << std::endl; // What is printed? ID of the Point (Point's ToString() called)
}

// output of the program
/*
Point(10.0, 20.0)
*/