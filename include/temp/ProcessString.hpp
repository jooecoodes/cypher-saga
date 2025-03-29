#pragma once

#include <vector>
#include <string>
#include "Vector.hpp"   // Ensure your Vector<T> is declared/defined here.
#include "Matrix.hpp"   // Ensure your Matrix<T> is declared/defined here.

template <typename T>
std::vector<Vector<T>> processStringToVectors(const std::string& input, const Matrix<T>& mat);

// Include the implementation file at the end.
#include "../../src/temp/ProcessString.tpp"