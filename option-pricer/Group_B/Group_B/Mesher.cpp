// mesher.cpp

#ifndef MESHER_CPP
#define MESHER_CPP

#include "Mesher.hpp"

// mesh generator function
template <typename T>
std::vector<T> GenerateMeshArray(T start, int numEntries, T step) {

    // declare the mesh of type T
    std::vector<T> mesh;
    
    // handle edge case when numEntries is <= 0
    if (numEntries <= 0)
    {
        return mesh;
    }

    // reserve the required size to avoid
    // memory relocations during pushback
    mesh.reserve(numEntries);

    // carries value of the last populated element in mesh array
    // initialize to 
    T lastPopulated = start;

    // populate the first element
    mesh.push_back(lastPopulated);

    // populate the mesh onwards with step increase
    for (size_t i = 1; i < numEntries; i++) {
        
        // uses + operator overloader of type T
        lastPopulated = lastPopulated + step;
        mesh.push_back(lastPopulated);
    }
    return mesh;
}

#endif // !MESHER_CPP