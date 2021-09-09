#include <IRremote.h>
int input_pin = 6;
IRrecv irrecv(input_pin);
decode_results results;
int R = 4;
int G = 3;
int B = 2;

/*
 * CH- : FFA25D
 * CH :
 * CH+ :
 * 0 : FF6897
 * 1 : FF30CF
 * 2 : FF18E7
 * 3 : FF7A85
 * 4 : FF10EF
 * 5 : FF38C7
 * 6 : FF5AA5
 * 7 : FF42BD
 * 8 : FF4AB5
 * 9 : FF52AD
 */
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
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    // 16진수
    // Serial.println(results.value, HEX);
    // 10진수
    // Serial.println(results.bits, DEC);
    switch (results.value)
    {
    case B0:
      Serial.println("Press '0'");
      break;
    case B1:
      Serial.println("Press '1'");
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      digitalWrite(R, HIGH);
      break;
    case B2:
      Serial.println("Press '2'");
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      digitalWrite(G, HIGH);
      break;
    case B3:
      Serial.println("Press '3'");
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      digitalWrite(B, HIGH);
      break;
    case B4:
      Serial.println("Press '4'");
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
