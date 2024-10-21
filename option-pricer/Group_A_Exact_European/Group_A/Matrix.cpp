// Matrix.cpp
#include "Matrix.hpp"
#include <stdexcept>

// Default constructor
Matrix::Matrix() :
	m_rows(0),
	m_cols(0),
	m_data()
{}

// parametrized constructor
Matrix::Matrix(int rows, int cols) : 
	m_rows(rows),
	m_cols(cols), 
	m_data(rows, std::vector<double>(cols, 0)) 
{}

// assignment operator
Matrix& Matrix::operator = (const Matrix& source)
{
	// handle self assignment
	if (this == &source)
		return *this;

	m_data = source.m_data; // use vector's assignment operator
	m_cols = source.m_cols;
	m_rows = source.m_rows;

	return *this;
}

// getter through operator overload
double& Matrix::operator()(int row, int col) 
{
	CheckBounds(row, col);
	return m_data[row][col];
}

// const getter through operator overload
const double& Matrix::operator()(int row, int col) const 
{
	CheckBounds(row, col);
	return m_data[row][col];
}

// GetRow()
std::vector<double> Matrix::GetRow(int row) const 
{
	CheckBounds(row, 0);
	return m_data[row];
}

// AddRow()
void Matrix::AddRow(const std::vector<double>& row) 
{
	// push vector to the vector of vectors
	m_data.push_back(row);

	// increase rows count
	m_rows++;

	// set cols count
	m_cols = row.size();
}

// UpdateElement()
void Matrix::UpdateElement(int row, int col, double value)
{
	CheckBounds(row, col);

	// set value at the position
	m_data[row][col] = value;
}

// Transpose the Matrix
Matrix& Matrix::Transpose()
{
	// check if matrix is empty
	if (m_rows == 0 && m_cols == 0) {
		return *this;
	}

	// local variable to hold a transposed matrix
	Matrix transposed(m_cols, m_rows);

	// fill the transpose matrix
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			// value at [i, j] in current goes to [j, i] in transposed
			transposed.UpdateElement(j, i, m_data[i][j]);
		}
	}

	// use the assignment operator
	Matrix::operator=(transposed);

	return *this;
}

//////////////////////////////////////////////////////////////////////////////////

// Checks bounds whenever a get/set is done on the matrix data
void Matrix::CheckBounds(int row, int col) const 
{
	if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
		throw std::out_of_range("Matrix index out of bounds");
	}
}
