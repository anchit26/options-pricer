// MeshMatrixGenerator.hpp
#ifndef MESH_MATRIX_GENERATOR_HPP
#define MESH_MATRIX_GENERATOR_HPP

#include "MatrixGeneratorInterface.hpp"
#include "Mesh.hpp"

#include <vector>
#include <boost/tuple/tuple.hpp>

/**
 * @brief Represents a matrix generator using Mesh
*/
class MeshMatrixGenerator : public MatrixGeneratorInterface
{
public:

	// Default constructor
	MeshMatrixGenerator();

	// Parametrized constructor
	MeshMatrixGenerator(std::vector<Mesh<double>> m_meshes);

	// Copy constructor
	MeshMatrixGenerator(const MeshMatrixGenerator& source);

	// Destructor
	virtual ~MeshMatrixGenerator();

	// GenerateMatrix()
	Matrix GenerateMatrix() const;

	// Add a mesh to the vector
	void AddMesh(const Mesh<double>& mesh);

private:
	
	// Represents a vector of Meshes 
	// this can take any number of parameters whose individual mesh ranges can be
	// passed and a matrix can be formed by combining those meshes
	std::vector<Mesh<double>> m_meshes;
};

#endif // !MESH_MATRIX_GENERATOR_HPP