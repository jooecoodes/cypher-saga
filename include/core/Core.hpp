#pragma once 

#include <iostream>
#include <string>
#include <vector>

#include "../../include/temp/Matrix.hpp"
#include "../../include/temp/Vector.hpp"
#include "../../include/temp/ProcessString.hpp"

using std::string;
using std::vector;

namespace Core {
    std::vector<Vector<double>> encryptedVectors(const string &input, const Matrix<double> &matrix);
    std::vector<Vector<double>> decryptedVectors(const vector<Vector<double>> &vectors, const Matrix<double> &matrix);
}
