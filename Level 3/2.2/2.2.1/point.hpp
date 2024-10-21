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
	double m_x;
	double m_y;

// public
public:

	// Default Constructor
	Point();

	// Destructor
	~Point();

	// Getters
	double GetX();
	double GetY();

	// Setters
	void SetX(double x);
	void SetY(double y);

	// ToString 
	std::string ToString();
};

#endif // !POINT_HPP