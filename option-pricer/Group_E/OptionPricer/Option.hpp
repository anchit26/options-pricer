// Option.hpp

#ifndef OPTION_HPP
#define OPTION_HPP

#include "Equity.hpp"
#include <vector>

enum class OptionType
{
	Call,
	Put
};

/**
 * @brief Represents the Option class
*/
class Option
{
private:

	// option type
	OptionType m_type;

	// underlying of the option
	Equity m_underlying;

	// strike price of the option
	double m_K;

	// risk free rate
	double m_rfr;

public:

	// Default constructor
	Option();

	// parametrized constructor
	Option(OptionType type, const Equity& underlying, double K, double rfr);

	// copy constructor
	Option(const Option& source);

	// assignment operator
	Option& operator = (const Option& source);

	// destructor
	virtual ~Option();

	// price of the option
	virtual double Price() const = 0; 
	virtual double Delta() const; 
	virtual double Gamma() const;

	// calculate price of the counter option (put for call, call for put)
	virtual double CounterOptionPrice() const;

	// Getters
	OptionType Type() const { return m_type; }
	const Equity& Underlying() const { return m_underlying; }
	double K() const { return m_K; }
	double RFR() const { return m_rfr; }

	// Setters
	void Type(OptionType type) { m_type = type; }
	void Underlying(Equity& underlying) { m_underlying = underlying; }  
	void K(double K) { m_K = K; }
	void RFR(double r) { m_rfr = r; }

	// modify option with given vector of params
	virtual void ModifyOptionWithParams(const std::vector<double>& params) = 0;
};

#endif // !OPTION_HPP