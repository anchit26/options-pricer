// Layering exceptions
#include <iostream>
#include "Stack.hpp"

using namespace AnchitAgarwal::Containers;

int main()
{
	try
	{
		// Stack of int, size 3
		Stack<int> s(3);

		s.Push(1); // stack: | 1
		s.Push(2); // stack: | 1 2
		std::cout << s.Pop() << std::endl; // stack: | 1

		s.Push(3); // stack: | 1 3
		s.Push(4); // stack: | 1 3 4

		//s.Push(5); // results in StackFullException

		std::cout << s.Pop() << std::endl; // stack: | 1 3
		std::cout << s.Pop() << std::endl; // stack: | 1
		std::cout << s.Pop() << std::endl; // stack: |

		std::cout << s.Pop() << std::endl; // results in StackEmptyException
	}
	catch (AnchitAgarwal::Exceptions::ArrayException& e)
	{
		// Handle array exceptions
		std::cout << e.GetMessage() << std::endl;
	}
	catch (AnchitAgarwal::Exceptions::StackException& e)
	{
		// Handle stack exceptions
		std::cout << e.GetMessage() << std::endl;
	}
}
