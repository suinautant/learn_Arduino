#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#define DHT11PIN 7
dht11 DHT11;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int chk;
void setup()
{
  Serial.begin(9600); // 컴퓨터와의 시리얼 통신 초기화
  chk = DHT11.read(DHT11PIN);
  lcd.init();
  lcd.backlight();
  Serial.println("READY");
}
void loop()
{
  Serial.print("Humidity (%): ");
  Serial.println(DHT11.humidity);
  Serial.print("Temperature : ");
  Serial.println(DHT11.temperature);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(DHT11.humidity);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.print(DHT11.temperature);
  lcd.print("%");
  delay(1000);
}