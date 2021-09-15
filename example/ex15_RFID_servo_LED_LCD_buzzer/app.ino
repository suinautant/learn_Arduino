#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
// #define LED_Y_PIN 3
// #define LED_R_PIN 4
#define SERVO_PIN 2
#define B 3
#define G 4
#define R 5
#define BUZZER_PIN 6
#define RST_PIN 9
#define SS_PIN 10

Servo myservo;
int pos = 0;

int myCard[] = {147, 174, 164, 24};
int myTag[] = {108, 184, 11, 73};
int credit[] = {100, 100, 100, 100};

// 0x27 pin config
// SDA : 4pin (ANALOG)
// SCL : 5pin (ANALOG)
LiquidCrystal_I2C lcd(0x27, 16, 2);

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  SPI.begin();
  mfrc.PCD_Init();
  lcd.init();
  lcd.backlight();
  myservo.attach(SERVO_PIN);
}

void loop()
{
  // 태그 접촉이 되지 않았을 때 또는 ID가 읽혀지지 않았을 떄
  if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
  {
    Serial.println("NOT Card Present");
    delay(500);
    return;
  }

  // 태그 접촉시 LED ON
  if (mfrc.uid.uidByte[0] == myCard[0] &&
      mfrc.uid.uidByte[1] == myCard[1] &&
      mfrc.uid.uidByte[2] == myCard[2] &&
      mfrc.uid.uidByte[3] == myCard[3])
  {
    Serial.print("CARD");
    Serial.print("Motor Rotate 90");
    // digitalWrite(LED_Y_PIN, HIGH);
    tone(BUZZER_PIN, 523, 100);
    delay(500);
    for (pos = 0; pos <= 90; pos += 1)
    {
      myservo.write(pos);
      delay(15);
    }
  }
  else if (mfrc.uid.uidByte[0] == myTag[0] &&
           mfrc.uid.uidByte[1] == myTag[1] &&
           mfrc.uid.uidByte[2] == myTag[2] &&
           mfrc.uid.uidByte[3] == myTag[3])
  {
    initUnit();
    Serial.println("TAG");
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 0);
    analogWrite(R, 255);
    delay(1000);
    analogWrite(R, 0);
    analogWrite(G, 255);
    delay(1000);
    analogWrite(G, 0);
    analogWrite(B, 255);
    delay(1000);
    analogWrite(B, 0);
  }
  else if (mfrc.uid.uidByte[0] == credit[0] &&
           mfrc.uid.uidByte[1] == credit[1] &&
           mfrc.uid.uidByte[2] == credit[2] &&
           mfrc.uid.uidByte[3] == credit[3])
  {
    initUnit();
    Serial.println("CREDIT CARD");
    // 신용카드
    lcd.setCursor(0, 0);
    lcd.print("Welcome!");
    lcd.setCursor(0, 1);
    lcd.print("- HONGGILDONG");
  }
  else
  {
    initUnit();
    Serial.println("Who are you?");
    tone(6, 523, 100);
    delay(300);
    tone(6, 523, 100);
    delay(500);
    tone(6, 523, 100);
    delay(500);
  }

  // UID 찾기
  Serial.print("Card UID : ");
  for (byte i = 0; i < 4; i++)
  {
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void initUnit()
{
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
  lcd.clear();
}