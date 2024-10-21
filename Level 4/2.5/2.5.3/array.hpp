// array.hpp
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "point.hpp"

/**
 * @brief Array class for Point objects
*/
class Array
{
private:
	// dynamic array for Point objects
	Point* m_data;

	// size of the data array
	unsigned int m_size;

public:

	// Default constructor
	Array();

	// Parametrized constructor
	Array(unsigned int size);

	// Copy constructor
	Array(const Array& source);

	// Destructor
	~Array();

	// Assignment operator
	Array& operator = (const Array& source);

	// Size
	unsigned int Size() const;

	// set element
	void SetElement(const Point& p, unsigned int idx);

	// GetElement
	Point& GetElement(unsigned int idx); // non-const
	const Point& GetElement(unsigned int idx) const; //const (read only access)

	// [] operator
	Point& operator [] (unsigned int idx); // non-const
	const Point& operator [] (unsigned int idx) const; //const (read only access)

	// Send to ostream
	friend std::ostream& operator <<  (std::ostream& os, const Array& arr);
};

// Size getter
inline unsigned int Array::Size() const
{
	return m_size;
}

#endif // !ARRAY_HPP