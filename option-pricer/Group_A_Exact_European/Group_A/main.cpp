// Exact Pricing Models
#include <iostream>
#include <string>

#include "EuropeanOption.hpp"
#include "Equity.hpp"
#include "OptionMatrixPricer.hpp"
#include "OptionException.hpp"
#include "Mesh.hpp"
#include "MeshMatrixGenerator.hpp"

void test_batch(double T, double K, double sig, double rfr, double S, double b);
void printHeading(const std::string& s);

//int main()
//{
//	try
//	{
//		{// batch 1
//			printHeading("Batch 1");
//			double T = 0.25; 
//			double K = 65; 
//			double sig = 0.3;
//			double rfr = 0.08;
//			double S = 60;
//			double b = rfr;
//			test_batch(T, K, sig, rfr, S, b);
//			std::cout << std::endl;
//		}
//
//		{// batch 2
//			printHeading("Batch 2");
//			double b = 0.0; // since we consider b = rfr
//			test_batch(1.0, 100, 0.2, 0.0, 100, b);
//			std::cout << std::endl;
//		}
//
//		{// batch 3
//			printHeading("Batch 3");
//			double b = 0.12; // since we consider b = rfr
//			test_batch(1.0, 10, 0.50, 0.12, 5, b);
//			std::cout << std::endl;
//		}
//
//		{// batch 4
//			printHeading("Batch 4");
//			double b = 0.08; // since we consider b = rfr
//			test_batch(30.0, 100.0, 0.3, 0.08, 100, b);
//			std::cout << std::endl;
//		}
//
//		{// Test Mesher
//			printHeading("Test Mesher");
//			Mesh<double> mesh(1.0, 10, 0.5);
//			std::vector<double> generated_mesh = mesh.GenerateMesh();
//			std::cout << "Generated Mesh with start = 1.0, step = 0.5:\n ";
//			for (size_t i = 0; i < generated_mesh.size(); i++)
//			{
//				std::cout << generated_mesh[i] << " ";
//			}
//			std::cout << "\n";
//		}
//
//		{// Mesher and Matrix Pricer for Option Prices
//			printHeading("Test Matrix Pricer for European options Prices");
//			double S = 60;
//			double K = 65;
//			double sig = 0.30; 
//			double T = 0.25;
//			double rfr = 0.08;
//			double b = rfr; // Since we consider b = rfr
//			Equity eq(S, b, sig);
//
//			// create an europan call option
//			EuropeanOption call_opt(OptionType::Call, eq, K, T, rfr);
//
//			int numOptions = 40;
//
//			// Create Mesh arrays for all params
//			Mesh<double> S_mesh(S, numOptions, 1.0); // spot price mesh with step 1.0
//			Mesh<double> K_mesh(K, numOptions, 0); // strike price mesh with step  0
//			Mesh<double> sig_mesh(sig, numOptions, 0); // volatility mesh with step 0
//			Mesh<double> T_mesh(T, numOptions, 0); // Time mesh with step 0
//			Mesh<double> rfr_mesh(rfr, numOptions, 0); // rfr mesh with step 0
//
//			// create matrix generator object 
//			MeshMatrixGenerator matrixGenerator;
//			matrixGenerator.AddMesh(S_mesh);
//			matrixGenerator.AddMesh(K_mesh);
//			matrixGenerator.AddMesh(sig_mesh);
//			matrixGenerator.AddMesh(T_mesh);
//			matrixGenerator.AddMesh(rfr_mesh);
//
//			// create Matrix using matrix generator
//			// columns: S, K, sig, T, rfr
//			Matrix optionsMatrix = matrixGenerator.GenerateMatrix();
//
//			// pass matrix to matrix pricer
//			std::vector<double> optionsPrices = OptionMatrixPricer(&call_opt).Price(optionsMatrix);
//
//			// print computed option prices
//			for (size_t i = 0; i < optionsPrices.size(); i++)
//			{
//				std::cout << "S: " << optionsMatrix(i, 0) << ", ";
//				std::cout << "K: " << optionsMatrix(i, 1) << ", ";
//				std::cout << "sig: " << optionsMatrix(i, 2) << ", ";
//				std::cout << "T: " << optionsMatrix(i, 3) << ", ";
//				std::cout << "Rfr: " << optionsMatrix(i, 4) << ", ";
//				std::cout << "Price: " << optionsPrices[i] << std::endl;
//			}
//		}
//
//		{// Delta 
//			printHeading("Test Delta for given test set");
//			double S = 105; double K = 100; double T = 0.5; 
//			double rfr = 0.1; double b = 0; double sig = 0.36;
//
//			Equity eq1(S, b, sig);
//			
//			// create a europan call option
//			EuropeanOption call(OptionType::Call, eq1, K, T, rfr);
//
//			// create a european put option
//			EuropeanOption put(OptionType::Put, eq1, K, T, rfr);
//
//			std::cout << "Call Option Delta is: " << call.Delta() << std::endl;
//			std::cout << "Put Option Delta is: " << put.Delta() << std::endl;
//		}
//
//		{// Mesher and Matrix Pricer for Option Deltas
//			printHeading("Test Matrix Pricer for European options Deltas");
//			double S = 105;
//			double K = 100;
//			double sig = 0.36;
//			double T = 0.5;
//			double rfr = 0.1;
//			double b = 0;
//			Equity eq(S, b, sig);
//
//			// create an europan call option
//			EuropeanOption call_opt(OptionType::Call, eq, K, T, rfr);
//
//			int numOptions = 40;
//			
//			// Create Mesh arrays for all params
//			Mesh<double> S_mesh(S, numOptions, 1.0); // spot price mesh with step 1.0
//			Mesh<double> K_mesh(K, numOptions, 0); // strike price mesh with step  0
//			Mesh<double> sig_mesh(sig, numOptions, 0); // volatility mesh with step 0
//			Mesh<double> T_mesh(T, numOptions, 0); // Time mesh with step 0
//			Mesh<double> rfr_mesh(rfr, numOptions, 0); // rfr mesh with step 0
//
//			// create matrix generator object 
//			MeshMatrixGenerator matrixGenerator;
//			matrixGenerator.AddMesh(S_mesh);
//			matrixGenerator.AddMesh(K_mesh);
//			matrixGenerator.AddMesh(sig_mesh);
//			matrixGenerator.AddMesh(T_mesh);
//			matrixGenerator.AddMesh(rfr_mesh);
//
//			// create Matrix using matrix generator
//			// columns: S, K, sig, T, rfr
//			Matrix optionsMatrix = matrixGenerator.GenerateMatrix();
//
//			// pass matrix to matrix pricer
//			std::vector<double> optionsDeltas = OptionMatrixPricer(&call_opt).Delta(optionsMatrix);
//
//			// print computed option prices
//			for (size_t i = 0; i < optionsDeltas.size(); i++)
//			{
//				std::cout << "S: " << optionsMatrix(i, 0) << ", ";
//				std::cout << "K: " << optionsMatrix(i, 1) << ", ";
//				std::cout << "sig: " << optionsMatrix(i, 2) << ", ";
//				std::cout << "T: " << optionsMatrix(i, 3) << ", ";
//				std::cout << "Rfr: " << optionsMatrix(i, 4) << ", ";
//				std::cout << "Price: " << optionsDeltas[i] << std::endl;
//			}
//		}
//
//		{//Delta comparision using Divided differences
//			printHeading("Delta comparision using Divided Differences");
//			double S = 105; double K = 100; double T = 0.5;
//			double rfr = 0.1; double b = 0; double sig = 0.36;
//
//			Equity eq1(S, b, sig);
//
//			// create a europan call option
//			EuropeanOption call(OptionType::Call, eq1, K, T, rfr);
//			
//			double deltaExact = call.Delta();
//
//			std::vector<double> vec_h = { 10, 1, 0.1, 0.001, 0.0001 };
//
//			for (int i = 0; i < vec_h.size(); i++)
//			{
//				double deltaDiff = call.DeltaDiff(vec_h[i]);
//				std::cout << "\nh: " << vec_h[i] << "\n";
//				std::cout << "Call Delta (divided differences): " <<
//					deltaDiff << "\n";
//				std::cout << "Call Delta (exact): " << deltaExact << "\n";
//				std::cout << "Error (exact - dd): " << 
//					deltaExact - deltaDiff << "\n";
//			}
//
//		}
//	}
//	catch (const OptionException& e)
//	{
//		std::cout << "Caught exception: " << e.GetMessage() << std::endl;
//	}
//	catch (const std::out_of_range& e)
//	{
//		std::cout << "Caught exception: " << e.what() << std::endl;
//	}
//}

void main()
{
	{// batch 1
		printHeading("Batch 1");
		double T = 1.65;
		double K = 122;
		double sig = 0.43;
		double rfr = 0.045;
		double S = 102;
		double b = 0;
		test_batch(T, K, sig, rfr, S, b);
		std::cout << std::endl;
	}
}

void test_batch(double T, double K, double sig, double rfr, double S, double b)
{
	Equity eq1(S, b, sig); 

	// create an europan call option
	EuropeanOption call(OptionType::Call, eq1, K, T, rfr);

	// create an european put option
	EuropeanOption put(OptionType::Put, eq1, K, T, rfr);
	std::cout << "Call option price: " << call.Price() << std::endl;
	std::cout << "Put option price: " << put.Price() << std::endl;

	// using put call parity
	std::cout << "Call option price through PC parity: " <<
		put.CounterOptionPrice() << std::endl;
	std::cout << "Put option price through PC parity: " <<
		call.CounterOptionPrice() << std::endl;

	// If put call parity holds
	std::cout << "If put call parity holds: " << 
		(put.IfPutCallParityHolds(call) ? "Yes" : "No") << std::endl;

	std::cout << "European put Delta" << put.Delta() << "\n";
	std::cout << "Gamma" << put.Gamma() << "\n";
}

void printHeading(const std::string& s)
{
	std::cout << "\n***********" << s << "**********\n";
}