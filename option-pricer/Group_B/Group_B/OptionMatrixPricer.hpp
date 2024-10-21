// OptionMatrixPricer.hpp
#ifndef OPTION_MATRIX_PRICER_HPP
#define OPTION_MATRIX_PRICER_HPP

#include <vector>
#include "Option.hpp"
#include "Matrix.hpp"

/**
 * @brief Represents an option matrix pricer class for a vector of vector of option
 * parameters
*/
class OptionMatrixPricer
{
public: 
	// Default constructor
	OptionMatrixPricer();

	// Parametrized constructor
	OptionMatrixPricer(Option* opt);

	// Destructor
	~OptionMatrixPricer();

	// Price all the options in the vector 
	std::vector<double> Price(const Matrix& mat) const;

	// Compute Delta of all the options in vector 
	std::vector<double> Delta(const Matrix& mat) const;

	// Compute Gamma of all the options in vector
	std::vector<double> Gamma(const Matrix& mat) const;

private:
	Option* m_opt;
};

#endif // !OPTION_MATRIX_PRICER_HPP