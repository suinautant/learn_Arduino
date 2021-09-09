/*
RFID 
- 무선 주파수를 이용한 자동인식 기술 중 하나로 RFID 태그와 RFID 리더로 구성
- 태그(tag)안에 ID 데이터를 저장하고 리더와 안테나를 이용해 태그가 부착된 사물을 관리, 판독, 추적하는 기술
- RFID 라이브러리 설정
 http://github.com/miguelbalboa/rfid 접속> Clone or Download> Downlaod Zip
 압축 해제> 아두이노 libraries 폴더 안에 복사
 c:\Program Files (x86)\libraries\rfid-master안에 example 폴더와 헤더 파일을 포함한 파일을 복사
*/
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10
#define LED_Y_PIN 3
#define LED_R_PIN 4

int myCard[] = {123, 456, 123, 444};

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
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
    digitalWrite(LED_Y_PIN, HIGH);
    digitalWrite(LED_R_PIN, LOW);
    Serial.println("Hello, Arduino!");
    tone(6, 523, 100);
    delay(500);
  }
  else
  {
    digitalWrite(LED_Y_PIN, LOW);
    digitalWrite(LED_R_PIN, HIGH);
    Serial.println("Who are you?");
    tone(6, 523, 100);
    delay(300);
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
