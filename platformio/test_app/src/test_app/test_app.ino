
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.print("test");
  delay(2000);
  lcd.clear();
}

void loop() {
  while(Serial.available()>0){
    lcd.setCursor(0,0);
    lcd.print("1");
    delay(6000);
  }
}
