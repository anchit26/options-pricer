// shape.cpp
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "shape.hpp"

namespace AnchitAgarwal
{
	namespace CAD
	{
		// Default constructor
		// assigns a random number
		Shape::Shape() : m_id(rand()) {}

		// Copy constructor
		Shape::Shape(const Shape& s) : m_id(s.m_id) {}

		// Destructor
		Shape::~Shape() {}

		// Assignment operator
		Shape& Shape::operator = (const Shape& source)
		{
			// handle self assignment
			if (this == &source)
				return *this;

			this->m_id = source.m_id;
			return *this;
		}

		// ToString
		std::string Shape::ToString() const
		{
			std::stringstream sstream;
			sstream.precision(1);
			sstream << std::fixed << "ID: " << m_id;
			return sstream.str();
		}

		// ID getter
		int Shape::ID() const
		{
			return m_id;
		}
	}
}
