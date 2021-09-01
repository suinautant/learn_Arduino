/*
광센서 (CdS, 조도센서)
- 빛 자체 또는 빛에 포함되는 정보를 전기신호로 변환하여 검지하는 소자
- 특징으로는 검지가 비접촉, 비파괴, 고속도, 주변에 잡음의 영향을 주지 않는 다는 것
- 센서의 검출 대상으로는 눈에 보이는 가시광선, 눈으로 볼 수 없는 자외선, 적외선 등
*/
int R = 11;
int G = 12;
void setup()
{
  Serial.begin(9600);
  pinMode(G, OUTPUT);
  pinMode(R, OUTPUT);
}

void loop()
{
  int brightness = analogRead(A0);
  Serial.print("brightness : ");
  Serial.println(brightness);

  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  delay(500);

  if (brightness < 300)
  {
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
  }
  else
  {
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
  }
  delay(500);
}
