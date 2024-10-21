// numeric array (generic inheritance)
#include <iostream>
#include "point.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"

using namespace AnchitAgarwal;

int main()
{
	try
	{
		// int
		Containers::NumericArray<int> intArr1; // default size
		Containers::NumericArray<int> intArr2(3); // size 3
		intArr2[0] = 1;  intArr2[1] = 2; intArr2[2] = 3; // set elements

		// double
		Containers::NumericArray<double> doubleArr1(3); // size 3
		Containers::NumericArray<double> doubleArr2(3); // size 3
		doubleArr1[0] = 3;  doubleArr1[1] = 2; doubleArr1[2] = 1; // set elements
		doubleArr2[0] = 1;  doubleArr2[1] = 2; doubleArr2[2] = 3; // set elements

		// Point
		Containers::NumericArray<CAD::Point> pointArr1(3);
		Containers::NumericArray<CAD::Point> pointArr2(3);

		// int Array
		std::cout << intArr2 * 4.1 << std::endl; // scale
		//intArr1 + intArr2; // throws runtime exception due to diff sizes

		// double Array
		std::cout << doubleArr1 + doubleArr2 << std::endl; // sum
		std::cout << doubleArr1.DotProduct(doubleArr2) << std::endl; // dot product

		// Point Array
		std::cout << pointArr1 + pointArr2 << std::endl; // sum

		//compiler error: Point class does not define all the required operators. 
		// Additionally a Point is not a Numeric and therefore should not be 
		// expected to work with NumericArray<T>
		//std::cout << pointArr1.DotProduct(pointArr2) << std::endl; // dot product

	}
	catch (AnchitAgarwal::Exceptions::ArrayException& e)
	{
		// Handle the exception thrown
		std::cout << e.GetMessage() << std::endl;
	}
}

/*
* NumericArray<T> - T assumptions
* should be a numeric
* defines these operators +=, *(double), *(T), =, + 
*/
