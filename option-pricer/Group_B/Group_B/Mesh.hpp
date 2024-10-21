// Mesh.hpp
#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

/**
 * @brief Represents the mesh class
*/
template <typename T>
class Mesh 
{
public:
	// Default constructor
	Mesh();

	// Parametrized constructor
	Mesh(T start, int size, T step);

	// Getters
	double GetStart() const { return m_start; }
	int GetSize() const { return m_size; }
	double GetStep() const { return m_step; }

	// GenerateMesh()
	std::vector<T> GenerateMesh() const;

private:
	// starting value of the mesh
	T m_start;

	// size of the mesh
	int m_size;

	// step of the mesh values
	T m_step;
};

#ifndef MESH_CPP
#include "Mesh.cpp"
#endif

#endif // !MESH_HPP