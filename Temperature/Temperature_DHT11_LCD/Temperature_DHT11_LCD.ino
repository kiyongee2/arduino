#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHT11);
void setup() {
   dht.begin();
   lcd.init();
   lcd.backlight();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if(isnan(h) || isnan(t)){
    Serial.println("Error in reading DHT sensor!");
    return;
  }
  lcd.setCursor(0,0);
  lcd.print("Temp=" + String(t) + "C");
  lcd.setCursor(0,1);
  lcd.print("Humid=" + String(h) + "%"); 
}
