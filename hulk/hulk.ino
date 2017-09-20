/*
  Permet de lire une valeur de tension dans le cadre du jeu Hulk
  Cette valeur correspond à la valeur d'impédance du corps humain.
  Utilisation d'un
*/

bool mesure = false;

// Le setup lancé à l'init de la board
void setup() {
  // Communication serial en 9600 baud
  Serial.begin(9600);
  for (int ledPin = 2; ledPin <= 11; ledPin++) {
    pinMode(ledPin, OUTPUT);
  }
}

// la boucle qui tourne indéfinément
void loop() {
  // S'il y a des données
  if (Serial.available() > 0) {
    // On lit les données sur le port serie
    String command = Serial.readString();
    // Si les données correspondent à la chaine "START"
    if (command == "START") {
      chase(20);
      int sensorValue = 0;
      do {
        // Lit la valeur sur A0 ( 0 - 1023)
        sensorValue = analogRead(A0);
        chase(10);
      } while (sensorValue < 100);

      // On envoi la réponse sur le port Serial
      Serial.println(sensorValue);
      mesure = true;
    }
    else if (command == "STOP") {
      mesure = false;
    }
    else{
      mesure = true;
      turnOn(command.toInt());
    }
    
  }
  if (!mesure) {
    animate();
  }
}


