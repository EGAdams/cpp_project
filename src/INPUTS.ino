#ifndef DIGI_V6_15_H_
#define DIGI_V6_15_H_
#include "DIGI_V6_15.ino"
#endif

#include "RESET.ino"

void ReadReset() {
  if (digitalRead(RESET) == LOW) {
    while (digitalRead(RESET) == LOW) {}
    Serial.println("Reset Button");
    delay(100);
    ResetScoreboard();
  }
}

void ReadUndoButton() {
  if (digitalRead(UNDO) == LOW) {
    while (digitalRead(UNDO) == LOW) {}
    Serial.println("Undo Button");
    delay(100);
    undo = true;
  }
}

void ReadRotary() {
  if (analogRead(ROTARY) <= 100) {
    rotaryPosition = 1;
    //    Serial.print("rotaryValue ");
    //    Serial.println(rotaryValue);
  }
  if (analogRead(ROTARY) >= 350 && analogRead(ROTARY) <= 450) {
    rotaryPosition = 2;
    //    Serial.print("rotaryValue ");
    //    Serial.println(rotaryValue);
  }
  if (analogRead(ROTARY) >= 550 && analogRead(ROTARY) <= 700) {
    rotaryPosition = 3;
    Serial.print("rotaryValue ");
    Serial.println(rotaryValue);
  }
  if (analogRead(ROTARY) >= 750 && analogRead(ROTARY) <= 800) {
    rotaryPosition = 4;
    Serial.print("rotaryValue ");
    Serial.println(rotaryValue);
  }
  if (analogRead(ROTARY) >= 850 && analogRead(ROTARY) <= 1000) {
    rotaryPosition = 5;
    Serial.print("rotaryValue ");
    Serial.println(rotaryValue);
  }
  if (rotaryPosition != prevRotaryPosition) {
    rotaryChange = true;
    prevRotaryPosition = rotaryPosition;
    Refresh();
  }
}

void ReadPlayerButtons() {

  if (analogRead(PLAYER_BUTTONS) <= 1000) {
    delay(20);

    if (analogRead(PLAYER_BUTTONS) <= 50) {
      playerButton = 1;
      //      Serial.print("buttonValue ");
      //      Serial.println(buttonValue);
      //      Serial.print("playerButton ");
      //      Serial.println(playerButton);
    }

    else if (analogRead(PLAYER_BUTTONS) >= 350 && analogRead(PLAYER_BUTTONS) <= 400) {
      playerButton = 2;
      //      Serial.print("buttonValue ");
      //      Serial.println(buttonValue);
      //      Serial.print("playerButton ");
      //      Serial.println(playerButton);
    }

    else if (analogRead(PLAYER_BUTTONS) >= 550 && analogRead(PLAYER_BUTTONS) <= 650) {
      playerButton = 3;
      //      Serial.print("buttonValue ");
      //      Serial.println(buttonValue);
      //      Serial.print("playerButton ");
      //      Serial.println(playerButton);
    }

    else if (analogRead(PLAYER_BUTTONS) >= 750 && analogRead(PLAYER_BUTTONS) <= 800) {
      playerButton = 4;
      //      Serial.print("buttonValue ");
      //      Serial.println(buttonValue);
      //      Serial.print("playerButton ");
      //      Serial.println(playerButton);
    }
    while (analogRead(PLAYER_BUTTONS) <= 1000) {}
  }
}
