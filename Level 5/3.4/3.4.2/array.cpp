// array.cpp
#include "array.hpp"

namespace AnchitAgarwal
{
	namespace Containers
	{
		// Default constructor
		Array::Array() : m_size(10), m_data(new CAD::Point[10]) {}

		// Parametrized constructor
		Array::Array(unsigned int size) : m_size(size), m_data(new CAD::Point[size]) {}

		// Copy constructor
		Array::Array(const Array& source) :
			m_size(source.m_size),
			m_data(new CAD::Point[source.m_size])
		{
			// copy data
			for (unsigned int i = 0; i < m_size; ++i)
			{
				// using Point assignment operator
				m_data[i] = source.m_data[i];
			}
		}

		// Destructor
		Array::~Array()
		{
			// free up heap memory
			delete[] m_data;
		}

		// Assignment operator
		Array& Array::operator = (const Array& source)
		{
			// handle self assignment 
			if (this == &source)
				return *this;

			// set size
			m_size = source.m_size;

			// delete old array
			delete[] m_data;

			// allocate new memory
			m_data = new CAD::Point[source.m_size];

			// copy data
			for (unsigned int i = 0; i < m_size; ++i)
			{
				// using Point assignment operator
				m_data[i] = source.m_data[i];
			}

			return *this;
		}

		// SetElement
		void Array::SetElement(const CAD::Point& p, unsigned int idx)
		{
			// handle index out of bounds
			if (idx >= m_size)
				return;

			// using assignment operator of Point
			m_data[idx] = p;
		}

		// GetElement - const version
		// read only access returned, safe access
		const CAD::Point& Array::GetElement(unsigned int idx) const
		{
			// handle index out of bounds
			if (idx >= m_size)
				return m_data[0];

			return m_data[idx];
		}

		// GetElement - non-const version
		CAD::Point& Array::GetElement(unsigned int idx)
		{
			// handle index out of bounds
			if (idx >= m_size)
				return m_data[0];

			return m_data[idx];
		}

		// [] operator
		CAD::Point& Array::operator [] (unsigned int idx)
		{
			// handle index out of bonds
			if (idx >= m_size)
				return m_data[0];

			return m_data[idx];
		}

		// const [] operator
		// read only access returned, safe access
		const CAD::Point& Array::operator [] (unsigned int idx) const
		{
			// handle index out of bonds
			if (idx >= m_size)
				return m_data[0];

			return m_data[idx];
		}

		// Send to ostream
		std::ostream& operator << (std::ostream& os, const Array& arr)
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