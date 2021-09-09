/*
수위 센서
- 공통 단자(3번/8번) : vcc(5v)
Common Cathod Type(FND 500/560)
공통단자(3번/8번) : GND
참고사이트 : http://blog.naver.com/rnc_ohm/40211103324
*/
int Sensor = A0;
int Sensor_val;
int R = 4;
int G = 3;
int B = 2;

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Sensor_val = analogRead(Sensor);
  Serial.print("water level : ");
  Serial.println(Sensor_val);

  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);

  if (Sensor_val <= 300)
  {
    digitalWrite(G, HIGH);
  }
  else if (Sensor_val >= 400 && Sensor_val <= 500)
  {
    digitalWrite(B, HIGH);
  }
  else
  {
    digitalWrite(R, HIGH);
  }
  delay(1000);
}