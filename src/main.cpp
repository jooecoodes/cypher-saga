#include "../include/Defines.hpp"
#include "../include/ui/TypeText.hpp"
#include "../include/temp/Matrix.hpp"

#include <iostream>

int main() {
    UITypeText::typeText("Hello, World!", 100, UIConstants::RED);

    Matrix<double> m1 = Matrix<double>( { { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } } );
    Matrix<double> m2 = Matrix<double>( { { { 2, 4, 1 }, { 7, 2, 2 }, { 6, 2, 4 } } } );

    m1.display();
    m2.display();

    Matrix<double> m3 = m1 + m2;
    m3.display();
    std::cout << "Determinant of the m3 matrix: " << m1.determinant() << std::endl;
    std::cout << "Determinant of the m2 matrix: " << m2.determinant() << std::endl;
    
    Matrix<double> m2Inverse = m2.inverse();

    std::cout << "Inverse of the m2 matrix: " << std::endl;
    m2Inverse.display();
    
    return 0;
}