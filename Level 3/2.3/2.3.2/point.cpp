// point.cpp
#include "point.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

// Default constructor
// initialize point to origin
Point::Point() : m_x(0.0), m_y(0.0)
{
	std::cout << "Point default constructor called" << std::endl;
}

// Parametrized constructor
Point::Point(double x, double y) : m_x(x), m_y(y)
{
	std::cout << "Point parametrized constructor called " << ToString()
		<< std::endl;
}

// Copy constructor
Point::Point(Point& p) : m_x(p.m_x), m_y(p.m_y)
{
	std::cout << "Point copy constructor called " << ToString() << std::endl;
}

// Destructor
Point::~Point()
{
	std::cout << "Point destructor called " << ToString() << std::endl;
}

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