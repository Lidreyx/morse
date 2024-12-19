#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "MQTTClient.h"
#include "mqtt.h"
#define RET 0

// Function prototype for decoding messages
void decode(char *mess);

// Global MQTT client object
MQTTClient client;

// Callback function triggered when a message is received
int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    if (message) {
        printf("Message arrived\n");
        printf("  -> topic: %s\n", topicName); // Print the topic name
        printf("  -> message: ");
        printf("%s\n", (char*)message->payload); // Print the message payload
        decode(message->payload); // Decode the received message
    }
    MQTTClient_freeMessage(&message); // Free the memory allocated for the message
    MQTTClient_free(topicName); // Free the memory allocated for the topic name
    return 1;
}

// Callback function triggered when the connection to the MQTT broker is lost
void connlost(void *context, char *cause)
{
    printf("Connection lost\n");
    if (cause) printf("Reason is : %s\n", cause); // Print the reason for disconnection
    MQTTDisconnect(); // Disconnect the client
    MQTTBegin(); // Reinitialize the connection
}

// Function to subscribe to a specific topic
void MQTTSubscribe(const char* topic)
{
    printf("Subscribing to topic <%s> for client <%s> using QoS%d\n\n", 
        topic, CLIENTID, QOS); // Print subscription details
    MQTTClient_subscribe(client, topic, QOS); // Subscribe to the topic with specified QoS
}

// Function to publish a message to a specific topic
void MQTTPublish(const char* topic, char* message)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer; // Initialize a message object
    MQTTClient_deliveryToken token; // Delivery token for tracking the message

    pubmsg.payload = message; // Set the message payload
    pubmsg.payloadlen = (int)strlen(message); // Set the payload length
    pubmsg.qos = QOS; // Set the quality of service (QoS) level
    pubmsg.retained = RET; // Set the retained flag

    MQTTClient_publishMessage(client, topic, &pubmsg, &token); // Publish the message
    printf("Waiting for publication of message: %s\n\r", message); // Print publication details
    printf("  -> topic: %s  QOS: %d RET: %d for client: %s\n\r", topic, QOS, RET, CLIENTID);

    int rc = MQTTClient_waitForCompletion(client, token, 1000); // Wait for message delivery to complete
    printf("Message with delivery token %d delivered\n", token); // Confirm message delivery
}

// Function to disconnect the MQTT client
void MQTTDisconnect()
{
    MQTTClient_disconnect(client, TIMEOUT); // Disconnect the client with a timeout
    MQTTClient_destroy(&client); // Destroy the client object
}

// Function to initialize the MQTT client and connect to the broker
void MQTTBegin()
{
    int rc = -1;
    printf("Initializing MQTT for <%s> broker\n", BROKER_ADDR); // Print initialization details
    MQTTClient_create(&client, BROKER_ADDR, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL); // Create the client
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, NULL); // Set callback functions

    // Attempt to connect to the broker
    while ((rc = MQTTClient_connect(client)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc); // Print error if connection fails
        sleep(TIMEOUT / 1000); // Wait before retrying
    }
    printf("Connection established\n"); // Confirm successful connection
}
