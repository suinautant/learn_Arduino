/*
블루투스
- 아두이노는 자체적으로 유선 통신인 시리얼 통신을 제공
- HC-06은 아두이노에서 블루투스 통신 모듈이며 4개의 핀만 배선하면 사용 가능

(1) 블루투스 기기명 변경
AT+NAME****
(2) 비밀번호 변경
AT+PIN****
(3) 통신속도 변경
AT+BAUD*
1=12000, 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
*/
#include <SoftwareSerial.h>
int blueTx = 3;
int blueRx = 2;
SoftwareSerial mySerial(blueTx, blueRx); // (RX, TX) -> HM-10의 (TX, RX)
void setup()
{
  Serial.begin(9600);   // 컴퓨터와의 시리얼 통신 초기화
  mySerial.begin(9600); // 블루투스 모듈과의 시리얼 통신 초기화
}

void loop()
{
  if (mySerial.available())
  { // 시리얼 모니터 → 아두이노 → HM-10 모듈
    Serial.write(mySerial.read());
  }
  if (Serial.available())
  { // HM-10 모듈 → 아두이노 → 시리얼 모니터
    mySerial.write(Serial.read());
  }
}