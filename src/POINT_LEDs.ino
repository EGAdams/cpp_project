#ifndef DIGI_V6_15_H_
#define DIGI_V6_15_H_
#include "DIGI_V6_15.ino"
#endif

void UpdatePoints() {

  switch (p1Points) {
    case 0:
      digitalWrite(P1_POINTS_LED1, HIGH);
      digitalWrite(P1_POINTS_LED2, LOW);
      digitalWrite(P1_POINTS_LED3, LOW);
      digitalWrite(P1_POINTS_LED4, LOW);
      //      Serial.println("p1Points 0");
      break;
    case 1:
      digitalWrite(P1_POINTS_LED1, LOW);
      digitalWrite(P1_POINTS_LED2, HIGH);
      digitalWrite(P1_POINTS_LED3, LOW);
      digitalWrite(P1_POINTS_LED4, LOW);
      //      Serial.println("p1Points 1");
      break;
    case 2:
      digitalWrite(P1_POINTS_LED1, LOW);
      digitalWrite(P1_POINTS_LED2, LOW);
      digitalWrite(P1_POINTS_LED3, HIGH);
      digitalWrite(P1_POINTS_LED4, LOW);
      //      Serial.println("p1Points 2");
      break;
    case 3:
      digitalWrite(P1_POINTS_LED1, LOW);
      digitalWrite(P1_POINTS_LED2, LOW);
      digitalWrite(P1_POINTS_LED3, LOW);
      digitalWrite(P1_POINTS_LED4, HIGH);
      //      Serial.println("p1Points 3");
      break;
    case 4:
      digitalWrite(P1_POINTS_LED1, LOW);
      digitalWrite(P1_POINTS_LED2, LOW);
      digitalWrite(P1_POINTS_LED3, LOW);
      digitalWrite(P1_POINTS_LED4, HIGH);
      break;
    case 5:
      digitalWrite(P1_POINTS_LED1, LOW);
      digitalWrite(P1_POINTS_LED2, LOW);
      digitalWrite(P1_POINTS_LED3, LOW);
      digitalWrite(P1_POINTS_LED4, HIGH);
      //      Serial.println("p1Points 4");
      break;
    case 99:
      digitalWrite(P1_POINTS_LED1, LOW);
      digitalWrite(P1_POINTS_LED2, LOW);
      digitalWrite(P1_POINTS_LED3, LOW);
      digitalWrite(P1_POINTS_LED4, LOW);
      //      Serial.println("p1Points 4");
      break;
  }

  switch (p2Points) {

    case 0:
      digitalWrite(P2_POINTS_LED1, HIGH);
      digitalWrite(P2_POINTS_LED2, LOW);
      digitalWrite(P2_POINTS_LED3, LOW);
      digitalWrite(P2_POINTS_LED4, LOW);
      //      Serial.println("p2Points 0");
      break;
    case 1:
      digitalWrite(P2_POINTS_LED1, LOW);
      digitalWrite(P2_POINTS_LED2, HIGH);
      digitalWrite(P2_POINTS_LED3, LOW);
      digitalWrite(P2_POINTS_LED4, LOW);
      //      Serial.println("p2Points 1");
      break;
    case 2:
      digitalWrite(P2_POINTS_LED1, LOW);
      digitalWrite(P2_POINTS_LED2, LOW);
      digitalWrite(P2_POINTS_LED3, HIGH);
      digitalWrite(P2_POINTS_LED4, LOW);
      //      Serial.println("p2Points 2");
      break;
    case 3:
      digitalWrite(P2_POINTS_LED1, LOW);
      digitalWrite(P2_POINTS_LED2, LOW);
      digitalWrite(P2_POINTS_LED3, LOW);
      digitalWrite(P2_POINTS_LED4, HIGH);
      //      Serial.println("p2Points 3");
      break;
    case 4:
      digitalWrite(P2_POINTS_LED1, LOW);
      digitalWrite(P2_POINTS_LED2, LOW);
      digitalWrite(P2_POINTS_LED3, LOW);
      digitalWrite(P2_POINTS_LED4, HIGH);
      break;
    case 5:
      digitalWrite(P2_POINTS_LED1, LOW);
      digitalWrite(P2_POINTS_LED2, LOW);
      digitalWrite(P2_POINTS_LED3, LOW);
      digitalWrite(P2_POINTS_LED4, HIGH);
      //      Serial.println("p2Points 4");
      break;
    case 99:
      digitalWrite(P2_POINTS_LED1, LOW);
      digitalWrite(P2_POINTS_LED2, LOW);
      digitalWrite(P2_POINTS_LED3, LOW);
      digitalWrite(P2_POINTS_LED4, LOW);
      //      Serial.println("p2Points 4");
      break;
  }
}

void UpdateTBPoints() {
  digitalWrite(P1_POINTS_LED1, LOW);
  digitalWrite(P1_POINTS_LED2, LOW);
  digitalWrite(P1_POINTS_LED3, LOW);
  digitalWrite(P1_POINTS_LED4, LOW);
  //      Serial.println("p1Points OFF");

  digitalWrite(P2_POINTS_LED1, LOW);
  digitalWrite(P2_POINTS_LED2, LOW);
  digitalWrite(P2_POINTS_LED3, LOW);
  digitalWrite(P2_POINTS_LED4, LOW);
  //      Serial.println("p2Points OFF");
}
