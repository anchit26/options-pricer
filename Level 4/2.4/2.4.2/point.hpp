// point.hpp
#include <string>
#include <ostream>

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

	// operator overloading
	Point operator - () const; // Negates the coordinates
	Point operator * (double factor) const; // Scale the coordinates
	Point operator + (const Point& p) const; // Add coordinates
	bool operator == (const Point& p) const; // Equally compare
	Point& operator = (const Point& source); // Assignment 
	Point& operator *= (double factor); // Scale the corrdinates and assign
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

// Send to ostream
std::ostream& operator << (std::ostream& os, const Point& p); 

#endif // !POINT_HPP