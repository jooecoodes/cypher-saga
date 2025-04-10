#pragma once

#include <array>
#include "Matrix.hpp"  

#include <array>

template <typename T>
struct Vector {
    std::array<T, 3> rowVector;

    // Constructor declarations
    Vector();
    Vector(std::array<T, 3> vec);

    // Operator declaration: Multiply this 1x3 row vector by a 3x3 matrix.
    Vector<T> operator*(const Matrix<T>& mat) const;

    // (Any other method declarations)
};

// Include implementations at the end.
#include "../../src/temp/Vector.tpp"
