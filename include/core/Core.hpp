#pragma once 

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../ui/UI.hpp"
#include "../utils/Utils.hpp"

#include "../temp/Matrix.hpp"
#include "../temp/Vector.hpp"
#include "../temp/ProcessString.hpp"

using std::string;
using std::vector;
using std::cin;

namespace Core {
    std::vector<Vector<double>> encryptedVectors(const string &input, const Matrix<double> &matrix);
    std::vector<Vector<double>> decryptedVectors(const vector<Vector<double>> &vectors, const Matrix<double> &matrix);
    void encryptionPart(std::string &sentenceToEncrypt);
    void decryptionPart();
}
