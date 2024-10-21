// array.hpp
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>

namespace AnchitAgarwal
{
	namespace Containers {
		/**
		 * @brief Array class for generic objects
		*/
		template <typename T> class Array
		{
		private:
			// dynamic array
			T* m_data;

			// size of the data array
			unsigned int m_size;

			// default size of the array
			static unsigned int m_def_size;

		public:

			// Default constructor
			Array();

			// Parametrized constructor
			Array(unsigned int size);

			// Copy constructor
			Array(const Array<T>& source);

			// Destructor
			virtual ~Array();

			// Assignment operator
			Array<T>& operator = (const Array<T>& source);

			// Getter
			unsigned int Size() const;

			// set element
			void SetElement(const T& obj, unsigned int idx);

			// GetElement
			T& GetElement(unsigned int idx); // non-const
			const T& GetElement(unsigned int idx) const; // const

			// Get DefaultSize
			static unsigned int DefaultSize();

			// Set DefaultSize
			static void DefaultSize(unsigned int size);

			// [] operator
			T& operator [] (unsigned int idx); // non-const
			const T& operator [] (unsigned int idx) const; // const

			// Send to ostream
			template <typename T>
			friend std::ostream& operator <<  (std::ostream& os, const Array<T>& arr);
		};

		// Size getter
		template <typename T>
		inline unsigned int Array<T>::Size() const
		{
			return m_size;
		}
	}
}

// The compiler sees the implementation and the header file
// in one translation unit due to the preprocessor directives that add 
// array.cpp here
// This is useful for template classes where by design the compiler needs 
// the complete implementation in one translation unit and the developer 
// simply adds the .hpp file keeping things consistent in the main program
#ifndef ARRAY_CPP // ARRAY_CPP
#include "array.cpp"
#endif // !ARRAY_CPP

#endif // !ARRAY_HPP