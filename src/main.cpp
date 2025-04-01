// Encryptions
#include "../include/core/Core.hpp"


#include <iostream>

int main() {
    // Initialize a 3×3 matrix with example values
    Matrix<double> mat({{
        {5.0, 8.0, 12.0},
        {1.0, 2.0, 4.0},
        {10.0, 11.0, 12.0}
    }});
    std::string input = "Hello, World!";
    std::vector<Vector<double>> encryptResult = Core::encryptedVectors(input, mat);
    std::vector<Vector<double>> decryptResult = Core::decryptedVectors(encryptResult, mat);

    // std::cout << "This is for encryptResult" << std::endl;
    // for (const auto &vec : encryptResult) {
    //     for (const auto &val : vec.rowVector) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << "This is for decryptResult" << std::endl;
    // for (const auto &vec : decryptResult) {
    //     for (const auto &val : vec.rowVector) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::string resultFromVectors = processVectorsToString<double>(decryptResult);
    std::cout << "This is the result for decryption: " << resultFromVectors << std::endl;

    return 0;
}