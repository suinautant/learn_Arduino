/*
블루투스 모듈로 앱에서 
3번을 누르면 LED가 서서히 밝아지고 
4번을 누르면 LED가 서서히 어두워지며
5번을 누르면 LED가 OFF
*/
#include <SoftwareSerial.h>
int blueTx = 3;
int blueRx = 2;
int LED_PWMpin = 9;
int trig = 4;
int echo = 5;
int distance;
SoftwareSerial mySerial(blueTx, blueRx); // (RX, TX) -> HM-10의 (TX, RX)
String myString = "";
byte n = 255;
void setup()
{
  Serial.begin(9600);   // 컴퓨터와의 시리얼 통신 초기화
  mySerial.begin(9600); // 블루투스 모듈과의 시리얼 통신 초기화
  pinMode(LED_PWMpin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop()
{

  while (mySerial.available())
  {
    char myChar = (char)mySerial.read();
    myString += myChar;
    delay(5);
  }

  if (!myString.equals(""))
  {
    Serial.println("input value: " + myString);
    if (myString == "3")
    {
      for (size_t i = 0; i < n; i++)
      {
        analogWrite(LED_PWMpin, i);
        delay(10);
      }
    }
    if (myString == "4")
    {
      for (size_t i = n; i > 0; i--)
      {
        analogWrite(LED_PWMpin, i);
        delay(10);
      }
    }
    if (myString == "5")
    {
      analogWrite(LED_PWMpin, LOW);
    }
    myString = "";
  }
}