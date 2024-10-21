// static variable for array default size
#include <iostream>
#include "array.hpp"
#include "ArrayException.hpp"

using namespace AnchitAgarwal::Containers;

int main()
{
	try
	{
		Array<int> intArray1;
		Array<int> intArray2;
		Array<double> doubleArray;

		std::cout << intArray1.DefaultSize() << std::endl;
		std::cout << intArray2.DefaultSize() << std::endl;
		std::cout << doubleArray.DefaultSize() << std::endl;

		intArray1.DefaultSize(15);

		std::cout << intArray1.DefaultSize() << std::endl;
		std::cout << intArray2.DefaultSize() << std::endl;
		std::cout << doubleArray.DefaultSize() << std::endl;
	}
	catch (AnchitAgarwal::Exceptions::ArrayException& ex)
	{
		// Handle the exception thrown
		std::cout << ex.GetMessage() << std::endl;
	}
}

// output
// Explanation: The int DefaultSize() setter sets the static variable 
// to 15 for the class Array<int> which is subsequently reflected in the output of
// all instances of this class, i.e, intArray1 and intArray2.
// Since Array<double> is a different class altogether, it does not get updated.
/*
10
10
10
15
15
10
*/