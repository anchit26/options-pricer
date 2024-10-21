// MatrixGeneratorInterface.hpp
#ifndef MATRIX_GENERATOR_INTERFACE_HPP
#define MATRIX_GENERATOR_INTERFACE_HPP

#include "Matrix.hpp"

/**
 * @brief Represents an interface to create a matrix with
 * option parameters
*/
class MatrixGeneratorInterface 
{
public:

	// Default constructor
	MatrixGeneratorInterface() {};

	// Destructor
	virtual ~MatrixGeneratorInterface() {};

	// GenerateMatrix pure virtual function
	// This would be implemented by child classes
	// which define the way a Matrix would be generated and returned
	virtual Matrix GenerateMatrix() const = 0;
};

#endif // !MATRIX_GENERATOR_INTERFACE_HPP