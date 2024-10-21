// Option.cpp
#include <vector>

#include "Option.hpp"
#include "NoImplementationException.hpp"

// Default constructor
Option::Option() :
	m_type(OptionType::Call),
	m_underlying(),
	m_K(0),
	m_rfr(0)
{}

// Param constructor
Option::Option(OptionType type, const Equity& underlying, double K, double rfr) :
	m_type(type),
	m_underlying(underlying),
	m_K(K),
	m_rfr(rfr)
{}

// Copy constructor
Option::Option(const Option& source) :
	m_type(source.m_type),
	m_underlying(source.m_underlying),
	m_K(source.m_K),
	m_rfr(source.m_rfr)
{}

// Assignment operator
Option& Option::operator= (const Option& source)
{
	// handle self assignment
	if (this == &source)
		return *this;

	// copy data
	m_type = source.m_type;
	m_underlying = source.m_underlying;
	m_K = source.m_K;
	m_rfr = source.m_rfr;

	return *this;
}

// Destructor
Option::~Option() {}

// Delta
double Option::Delta() const
{
	throw NoImplementationException("Delta()");
}

// Gamma
double Option::Gamma() const
{
	throw NoImplementationException("Gamma()");
}

// CounterOptionPrice
double Option::CounterOptionPrice() const
{
	throw NoImplementationException("CounterOptionPrice()");
}


