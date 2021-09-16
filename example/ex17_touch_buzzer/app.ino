#include "pitches.h"
#define TOUCH_PIN 8
#define LED_PIN 13
#define BUZZER_PIN 2

int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
  Serial.println("READY!!");
}

void loop()
{
  int touchValue = digitalRead(TOUCH_PIN);

  if (touchValue == HIGH)
  {
    Serial.println("TOUCHED");
    digitalWrite(LED_PIN, HIGH);
    // tone(BUZZER_PIN, 255, 1000);
    // buzzerMelody();
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {

      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
    delay(1000);
  }
  else
  {
    Serial.println("UNTOUCHED");
    digitalWrite(LED_PIN, LOW);
    delay(1000);
  }
}

void buzzerMelody()
{
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}