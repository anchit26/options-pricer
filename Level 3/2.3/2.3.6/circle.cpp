// circle.cpp
#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <sstream>
#include <cmath>

// Default constructor
Circle::Circle()
{
	// unit circle with centre at origin
	m_centre = Point(0, 0);
	m_radius = 1;
}

// Parametrized
Circle::Circle(Point centre, double radius)
{
	m_centre = centre;
	m_radius = radius;
}

// Copy constructor
Circle::Circle(const Circle& c)
{
	m_centre = c.m_centre;
	m_radius = c.m_radius;
}

// Destructor
Circle::~Circle() {}

// Getters
Point Circle::CentrePoint() const
{
	return m_centre;
}

double Circle::Radius() const
{
	return m_radius;
}

// Setters
void Circle::CentrePoint(Point c)
{
	m_centre = c;
}

void Circle::Radius(double r)
{
	m_radius = r;
}

// ToString
std::string Circle::ToString() const
{
	std::stringstream sstream;
	sstream.precision(2);
	sstream << std::fixed << "Circle centre at " << m_centre.ToString() << " with radius "
		<< m_radius;
	return sstream.str();
}

// Diameter
double Circle::Diameter() const
{
	// 2 * radius 
	return 2 * m_radius;
}

// Area
double Circle::Area() const
{
	// pi * (radius^2)
	return M_PI * pow(m_radius, 2);
}

// Circumference
double Circle::Circumference() const
{
	// 2 * pi * radius
	return 2 * M_PI * m_radius;
}