#include <iostream>
#include <unordered_map>
#include <string>
#include <stdio.h>

// Fonction pour initialiser la table de correspondance 
void initializeMorseCode(std::unordered_map<char, std::string>& morseCode) {
    morseCode['A'] = ".-";
    morseCode['B'] = "-...";
    morseCode['C'] = "-.-.";
    morseCode['D'] = "-..";
    morseCode['E'] = ".";
    morseCode['F'] = "..-.";
    morseCode['G'] = "--.";
    morseCode['H'] = "....";
    morseCode['I'] = "..";
    morseCode['J'] = ".---";
    morseCode['K'] = "-.-";
    morseCode['L'] = ".-..";
    morseCode['M'] = "--";
    morseCode['N'] = "-.";
    morseCode['O'] = "---";
    morseCode['P'] = ".--.";
    morseCode['Q'] = "--.-";
    morseCode['R'] = ".-.";
    morseCode['S'] = "...";
    morseCode['T'] = "-";
    morseCode['U'] = "..-";
    morseCode['V'] = "...-";
    morseCode['W'] = ".--";
    morseCode['X'] = "-..-";
    morseCode['Y'] = "-.--";
    morseCode['Z'] = "--..";

    morseCode['1'] = ".----";
    morseCode['2'] = "..---";
    morseCode['3'] = "...--";
    morseCode['4'] = "....-";
    morseCode['5'] = ".....";
    morseCode['6'] = "-....";
    morseCode['7'] = "--...";
    morseCode['8'] = "---..";
    morseCode['9'] = "----.";
    morseCode['0'] = "-----";

    // Ajouter des symboles de ponctuation et autres
    morseCode['.'] = ".-.-.-";
    morseCode[','] = "--..--";
    morseCode['?'] = "..--..";
    morseCode[' '] = "/";  // Séparateur entre les mots
}

//enum{MORSE_DOT, MORSE_DASH, MORSE_WSEP};
void ascii_to_morse(const char* text, void(morse_callback)(const std::string&)){
	
	std::unordered_map<char, std::string> morseCode;
	initializeMorseCode(morseCode);
	
	for (int i = 0; text[i] != '\0'; ++i) {
        char c = std::toupper(text[i]);  // Convertir en majuscule
        if (morseCode.find(c) != morseCode.end()) {
            // Appeler la fonction callback avec le code Morse
            morse_callback(morseCode[c]);
    	}
	}
}
