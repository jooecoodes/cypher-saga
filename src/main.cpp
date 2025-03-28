#include "../include/Defines.hpp"
#include "../include/ui/TypeText.hpp"
#include "../include/temp/Matrix.hpp"

#include <iostream>

int main() {
    UITypeText::typeText("Hello, World!", 100, UIConstants::RED);

    Matrix<int> m1 = Matrix<int>( { { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } } );
    Matrix<int> m2 = Matrix<int>( { { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } } );

    m1.display();
    m2.display();

    Matrix<int> m3 = m1 + m2;
    m3.display();
    

    return 0;
}