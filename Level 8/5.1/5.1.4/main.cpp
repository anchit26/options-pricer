// Random number generation
#include <iostream>
#include <boost/random.hpp>
#include <map>

#define NUM_TRIALS 1000000
int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	std::map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome = 0; // Current outcome

	for (int i = 0; i < NUM_TRIALS; ++i)
	{
		outcome = six(myRng); // random number generation in range
		++statistics[outcome]; // increase freq in map for outcome
	}

	std::cout << "How many trials? " << NUM_TRIALS << "\n\n";

	for (int i = 1; i <= 6; i++)
	{
		// calculate percentage
		double freq_percentage = ((double)statistics[i] * 100) / NUM_TRIALS;
		// send to cout
		std::cout << "Trial " << i << " has " << freq_percentage << "% outcomes\n";
	}

	return 0;
}