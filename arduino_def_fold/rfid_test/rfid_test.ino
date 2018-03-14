#include <SoftwareSerial.h>
SoftwareSerial rfid(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  rfid.begin(9600);
}

void loop() { // run over and over

  while(rfid.available() >= 1) {
    Serial.print(rfid.read());
    if(rfid.available() <= 1) {
      Serial.println(' ');
    }
  }
}
