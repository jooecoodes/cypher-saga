
#include "../../include/temp/Vector.hpp"
#include "../../include/temp/Matrix.hpp"

#include <array>

// Default constructor: initialize rowVector with default values.
template <typename T>
Vector<T>::Vector() : rowVector({}) {
    // Optionally, you can initialize explicitly:
    rowVector = { T(), T(), T() };
}

// Parameterized constructor: copy the provided vector.
template <typename T>
Vector<T>::Vector(std::array<T, 3> vec) : rowVector(vec) { }

// Operator* definition: Multiply a 1×3 row vector (this) by a 3×3 matrix (mat)
// and return a new 1×3 row vector as the result.
template <typename T>
Vector<T> Vector<T>::operator*(const Matrix<T>& mat) const {
    Vector<T> result;
    for (int j = 0; j < 3; ++j) {
        result.rowVector[j] = rowVector[0] * mat.matrix[0][j] +
                               rowVector[1] * mat.matrix[1][j] +
                               rowVector[2] * mat.matrix[2][j];
    }
    return result;
}
