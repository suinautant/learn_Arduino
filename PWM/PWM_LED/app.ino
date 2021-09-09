int LEDpin = 9;
void setup()
{
}
byte n = 255;
void loop()
{
  for (size_t i = 0; i < n; i++)
  {
    analogWrite(LEDpin, i);
    delay(100);
  }
}