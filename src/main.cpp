// Encryptions
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
        if (choice.empty() || isNotDigitChecker(choice))
        {
            UI::invalidDisplay("Invalid Selection");
        }

        int choiceInInt = toIntForChoice(choice);
        string sentenceToEncrypt, sentenceToDecrypt;

        switch (choiceInInt)
        {
        case 1:
            UI::sentenceInputAndValidation(sentenceToEncrypt);
            displayResult(stringToVectors(sentenceToEncrypt), "This is the results for encrypted vectors: ");
            break;
        case 2:
            UI::encodeInputAndValidation(sentenceToDecrypt);
            
            break;
        case 3:

            break;
        default:

            UI::invalidDisplay("Invalid Selection");

            break;
        }
    }

    return 0;
}