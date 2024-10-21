// point.cpp
#include "point.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

// Default constructor
// initialize point to origin
Point::Point() : m_x(0.0), m_y(0.0) {}

// Parametrized constructor
Point::Point(double x, double y) : m_x(x), m_y(y) {}

// Copy constructor
Point::Point(Point& p) : m_x(p.m_x), m_y(p.m_y) {}

// Destructor
Point::~Point() {}

// Get x coordinate
double Point::X()
{
	return m_x;
}

// Get y coordinate
double Point::Y()
{
	return m_y;
}

// Set x coordinate
void Point::X(double x)
{
	m_x = x;
}

// Set y coordinate
void Point::Y(double y)
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
double Point::Distance()
{
	Point origin(0.0, 0.0);
	return Distance(origin);
}

// Distance from point p using pythagoras algorithm
double Point::Distance(const Point& p)
{
	double x_squared = pow(abs(p.m_x - m_x), 2); // (x1 - x2)^2
	double y_squared = pow(abs(p.m_y - m_y), 2); // (y1 - y2)^2
	return sqrt(x_squared + y_squared); // sqrt
}