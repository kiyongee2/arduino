int trigPin = 4;  //초음파 발신
int echoPin = 5;  //초음파 수신
int ledPin = 9;
int speaker = 11;
#define NOTE_C5  523   //높은 도

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //거리 = 시간 x 속도
  long duration;  //시간 변수, long 자료형으로 선언
  float distance;
  digitalWrite(trigPin, HIGH);      
  delayMicroseconds(10);   //10마이크로초 = 0.001밀리초
  digitalWrite(trigPin, LOW);

  duration = pulseInLong(echoPin, HIGH);
  
  distance = (duration * 340) / 10000 / 2; 

  if(distance >= 10 && distance < 20){
    flush(1000);
  }else if(distance >=5 && distance < 10){
    flush(500);
  }else if(distance < 5){
    flush(100);
  }else{
    digitalWrite(ledPin, LOW);
  }
}

void flush(int delayTime){
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  analogWrite(speaker, NOTE_C5);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
  analogWrite(speaker, 0);
  delay(300);
}

void sound(){
  analogWrite(speaker, NOTE_C5);
  delay(500);
  analogWrite(speaker, 0);
  delay(500);
}
