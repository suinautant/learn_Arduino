int LEDpin = 13;
int SOUNDpin = A0;
// the setup routine runs once when you press reset:
void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(SOUNDpin, INPUT);
  pinMode(LEDpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(SOUNDpin);
  // print out the value you read:
  Serial.print("sensorValue : ");
  Serial.println(sensorValue);
  if (sensorValue > 100)
  {
    digitalWrite(LEDpin, HIGH);
    delay(2000);
  }
  digitalWrite(LEDpin, LOW);
}