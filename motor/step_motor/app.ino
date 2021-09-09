#include <Stepper.h>
// 2048: 한바퀴(360) 1024:반바퀴(180도)
const int stepsPerRevolution = 2048;
Stepper stepper(stepsPerRevolution, 11, 9, 10, 8);

void setup()
{
  stepper.setSpeed(14);
}

void loop()
{
  stepper.step(-stepsPerRevolution);
  delay(1000);
}