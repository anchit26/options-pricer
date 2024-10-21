// EuropeanOption.cpp
#include <boost/math/distributions/normal.hpp>

#include "EuropeanOption.hpp"

// Default constructor
EuropeanOption::EuropeanOption() :
	m_T(0)
{}

// Parametrzied constructor
EuropeanOption::EuropeanOption(OptionType type, const Equity& underlying, double K,
	double T, double rfr) :
	Option(type, underlying, K, rfr),
	m_T(T)
{}

// Copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption& source) :
	Option(source),
	m_T(source.m_T)
{}

// Assignment operator
EuropeanOption& EuropeanOption::operator= (const EuropeanOption& source)
{
	if (this == &source)
		return *this;

	Option::operator=(source);
	m_T = source.m_T;
	return *this;
}

// Destructor
EuropeanOption::~EuropeanOption() {}

// Price
double EuropeanOption::Price() const
{
	double spot = Underlying().S();
	double strike = K();
	double T = m_T;
	double sig = Underlying().Sig();
	double r = RFR();
	double b = Underlying().CostOfCarry();

	return Type() == OptionType::Call ? 
		CallPrice(spot, strike, T, sig, r, b) :
		PutPrice(spot, strike, T, sig, r, b);
}

// Delta 
double EuropeanOption::Delta() const
{
	double spot = Underlying().S();
	double strike = K();
	double T = m_T;
	double sig = Underlying().Sig();
	double r = RFR();
	double b = Underlying().CostOfCarry();
	return Type() == OptionType::Call ? 
		CallDelta(spot, strike, T, sig, r, b) :
		PutDelta(spot, strike, T, sig, r, b);
}

// Gamma 
double EuropeanOption::Gamma() const
{
	double spot = Underlying().S();
	double strike = K();
	double T = m_T;
	double sig = Underlying().Sig();
	double r = RFR();
	double b = Underlying().CostOfCarry();
	return Type() == OptionType::Call ? 
		CallGamma(spot, strike, T, sig, r, b) :
		PutGamma(spot, strike, T, sig, r, b);
}

// CounterOptionPrice
double EuropeanOption::CounterOptionPrice( ) const
{
	// calculate self price using Price()
	double selfPrice = Price();

	// calculate counter option price using PC parity
	double tmp = K()* exp(-RFR() * m_T) - Underlying().S();
	double counterOptPrice = 0;
	if (this->Type() == OptionType::Call)
	{
		// self is call, counter is put: P = C + (K * e^(-r*t) - S)
		counterOptPrice = selfPrice + tmp;
	}
	else
	{
		// self is put, counter is call: C = P - (K * e^(-r*t) - S)
		counterOptPrice = selfPrice - tmp;
	}
	return counterOptPrice;
}

// Checks if put call parity holds
// Two options satisfy put call parity, if:
// counter options to each other
// same strike
// same expiry 
// same underlying asset
bool EuropeanOption::IfPutCallParityHolds(const EuropeanOption& opt) const
{	
	// counter options check
	if (this->Type() == opt.Type())
	{
		return false;
	}

	// same strike price check
	if (K() != opt.K())
	{
		return false;
	}

	// same expiry check
	if (m_T != opt.m_T)
	{
		return false;
	}

	// same underlying asset check
	// uses == operator overload of underlying type
	if (!(Underlying() == opt.Underlying()))
	{
		return false;
	}
	return true;
}

// modify option with given vector of params
void EuropeanOption::ModifyOptionWithParams(const std::vector<double>& params)
{
	//S, K, sig, T, rfr
	double S = params[0];
	double K = params[1];
	double sig = params[2];
	double T = params[3];
	double rfr = params[4];

	Equity eq(S, Underlying().CostOfCarry(), sig);
	this->Underlying(eq);
	this->K(K);
	this->RFR(rfr);
	m_T = T;
}


// Delta of the option using divided differences
double EuropeanOption::DeltaDiff(double h) const
{
	double spot = Underlying().S();
	double strike = K();
	double T = m_T;
	double sig = Underlying().Sig();
	double r = RFR();
	double b = Underlying().CostOfCarry();

	// create two equities with S+h and S-h
	Equity eq_spot_high(spot + h, b, sig);
	Equity eq_spot_low(spot - h, b, sig);

	// create two options with each equity
	EuropeanOption op_spot_high(Type(), eq_spot_high, strike, T, r);
	EuropeanOption op_spot_low(Type(), eq_spot_low, strike, T, r);

	return (op_spot_high.Price() - op_spot_low.Price()) / (2 * h);
}

// Gamma of the option using divided differences
double EuropeanOption::GammaDiff(double h) const
{
	double spot = Underlying().S();
	double strike = K();
	double T = m_T;
	double sig = Underlying().Sig();
	double r = RFR();
	double b = Underlying().CostOfCarry();

	// create two equities with S+h and S-h
	Equity eq_spot_high(spot + h, b, sig);
	Equity eq_spot_low(spot - h, b, sig);

	// create two options with each equity
	EuropeanOption op_spot_high(Type(), eq_spot_high, strike, T, r);
	EuropeanOption op_spot_low(Type(), eq_spot_low, strike, T, r);

	return (op_spot_high.Price() - this->Price() + op_spot_low.Price()) / (h * h);
}


//////////////////////////////////////////////////////////////////////////////////

// Call price
double CallPrice(double S, double K, double T, double sig, double r, double b)
{
	// standard normal distribution
	boost::math::normal_distribution<> normal_dist(0.0, 1.0);

	double tmp = sig * std::sqrt(T);
	double d1 = (std::log(S / K) + (b + 0.5 * sig * sig) * T) / (tmp);
	double d2 = d1 - tmp;

	double N_d1 = boost::math::cdf(normal_dist, d1); // N(d_1)
	double N_d2 = boost::math::cdf(normal_dist, d2); // N(d_2)

	return (S * exp((b - r) * T) * N_d1) - (K * exp(-r * T) * N_d2);
}

// Put price
double PutPrice(double S, double K, double T, double sig, double r, double b)
{
	// standard normal distribution
	boost::math::normal_distribution<> normal_dist(0.0, 1.0);
	
	double tmp = sig * std::sqrt(T);
	double d1 = (std::log(S / K) + (b + 0.5 * sig * sig) * T) / (tmp);
	double d2 = d1 - tmp;

	double N_neg_d1 = boost::math::cdf(normal_dist, -d1); // N(-d_1)
	double N_neg_d2 = boost::math::cdf(normal_dist, -d2); // N(-d_2)

	return (K * exp(-r * T) * N_neg_d2) - (S * exp((b - r) * T) * N_neg_d1);
}

// CallDelta
double CallDelta(double S, double K, double T, double sig, double r, double b)
{
	// standard normal distribution
	boost::math::normal_distribution<> normal_dist(0.0, 1.0);
	
	double tmp = sig * std::sqrt(T);
	double d1 = (std::log(S / K) + (b + 0.5 * sig * sig) * T) / (tmp);
	double N_d1 = boost::math::cdf(normal_dist, d1); // N(d_1)

	return exp((b - r) * T) * N_d1;
}

// PutDelta
double PutDelta(double S, double K, double T, double sig, double r, double b)
{
	// standard normal distribution
	boost::math::normal_distribution<> normal_dist(0.0, 1.0);

	double tmp = sig * std::sqrt(T);
	double d1 = (std::log(S / K) + (b + 0.5 * sig * sig) * T) / (tmp);
	double N_d1 = boost::math::cdf(normal_dist, d1); // N(d_1)

	return exp((b - r) * T) * (N_d1 - 1);
}

// CallGamma
double CallGamma(double S, double K, double T, double sig, double r, double b)
{
	// standard normal distribution
	boost::math::normal_distribution<> normal_dist(0.0, 1.0);

	double tmp = sig * std::sqrt(T);
	double d1 = (std::log(S / K) + (b + 0.5 * sig * sig) * T) / (tmp);
	double n_d1 = boost::math::pdf(normal_dist, d1); // n(d_1)

	return (exp((b - r) * T) * n_d1) / (S * tmp);
}

// PutGamma
double PutGamma(double S, double K, double T, double sig, double r, double b)
{
	// PutGamma == CallGamma
	return CallGamma(S, K, T, sig, r, b);
}