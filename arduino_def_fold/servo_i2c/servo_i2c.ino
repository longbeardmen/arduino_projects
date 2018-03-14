#include <Wire.h>
#include <Servo.h>

Servo hor, ver;

void setup(){
  
  hor.attach(5);
  ver.attach(6);
  hor.write(90);
  ver.write(90);
  
  //i2c setup    
  Wire.begin(4);
  Wire.setClock(400000L);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
}

void receiveEvent(int howMany){
  while(Wire.available() >= 1){  
    int key = Wire.read();

    Serial.println(key);
    
    if(key == 5){
      hor.write(Wire.read());
    }
    
    if(key == 6){
      ver.write(Wire.read());
    }
  
    Wire.flush();
  }
}


