#include "../../include/ui/UI.hpp"
#include "../../include/Defines.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::string;

namespace UI {
    void typeText(const string &text, unsigned int msDelay, const string &color)
    {
        // iterate through each character in the text
        for (const char c : text)
        {
            // print the character with the specified color and reset the color after each character
            cout << color << c << Constants::RESET;

            // pause for the specified delay to simulate typing effect
            std::this_thread::sleep_for(std::chrono::milliseconds(msDelay));
        }
    }
    void loadingBar(const string &loadingName, unsigned int totalDurationMs, int steps)
    {
        // calculate the delay between steps
        // the total duration is divided by the number of steps
        // this will give us the delay between each step
        unsigned int delay = totalDurationMs / steps;

        // start the loading bar
        // print the loading bar with the number of steps
        // the loading bar will be displayed as a progress bar
        cout << Constants::RED << loadingName << ": [" << Constants::RESET;

        // print the loading bar
        for (int i = 0; i < steps; i++)
        {
            cout << Constants::RED << "=" << Constants::RESET;
        }

        // when the loading bar is completed, print the closing bracket
        cout << Constants::RED << "]" << Constants::RESET;

        // return the cursor to the beginning of the line
        // this will allow us to update the loading bar step by step as it progresses and completes
        cout << Constants::RED << "\r" << loadingName << ": [ " << Constants::RESET;

        // update the loading bar step by step
        // this will update the loading bar as it progresses
        for (int i = 0; i <= steps; i++)
        {
            // print the completed part of the bar
            for (int j = 0; j < steps; j++) 
            {
                // if the current step is less than the total number of steps then print the completed part of the bar in red background color 
                // otherwise print the completed part of the bar in red color
                if (j < i)
                    cout << Constants::RED_BACKGROUND << " " << Constants::RESET;
                else
                    cout << Constants::RED << "=" << Constants::RESET;
            }

            // print the percentage of the loading bar as it progresses step by step
            cout << Constants::RED << " ] " << (i * 100 / steps) << "%" << Constants::RESET;
            // sleep for the delay between each step to update the loading bar step by step as it progresses
            std::this_thread::sleep_for(std::chrono::milliseconds(delay)); 
            // move the cursor back to the beginning of the bar 
            // this ensures that the loading bar is updated in place without creating a new line
            cout << Constants::RED << "\r" << loadingName << ": [ " << Constants::RESET; // return the cursor to the beginning of the bar
        }

        // print the final loading bar
        cout << Constants::RED << "\r" << loadingName << ": [ " << Constants::RESET;

        // print the final loading bar with the percentage of 100%
        for (int i = 0; i < steps; i++)  //
        {
            cout << Constants::GREEN_BACKGROUND << " " << Constants::RESET;
        }
        cout << Constants::RED << " ]" << Constants::RESET << Constants::GREEN << " 100%" << Constants::RESET << std::endl;
    }
    void joesCatDisplay()
    {
    cout << "\033[4A";

        cout << Constants::RED << "\033[72G" << "        |\\      _,,,---,,_" << Constants::RESET << std::endl;
        cout << Constants::RED << "\033[72G" << "  ZZZzz /,`.-'`'    -.  ;-;;,_" << Constants::RESET << std::endl;
        cout << Constants::RED << "\033[72G" << "       |,4-  ) )-,_. ,\\ (  `'-'" << Constants::RESET << std::endl;
        cout << Constants::RED << "\033[72G" << "      '---''(_/--'  `-'\\_)" << Constants::RESET << std::endl;
    }
    void notchDisplay()
    {
        cout << "[" << Constants::CYAN << "-" << Constants::RESET << "] ";
    }
    void logoDisplay()
    {
        cout << Constants::RED << R"(
        ______                       __                             ______                                
        /      \                     /  |                           /      \                               
        /$$$$$$  | __    __   ______  $$ |____    ______    ______  /$$$$$$ 	 |  ______    ______    ______  
        $$ |  $$/ /  |  /  | /      \ $$      \  /      \  /      \ $$ \__$$/  /      \  /      \  /      \ 
        $$ |      $$ |  $$ |/$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |$$      \  $$$$$$  |/$$$$$$  | $$$$$$  |
        $$ |   __ $$ |  $$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/  $$$$$$  | /    $$ |$$ |  $$ | /    $$ |
        $$ \__/  |$$ \__$$ |$$ |__$$ |$$ |  $$ |$$$$$$$$/ $$ |      /  \__$$ |/$$$$$$$ |$$ \__$$ |/$$$$$$$ |
        $$    $$/ $$    $$ |$$    $$/ $$ |  $$ |$$       |$$ |      $$    $$/ $$    $$ |$$    $$ |$$    $$ |
        $$$$$$/   $$$$$$$ |$$$$$$$/  $$/   $$/  $$$$$$$/ $$/        $$$$$$/   $$$$$$$/  $$$$$$$ | $$$$$$$/ 
                /  \__$$ |$$ |                                                        /  \__$$ |          
                $$    $$/ $$ |                                                        $$    $$/           
                $$$$$$/  $$/                                                          $$$$$$/            
                )"
            << Constants::RESET << std::endl;
    }
    void introDisplay()
    {
        notchDisplay(); typeText("Welcome to CypherSaga, this is a program made by the group of Bologa (The Chess God).", 10, Constants::GREEN); cout << std::endl;
        notchDisplay(); typeText("This program is a simple encryption and decryption program that uses a 3x3 matrix.", 10, Constants::GREEN); cout << std::endl;
        notchDisplay(); typeText("The program will ask you to input a message and a key.", 10, Constants::GREEN); cout << std::endl;
        notchDisplay(); typeText("The key must be a 4 digit number.", 10, Constants::GREEN); cout << std::endl;
        notchDisplay(); typeText("The program will then encrypt the message using the key and display the encrypted message.", 10, Constants::GREEN); cout << std::endl;
        notchDisplay(); typeText("The program will also decrypt the message using the key and display the decrypted message.", 10, Constants::GREEN); cout << std::endl;
        notchDisplay(); typeText("Enjoy!", 10, Constants::GREEN); cout << std::endl;
    }
    void breakDisplay(int n)
    {
        cout << "|";
        for (int i = 0; i <= n; i++)
        {
            cout << Constants::RED << "==" << Constants::RESET;
        }
        cout << "|";
        cout << std::endl;
    }
    void outputDisplay(const string &text)
    {
        cout << Constants::CYAN << text << Constants::RESET << std::endl;
    }
    void optionDisplay()
    {  

        breakDisplay(50);
        cout << std::endl;
        string messageMenu = "Choose 1 if you want to encrypt your message, 2 if you want to decrypt, or 3 if you want to exit";
        notchDisplay();
        typeText(messageMenu, 5, Constants::RED);
        cout << std::endl;
        cout << "[" << Constants::RED << "1" << Constants::RESET << "]" << " Encryptor" << std::endl;
        cout << "[" << Constants::RED << "2" << Constants::RESET << "]" << " Decryptor" << std::endl;
        cout << "[" << Constants::RED << "3" << Constants::RESET << "]" << " Exit" << std::endl;

        cout << std::endl;
    }
    void invalidDisplay(const string &text)
    {
        cout << "[" << Constants::RED << "x" << Constants::RESET << "]" << " " << text << std::endl;
    }

    // this function will display the names of the members of the group
    // it will display the name of the member and their description
    void memberDisplay(const string& name, const string& desc) {

        typeText(name, 5, Constants::RED);
        typeText(" - ", 5, Constants::RED);
        typeText(desc, 5, Constants::CYAN);
        cout << std::endl;
    }


    // this function will display the exit message
    void exitDisplay()
    {
        cout << std::endl;

        // cout << "[" << CYAN << "***" << RESET << "] ";
        // cout << RED << "Developed by the 4 Top G's " << RESET;
        // cout << "[" << CYAN << "***" << RESET << "] ";
        typeText("[", 5, Constants::RESET);
        typeText("***", 5, Constants::CYAN);
        typeText("]", 5, Constants::RESET);

        typeText(" Developed by the 5 Top G's ", 5, Constants::RED);

        typeText("[", 5, Constants::RESET);
        typeText("***", 5, Constants::CYAN);
        typeText("]", 5, Constants::RESET);
        

        cout << std::endl;
        cout << std::endl;

        memberDisplay("Bologa", "The Leader, Chess God, Best Programmer Perk, Logic boy, 1v1, EZ");
        memberDisplay("Villacorta", "The Designer, UI/UX Boi, IDK, Yeah");
        memberDisplay("Recopelacion", "Roblox Studio God, Best Programmer Perk, Java Hater");
        memberDisplay("Herrero", "Oldest, Ain't playing, Speaks HTML CSS JS for fun");
        memberDisplay("Paul", "The Best Writer, Poet, Linear Algebra");

        joesCatDisplay();
        
        cout << std::endl;

        notchDisplay();
        typeText("Thank you for using our program :)", 10, Constants::RED);

        cout << std::endl;

        breakDisplay(50);
        
        
    }

    void encodeInputAndValidation(string &message) {
        encodeInput:
            notchDisplay();
            typeText("Enter encoded message: ", 5, Constants::RED);
            getline(std::cin, message);

            if(message.empty()) {
                invalidDisplay("Input must not be empty");
                goto encodeInput;
            }
            if (!isdigit(message.at(0)) && int(message.at(0)) != Constants::ASCIIForHyphen) // this ensures that it excludes the "-" which is 45 in ASCII as invalid
            {
                invalidDisplay("Input must be integers");
                goto encodeInput;
            }
    }
    
    void keyInputAndValidation(string &key) {
        keyInput:
            notchDisplay();
            typeText("Enter key: ", 5, Constants::RED);
            getline(std::cin, key);
            if(key.empty()) 
            {
                invalidDisplay("Input must not be empty");
                goto keyInput;
            }

            if(!isdigit(key.at(0)) && int(key.at(0)) != Constants::ASCIIForHyphen) 
            {
                invalidDisplay("Input must be integers");
                goto keyInput;
            }
            if(key.length() < 9) 
            {
                invalidDisplay("Input must not be less than to 9");
                goto keyInput;
            }
            if(key.length() > 9) {
                invalidDisplay("Input must not exceed to 9");
                goto keyInput;
            }

    }
    void sentenceInputAndValidation(string &sentence) {
        stringInput:
            notchDisplay();
            typeText("Enter a string of characters you want to encrypt: ", 5, Constants::RED);
            getline(std::cin, sentence);

            if(sentence.empty())
            {
                invalidDisplay("Input must not be empty");
                goto stringInput;
            }
    }

}

