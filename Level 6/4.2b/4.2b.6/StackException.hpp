//StackException.hpp

#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

#include <string>

namespace AnchitAgarwal
{
	namespace Exceptions
	{
		/**
		 * @brief Represents the Stack Exception class
		*/
		class StackException
		{
		public:

			// GetMessage
			virtual std::string GetMessage() const = 0;
		};
	}
}

#endif // !STACK_EXCEPTION_HPP