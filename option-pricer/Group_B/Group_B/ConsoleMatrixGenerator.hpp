// ConsoleMatrixGenerator.hpp
#ifndef CONSOLE_MATRIX_GENERATOR_HPP
#define CONSOLE_MATRIX_GENERATOR_HPP

#include "MatrixGeneratorInterface.hpp"

/**
 * @brief Represents Matrix generator class through console
*/
class ConsoleMatrixGenerator : public MatrixGeneratorInterface
{
public:
	// Default constructor
	ConsoleMatrixGenerator() {}

	// Destructor
	virtual ~ConsoleMatrixGenerator() {}

	// GenerateMatrix()
	// TODO: Not implemented, only as a design placeholder
	Matrix GenerateMatrix() const { return Matrix(0, 0); };

};

#endif // !CONSOLE_MATRIX_GENERATOR_HPP