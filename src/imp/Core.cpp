
#include "../../include/core/Core.hpp"

namespace Core
{

    vector<Vector<double>> encryptedVectors(const string &input, const Matrix<double> &matrix)
    {

        Matrix<double> identityMatrix({{{1.0, 0.0, 0.0},
                                        {0.0, 1.0, 0.0},
                                        {0.0, 0.0, 1.0}}});

        // Ensure processStringToVectors<T> is correctly included and defined
        auto vectors = processStringToVectors<double>(input, identityMatrix);
        std::cout << "Processed Vectors:\n";
        for (const auto &vec : vectors)
        {
            for (const auto &val : vec.rowVector)
            {
                std::cout << val << ' ';
            }
            std::cout << std::endl;
        }

        vector<Vector<double>> preVectors;

        for (const auto &vec : vectors)
        {
            // Multiply the vector by the given matrix.
            Vector<double> product = vec * matrix;
            preVectors.push_back(product);
        }

        return preVectors;
    }
    vector<Vector<double>> decryptedVectors(const vector<Vector<double>> &vectors, const Matrix<double> &matrix)
    {
        Matrix<double> m2Inverse = matrix.inverse();

        // Multiplying vectors to the inverse of the m2 Inverse of the matrix
        std::vector<Vector<double>> finalVectors;
        for (const auto& vec : vectors) {
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

        return finalVectors;
    }

    void encryptionPart(std::string &sentenceToEncrypt) {
        UI::sentenceInputAndValidation(sentenceToEncrypt);
        std::vector<Vector<double>> vectoredSentence = Utils::stringToVectors(sentenceToEncrypt);
        Utils::displayResult(vectoredSentence, "This is the results for encrypted vectors: ");
    }
    
    void decryptionPart() {
        std::string inputVectorsString;
    
        std::cout << "Enter the vectors separated by spaces: " << std::endl;
        getline(std::cin, inputVectorsString);
    
        std::string decryptedMessage = Utils::vectorsToString(Utils::stringChunkToVectors(inputVectorsString));
        Utils::displayResult(Utils::stringChunkToVectors(inputVectorsString), "This is the vectors from the string: ");
    
        std::cout << "Here is the decrypted message: " << decryptedMessage << std::endl;
    }

}