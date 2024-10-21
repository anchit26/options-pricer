// virtual destructors
#include "shape.hpp"
#include "line.hpp"
#include "point.hpp"
#include "circle.hpp"

#include <iostream>
using namespace AnchitAgarwal::CAD;

int main() 
{

	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;

	for (int i = 0; i != 3; i++)
	{
		std::cout << "Iteration: " << i << std::endl;
		delete shapes[i];
		std::cout << "Complete" << std::endl;
	}
		
}

// output without virtual destructor
// derived class destructors NOT called
/*
Iteration: 0
Shape destructor
Complete
Iteration: 1
Shape destructor
Complete
Iteration: 2
Shape destructor
Complete
*/

// with virtual destructor - destructors called properly
/*
Iteration: 0
Shape destructor
Complete
Iteration: 1
Point destructor
Shape destructor
Complete
Iteration: 2
Line destructor
Point destructor
Shape destructor
Point destructor
Shape destructor
Shape destructor
Complete
*/