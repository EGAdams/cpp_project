#include "INPUTS.ino"



//Written by Chris Bean for Teensy 4.1 only

#define SIMULATION 1
#define PLAYER_BUTTONS A2
#define ROTARY "A15"
#define UNDO 26
#define RESET 38


//-----------------------------------------------------------------------------------------------
//The Prototype board uses the following pins:

#define P1_POINTS_LED1 22
#define P1_POINTS_LED2 23
#define P1_POINTS_LED3 0
#define P1_POINTS_LED4 1

#define P1_SERVE 19

#define P1_GAMES_LED0 31
#define P1_GAMES_LED1 18
#define P1_GAMES_LED2 15
#define P1_GAMES_LED3 14
#define P1_GAMES_LED4 41
#define P1_GAMES_LED5 37
#define P1_GAMES_LED6 36

#define P1_TIEBREAKER 33

#define P1_SETS_LED1 29
#define P1_SETS_LED2 25

#define P2_POINTS_LED1 21
#define P2_POINTS_LED2 20
#define P2_POINTS_LED3 3
#define P2_POINTS_LED4 2

#define P2_SERVE 4

#define P2_GAMES_LED0 32
#define P2_GAMES_LED1 5
#define P2_GAMES_LED2 6
#define P2_GAMES_LED3 7
#define P2_GAMES_LED4 8
#define P2_GAMES_LED5 9
#define P2_GAMES_LED6 10

#define P2_TIEBREAKER 11

#define P2_SETS_LED1 28
#define P2_SETS_LED2 12


//The Updated board uses the following pins:
/*
  #define P1_POINTS_LED1 22
  #define P1_POINTS_LED2 23
  #define P1_POINTS_LED3 0
  #define P1_POINTS_LED4 1

  #define P1_SERVE 19

  #define P1_GAMES_LED0 18
  #define P1_GAMES_LED1 15
  #define P1_GAMES_LED2 14
  #define P1_GAMES_LED3 41
  #define P1_GAMES_LED4 37
  #define P1_GAMES_LED5 36
  #define P1_GAMES_LED6 33

  #define P1_TIEBREAKER 32

  #define P1_SETS_LED1 29
  #define P1_SETS_LED2 25

  #define P2_POINTS_LED1 21
  #define P2_POINTS_LED2 20
  #define P2_POINTS_LED3 3
  #define P2_POINTS_LED4 2

  #define P2_SERVE 4

  #define P2_GAMES_LED0 5
  #define P2_GAMES_LED1 6
  #define P2_GAMES_LED2 7
  #define P2_GAMES_LED3 8
  #define P2_GAMES_LED4 9
  #define P2_GAMES_LED5 10
  #define P2_GAMES_LED6 11

  #define P2_TIEBREAKER 31


  #define P2_SETS_LED1 28
  #define P2_SETS_LED2 12
*/

//-----------------------------------------------------------------------------------------------

boolean setTieBreak = false;
boolean tieBreak = false;
boolean tieLEDsOn = false;
boolean prev3TieLEDsOn = false;
boolean prev2TieLEDsOn = false;
boolean prev1TieLEDsOn = false;
boolean prevTieLEDsOn = false;

byte prevSetTieBreak = 0;
byte prev1SetTieBreak = 0;
byte prev2SetTieBreak = 0;
byte prev3SetTieBreak = 0;
byte prev3TieBreak = 0;
byte prev2TieBreak = 0;
byte prev1TieBreak = 0;
byte prevTieBreak = 0;

byte p1Points = 0;
byte p2Points = 0;
byte p1Games = 0;
byte p2Games = 0;
byte p1Sets = 0;
byte p2Sets = 0;
byte p1Matches = 0;
byte p2Matches = 0;
byte p1TBGames = 0;
byte p2TBGames = 0;
byte prevP1TBGames = 0;
byte prevP2TBGames = 0;
byte prev1P1TBGames = 0;
byte prev1P2TBGames = 0;
byte prev2P1TBGames = 0;
byte prev2P2TBGames = 0;
byte prev3P1TBGames = 0;
byte prev3P2TBGames = 0;

// Variables for Undo()
byte undoPos = 0;
boolean prevPointFlash = false;
byte prevP1Points = 0;
byte prevP2Points = 0;
byte prevP1Games = 0;
byte prevP2Games = 0;
byte prevP1Sets = 0;
byte prevP2Sets = 0;
byte prevP1Matches = false;
byte prevP2Matches = false;
byte prevServe = 0;

boolean prev1PointFlash = false;
byte prev1P1Points = 0;
byte prev1P2Points = 0;
byte prev1P1Games = 0;
byte prev1P2Games = 0;
byte prev1P1Sets = 0;
byte prev1P2Sets = 0;
byte prev1P1Matches = false;
byte prev1P2Matches = false;
byte prev1Serve = 0;

boolean prev2PointFlash = false;
byte prev2P1Points = 0;
byte prev2P2Points = 0;
byte prev2P1Games = 0;
byte prev2P2Games = 0;
byte prev2P1Sets = 0;
byte prev2P2Sets = 0;
byte prev2P1Matches = false;
byte prev2P2Matches = false;
byte prev2Serve = 0;

boolean prev3PointFlash = false;
byte prev3P1Points = 0;
byte prev3P2Points = 0;
byte prev3P1Games = 0;
byte prev3P2Games = 0;
byte prev3P1Sets = 0;
byte prev3P2Sets = 0;
byte prev3P1Matches = false;
byte prev3P2Matches = false;
byte prev3Serve = 0;

boolean gameStart = true;

//int sequenceTime = 4;
//int sequence = 0;
//int flashTime = 1000; // Use to control Win Sequence flash speeds when not using PWM.
//int flash = 0;

boolean resetScoreBoard = false;

int modeP1 = 0;
int modeP2 = 0;
byte p1Setting = 0;
byte p2Setting = 0;

int rotaryValue = 0;
int rotaryPosition = 0;
int prevRotaryPosition = 0;
boolean rotaryChange = false;

int buttonValue = 0;
int playerButton = 0;
boolean buttonPress = false;
boolean undo = false;

byte serveButtonValue = 0;
byte serveButtonPress = 0;
byte serveSwitch = 1;
byte serve = 0;

unsigned long now = millis();
unsigned long prev = 0;
unsigned long pointFlashPrev = 0;

/*--------------------------------------USER SELECTABLE VARIABLES--------------------------------------*/

int buttonDelay = 300;
int updateDisplayDelay = 700;
int winDelay = 1000;
//long matchWinDelay = 15000;
int flashDelay = 1000; // SET TO 1000
byte tiePulseCount = 3;
byte GameWinPulseCount = 3;
byte SetWinPulseCount = 3;
byte MatchWinPulseCount = 5;

/*------------------------------------END USER SELECTABLE VARIABLES------------------------------------*/

byte toggle = 0;

boolean pointFlash = false;
boolean p1PointFlash = false;
boolean p2PointFlash = false;

int currentPulseCount = 0;

byte p1TBGamesMem = 0;
byte p2TBGamesMem = 0;
byte tieBreakMem = 0;
byte setTieBreakMem = 0;

byte p1PointsMem = 0;
byte p2PointsMem = 0;
byte p1GamesMem = 0;
byte p2GamesMem = 0;
byte p1SetsMem = 0;
byte p2SetsMem = 0;

void setup() {

  pinMode(PLAYER_BUTTONS, INPUT);
  pinMode(ROTARY, INPUT);
  pinMode(UNDO, INPUT);
  pinMode(RESET, INPUT);

  pinMode(P1_POINTS_LED1, OUTPUT);
  pinMode(P1_POINTS_LED2, OUTPUT);
  pinMode(P1_POINTS_LED3, OUTPUT);
  pinMode(P1_POINTS_LED4, OUTPUT);

  pinMode(P2_POINTS_LED1, OUTPUT);
  pinMode(P2_POINTS_LED2, OUTPUT);
  pinMode(P2_POINTS_LED3, OUTPUT);
  pinMode(P2_POINTS_LED4, OUTPUT);

  pinMode(P1_SERVE, OUTPUT);
  pinMode(P2_SERVE, OUTPUT);

  pinMode(P1_GAMES_LED0, OUTPUT);
  pinMode(P1_GAMES_LED1, OUTPUT);
  pinMode(P1_GAMES_LED2, OUTPUT);
  pinMode(P1_GAMES_LED3, OUTPUT);
  pinMode(P1_GAMES_LED4, OUTPUT);
  pinMode(P1_GAMES_LED5, OUTPUT);
  pinMode(P1_GAMES_LED6, OUTPUT);
  pinMode(P1_TIEBREAKER, OUTPUT);

  pinMode(P2_GAMES_LED0, OUTPUT);
  pinMode(P2_GAMES_LED1, OUTPUT);
  pinMode(P2_GAMES_LED2, OUTPUT);
  pinMode(P2_GAMES_LED3, OUTPUT);
  pinMode(P2_GAMES_LED4, OUTPUT);
  pinMode(P2_GAMES_LED5, OUTPUT);
  pinMode(P2_GAMES_LED6, OUTPUT);
  pinMode(P2_TIEBREAKER, OUTPUT);

  pinMode(P1_SETS_LED1, OUTPUT);
  pinMode(P1_SETS_LED2, OUTPUT);

  pinMode(P2_SETS_LED1, OUTPUT);
  pinMode(P2_SETS_LED2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  ReadReset();
  // ReadRotary();
  // GameModes();
}
