/*
수위 센서
- 공통 단자(3번/8번) : vcc(5v)
Common Cathod Type(FND 500/560)
공통단자(3번/8번) : GND
참고사이트 : http://blog.naver.com/rnc_ohm/40211103324
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int Sensor = A0;
int Sensor_val;
int tone_pin = 7;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  Sensor_val = analogRead(Sensor);
  Serial.print("water level : ");
  Serial.println(Sensor_val);

  if (Sensor_val >= 500)
  {
    lcd.print("Hello, world!");
    lcd.setCursor(3, 1);
    lcd.print("Alert!!!");
    tone(tone_pin, 1000, 3000);
  }
  delay(1000);
}