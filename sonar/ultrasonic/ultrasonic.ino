int trigPin = 4;  //초음파 발신
int echoPin = 5;  //초음파 수신

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  //Serial.println(duration);
  
  distance = (duration * 340) / 10000 / 2; 
  return distance;
  //m->cm로 환산하므로 1,000,000/100 = 10,000, 
  //편도 거리이므로 2로 나눔(소수로 나올수 있으므로 float 형)
  
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);
}
