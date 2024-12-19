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
    pinMode(LED_PIN, OUTPUT);  // Definition of GPIO as an output

    MQTTBegin ();
    MQTTSubscribe (TOPIC);
    while(1) {
        while (digitalRead(btn)==1);
        MQTTPublish (TOPIC, "Message à messager");
        while(digitalRead(btn)==0);
    };
    MQTTDisconnect()

    // callback to ascii_to_morse
    std::cout << "Code Morse: ";
    ascii_to_morse(argv[], printMorse);
    std::cout << std::endl;
    MorseToLed(morseCode);  // call morseCode to print the morse message

}

    return 0;
}


