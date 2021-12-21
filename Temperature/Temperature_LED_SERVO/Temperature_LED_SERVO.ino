#include <DHT.h>  //라이브러리 가져오기
#include <Servo.h>  
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHT11); //DHT 객체 생성
Servo sv;     //Servo 객체 생성
int led = 6;

void setup() {
   dht.begin();
   sv.attach(9);
   sv.write(0);
   pinMode(led, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  float temp = getTemp(); //온도 함수 호출

  //온도가 30도 이상이면 서보가 작동하고, LED 켜짐
  if(temp > 30){
    sv.write(120);
    digitalWrite(led, HIGH);
  }
  else{
    sv.write(0);
    digitalWrite(led, LOW);
  }
}

float getTemp(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if(isnan(h) || isnan(t)){
    Serial.println("Error in reading DHT sensor!");
    return;
  }
//  Serial.println("Temperature : " + String(t) + " C");
//  Serial.println("Humidity : " + String(h) + " %");
  //delay(2000);

  return t; //온도 반환
}
