int led = 5;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.println("Enter 1 or 0");
}

void loop() {
  if(Serial.available()){ //시리얼에 데이터가 있으면
    char data = Serial.read();
    if(data == '1'){  //문자 1과 같으면
      digitalWrite(led, HIGH);
      Serial.println(1);
    }
    
    if(data == '0'){  //문자 0과 같으면
      digitalWrite(led, LOW);
      Serial.println(0);
    }
  }
}
