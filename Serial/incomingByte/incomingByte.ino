int incomingByte = 0; // 수신 데이터

void setup() {
  Serial.begin(9600);
}

void loop() {  
  if(Serial.available()>0){       //수신 데이터가 있는 경우
    incomingByte = Serial.read(); //버퍼의 첫 번째 데이터 읽기

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC); 
    //문자의 아스키값 전송, DEC(decimal) - 10진수
  }
}
