// NumericArray.hpp
#ifndef NUMERIC_ARRAY_HPP
#define NUMERIC_ARRAY_HPP

#include "array.hpp"
#include <ostream>

namespace AnchitAgarwal
{
	namespace Containers {
		/**
		 * @brief Array class for generic objects
		*/
		template <typename T> 
		class NumericArray : public Array<T>
		{
		public:

			// Default constructor
			NumericArray();

			// Parametrized constructor
			NumericArray(unsigned int size);

			// Copy constructor
			NumericArray(const NumericArray<T>& source);

			// Destructor
			virtual ~NumericArray();

			// Assignment operator
			NumericArray<T>& operator = (const NumericArray<T>& source);

			// Operators
			NumericArray<double> operator * (double factor) const; // scale elements by factor
			NumericArray<T> operator + (const NumericArray<T>& other) const; // add elements
			T DotProduct(const NumericArray<T>& other) const; // Dot product
		};
	}
}

#ifndef NUMERIC_ARRAY_CPP // NUMERIC_ARRAY_CPP
#include "NumericArray.cpp"
#endif // !NUMERIC_ARRAY_CPP

#endif // !NUMERIC_ARRAY_HPP