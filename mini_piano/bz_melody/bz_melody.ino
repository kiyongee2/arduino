//음계 상수 정의
#define NOTE_C4  262  
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

//음계 배열
int melody[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
        NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

void setup() {
  pinMode(5, OUTPUT);
  //음계 재생
  for(int i = 0; i < 8; i++){
    tone(5, melody[i], 200);
    delay(1000);
  }
}

void loop() {
}
