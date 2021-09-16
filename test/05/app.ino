#include <Wire.h>
#include <dht11.h>
#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#define B1 0xFF30CF
#define B2 0xFF18E7
#define B3 0xFF7A85
#define B4 0xFF10EF
#define DHT11PIN 4
#define TRIG 2
#define ECHO 3
#define IRPIN 5
#define LED_PIN 13
dht11 DHT11;
IRrecv irrecv(IRPIN);
decode_results results;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int distance;
double humi;
double temp;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  lcd.init();
  lcd.backlight();
}
void loop()
{
  if (irrecv.decode(&results))
  {
    switch (results.value)
    {
    case B1:
      digitalWrite(TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG, LOW);

      distance = pulseIn(ECHO, HIGH) * 17 / 1000;
      Serial.print(distance);
      Serial.println("cm");
      if (distance <= 5)
      {
        digitalWrite(LED_PIN, HIGH);
      }
      break;
    case B2:
      int chk = DHT11.read(DHT11PIN);
      humi = DHT11.humidity;
      temp = DHT11.temperature;
      Serial.print("Humidity (%): ");
      Serial.println(humi);
      Serial.print("Temperature : ");
      Serial.println(temp);

      lcd.setCursor(0, 0);
      lcd.print("humi : ");
      lcd.print(humi);
      lcd.setCursor(0, 1);
      lcd.print("temp : ");
      lcd.print(temp);
      break;
    case B3:
      digitalWrite(LED_PIN, HIGH);
      break;
    case B4:
      digitalWrite(LED_PIN, LOW);
      break;
    }
    irrecv.resume();
  }
}
