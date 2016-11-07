void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0) {
    digitalWrite(13, LOW);
      delay(5000);
      digitalWrite(13, HIGH);
  }
}
