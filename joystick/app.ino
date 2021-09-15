/*
조이스틱
VCC, GND, VRX, VRY, SW
라이브러리
 : > 툴> 라이브러리 관리> 마우스 검색> 설치
*/
#define JOYX_PIN A0
#define JOYY_PIN A1
#define JOYZ_PIN A2

void setup()
{
  pinMode(JOYZ_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(JOYX_PIN);
  int y = analogRead(JOYY_PIN);
  int z = analogRead(JOYZ_PIN);
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tZ: ");
  Serial.print(z);
  Serial.println();
  delay(1000);
}