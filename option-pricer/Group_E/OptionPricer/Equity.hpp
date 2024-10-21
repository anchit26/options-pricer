// Equity.hpp
#ifndef EQUITY_HPP
#define EQUITY_HPP

/**
 * @brief Represents the equity security
*/
class Equity
{
private:

	// price of the equity unit
	double m_S;
	
	// cost of carry
	double m_costOfCarry;

	// volatiltiy of the security
	double m_sig;

public:
	// Default constructor
	Equity();

	// Parametrized constructor
	Equity(double S, double b, double sig);

	// copy constructor
	Equity(const Equity& source);

	// Assignment operator
	Equity& operator = (const Equity& source);

	// Destructor
	virtual ~Equity();

	// Getters
	double S() const { return m_S; }
	double CostOfCarry() const { return m_costOfCarry; }
	double Sig() const { return m_sig; }

	// operator == overload
	bool operator == (const Equity& other) const;

	// Setters
	void S(double S) { m_S = S; }
	void CostOfCarry(double b) { m_costOfCarry = b; }
	void Sig(double sig) { m_sig = sig; }
};

#endif // !EQUITY_HPP