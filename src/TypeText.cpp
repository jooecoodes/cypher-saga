#include "../include/ui/TypeText.hpp"
#include "../include/Defines.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::string;

namespace UITypeText {
    void typeText(const string &text, unsigned int msDelay, const string &color)
        {
            // iterate through each character in the text
            for (const char c : text)
            {
                // print the character with the specified color and reset the color after each character
                cout << color << c << UIConstants::RESET;

                // pause for the specified delay to simulate typing effect
                std::this_thread::sleep_for(std::chrono::milliseconds(msDelay));
            }
        }
}

