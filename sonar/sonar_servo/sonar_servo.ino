#include <Servo.h>
Servo sv;
#define TRIG 4  //트리그핀을 상수 4로 저장
#define ECHO 5  //에코핀을 상수 5로 저장
int led = 10;   //led 변수에 10을 저장
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(led, OUTPUT);
  sv.attach(9);
  sv.write(0);
  Serial.begin(9600);
}

void loop() {
  float distance;
  distance = getDistance();

  if(distance < 10){  //거리가 10보다 작으면
    sv.write(120);    //서보모터 120도 회전
    digitalWrite(led, HIGH);
  }
  else{
    sv.write(0);  //서보모터 0도 회전
    digitalWrite(led, LOW);
  }
}

float getDistance(){  //거리 계산 함수
  float distance;     //거리 변수
  long duration;      //시간 변수

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseInLong(ECHO, HIGH);      //시간 측정
  distance = (duration * 340) / 10000 / 2; //거리 계산

//  Serial.println(distance);
//  delay(500);
  return distance;
}
