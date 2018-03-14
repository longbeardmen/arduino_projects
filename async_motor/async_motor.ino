#define A 9
#define B 10
#define C 11

unsigned int ms = 100;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
}

void loop(){
  analogWrite(A, 1);
  analogWrite(B, 0);
  analogWrite(C, 0);
  delay(ms);
  analogWrite(A, 1);
  analogWrite(B, 0);
  analogWrite(C, 1);
  delay(ms);
  analogWrite(A, 0);
  analogWrite(B, 1);
  analogWrite(C, 0);
  delay(ms);
  analogWrite(A, 0);
  analogWrite(B, 1);
  analogWrite(C, 1);
  delay(ms);
  analogWrite(A, 0);
  analogWrite(B, 0);
  analogWrite(C, 1);
  delay(ms);
  analogWrite(A, 1);
  analogWrite(B, 1);
  analogWrite(C, 0);
  delay(ms);
}

