#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#define DHT11PIN 7
dht11 DHT11;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int R = 2;
int G = 3;
int i = 0;

void setup()
{
  Serial.begin(9600);
  DHT11check();
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  // double humi = DHT11.humidity;
  // double temp = DHT11.temperature;

  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Humi : ");
  lcd.print(DHT11.humidity);
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.print(DHT11.temperature);

  lcd.setCursor(11, 0);
  lcd.print(i++);

  Serial.print("Humidity (%): ");
  Serial.println(DHT11.humidity);
  Serial.print("Temperature : ");
  Serial.println(DHT11.temperature);

  if (DHT11.temperature >= 20)
    digitalWrite(R, HIGH);
  else
    digitalWrite(G, HIGH);
  delay(1000);
}
void DHT11check()
{
  int chk = DHT11.read(DHT11PIN);
  Serial.println("Read");
  switch (chk)
  {
  case 0:
    Serial.println("ok");
    break;
  case 1:
    Serial.println("checksum error");
    break;
  case 2:
    Serial.println("time out");
    break;
  default:
    Serial.println("Unknown");
    break;
  }
}