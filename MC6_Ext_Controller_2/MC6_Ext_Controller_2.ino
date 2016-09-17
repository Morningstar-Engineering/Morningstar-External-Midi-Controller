/*
 * Code adapted to allow for 8 LEDs
 */

#include <MIDI.h>

#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5
#define SW5 6
#define SW6 7
#define SW7 8
#define SW8 9

#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 14
#define LED5 15
#define LED6 16
#define LED7 17
#define LED8 18

#define TOTAL_LED 8

byte ledArray[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

void blinkAllLeds(byte numTimes, byte inDelay) {
  for (int j = 0; j < numTimes; j++) {
    for (int i = 0; i < TOTAL_LED; i++) {
      digitalWrite(ledArray[i], HIGH);
    }
    delay(inDelay);
    for (int i = 0; i < TOTAL_LED; i++) {
      digitalWrite(ledArray[i], LOW);
    }
  }
}

void setAllLEDs(int type) {
  for (int i = 0; i < TOTAL_LED; i++) {
    digitalWrite(ledArray, type);
  }
}

void setup() {

  // Set pin modes
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
  pinMode(SW6, INPUT);
  pinMode(SW7, INPUT);
  pinMode(SW8, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  digitalWrite(SW1, HIGH);
  digitalWrite(SW2, HIGH);
  digitalWrite(SW3, HIGH);
  digitalWrite(SW4, HIGH);
  digitalWrite(SW5, HIGH);
  digitalWrite(SW6, HIGH);
  digitalWrite(SW7, HIGH);
  digitalWrite(SW8, HIGH);

  MIDI.begin(31250);

  // Blink LED on start
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED1, HIGH);
    delay(60);
    digitalWrite(LED1, LOW);
    delay(60);
  }

  delay(100);
}

unsigned long db = 150; // For switch debounce
unsigned long lastRead = millis();
byte chn = 1; // Midi Channel to send

unsigned long ledOn = millis();
bool isLEDOn = false;

void loop() {

  // Preset G
  if (digitalRead(SW1) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED1, HIGH);
    MIDI.sendControlChange(16, 0, chn);
    lastRead = millis();
  }

  // Preset H
  if (digitalRead(SW2) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED2, HIGH);
    MIDI.sendControlChange(17, 0, chn);
    lastRead = millis();
  }

  // Preset I
  if (digitalRead(SW3) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED3, HIGH);
    MIDI.sendControlChange(18, 0, chn);
    lastRead = millis();
  }

  // Bank Down
  if (digitalRead(SW4) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED4, HIGH);
    MIDI.sendControlChange(1, 0, chn);
    lastRead = millis();
  }

  // Preset J
  if (digitalRead(SW5) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED5, HIGH);
    MIDI.sendControlChange(19, 0, chn);
    lastRead = millis();
  }

  // Preset K
  if (digitalRead(SW6) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED6, HIGH);
    MIDI.sendControlChange(20, 0, chn);
    lastRead = millis();
  }

  // Preset L
  if (digitalRead(SW7) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED7, HIGH);
    MIDI.sendControlChange(21, 0, chn);
    lastRead = millis();
  }

  // Bank Up
  if (digitalRead(SW8) == LOW && millis() - lastRead > db) {
    setAllLEDs(LOW);
    digitalWrite(LED8, HIGH);
    MIDI.sendControlChange(0, 0, chn);
    lastRead = millis();
  }
}
