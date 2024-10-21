// OptionMatrixPricer.cpp
#include "OptionMatrixPricer.hpp"

// Default constructor
OptionMatrixPricer::OptionMatrixPricer() :
	m_opt(nullptr)
{}

// Parametrized constructor
OptionMatrixPricer::OptionMatrixPricer(Option* opt) :
	m_opt(opt)
{}

// Destructor
OptionMatrixPricer::~OptionMatrixPricer() {}

// Prices a vector of options
std::vector<double> OptionMatrixPricer::Price(const Matrix& mat) const
{
	// vector to store option prices
	std::vector<double> optionPrices;

	// iterate over all rows
	for (size_t i = 0; i < mat.Rows(); i++)
	{
		// modify option params
		m_opt->ModifyOptionWithParams(mat.GetRow(i));

		// call options price member method and
		// push the option price to vector
		optionPrices.push_back(m_opt->Price());
	}
	return optionPrices;
}

// Computes delta of a vector of options
std::vector<double> OptionMatrixPricer::Delta(const Matrix& mat) const
{
	// vector to store option prices
	std::vector<double> optionDeltas;

	// iterate over all rows
	for (size_t i = 0; i < mat.Rows(); i++)
	{
		// modify option params
		m_opt->ModifyOptionWithParams(mat.GetRow(i));

		// call options delta member method and
		// push the option delta to vector
		optionDeltas.push_back(m_opt->Delta());
	}
	return optionDeltas;
}

// Computes gamma of a vector of options
std::vector<double> OptionMatrixPricer::Gamma(const Matrix& mat) const
{
	// vector to store option prices
	std::vector<double> optionGammas;

	// iterate over all rows
	for (size_t i = 0; i < mat.Rows(); i++)
	{
		// modify option params
		m_opt->ModifyOptionWithParams(mat.GetRow(i));

		// call options gamma member method and
		// push the option gamma to vector
		optionGammas.push_back(m_opt->Gamma());
	}
	return optionGammas;
}

