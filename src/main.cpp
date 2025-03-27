#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <string>
#include <cmath>
#include<Windows.h>


#include <chrono>
#include <thread>

using namespace std;

// back end global constants
constexpr int ASCIIForSpace = 32;
constexpr int ASCIIForZero = 48;
constexpr int ASCIIForBackTick = 96;
constexpr int ASCIIForHyphen = 45;

// front end global constants
const string  RED = "\033[1;31m";
const string  GREEN = "\033[1;32m";
const string  CYAN = "\033[1;36m";
const string  MAGENTA = "\033[1;33m";
const string  RESET = "\033[0m";

const string  RED_BACKGROUND = "\x1b[41m";
const string  GREEN_BACKGROUND = "\x1b[42m";

// fucntions back end side
inline string myTo_string(int num);
inline int to_int(const string &strValue);
void encryptor();
void decryptor();

// functions front end side
inline void typeText(const string &text, unsigned int msDelay, const string &color);
inline void loadingBar(const string &loadingName, unsigned int totalDurationMs, int steps);
inline void joesCatDisplay();
inline void notchDisplay();
inline void logoDisplay();
inline void introDisplay();
inline void optionDisplay();
inline void outputDisplay(const string &text);
inline void breakDisplay(int n);
inline void invalidDisplay(const string &text);
inline void exitDisplay();

// helper functions
inline void encodeInputAndValidation(string &message);
inline void keyInputAndValidation(string &key);
inline void sentenceInputAndValidation(string &sentence);



void maxsc()
{
    HWND Hwnd = GetForegroundWindow();
    ShowWindow(Hwnd, SW_MAXIMIZE);
}
/*void fullsc()
{
    HWND Hwnd = GetForegroundWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);
    SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(Hwnd,HWND_TOP,0,0,x,y,0);

}*/
int main()
{
	maxsc();
    loadingBar("Loading", 1000, 90);
    breakDisplay(50);
    logoDisplay();
    breakDisplay(50);
    introDisplay();
    breakDisplay(50);

    string choice;
    bool sentinel;
    sentinel = true;
    // loop until the user chooses to exit the program
    while (sentinel)
    {
        optionDisplay();
        getline(cin, choice);
        if (choice.empty() || !isdigit(choice.at(0)))
        {
            invalidDisplay("Invalid Selection");
        }
        else
        {
            if (to_int(choice) == 1)
            {
                encryptor();
            }
            else if (to_int(choice) == 2)
            {
                decryptor();
            }
            else if (to_int(choice) == 3)
            {
                exitDisplay();
                sentinel = false;
            }
            else
            {
                invalidDisplay("Invalid Selection");
            }
        }
    }
    {
        optionDisplay();
        getline(cin, choice);
        if (choice.empty() || !isdigit(choice.at(0)))
        {
            invalidDisplay("Invalid Selection");
        }
        else
        {
            if (to_int(choice) == 1)
            {
                encryptor();
            }
            else if (to_int(choice) == 2)
            {
                decryptor();
            }
            else if (to_int(choice) == 3)
            {
                exitDisplay();
                sentinel = false;
            }
            else
            {
                invalidDisplay("Invalid Selection");
            }
        }
    }

    return 0;
}

//back end functions
inline string myTo_string(int num)
{
    ostringstream oss; // create a string stream object.
    oss << num; // insert the integer into the string stream. 
    return oss.str(); // return the string stream as a string.
}

inline int to_int(const string &strValue)
{
    istringstream iss(strValue); // create a string stream from the input string.
    int intValue = 0;  // initialize an integer to store the converted value.
    iss >> intValue; // extract the integer value from the string stream.
    return intValue; // return the converted integer.
}

void encryptor()

{
    srand((unsigned int)time(NULL));
    bool lever = false, lever2 = false;
    int a, b, c, d, e, f, g, h, i, fchar, schar, tchar, fin, x = 0;
    string encrypt, sentence;
    // generate random values for the matrix that will be used to encrypt the message 
    a = rand() % 10;
    b = rand() % 10;
    c = rand() % 10;
    d = rand() % 10;
    e = rand() % 10;
    f = rand() % 10;
    g = rand() % 10;
    h = rand() % 10;
    i = rand() % 10;
    // if the determinant of the matrix is 0, generate new random values for the matrix because the matrix is singular and cannot be inverted or doesn't have an inverse 
    while(a*d - b*d == 0){
        a = rand() % 10;
        b = rand() % 10;
        c = rand() % 10;
        d = rand() % 10;
        e = rand() % 10;
	    f = rand() % 10;
	    g = rand() % 10;
	    h = rand() % 10;
	    i = rand() % 10;
    }

    // input and validate the sentence to be encrypted
    sentenceInputAndValidation(sentence);

    // ensure the sentence length is odd and greater than 1 by appending spaces if necessary because the encryption works in chunks of 3 characters, otherwise the encryption will not work because the matrix is 3x3 and the encryption works in chunks of 3 characters, so that is why we want the sentence length to be odd or greater than 1
    while (sentence.length() % 2 == 0 || sentence.length() == 1)
    {
        sentence.append(" ");
    }

    // loop through the sentence in chunks of 3 characters because the encryption works in chunks of 3 characters
    while (sentence.length() + 1 > x)
    {
        // handle the first character of the chunk if it is a space character then subtract the ASCII value of space from the character so that the character starts from 0
        // and we subtract ASCII for backtick, why do we subtract ASCII for backtick you ask? well, because we want to start from 0 and not from 96 since ASCII for backtick is 96 and so that we can easily reverse the process during decryption by adding the same amount to the result. generally, we just want to start from 0 and not from 96.
        if (int(sentence[x]) == ASCIIForSpace)
        {
            fchar = int(sentence[x]) - ASCIIForSpace;
            schar = int(sentence[x + 1]) - ASCIIForBackTick;
            tchar = int(sentence[x + 2]) - ASCIIForBackTick;
            fin = fchar * a + schar * d + tchar * g; // calculate it by multiplying the first character by the first element of the matrix, the second character by the second element of the matrix, and the third character by the third element of the matrix
        }
        else if (int(sentence[x + 1]) == ASCIIForSpace)
        {
            fchar = int(sentence[x]) - ASCIIForBackTick; 
            schar = int(sentence[x + 1]) - ASCIIForSpace; 
            tchar = int(sentence[x + 2]) - ASCIIForBackTick;
            fin = fchar * a + schar * d + tchar * g;
        }
        else
        {
            fchar = int(sentence[x]) - ASCIIForBackTick;
            schar = int(sentence[x + 1]) - ASCIIForBackTick;
            tchar = int(sentence[x + 2]) - ASCIIForBackTick;
            fin = fchar * a + schar * d + tchar * g;
        }
        // append the result of the first character transformation to the encrypted message and so we convert the integer to a string and append it to the encrypted variable string and add a space to separate the encrypted characters
        encrypt.append(myTo_string(fin) + " ");
        lever = true;

        // handle the second character of the chunk 
        // while (lever)
        // {
            if (int(sentence[x]) == ASCIIForSpace)
            {
                fchar = int(sentence[x]) - ASCIIForSpace;
                schar = int(sentence[x + 1]) - ASCIIForBackTick;
                tchar = int(sentence[x + 2]) - ASCIIForBackTick;
                fin = fchar * b + schar * e + tchar * h;
            }
            else if (int(sentence[x + 1]) == ASCIIForSpace)
            {
                fchar = int(sentence[x]) - ASCIIForBackTick;
                schar = int(sentence[x + 1]) - ASCIIForSpace;
                tchar = int(sentence[x + 2]) - ASCIIForBackTick;
                fin = fchar * b + schar * e + tchar * h;
            }
            else
            {
                fchar = int(sentence[x]) - ASCIIForBackTick;
                schar = int(sentence[x + 1]) - ASCIIForBackTick;
                tchar = int(sentence[x + 2]) - ASCIIForBackTick;
                fin = fchar * b + schar * e + tchar * h;
            }
            // append the result of the second character transformation to the encrypted message
            encrypt.append(myTo_string(fin) + " ");
            lever = false;
            lever2 = true;

            // handle the third character of the chunk
            // while (lever2)
            // {
                if (int(sentence[x]) == ASCIIForSpace)
                {
                    fchar = int(sentence[x]) - ASCIIForSpace;
                    schar = int(sentence[x + 1]) - ASCIIForBackTick;
                    tchar = int(sentence[x + 2]) - ASCIIForBackTick;
                    fin = fchar * c + schar * f + tchar * i;
                }
                else if (int(sentence[x + 1]) == ASCIIForSpace)
                {
                    fchar = int(sentence[x]) - ASCIIForBackTick;
                    schar = int(sentence[x + 1]) - ASCIIForSpace;
                    tchar = int(sentence[x + 2]) - ASCIIForBackTick;
                    fin = fchar * c + schar * f + tchar * i;
                }
                else
                {
                    fchar = int(sentence[x]) - ASCIIForBackTick;
                    schar = int(sentence[x + 1]) - ASCIIForBackTick;
                    tchar = int(sentence[x + 2]) - ASCIIForBackTick;
                    fin = fchar * c + schar * f + tchar * i;
                }
                // append the result of the third character transformation to the encrypted message
                encrypt.append(myTo_string(fin) + " ");
                lever2 = false;
            // }
        // }
        // move to the next chunk of 3 characters
        x += 3;
    }

    loadingBar("Encrypting", 2000, 90);
    notchDisplay();
    typeText("Your randomly generated key values are: ", 5, GREEN);

    // combine the randomly generated key values into a single string
    // start with a space for formatting
    string combinedTogetherValue = " " + myTo_string(c);

    // append each key value to the string in a specific order 
    combinedTogetherValue += myTo_string(a);
    combinedTogetherValue += myTo_string(b);
    combinedTogetherValue += myTo_string(d);
    combinedTogetherValue += myTo_string(f);
    combinedTogetherValue += myTo_string(e);
    combinedTogetherValue += myTo_string(g);
    combinedTogetherValue += myTo_string(i);
    combinedTogetherValue += myTo_string(h);

    // display the combined key values as output
    outputDisplay(combinedTogetherValue);

    notchDisplay();
    typeText("Your encrypted message is: ", 5, GREEN);
    outputDisplay(encrypt);
}

void decryptor()
{
    string key, message, fchar1, fchar2, fchar3, decrypted, messageHandler;
    bool valid;
    double calc, calc1, calc2, m11, m12, m13, m21, m22, m23, m31, m32, m33, det, c11,c12,c13,c21,c22,c23,c31,c32,c33;

    encodeInputAndValidation(message);
    keyInputAndValidation(key);

    // extract matrix elements from the key string
    m11 = key[1] - ASCIIForZero; // first row, first column
    m12 = key[2] - ASCIIForZero; // first row, second column
    m13 = key[0] - ASCIIForZero; // first row, third column
    m21 = key[3] - ASCIIForZero; // second row, first column
    m22 = key[5] - ASCIIForZero; // second row, second column
    m23 = key[4] - ASCIIForZero; // second row, third column
    m31 = key[6] - ASCIIForZero; // third row, first column
    m32 = key[8] - ASCIIForZero; // third row, second column
    m33 = key[7] - ASCIIForZero; // third row, third column

    // calculate the determinant of the 3x3 matrix using cofactor expansion
    det = m11 * (m22 * m33 - m23 * m32) 
        - m12 * (m21 * m33 - m23 * m31) 
        + m13 * (m21 * m32 - m22 * m31);

    // compute the cofactors and divide by the determinant to get the inverse matrix
    c11 = 1 / det * ((1) * (m22 * m33 - m23 * m32)); // cofactor for (1,1)
    c12 = 1 / det * ((-1) * (m21 * m33 - m23 * m31)); // cofactor for (1,2)
    c13 = 1 / det * ((1) * (m21 * m32 - m22 * m31)); // cofactor for (1,3)
    c21 = 1 / det * ((-1) * (m12 * m33 - m13 * m32)); // cofactor for (2,1)
    c22 = 1 / det * ((1) * (m11 * m33 - m13 * m31)); // cofactor for (2,2)
    c23 = 1 / det * ((-1) * (m11 * m32 - m12 * m31)); // cofactor for (2,3)
    c31 = 1 / det * ((1) * (m12 * m23 - m13 * m22)); // cofactor for (3,1)
    c32 = 1 / det * ((-1) * (m11 * m23 - m13 * m21)); // cofactor for (3,2)
    c33 = 1 / det * ((1) * (m11 * m22 - m12 * m21)); // cofactor for (3,3)

    
    // create a stringstream object to parse or go to each the encrypted message because it is separated by a space
    stringstream ss(message);

    // loop through the encrypted message, extracting three values at a time 
    while (ss >> fchar1 >> fchar2 >> fchar3)
    {

        // `calc` is calculated by converting `fchar1`, `fchar2`, and `fchar3` to integers,
        // multiplying them by  `c11`, `c12`, and `c13` respectively, and adding ASCIIForBackTick because it was subtracted during encryption by the same amount.
        calc = to_int(fchar1) * (c11) + to_int(fchar2) * (c12) + to_int(fchar3) * (c13) + ASCIIForBackTick;


        // `calc1` is calculated similarly, but uses  `c21`, `c22`, and `c23`.
        calc1 = to_int(fchar1) * (c21) + to_int(fchar2) * (c22) + to_int(fchar3) * (c23) + ASCIIForBackTick;

        // `calc2` is calculated similarly, but uses  `c31`, `c32`, and `c33`.
        calc2 = to_int(fchar1) * (c31) + to_int(fchar2) * (c32) + to_int(fchar3) * (c33) + ASCIIForBackTick;

        // check if the calculated values correspond to a space character
        // we round the calc, calc1, and calc2 because the result of the calculation is a double and we need to convert it to an integer to compare it with the ASCII value of the backtick character which is 96 in ASCII table. if it is equal to the backtick character, we replace it with a space character which is 32 in ASCII table because the backtick character was subtracted during encryption by the same amount which is 96. and we want to reverse the process during decryption by adding the same amount to the result. and then we append the decrypted characters to the messageHandler string var which will be displayed at the end of the decryption process.
        if (round(calc) == ASCIIForBackTick) 
        {
            calc = ASCIIForSpace; // replace with space if it matches the backtick offset since it was subtracted during encryption by the same amount which is 96.
        }
        else if (round(calc1) == ASCIIForBackTick)
        {
            calc1 = ASCIIForSpace; // replace with space if it matches the backtick offset since it was subtracted during encryption by the same amount which is 96.
        }	
        else if (round(calc2) == ASCIIForBackTick)
        {
            calc2 = ASCIIForSpace; // replace with space if it matches the backtick offset since it was subtracted during encryption by the same amount which is 96.
        }

        // append the decrypted characters to the messageHandler string var 
        messageHandler.push_back(char(round(calc)));
        messageHandler.push_back(round(calc1));
        messageHandler.push_back(round(calc2));
    }

    // display a loading bar to simulate decryption progress
    loadingBar("Decrypting", 2000, 90);

    // display the decrypted message
    notchDisplay();
    typeText("The message is: ", 5, RED);
    outputDisplay(messageHandler);
}

// front end functions
// all of these crazy thingy properties and methods like flush, this_thread, chrono are from the std namespace :)
// this function simulates typing text character by character with a delay and color
inline void typeText(const string &text, unsigned int msDelay, const string &color)
{
    // iterate through each character in the text
    for (const char c : text)
    {
        // print the character with the specified color and reset the color after each character
        cout << color << c << RESET;

        // pause for the specified delay to simulate typing effect
        this_thread::sleep_for(chrono::milliseconds(msDelay));
    }
}

inline void loadingBar(const string &loadingName, unsigned int totalDurationMs, int steps)
{
    // calculate the delay between steps
    // the total duration is divided by the number of steps
    // this will give us the delay between each step
    unsigned int delay = totalDurationMs / steps;

    // start the loading bar
    // print the loading bar with the number of steps
    // the loading bar will be displayed as a progress bar
    cout << RED << loadingName << ": [" << RESET;

    // print the loading bar
    for (int i = 0; i < steps; i++)
    {
        cout << RED << "=" << RESET;
    }

    // when the loading bar is completed, print the closing bracket
    cout << RED << "]" << RESET;

    // return the cursor to the beginning of the line
    // this will allow us to update the loading bar step by step as it progresses and completes
    cout << RED << "\r" << loadingName << ": [ " << RESET;

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
                cout << RED_BACKGROUND << " " << RESET;
            else
                cout << RED << "=" << RESET;
        }

        // print the percentage of the loading bar as it progresses step by step
        cout << RED << " ] " << (i * 100 / steps) << "%" << RESET;
        // sleep for the delay between each step to update the loading bar step by step as it progresses
        this_thread::sleep_for(chrono::milliseconds(delay)); 
        // move the cursor back to the beginning of the bar 
        // this ensures that the loading bar is updated in place without creating a new line
        cout << RED << "\r" << loadingName << ": [ " << RESET; // return the cursor to the beginning of the bar
    }

    // print the final loading bar
    cout << RED << "\r" << loadingName << ": [ " << RESET;

    // print the final loading bar with the percentage of 100%
    for (int i = 0; i < steps; i++)  //
    {
        cout << GREEN_BACKGROUND << " " << RESET;
    }
    cout << RED << " ]" << RESET << GREEN << " 100%" << RESET << endl;
}

// this function will display the ascii art of the cat
inline void joesCatDisplay()
{
cout << "\033[4A";

    cout << RED << "\033[72G" << "        |\\      _,,,---,,_" << RESET << endl;
    cout << RED << "\033[72G" << "  ZZZzz /,`.-'`'    -.  ;-;;,_" << RESET << endl;
    cout << RED << "\033[72G" << "       |,4-  ) )-,_. ,\\ (  `'-'" << RESET << endl;
    cout << RED << "\033[72G" << "      '---''(_/--'  `-'\\_)" << RESET << endl;
}


// this function will display the notch [-] in cyan color 
inline void notchDisplay()
{
    cout << "[" << CYAN << "-" << RESET << "] ";
}


// this function will display the logo of the program
// it will display the logo in red color
// the logo is a simple ascii art of the program name
inline void logoDisplay()
{
    cout << RED << R"(
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
         << RESET << endl;
}


// this function will display the intro message in green color
inline void introDisplay()
{
    notchDisplay();
    typeText("Welcome to CypherSaga, this is a program made by the group of Bologa (The Chess God).", 10, GREEN);
    cout << endl;
    notchDisplay();
    typeText("This program is a simple encryption and decryption program that uses a 3x3 matrix.", 10, GREEN);
    cout << endl;
    notchDisplay();
    typeText("The program will ask you to input a message and a key.", 10, GREEN);
    cout << endl;
    notchDisplay();
    typeText("The key must be a 4 digit number.", 10, GREEN);
    cout << endl;
    notchDisplay();
    typeText("The program will then encrypt the message using the key and display the encrypted message.", 10, GREEN);
    cout << endl;
    notchDisplay();
    typeText("The program will also decrypt the message using the key and display the decrypted message.", 10, GREEN);
    cout << endl;
    notchDisplay();
    typeText("Enjoy!", 10, GREEN);
    cout << endl;
}

// this function will display the options for the user
// it will ask the user to choose if they want to encrypt, decrypt, or exit
// it will display the options in red color
inline void optionDisplay()
{  

    breakDisplay(50);
    cout << endl;
    string messageMenu = "Choose 1 if you want to encrypt your message, 2 if you want to decrypt, or 3 if you want to exit";
    notchDisplay();
    typeText(messageMenu, 5, RED);
    cout << endl;
    cout << "[" << RED << "1" << RESET << "]" << " Encryptor" << endl;
    cout << "[" << RED << "2" << RESET << "]" << " Decryptor" << endl;
    cout << "[" << RED << "3" << RESET << "]" << " Exit" << endl;

    cout << endl;
}


// this function will display the output message
// it will display the message in cyan color
inline void outputDisplay(const string &text)
{
    cout << CYAN << text << RESET << endl;
}

// this function will display a break line
// it will display a break line with a specific number of characters
inline void breakDisplay(int n)
{
    cout << "|";
    for (int i = 0; i <= n; i++)
    {
        cout << RED << "==" << RESET;
    }
    cout << "|";
    cout << endl;
}

// this function will display an error message
// it will display an error message in red color
inline void invalidDisplay(const string &text)
{
    cout << "[" << RED << "x" << RESET << "]" << " " << text << endl;
}

// this function will display the names of the members of the group
// it will display the name of the member and their description
inline void memberDisplay(const string& name, const string& desc) {

    typeText(name, 5, RED);
    typeText(" - ", 5, RED);
    typeText(desc, 5, CYAN);
    cout << endl;
}


// this function will display the exit message
inline void exitDisplay()
{
    cout << endl;

    // cout << "[" << CYAN << "***" << RESET << "] ";
    // cout << RED << "Developed by the 4 Top G's " << RESET;
    // cout << "[" << CYAN << "***" << RESET << "] ";
    typeText("[", 5, RESET);
    typeText("***", 5, CYAN);
    typeText("]", 5, RESET);

    typeText(" Developed by the 5 Top G's ", 5, RED);

    typeText("[", 5, RESET);
    typeText("***", 5, CYAN);
    typeText("]", 5, RESET);
    

    cout << endl;
    cout << endl;

    memberDisplay("Bologa", "The Leader, Chess God, Best Programmer Perk, Logic boy, 1v1, EZ");
    memberDisplay("Villacorta", "The Designer, UI/UX Boi, IDK, Yeah");
    memberDisplay("Recopelacion", "Roblox Studio God, Best Programmer Perk, Java Hater");
    memberDisplay("Herrero", "Oldest, Ain't playing, Speaks HTML CSS JS for fun");
    memberDisplay("Paul", "The Best Writer, Poet, Linear Algebra");

    joesCatDisplay();
    
    cout << endl;

    notchDisplay();
    typeText("Thank you for using our program :)", 10, RED);

    cout << endl;

    breakDisplay(50);
    
    
}

// helper functions 

// this functions serves as the input and validation for the message
// it will ask the user to input the message and validate it if it is empty, if it is an integer, and if it is not less than 9
// if the input is invalid, it will display an error message and ask the user to input again
inline void encodeInputAndValidation(string &message) {
    encodeInput:
        notchDisplay();
        typeText("Enter encoded message: ", 5, RED);
        getline(cin, message);

        if(message.empty()) {
            invalidDisplay("Input must not be empty");
            goto encodeInput;
        }
        if (!isdigit(message.at(0)) && int(message.at(0)) != ASCIIForHyphen) // this ensures that it excludes the "-" which is 45 in ASCII as invalid
        {
            invalidDisplay("Input must be integers");
            goto encodeInput;
        }
}

// this functions serves as the input and validation for the key
// it will ask the user to input the key and validate it if it is empty, if it is an integer, and if it is not less than 9
// if the input is invalid, it will display an error message and ask the user to input again
inline void keyInputAndValidation(string &key) {
    keyInput:
        notchDisplay();
        typeText("Enter key: ", 5, RED);
        getline(cin, key);
        if(key.empty()) 
        {
            invalidDisplay("Input must not be empty");
            goto keyInput;
        }

        if(!isdigit(key.at(0)) && int(key.at(0)) != ASCIIForHyphen) 
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

// this functions serves as the input and validation for the sentence
// it will ask the user to input the sentence and validate it if it is empty
// if the input is invalid, it will display an error message and ask the user to input again
inline void sentenceInputAndValidation(string &sentence) {
    stringInput:
        notchDisplay();
        typeText("Enter a string of characters you want to encrypt: ", 5, RED);
        getline(cin, sentence);

        if(sentence.empty())
        {
            invalidDisplay("Input must not be empty");
            goto stringInput;
        }
}

// end of joe's front-end function declaration
// disclaimer, please excuse my dear me for some grammatical errors here and there, but you get the idea anyways, thank you mwa bless and love :) sincerely, joe
