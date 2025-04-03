#pragma once

#include <cctype> // Required for isdigit
#include <sstream>
#include <vector>

#include "../temp/Matrix.hpp"
#include "../temp/Vector.hpp"
#include "../temp/ProcessString.hpp"

#include "../core/Core.hpp"

namespace Utils {
    bool isNotDigitChecker(const std::string &choice);
    int toIntForChoice(const std::string &strValue);
    std::vector<Vector<double>> stringToVectors(const std::string &sentenceToEncrypt);
    std::string vectorsToString(const std::vector<Vector<double>> &encryptedVectorsResult);
    void displayResult(const std::vector<Vector<double>> vector, const std::string &desc);
    std::vector<Vector<double>> stringChunkToVectors(const std::string &numbersString);
}