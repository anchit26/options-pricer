// line.cpp
#include "line.hpp"
#include <sstream>

namespace AnchitAgarwal
{
	namespace CAD
	{
		// Default constructor
		Line::Line()
		{
			m_start = Point(0, 0);
			m_end = Point(0, 0);
		}

		// Parametrized constructor
		Line::Line(Point start, Point end)
		{
			m_start = start;
			m_end = end;
		}

		// Copy constructor
		Line::Line(const Line& l)
		{
			m_start = l.m_start;
			m_end = l.m_end;
		}

		// Assignment operator
		Line& Line::operator = (const Line& source)
		{
			// handle self-assignment
			// by comparing memory address
			if (this == &source)
				return *this;

			// using Point class assignment operator
			m_start = source.m_start;
			m_end = source.m_end;
			return *this;
		}

		// Destructor
		Line::~Line() {}

		// Description
		std::string Line::ToString() const
		{
			std::stringstream sstream;
			sstream << "Line from " << m_start.ToString() << " to "
				<< m_end.ToString();
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