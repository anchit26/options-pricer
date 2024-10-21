// array.cpp
#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "array.hpp"
#include "OutOfBoundsException.hpp"

namespace AnchitAgarwal
{
	namespace Containers
	{
		// initalize the static member
		template <typename T> 
		unsigned int Array<T>::m_def_size = 10;

		// Default constructor
		template <typename T> 
		Array<T>::Array() : 
			m_size(m_def_size),
			m_data(new T[m_def_size])
		{}

		// Parametrized constructor
		template <typename T>
		Array<T>::Array(unsigned int size) : 
			m_size(size), 
			m_data(new T[size]) 
		{}

		// Copy constructor
		template <typename T>
		Array<T>::Array(const Array<T>& source) :
			m_size(source.m_size),
			m_data(new T[source.m_size])
		{
			// copy data
			for (unsigned int i = 0; i < m_size; ++i)
			{
				// using T's assignment operator
				m_data[i] = source.m_data[i];
			}
		}

		// Destructor
		template <typename T>
		Array<T>::~Array()
		{
			// free up heap memory
			delete[] m_data;
		}

		// Assignment operator
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
		{
			// handle self assignment 
			if (this == &source)
				return *this;

			// set size
			m_size = source.m_size;

			// delete old array
			delete[] m_data;

			// allocate new memory
			m_data = new T[source.m_size];

			// copy data
			for (unsigned int i = 0; i < m_size; ++i)
			{
				// uses T's assignment operator
				m_data[i] = source.m_data[i];
			}

			return *this;
		}

		// SetElement
		template <typename T>
		void Array<T>::SetElement(const T& obj, unsigned int idx)
		{
			// handle index out of bounds
			if (idx < 0 || idx >= m_size)
				throw Exceptions::OutOfBoundsException(idx);

			// using assignment operator of T
			m_data[idx] = obj;
		}

		// GetElement - const version
		// read only access returned, safe access
		template <typename T>
		const T& Array<T>::GetElement(unsigned int idx) const
		{
			// handle index out of bounds
			if (idx < 0 || idx >= m_size)
				throw Exceptions::OutOfBoundsException(idx);

			return m_data[idx];
		}

		// GetElement - non-const version
		template <typename T>
		T& Array<T>::GetElement(unsigned int idx)
		{
			// handle index out of bounds
			if (idx < 0 || idx >= m_size)
				throw Exceptions::OutOfBoundsException(idx);

			return m_data[idx];
		}

		// DefaultSize getter
		template <typename T>
		unsigned int Array<T>::DefaultSize()
		{
			return m_def_size;
		}

		// DefaultSize setter
		template <typename T>
		void Array<T>::DefaultSize(unsigned int size)
		{
			m_def_size = size;
		}

		// [] operator
		template <typename T>
		T& Array<T>::operator [] (unsigned int idx)
		{
			// handle index out of bonds
			if (idx < 0 || idx >= m_size)
				throw Exceptions::OutOfBoundsException(idx);

			return m_data[idx];
		}

		// const [] operator
		// read only access returned, safe access
		template <typename T>
		const T& Array<T>::operator [] (unsigned int idx) const
		{
			// handle index out of bonds
			if (idx < 0 || idx >= m_size)
				throw Exceptions::OutOfBoundsException(idx);

			return m_data[idx];
		}

		// Send to ostream
		template <typename T>
		std::ostream& operator << (std::ostream& os, const Array<T>& arr)
		{
			os << "[";
			// iterate over all objects and print them
			for (unsigned int i = 0; i < arr.m_size; ++i)
			{
				os << arr.m_data[i];

				// string formatting till
				// penultimate element
				if (i != arr.m_size - 1)
					os << ", ";
			}
			os << "]";
			return os;
		}
	}
}

#endif // !ARRAY_CPP