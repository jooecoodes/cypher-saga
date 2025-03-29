#pragma once

#include "../../include/temp/Vector.hpp"

#include <iostream>
#include <string>

namespace StringHandler {
    std::string stringSlice(std::string str, int start, int end) {
        return str.substr(start, end - start);
    }
    
}

