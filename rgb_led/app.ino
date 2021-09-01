int R = 9;
int G = 10;
int B = 11;
void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop()
{
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 0);
  delay(1000);
}