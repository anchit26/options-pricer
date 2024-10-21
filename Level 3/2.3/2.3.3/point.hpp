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
	Point(Point& p);

	// Destructor
	~Point();

	// Getters
	double X();
	double Y();

	// Setters
	void X(double x);
	void Y(double y);

	// ToString 
	std::string ToString();

	// distance functions
	double Distance(); // distance from origin
	double Distance(const Point& p); // distance from a given point p

};

#endif // !POINT_HPP