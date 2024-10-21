// PerpetualAmericanOption.hpp
#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP

#include "Option.hpp"

/**
 * @brief Represents the PerpetualAmericanOption class.
 * inherits the Option class
*/
class PerpetualAmericanOption : public Option
{
public:

	// Default constructor
	PerpetualAmericanOption();

	// Parametrized constructor
	PerpetualAmericanOption(OptionType type, const Equity& underlying, 
		double K, double rfr);

	// Copy constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& source);

	// Assignment Operator
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);

	// Destructor
	virtual ~PerpetualAmericanOption();

	// calculate option price
	double Price() const;

	// modify option with given vector of params
	void ModifyOptionWithParams(const std::vector<double>& params);

private:
	// call option price 
	double callPrice() const;

	// put option price
	double putPrice() const;
};

#endif // !PERPETUAL_AMERICAN_OPTION_HPP