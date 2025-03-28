
#pragma once

#include "../../include/temp/Matrix.hpp"

// Constructors
template <typename T>
Matrix<T>::Matrix() : matrix({{}}) {
    // Default constructor: initializes matrix with T's default values.
}

template <typename T>
Matrix<T>::Matrix(std::array<std::array<T, 3>, 3> matrix) : matrix(matrix) {
    // Parameterized constructor: copy the provided array.
}

// Operators

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    Matrix<T> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = T(); // Initialize to default value
            for (int k = 0; k < 3; k++) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    Matrix<T> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    Matrix<T> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar) const {
    Matrix<T> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& other) const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Other member functions

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::display() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
T Matrix<T>::determinant() const {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

template <typename T>
Matrix<T> Matrix<T>::inverse() const {
    T det = determinant();
    if (det == T()) {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }

    Matrix<T> result;

    result.matrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / det;
    result.matrix[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / det;
    result.matrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / det;

    result.matrix[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / det;
    result.matrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / det;
    result.matrix[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) / det;

    result.matrix[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) / det;
    result.matrix[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) / det;
    result.matrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) / det;

    return result;
}