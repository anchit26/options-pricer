// Mesher.hpp
#ifndef MESHER_HPP
#define MESHER_HPP

#include <vector>

// generic mesh generator function
// default type is double
template <typename T = double>
std::vector<T> GenerateMeshArray(T start, int numEntries, T step);

#ifndef MESHER_CPP
#include "Mesher.cpp"
#endif 

#endif // !MESHER_HPP
