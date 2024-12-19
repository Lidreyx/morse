#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define LED_PIN 7  // Define the GPIO pin connected to the LED (GPIO 7 for this example)

// Function to convert Morse code to LED signals
// Each character in the Morse string will control the LED's state
void MorseToLed(const char* morse) {
    for (int i = 0; morse[i] != '\0'; i++) {  // Loop through each character in the Morse string
        if (morse[i] == '-') {  // Dash ('-') represents a long signal
            digitalWrite(LED_PIN, HIGH);  // Turn the LED on
            delay(1000);  // Keep the LED on for 1 second
            digitalWrite(LED_PIN, LOW);  // Turn the LED off
            delay(500);  // Pause for 500ms after the dash
        } else if (morse[i] == '.') {  // Dot ('.') represents a short signal
            digitalWrite(LED_PIN, HIGH);  // Turn the LED on
            delay(500);  // Keep the LED on for 500ms
            digitalWrite(LED_PIN, LOW);  // Turn the LED off
            delay(500);  // Pause for 500ms after the dot
        } else if (morse[i] == '/') {  // Slash ('/') represents a space between words
            digitalWrite(LED_PIN, LOW);  // Ensure the LED is off
            delay(1000);  // Wait for 1 second to indicate a space
        }
    }
}
