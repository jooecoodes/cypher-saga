#include "../../include/core/Encryptor.hpp"

// Utils 
#include "../../include/utils/ASCIIHandler.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::cin;

namespace EncryptorUtils {
    inline int* generateKey() {
        int* key = new int[9]; // Allocate a 1D array to represent a 3x3 matrix
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                key[i * 3 + j] = rand() % 10; // Map 2D indices to 1D array
            }
        }
        return key;
    }
    
    inline void sentenceInputAndValidation(std::string &sentence) {
        // Input and validate the sentence to be encrypted
        std::cout << "Enter sentence to be encrypted: ";
        std::getline(std::cin, sentence);
    }

}

void encrypt() {
    // Encryptor code here
    int *key = EncryptorUtils::generateKey();
    // Print key values
    for (int i = 0; i < 9; i++) {
        std::cout << key[i] << " ";
    }

    // ASCIIHandler::printFromASCIIHandler();
    // std::string ASCII = ASCIIHandler::stringToASCII("Hello, World!");
    // std::cout << R"(This is the ASCII for "Hello, World!": )" << ASCII << std::endl;
}