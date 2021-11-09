#include <SoftwareSerial.h>
//객체 생성
SoftwareSerial BTSerial(11, 12); //RX, TX
//아두이노 점퍼 설정(반대) : 11 - TX, 12 - RX
void setup() {
  Serial.begin(9600);    //하드웨어 시리얼 설정
  BTSerial.begin(9600);  //소프트웨어 시리얼 설정
}

void loop() {
  if(BTSerial.available()){  //블루투스 시리얼에 데이터가 있으면
    Serial.write(BTSerial.read());  //블루투스 데이터를 읽어서 시리얼에 씀
  }

  if(Serial.available()){ //시리얼에 데이터가 있으면
    BTSerial.write(Serial.read());  //시리얼 데이터를 읽어서 블루투스에 씀
  }
}
