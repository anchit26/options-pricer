// Equity.cpp
#include "Equity.hpp"

// Default constructor
Equity::Equity() :
	m_S(0),
	m_costOfCarry(0),
	m_sig(0)
{}

// Param constrcutor
Equity::Equity(double S, double b, double sig) :
	m_S(S),
	m_costOfCarry(b),
	m_sig(sig)
{}

// Copy constructor
Equity::Equity(const Equity& source) :
	m_S(source.m_S),
	m_costOfCarry(source.m_costOfCarry),
	m_sig(source.m_sig)
{}

// Assignment operator
Equity& Equity::operator=(const Equity& source)
{
	// handle self assignment
	if (this == &source)
		return *this;

	// copy data
	m_S = source.m_S;
	m_costOfCarry = source.m_costOfCarry;
	m_sig = source.m_sig;

	return *this;
}

// Destructor
Equity::~Equity() {}

// == operator overload
bool Equity::operator == (const Equity& other) const
{
	// check for member variables to have same value
	if (m_S == other.m_S &&
		m_costOfCarry == other.m_costOfCarry &&
		m_sig == other.m_sig)
		return true;
	return false;
}