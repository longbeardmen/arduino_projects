#include <Wire.h>

int pwm, pin;

void setup(){
  
//  int myEraser = 7;             // this is 111 in binary and is used as an eraser
//  int myPrescaler = 1;         // this could be a number in [1 , 6]. In this case, 3 corresponds in binary to 011.

//  TCCR2B &= ~myEraser;   // this operation (AND plus NOT),  set the three bits in TCCR0B to 0
//  TCCR2B |= myPrescaler;  //this operation (OR), replaces the last three bits in TCCR2B with our new value 011
//
//  TCCR4B &= ~myEraser;   // this operation (AND plus NOT),  set the three bits in TCCR0B to 0
//  TCCR4B |= myPrescaler;  //this operation (OR), replaces the last three bits in TCCR2B with our new value 011
  
  Wire.begin(4);
  Wire.setClock(400000L);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
}

void receiveEvent(int howMany){
  while(1 == Wire.read()){
//    pin = Wire.read();
//    pwm = Wire.read();
    Serial.println(Wire.read());
//    analogWrite(pin, pwm);
  }
  Wire.flush();
}


