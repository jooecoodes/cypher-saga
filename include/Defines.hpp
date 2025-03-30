#pragma once
#include <string>
using std::string;

namespace Constants {
    // front end global constants
    inline const string  RED = "\033[1;31m";
    inline const string  GREEN = "\033[1;32m";
    inline const string  CYAN = "\033[1;36m";
    inline const string  MAGENTA = "\033[1;33m";
    inline const string  RESET = "\033[0m";

    inline const string  RED_BACKGROUND = "\x1b[41m";
    inline const string  GREEN_BACKGROUND = "\x1b[42m";
}