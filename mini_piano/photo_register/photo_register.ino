#define NOTE_C4  262
void setup() {
  pinMode(A1, INPUT);
  //Serial.begin(9600);
}

void loop() {
  int value = analogRead(A1);
  //Serial.println(value);
  //delay(500);
  if(value > 600){
    tone(5, NOTE_C4, 100);
  }
  else{
    noTone(9);
  }
}
