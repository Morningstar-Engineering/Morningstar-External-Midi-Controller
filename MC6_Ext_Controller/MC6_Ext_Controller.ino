#include <MIDI.h>

#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6
#define SW5 7
#define SW6 8
#define SW7 9
#define SW8 10

#define LED1 12

void setup() {
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
  pinMode(SW6, INPUT);
  pinMode(SW7, INPUT);
  pinMode(SW8, INPUT);
  pinMode(LED1, OUTPUT);

  digitalWrite(SW1, HIGH);
  digitalWrite(SW2, HIGH);
  digitalWrite(SW3, HIGH);
  digitalWrite(SW4, HIGH);
  digitalWrite(SW5, HIGH);
  digitalWrite(SW6, HIGH);
  digitalWrite(SW7, HIGH);
  digitalWrite(SW8, HIGH);

  //Serial.begin(9600);
  MIDI.begin(31250);

  for (int i = 0; i < 10; i++) {
    digitalWrite(LED1, HIGH);
    delay(60);
    digitalWrite(LED1, LOW);
    delay(60);
  }

  delay(100);
}

unsigned long db = 150;
unsigned long lastRead = millis();
byte chn = 1;

unsigned long ledOn = millis();
bool isLEDOn = false;

void loop() {

  if (digitalRead(SW1) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(16, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW2) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(17, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW3) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(18, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW4) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(1, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW5) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(19, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW6) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(20, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW7) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(21, 0, chn);
    lastRead = millis();
  }

  if (digitalRead(SW8) == LOW && millis() - lastRead > db) {
    turnLEDOn();
    MIDI.sendControlChange(0, 0, chn);
    lastRead = millis();
  }

  if (millis() - ledOn > 500 && isLEDOn == true) {
    isLEDOn = false;
    digitalWrite(LED1, LOW);
  }

}

void turnLEDOn() {
  isLEDOn = true;
  ledOn = millis();
  digitalWrite(LED1, HIGH);
}

