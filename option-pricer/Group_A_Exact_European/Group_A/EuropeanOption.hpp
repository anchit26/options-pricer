// EuropeanOption.hpp
#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include "Option.hpp"

/**
 * @brief Represents the EuropeanOption class.
 * inherits the Option class
*/
class EuropeanOption : public Option
{
public:

	// Default constructor
	EuropeanOption();

	// Parametrized constructor
	EuropeanOption(OptionType type, const Equity& underlying, double K, 
		double T, double rfr);

	// Copy constructor
	EuropeanOption(const EuropeanOption& source);

	// Assignment Operator
	EuropeanOption& operator = (const EuropeanOption& source);

	// Destructor
	virtual ~EuropeanOption();

	// calculate price of the option
	double Price() const;

	// Delta of the option
	double Delta() const;

	// Gamma of the option  
	double Gamma() const;

	// calculate price using put call parity
	double CounterOptionPrice() const;

	// checks if put call parity holds within self and passed option
	bool IfPutCallParityHolds(const EuropeanOption& opt) const;

	// getter
	double T() const { return m_T; }

	// setter
	void T(double T) { m_T = T; }

	// modify option with given vector of params
	void ModifyOptionWithParams(const std::vector<double>& params);

	// Delta of the option using divided differences
	double DeltaDiff(double h) const;

	// Gamma of the option using divided differences
	double GammaDiff(double h) const;

private:

	// time to expiry of european option
	double m_T;
};

// call option price 
double CallPrice(double S, double K, double T, double sig, double r, double b);

// put option price
double PutPrice(double S, double K, double T, double sig, double r, double b);

// call delta
double CallDelta(double S, double K, double T, double sig, double r, double b);

// put delta
double PutDelta(double S, double K, double T, double sig, double r, double b);

// call Gamma
double CallGamma(double S, double K, double T, double sig, double r, double b);

// put Gamma
double PutGamma(double S, double K, double T, double sig, double r, double b);


#endif // !EUROPEAN_OPTION_HPP