#define ledA 7
#define ledB 8
#define ledC 9
#define ledD 10
#define ledE 11
#define ledF 12
#define ledG 13
void setup()
{
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  Serial.begin(9600); //시리얼 모니터 설정.
}
void loop()
{
  Serial.println("Starting\n");
  LoopDisplay(); //LoopDisplay 함수 실행.
}
void clear()
{
  delay(500);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
}
void one()
{
  clear();
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void two()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
}
void three()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void four()
{
  clear();
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void five()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledC, HIGH);
}
void six()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledC, HIGH);
}
void seven()
{
  clear();
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void eight()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void nine()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void zero()
{
  clear();
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
}
void LoopDisplay()
{
  one();
  two();
  three();
  four();
  five();
  six();
  seven();
  eight();
  nine();
  zero();
}
