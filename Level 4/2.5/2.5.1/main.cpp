// dynamically creating objects
#include "point.hpp"
#include <iostream>

int main()
{
	// create points
	Point* p_def_ctor = new Point();
	Point* p_param_ctor = new Point(1, 1);
	Point* p_copy_ctor = new Point(*p_param_ctor);

	// Distance function
	std::cout << "Distance of " << *p_def_ctor << " to " << *p_copy_ctor << ": "
		<< p_def_ctor->Distance(*p_copy_ctor) << std::endl;

	// free heap memory
	delete p_def_ctor;
	delete p_param_ctor;
	delete p_copy_ctor;

	// arrays
	// user input
	unsigned int size;
	std::cout << "Enter the array size: ";
	std::cin >> size;

	// on stack - compiler error with variable size
	//Point points[size];

	// on heap, using default ctor
	// cannot use other ctor
	Point* points = new Point[size];

	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << points[i] << std::endl;
	}

	// free the heap memory 
	delete[] points;
	return 0;
}