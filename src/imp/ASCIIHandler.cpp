#include "../../include/utils/ASCIIHandler.hpp"

#include <iostream>
#include <string>
#include <sstream>

using std::string;

namespace ASCIIHandler {
    void printFromASCIIHandler() {
        std::cout << "This is from ASCIIHandler" << std::endl;
    }
    std::string stringToASCII(const std::string &str) {
        std::stringstream ss;
        for (char c : str) {
            ss << int(c) << " ";
        }
        return ss.str();
    }
    std::string ASCIItoString(const std::string &str) {
        std::stringstream ss;
        std::string result;
        std::istringstream iss(str);
        int ascii;
        while (iss >> ascii) {
            ss << char(ascii);
        }
        return ss.str();
    }
}