#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#include <IRremote.h>

#define DHT11pin 4

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
// DHT11
dht11 DHT11;
int IRpin = 6;
// IR remote
IRrecv irrecv(IRpin);
decode_results results;
// LED
int LEDpin = 13;
// HC_SR04
int trig = 2;
int echo = 3;
int distance;
int chk;
double humi;
double temp;

#define B0 0xFF6897
#define B1 0xFF30CF
#define B2 0xFF18E7
#define B3 0xFF7A85
#define B4 0xFF10EF
#define B5 0xFF38C7
#define B6 0xFF5AA5
#define B7 0xFF42BD
#define B8 0xFF4AB5
#define B9 0xFF52AD

void setup()
{
  Serial.begin(9600);
  // 신호 수신 상태 활성화
  irrecv.enableIRIn();
  pinMode(LEDpin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  // LCD
  lcd.init();
  lcd.backlight();
}

void loop()
{

  if (irrecv.decode(&results))
  {
    switch (results.value)
    {
    case B0:
      Serial.println("Press '0' - LED ON");
      digitalWrite(LEDpin, HIGH);
      break;
    case B1:
      Serial.println("Press '1' - Ultra wave");
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);

      distance = pulseIn(echo, HIGH) * 17 / 1000;
      Serial.print(pulseIn(echo, HIGH));
      Serial.print(distance);
      Serial.println("cm");
      lcd.setCursor(0, 0);
      lcd.print(distance);
      lcd.print("cm");
      if (distance <= 30)
      {
        digitalWrite(LEDpin, HIGH);
      }
      break;
    case B2:
      Serial.println("Press '2' - humadity / temperature");
      chk = DHT11.read(DHT11pin);
      humi = DHT11.humidity;
      temp = DHT11.temperature;
      Serial.print("Humidity (%): ");
      Serial.println(humi);
      lcd.setCursor(0, 0);
      lcd.print("humi : ");
      lcd.print(humi);
      Serial.print("Temperature : ");
      Serial.println(temp);
      lcd.print("temp : ");
      lcd.setCursor(0, 1);
      lcd.print(temp);
      break;
    case B3:
      Serial.println("Press '3' - LED on");
      digitalWrite(LEDpin, HIGH);
      break;
    case B4:
      Serial.println("Press '4' - LED off");
      digitalWrite(LEDpin, LOW);
      break;
    case B5:
      Serial.println("Press '5'");
      break;
    case B6:
      Serial.println("Press '6'");
      break;
    case B7:
      Serial.println("Press '7'");
      break;
    case B8:
      Serial.println("Press '8'");
      break;
    case B9:
      Serial.println("Press '9'");
      break;
    }
    // 다음 신호
    irrecv.resume();
  }
}
