#define NOTE_C4  262  
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

int melody[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
        NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int button[] = {8, 9, 10, 11};

void setup() {
  for(int i = 0; i < 4; i++){
    pinMode(button[i], INPUT_PULLUP); //풀업 저항
  }
}

void loop() {
  for(int i = 0; i < 4; i++){
    if(digitalRead(button[i])==0){
      tone(5, melody[i], 100);
    }
  }
}
