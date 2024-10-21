// shape.hpp
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
namespace AnchitAgarwal
{
	namespace CAD
	{
		/**
		 * @brief Represents the Shape class
		*/
		class Shape
		{
		private:

			// identifier
			int m_id;
			
		public:

			// Default constructor
			Shape();

			// Copy constructor
			Shape(const Shape& s);

			// Destructors
			virtual ~Shape();

			// Assignment operator
			Shape& operator = (const Shape& s);

			// ToString 
			virtual std::string ToString() const;

			// ID getter
			int ID() const;

		};
	}
}

#endif // !SHAPE_HPP