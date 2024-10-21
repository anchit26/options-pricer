// Statistical functions

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	{// Exponential Distribution
		cout << "***Exponential distribution: \n";
		exponential_distribution<> myExp(2.5); // Default type is 'double'
		cout << "Mean: " << mean(myExp) << ", standard deviation: " << standard_deviation(myExp) << endl;

		// Distributional properties
		double x = 10.25;

		cout << "pdf: " << pdf(myExp, x) << endl;
		cout << "cdf: " << cdf(myExp, x) << endl;

		// Choose another data type and now a lambda = 1 variate
		exponential_distribution<float> myExp2;
		cout << "Mean: " << mean(myExp2) << ", standard deviation: " << standard_deviation(myExp2) << endl;

		cout << "pdf: " << pdf(myExp2, x) << endl;
		cout << "cdf: " << cdf(myExp2, x) << endl;

		// Choose precision
		cout.precision(10); // Number of values behind the comma

		// Other properties
		
		cout << "mean: " << mean(myExp) << endl;
		cout << "variance: " << variance(myExp) << endl;
		cout << "median: " << median(myExp) << endl;
		cout << "mode: " << mode(myExp) << endl;
		cout << "kurtosis excess: " << kurtosis_excess(myExp) << endl;
		cout << "kurtosis: " << kurtosis(myExp) << endl;
		cout << "characteristic function: " << chf(myExp, x) << endl;
		cout << "hazard: " << hazard(myExp, x) << endl;
	}

	{// Poisson Distribution
		cout << "\n***Poisson distribution: \n";
		double lambda = 3.0; // rate at which events occur
		poisson_distribution<double> myPoisson(lambda);

		double x = 13.0;
		cout << endl << "pmf: " << pdf(myPoisson, x) << endl;
		cout << "cdf: " << cdf(myPoisson, x) << endl;

		vector<double> pmfList;
		vector<double> cdfList;

		double start = 0.0;
		double end = 10.0;
		long N = 30;		// Number of subdivisions

		x = 0.0;
		double h = (end - start) / double(N);

		for (long j = 1; j <= N; ++j)
		{
			pmfList.push_back(pdf(myPoisson, x));
			cdfList.push_back(cdf(myPoisson, x));

			x += h;
		}

		for (long j = 0; j < pmfList.size(); ++j)
		{
			cout << pmfList[j] << ", ";

		}

		cout << "***" << endl;

		for (long j = 0; j < cdfList.size(); ++j)
		{
			cout << cdfList[j] << ", ";

		}

	}

	return 0;
}