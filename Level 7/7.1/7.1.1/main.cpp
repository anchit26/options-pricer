// STL Containers
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

using namespace std;

// function declaration
void test_list();
void test_vector();
void test_map();

int main()
{
	test_list();
	test_vector();
	test_map();
}

// Test List
void test_list()
{
	// list of doubles
	list<double> myList = { 1.4, 2.3, 3, 4.5 };

	// Access the front and back elements
	cout << "First element of list: " << myList.front() << endl;
	cout << "Last element of list: " << myList.back() << endl;

	// using push_back and push_front
	myList.push_back(6.7);
	myList.push_front(0.4);

	// Access the front and back elements
	cout << "Post push, First element of list: " << myList.front() << endl;
	cout << "Post push, Last element of list: " << myList.back() << endl;

	//myList[1]; // random access invalid for a list
}

// Test Vector
void test_vector()
{
	// vector of doubles
	vector<double> myVec = { 1.4, 2.3, 3, 4.5 };

	cout << "Vector's size: " << myVec.size() << endl;
	cout << "Vector's capacity: " << myVec.capacity() << endl;

	// grow the vector by pushing elements
	myVec.push_back(2.0);
	myVec.push_back(3.5);

	//myVec.push_front(1.1); // push_front invalid for a vector

	cout << "Post pushback, Vector's size: " << myVec.size() << endl;
	cout << "Post pushback, Vector's capacity: " << myVec.capacity() << endl;

	// index operator (random access)
	cout << "Element at index 1: " << myVec[1] << endl;
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

	// put key,value using operator
	myMap["foo"] = 1.2;

	// access elements using operator
	cout << "'quiz': " << myMap["quiz"] << endl;
	cout << "'foo': " << myMap["foo"] << endl;

	// non-existent key
	cout << "'bar': " << myMap["bar"] << endl; // gives default value of type double
}