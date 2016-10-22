#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int x, n = 4,ledDelay = 100, ledPin[] = {53, 51, 49, 47};

void setup(){
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("Choose ledPin:");
  lcd.setCursor(0, 1);
   lcd.print("Delay:");
  for (int i = 0; i < n; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

 void loop(){
  int i = 0;
  while(i < n) {
    x = analogRead (0); 
    lcd.setCursor(15, 0);
    lcd.print (i);
    lcd.setCursor(7, 1);
    lcd.print (ledDelay); 
    
    if (x < 60) {
      i+=1;
      lcd.setCursor(15, 0);
      lcd.print (i);
    } 
    else if (x < 200) { 
      if (ledDelay > 100) {
        ledDelay -= 100;
      }
      lcd.setCursor(7, 1);
      lcd.print (ledDelay); 
    }
    else if (x < 400){ 
      ledDelay += 100;
      lcd.setCursor(7, 1);
      lcd.print (ledDelay);  
    } 
    else if (x < 600){
      if(i == 0){
         i = n - 1;
      }
      else {
        i--;
      }
      lcd.setCursor(15, 0);
      lcd.print (i);
    }
    digitalWrite(ledPin[i], HIGH);
    delay(ledDelay);
    digitalWrite(ledPin[i], LOW);
    delay(ledDelay);
  }
 }

