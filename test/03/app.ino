#define TRIG 2
#define ECHO 3
#define RLED 9
#define GLED 10
#define BLED 11
void setup()
{
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  delay(100);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  int distance = pulseIn(ECHO, HIGH) * 17 / 1000;
  if (distance > 0 && distance < 20)
  {
    analogWrite(RLED, 255);
    analogWrite(GLED, 0);
    analogWrite(BLED, 0);
  }
  else if (distance > 20 && distance < 40)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 255);
    analogWrite(BLED, 0);
  }
  else
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, 255);
  }
  Serial.print(pulseIn(ECHO, HIGH));
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}
