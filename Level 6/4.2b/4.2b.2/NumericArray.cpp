// NumericArray.cpp
#ifndef NUMERIC_ARRAY_CPP
#define NUMERIC_ARRAY_CPP

#include "NumericArray.hpp"
#include "IncompatibleDimensionException.hpp"

namespace AnchitAgarwal
{
	namespace Containers
	{
		// Default constructor
		template <typename T>
		NumericArray<T>::NumericArray() :
			Array<T>()
		{}

		// Parametrized constructor
		template <typename T>
		NumericArray<T>::NumericArray(unsigned int size) :
			Array<T>(size)
		{}

		// Copy constructor
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) :
			Array<T>(source)
		{}

		// Destructor
		template <typename T>
		NumericArray<T>::~NumericArray() {}

		// Assignment operator
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
		{ 
			if (this == &source)
				return *this;

			// call the base class assignment operator
			Array<T>::operator=(source);

			return *this;
		}

		// * operator, scale elements by factor
		template <typename T>
		NumericArray<double> NumericArray<T>::operator * (double factor) const
		{
			// get the self size using inherited base class getter
			unsigned int size = (*this).Size();
			
			// initialize with size
			NumericArray<double> arr(size);

			// scale by factor and set all elements
			for (unsigned int i = 0; i < size; ++i)
			{
				// uses [] operator and GetElement of Array<T>
				// uses assignment operator and *(double) operator of T
				arr[i] = (*this).GetElement(i) * factor;
			}

			return arr;
		}

		// + operator, add elements
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& other) const
		{
			// get the self size using inherited base class getter
			unsigned int size = (*this).Size();

			// check for unequal sizes
			if (size != other.Size())
				throw Exceptions::IncompatibleDimensionException();

			// initialize with size
			NumericArray<T> arr(size);

			// scale by factor and set all elements
			for (unsigned int i = 0; i < size; ++i)
			{
				// uses [] operator and GetElement of Array<T>
				// uses assignment operator and + operator of T
				arr[i] = (*this).GetElement(i) + other.GetElement(i) ;
			}

			return arr;
		}

		// Dot Product
		template <typename T>
		T NumericArray<T>::DotProduct(const NumericArray<T>& other) const
		{
			if ((*this).Size() != other.Size())
				throw Exceptions::IncompatibleDimensionException();

			for (unsigned int i = 0; i < std::min((*this).Size(), other.Size()); ++i)
			{
				// uses GetElement of Array<T>
				// uses assignment operator, *(T) operator and += operator of T
				dotProduct += (*this).GetElement(i) * other.GetElement(i);
			}
			return dotProduct;
		}
	}
}

#endif // !NUMERIC_ARRAY_CPP