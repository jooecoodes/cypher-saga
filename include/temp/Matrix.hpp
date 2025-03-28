#pragma once
#include <array>
#include <iostream> // For display()

template <typename T>
struct Matrix {
    std::array<std::array<T, 3>, 3> matrix;

    // Constructor declarations
    Matrix();
    Matrix(std::array<std::array<T, 3>, 3> matrix);

    // Operator declarations
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const T& scalar) const;
    bool operator==(const Matrix<T>& other) const;

    // Method declarations
    Matrix<T> transpose() const;
    void display() const;
    T determinant() const;
};


// Include implementations at the end
#include "../../src/temp/Matrix.tpp"