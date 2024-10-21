// Variant
#include <iostream>
#include <boost/variant.hpp>

#include "shape.hpp"
#include "array.hpp"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"

using namespace AnchitAgarwal;

// typedef for a shape type
typedef boost::variant<CAD::Point, CAD::Line, CAD::Circle> ShapeType;

// Takes user input for shape type
// creates that type of shape and returns it
ShapeType CreateShape();

/**
 * @brief Represents the visitor class for ShapeType variant
*/
class ShapeTypeVisitor : boost::static_visitor<void>
{
private:
	double m_dx;
	double m_dy;

public:
	// Param contructor
	ShapeTypeVisitor(double x, double y) : m_dx(x), m_dy(y) {}

	void operator () (CAD::Point& p) const; // operator() Point
	void operator () (CAD::Line& l) const; // operator() Line
	void operator () (CAD::Circle& c) const; // operator() Circle
};

int main()
{
	try
	{
		ShapeType shape = CreateShape();
		std::cout << shape << std::endl; // print shape

		// assigning shape to Line
		CAD::Line line = boost::get<CAD::Line>(shape);
		std::cout << line << std::endl;

		// variants with different shapes
		ShapeType s1 = CAD::Point();
		ShapeType s2 = CAD::Line(CAD::Point(1, 1), CAD::Point(2, 2));
		ShapeType s3 = CAD::Circle();

		// visitor instance
		ShapeTypeVisitor shape_shifter(1, 3);

		// Apply the visitor
		boost::apply_visitor(shape_shifter, s1);
		boost::apply_visitor(shape_shifter, s2);
		boost::apply_visitor(shape_shifter, s3);

		// Print the results
		std::cout << s1 << std::endl;
		std::cout << s2 << std::endl;
		std::cout << s3 << std::endl;

	}
	catch (boost::bad_get& e)
	{
		// catch bad assignment of variant
		std::cout << "exception caught: " << e.what() << std::endl;
	}
}

// CreateShape()
ShapeType CreateShape()
{
	// Take user input
	std::cout << "Enter the type of shape:\n"
		<< "Enter [1] for Point\n"
		<< "Enter [2] for Line\n"
		<< "Enter [3] for Circle\n";

	int req_shape = 0;
	std::cin >> req_shape;

	// Select shape type based on user request
	ShapeType shape;
	switch (req_shape)
	{
	case 1:
		shape = CAD::Point(2.5, 3.3);
		break;
	case 2:
		shape = CAD::Line();
		break;
	case 3:
		shape = CAD::Circle();
		break;
	default:
		std::cout << "Invalid input given" << '\n';
		exit(1);
	}

	return shape;
}

// ShapeTypeVisitor () Point
void ShapeTypeVisitor::operator () (CAD::Point& p) const
{
	p.X(p.X() + m_dx); // shift x coordinate
	p.Y(p.Y() + m_dy); // shift y coordinate
}

// ShapeTypeVisitor () Line
void ShapeTypeVisitor::operator () (CAD::Line& l) const
{
	// temporary start & end point to pass to Point Visitor
	CAD::Point start = l.P1();
	CAD::Point end = l.P2();

	// Pass to point visitor
	ShapeTypeVisitor::operator()(start); 
	ShapeTypeVisitor::operator()(end);

	// Set the shifted points in line
	l.P1(start);
	l.P2(end);
}

// ShapeTypeVisitor () Circle
void ShapeTypeVisitor::operator () (CAD::Circle& c) const
{
	// temporary center point 
	CAD::Point centre = c.CentrePoint();

	// Pass to point visitor
	ShapeTypeVisitor::operator()(centre);

	// Set the shifted center in circle
	c.CentrePoint(centre);
}