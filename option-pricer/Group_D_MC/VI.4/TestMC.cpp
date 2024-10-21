#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <cmath>
#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <fstream>
#include <string>
#include <vector>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

// Calculate SD and SE
// Returns a tuple of <SD, SE>
template <typename Type>
boost::tuple<Type, Type> SDSE(const std::vector<Type>& prices, Type r, Type T)
{
	long M = prices.size(); 

	Type sum_of_squares_of_price{};
	Type sum_of_prices{};

	for (int i = 0; i < M; i++)
	{
		sum_of_squares_of_price += prices[i] * prices[i];
		sum_of_prices += prices[i];
 	}

	Type SD = sqrt((sum_of_squares_of_price - (1.0 / M) * sum_of_prices * sum_of_prices) /
		(M - 1.0)) * exp(-1 * r * T);
	Type SE = SD / sqrt(M);

	return boost::make_tuple(SD, SE);
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	// Open file here
	std::ofstream file("results.csv");

	// K, T, r, sig, S_0
	typedef boost::tuple<double, double, double, double, double> OptParams;
	vector<OptParams> batches;
	// INPUT batches
	batches.push_back(boost::make_tuple(155.0, 1.25, 0.03, 0.25, 150.0));
	//batches.push_back(boost::make_tuple(100, 1.0, 0.0, 0.2, 100));

	// for every batch
	for (int k = 0; k < batches.size(); k++)
	{
		// batch distinguisher in file
		if (file.is_open())
			file << "Batch " << k+1 << "\n";

		typedef boost::tuple<long, long> NSim_NT;
		vector<NSim_NT> testsets;
		// INPUT NSim NT
		testsets.push_back(boost::make_tuple(1000000, 75));
		//testsets.push_back(boost::make_tuple(10000, 1000));

		// heading for this NSim NT
		if (file.is_open())
			file << "NSim,NT,Call Price (MC),Call SD,Call SE,Put Price (MC),Put SD, Put SE\n";

		std::cout << "1 factor MC with explicit Euler\n";
		OptionData myOption;
		myOption.K = batches[k].get<0>();
		myOption.T = batches[k].get<1>();
		myOption.r = batches[k].get<2>();
		myOption.sig = batches[k].get<3>();
		myOption.type = 1; // call 
		double S_0 = batches[k].get<4>();

		// for every pair of <NSim, NT>
		for (int j = 0; j < testsets.size(); j++)
		{
			vector<double> call_prices;
			vector<double> put_prices;

			/*long N = 100;
			std::cout << "Number of subintervals in time: ";
			std::cin >> N;*/
			long N = testsets[j].get<1>();

			// Create the basic SDE (Context class)
			Range<double> range(0.0, myOption.T);
			double VOld = S_0;
			double VNew;

			std::vector<double> x = range.mesh(N);


			// V2 mediator stuff
			/*long NSim = 50000;
			std::cout << "Number of simulations: ";
			std::cin >> NSim;*/
			long NSim = testsets[j].get<0>();

			double k = myOption.T / double(N);
			double sqrk = sqrt(k);

			// Normal random number
			double dW;
			//double price = 0.0;	// Option price

			// NormalGenerator is a base class
			NormalGenerator* myNormal = new BoostNormal();

			using namespace SDEDefinition;
			SDEDefinition::data = &myOption;

			std::vector<double> res;
			int coun = 0; // Number of times S hits origin

			double callPrice = 0;
			double putPrice = 0;

			// A.
			for (long i = 1; i <= NSim; ++i)
			{ // Calculate a path at each iteration

				if ((i / 10000) * 10000 == i)
				{// Give status after each 1000th iteration

					std::cout << i << std::endl;
				}

				VOld = S_0;
				for (unsigned long index = 1; index < x.size(); ++index)
				{

					// Create a random number
					dW = myNormal->getNormal();

					// The FDM (in this case explicit Euler)
					VNew = VOld + (k * drift(x[index - 1], VOld))
						+ (sqrk * diffusion(x[index - 1], VOld) * dW);

					VOld = VNew;

					// Spurious values
					if (VNew <= 0.0) coun++;
				}

				myOption.type = 1; // call 
				double tmp1 = myOption.myPayOffFunction(VNew);
				callPrice += (tmp1) / double(NSim);
				call_prices.push_back(callPrice);

				myOption.type = -1; // put 
				double tmp2 = myOption.myPayOffFunction(VNew);
				putPrice += (tmp2) / double(NSim);
				put_prices.push_back(putPrice);
			}

			// D. Finally, discounting the average price
			callPrice *= exp(-myOption.r * myOption.T);
			putPrice *= exp(-myOption.r * myOption.T);

			// calculate SD and SE 
			boost::tuple<double, double> call_sdse = SDSE<>(call_prices, 
				myOption.r, myOption.T);

			boost::tuple<double, double> put_sdse = SDSE<>(call_prices,
				myOption.r, myOption.T);

			// write all this data to file
			if (file.is_open())
			{
				file << NSim << ","
					<< N << ","
					<< callPrice << ","
					<< call_sdse.get<0>() << ","
					<< call_sdse.get<1>() << ","
					<< putPrice << ","
					<< put_sdse.get<0>() << ","
					<< put_sdse.get<1>()
					<< "\n";
			}

			// Cleanup; V2 use scoped pointer
			delete myNormal;

			//std::cout << "Price, after discounting: " << price << ", " << std::endl;
			std::cout << "Number of times origin is hit: " << coun << endl;
		}
	}
	file.close();
	return 0;
}