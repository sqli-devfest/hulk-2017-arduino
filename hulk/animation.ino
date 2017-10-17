
 #define HIGH_HULK 0x0
 #define LOW_HULK  0x1

int iteration = 0;

void animate() {
  // Tous les 4 itération on change d'animation
  int animation = 0;
  if (iteration > 10) {
    iteration = 0;
  }
  if (iteration == 0 || iteration == 1 || iteration == 2 || iteration == 3) {
    k2000(150);
  } else if ( iteration == 4 || iteration == 5 || iteration == 6 || iteration == 7) {
    chase(100);
  } else if (iteration == 8) {
    blinkAll(100);
  } else {
    blinkEvenOddl(100);
  }
  iteration++;
}

void turnOn(int rank) {
  chase(20);
  chase(50);
  chase(80);
  chase(110);
  chase(140);
  chase(170);
  chase(200);
  for (int ledPin = 2; ledPin <= rank+1; ledPin++) {
    digitalWrite(ledPin, HIGH_HULK);   // sets the LED on
    delay(200);                  // waits for a second
    digitalWrite(ledPin, LOW_HULK);    // sets the LED off
  }
  digitalWrite(rank+1, HIGH_HULK);   // sets the LED on
}

void chase(int delaySeconds) {
  for (int ledPin = 2; ledPin <= 11; ledPin++) {
    digitalWrite(ledPin, HIGH_HULK);   // sets the LED on
    delay(delaySeconds);                  // waits for a second
    digitalWrite(ledPin, LOW_HULK);    // sets the LED off
  }
}

void k2000(int delaySeconds) {
  for (int ledPin = 2; ledPin <= 10; ledPin++) {
    digitalWrite(ledPin - 1, LOW_HULK); // sets the LED on
    digitalWrite(ledPin, HIGH_HULK);    // sets the LED off
    digitalWrite(ledPin + 1, HIGH_HULK); // sets the LED on
    delay(delaySeconds);                  // waits for a second
  }
  for (int ledPin = 10; ledPin >= 2; ledPin--) {
    digitalWrite(ledPin + 1, LOW_HULK); // sets the LED on
    digitalWrite(ledPin, HIGH_HULK);    // sets the LED off
    digitalWrite(ledPin - 1, HIGH_HULK); // sets the LED on
    delay(delaySeconds);                  // waits for a second
  }
}

void blinkAll(int delaySeconds) {
  for (int ledPin = 2; ledPin <= 11; ledPin++) {
    digitalWrite(ledPin, HIGH_HULK);   // sets the LED on
  }
  delay(delaySeconds);                  // waits for a second
  for (int ledPin = 2; ledPin <= 11; ledPin++) {
    digitalWrite(ledPin, LOW_HULK);    // sets the LED off
  }
  delay(delaySeconds);
}

void blinkEvenOddl(int delaySeconds) {
  for (int ledPin = 2; ledPin <= 11; ledPin = ledPin + 2) {
    digitalWrite(ledPin, HIGH_HULK);   // sets the LED on
  }
  delay(delaySeconds);                  // waits for a second
  for (int ledPin = 3; ledPin <= 11; ledPin = ledPin + 2) {
    digitalWrite(ledPin, LOW_HULK);    // sets the LED off
  }
  delay(delaySeconds);
}

void results(int count, int delaySeconds) {
  chase(delaySeconds);
  chase(delaySeconds);
}


