// smart pointers
#include <iostream>
#include <boost/shared_ptr.hpp>

#include "shape.hpp"
#include "array.hpp"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"

using namespace AnchitAgarwal;

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<CAD::Shape> ShapePtr;
typedef Containers::Array<ShapePtr> ShapeArray;

int main()
{
	ShapePtr sp1(new CAD::Point(1, 1)); // ShapePtr to Point
	
	CAD::Point* point2 = new CAD::Point(2, 2);
	ShapePtr sp2 = ShapePtr(point2); // copy constructor of shared_ptr
	std::cout << "Ref count of point2 object: " << sp2.use_count() << std::endl; // 1
	
	{
		// array of shape pointers
		ShapeArray shape_arr(4);

		ShapePtr sp3(new CAD::Line()); // line ShapePtr
		//ShapePtr sp4(new CAD::Circle())

		// assign shapes to the pointers
		shape_arr[0] = sp1;
		shape_arr[1] = sp2;
		shape_arr[2] = sp3;
		shape_arr[3] = ShapePtr(new CAD::Circle(*point2, 1));

		std::cout << "Ref count of point2 object: " << sp2.use_count() << std::endl; // 2
		// print shape info
		for (int i = 0; i < 4; i++)
		{
			shape_arr[i]->Print();
			std::cout << "Ref count of ptr " << i << ": " <<
				shape_arr[i].use_count() << std::endl;
		}
	}
	// Line memory auto deleted

	std::cout << "Ref count of point2 object: " << sp2.use_count() << std::endl; // 1
	return 0;
}