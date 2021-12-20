int TrigPin = 8;
int EchoPin = 9;
#define NOTE_C6  1047
int speak = 5;
void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  //TrigPin에서 음파를 쏘고 Echo에서 받아서 계산 
  float distance, duration;
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH);  //시간
  //Serial.println("시간 : " + (String)duration);
  //delay(500);c
  distance = (duration*34000)/1000000/2;   //거리 = 시간 x 속도 (340m를 cm로 환산)
  //Serial.println("거리 : " + (String)distance + "cm");
  //delay(500);
  if(distance >=20 && distance <30)
    {
      sound(1, 300);
    }
    else if(distance >= 10 && distance <20)
    {
      sound(2, 150);
    }
    else if(distance <10)
    {
      sound(3, 50);
    }
    else
    {
      sound(0, 0);
    }
}

void sound(int n, int t)
{
  for(int i=1; i<=n; i+=1)
  {
    analogWrite(bz, NOTE_C6);
    delay(t);
    analogWrite(bz,0);
    delay(t);
  }
  delay(300);
}
