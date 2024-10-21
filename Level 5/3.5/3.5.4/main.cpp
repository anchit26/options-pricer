// abstract functions
#include "shape.hpp"
#include "line.hpp"
#include "point.hpp"
#include "circle.hpp"

#include <iostream>
using namespace AnchitAgarwal::CAD;

int main() 
{
	//Shape shape; // gives compiler error as Shape is abstract

	Shape* shapes[4];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Circle(Point(1, 2), 2);

	for (int i = 0; i != 4; i++) shapes[i]->Draw();
	for (int i = 0; i != 4; i++) delete shapes[i];

	return 0;
}

// output
/*
Line Draw()
Point Draw()
Line Draw()
Circle Draw()
*/