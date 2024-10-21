// MeshMatrixGenerator.cpp
#include "MeshMatrixGenerator.hpp"

// Default constructor
MeshMatrixGenerator::MeshMatrixGenerator() :
	m_meshes()
{}

// Parametrized constructor
MeshMatrixGenerator::MeshMatrixGenerator(std::vector<Mesh<double>> meshes) :
	m_meshes(meshes)
{}

// Copy constructor
MeshMatrixGenerator::MeshMatrixGenerator(const MeshMatrixGenerator& source):
	m_meshes(source.m_meshes)
{}

// Destructor
MeshMatrixGenerator::~MeshMatrixGenerator()
{}

// GenerateMatrix()
Matrix MeshMatrixGenerator::GenerateMatrix() const
{
	// declare a matrix
	Matrix meshMatrix;

	for (int i = 0; i < m_meshes.size(); i++)
	{
		// Generate a mesh using Mesh's member function GenerateMesh
		// Push the generated mesh into the meshMatrix
		meshMatrix.AddRow(m_meshes[i].GenerateMesh());
	}

	meshMatrix.Transpose();
	return meshMatrix;
}

// Add a mesh to the vector
void MeshMatrixGenerator::AddMesh(const Mesh<double>& mesh)
{
	m_meshes.push_back(mesh);
}

