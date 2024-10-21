// circle.cpp
#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

namespace AnchitAgarwal
{
	namespace CAD
	{
		// Default constructor
		Circle::Circle() :
			Shape(),
			m_centre(Point(0, 0)),
			m_radius(1)
		{}

		// Parametrized
		Circle::Circle(Point centre, double radius) : 
			Shape(),
			m_centre(centre),
			m_radius(radius) 
		{}

		// Copy constructor
		Circle::Circle(const Circle& c) :
			Shape(c),
			m_centre(c.m_centre),
			m_radius(c.m_radius)
		{}

		// Assignment operator
		Circle& Circle::operator = (const Circle& source)
		{
			// handle self-assignment 
			// by comparing memory address
			if (this == &source)
				return *this;

			// copy base class data
			Shape::operator=(source);

			// copy self data
			m_centre = source.m_centre;
			m_radius = source.m_radius;
			return *this;
		}

		// Destructor
		Circle::~Circle() 
		{
			std::cout << "Circle destructor" << std::endl;
		}

		// ToString
		std::string Circle::ToString() const
		{
			std::string s = Shape::ToString(); // base class description
			std::stringstream sstream;
			sstream.precision(2);
			sstream << std::fixed << "Circle(" << s << ", centre at " 
				<< m_centre.ToString() << " with radius " << m_radius << ")";
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

		// Draw
		void Circle::Draw() const
		{
			std::cout << "Circle Draw()" << std::endl;
		}
	}
}
