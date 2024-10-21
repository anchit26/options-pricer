// Exact Pricing Models
#include <iostream>
#include <string>

#include "PerpetualAmericanOption.hpp"
#include "Equity.hpp"
#include "Mesh.hpp"
#include "MeshMatrixGenerator.hpp"
#include "OptionMatrixPricer.hpp"
#include "OptionException.hpp"

void test_batch(double K, double sig, double rfr, double S, double b);
void printHeading(const std::string& s);

int main()
{
	try
	{
		double S = 110; double K = 100; double sig = 0.1;
		double rfr = 0.1; double b = 0.02;

		{// American Perpetual Option 
			printHeading("American Perpetual Option");
			test_batch(K, sig, rfr, S, b);
		}

		{// Mesher and Matrix Pricer for Option Deltas
			printHeading("Test Matrix Pricer for Perpetual American option Prices");
			Equity eq(S, b, sig);

			// create a perpetual american call option
			PerpetualAmericanOption call_opt(OptionType::Call, eq, K, rfr);

			int numOptions = 40;

			// Create Mesh arrays for all params
			Mesh<double> S_mesh(S, numOptions, 1.0); // spot price mesh with step 1.0
			Mesh<double> K_mesh(K, numOptions, 0); // strike price mesh with step  0
			Mesh<double> sig_mesh(sig, numOptions, 0); // volatility mesh with step 0
			Mesh<double> rfr_mesh(rfr, numOptions, 0); // rfr mesh with step 0

			// create matrix generator object 
			MeshMatrixGenerator matrixGenerator;
			matrixGenerator.AddMesh(S_mesh);
			matrixGenerator.AddMesh(K_mesh);
			matrixGenerator.AddMesh(sig_mesh);
			matrixGenerator.AddMesh(rfr_mesh);

			// create Matrix using matrix generator
			// columns: S, K, sig, T, rfr
			Matrix optionsMatrix = matrixGenerator.GenerateMatrix();

			// pass matrix to matrix pricer
			std::vector<double> optionsPrices = OptionMatrixPricer(&call_opt).Price(optionsMatrix);

			// print computed option prices
			for (size_t i = 0; i < optionsPrices.size(); i++)
			{
				std::cout << "S: " << optionsMatrix(i, 0) << ", ";
				std::cout << "K: " << optionsMatrix(i, 1) << ", ";
				std::cout << "sig: " << optionsMatrix(i, 2) << ", ";
				std::cout << "Rfr: " << optionsMatrix(i, 3) << ", ";
				std::cout << "Price: " << optionsPrices[i] << std::endl;
			}
		}
	}
	catch (const OptionException& e)
	{
		std::cout << "Caught exception: " << e.GetMessage() << std::endl;
	}
}

void test_batch(double K, double sig, double rfr, double S, double b)
{
	Equity eq1(S, b, sig); 

	// create an europan call option
	PerpetualAmericanOption call(OptionType::Call, eq1, K, rfr);

	// create an european put option
	PerpetualAmericanOption put(OptionType::Put, eq1, K, rfr);
	std::cout << "Call option price: " << call.Price() << std::endl;
	std::cout << "Put option price: " << put.Price() << std::endl;
}

void printHeading(const std::string& s)
{
	std::cout << "\n***********" << s << "**********\n";
}