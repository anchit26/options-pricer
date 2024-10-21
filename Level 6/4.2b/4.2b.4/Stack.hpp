// Stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

#include "array.hpp"

namespace AnchitAgarwal
{
	namespace Containers {
		/**
		 * @brief Stack class for generic objects
		*/
		template <typename T> 
		class Stack
		{
		private:

			// data through Array<T> class
			// composition: embedded array
			Array<T> m_data;

			// current index of array
			// represents the top of the stack
			int m_current;

		public:

			// Default constructor
			// initializes the data store of the stack with default size
			Stack();

			// Parametrized constructor
			// initializes the data store of the stack with given size
			Stack(int size);

			// Copy constructor
			Stack(const Stack<T>& source);

			// Destructor
			virtual ~Stack();

			// Assignment operator
			Stack<T>& operator = (const Stack<T>& other);

			// Push an element on top of the stack
			void Push(const T& obj);

			// Pop an element from the top of the stack
			T Pop();
		};
	}
}

#ifndef STACK_CPP // STACK_CPP
#include "Stack.cpp"
#endif // !STACK_CPP

#endif // !STACK_HPP