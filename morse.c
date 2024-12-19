#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype> // for std::tolower

// function initiliazing
std::string EnglishToMorse(const std::string& text);

int main() {
    std::string text = "bonjour"; // exemple of text
    std::string morseCode = EnglishToMorse(text);  // call of the function

    std::cout << "Morse Code: " << morseCode << std::endl;
    std::cout << "English Text: " << text << std::endl;

    return 0;
}

// Définition de la fonction pour convertir l'anglais en morse
std::string EnglishToMorse(const std::string& text) {
    std::string morseCode;
    
    // Exemple simple de correspondance des lettres
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
    
    // turn every caracter into morse code
    for (char c : text) {
        c = std::tolower(c);  // convert maj letter into lowercase letter
        if (c == ' ') {
            morseCode += "/ ";  // space between word
        } else {
            // check if the caracter is on the traduction map
            if (morseCodeMap.find(c) != morseCodeMap.end()) {
                morseCode += morseCodeMap[c] + " ";  // add the morse code of every letter
            } else {
                
                morseCode += "? ";  // add a "?" if unknown caracter
            }
        }
    }

    return morseCode;
}
