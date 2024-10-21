// Stack.cpp
#ifndef STACK_CPP
#define STACK_CPP

#include "ArrayException.hpp"
#include "Stack.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"

namespace AnchitAgarwal
{
	namespace Containers {

		// Default constructor
		template <typename T>
		Stack<T>::Stack() :
			m_data(),
			m_current(0)
		{}

		// Parametrized constructor
		template <typename T>
		Stack<T>::Stack(int size) :
			m_data(size),
			m_current(0)
		{}

		// Copy constructor
		template <typename T>
		Stack<T>::Stack(const Stack<T>& source) :
			m_data(source),
			m_current(0)
		{}

		// Destructor
		template <typename T>
		Stack<T>::~Stack() {}

		// Assignment operator
		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& other)
		{
			// handle self assignment
			if (this == &other)
				return *this;

			// copy 
			m_data = other.m_data; // uses assignment operator of Array<T>
			m_current = other.m_current;

			return *this;
		}

		// Push
		template <typename T>
		void Stack<T>::Push(const T& obj)
		{
			try
			{
				// throws OOB exception from the use of Array<T>::operator[]
				// also uses assignment operator of T
				m_data[m_current] = obj;

				// increase current index if push successful
				m_current++;
			}
			catch (Exceptions::ArrayException&)
			{
				// throw stack full exception
				throw Exceptions::StackFullException();
			}
		}

		// Pop
		template <typename T>
		T Stack<T>::Pop()
		{
			try 
			{
				// thorws OOB exception from the use of Array<T>::operator[]
				// also uses assignment operator of T
				T obj = m_data[m_current - 1];

				// decrement the current index if array read successful
				m_current--;

				return obj;
			}
			catch (Exceptions::ArrayException&)
			{
				m_current = 0; // set current index to 0
				// throw stack empty exception
				throw Exceptions::StackEmptyException();
			}
		}
	}
}

#endif // !STACK_CPP