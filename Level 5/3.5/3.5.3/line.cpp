// line.cpp
#include "line.hpp"
#include <sstream>
#include <iostream>

namespace AnchitAgarwal
{
	namespace CAD
	{
		// Default constructor
		Line::Line() : 
			Shape(),
			m_start(Point(0, 0)),
			m_end(Point(0, 0))
		{}

		// Parametrized constructor
		Line::Line(Point start, Point end) :
			Shape(),
			m_start(start),
			m_end(end)
		{}

		// Copy constructor
		Line::Line(const Line& l) :
			Shape(l),
			m_start(l.m_start),
			m_end(l.m_end)
		{}

		// Assignment operator
		Line& Line::operator = (const Line& source)
		{
			// handle self-assignment
			// by comparing memory address
			if (this == &source)
				return *this;

			// copy base class data
			Shape::operator=(source);

			// copy self data
			m_start = source.m_start;
			m_end = source.m_end;
			return *this;
		}

		// Destructor
		Line::~Line() 
		{
			std::cout << "Line destructor" << std::endl;
		}

		// Description
		std::string Line::ToString() const
		{
			std::string s = Shape::ToString(); // base class description
			std::stringstream sstream;
			sstream << "Line(" << s << ", from " << m_start.ToString()
				<< " to " << m_end.ToString() << ")";
			return sstream.str();
		}

		// Length
		double Line::Length() const
		{
			return m_start.Distance(m_end);
		}

		// Send to ostream
		std::ostream& operator << (std::ostream& os, const Line& l)
		{
			return os << "Line from " << l.m_start << " to "
				<< l.m_end;
		}
	}
}