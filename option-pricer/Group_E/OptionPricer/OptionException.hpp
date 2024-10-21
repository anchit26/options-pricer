// OptionException.hpp
#ifndef OPTION_EXCEPTION_HPP
#define OPTION_EXCEPTION_HPP

#include "Option.hpp"
#include <string>

class OptionException
{
public:
	// constructor
	OptionException() {}

	// destructor
	virtual ~OptionException() {}

	// pure virutal function 
	virtual std::string GetMessage() const = 0;
};

#endif // !OPTION_EXCEPTION_HPP