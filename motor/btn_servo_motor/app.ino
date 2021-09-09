#include <Servo.h>
Servo servo;
int sw = 13;
int motor = 12;
void setup()
{
  servo.attach(motor);
  pinMode(sw, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(sw) == HIGH)
  {
    servo.write(180);
  }
  else
  {
    servo.write(90);
  }
}