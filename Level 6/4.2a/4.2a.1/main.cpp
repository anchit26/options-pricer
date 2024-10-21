// introduction to templates
#include <iostream>
#include "array.hpp"
#include "ArrayException.hpp"
#include "point.hpp"

using namespace AnchitAgarwal;

int main()
{
	try
	{
		//Array arr; // gives compiler error
		
		int size = 5;
		Containers::Array<CAD::Point> p_arr(size); // Point array

		std::cout << "Size of array: " << p_arr.Size() << std::endl;
		std::cout << p_arr << std::endl; 
	}
	catch (AnchitAgarwal::Exceptions::ArrayException& ex)
	{
		// Handle the exception thrown
		std::cout << ex.GetMessage() << std::endl;
	}
}