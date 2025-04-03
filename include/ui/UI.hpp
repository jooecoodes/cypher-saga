#pragma once

#include "../../include/Defines.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using std::string;

namespace UI {
    void typeText(const string &text, unsigned int msDelay, const string &color);
    void loadingBar(const string &loadingName, unsigned int totalDurationMs, int steps);
    void joesCatDisplay();
    void notchDisplay();
    void logoDisplay();
    void introDisplay();
    void breakDisplay(int n);
    void outputDisplay(const string &text);
    void optionDisplay();
    void invalidDisplay(const string &text);
    void memberDisplay(const string& name, const string& desc);
    void exitDisplay();
    void encodeInputAndValidation(string &message);
    void keyInputAndValidation(string &key);
    void sentenceInputAndValidation(string &sentence);
    
}