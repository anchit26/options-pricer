// bounds checking array
#include <iostream>
#include "array.hpp"

using namespace AnchitAgarwal::Containers;

int main()
{
	try
	{
		Array arr; // Default arr of 10 size

		std::cout << arr[9].ToString() << std::endl; // works fine

		std::cout << arr[11].ToString() << std::endl; // throws -1
	}
	catch (int e)
	{
		// Handle the int exception thrown
		std::cout << "Caught an integer exception: " << e << std::endl;
	}
}