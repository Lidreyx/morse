### EN COURS DE MODIFICATION, NE PAS TOUCHER
#incluse <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "MQTTClient.h"
#include "mqtt.h"
#define RET 0

void decode(char *mess);

MQTTClient client;

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    if(message) {
        printf("Message arrived\n");
        printf("  -> topic: %s\n", topicName);
        printf("  -> message: ");
        printf("%s\n", (char*)message->payload);
	decode(message->payload);
    }
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}
void connlost(void *context, char *cause)
{
    printf("Connection lost\n");
    if (cause) printf("Reason is : %s\n", cause);
    MQTTDisconnect();
    MQTTBegin();
}
void MQTTSubscribe(const char* topic)
{
    printf("Subscribing to topic <%s> for client <%s> using QoS%d\n\n", 
        topic, CLIENTID, QOS);
    MQTTClient_subscribe(client, topic, QOS);
}
void MQTTPublish(const char* topic, char* message)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    pubmsg.payload = message;
    pubmsg.payloadlen = (int)strlen(message);
    pubmsg.qos = QOS;
    pubmsg.retained = RET;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    printf("Waiting for publication of message: %s\n\r",message);
	  printf("  -> topic: %s  QOS: %d RET: %d for client: %s\n\r", topic, QOS,RET,CLIENTID);
    int rc = MQTTClient_waitForCompletion(client, token, 1000);
    printf("Message with delivery token %d delivered\n", token);
}
void MQTTDisconnect()
{
    MQTTClient_disconnect(client, TIMEOUT);
    MQTTClient_destroy(&client);
}
void MQTTBegin()
{
    int rc = -1;
    printf("Initializing MQTT for <%s> broker\n",BROKER_ADDR);
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.keepAliveInterval = KEEP_ALIVE;
    conn_opts.cleansession = 1;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;
    MQTTClient_create(&client, BROKER_ADDR, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, NULL);

    while ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        sleep(TIMEOUT / 1000); 
    }
	printf("Connexion etablished\n");
}
