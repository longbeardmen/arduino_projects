//#define A 6
//#define B 7
//#define C 8

unsigned int ms = 1000;

void setup() { 
  for (size_t i = 2; i < 8; i++)
    pinMode(i, OUTPUT);
//  pinMode(A, OUTPUT);
//  pinMode(B, OUTPUT);
//  pinMode(C, OUTPUT);
}

void loop(){
  digitalWrite(2, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(ms);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(ms);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  delay(ms);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  delay(ms);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  delay(ms);
  digitalWrite(2, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  delay(ms);
//    digitalWrite(A, 1); 
//    digitalWrite(B, 0);
//    digitalWrite(C, 1);
//      delay(ms); 
//    digitalWrite(A, 0); 
//    digitalWrite(B, 0);
//    digitalWrite(C, 1);
//      delay(ms);
//    digitalWrite(A, 0);
//    digitalWrite(B, 1);
//    digitalWrite(C, 1);
//      delay(ms);
//    digitalWrite(A, 0); 
//    digitalWrite(B, 1);
//    digitalWrite(C, 0);
//      delay(ms); 
//    digitalWrite(A, 1); 
//    digitalWrite(B, 1);
//    digitalWrite(C, 0);
//      delay(ms);
//    digitalWrite(A, 1);
//    digitalWrite(B, 0);
//    digitalWrite(C, 0);
//      delay(ms); 
}

