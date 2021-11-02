#define NOTE_C4  262 //도

void setup() {
  pinMode(5, OUTPUT);  //아날로그 출력은 생략 가능
}

void loop() {
  //tone 함수
  tone(5, NOTE_C4, 200); //200은 재생 길이
  delay(500);
  noTone(5);
  delay(500);

  /*analogWrite(5, 200); //0~255 (8비트로 출력)
  delay(500);
  analogWrite(5, 0);
  delay(500);*/
}
