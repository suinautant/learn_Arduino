/*
  초음파 센서
  HC-SR04는 초음파는 이용해 거리를 측정하는 센서
  pulseIn() : 시간 함수
  --> 이 함수는 지정된 핀의 상태(HIGH, LOW) 가 되기를 기다렸다가 해당되는 시간을 재기 시작하고,
  핀의 상태가 바뀌면 시간 재기를 중지 한 후 경과시간을 마이크로 초로 변환
  -- 시간을 거리(cm)로 바꾸는 공식 : int distance = pulseIn(echo, HIGH)*17/1000;
*/
int trig = 2;
int echo = 3;
int R = 11;
int G = 12;
int Y = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int distance = pulseIn(echo, HIGH) * 17 / 1000;

  if (distance > 20)
  {
    ledInit();
    digitalWrite(Y, HIGH);
    
    
  }
  else if (distance > 0 && distance < 10)
  {
    ledInit();
    digitalWrite(R, HIGH);
  }
  else
  {
    ledInit();
    digitalWrite(G, HIGH);
  }

  Serial.print(pulseIn(echo, HIGH));
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

void ledInit() {
    digitalWrite(G, LOW);
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
}
