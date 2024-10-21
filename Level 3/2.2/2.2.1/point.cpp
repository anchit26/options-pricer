// point.cpp
#include "point.hpp"
#include <sstream>

// Default constructor
// initialize point to origin
Point::Point() : m_x(0), m_y(0) {}

// Destructor
Point::~Point() {}

// Get x coordinate
double Point::GetX()
{
	return m_x;
}

// Get y coordinate
double Point::GetY()
{
	return m_y;
}

// Set x coordinate
void Point::SetX(double x)
{
	m_x = x;
}

// Set y coordinate
void Point::SetY(double y)
{
	m_y = y;
}

// ToString 
std::string Point::ToString()
{
	std::stringstream sstream;
	sstream.precision(1);
	sstream << std::fixed << "Point(" << m_x << ", " << m_y << ")";
	return sstream.str();
}