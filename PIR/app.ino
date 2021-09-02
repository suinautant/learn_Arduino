int LED = 2;
int inputPin = 4;
int pirState = LOW;
int val = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(inputPin);
  if (val == HIGH)
  {
    digitalWrite(LED, HIGH);
    if (pirState == LOW)
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(LED, LOW);
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}