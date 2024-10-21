// exception objects
#include <iostream>
#include "array.hpp"
#include "ArrayException.hpp"

using namespace AnchitAgarwal::Containers;

int main()
{
	try
	{
		Array arr; // Default arr of 10 size

		std::cout << arr[9].ToString() << std::endl; // works fine

		std::cout << arr[11].ToString() << std::endl; // throws OOB
	}
	catch (AnchitAgarwal::Exceptions::ArrayException& ex)
	{
		// Handle the exception thrown
		std::cout << ex.GetMessage() << std::endl;
	}
}