// circle.hpp
#include "point.hpp"
#include <string>

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

/**
 * @brief Represents a circle object in 2D
*/
class Circle
{
private:
	// centre
	Point m_centre;
	
	// radius
	double m_radius;

public:

	// Default constructor
	Circle();

	// Parametrized constructor
	Circle(Point, double);

	// Copy constructor
	Circle(const Circle&);

	// Destructor
	~Circle();

	// Getters
	Point CentrePoint() const;
	double Radius() const;

	// Setters
	void CentrePoint(Point);
	void Radius(double);

	// ToString
	std::string ToString() const;

	// Diameter
	double Diameter() const;

	// Area
	double Area() const;

	// Circumference
	double Circumference() const;
};

#endif // !CIRCLE_HPP