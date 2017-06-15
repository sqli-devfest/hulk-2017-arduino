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
  for (int ledPin=2; ledPin <= 11; ledPin++){
    pinMode(ledPin, OUTPUT);   
   } 
}

// la boucle qui tourne indéfinément
void loop() {
  
  // S'il y a des données
  if (Serial.available() > 0) {
    chase(100);
    // On lit les données sur le port serie
       String command = Serial.readString();
       // Si les données correspondent à la chaine "START"
       if (command == "START"){
          chase(20);
          int sensorValue = 0;
          do{
             // Lit la valeur sur A0 ( 0 - 1023)
            sensorValue = analogRead(A0);
          chase(10);
          } while (sensorValue<100);
         
          // On envoi la réponse sur le port Serial
          Serial.println(sensorValue);
          chase(20);
          digitalWrite(2, LOW);   // sets the LED on
          digitalWrite(3, HIGH);  
          digitalWrite(4, LOW); 
          mesure =true; 
        }
        if (command == "STOP"){
          mesure =false; 
        }
   }
   if (!mesure){
    if (random(4) == 1){
          k2000(100);
          k2000(100);
          k2000(100);
    }else{
      chase(100);
    }
   }
}

void chase(int delaySeconds){
  for (int ledPin=2; ledPin <= 11; ledPin++){
     digitalWrite(ledPin, HIGH);   // sets the LED on
     delay(delaySeconds);                  // waits for a second
     digitalWrite(ledPin, LOW);    // sets the LED off
  } 
}

void k2000(int delaySeconds){
  for (int ledPin=2; ledPin <= 10; ledPin++){
     digitalWrite(ledPin-1, LOW);   // sets the LED on
     digitalWrite(ledPin, HIGH);    // sets the LED off
     digitalWrite(ledPin+1, HIGH);   // sets the LED on
     delay(delaySeconds);                  // waits for a second
  } 
  for (int ledPin=10; ledPin >= 2; ledPin--){
     digitalWrite(ledPin-1, LOW);   // sets the LED on
     digitalWrite(ledPin, HIGH);    // sets the LED off
     digitalWrite(ledPin+1, HIGH);   // sets the LED on
     delay(delaySeconds);                  // waits for a second
     
  } 
}

void blinkAll(int delaySeconds){
  for (int ledPin=2; ledPin <= 11; ledPin++){
    digitalWrite(ledPin, HIGH);   // sets the LED on
  }
     delay(delaySeconds);                  // waits for a second
     for (int ledPin=2; ledPin <= 11; ledPin++){
     digitalWrite(ledPin, LOW);    // sets the LED off
     }
     delay(delaySeconds);
}




