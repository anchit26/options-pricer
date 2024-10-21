// point.hpp
#include <string>

#ifndef POINT_HPP
#define POINT_HPP

/**
 * @brief Represents a point in 2-D
*/
class Point
{
	// private
private:
	// x coordinate
	double m_x;

	// y coordinate
	double m_y;

	// public
public:

	// Default Constructor
	Point();

	// Parametrized Constructor
	Point(double x, double y);

	// Copy Constructor
	Point(const Point& p);

	// Destructor
	~Point();

	// Getters
	double X() const;
	double Y() const;

	// Setters
	void X(double x);
	void Y(double y);

	// ToString 
	std::string ToString() const;

	// distance functions
	double Distance() const; // distance from origin
	double Distance(const Point& p) const; // distance from a given point p

};

#endif // !POINT_HPP