// line.cpp
#include "line.hpp"
#include <sstream>

// Default constructor
Line::Line()
{
	m_start = Point(0, 0);
	m_end = Point(0, 0);
}

// Parametrized constructor
Line::Line(Point start, Point end)
{
	m_start = start;
	m_end = end;
}

// Copy constructor
Line::Line(const Line& l)
{
	m_start = l.m_start;
	m_end = l.m_end;
}

// Destructor
Line::~Line() {}

// Getters
const Point& Line::P1() const
{ 
	return m_start;
}

const Point& Line::P2() const
{
	return m_end;
}

// Setters
void Line::P1(Point p)
{ 
	m_start = p;
}

void Line::P2(Point p)
{
	m_end = p;
}

// Description
std::string Line::ToString() const
{
	std::stringstream sstream;
	sstream << "Line from " << m_start.ToString() << " to "
		<< m_end.ToString();
	return sstream.str();
}

// Length
double Line::Length() const
{
	return m_start.Distance(m_end);
}