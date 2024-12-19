#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype> // for std::tolower

// Function declaration
std::string EnglishToMorse(const std::string& text);

int main() {
    std::string text = "bonjour"; // exemple of text
    std::string morseCode = EnglishToMorse(text);  // call of the function

    std::cout << "Morse Code: " << morseCode << std::endl;
    std::cout << "English Text: " << text << std::endl;

    return 0;
}

// Function definition for converting English to Morse
std::string EnglishToMorse(const std::string& text) {
    std::string morseCode;
    
     // Simple example of letter mapping
    std::map<char, std::string> morseCodeMap = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
        {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"},
        {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"},
        {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
        {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"},
        {'z', "--.."},
        {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, 
        {'8', "---.."}, {'9', "----."}
    };
    
    // Convert every character to Morse code
    for (char c : text) {
        c = std::tolower(c);  // Convert uppercase letter to lowercase
        if (c == ' ') {
            morseCode += "/ ";  // space between words
        } else {
            // Check if the character exists in the translation map
            if (morseCodeMap.find(c) != morseCodeMap.end()) {
                morseCode += morseCodeMap[c] + " ";  // add the morse code of the letter
            } else {
                
                morseCode += "? ";  // add "?" for unknown caracter
            }
        }
    }

    return morseCode;
}
