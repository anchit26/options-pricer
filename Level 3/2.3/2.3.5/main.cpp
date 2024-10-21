// line through composition
#include "line.hpp"
#include <iostream>

int main()
{
	// point objects initialization using paramterized constructor
	Point p1(1, 2);
	Point p2(3, 4);

	// line objects initialization using parametrized constructor
	Line l(p1, p2);

	// line info
	std::cout << l.P1().ToString() << std::endl;
	const Point point = l.P1(); // write on this wouldn't be a compiler error
	const Point& p = l.P1(); // write on this will be compiler error
	std::cout << l.ToString() << std::endl;
	std::cout << "Line length: " << l.Length() << std::endl;
	return 0;
}
