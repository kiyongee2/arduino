#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); //RX, TX
int led = 5;

void setup() {
  BTSerial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(BTSerial.available()){ //시리얼에 데이터가 있으면
    char data = BTSerial.read(); //데이터를 읽어와서
    if(data == '1'){  //문자 1과 같으면
      digitalWrite(led, HIGH);
    }
    
    if(data == '0'){
      digitalWrite(led, LOW);
    }
  }
}
