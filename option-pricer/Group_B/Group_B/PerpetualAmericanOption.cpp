// PerpetualAmericanOption.cpp
#include "PerpetualAmericanOption.hpp"
#include <cmath>
#include <limits>

// Default constructor
PerpetualAmericanOption::PerpetualAmericanOption() {}

// Parametrized constructor
PerpetualAmericanOption::PerpetualAmericanOption(OptionType type,
	const Equity& underlying, double K, double rfr) :
	Option(type, underlying, K, rfr)
{}

// Copy constructor
PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) :
	Option(source)
{}

// Assignment operator
PerpetualAmericanOption& PerpetualAmericanOption::operator= (const PerpetualAmericanOption& source)
{
	if (this == &source)
		return *this;

	Option::operator=(source);
	return *this;
}

// Destructor
PerpetualAmericanOption::~PerpetualAmericanOption() {}

// Price
double PerpetualAmericanOption::Price() const
{
	return Type() == OptionType::Call ? callPrice() : putPrice();
}

// modify option with given vector of params
void PerpetualAmericanOption::ModifyOptionWithParams(const std::vector<double>& params)
{
	//S, K, sig, rfr
	double S = params[0];
	double K = params[1];
	double sig = params[2];
	double rfr = params[3];

	Equity eq(S, Underlying().CostOfCarry(), sig);
	this->Underlying(eq);
	this->K(K);
	this->RFR(rfr);
}

/////////////////////////////////////////////////////////////////////////////////

// call price
double PerpetualAmericanOption::callPrice() const
{
	double spot = Underlying().S(); // spot price
	double sig = Underlying().Sig(); // volatility
	double b = Underlying().CostOfCarry(); // cost of carry
	double tmp = 0.5 - (b / (sig * sig));
	double y1 = tmp + std::sqrt(tmp * tmp + (2 * RFR()) / (sig * sig));

	return (K() / (y1 - 1)) * std::pow(((y1 - 1) / y1) * (spot / K()), y1);
}

// put price
double PerpetualAmericanOption::putPrice() const
{
	double spot = Underlying().S(); // spot price
	double sig = Underlying().Sig(); // volatility
	double b = Underlying().CostOfCarry(); // cost of carry
	double tmp = 0.5 - (b / (sig * sig));
	double y2 = tmp - std::sqrt(tmp * tmp + (2 * RFR()) / (sig * sig));

	return (K() / (1 - y2)) * std::pow(((y2 - 1) / y2) * (spot / K()), y2);
}
