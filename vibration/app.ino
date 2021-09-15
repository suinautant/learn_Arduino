#define LED_PIN 13
#define VIB_PIN 7
#define R_PIN 5
#define G_PIN 4
#define B_PIN 3
#define BUZZER_PIN 6
#define RED 1
#define GREEN 2
#define BLUE 3

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(VIB_PIN, INPUT);
  Serial.begin(9600);
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
}

void loop()
{
  long measurement = TP_init();
  delay(50);
  Serial.print("Measurement = ");
  Serial.println(measurement);

  if (measurement > 20000)
  {
    Serial.println("20000");
    threeLED(RED);
    buzzerLoop(7, 500);
  }
  else if (measurement > 10000)
  {
    Serial.println("10000");
    threeLED(GREEN);
    buzzerLoop(5, 500);
  }
  else if (measurement > 1000)
  {
    Serial.println("1000");
    threeLED(BLUE);
    buzzerLoop(3, 500);
  }
}

long TP_init()
{
  delay(10);
  return pulseIn(VIB_PIN, HIGH);
}

void buzzerLoop(int count, int interval)
{
  for (size_t i = 0; i < count; i++)
  {
    tone(BUZZER_PIN, 255, 100);
    delay(interval);
  }
}

void threeLED(int color)
{
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 0);
  switch (color)
  {
  case RED:
    analogWrite(R_PIN, 255);
    break;
  case GREEN:
    analogWrite(G_PIN, 255);
    break;
  case BLUE:
    analogWrite(B_PIN, 255);
    break;
  }
}