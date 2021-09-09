#include <SoftwareSerial.h>
int blueTx = 3;
int blueRx = 2;
int LEDpin = 13;
SoftwareSerial mySerial(blueTx, blueRx); // (RX, TX) -> HM-10의 (TX, RX)
String myString = "";
void setup()
{
  Serial.begin(9600);   // 컴퓨터와의 시리얼 통신 초기화
  mySerial.begin(9600); // 블루투스 모듈과의 시리얼 통신 초기화
  pinMode(LEDpin, OUTPUT);
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

    if (myString == "on")
    {
      digitalWrite(LEDpin, HIGH);
    }
    else
    {
      digitalWrite(LEDpin, LOW);
    }
    myString = "";
  }
}