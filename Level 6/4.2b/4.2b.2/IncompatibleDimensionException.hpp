//IncompatibleDimensionException.hpp

#ifndef INCOMPATIBLE_DIMENSION_EXCEPTION
#define INCOMPATIBLE_DIMENSION_EXCEPTION

#include "ArrayException.hpp"
#include <sstream>

namespace AnchitAgarwal
{
	namespace Exceptions
	{
		/**
		 * @brief Represents the Out Of Bounds Exception class
		*/
		class IncompatibleDimensionException : public ArrayException
		{

		public:

			// Param constructor
			IncompatibleDimensionException() {}

			// GetMessage
			std::string GetMessage() const
			{
				std::stringstream sstream;
				sstream << "given arrays have incompatible dimensions";
				return sstream.str();
			}
		};
	}
}
#endif // !OUT_OF_BOUNDS_EXCEPTION_HPP