/*
블루투스 모듈로 앱에서 
1번 버 초음파 센서
2번 버튼 온도/습도
출력은 LCD
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#include <SoftwareSerial.h>
#define DHT11PIN 13
dht11 DHT11;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int blueTx = 3;
int blueRx = 2;
int LED_PWMpin = 9;
int trig = 4;
int echo = 5;
int distance;
SoftwareSerial mySerial(blueTx, blueRx); // (RX, TX) -> HM-10의 (TX, RX)
String myString = "";
byte n = 255;
int chk;
void setup()
{
  Serial.begin(9600);   // 컴퓨터와의 시리얼 통신 초기화
  mySerial.begin(9600); // 블루투스 모듈과의 시리얼 통신 초기화
  pinMode(LED_PWMpin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  chk = DHT11.read(DHT11PIN);
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
  lcd.setCursor(3, 1);
  lcd.print("HI, Earth!");
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
    if (myString == "1")
    {
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      distance = pulseIn(echo, HIGH) * 17 / 1000;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("[ DISTANCE ]");
      lcd.setCursor(0, 1);
      lcd.print(distance);
      lcd.print(" cm");

      Serial.print(pulseIn(echo, HIGH));
      Serial.print(distance);
      Serial.println("cm");
    }

    if (myString == "2")
    {

      Serial.print("Humidity (%): ");
      Serial.println(DHT11.humidity);
      Serial.print("Temperature : ");
      Serial.println(DHT11.temperature);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Humi : ");
      lcd.print(DHT11.humidity);
      lcd.setCursor(0, 1);
      lcd.print("Temp : ");
      lcd.print(DHT11.temperature);
    }

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