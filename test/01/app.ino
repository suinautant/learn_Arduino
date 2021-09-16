#define LED_PIN 9
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}