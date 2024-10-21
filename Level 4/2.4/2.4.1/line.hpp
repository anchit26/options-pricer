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

	// Assignment operator
	Line& operator = (const Line& source); 

	// Destructor
	~Line();

	// Getters
	const Point& P1() const;
	const Point& P2() const;

	// Setters
	void P1(Point p) { m_start = p; }
	void P2(Point p) { m_end = p; }

	// Description
	std::string ToString() const;

	// Length
	double Length() const;
};

// Inline Getters
inline const Point& Line::P1() const
{
	return m_start;
}

inline const Point& Line::P2() const
{
	return m_end;
}

#endif // !LINE_HPP