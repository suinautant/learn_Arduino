#include <Servo.h>

#define TOUCH_PIN 8
#define LED_PIN 13
#define BUZZER_PIN 2
#define SERVO_PIN 3

Servo myservo;

int pos = 0;
boolean check = false;
String strTouch = "";
int statusLed;
int statusServo;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
  myservo.attach(SERVO_PIN);
  Serial.println("READY!!");
}

void loop()
{
  int touchValue = digitalRead(TOUCH_PIN);

  if (touchValue == HIGH)
  {

    if (!check)
    {
      strTouch = "ON";
      statusLed = HIGH;
      statusServo = 90;
      check = true;
    }
    else
    {
      strTouch = "OFF";
      statusLed = LOW;
      statusServo = -90;
      check = false;
    }
    Serial.println(strTouch);
    digitalWrite(LED_PIN, statusLed);
    myservo.write(statusServo);
  }
  delay(1000);
}
