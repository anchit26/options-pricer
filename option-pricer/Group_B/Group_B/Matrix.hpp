// Matrix.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

/**
 * @brief Represents a 2D matrix
*/
class Matrix 
{
public:
	// default constructor
	Matrix();

	// parametrized constructor to create matrix with given rows and elements
	Matrix(int rows, int cols);

	// Assignment operator
	Matrix& operator = (const Matrix& source);

	// operator overloading to access elements
	double& operator()(int row, int col);
	const double& operator()(int row, int col) const;

	// getters
	int Rows() const { return m_rows; }
	int Cols() const { return m_cols; }

	// Get a row of the matrix
	std::vector<double> GetRow(int row) const;

	// Add a row to the matrix
	void AddRow(const std::vector<double>& row);

	// Update an element at a specific position
	void UpdateElement(int row, int col, double value);

	// Transposes the matrix
	Matrix& Transpose();

private:
	// vector of vectors which holds the matrix data
	std::vector<std::vector<double>> m_data;
	
	// number of rows in the matrix
	int m_rows;
	
	// nmumber of columns in the matrix
	int m_cols;

	// checks if valid row col is provided
	void CheckBounds(int row, int col) const;
};

#endif // !MATRIX_HPP