// STL Algorithms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define THRESHOLD 5.1

// checks if smaller than a certain threshold
bool IsLessThan(double value);

/**
 * @brief Represents the LessThanCompare class
*/
class LessThanCompare
{
private:
	double m_threshold; // threshold value for comparision

public:
	LessThanCompare(double t); // Parametrized constructor
	bool operator () (double value) const; // operator ()
};

int main()
{
	// vector of doubles
	vector<double> myVec = { 1.4, 2.3, 3, 4.55, 5.1, 6, 7};
	
	// using global function
	cout << "Counted elements through global function: " <<
		count_if(myVec.begin(), myVec.end(), IsLessThan) << endl;
	
	// using function object
	LessThanCompare cmp(THRESHOLD); // threshold encapsulated within the object
	cout << "Counted elements through function object: " <<
		count_if(myVec.begin(), myVec.end(), cmp) << endl;
}

// isSmallerThan
bool IsLessThan(double value)
{
	return value < THRESHOLD;
}

// Parametrized constructor
LessThanCompare::LessThanCompare(double t) :
	m_threshold(t) 
{};

// operator overloading ()
bool LessThanCompare::operator () (double value) const
{
	return value < m_threshold; // less than comparision
}
