#include <Wire.h>

char in_bytes[4];
int count = 0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  
  in_bytes[count] = Wire.read();
  Serial.println(in_bytes[count]);
  count++;
  Serial.println(count);

  if (count == 3) {
    count = 0;
    union u_tag {
      int b[4];
      float fval;
    } u;
    Serial.println(in_bytes[0]);
    Serial.println(in_bytes[1]);
    Serial.println(in_bytes[2]);
    Serial.println(in_bytes[3]);
    u.b[0] = (byte)in_bytes[0];
    u.b[1] = (byte)in_bytes[1];
    u.b[2] = (byte)in_bytes[2];
    u.b[3] = (byte)in_bytes[3]; 
    Serial.println(u.fval, 4); 
    Serial.println("all");
  }
  
  Serial.println("###");
}
