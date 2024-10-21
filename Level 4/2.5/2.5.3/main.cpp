// creating array of pointers
#include "array.hpp"
#include <iostream>

int main() {
   
	// create an array using default ctor
	Array arr;
	std::cout << "Default Array size: " << arr.Size() << std::endl;


	// create an array using parametrized constructor
	Array arr1(3);
	std::cout << "Parametrized ctor array size: " << arr1.Size() << std::endl;

	// set element
	arr1.SetElement(Point(1, 2), 0);
	arr1.SetElement(Point(2, 3), 1);
	arr1.SetElement(Point(3, 5), 2);

	// get element non-const
	Point& pRef = arr1.GetElement(2);
	std::cout << "Got element: " << pRef << std::endl;

	// [] operator const
	const Point& pCRef = arr1[0]; 
	//pCRef[1] = p; // gives compiler error

	// copy constructor
	Array arr2 = arr1;
	std::cout << "Copy constructed array size: " << arr2.Size() << std::endl;
	std::cout << "Copy constructed array using << operator: " << arr2 << std::endl;

	// assignment operator
	Array arr3;
	arr3 = arr1;
	std::cout << "Assigned array size: " << arr3.Size() << std::endl;
	std::cout << "Get element through [] operator: " << arr3[2] << std::endl;

	return 0;
}