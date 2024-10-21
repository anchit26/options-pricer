// PointArray.hpp
#ifndef POINT_ARRAY_HPP
#define POINT_ARRAY_HPP

#include <ostream>
#include "array.hpp"
#include "point.hpp"

namespace AnchitAgarwal
{
	namespace Containers {
		/**
		 * @brief PointArray class for point objects array
		*/
		class PointArray : public Array<CAD::Point>
		{
		public:

			// Default constructor
			PointArray();

			// Parametrized constructor
			PointArray(unsigned int size);

			// Copy constructor
			PointArray(const PointArray& source);

			// Destructor
			virtual ~PointArray();

			// Assignment operator
			PointArray& operator = (const PointArray& other);

			// Returns the total length between the points in the array
			double Length() const;
		};
	}
}

#endif // !POINT_ARRAY_HPP