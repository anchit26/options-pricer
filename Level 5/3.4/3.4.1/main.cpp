// colon syntax for constructors
#include "line.hpp"

int main() 
{
    // Full namespace for Line
    AnchitAgarwal::CAD::Line l;
}


// output without colon syntax
/*
Point contructor called
Point contructor called
Point param contructor called
Point assignment operator called
Point destructor called
Point param contructor called
Point assignment operator called
Point destructor called
Point destructor called
Point destructor called
*/

// output with colon syntax
/*
Point param contructor called
Point param contructor called
Point destructor called
Point destructor called
*/