#define TOUCH_PIN 8
#define LED_PIN 13

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
}

void loop()
{
  int touchValue = digitalRead(TOUCH_PIN);

  if (touchValue == HIGH)
  {
    Serial.println("TOUCHED");
    digitalWrite(LED_PIN, HIGH);
    tone(2, 255, 1000);
    delay(1000);
  }
  else
  {
    Serial.println("UNTOUCHED");
    digitalWrite(LED_PIN, LOW);
    delay(1000);
  }
}