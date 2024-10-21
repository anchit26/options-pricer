// point.hpp
#include <string>

#ifndef POINT_HPP
#define POINT_HPP

/**
 * @brief Represents a point object in 2-D
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

	//  Inline Getters
	double X() const;
	double Y() const;

	// Inline Setters
	void X(double x) { m_x = x; }
	void Y(double y) { m_y = y; }

	// ToString 
	std::string ToString() const;

	// distance functions
	double Distance() const; // distance from origin
	double Distance(const Point& p) const; // distance from a given point p
};

// Inline getters implementation
inline double Point::X() const
{
	return m_x;
}

inline double Point::Y() const
{
	return m_y;
}

#endif // !POINT_HPP