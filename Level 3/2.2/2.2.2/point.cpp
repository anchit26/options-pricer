// point.cpp
#include "point.hpp"
#include <sstream>
#include <cmath>

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

// Distance from origin
double Point::DistanceOrigin()
{
	return Distance(Point{});
}

// Distance from point p using pythagoras algorithm
double Point::Distance(Point p)
{
	double x_squared = pow(abs(p.m_x - m_x), 2); // (x1 - x2)^2
	double y_squared = pow(abs(p.m_y - m_y), 2); // (y1 - y2)^2
	return sqrt(x_squared + y_squared); // sqrt
}