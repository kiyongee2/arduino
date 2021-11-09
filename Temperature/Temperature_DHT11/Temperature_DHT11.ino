#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHT11);

void setup() {
   dht.begin();
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
}
