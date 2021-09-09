#include <dht11.h>
#define DHT11PIN 7
dht11 DHT11;
int R = 2;
int G = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop()
{
  double humi = DHT11.humidity;
  double temp = DHT11.temperature;

  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  delay(1000);

  Serial.print("Humidity (%): ");
  Serial.println(humi);
  Serial.print("Temperature : ");
  Serial.println(temp);

  if (temp >= 20)
    digitalWrite(R, HIGH);
  else
    digitalWrite(G, HIGH);
  delay(1000);
}