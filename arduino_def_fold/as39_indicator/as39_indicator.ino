#define strobe_pin 11
#define data_pin 10
#define load_pin 9

void setup() {
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11, 1);
  digitalWrite(10, 1);
  digitalWrite(9, 1);
  delay(10);
  digitalWrite(11, 0);
  digitalWrite(9, 0);
  delay(10);
}
