#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHT11);
int led = 6;

void setup() {
   dht.begin();
   pinMode(led, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if(isnan(h) || isnan(t)){
    Serial.println("Error in reading DHT sensor!");
    return;
  }
  Serial.println("Temperature : " + String(t) + " C");
  Serial.println("Humidity : " + String(h) + " %");
  delay(2000);
  
  //온도가 30도를 초과하면 LED 켜지고, 아니면 꺼짐
  if(t > 30){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
