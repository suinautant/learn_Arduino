#include "pitches.h"
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4};

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, buzzer, CHANGE);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

void buzzer()
{
  pinMode(9, OUTPUT);
  Serial.println("start buzzer");
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    Serial.print("loop : ");
    Serial.println(thisNote);
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(9, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(9);
  }
  // tone(9, 255, 1000);
  // delay(10);
  // tone(9, 200, 1000);
  // delay(10);
  // tone(9, 100, 1000);
  // delay(10);
  // tone(9, 200, 1000);
}