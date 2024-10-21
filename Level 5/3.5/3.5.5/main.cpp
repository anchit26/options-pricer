// template method pattern
#include "shape.hpp"
#include "line.hpp"
#include "point.hpp"
#include "circle.hpp"

#include <iostream>
using namespace AnchitAgarwal::CAD;

int main() 
{
	Shape* shapes[2];
	shapes[0] = new Line;
	shapes[1] = new Point;

	for (int i = 0; i != 2; i++) shapes[i]->Print();
	for (int i = 0; i != 2; i++) delete shapes[i];

	return 0;
}

// incomplete implementation
// output without `virtual` Shape::ToString()
/*
ID: 41
ID: 26500
*/

// correct implementation - polymorphism
// output with `virtual` Shape::ToString()
// prints the right information even when Point, Line do not define Print()
/*
Line(ID: 41, from Point(ID: 18467, {0.0, 0.0}) to Point(ID: 6334, {0.0, 0.0}))
Point(ID: 26500, {0.0, 0.0})
*/