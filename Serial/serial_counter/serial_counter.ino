int count = 0;  //카운트

void setup() {
  Serial.begin(9600);
}

void loop() {
  count++;   //1씩 증가
  Serial.println(count);
  delay(1000);
}
