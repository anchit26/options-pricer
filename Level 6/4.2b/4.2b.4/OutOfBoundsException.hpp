//OutOfBoundsException.hpp

#ifndef OUT_OF_BOUNDS_EXCEPTION_HPP
#define OUT_OF_BOUNDS_EXCEPTION_HPP

#include "ArrayException.hpp"
#include <sstream>

namespace AnchitAgarwal
{
	namespace Exceptions
	{
		/**
		 * @brief Represents the Out Of Bounds Exception class
		*/
		class OutOfBoundsException : public ArrayException
		{
		private:

			// erroneous index
			int m_index;

		public:

			// Param constructor
			OutOfBoundsException(int idx) : m_index(idx) {}

			// GetMessage
			std::string GetMessage() const
			{
				std::stringstream sstream;
				sstream << "given index " << m_index << " is out of bounds";
				return sstream.str();
			}
		};
	}
}
#endif // !OUT_OF_BOUNDS_EXCEPTION_HPP