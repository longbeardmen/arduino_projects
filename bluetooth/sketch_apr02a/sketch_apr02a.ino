#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
String comp;
void setup()
{
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
char a; // stores incoming character from other device
void loop()
{
  if (BT.available())
  {
    a = (BT.read());
    Serial.println(a);
//    digitalWrite(a / 10, a % 2);
  }
}
