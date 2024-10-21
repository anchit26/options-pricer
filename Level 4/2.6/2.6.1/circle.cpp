// circle.cpp
#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <sstream>
#include <cmath>

namespace AnchitAgarwal
{
	namespace CAD
	{
		// Default constructor
		Circle::Circle()
		{
			// unit circle with centre at origin
			m_centre = Point(0, 0);
			m_radius = 1;
		}

		// Parametrized
		Circle::Circle(Point centre, double radius)
		{
			m_centre = centre;
			m_radius = radius;
		}

		// Copy constructor
		Circle::Circle(const Circle& c)
		{
			m_centre = c.m_centre;
			m_radius = c.m_radius;
		}

		// Assignment operator
		Circle& Circle::operator = (const Circle& source)
		{
			// handle self-assignment 
			// by comparing memory address
			if (this == &source)
				return *this;

			// using Point class assignment operator
			m_centre = source.m_centre;
			m_radius = source.m_radius;
			return *this;
		}

		// Destructor
		Circle::~Circle() {}

		// ToString
		std::string Circle::ToString() const
		{
			std::stringstream sstream;
			sstream.precision(2);
			sstream << std::fixed << "Circle centre at " << m_centre.ToString() <<
				" with radius " << m_radius;
			return sstream.str();
		}

		// Diameter
		double Circle::Diameter() const
		{
			// 2 * radius 
			return 2 * m_radius;
		}

		// Area
		double Circle::Area() const
		{
			// pi * (radius^2)
			return M_PI * pow(m_radius, 2);
		}

		// Circumference
		double Circle::Circumference() const
		{
			// 2 * pi * radius
			return 2 * M_PI * m_radius;
		}

		// Send to ostream
		std::ostream& operator << (std::ostream& os, const Circle& c)
		{
			return os << "Circle centre at " << c.m_centre << " with radius "
				<< c.m_radius;
		}
	}
}
