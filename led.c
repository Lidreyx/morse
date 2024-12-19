#include <Arduino.h>  // Pour utiliser les fonctions Arduino comme pinMode, digitalWrite, etc.

// Définition de la classe Led
class Led {
private:
    int pin;            // La broche à laquelle la LED est connectée
    const char* name;   // Le nom de la LED

public:
    // Constructeur pour initialiser la LED
    Led(int pin, const char* name) {
        this->pin = pin;
        this->name = name;
        pinMode(pin, OUTPUT);  // Configurer la broche comme une sortie
    }

    // Méthode pour allumer la LED pendant un court moment (500 ms)
    void lightShort() {
        digitalWrite(pin, HIGH);  // Allumer la LED
        delay(500);               // Attendre 500 ms
        digitalWrite(pin, LOW);   // Éteindre la LED
    }

    // Méthode pour allumer la LED pendant un long moment (2000 ms)
    void lightLong() {
        digitalWrite(pin, HIGH);  // Allumer la LED
        delay(2000);              // Attendre 2000 ms
        digitalWrite(pin, LOW);   // Éteindre la LED
    }
};

Led* led;  // Déclaration d'un pointeur vers une instance de la classe Led

void setup() {
    led = new Led(13, "LED");  // Créer une instance de la LED sur la broche 13
}

void loop() {
    led->lightShort();  // Allumer la LED pendant un court moment
    delay(1000);        // Attendre 1 seconde

    led->lightLong();   // Allumer la LED pendant un long moment
    delay(1000);        // Attendre 1 seconde
}
