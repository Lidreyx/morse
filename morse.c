#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype> // Pour std::tolower

// Déclaration de la fonction
std::string EnglishToMorse(const std::string& text);

int main() {
    std::string text = "bonjour"; // Exemple de texte en anglais
    std::string morseCode = EnglishToMorse(text);  // Appel à la fonction avec le bon nom

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
    
    // Convertir chaque caractère en morse
    for (char c : text) {
        c = std::tolower(c);  // Convertir en minuscule pour uniformiser
        if (c == ' ') {
            morseCode += "/ ";  // Séparateur entre les mots
        } else {
            // Vérifier si le caractère est dans la map
            if (morseCodeMap.find(c) != morseCodeMap.end()) {
                morseCode += morseCodeMap[c] + " ";  // Ajouter le code morse de chaque lettre
            } else {
                // Si le caractère n'est pas dans la map (par exemple une lettre invalide), l'ignorer
                morseCode += "? ";  // Ajouter un '?' pour les caractères inconnus
            }
        }
    }

    return morseCode;
}
