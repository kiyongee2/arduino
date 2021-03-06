#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHT11);

void setup() {
   dht.begin();
   pinMode(13, OUTPUT);
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
  if(t > 33){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
}
