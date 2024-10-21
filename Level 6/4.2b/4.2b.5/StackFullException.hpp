//StackFullException.hpp

#ifndef STACK_FULL_EXCEPTION_HPP
#define STACK_FULL_EXCEPTION_HPP

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
		class StackFullException : public StackException
		{
		public:

			// Default constructor
			StackFullException() {}

			// GetMessage
			std::string GetMessage() const
			{
				std::stringstream sstream;
				sstream << "stack is full";
				return sstream.str();
			}
		};
	}
}

#endif // !STACK_FULL_EXCEPTION_HPP