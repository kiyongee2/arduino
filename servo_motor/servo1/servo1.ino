#include <Servo.h>  //라이브러리 가져오기
Servo sv;  //sv 객체 생성

void setup() {
  sv.attach(7); //12번핀에 연결
}

void loop() {
  sv.write(0); //0각도에 위치
  //delay(20);  //0.02초 대기
  delay(1000);
  sv.write(120);
  delay(1000);
}
