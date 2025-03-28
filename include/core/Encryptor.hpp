#pragma once 

#include <iostream>
#include <string>
using std::string;


namespace Encryptor {
    inline int* generateKey();
    void sentenceInputAndValidation(std::string &sentence);
}

void encrypt();