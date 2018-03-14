#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

void setup() {
  Serial.begin(9600);
  SerialUSB.begin(9600);

  lcd.init();                     
  lcd.backlight();
  lcd.print("Status:");
}
  
void loop() {
  while(SerialUSB.available() > 0){
    lcd.setCursor(0, 1);
    char message = (char)SerialUSB.read();
    lcd.print(message);
    delay(1000);
    SerialUSB.flush();
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Silent");
  
  SerialUSB.flush();
}
