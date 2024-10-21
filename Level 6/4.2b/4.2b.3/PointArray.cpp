// PointArray.cpp
#include "PointArray.hpp"

namespace AnchitAgarwal
{
	namespace Containers {
		
		// Default constructor
		PointArray::PointArray() :
			Array<CAD::Point>()
		{}

		// Parametrized constructor
		PointArray::PointArray(unsigned int size) :
			Array<CAD::Point>(size)
		{}

		// Copy constructor
		PointArray::PointArray(const PointArray& source) :
			Array<CAD::Point>(source)
		{}

		// Destructor
		PointArray::~PointArray() {}

		// Assignment operator
		PointArray& PointArray::operator = (const PointArray& other)
		{
			if (this == &other)
				return *this;

			// call base class assignment operator
			Array<CAD::Point>::operator=(other);

			return *this;
		}

		// Returns the total length between the points in the array
		double PointArray::Length() const
		{
			double length = 0; // initialize to 0

			for (unsigned int i = 0; i < (*this).Size() - 1; ++i)
			{
				// calculate distance between adjacent points using Point::Distance()
				length += (*this).GetElement(i).Distance((*this).GetElement(i+1));
			}

			return length;
		}
	}
}