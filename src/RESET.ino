#ifndef DIGI_V6_15_H_
#define DIGI_V6_15_H_
#include "DIGI_V6_15.ino"
#endif

void Refresh() {
  if (rotaryChange == true) {
    Serial.println("Rotary Change True");
    rotaryChange = false;
    ResetScoreboard();
  }
}

void ResetScoreboard() {
  Serial.println("Reset sequence");
  digitalWrite(P1_POINTS_LED1, LOW);
  digitalWrite(P1_POINTS_LED2, LOW);
  digitalWrite(P1_POINTS_LED3, LOW);
  digitalWrite(P1_POINTS_LED4, LOW);   /////////-------------------------------------add a mapped for loop to flash Player 1 LED's

  digitalWrite(P2_POINTS_LED1, LOW);
  digitalWrite(P2_POINTS_LED2, LOW);
  digitalWrite(P2_POINTS_LED3, LOW);
  digitalWrite(P2_POINTS_LED4, LOW);

  digitalWrite(P1_GAMES_LED0, LOW);
  digitalWrite(P1_GAMES_LED1, LOW);
  digitalWrite(P1_GAMES_LED2, LOW);
  digitalWrite(P1_GAMES_LED3, LOW);
  digitalWrite(P1_GAMES_LED4, LOW);
  digitalWrite(P1_GAMES_LED5, LOW);
  digitalWrite(P1_GAMES_LED6, LOW);
  digitalWrite(P1_TIEBREAKER, LOW);

  digitalWrite(P2_GAMES_LED0, LOW);
  digitalWrite(P2_GAMES_LED1, LOW);
  digitalWrite(P2_GAMES_LED2, LOW);
  digitalWrite(P2_GAMES_LED3, LOW);
  digitalWrite(P2_GAMES_LED4, LOW);
  digitalWrite(P2_GAMES_LED5, LOW);
  digitalWrite(P2_GAMES_LED6, LOW);
  digitalWrite(P2_TIEBREAKER, LOW);

  digitalWrite(P1_SETS_LED1, LOW);
  digitalWrite(P1_SETS_LED2, LOW);   
  
  digitalWrite(P2_SETS_LED1, LOW);
  digitalWrite(P2_SETS_LED2, LOW);

  digitalWrite(P1_SERVE, LOW);
  digitalWrite(P2_SERVE, LOW);

  // TieLEDsOff();

  tieBreak = false;
  setTieBreak = false;

  serveSwitch = 1;
  serve = 0;
  playerButton = 0;
  gameStart = true;
  delay(200);
}
