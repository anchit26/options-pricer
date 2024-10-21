// line.hpp
#include "point.hpp"
#include <string>

#ifndef LINE_HPP
#define LINE_HPP

/**
 * @brief Represents a line object in 2-D
*/
class Line
{
private:
	// start point
	Point m_start;

	// end point
	Point m_end;

public:

	// Default constructor
	Line();

	// Parametrized constructor
	Line(Point start, Point end);

	// Copy constructor
	Line(const Line& l);

	// Destructor
	~Line();

	// Getters
	const Point& P1() const;
	const Point& P2() const;

	// Setters
	void P1(Point);
	void P2(Point);

	// Description
	std::string ToString() const;

	// Length
	double Length() const;
};

#endif // !LINE_HPP