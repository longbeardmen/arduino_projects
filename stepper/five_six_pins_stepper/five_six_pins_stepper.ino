int motorSpeed = 5000, steps[8] = { B01000, B00100, B00010, B00001 }, drilledSteps[8] = { B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001 }, coils[4] = { 6, 7, 8, 9 };

void setup() {
  pinMode(13, OUTPUT);
  for (size_t i = 6; i < 10; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  // for drilled steps
  for(int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(coils[j], bitRead(drilledSteps[i], j));
    }
    
    delayMicroseconds(motorSpeed);
    digitalWrite(13, HIGH);
  }

  //for not drilled stepss
  /*
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      digitalWrite(coils[j], bitRead(steps[i], j));
    }
    delayMicroseconds(motorSpeed);
  }
  */
}
