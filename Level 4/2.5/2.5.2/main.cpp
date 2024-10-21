// creating array of pointers
#include "point.hpp"
#include <iostream>

int main()
{
	// array size
	const unsigned int size = 3;
	
	// create array of Point pointers
	Point** points = new Point*[size];
	
	// initialize on heap with various ctors
	points[0] = new Point(); // default ctor
	points[1] = new Point(1, 1); // param ctor
	points[2] = new Point(*points[1]); // copy ctor

	// iterate and print
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << *points[i] << std::endl;
	}

	// iterate and delete point objects
	for (unsigned int i = 0; i < size; ++i)
	{
		delete points[i];
	}

	// free the array memory
	delete[] points;
	return 0;
}