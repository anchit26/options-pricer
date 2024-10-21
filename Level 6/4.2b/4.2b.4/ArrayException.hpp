//arrayException.hpp

#ifndef ARRAY_EXCEPTION_HPP
#define ARRAY_EXCEPTION_HPP

#include <string>

namespace AnchitAgarwal
{
	namespace Exceptions
	{
		/**
		 * @brief Represents the Array Exception class
		*/
		class ArrayException
		{
		public:

			// GetMessage
			virtual std::string GetMessage() const = 0;
		};
	}
}

#endif // !ARRAY_EXCEPTION_HPP