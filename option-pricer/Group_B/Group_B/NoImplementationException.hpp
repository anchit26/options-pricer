// NoImplementionException.hpp

#ifndef NO_IMPLEMENTION_EXCEPTION_HPP
#define NO_IMPLEMENTATION_EXCEPTION_HPP

#include "OptionException.hpp"
#include <sstream>

/**
 * @brief Represents the NoImplementationException class for 
 * functions which are not implemented
*/
class NoImplementationException : public OptionException
{
private:
	// function name whose implementation is missing
	std::string m_fname;

public:
	// default constructor
	NoImplementationException() :
		m_fname("")
	{}

	// parametrized constructor
	NoImplementationException(const std::string functionName) :
		m_fname(functionName)
	{}

	// destructor
	virtual ~NoImplementationException() {}

	virtual std::string GetMessage() const
	{
		std::stringstream stream;
		stream << "no implementation found for " << m_fname;
		return stream.str();
	}
};

#endif // !NO_IMPLEMENTION_EXCEPTION_HPP