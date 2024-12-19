#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define LED_PIN 7  // GPIO 7 pour cet exemple

// Fonction pour envoyer un signal Morse à la LED
void MorseToLed(const char* morse) {
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '-') {  // Si c'est un tiret, signal long
            digitalWrite(LED_PIN, HIGH);  // Allume la LED
            delay(1000);  // 1 seconde
            digitalWrite(LED_PIN, LOW);  // Éteint la LED
            delay(500);  // Pause de 500ms
        } else if (morse[i] == '.') {  // Si c'est un point, signal court
            digitalWrite(LED_PIN, HIGH);  // Allume la LED
            delay(500);  // 500ms
            digitalWrite(LED_PIN, LOW);  // Éteint la LED
            delay(500);  // Pause de 500ms
        } else if (morse[i] == '/') {  // Espace entre les lettres
            digitalWrite(LED_PIN, LOW);  // Éteint la LED
            delay(1000);  // Pause de 1 seconde
        }
    }
}

