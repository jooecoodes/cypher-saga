#include "../include/Defines.hpp"
#include "../include/ui/TypeText.hpp"

#include "../include/temp/Matrix.hpp"
#include "../include/temp/Vector.hpp"
#include "../include/temp/ProcessString.hpp"

// Encryptions
#include "../include/core/Encryptor.hpp"

#include "../include/utils/ASCIIHandler.hpp"



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


    ASCIIHandler::printFromASCIIHandler();
    string ASCII = ASCIIHandler::stringToASCII("Hello, World!");
    std::cout << R"(This is the ASCII for "Hello, World!": )" << ASCII << std::endl;

    // encrypt();

    // Initialize a 1×3 row vector with example values
    Vector<double> rowVec({1.0, 2.0, 3.0});

    // Initialize a 3×3 matrix with example values
    Matrix<double> mat({{
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {10.0, 11.0, 12.0}
    }});
    
    // Perform the multiplication
    Vector<double> result = rowVec * mat;

    // Output the result
    std::cout << "Resulting 1×3 Vector:\n";
    for (const auto& val : result.rowVector) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    // Process a string into vectors
    std::string input = "Hello, World!";
    Matrix<double> identityMatrix({{
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    }});
    auto vectors = processStringToVectors<double>(input, identityMatrix);
    std::cout << "Processed Vectors:\n";
    for (const auto& vec : vectors) {
        for (const auto& val : vec.rowVector) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }

    // Multiplying to m2 matrix
    std::cout << "Vectors multiplied by m2 Matrix:\n";
        // Multiplying vectors to the inverse of the m2 Inverse of the matrix
        std::vector<Vector<double>> preVectors;
        for (const auto& vec : vectors) {
            // Multiply the vector by the second matrix.
            Vector<double> product = vec * m2;
            preVectors.push_back(product);
    }

    
    std::cout << "This is the result of multiplying each processed vector by the m2 matrix:\n";

    for (const auto& vec : preVectors) {
        for (const auto& val : vec.rowVector) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }

    // Multiplying vectors to the inverse of the m2 Inverse of the matrix
    std::vector<Vector<double>> finalVectors;
    for (const auto& vec : preVectors) {
        // Multiply the vector by the second matrix.
        Vector<double> product = vec * m2Inverse;
        finalVectors.push_back(product);
    }


    std::cout << "This is the result of multiplying each processed vector by the inverse of the m2 matrix:\n";

    for (const auto& vec : finalVectors) {
        for (const auto& val : vec.rowVector) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }

    
    return 0;
}