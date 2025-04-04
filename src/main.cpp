#include "../include/core/Core.hpp"
#include "../include/ui/UI.hpp"
#include "../include/utils/Utils.hpp"

#include <iostream>
#include <sstream>

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

        int choiceInInt = Utils::toIntForChoice(choice);
        string sentenceToEncrypt, sentenceToDecrypt; 

        switch (choiceInInt)
        {
        case 1:
            Core::encryptionPart(sentenceToEncrypt);
            break;
        case 2:
            Core::decryptionPart();
            break;
        case 3:
            UI::exitDisplay();
            sentinel = false;
            break;
        default:
            UI::invalidDisplay("Invalid Selection");
            break;
        }
    }

    return 0;
}