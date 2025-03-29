
#include "../../include/temp/ProcessString.hpp"

#include <string>
#include <vector>

template <typename T>
std::vector<Vector<T>> processStringToVectors(const std::string& input, const Matrix<T>& mat) {
    std::string s = input;
    
    // Pad the string with spaces until its length is a multiple of 3.
    while (s.length() % 3 != 0) {
        s.push_back(' ');
    }
    
    std::vector<Vector<T>> results;
    // Process the string in chunks of 3 characters.
    for (std::size_t i = 0; i < s.length(); i += 3) {
        std::array<T, 3> arr;
        for (int j = 0; j < 3; ++j) {
            // Convert char to its ASCII code (or cast as needed).
            arr[j] = static_cast<T>(s[i + j]);
        }
        // Create a vector from the array.
        Vector<T> vec(arr);
        // Multiply the vector by the matrix.
        Vector<T> product = vec * mat;
        results.push_back(product);
    }
    return results;
}