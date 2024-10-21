// point.cpp
#include "point.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

namespace AnchitAgarwal
{
	namespace CAD
	{
		// Default constructor
		// initialize point to origin
		Point::Point() :
			Shape(),
			m_x(0.0),
			m_y(0.0)
		{}

		// Parametrized constructor
		Point::Point(double x, double y) : 
			Shape(),
			m_x(x),
			m_y(y)
		{}

		// Copy constructor
		Point::Point(const Point& p) : 
			Shape(p),
			m_x(p.m_x), 
			m_y(p.m_y)
		{}

		// Destructor
		Point::~Point() 
		{
			std::cout << "Point destructor" << std::endl;
		}

		// ToString 
		std::string Point::ToString() const
		{
			std::string s = Shape::ToString(); // base class description
			std::stringstream sstream;
			sstream.precision(1);
			sstream << std::fixed << "Point(" << s << ", {" << m_x << ", " 
				<< m_y << "})";
			return sstream.str();
		}

		// Distance from origin
		double Point::Distance() const
		{
			Point origin(0.0, 0.0);
			return Distance(origin);
		}

		// Distance from point p using pythagoras algorithm
		double Point::Distance(const Point& p) const
		{
			double x_squared = pow(abs(p.m_x - m_x), 2); // (x1 - x2)^2
			double y_squared = pow(abs(p.m_y - m_y), 2); // (y1 - y2)^2
			return sqrt(x_squared + y_squared); // sqrt
		}

		// Negate the coordinates
		Point Point::operator - () const
		{
			return Point(-1 * m_x, -1 * m_y);
		}

		// Scale the coordinates
		Point Point::operator * (double factor) const
		{
			return Point(factor * m_x, factor * m_y);
		}

		// Add coordinates
		Point Point::operator + (const Point& p) const
		{
			return Point(m_x + p.m_x, m_y + p.m_y);
		}

		// Equality compare
		bool Point::operator == (const Point& p) const
		{
			return m_x == p.m_x && m_y == p.m_y;
		}

		// Assignment operator
		Point& Point::operator = (const Point& source)
		{
			// handle self assignment
			// by comparing memory address
			if (this == &source)
				return *this;

			// copy base class data
			Shape::operator=(source);

			// copy self data
			this->m_x = source.m_x;
			this->m_y = source.m_y;
			return *this;
		}

		// Scale the coordinates and assign
		Point& Point::operator *= (double factor)
		{
			// use the scale operator to scale
			// use the assignment operator to copy
			*this = *this * factor;
			return *this;
		}

		// Send to ostream
		std::ostream& operator << (std::ostream& os, const Point& p)
		{
			return os << "Point(" << p.m_x << ", " << p.m_y << ")";
		}
	}
}
