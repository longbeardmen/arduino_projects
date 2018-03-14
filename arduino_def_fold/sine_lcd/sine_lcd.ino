#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte temp_block[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 }, *positive[16], *negative[16];

void generate_empty_rows() {
  for (int i = 0; i < 16; i++) {
    positive[i] = temp_block;
    negative[i] = temp_block;
  }
}

int comparator(double val) {
  int out = val*1000/125;
  if(val / 125 == 0) {
    out--;
  }
  return out;
}

int group_index(int index) {
  int out = index/5.0;
  if(index % 5 == 0) {
    out--;
  }
  return out;
}

void set_row_block() {
  int k = 0;
  for (int i = 0; i < 25; i++) {
    
    double temp = sin(4*i*PI/180);
    int level, digit = group_index(i);
      
    if(temp > 0) {
      level = 7 - comparator(temp);
      Serial.print(temp);
      //Serial.println(comparator(temp)); 
      
      positive[digit][level] = positive[digit][level] | (1 << (4 - k));
      //positive[digit][level] = (1 << (4 - k));
    } else {
      level = comparator(temp);
      negative[digit][level] = negative[digit][level] | (1 << k);
    }
    k++;
    if(k == 5) {
      k = 0;
    }
  }
  
}

void setup() {
  byte asd[8] = { 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001 };
  Serial.begin(9600);
  
  generate_empty_rows();
  set_row_block();
  
  for(int i = 0; i < 16; i++) {
    lcd.createChar(i, positive[i]);
  }
  
  lcd.begin(16, 2);
  
  for(int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    //lcd.write(byte(i));
    lcd.print(byte(asd));
  }
}

void loop() {
  
}
