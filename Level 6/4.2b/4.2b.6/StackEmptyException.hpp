//StackEmptyException.hpp

#ifndef STACK_EMPTY_EXCEPTION_HPP
#define STACK_EMPTY_EXCEPTION_HPP

#include <string>
#include <sstream>
#include "StackException.hpp"

namespace AnchitAgarwal
{
	namespace Exceptions
	{
		/**
		 * @brief Represents the Stack Exception class
		*/
		class StackEmptyException : public StackException
		{
		public:

			// Default constructor
			StackEmptyException() {}

			// GetMessage
			std::string GetMessage() const
			{
				std::stringstream sstream;
				sstream << "stack is empty";
				return sstream.str();
			}
		};
	}
}

#endif // !STACK_EMPTY_EXCEPTION_HPP