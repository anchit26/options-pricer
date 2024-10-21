// STL Iterators
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

using namespace std;

// sum of generic sequence containers
template <typename T> 
double Sum(const T& ctr); 

// sum of a map container
template <typename K, typename V> 
double Sum(const map<K, V>& container);

// Sum of sequence containers through iterators
template <typename T>
double Sum(const typename T::const_iterator& begin,
	const typename T::const_iterator& end);

// sum of map values through iterators
template <typename K, typename V>
double Sum(const typename map<K, V>::const_iterator& begin,
	const typename map<K, V>::const_iterator& end);

// test_list()
void test_list(); 

// test_vector()
void test_vector(); 

// test_map()
void test_map();

int main()
{
	test_list();
	test_vector();
	test_map();
}

// Sum of generic sequence containers
template <typename T> 
double Sum(const T& ctr)
{
	typename T::const_iterator end = ctr.end(); // end iterator
	double sum = 0; // initialize 

	for (typename T::const_iterator it = ctr.begin(); it != end; it++)
	{
		// dereference the iterator and add the value to sum
		sum += *it;
	}

	return sum;
}

// Sum for map
template <typename K, typename V>
double Sum(const map<K, V>& m)
{
	typename map<K, V>::const_iterator end = m.end(); // end iterator
	double sum = 0; // initialize 

	for (typename map<K, V>::const_iterator it = m.begin(); it != end; it++)
	{
		// dereference the iterator and add the value to sum
		sum += it->second;
	}

	return sum;
}

// Sum of sequence containers through iterators
template <typename T>
double Sum(const typename T::const_iterator& begin, 
	const typename T::const_iterator& end)
{
	double sum = 0; // initialize

	for (typename T::const_iterator it = begin; it != end; it++)
	{
		sum += *it;
	}

	return sum;
}

// Sum for map using iterators
template <typename K, typename V>
double Sum(const typename map<K, V>::const_iterator& begin,
	const typename map<K, V>::const_iterator& end)
{
	double sum = 0; // initialize

	for (typename map<K, V>::const_iterator it = begin; it != end; it++)
	{
		sum += it->second;
	}

	return sum;
}

// Test List
void test_list()
{
	// list of doubles
	list<double> myList = { 1.4, 2.3, 3, 5.2 };

	// Calculate sum
	cout << "Sum of my list: " << Sum(myList) << endl;

	// Calculate sum using iterators
		// Calculate sum using iterators
	cout << "Sum of list using iterators: " <<
		Sum<list<double>>(myList.begin(), myList.end()) << endl;
}

// Test Vector
void test_vector()
{
	// vector of doubles
	vector<double> myVec = { 1.4, 2.3, 3, 4.55 };

	// Calculate sum
	cout << "Sum of vector: " << Sum(myVec) << endl;

	// Calculate sum using iterators
	cout << "Sum of vector using iterators: " << 
		Sum<vector<double>>(myVec.begin(), myVec.end()) << endl;
}

// Test Map
void test_map()
{
	// map of string to double
	map<string, double> myMap = {
		{"forum", 12.5 },
		{"quiz", 9.8},
		{"lecture", 7}
	};

	// Calculate Sum
	cout << "Sum of map values: " << Sum(myMap) << endl;

	// Calculate sum using iterators
	cout << "Sum of map values using iterators: " << 
		Sum<string, double>(myMap.begin(), myMap.end()) << endl;
}