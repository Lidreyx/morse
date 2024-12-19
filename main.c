#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include "morse.c"
#include "mqtt.c"
#include "led.c"
#define led 0
#define btn 1


int main(int argc, char* argv[]){
    wiringPiSetup();
    pinMode(LED_PIN, OUTPUT);  // Définition du GPIO 7 en sortie

    MQTTBegin ();
    MQTTSubscribe (TOPIC);
    while(1) {
        while (digitalRead(btn)==1);
        MQTTPublish (TOPIC, "Message à messager");
        while(digitalRead(btn)==0);
    };
    MQTTDisconnect()

    // Appel à la fonction ascii_to_morse avec le callback
    std::cout << "Code Morse: ";
    ascii_to_morse(argv[], printMorse);
    std::cout << std::endl;
    // Exemple de message en code Morse
    MorseToLed(morseCode);  // Appel de la fonction pour envoyer le code Morse

}

    return 0;
}


