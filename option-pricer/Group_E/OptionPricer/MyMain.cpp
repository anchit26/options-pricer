// writing data to excel
#include <iostream>
#include <string>

#include "EuropeanOption.hpp"
#include "Equity.hpp"
#include "OptionException.hpp"
#include "Mesh.hpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/ExcelDriver/Utilities.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
int main()
{
	typedef std::vector<double> Vector;

	double S = 60;
	double K = 65;
	double sig = 0.30;
	double T = 0.25;
	double rfr = 0.08;
	double b = rfr; // Since we consider b = rfr
	
	Mesh<double> mesh(S, 100, 1);
	std::vector<double> spot_prices = mesh.GenerateMesh();

	Equity eq(S, b, sig);
	EuropeanOption call(OptionType::Call, eq, K, T, rfr);

	std::vector<double> call_option_prices;

	for (int i = 0; i < spot_prices.size(); i++)
	{
		// create a local equity instance
		Equity equity(spot_prices[i], b, sig);

		// update the equity of the option
		call.Underlying(equity);

		// price the option 
		call_option_prices.push_back(call.Price());
	}
	
	// print data to excel
	try
	{
		printOneExcel(spot_prices, call_option_prices, "Option Prices", 
			"spot price", "call option price", "call option price");
	}
	catch (DatasimException& e)
	{
		std::cout << "Caught Exception: ";  e.print();
	}

	std::cout << "Option prices data populated in excel";

}
