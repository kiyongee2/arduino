#include<Servo.h>
Servo sv;   //sv 객체 생성
void setup() {
  sv.attach(12);
}

void loop() {
  for(int i=0; i<180; i++){ //각도 1씩 증가
    sv.write(i);
    delay(20);
  }
  for(int i=180; i>=0; i--){  //각도 1씩 감소
    sv.write(i);
    delay(20);
  }
}
