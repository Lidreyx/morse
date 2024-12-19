#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define LED_PIN 7  // GPIO 7 pour cet exemple

// Function to change morse into led signal
void MorseToLed(const char* morse) {
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '-') {  // if dash, long signal
            digitalWrite(LED_PIN, HIGH);  // turn on  LED
            delay(1000);  // 1 seconde
            digitalWrite(LED_PIN, LOW);  // turn off LED
            delay(500);  // delay 500ms
        } else if (morse[i] == '.') {  // if dot, long signal
            digitalWrite(LED_PIN, HIGH);  // turn on LED
            delay(500);  // 500ms
            digitalWrite(LED_PIN, LOW);  // turn off LED
            delay(500);  // Pause de 500ms
        } else if (morse[i] == '/') {  // space between word
            digitalWrite(LED_PIN, LOW);  // turn off LED
            delay(1000);  // 1s delay if space
        }
    }
}

