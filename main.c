#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include "morse.c"
#include "mqtt.c"
#include "led.c"
#define led 0  // LED GPIO pin
#define btn 1  // Button GPIO pin

int main(int argc, char* argv[]) {
    wiringPiSetup();
    pinMode(LED_PIN, OUTPUT);  // Configure LED pin as output

    MQTTBegin();
    MQTTSubscribe(TOPIC);  // Subscribe to the MQTT topic

    while (1) {  
        while (digitalRead(btn) == 1);  // Wait for button press
        MQTTPublish(TOPIC, "Message à messager");  // Publish message on press
        while (digitalRead(btn) == 0);  // Wait for button release
    };

    MQTTDisconnect();

    if (argc > 1) {  // Convert and display Morse code if text is provided
        std::string morseCode = EnglishToMorse(argv[1]);
        std::cout << "Code Morse: " << morseCode << std::endl;
        MorseToLed(morseCode.c_str());
    } else {
        std::cout << "Aucun texte à convertir en morse." << std::endl;
    }

    return 0;
}

