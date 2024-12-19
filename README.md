Fonctionnalités principales :
Convertit un texte en code Morse grâce à un algorithme de correspondance des caractères.

Publication des messages en Morse via MQTT

Traduit le code Morse en signaux lumineux (points et traits) contrôlant une LED connectée à un Raspberry PI4.

Prérequis :
Un Raspberry PI4
Une LED connectée au Raspberry.
Une installation de broker MQTT pour recevoir les messages publiés.

Organisation des fichiers :
morse.c : Gère la conversion de texte en code Morse.
mqtt.c : Gère la connexion au broker MQTT, la publication et la souscription aux topics.
led.c : Gère l’envoi des signaux lumineux correspondant au code Morse.
main.c : Point d'entrée de l'application, coordonne les fonctions pour convertir un texte, publier via MQTT et utiliser la LED.

Utilisation :
1. Lancement du programme
Exécutez l'application en fournissant un texte à convertir, Exemple : Bonjour
2. Publication via MQTT
En théorie, lorsque le bouton est pressé, un message prédéfini est publié sur le MQTT configuré dans mqtt.c.
3. Signal lumineux
Toujours en théorie, le texte converti en Morse sera retransmis sous forme de signaux lumineux via une LED connectée au Raspberry.

Limites du Projet :
Nous n'avons pas réussi à nous connecter au Raspberry ou à WiringPi de notre côté, donc nous n'avons pas pu essayer de vérifier si la partie LED et la partie MQTT fonctionnaient bien comme on l'espère.
