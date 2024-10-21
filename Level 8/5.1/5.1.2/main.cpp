// tuple
#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>

// Tuple to store different kinds of entity
// This tuple contains: 
// - Name (std::string) at index 0
// - Age (int) at index 1
// - Height (double) at index 2
typedef boost::tuple<std::string, int, double> Person;

void PrintPerson(const Person& person);

int main()
{
    // Person tuple instances
    Person person1 = boost::make_tuple("foo", 30, 5.5);
    Person person2 = boost::make_tuple("bar", 25, 6.0);

    // Print
    PrintPerson(person1);
    PrintPerson(person2);

    // Increment the age 
    boost::get<1>(person1) += 1;

    // Print after incrementing age
    std::cout << "After incrementing age:" << std::endl;
    PrintPerson(person1);

    return 0;
}

// PrintPerson()
void PrintPerson(const Person& person) 
{
    //auto [name, age, height] = person; // can also be used 
    std::cout << "Name: " << boost::get<0>(person)
        << ", Age: " << boost::get<1>(person)
        << ", Height: " << boost::get<2>(person) 
        << std::endl;
}