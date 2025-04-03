#include "../include/core/Core.hpp"

#include "../include/ui/UI.hpp"
#include "../include/temp/Matrix.hpp"
#include "../include/temp/Vector.hpp"

#include <iostream>
#include <sstream>

inline bool isNotDigitChecker(const std::string &choice)
{
    return !isdigit(choice.at(0));
}
inline int toIntForChoice(const std::string &strValue)
{
    std::istringstream iss(strValue); // create a string stream from the input string.
    int intValue = 0;                 // initialize an integer to store the converted value.
    iss >> intValue;                  // extract the integer value from the string stream.
    return intValue;                  // return the converted integer.
}

std::vector<Vector<double>> stringToVectors(const std::string &sentenceToEncrypt)
{
    Matrix<double> mat({{{5.0, 8.0, 12.0},
                         {1.0, 2.0, 4.0},
                         {10.0, 11.0, 12.0}}});
    std::vector<Vector<double>> encryptedVectorsResult = Core::encryptedVectors(sentenceToEncrypt, mat);
    return encryptedVectorsResult;
}


std::string vectorsToString(const std::vector<Vector<double>> &encryptedVectorsResult) {
    Matrix<double> mat({{{5.0, 8.0, 12.0},
        {1.0, 2.0, 4.0},
        {10.0, 11.0, 12.0}}});
    std::vector<Vector<double>> decryptedVectorsResult = Core::decryptedVectors(encryptedVectorsResult, mat);
    std::string resultFromVectors = processVectorsToString<double>(decryptedVectorsResult);
    std::cout << "This is the result for decryption: " << resultFromVectors << std::endl;
    return resultFromVectors;
}

void displayResult(const std::vector<Vector<double>> vector, const std::string &desc) {
        
    std::cout << desc << std::endl;
    for (const auto &vec : vector) {
        for (const auto &val : vec.rowVector) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<Vector<double>> stringChunkToVectors(const std::string &numbersString) {
    std::istringstream iss(numbersString);
    std::vector<Vector<double>> vectors;
    std::vector<double> tempVector;
    double number;
    int count = 0;

    while (iss >> number) {
        tempVector.push_back(number);
        count++;
        if (count == 3) {
            // Convert std::vector<double> to std::array<double, 3>
            std::array<double, 3> arr = {tempVector[0], tempVector[1], tempVector[2]};
            vectors.emplace_back(arr); // Now it matches the constructor
            tempVector.clear();
            count = 0;
        }
    }

    if (!tempVector.empty()) {
        // Handle cases where the last chunk has fewer than 3 elements
        std::array<double, 3> arr = {0.0, 0.0, 0.0}; // Default initialize
        for (size_t i = 0; i < tempVector.size(); i++) {
            arr[i] = tempVector[i];
        }
        vectors.emplace_back(arr);
    }

    return vectors;
}

void encryptionPart(std::string &sentenceToEncrypt) {
    UI::sentenceInputAndValidation(sentenceToEncrypt);
    std::vector<Vector<double>> vectoredSentence = stringToVectors(sentenceToEncrypt);
    displayResult(vectoredSentence, "This is the results for encrypted vectors: ");
}

void decryptionPart() {
    std::string inputVectorsString;

    std::cout << "Enter the vectors separated by spaces: " << std::endl;
    getline(std::cin, inputVectorsString);

    std::string decryptedMessage = vectorsToString(stringChunkToVectors(inputVectorsString));
    displayResult(stringChunkToVectors(inputVectorsString), "This is the vectors from the string: ");

    std::cout << "Here is the decrypted message: " << decryptedMessage << std::endl;
}

int main()
{

    UI::loadingBar("Loading", 1000, 90);
    UI::breakDisplay(50);
    UI::logoDisplay();
    UI::breakDisplay(50);
    UI::introDisplay();
    UI::breakDisplay(50);

    std::string choice;
    bool sentinel = true;
    while (sentinel)
    {
        UI::optionDisplay();
        std::getline(std::cin, choice);
        // if (choice.empty() || isNotDigitChecker(choice))
        // {
        //     UI::invalidDisplay("Invalid Selection");
        // }

        int choiceInInt = toIntForChoice(choice);
        string sentenceToEncrypt, sentenceToDecrypt;
        

        switch (choiceInInt)
        {
        case 1:
            encryptionPart(sentenceToEncrypt);

            break;
        case 2:
            decryptionPart();

            break;
        case 3:
            sentinel = false;

            break;
        default:

            UI::invalidDisplay("Invalid Selection");

            break;
        }
    }

    return 0;
}