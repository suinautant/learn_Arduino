#include <dht11.h>
#define DHT11PIN 7
dht11 DHT11;

void setup()
{
  Serial.begin(9600);
  DHT11check();
}

void loop()
{
  Serial.print("Humidity (%): ");
  Serial.println(DHT11.humidity);
  Serial.print("Temperature : ");
  Serial.println(DHT11.temperature);
  delay(2000);
}

void DHT11check()
{
  int chk = DHT11.read(DHT11PIN);
  Serial.println("Read");
  switch (chk)
  {
  case 0:
    Serial.println("ok");
    break;
  case 1:
    Serial.println("checksum error");
    break;
  case 2:
    Serial.println("time out");
    break;
  default:
    Serial.println("Unknown");
    break;
  }
}