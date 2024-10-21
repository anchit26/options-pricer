// concrete inheritance
#include <iostream>
#include "PointArray.hpp"

using namespace AnchitAgarwal;

int main()
{
	try
	{
		// point array of size 4
		Containers::PointArray p_arr(4);
		p_arr[0] = CAD::Point(1, 2);
		p_arr[1] = CAD::Point(2, 3);
		p_arr[2] = CAD::Point(3, 4);
		p_arr[3] = CAD::Point(5.5, 6.7);

		// size of p_arr
		std::cout << "Size of point array: " << p_arr.Size() << std::endl;

		// print p_arr
		std::cout << p_arr << std::endl;

		// length of p_arr
		std::cout << "Length of point array: " << p_arr.Length() << std::endl;
	}
	catch (AnchitAgarwal::Exceptions::ArrayException& e)
	{
		// Handle the exception thrown
		std::cout << e.GetMessage() << std::endl;
	}
}
