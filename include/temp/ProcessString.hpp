#pragma once

#include <vector>
#include <string>
#include "Vector.hpp"  
#include "Matrix.hpp"  

template <typename T>
std::vector<Vector<T>> processStringToVectors(const std::string& input, const Matrix<T>& mat);
template <typename T>
std::vector<Vector<T>> processVectorsToString(const std::string& input, const Matrix<T>& mat);

// Include the implementation file at the end.
#include "../../src/temp/ProcessString.tpp"
