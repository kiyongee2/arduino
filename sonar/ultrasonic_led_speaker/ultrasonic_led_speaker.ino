int trigPin = 4;   //초음파 발사
int echoPin = 5;   //초음파 수신
int Rled = 8;
int Yled = 9;
int Gled = 10;
int bz = 11;  //버저 or 스피커
#define NOTE_C5  523   //높은 도

void setup() { 
  pinMode(Rled, OUTPUT);
  pinMode(Yled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(bz, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance; 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); 
  distance = duration/58;
  Serial.println("  , 거리 : " + String(distance) + "cm");
  if(distance >=20 && distance <30)
  {
    digitalWrite(Rled, LOW);
    digitalWrite(Yled, LOW);
    digitalWrite(Gled, HIGH);
    bzling(1, 300);
  }
  else if(distance >= 10 && distance <20)
  {
    digitalWrite(Rled, LOW);
    digitalWrite(Yled, HIGH);
    digitalWrite(Gled, LOW);
    bzling(2, 150);
  }
  else if(distance <10)
  {
    digitalWrite(Rled, HIGH);
    digitalWrite(Yled, LOW);
    digitalWrite(Gled, LOW);
    bzling(3, 50);
  }
  else
  {
    digitalWrite(Rled, LOW);
    digitalWrite(Yled, LOW);
    digitalWrite(Gled, LOW);
  }
}

void bzling(int n, int t)
{
  for(int i=1; i<=n; i+=1)
  {
    analogWrite(bz, NOTE_C5);
    delay(t);
    analogWrite(bz,0);
    delay(t);
  }
  delay(300);
}
