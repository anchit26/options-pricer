// Mesh.cpp
#ifndef MESH_CPP
#define MESH_CPP

#include "Mesh.hpp"

// Default constructor
template <typename T>
Mesh<T>::Mesh() :
	m_start(),
	m_size(1),
	m_step()
{}

// Parametrized constructor
template <typename T>
Mesh<T>::Mesh(T start, int size, T step) :
	m_start(start),
	m_size(size),
	m_step(step)
{}

// mesh generator function
template <typename T>
std::vector<T> Mesh<T>::GenerateMesh() const
{
	// declare the mesh of type T
	std::vector<T> mesh;

	// handle edge case when numEntries is <= 0
	if (m_size <= 0)
	{
		return mesh;
	}

	// reserve the required size to avoid
	// memory relocations during pushback
	mesh.reserve(m_size);

	// carries value of the last populated element in mesh array
	// initialize to 
	T lastPopulated = m_start;

	// populate the first element
	mesh.push_back(lastPopulated);

	// populate the mesh onwards with step increase
	for (size_t i = 1; i < m_size; i++) {

		// uses + operator overloader of type T
		lastPopulated = lastPopulated + m_step;
		mesh.push_back(lastPopulated);
	}
	return mesh;
}

#endif // !MESH_CPP