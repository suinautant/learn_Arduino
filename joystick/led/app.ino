#define JOYX_PIN A0
#define JOYY_PIN A1
#define JOYZ_PIN A2
#define DATUM_X 512

#define LED1_PIN 6
#define LED2_PIN 7
#define LED3_PIN 8
#define LED4_PIN 9
#define LED5_PIN 10
#define LED6_PIN 11
#define LED7_PIN 12
#define LED8_PIN 13
#define LED_COUNT 8

void setup()
{
  pinMode(JOYZ_PIN, INPUT);
  Serial.begin(9600);
  for (size_t i = 0; i < LED_COUNT; i++)
  {
    pinMode(i + LED1_PIN, OUTPUT);
  }
}

void loop()
{
  int x = analogRead(JOYX_PIN);
  int y = analogRead(JOYY_PIN);
  int z = analogRead(JOYZ_PIN);
  // vrx = analogRead(VRXPIN);

  if (x > DATUM_X + 5)
  {
    moveRight(x);
  }
  else if (x < DATUM_X - 5)
  {
    moveLeft(x);
  }
  else
    ledOff();

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tZ: ");
  Serial.print(z);
  Serial.println();

  delay(1000);
}

void moveRight(int x)
{
  int targets = (x - DATUM_X) / 63;
  Serial.println(targets);
  // for (size_t i = 5; i < 5 + targets; i++)
  for (size_t i = LED1_PIN; i < LED1_PIN + targets; i++)
  {
    digitalWrite(i, HIGH);
  }
}

void moveLeft(int x)
{
  int targets = x / 63;
  Serial.println(targets);
  // for (size_t i = 5; i < 5 + targets; i++)
  for (size_t i = 13; i >= LED1_PIN + targets; i++)
  {
    digitalWrite(i, HIGH);
  }
}

void ledOff()
{
  for (size_t i = 0; i < LED_COUNT; i++)
  {
    digitalWrite(i + LED1_PIN, LOW);
  }
}