#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include "morse.c"
#include "mqtt.c"
#include "sleep.c"
#include "led.c"
#define led 0
#define btn 1


int main(int argc, char* argv[]){
    wiringPiSetup();
    pinMode(led,OUTPUT);
    pinMode(btn,INPUT);
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

    return 0;
}


on_morse_ev(enum){
    void decode(char *mess)
{
	if (*mess=='_') {
						digitalWrite(led,HIGH);
						printf("LED allumee\n\r");
					  }
        else 		 {
						digitalWrite(led,HIGH);
						sleep(500);
						printf("LED clignotante\n\r");
						digitalWrite(led,LOW)
					  }
}

}
