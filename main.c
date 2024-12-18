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
    MQTTDisconnect();
    return 0;
}

on_mqtt_msg(){
#J'ai pas compris à quoi ça sert cet endroit si mqtt est dans le int main
}

on_morse_ev(enum){
    void decode(char *mess)
{
	if (*mess=='1') {
						digitalWrite(led,HIGH);
						printf("LED allumee\n\r");
					  }
        else 		 {
						digitalWrite(led,LOW);
						printf("LED eteinte\n\r");
					  }
}

}
