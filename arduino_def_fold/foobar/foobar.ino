void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  analogWrite(11,analogRead(0)/4);
}
